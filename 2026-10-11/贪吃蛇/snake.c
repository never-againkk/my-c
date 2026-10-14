/* ============================================================================
 *  贪吃蛇（Snake）—— C 语言控制台实现（Visual Studio / Windows）
 *  ----------------------------------------------------------------------------
 *  在 Visual Studio 里：
 *      1) 打开 贪吃蛇.slnx，工程里已经有 snake.c；
 *      2) 直接按 F5（或 Ctrl+F5）就能编译运行。
 *      （工程已经设置了 /utf-8；如果自己新建工程，请右键工程 -> 属性 ->
 *        C/C++ -> 命令行 -> 其它选项 里加上 /utf-8，否则中文可能显示乱码。）
 *
 *  命令行编译：
 *      cl /utf-8 snake.c                 MSVC
 *      gcc snake.c -o snake.exe          MinGW-w64
 *
 *  运行：
 *      snake.exe                        开始游戏
 *      snake.exe --selftest             无界面自检（批量模拟，用来验证游戏逻辑）
 *
 *  操作：
 *      方向键 或 W/A/S/D    控制方向
 *      P                    暂停 / 继续
 *      R                    游戏结束后重新开始
 *      Q 或 Esc             退出
 *
 *  画面说明：
 *      [] 墙壁    @@ 蛇头    () 蛇身    ** 食物
 * ==========================================================================*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

/* ------------------------------ 可调参数 --------------------------------- */

#define BOARD_W      20                     /* 棋盘宽度（格） */
#define BOARD_H      20                     /* 棋盘高度（格） */
#define MAX_SNAKE    (BOARD_W * BOARD_H)    /* 蛇最长可以填满整个棋盘 */

#define DIR_QUEUE    2                      /* 最多缓存 2 个转向指令，操作更跟手 */

#define START_SPEED  220                    /* 初始速度：每走一步的毫秒数（越小越快） */
#define MIN_SPEED    70                     /* 最快速度上限 */
#define SPEED_STEP   4                      /* 每吃一个食物提速的毫秒数 */

#define CELL_EMPTY   0                      /* 棋盘格子的四种状态 */
#define CELL_BODY    1
#define CELL_HEAD    2
#define CELL_FOOD    3

#define ROW_CHARS    ((BOARD_W + 2) * 2)    /* 棋盘每行输出的字符数（一格两个字符） */
#define TEXT_WIDTH   70                     /* 文字行补齐宽度，用来覆盖上一帧的残留 */

/* ------------------------------- 数据结构 -------------------------------- */

typedef enum { DIR_UP = 0, DIR_RIGHT, DIR_DOWN, DIR_LEFT } Dir;

/* 约定：上/右/下/左 四个方向在 DX、DY 里按下标一一对应 */
static const int DX[4] = {  0, 1,  0, -1 };
static const int DY[4] = { -1, 0,  1,  0 };

typedef struct { int x; int y; } Pos;

typedef struct {
    Pos body[MAX_SNAKE];        /* body[0] 是蛇头，body[len-1] 是蛇尾 */
    int len;                    /* 当前长度 */
    Dir dir;                    /* 当前前进方向 */
    Dir queue[DIR_QUEUE];       /* 待执行的转向指令 */
    int queued;                 /* 队列中有几条指令 */
    Pos food;                   /* 食物位置，x < 0 表示棋盘已满、没有食物 */
    int score;                  /* 本局得分 */
    int best;                   /* 历史最高分（重开不清空） */
    int ms_per_step;            /* 当前速度 */
    int alive;                  /* 1 = 存活，0 = 已撞死 */
    int paused;                 /* 1 = 暂停中 */
    int won;                    /* 1 = 蛇已填满棋盘 */
    int dirty;                  /* 1 = 状态变了，需要重绘 */
} Game;

/* ------------------------------ 控制台输出 ------------------------------- */

static HANDLE g_stdout = INVALID_HANDLE_VALUE;
static int    g_has_console = 0;            /* 输出真的接在控制台上吗 */
static CONSOLE_CURSOR_INFO g_old_cursor;
static int    g_cursor_saved = 0;

