#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
//int main()
//{
//	int n = 0;
//	srand((unsigned int)time(NULL));
//	/*printf("%d\n", rand()*/
//	/*srand((unsigned int)time(null)););
//	printf("%d\n", rand());
//	printf("%d\n", rand());*/
//	for (n; n < 10; n++)
//	{
//		
//		printf("%d\n", rand()%10);
//
//	}
//
//
//	return 0;
//}
int main()
{
	int n = 0;
	int i = 0;
	scanf("%d", &n);
	do
	{
		n % 10 == i;
		n /=10;


	} while (n != 0);
	printf("%d", i);

}
