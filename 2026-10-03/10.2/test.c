#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
////void leftround(char arr[],int k)
////{
////	char tmp[256] = { 0 };
////	int len = strlen(arr);
////	int time = k % len;
////	strcpy(tmp, arr+time);
////	strncat(tmp, arr ,time);
////	strcpy(arr, tmp);
////
////}
////int main()
////{
////	char arr[] = "abcdef";
////	leftround(arr,1);
////	printf("%s", arr);
////	return 0;
////}
//char* judge(char arr[],char str[])
//{
//	char tmp[256] = { 0 };
//	strcpy(tmp, arr);
//	strcat(tmp, arr);
//	return strstr(tmp, str);
//
//}
//int main()
//{
//char arr[] = "abcdef";
//char str[] = "bcdefa";
//int ret = judge(arr, str);
//if (ret == NULL)
//{
//	printf("’“µΩ¡À");
//}
//else
//{
//	printf("√ª’“µΩ");
//}
//
//	return 0;
//}
//void func(int arr[][3],int x,int y,int key)
//{
//	int i = 0;
//	int j = y - 1;
//	while(i<x&&j>=0)
//		if (arr[i][j] < key)
//		{
//			i++;
//		}
//	if (arr[i][j] > key)
//	{
//		j--;
//	}
//	else
//	{
//		return 1;
//	}
//	return 0;
//}
//int main()
//{
//	int* p = (int*)malloc(10 * sizeof(int));
//	if (p == NULL)
//	{
//		printf("∏≥÷µ ß∞‹");
//		return 1;
//	}
//	int i = 0;
//	for(i=0;i<10;i++)
//	{
//		p[i] = i;//*(p+i)=i
//	}
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d", p[i]);
//	}
//	int *tmp=realloc(p,)
//	return 0;
//}
//struct s
//}
//	int n;
//	int num[];
//};
//int main()
//{
//	struct s* ps = (struct s*)malloc(sizeof(struct s) + 5 * sizeof(int));
//	if(ps==NULL)
//		{
//		printf("malloc ß∞‹");
//		return 1;
//	}
//	ps->n = 100;
//	for (int i = 0; i < 5; i++)
//	{
//		ps->num[i] = i + 1;
//
//	}
//	struct s*p =realloc(ps, sizeof(struct s) + 5 * sizeof(int));
//	if (p == NULL)
//	{
//		printf(" ß∞‹");
//		return 1;
//	}
//	else
//	{
//		ps = p;
//		p = NULL;
//	}
//	free(ps);
//	ps = NULL;
//
//	return 0;
//}
struct s
{
	int n;
	int* num;
}