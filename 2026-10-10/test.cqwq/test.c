#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
//int main()
//{
//	int r = islower('x');
//	if (r)
//	{
//		printf("x");
//	}
//	else
//	{
//		printf("d");
//	}
//	return 0;
//}
//int main()
//{
//	char arr[] = "I like c";
//	int i = 0;
//	while (arr[i]!= 0)
//	{
//		if (islower(arr[i]))
//		{
//		//	arr[i] -= 32;
//			arr[i] = toupper(arr[i]);
//		}
//		
//		putchar(arr[i]);
//		i++;
//
//	}
//	//printf("%s\n", arr)
//
//	return 0;
////}
//size_t my_strlen(const char* s)
//{
//	if (*s == '\0')
//	{
//		return 0;
//	}
//	else
//	{
//		return 1 + my_strlen(s + 1);
//	}
//
//}
//int main()
//{
//	size_t len = my_strlen("abcde");
//	printf("%zu", len);
//	return 0;
//}
//char* my_strcpy(char* ttg,const char* arr)
//{
//	char* dest = ttg;
//	while (*arr != '\0')
//	{
//		*ttg = *arr;
//		arr++;
//		ttg++;
//	}
//	*ttg = *arr;
//	return dest;
//}
//
//
//
//
//
//
//int main()
//{
//	char arr[] = "abcdef";
//	char ttg[20] = { 0 };
//	my_strcpy(ttg,arr);
//	printf("%s", ttg);
//	return 0;
//}
int my_strcmp(const char* arr1, const char* arr2)
{
	while (*arr1 == *arr2)
	{
		if (*arr1 == '\0')
		{
			return 0;
		}
		arr1++;
		arr2++;
	}
	return *arr1 - *arr2;
	if (*arr1 > *arr2)
	{
		return 1;
	}
	if (*arr1 < *arr2)
	{
		return -1;
}
	
	int main()
{
	char arr1[20] = "abcdef";
	char arr2[20] = "abcfqq";
	int ret=my_strcmp(arr1,arr2);

	if (ret < 0)
	{
		printf("<\n");
	}
	if (ret > 0)
	{
		printf(">\n");
	}
	else 
	{
		printf("=\n");
	}
	return 0;
}