#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//int main()
//{
//	int a = 10;
//	int* pa = &a;
//	printf("%d", *pa);
//
//	return 0;
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9 };
//	int i = 0;
//	int* pi = &arr[0];
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d", *(pi + i));
//	}
//	return 0;
//}
//size_t my_strlen(char* s)
//{
//	int count = 0;
//	while (*s != '\0')
//	{
//		count++;
//		s++;
//	}
//	return count;
//}
//
//
//
//
//int main()
//{
//
//	char arr[]="abcdef";
//	size_t len = my_strlen(arr);
//	printf("%d", len);
//	return 0;
//}
//size_t my_strlen(char* s)
//{
//	char* str = s;
//	char* end = s;
//	while (*end)
//	{
//		end++;
//
//	}
//	return end - str;
//}
//int main()
//{
//
//	char arr[]="abcdef";
//	size_t len = my_strlen(arr);
//	printf("%d", len);
//	return 0;
//}
//void swap(int* x, int* y) 
//{
//	int z = 0;
//	z = *x;
//	*x = *y;
//	*y = z;
//
//}
//
//
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	swap(&a, &b);
//	printf("%d %d", a, b);
//	return 0;
//}