/*
 * 统一的输出入口，只接受宽字符串。
 * 有控制台时走 WriteConsoleW（Windows 原生 Unicode，跟代码页无关，不会乱码）；
 * 输出被重定向到文件/管道时退化成 UTF-8 字节流，方便保存和自动化测试。
 */
static void out_text(const wchar_t *s)
{
    size_t len;

    if (s == NULL) {
        return;
    }

    if (g_has_console) {
        len = wcslen(s);
        while (len > 0) {
            DWORD written = 0;
            DWORD chunk = (len > 8192) ? 8192 : (DWORD)len;
            if (!WriteConsoleW(g_stdout, s, chunk, &written, NULL) || written == 0) {
                break;
            }
            s += written;
            len -= written;
        }
        return;
    }

    {
        char utf8[8192];
        int need = WideCharToMultiByte(CP_UTF8, 0, s, -1, NULL, 0, NULL, NULL);
        if (need > 1 && need <= (int)sizeof(utf8)) {
            WideCharToMultiByte(CP_UTF8, 0, s, -1, utf8, need, NULL, NULL);
            fwrite(utf8, 1, (size_t)(need - 1), stdout);
            fflush(stdout);
        }
    }
}

/* 把光标移到指定位置（没有控制台时忽略） */
static void set_cursor(int x, int y)
{
    COORD pos;
    if (!g_has_console) {
        return;
    }
    pos.X = (SHORT)x;
    pos.Y = (SHORT)y;
    SetConsoleCursorPosition(g_stdout, pos);
}

/* 初始化控制台：藏起光标、把窗口调整到能放下棋盘的大小 */
static void console_init(void)
{
    CONSOLE_CURSOR_INFO info;
    SMALL_RECT tiny;
    SMALL_RECT win;
    COORD size;
    DWORD mode = 0;

    g_stdout = GetStdHandle(STD_OUTPUT_HANDLE);
    if (g_stdout == INVALID_HANDLE_VALUE || g_stdout == NULL) {
        return;
    }
    g_has_console = (GetConsoleMode(g_stdout, &mode) != 0);

    SetConsoleTitleW(L"贪吃蛇 - C 语言实现");

    if (!g_has_console) {
        return;
    }

    if (GetConsoleCursorInfo(g_stdout, &info)) {
        g_old_cursor = info;
        g_cursor_saved = 1;
        info.bVisible = FALSE;
        SetConsoleCursorInfo(g_stdout, &info);
    }

    /* 先缩窗口 -> 再放大缓冲区 -> 最后设置窗口，否则接口会因为尺寸冲突而失败 */
    tiny.Left = 0; tiny.Top = 0; tiny.Right = 1; tiny.Bottom = 1;
    win.Left = 0;  win.Top = 0;  win.Right = 89; win.Bottom = 34;
    size.X = 90;   size.Y = 400;
    SetConsoleWindowInfo(g_stdout, TRUE, &tiny);
    SetConsoleScreenBufferSize(g_stdout, size);
    SetConsoleWindowInfo(g_stdout, TRUE, &win);   /* 某些终端不允许改大小，失败也无妨 */
}

/* 退出前把控制台恢复原样 */
static void console_done(void)
{
    if (g_cursor_saved) {
        SetConsoleCursorInfo(g_stdout, &g_old_cursor);
    }
    set_cursor(0, BOARD_H + 8);
    out_text(L"\n感谢游玩，再见！\n");
}

/* ------------------------------- 游戏逻辑 -------------------------------- */

static int in_board(int x, int y)
{
    return x >= 0 && x < BOARD_W && y >= 0 && y < BOARD_H;
}

/* 这个格子能不能放食物：必须在棋盘内，且不在蛇身上 */
static int cell_is_free(const Game *g, int x, int y)
{
    int i;
    if (!in_board(x, y)) {
        return 0;
    }
    for (i = 0; i < g->len; ++i) {
        if (g->body[i].x == x && g->body[i].y == y) {
            return 0;
        }
    }
    return 1;
}

