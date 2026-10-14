/*
 * test.c 的修正版（原文件 test.c 未做任何改动）
 * 原程序的意图：模拟红绿灯，红灯 10 秒、绿灯 10 秒、黄灯 3 秒，循环切换。
 *
 * 已修正的问题（共 9 处）：
 *   1. 第 43 行  whiel(1)          -> while (1)             拼写错误，头文件里的 while 拼错了
 *   2. 第 46 行  "……秒"，message    -> "……秒", message      中文全角逗号，不是 C 的逗号
 *   3. 第 46 行  %d 传入 seconds[cur] -> 传入倒计时变量 i    参数与语义不符
 *   4. 第 49 行  printf("剩余%d 秒", sec) -> 用 i            每轮都打印同一个 sec，倒计时不动
 *   5. 第 50 行  sleep(1000)        -> Sleep(1000)          Windows 下要大写 S，且单位是毫秒
 *   6. 第 52 行  trflight cur = ... -> cur = ...            在内层重复定义变量，外层 cur 永远不变
 *   7. 第 52 行  (cur + 1) % 3      -> 显式取整再转回枚举    枚举不保证能直接参与取余运算
 *   8. 第 40/41 行 数组长度 20      -> 按枚举个数建数组      20 与实际只有 3 种灯不符
 *   9. 缺少 setlocale + main 缺 void，以及未换行导致输出连成一行
 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <windows.h>

/* 原文件里被注释掉的结构体 / 联合体练习代码，保持原样保留 */
//typedef struct date
//{
//	int year;
//	int month;
//	int day;
//}date;
//struct student
//{
//	char  name[20];
//	date birthday;
//	char num[20];
//};
//int main()
//{
//	struct student s = { "wangwu", { 2008,8,23 }, "2374824827" };
//	printf("%s %d %d %d %s", s.name, s.birthday.year,s.birthday.month,s.birthday.day, s.num);
//	return 0;
//}
//int check_big()
//{
//	union
//	{
//		char c;
//		int i;
//	}u;
//	u.i = 1;
//	return u.i;
//}

typedef enum
{
	red,
	green,
	yellow,
	LIGHT_COUNT          /* 放在最后，自动等于 3，作为灯的种数和取余的模 */
} trflight;

int main(void)
{
	/* setlocale 让 printf 能按本地编码正常输出中文（否则控制台里是乱码） */
	setlocale(LC_ALL, "");

	const char* message[LIGHT_COUNT] = { [red] = "红", [green] = "绿", [yellow] = "黄" };
	int seconds[LIGHT_COUNT] = { [red] = 10, [green] = 10, [yellow] = 3 };
	trflight cur = red;

	while (1)
	{
		int sec = seconds[cur];
		printf("现在是%s灯，持续%d秒\n", message[cur], seconds[cur]);

		for (int i = sec; i > 0; i--)
		{
			printf("剩余%d秒\n", i);   /* 这里要用 i，sec 是不变的 */
			Sleep(1000);              /* Windows 下是 Sleep，单位毫秒 */
		}

		/* 修正：不要重新定义 cur，直接给外层的 cur 赋值 */
		cur = (trflight)(((int)cur + 1) % LIGHT_COUNT);
	}

	return 0;
}
