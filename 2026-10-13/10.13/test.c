#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
//typedef struct date
//{
//	int year;
//	int month;
//	int day;
//}date;
//struct student
//{
//	char  name[20];
//	date birthday;
//	char num[20];
//};
//int main()
//{
//	struct student s = { "wangwu", { 2008,8,23 }, "2374824827" };
//	printf("%s %d %d %d %s", s.name, s.birthday.year,s.birthday.month,s.birthday.day, s.num);
//	return 0;
//}
//int check_big()
//{
//	union
//	{
//		char c;
//		int i;
//	}u;
//	u.i = 1;
//	return u.i;
//}
typedef enum
{
	red,
	green,
	yellow
}trflight;
int main()
{
	const char* message[20] = { [red] ="红" ,[green] = "绿",[yellow] = "黄"};
	int seconds[20] = { [red] = 10,[green] = 10,[yellow] = 3 };
	trflight cur = red;
	while(1)
	{
		int sec = seconds[cur];
		printf("现在是%s 灯持续%d秒"，message[cur], seconds[cur]);
		for (int i = sec; i > 0; i--)
		{
			printf("剩余%d 秒", sec);
			sleep(1000);
		}
		trflight cur= (cur + 1)%3;
		
	}
	return 0;
}
