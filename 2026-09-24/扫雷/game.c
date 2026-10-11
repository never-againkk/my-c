#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

void Initboard(char board[ROWS][COLS], int r, int c,char set)
{
	int i = 0;
	
	for (i = 0; i < r; i++)
	{
		int j = 0;
		for (j = 0; j < c; j++)
		{
			board[i][j] = set;
		}
	}
	
}
void Displayboard(char board[ROWS][COLS], int r, int c)
{

	int i = 0;
	
	/* 列号从 1 开始，前面留两个空格对齐 */
	printf("  ");
	for (i = 1; i <= c; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <=r; i++)
	{
		printf("%d ", i);
		int j = 0;

		
		for (j = 1; j <=c; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("\n");


}
void setmine(char mine[ROWS][COLS], int r, int c)
{
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % r + 1;
		int y = rand() % c + 1;
		if (mine[x][y] != '1')
		{
			mine[x][y] = '1';
			count--;
		}
	}

}
static int getminecount(char mine[ROWS][COLS], int x, int y, int r, int c)
{
	int i = 0;
	int j = 0;
	int count = 0;
	for (i = -1; i <= 1; i++)
	{
		for (j = -1; j <= 1; j++)
		{
			if (i == 0 && j == 0) continue; /* 不统计自身 */
			int xi = x + i;
			int yj = y + j;
			if (xi >= 1 && xi <= r && yj >= 1 && yj <= c)
			{
				if (mine[xi][yj] == '1') count++;
			}
		}
	}
	return count;
}


void findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int r, int c)
{
	printf("请输入要排查的坐标 (x y)：\n");
	
	int x = 0;
	int y = 0;
	int win = 0;
	

	while (win<r * c-EASY_COUNT)
	{
		scanf("%d%d", &x, &y);

		if (x >= 1 && x <= r && y >= 1 && y <= c)
		{
			if (show[x][y] == '*')
			{
				if (mine[x][y] == '0')
				{
					/* 强制将返回值转换为 char */
					char count = (char)getminecount(mine, x, y, r, c);
					show[x][y] = (char)(count + '0');
					Displayboard(show, ROW, COL);
					win++;
	
	
				}
				else
				{
					printf("你个臭傻逼踩到雷了，fw游戏结束\n");
					Displayboard(mine, ROW, COL);
					break;
				}
			}
			else
			{
				printf("该位置已被排查，请重新输入\n");
			}
		}
		else
		{
			printf("输入坐标非法，请重新输入 \n", r, c);
		}
	}
	if(win==  r * c - EASY_COUNT)
		{
		printf("恭喜你排雷成功，你可真是个大聪明qwq\n");
		Displayboard(show, ROW, COL);

		}
}
