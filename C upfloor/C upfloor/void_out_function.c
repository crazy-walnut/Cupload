#include "test.h"
void print(stu student[],int n)
{
	int i;
	for (i=0;i<n;i++)
	{
		printf("学生%s的成绩为%d\n",student[i].name,student[i].score);
	}
	printf("\n");
	return;
}
