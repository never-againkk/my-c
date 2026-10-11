#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
//review 单身狗2
//void find(int arr[], int len, int* a, int* b)
//{
//	int ret = 0;
//	for (int i = 0; i < len; i++)
//	{
//		ret ^= arr[i];
//	}
//	int pos = 0;
//	for (int i = 0; i < 32; i++)
//	{
//		if ((ret >> i) & 1 == 1)
//		{
//			pos++;
//			break;
//		}
//	}
//	for (int i = 0; i < len; i++)
//	{
//		if ((arr[i] >> pos) & 1 == 1)
//		{
//			*a ^= arr[i];
//		}
//		else
//		{
//			*b ^= arr[i];
//		}
//	}
//}
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int arr[20] = { 1,1,2,2,3,3,4,4,5,6 };
//	int len = sizeof(arr) / sizeof(arr[0]);
//	find(arr, len, &a, &b);
//	printf("%d %d", a, b);
//	return 0;
//}
int main()
{
	return 0;
}

//==================== 优化版：上面你的代码原样保留，这里是改好的写法 ====================
//
// 主要改动：
//   1) 原来的 pos 恒等于 1（pos++ 在 break 之前只执行一次），分组用的位被写死成 bit 1，
//      两个单身狗在该位上相同时就会算错，例如 {1,1,4,8} 原版输出 0 12；
//      这里直接取最低位的 1：lowbit = xor_all & (-xor_all)，一步到位且必定正确。
//   2) (x >> pos) & 1 == 1 会被解析成 (x >> pos) & (1 == 1)，MSVC 会报 C4554，
//      所以用 & 时一定要加括号。
//   3) int arr[20] = {...} 的 sizeof 长度是 20 而不是 10，改成 int arr[] 交给编译器推导。
//   4) *a / *b 在函数内部清零，形参加 const，printf 补换行。
//
// 想编译运行这段：把下面的 #if 0 改成 #if 1，并把文件上面那个
// int main() { return 0; } 注释掉（一个程序只能有一个 main）。
// printf 用文件开头已经包含的 <stdio.h>。
// 这段代码已单独编译运行验证过，输出：5 6

#if 0

void find(const int arr[], int len, int* a, int* b)
{
	*a = 0;
	*b = 0;

	int xor_all = 0;
	for (int i = 0; i < len; ++i)
	{
		xor_all ^= arr[i];
	}
	if (xor_all == 0)			// 全部成对，没有两个不同的单身狗
	{
		return;
	}

	int lowbit = xor_all & (-xor_all);	// 只保留最低位的 1，替代原来逐位找位置的循环

	for (int i = 0; i < len; ++i)
	{
		if (arr[i] & lowbit)			// 按这一位分组，两个单身狗必然被分到不同组
		{
			*a ^= arr[i];
		}
		else
		{
			*b ^= arr[i];
		}
	}
}

int main(void)
{
	int arr[] = { 1, 1, 2, 2, 3, 3, 4, 4, 5, 6 };
	int len = (int)(sizeof(arr) / sizeof(arr[0]));

	int a = 0;
	int b = 0;
	find(arr, len, &a, &b);

	printf("%d %d\n", a, b);
	return 0;
}

#endif
