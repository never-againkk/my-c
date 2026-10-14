#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
//char*my_strncpy(char* str1, const char* str2, int  len)
//{
//	int count = 0;
//	int i = 0;
//	for ( i = 0; str2[i]!='\0' && i < len; i++)
//	{
//		str1[i] = str2[i];
//		count++;
//	}
//	if (count < len)
//	{
//		str1[i] = '\0';
//	}
// return str2;
//}
//char* my_strncat(char* arr1, char* arr2, int len)
//{
//	char* tmp = arr1;
//	while (*tmp)
//	{
//		tmp++;
//	}
//	for (int i = 0; i < len&&arr2[i]!='\0'; i++)
//	{
//		tmp[i] = arr2[i];
//	}
//	arr1 = tmp;
//	return arr2;
//}
//int main()
//{
//	char arr1[20] = "abcdefg";
//	char* arr2 = "hello";
//	my_strncat(arr1, arr2, 10);
//	printf("%s", arr1);
//}
//宏复习
//int max(int a,int b)
//{
//	return(a > b ? a : b);
//}
//#define GENERAIC_MAX(type)  \
//type type##_max(type x,type y)\
//{\
//	return (x > y ? x : y);\
//}
//#define square(x) ((x)*(x))
////#undef square
//int main()
//{
//	printf("%d", square(9));
//	return 0;
//}
//#define PRINT(n,format)\
//printf("the value of "#n" is "format"\n")
//
//int main()
//{
//	PRINT(a, "10");
//	return 0;
//}
//水仙花数
//#include <math.h>
//int main()
//{
//	for (int i = 0; i < 100000; i++)
//	{
//		int count = 0;
//		int tmp = i;
//		while (tmp)
//		{
//			tmp/= 10;
//			count++;
//		}
//		tmp = i;
//		int sum = 0;
//		while (tmp)
//		{
//			sum += pow(tmp% 10, count);
//			tmp /=10;
//		}
//		if (sum == i)
//		{
//			printf("%d\n", i);
//		}
//	}
//
//
//	return 0;
//}
//变种水仙花数
//int main()
//{
//	int tmp = 0;
//	int count = 0;
//	for (int i = 10000; i < 99999; i++)
//	{
//		 tmp = i;
//		 while (tmp)
//		 {
//			 i /= 10;
//			 count++l;
//		 }
//		 tmp = i;
//		 int sum = 0;
//		 while (tmp)
//		 {
//			 tmp %= pow(10, count - 1);
//			 tmp
//		}
//	}
//
//
//
//	return 0;
//}
//int main()
//{
//	int i = 0;
//	for (i = 10000; i < 99999; i++)
//	{
//		int j = 0;
//		int sum = 0;
//		int tmp = i;
//		for (j = 10; j < 10000; j *= 10)
//		{
//			sum = sum + (tmp % j) * (tmp / j);
//		}
//		if (sum == i)
//		{
//			printf("%d ",i);
//		}
//	}
//
//
//
//	return 0;
//}
//删除数字
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int arr[50] = { 0 };
//	
//		for (int i = 0; i < n; i++)
//		{
//			scanf("%d", arr[i]);
//		}
//		int m;
//		scanf("%d", m);
//		for (int j = 0; j < n; j++)
//		{
//			if (arr[i] == m)
//			{
//				arr[i] = ;
//			}
//	}
//	return 0;
//}
int main()
{
	int n = 0;
	scanf("%d", n);
	int arr[50] = { 0 };
	for (int i = 0;i < n; i++)
	{
		scanf("%d", arr[i]);
	}
	int del;
	scanf("%d", &del);
	int i = 0;
	int j = 0;
	for (i = 0; i < n; i++)
	{
		if (arr[i] != del)
		{
			j++;
		}
		else
		{
			arr[j] = arr[i];
		}
	}
	for (int k = 0; k < j ; k++)
	{
		printf("%d", arr[k]);
	}



	return 0;
}