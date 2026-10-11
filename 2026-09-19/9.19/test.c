#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//void set_arr(int arr[10],int sz)
//{
//	int i = 0;
//		for (i = 0; i<sz;i++)
//		{
//			arr[i] = -1;
//
//		}
//
//
//}
//void print(int arr[10], int sz)
//{
//	int i = 0;
//	for (i = 0; i <sz ;i++)
//	{
//		printf("%d",arr[i]);
//	}
//	printf("\n");
//
//
//
//}
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	set_arr(arr, sz);
//	print(arr, sz);
//	return 0;
//}
void print(int arr[3][5], int x, int y)
	{
		int i = 0;
for (i = 0; i < x; i++)
{
	int j = 0;
	for (j = 0; j < y; j++)
	{
		printf("%d", arr[i][j] );
	}
}
printf("\n");
	}



int main()
{
	int arr[3][5] = { 1,2,3,4,5, 2,3,4,5,6, 3,4,5,6,7 };
	print(arr, 3, 5);

	return 0;
}

















