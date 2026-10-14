#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
//void* my_memcpy(void* arr1, void* arr2, size_t num)
//{
//	while (num--)
//	{
//		*(char*)arr1 = *(char*)arr2;
//		arr1 = (char*)arr1 + 1;
//		arr2 = (char*)arr2 + 1;
//	}
//	return arr1;
//}
//int main()
//{
//	int arr1[5] = { 1, 2, 3, 4, 5 };
//	int arr2[20] = { 0 };
//	my_memcpy(arr2, arr1, sizeof(arr1));
//	for (int i = 0; i < 5; i++)
//	{
//		printf("%d",arr2[i]);
//	}
//	return 0;
//}
//void* my_memmove(void* arr1, void* arr2, size_t num)
//{
//	if (arr1 < arr2)
//	{
//		while (num--)
//		{
//			*(char*)arr1 = *(char*) arr2;
//			arr2 = (char*)arr2 + 1;
//			arr1 = (char*)arr1 + 1;
//		}
//	}
//	else
//	{
//		while (num--)
//		{
//			*((char*)arr1 + num) = *((char*)arr2 + num);
//
//
//		}
//		return arr1;
//	}
//}
//int main()
//{
//	int arr1[20] = { 1,2,3,4,5,6,7,8,9,10 };
//	size_t sz = sizeof(arr1);
//	my_memmove(arr1+3, arr1+4, sz);
//	
//}
int main()
{
	int arr1[20] = {0};
	memset(arr1, 1, 20);



	return 0;
}