/* 随机找一个空格放食物；棋盘快满时随机很难命中，所以再顺序扫一遍 */
static void spawn_food(Game *g)
{
    int x, y, tries, free_count, pick;

    for (tries = 0; tries < 200; ++tries) {
        x = rand() % BOARD_W;
        y = rand() % BOARD_H;
        if (cell_is_free(g, x, y)) {
            g->food.x = x;
            g->food.y = y;
            return;
        }
    }

    free_count = 0;
    for (y = 0; y < BOARD_H; ++y) {
        for (x = 0; x < BOARD_W; ++x) {
            if (cell_is_free(g, x, y)) {
                free_count++;
            }
        }
    }
    if (free_count == 0) {          /* 棋盘满了，没有食物可放 */
        g->food.x = -1;
        g->food.y = -1;
        return;
    }

    pick = rand() % free_count;
    for (y = 0; y < BOARD_H; ++y) {
        for (x = 0; x < BOARD_W; ++x) {
            if (cell_is_free(g, x, y)) {
                if (pick == 0) {
                    g->food.x = x;
                    g->food.y = y;
                    return;
                }
                pick--;
            }
        }
    }
}

/* 重开一局：蛇放在正中间、朝右，长度为 3 */
static void reset_game(Game *g)
{
    int i;
    int cx = BOARD_W / 2;
    int cy = BOARD_H / 2;

    g->len = 3;
    g->dir = DIR_RIGHT;
    for (i = 0; i < g->len; ++i) {
        g->body[i].x = cx - i;
        g->body[i].y = cy;
    }
    g->queued = 0;
    g->score = 0;
    g->ms_per_step = START_SPEED;
    g->alive = 1;
    g->paused = 0;
    g->won = 0;
    g->food.x = -1;
    g->food.y = -1;
    spawn_food(g);
}

/* 把一条转向指令放进队列：不能原地掉头，也不能和上一条重复 */
static void queue_dir(Game *g, Dir d)
{
    Dir last;

    if (g->queued > 0) {
        last = g->queue[g->queued - 1];
    } else {
        last = g->dir;
    }
    if (d == last) {
        return;                                  /* 同方向，忽略 */
    }
    if (((int)d + 2) % 4 == (int)last) {
        return;                                  /* 180 度掉头，忽略 */
    }
    if (g->queued >= DIR_QUEUE) {
        return;                                  /* 队列满了，忽略 */
    }
    g->queue[g->queued] = d;
    g->queued++;
}

/* 走一步。返回 1 表示还活着，返回 0 表示这一步撞死了 */
static int step(Game *g)
{
    Pos head;
    int i;
    int eating;

    if (!g->alive) {
        return 0;
    }

    /* 从队列里取出一个转向指令（一帧只转一次） */
    if (g->queued > 0) {
        g->dir = g->queue[0];
        for (i = 1; i < g->queued; ++i) {
            g->queue[i - 1] = g->queue[i];
        }
        g->queued--;
    }

    head.x = g->body[0].x + DX[g->dir];
    head.y = g->body[0].y + DY[g->dir];

    /* 撞墙 */
    if (!in_board(head.x, head.y)) {
        g->alive = 0;
        return 0;
    }

    eating = (head.x == g->food.x && head.y == g->food.y);

    /* 撞到自己。注意：不吃食物时，蛇尾这一步会让开，所以撞尾巴不算死 */
    for (i = 0; i < g->len; ++i) {
        if (i == g->len - 1 && !eating) {
            continue;
        }
        if (g->body[i].x == head.x && g->body[i].y == head.y) {
            g->alive = 0;
            return 0;
        }
    }

    /* 整条蛇往前挪一格：新蛇头放到下标 0，尾巴看情况保留 */
    if (eating && g->len < MAX_SNAKE) {
        memmove(&g->body[1], &g->body[0], (size_t)g->len * sizeof(Pos));
        g->len++;
    } else {
        memmove(&g->body[1], &g->body[0], (size_t)(g->len - 1) * sizeof(Pos));
    }
    g->body[0] = head;

    if (eating) {
        g->score += 10;
        if (g->score > g->best) {
            g->best = g->score;
        }
        if (g->ms_per_step > MIN_SPEED) {
            g->ms_per_step -= SPEED_STEP;
            if (g->ms_per_step < MIN_SPEED) {
                g->ms_per_step = MIN_SPEED;
            }
        }
        if (g->len >= MAX_SNAKE) {
            g->won = 1;                  /* 蛇填满棋盘，通关 */
        } else {
            spawn_food(g);
        }
    }
    return 1;
}

