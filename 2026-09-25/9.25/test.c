#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//int fact(int n)
//{
//	if (n == 0)
//	{
//		return 1;
//	}
//	else
//	{
//		return n * fact(n-1);
//	}
//
//
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int r = fact(n);
//	printf("%d", r);
//	return 0;
//}

//int print(int n)
//{
//	if (n > 9)
//	{
//		print(n / 10);
//	}
//	printf("%d ", n % 10);
//}
//int main()
//{
//	
//	int n = 0;
//	scanf("%d", &n);
//	print(n);
//
//
//	return 0;
//}
//int Fib(int n)
//{
//	if (n == 0)
//		return 0;
//	if (n == 1)
//		return 1;
//	else if (n >= 2)
//		return  Fib(n - 1) + Fib(n - 2);
//
//}
//
//
//
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int r = Fib(n);
//	printf("%d", r);
//	return 0;
//}
int fib(int n)
{
	int a = 0;
	int b = 1;
	int c = n;
	while (n >= 2)
	{
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return c;
}





int main()
{
	

	int n = 0;
	scanf("%d", &n);
	int r = fib(n);

	printf("%d", r);
	return 0;
}







