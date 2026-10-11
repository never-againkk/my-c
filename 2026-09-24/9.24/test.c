#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	
	int sum = 0;

	int ret = 1;
	for(int n=0;n<=10;n++)
	{
		int i = 0;

		for (i = 1; i <= n; i++)
		{
			ret *= i;

		}
		sum += ret;
	}
	printf("%d",sum);
	return 0;
}