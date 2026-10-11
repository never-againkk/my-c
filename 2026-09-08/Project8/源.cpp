#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 0;
//	float c = 0;
//	scanf("%d %d %f", &a, &b, &c);
//		printf("%d\n",a);
//		printf("%d\n", b);
//			printf("%f\n",c);
//	return 0;
//}
//int main()
//{/*int a = 2;
//	int b = 4;
//	
//	printf("%d",(a+b)/2);
//*/
//
//	return 0;
//}
int main()
{
	int a = 0;
	int b = 0;
	int c = a + b;
	while (scanf("%d %d", &a, &b) == 2)
	printf("%d\n", c);
	return 0;
}

