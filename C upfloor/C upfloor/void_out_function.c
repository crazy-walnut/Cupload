#include "test.h"
void print(stu student[],int n)
{
	int i;
	for (i=0;i<n;i++)
	{
		printf("ѧ��%s�ĳɼ�Ϊ%d\n",student[i].name,student[i].score);
	}
	printf("\n");
	return;
}