/* -------------------------------- 画面 ---------------------------------- */

/* 往缓冲区追加一行：不足 width 个字符的用空格补齐，这样能盖掉上一帧的旧内容 */
static int put_line(wchar_t *dst, int n, const wchar_t *text, int width)
{
    int i = 0;
    if (text != NULL) {
        while (text[i] != L'\0' && i < width) {
            dst[n++] = text[i];
            i++;
        }
    }
    while (i < width) {
        dst[n++] = L' ';
        i++;
    }
    dst[n++] = L'\n';
    return n;
}

/* 整帧一次性写出去，避免闪烁 */
static void render(const Game *g)
{
    static const wchar_t *cell_text[4] = { L"  ", L"()", L"@@", L"**" };
    unsigned char grid[BOARD_H][BOARD_W];
    wchar_t buf[4096];
    wchar_t line[128];
    int n = 0;
    int x, y, i;
    const wchar_t *t;

    memset(grid, CELL_EMPTY, sizeof(grid));
    if (in_board(g->food.x, g->food.y)) {
        grid[g->food.y][g->food.x] = CELL_FOOD;
    }
    for (i = g->len - 1; i >= 0; --i) {          /* 倒着放，蛇头最后写入，压过蛇身 */
        if (in_board(g->body[i].x, g->body[i].y)) {
            grid[g->body[i].y][g->body[i].x] = (i == 0) ? CELL_HEAD : CELL_BODY;
        }
    }

    n = put_line(buf, n, L"贪吃蛇 —— C 语言控制台版", TEXT_WIDTH);
    n = put_line(buf, n, L"", TEXT_WIDTH);

    for (y = -1; y <= BOARD_H; ++y) {            /* 外圈一圈墙壁 */
        for (x = -1; x <= BOARD_W; ++x) {
            if (!in_board(x, y)) {
                t = L"[]";
            } else {
                t = cell_text[grid[y][x]];
            }
            buf[n++] = t[0];
            buf[n++] = t[1];
        }
        buf[n++] = L'\n';
    }

    n = put_line(buf, n, L"", TEXT_WIDTH);
    swprintf(line, 128, L"得分: %d    最高分: %d    长度: %d    速度: %d 毫秒/步",
             g->score, g->best, g->len, g->ms_per_step);
    n = put_line(buf, n, line, TEXT_WIDTH);
    n = put_line(buf, n, L"方向键 / WASD 移动    P 暂停    Q 退出", TEXT_WIDTH);

    if (!g->alive) {
        swprintf(line, 128, L"游戏结束！本局 %d 分，按 R 重新开始，按 Q 退出", g->score);
    } else if (g->won) {
        swprintf(line, 128, L"太厉害了，蛇填满了整个棋盘！按 R 再来一局，按 Q 退出");
    } else if (g->paused) {
        swprintf(line, 128, L"已暂停 —— 按 P 继续");
    } else {
        line[0] = L'\0';
    }
    n = put_line(buf, n, line, TEXT_WIDTH);

    buf[n] = L'\0';
    set_cursor(0, 0);
    out_text(buf);
}

/* -------------------------------- 输入 ---------------------------------- */

