#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//int main()//
//{
//	int a = 2;
//	int b = 3;
//	int c = 1;
//	int d = 0;
//	if (a < b)
//	{
//		d = a;
//		a = b;
//		b = d;
//
//	}//a>=b
//	if (a < c)
//	{
//		d = a;
//		a = c;
//		d = c;
//	}
//	if (b < c)
//	{
//		d = b;
//		b = c;
//		c = d;
//	}
//	printf("%d%d%d", a, b, c);
//
//
//
//	return 0;
//}
int main()
{
	int a;
	int b;
	int c;
	while (scanf("%d%d%d", &a, &b, &c) != EOF)
	{
		
		if (a + b > c && b + c > a && a + c > b)
		{
			printf("是三角形");
			{
				if (a == b && b == c && c == a)
				{

					printf("等边三角形");
					
					}
				if (a == b || a == c || b == c)
					printf("等腰三角形");
				}


				


			}
		}
		else
			printf("不构成三角形");
	
}






	return 0;
}




























