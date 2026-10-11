#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <string.h>
//int main()
//{
//	int arr[10] = { 0 };
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	for (i = 0; i < 10; i++)
//		printf("%d/n", arr[i]);
//	return 0;

//int main()
//{
//	int i = 0;
//	srand((unsigned int)time(NULL));
//	for (i = 0; i < 10; i++) {
//
//
//		printf("%d\n", rand() % 100);
//	}
//
//
//
//	return 0;
//}
//
//
//
//
//}int main()
//{
//	int i = 0;
//	int arr[10] = { 0 };
//	int sz = sizeof(arr) / sizeof arr[0];
//	for (i = 0; i < sz; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	for (i = 0; i < sz; i++)
//	{
//
//		printf("%d\n", arr[i]);
//	}
//
//	//return 0;
//
//int main()
//{
//	int arr[10] = { 0 };
//	int i = 0;
//	int sz = sizeof(arr) /sizeof(arr{ 0 });
//	for (i = 0; i < sz; i++)
//		printf("%p", &arr[i]);
//
//
//
//
//
//
//	return 0;
// }
int main()

char arr1[] = "huang xin yan is pig";
char arr2[] = "####################";
int left = 0;
int right = strlen(arr1) - 1;
while (left <= right)
{
	arr1[left] = arr2[left];
	arr1[right] = arr2[right];
	printf("%s/n", arr2);
	left++;
	right--;
}

	return 0;
}
