/* 处理这一帧的所有按键。返回 1 表示玩家要退出 */
static int handle_input(Game *g)
{
    while (_kbhit()) {
        int c = _getch();

        if (c == 0 || c == 0xE0) {                /* 方向键：先来一个前导字节 */
            switch (_getch()) {
            case 72: queue_dir(g, DIR_UP);    break;
            case 80: queue_dir(g, DIR_DOWN);  break;
            case 75: queue_dir(g, DIR_LEFT);  break;
            case 77: queue_dir(g, DIR_RIGHT); break;
            default: break;
            }
            continue;
        }

        switch (c) {
        case 'q': case 'Q': case 27:              /* 27 = Esc */
            return 1;
        case 'p': case 'P':
            g->paused = !g->paused;
            g->dirty = 1;
            break;
        case 'r': case 'R':
            if (!g->alive || g->won) {
                reset_game(g);
                g->dirty = 1;
            }
            break;
        case 'w': case 'W': queue_dir(g, DIR_UP);    break;
        case 's': case 'S': queue_dir(g, DIR_DOWN);  break;
        case 'a': case 'A': queue_dir(g, DIR_LEFT);  break;
        case 'd': case 'D': queue_dir(g, DIR_RIGHT); break;
        default:
            break;
        }
    }
    return 0;
}

/* ------------------------------ 自查 / 自检 ------------------------------ */

/*
 * 不接界面，直接跑几万步游戏逻辑：
 * 每步都故意把食物放到蛇头正前方，逼它不停吃、不停变长，
 * 直到撞死或者填满棋盘就重开，同时检查蛇身有没有越界、有没有重叠。
 * 用来在没有人工操作的情况下确认核心逻辑没有内存越界之类的低级错误。
 */
static int run_selftest(void)
{
    const int steps = 20000;
    Game g;
    int i, k, eaten = 0, resets = 0, failures = 0;
    wchar_t line[256];

    srand(20240607u);
    memset(&g, 0, sizeof(g));
    reset_game(&g);

    for (i = 0; i < steps && failures == 0; ++i) {
        unsigned char seen[BOARD_H][BOARD_W];
        Dir ahead;
        int x, y, len_before;

        queue_dir(&g, (Dir)(rand() % 4));

        /* 把食物放到蛇头下一步要去的格子（那里不是墙也不是蛇身时才放） */
        ahead = (g.queued > 0) ? g.queue[0] : g.dir;
        x = g.body[0].x + DX[ahead];
        y = g.body[0].y + DY[ahead];
        if (cell_is_free(&g, x, y)) {
            g.food.x = x;
            g.food.y = y;
        }

        len_before = g.len;
        if (step(&g) && g.len > len_before) {
            eaten++;
        }
        if (!g.alive || g.won) {
            resets++;
            reset_game(&g);
        }

        /* 不变量：长度合法、蛇身不出界、蛇身不重叠 */
        if (g.len < 1 || g.len > MAX_SNAKE) {
            failures++;
            break;
        }
        memset(seen, 0, sizeof(seen));
        for (k = 0; k < g.len; ++k) {
            x = g.body[k].x;
            y = g.body[k].y;
            if (!in_board(x, y) || seen[y][x]) {
                failures++;
                break;
            }
            seen[y][x] = 1;
        }
    }

    swprintf(line, 256, L"自检：模拟 %d 步，吃到食物 %d 次，撞死/通关重开 %d 次 —— %s\n",
             steps, eaten, resets, (failures == 0) ? L"通过" : L"失败");
    out_text(line);
    return (failures == 0) ? 0 : 1;
}

/* --------------------------------- 主程序 -------------------------------- */

int main(int argc, char *argv[])
{
    Game game;
    DWORD last;

    if (argc > 1 && strcmp(argv[1], "--selftest") == 0) {
        return run_selftest();
    }

    console_init();
    srand((unsigned)time(NULL));
    memset(&game, 0, sizeof(game));
    reset_game(&game);
    game.dirty = 1;

    last = GetTickCount();
    while (1) {
        if (handle_input(&game)) {
            break;
        }
        if (game.dirty) {
            render(&game);
            game.dirty = 0;
        }
        if (game.paused) {
            last = GetTickCount();               /* 暂停期间不计时，恢复后不会突然冲一步 */
        } else if (game.alive && !game.won &&
                   GetTickCount() - last >= (DWORD)game.ms_per_step) {
            last = GetTickCount();
            step(&game);
            render(&game);
        }
        Sleep(10);                               /* 让出 CPU，同时保证按键响应及时 */
    }

    console_done();
    return 0;
}
