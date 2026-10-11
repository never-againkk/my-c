#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int check()
{
	int a = 1;
	char* pa = (char*)&a;
	return *pa;
}
int main()
{
	int ret = check;
	if (ret = 1)
	{
		printf("Ð¡¶Ë");
	}
	else
	{
		printf("´ó¶Ë");
	}
	return 0;
}