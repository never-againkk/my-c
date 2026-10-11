#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
//int main()
//{
//char arr1[] = "huang xin yan is pig";
//char arr2[] = "####################";
//int left = 0;
//int right = strlen(arr1) - 1;
//while (left <= right)
//{
//	arr2[left] = arr1[left];
//	arr2[right] = arr1[right];
//	printf("%s\n", arr2);
//	Sleep(1000);
//	left++;
//	right--;
//}
//
//return 0;
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10};
//	int k = 9;
//	int left = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int right = sz - 1;
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid] > k) {
//
//			right = mid - 1;
//		}
//		else if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else {
//			printf("找到了是%d", mid);
//			break;
//		}
//	}
//	if (left > right)
//	{
//		printf("找不到");
//	}
//	return 0;
//}


void menu()
{

	printf("---------------------\n");
	printf("---------------------\n");
	printf("-------play:1--------\n");
	printf("-------exist:0-------\n");
	printf("---------------------\n");

}

void game()
{
	int r = rand() % 100 + 1;
	int guess = 0;
	while (1)
	{
		printf("请猜数字:");
		scanf("%d", &guess);
		if (guess < r)
		{
			printf("猜小了\n");
		}
		else if (guess > r)
		{
			printf("猜大了\n");
		}
		else
		{
			printf("恭喜你，猜对了\n");
			break;
		}
	}
}
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	
	do
	{
		menu();
		printf("请选择:\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 2:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误\n请重新输入:\n");
			break;
		}

	}
		while (input!=0);
	return 0;
}




















