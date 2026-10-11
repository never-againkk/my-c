#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//int main()
//{
//	int n ;
//	scanf("%d", &n);
//	int i = 0;
//	
//	for (i = 0; i <=n ; i++)
//	{
//		
//		for ( int j = 0; j <= n; j++)
//		{
//			if (j == i || i + j == n)
//				printf("*");
//			else
//				printf(" ");
//
//		}
//		printf("\n");
//	}
//	return 0;
//}
//int main()
//{
//	int m;
//	int n;
//	
//	scanf("%d%d", &m,&n);
//	int arr[m][n];
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			scanf("%d", &arr[i][j]);
//		}
//	}
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < m; j++)
//		{
//			printf("%d", arr[j][i]);
//		}
//	}
//
//
//
//
//
//		return 0;
///
int bin_reserch(int arr[], int left, int  right, int key){
	{
		int mid = 0;

			while (left <= right)

			{
				mid == (right + left) / 2;
				if (arr[mid] > key)
				{

					right = mid - 1;
				}
				else if (arr[mid] < key) {


					left = mid + 1;
				}
				else {
					return mid;
				}
			}
			return -1;
	}


}
int main()
{
	int arr[9] = { 1,2,3,4,5,6,7,8,9 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int ret= bin_reserch(arr, 0, len - 1, 6);
	if (ret == -1)
	{

		printf("wrong");
	}
	else {


		printf("ур╣╫ак%d",ret);
	}
	return 0;
}











