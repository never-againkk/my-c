#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h>
//int compare_int(const void* p1, const void* p2)
//{
//	return (*(int*)p1 - *(int*)p2);
//
//}
//void test()
//{
//	int arr[5] = { 3,2,5,6,1};
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	qsort(arr, sz, sizeof(arr[0]), compare_int);
//		for (int i = 0; i < sz; i++)
//		{
//			printf("%d", arr[i]);
//		}
//
//
//
//}
//int main()
//{
//	test();
//	return 0;
//}
//int main()
//{
//
//
//
//
//	return 0;
//}
//struct stu
//{
//	char name[20];
//	int age;
//};
//int cmp_stu(const void* p1,const void* p2)
//{
//	return ((struct stu*)p1)->age - ((struct stu*)p2)->age;
//}
//void test()
//{
//	struct stu s[3] = {{"zhangsan",14},{"lisi",18},{"wangwu",19}};
//	int sz = sizeof(s) / sizeof(s[0]);
//	qsort(s, sz, sizeof(s[0]), cmp_stu);
//	for (int i = 0; i < 3; i++)
//	{
//
//		printf("name %s age %d", s[i].name, s[i].age);
//
//	}
//}
//
//
//int main()
//{
//	test();
//	
//
//	return 0;
//} 
//void _swap(char* buf1, char* buf2,size_t size)
//{
//	for (int i = 0; i < size; i++)
//	{
//		char tmp = *buf1;
//		*buf1 = *buf2;
//		*buf2 = tmp;
//		buf1++;
//		buf2++;
//	}
//
//}
//void my_bubsort(void*base,size_t sz,size_t size,int (*cmp)(const void* p1,const void*p2))
//{
//	int i = 0;
//	for (i = 0; i < sz - 1; i++)
//	{
//		int j = 0;
//		for (j = 0; j < sz - i - 1; i++)
//		{
//			if (cmp((char*)base+j*size, (char*)base+(j+1)*sz) > 0);
//			{
//				_swap((char*)base + j * size, (char*)base + (j + 1) * sz,size);
//			}
//		}
//	}
//}
//int main()
//{
//	return 0;
//}