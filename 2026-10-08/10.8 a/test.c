#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int add(int a, int b)
{
	return a / b;
}
int main()
{
	int result;
	result = add(36, 6);
	printf("%d",result);
	return 0;
}