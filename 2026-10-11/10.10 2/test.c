#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <errno.h>
//char* my_strstr(char* str1, char* str2)
//{
//	int count = 0;
//	while (*str1 != '\0' && *str2 != '\0')
//	{
//		int count = 0;
//		while (*str1 != *str2)
//		{
//			str1++;
//			str2++;
//			count++;
//		}
//		if(*str1==*str2)
//		{
//			return str1 + count;
//			break;
//		}
//		if (count == 0)
//		{
//			return NULL;
//		}
//	}
	
//}
//char* my_strstr(const char*str1,char*str2)
//{
//	if (*str2 == '0')
//	{
//		return *str1;
//	}
//	char* cur = str1;
//	char* s1 = NULL;
//	char* s2 = NULL;
//	while (*cur != '\0')
//	{
//		s1 = cur;
//		s2 = str2;
//		while (*s1 && *s2 &&*s1== *s2)
//		{
//			s1++;
//			s2++;
//		}
//		if (*s2 == '\0')
//		{
//			return cur;
//		}
//		cur++;
//	}
//	return NULL;
//}
//int main()
//{
//	char arr1[20] = "abcdef";
//	char arr2[20] = "def";
//	char arr3 [20] = "tttt";
//	/*char* p = strstr(arr1, arr2);*/
//	char* p = my_strstr(arr1, arr2);
//	if (p == NULL)
//	{
//		printf("arr1不存在arr2");
//	}
//	else
//	{
//		printf("%p", p);
//	}
//
//	return 0;
//}
//int main()
//{
//	char* arr = "zhabng@uuuiii.kkk";
//	char* buf[30] = { 0 };
//	snprintf(buf, sizeof(buf), arr);
//	printf("%s\n", buf);
//	const char* sep = "@.";
//	char*r=strtok(buf, sep);
//	printf("%s\n", r);
//	 r = strtok(NULL, sep);
//	printf("%s\n", r);
//
//
//
//	return 0;
//}
//int main()
//{
//	char* arr = "zhabng@uuuiii.kkk";
//	char* buf[30] = { 0 };
//	snprintf(buf, sizeof(buf), arr);
//	char* r = NULL;
//		const char* sep = "@.";
//	for (r=strtok(buf, sep); r != NULL; r =strtok(NULL, sep))
//	{
//		printf("%s\n", r);
//	}
//	return 0;
//}
//int main()
//{
//	char* arr = "zhabng@uuuiii.kkk";
//		char* buf[30] = { 0 };
//		snprintf(buf, sizeof(buf), arr);
//		 const char* sep = "@ .";
//		 char* r = NULL;
//		 for (r = strtok(buf, sep); r != NULL; r = strtok(NULL, sep))
//		 {
//			 printf("%s\n", r);
//		 }
//
//	return 0;
//}
//char* my_strstr(const char* str1, const char* str2)
//{
//	char* cur = str1;
//	char* s1 = str1;
//	char* s2 = str2;
//	while (*cur != '\0')
//	{
//		s1 = cur;
//		s2 = str2;
//		while (*s1 == *s2 && *s1 != '\0')
//		{
//
//			s1++;
//			s2++;
//		}
//		if (*s2 == 0)
//		{
//			return cur;
//		}
//		cur++;
//	}
//}
//int main()
//{
//	char arr1[20] = "abcdef";
//	char arr2[20] = "def";
//	char arr3 [20] = "tttt";
//	/*char* p = strstr(arr1, arr2);*/
//	char* p = my_strstr(arr1, arr2);
//	if (p == NULL)
//	{
//		printf("arr1不存在arr2");
//	}
//	else
//	{
//		printf("%p", p);
//	}
//
//	return 0;
//}