#define _CRT_SECURE_NO_WARNINGS
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#include <stdio.h>
#include <stdlib.h>
#define EASY_COUNT 10
#include <time.h>
//º¯ÊýÉêÃ÷
void Initboard(char board[ROWS][COLS], int r, int c,char set);
void Displayboard(char board[ROWS][COLS], int r, int c);
void setmine(char mine[ROWS][COLS],int r,int c);
void findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int r, int c);

