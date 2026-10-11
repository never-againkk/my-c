#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
/*int main()
{
	int a = 10;
	int b = 20;
	a = a + b;
	b = a - b;
	a = a - b;
	printf("%d %d", a, b);

	return 0;
}*/
//int main()
//{
//	int a = 10;
//	int b = 20;
//	a = a ^ b;
//	b = a ^ b;
//	a = a ^ b;
//
//
//	return 0;
//
//int getcount(int x)
//{
//	int count = 0;
//	while (x)
//	
//	{
//		if (x % 2 == 1)
//			count++;
//		x /= 2;
//	}
//	return count;
//}
//
//
//int main()
//{
//	int i;
//	scanf("%d", &i);
//	int ret = getcount(i);
//	printf("%d", ret);
//
//	return 0;
//}
//int main()
//{
//	unsigned int num = 4;
//	int i = 0;
//	int count = 0;
//	for (i = 0; i < 32; i++)
//	{
//		if (num & 1 == 1)
//			count++;
//	}
//	printf("%d", count);
//	return 0;
//}
//int main()
//{
//	int num = 3;
//	int count = 0;
//	while (num)
//	{
//		num = num & (num - 1);
//			count++;
//	}
//	printf("%d", count);
//	return 0;
//}
//int main()
//{
//	int num = 13;
//	num |= (1 << 4)//±ä³É1
//		num &= ~(1 << 4);
//
//	return 0;
//}
//int main()
//{
//	int total = 20;
//	int empty = 20;
//	while (empty>1)
//	{
//		total = total + empty / 2;
//		empty = empty / 2 + empty % 2;
//	}
//	printf("%d", total);
//	return 0;
//}
//int main()
//{
//
//	for (int i = 1; i < 10000; i++)
//	{
//		int count = 0;
//		int tmp = i;
//		while (tmp != 0)
//		{
//			tmp /= 10;
//			count++;
//		}
//		tmp = i;
//		int sum = 0;
//		while (tmp != 0)
//		{
//			sum = sum + pow(tmp % 10, count);
//			tmp /= 10;
//		}
//		if (sum==i )
//		{
//			printf("%d\n", i);
//		}
//	}
//
//
//	return 0;
//}
//int func(int x,int y)
//{
//	if (y == 1)
//		return x;
//	else
//		return x * func(x, y - 1);
//}
//
//
//int main()
//{
//	int i = 7;
//	printf("%d", func(i,6));
//	return 0;
//}
//int ggboom(int n)
//{
//	if (n < 10)
//	{
//		return n;
//	}
//	else
//	{
//		return ggboom(n / 10) + n % 10;
//	}
//}
//
//int main()
//{
//	printf("%d", ggboom(6));
//	return 0;
//}
int fun(int n)
{
	if (n = 1)
	{
		return 0;
	}
	else
	{
		return n * fun(n - 1);
	}

	int main()
	{
		printf("%d", fun(4));
			return 0;
	}




