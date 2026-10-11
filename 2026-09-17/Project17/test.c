#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//int main()
//{
//	int j = 1;
//	int i = 1;
//	for (i = 1; i <= 9; i++)
//	{
//		for (j = 1; j <= 9; j++)
//		{
//			printf("%d*%d=%d ", i, j, i * j);
//
//		}
//		printf("\n");
//
//
//
//	}
//
//
//
//
//
//
//
//
//
//	return 0;
//}
//int main()
//{
//	int i = 1;
//	int flag = 1;
//	float sum = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		sum = 1.0 / i*flag + sum;
//		flag = -flag;
//		
//
//	}
//	printf("%f", sum);
//
//
//
//
//
//	return 0;
//}
//
int main()
{
	int a = 24;
	int b = 6;
	int c = a % b;
	while (c != 0)
	{
		a = b;
		b = c;
		c = a % b;
		
	}
	printf("%d", b);

	return 0;
}






