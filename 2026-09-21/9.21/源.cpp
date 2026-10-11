#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//int isPremi(int n)
//{
//	int j = 0;
//	for (j = 2; j < n; j++)
//	{
//		if (n % j == 0)
//		{
//			return 0;
//		}
//	}
//	return 1;
//}
//int main()
//{
//	int i = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		int ret = isPremi(i);
//		if (ret == 0)
//			printf("是质数%d", i);
//		else
//		{
//			printf("素数%d", i);
//		}
//	}
//	return 0;
//}
void init(int arr[10], int len)
{
	int i = 0;
	for (i = 0; i < len; i++)
		arr[i] = i + 1;

}
void print(int arr[10], int len)
{
	int i = 0;
	for (i = 0; i < len; i++)
	{
		printf("%d", arr[i]);
	}
	
}
void reverse(int arr[10], int len)
{
	int left = 0;
	int right = len-1;
	while (left < right)
	{
		int tmp = 0;
		tmp = left;
		right = tmp;
		left = tmp;
		right++;
		left--;
	}

}
int main()
{
	int arr[10] = { 0 };
	int len = sizeof(arr) / sizeof(arr[0]);
	init(arr, len);
		print(arr, len);
		reverse(arr, len);
}