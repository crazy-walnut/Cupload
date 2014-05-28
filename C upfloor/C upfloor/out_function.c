#include "test.h"

extern void sort(stu student[],int n)	//Ñ¡ÔñÅÅĞòÉıĞò
{
	int i,j,k;
	stu temp;
	for(i=0;i<n;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
		{
			if(student[k].score>student[j].score)
			{
				k=j;
			}
		}
		if(k!=i)
		{
			temp=student[i];
			student[i]=student[k];
			student[k]=temp;
		}
	}
}