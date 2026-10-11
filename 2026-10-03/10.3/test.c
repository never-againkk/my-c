#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
//int main()
//{
//	int** p = (int**)malloc(3 * sizeof(int*));
//	for (int i = 0; i < 3; i++)
//	{
//		p[i] = (int*)malloc(5 * sizeof(int));
//	}
//	for (int i = 0; i < 3; i++)
//	{
//		
//		for (int j = 0; j < 5; j++)
//		{
//			p[i][j] = 0;
//		}
//	}
//	for (int i = 0; i < 3; i++)
//	{
//		free(p[i]);
//		p[i] = NULL;
//	}
//	free(p);
//	return 0;
//}
//int add(int x, int y)
//{
//	return x + y;
//}
//
//int main()
//{
//	int (*p)(int, int) = add;
//	printf("%p ", p);
//	printf("%d", p(2, 3));
//
//	return 0;
//}
//typedef int (*ttg)[6];
//int main()
//{
//
//	int arr[6] = { 0 };
//	int (*p1)[6] = &arr;
//	ttg p2 = &arr;
//
//	return 0;
//}
//typedef int (*fff)(int, int);
//int main()
//{
//	/*int (*p[4])(int, int) = { j,q,e,r };*/
//	
//	return 0;
int add(int x, int y)
{
	return x + y;
}
int sub(int x, int y)
{
	return x - y;
}
int mul(int x, int y)
{
	return x * y;
}
int div(int x, int y)
{
	return x / y;
}
void menu()
{
	printf("-----------------------\n");
	printf("----------1 add--------\n");
	printf("----------2 sub--------\n");
	printf("----------3 mul---------\n");
	printf("----------4 div--------\n");
	printf("----------0 exit---------\n");
	printf("-----------------------\n");
	printf("-----------------------\n");
	printf("\n");
}
//int main()
//{ 
//	int input;
//	int x;
//	int y;
//	int (*p[5])(int, int) = { 0,add,sub,mul,div };
//	do
//	{
//		menu();
//		printf("请选择 ");
//		scanf("%d", &input);
//		if (input == 0)
//		{
//			printf("退出计算机");
//			break;
//		}
//		if (input >= 1 && input <= 4)
//		{
//			printf("请输入操作数 ");
//			scanf("%d%d", & x, &y);
//			int ret = p[input](x,y);
//			printf("\n");
//			printf("\n%d\n", ret);
//		}
//		else
//		{
//			printf("输入错误");
//		}
//	} while (input);
//	return 0;
//}
void cacul(int (*ps)(int,int))
{
	int x = 0;
	int y = 0;
	int r = 0;
	printf("请输入两个操作数");
	scanf("%d%d", &x, &y);
	r = ps(x, y);
	printf("%d\n", r);
}
int main()
{
	int input;
	do
	{
		menu();
		printf("请选择 ");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
				cacul(add);
				break;
		case 2:
					cacul(sub);
					break;
		case 3:
			cacul(mul);
			break;
		case 4:
			cacul(div);
			break; 
		case 0:
			printf("输入错误");
			break;

		}

	} while (input);

	return 0;
}