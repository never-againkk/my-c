#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "game.h"
#include <stdlib.h>
void game()
{
	char mine[ROWS][COLS];//布置雷
	char show[ROWS][COLS];//排查雷
	//初始化棋盘
	Initboard(mine, ROWS, COLS, '0');//0
	Initboard(show, ROWS, COLS, '*');//*'
	//打印棋盘
	/*Displayboard(mine,ROW,COL);*/
	Displayboard(show, ROW, COL);
	//布置雷
	setmine(mine,ROW,COL);
	/*Displayboard(mine, ROW, COL);*/

	//排查雷
	findmine(mine, show, ROW, COL);



}


void menu()
{
	printf("--------------------\n");
	printf("--------------------\n");
	printf("-------1.play-------\n");
	printf("-------0.exist------\n");
	printf("--------------------\n");
	printf("--------------------\n");

}
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;

	do
	{
		
		menu();

		printf("请选择:");
		scanf("%d", &input);
		switch(input)
		{
		case 1:

			game();
			break;
		case 0:
			printf("退出游戏");
			break;

		default:
			printf("输入错误，请重新选择");
		
	}
	} while (input);


	return 0;
}

