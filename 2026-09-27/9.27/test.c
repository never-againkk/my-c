#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
struct stu
{
	char name[20];
	int age;
	char sex[10];
	char id[20];

};
void print(struct stu* s)
{
	printf("%s", s->name);
	
}




int main()
{
	struct stu s1 = { "×°Èý",18,"ÄÐ","2034877"};
	struct stu s2 = { .age = 16,.sex = "female",.name = "alice",.id = "77777" };
	/*printf("age:%d", s1.age);
	printf("\n");
	struct stu* ps = &s1;
	printf("%s", ps->name);*/
	print(&s1);
	return 0;
}