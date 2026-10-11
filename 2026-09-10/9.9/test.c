#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int max = 0;
//	scanf("%d %d", &a, &b);
//	if (a > b)
//		max = a;
//	if (a < b)
//		max = b;
//	printf("%d", max);
//		return 0;
//}
int main()
{
	int n = 0;
	scanf("%d", &n);
	if (n%2== 1)
		printf("奇数");
	else printf("偶数");
	return 0;
}