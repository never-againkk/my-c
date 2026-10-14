#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n = 0;
	scanf("%d", &n);
	int arr[50] = { 0 };
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	int del;
	scanf("%d", &del);
	int i = 0;
	int j = 0;
	for (i = 0; i < n; i++)
	{
		if (arr[i] != del)
		{
			arr[j] = arr[i];
			j++;
		}
		else
		{
			arr[j] = arr[i];
		}
	}
	for (int k = 0; k < j; k++)
	{
		printf("%d", arr[k]);
	}



	return 0;
}