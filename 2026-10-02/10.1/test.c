#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
//void reverse(char* n)
//{
//	char* left = n;
//	int len = strlen(n);
//	char* right = left + len - 1;
//	while (left < right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//	}
//}
//int main()
//{
//	char arr[100000] = { 0 };
//	while (fgets(arr,10000,stdin));
//	{
//		reverse(arr)
//	}
//	return 0;
//}
//void leftround(char* str,int k)
//{
//	int len = strlen(str);
//	int time = k % len;
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < time; i++)
//	{
//		char tmp = str[0];
//		for (j = 0; j < len - 1; j++)
//		{
//			str[j] = str[j + 1];
//		}
//		str[j] = tmp;
//	}
//}
//int main()
//{
//	char str[] = "abcde";
//	leftround(str, 2);
//	printf("%s", str);
//	return 0;
//}
//void func(r)
//{
//	int left = 0;
//	int len = strlen(arr);
//	int right = len-1;
//	while (left < right)
//	{
//		while (left < right && arr[left] % 2 != 0)
//		{
//			left++;
//		}
//		while (left < right && arr[left] % 2 == 0)
//		{
//			right--;
//		}
//		int tmp = 0;
//		tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = tmp;
//	}
//}
//int fun(int arr[], int len)
//{
//	int ret = 0;
//	for (int i = 0; i <= len - 1; i++)
//	{
//		ret ^= arr[i];
//	}
//	return ret;
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,4,3, 2, 1};
//	int len = sizeof(arr) / sizeof(arr[0]);
//	printf("%d", fun(arr, len));
//
//
//	return 0;
//}
//void fun(int n)
//{
//	for (int i = 30; i >= 0; i -= 2)
//	{
//		printf("%d", (n>>i) & 1);
//	}
//	printf("\n");
//	for (int i = 31; i >= 1; i -= 2)
//	{
//		printf("%d", (n>>i)&1);
//	}
//
//}
//int main()
//{
//	fun(4);
//	return 0;
//}
//void bubble(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i <= sz - 1; i++)
//	{
//		int j = 0;
//		int flag = 0;
//		for (j = 0; j <sz-1-i ; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				flag = 1;
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//
//			}
//		}
//		if (flag = 1)
//			break;
//	}

//}
//void print(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//}
//
//int main()
//{
//	int arr[] = { 10,9,8,7,6,5,4,3,2,1 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	bubble(arr, sz);
//	print(arr, sz);
//
//	return 0;
//}
//int main()
//{
//	int arr[10] = { 0 };
//	&arr;
//	int (*p)[10] = &arr;
//
//
//
//	return 0;
//}
//int main()
//{
//	int arr1[] = { 1,2,3,4,5,6,7 };
//	int arr2[] = { 1,2,3,4,5 };
//	int arr3[] = { 3,4,5,6,7,8 };
//	int* parr[3] = { arr1,arr2,arr3 };
//	int i = 0;
//	for (i = 0; i <= 2, i++)
//	{
//		int j = 0;
//		for(j=0)
//	}
//
//	return 0;
//}
void yanghui(int arr[][4],int n)
{
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0 || j == i)
			{
				arr[i][j] = 1;
			}
			else
			{
				arr[i][j] == arr[i - 1][j] + arr[i - 1][j];
			}
		}

	}



}


int main()
{

	return 0;
}