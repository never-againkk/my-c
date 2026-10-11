#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
//void find(int arr[], int len, int *num1, int *num2)
//{
//	int tmp = 0;
//	for (int i = 0; i < len; i++)
//	{
//		tmp ^= arr[i];
//	}
//
//	int pose = 0;
//	for (int i = 0; i < 32; i++)
//	{
//		if (((tmp >> i) & 1) == 1)
//		{
//			pose = i;
//			break;
//		}
//	}
//
//	*num1 = 0;
//	*num2 = 0;
//	for (int i = 0; i < len; i++)
//	{
//		if (((arr[i] >> pose) & 1) == 1)
//		{
//			*num1 ^= arr[i];
//		}
//		else
//		{
//			*num2 ^= arr[i];
//		}
//	}
//}
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int arr[20] = { 1,1,2,2,3,3,4,4,5,6 };
//	int len = sizeof(arr) / sizeof(arr[0]);
//	find(arr, len, &a, &b);
//	printf("%d %d", a, b);
//	return 0;
//}

int main()
{
	char arr1 = "abcdef";
	char arr2 = "def";
	char arr3 = "tttt";
	char* p = strstr(arr1, arr2);
	if (p == NULL)
	{
		printf("arr1²»´æÔÚarr2");
	}
	else
	{
		printf("%p",p);
	}

	return 0;
}