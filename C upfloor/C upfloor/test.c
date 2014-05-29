#include "test.h"
/*�����������򣬺�����+����+ҳ��*/
int first()
{
	char *pa,a = 1 ;
	int		b= 2, *pb;
	double c =3,*pc;
	pa=&a;
	pb=&b;
	pc=&c;

	printf("char ��ָ��paռ���ڴ��СΪ��%d�ֽ�\n",sizeof pa);
	printf("int ��ָ��pbռ���ڴ��СΪ��%d�ֽ�\n",sizeof pb);
	printf("double ��ָ��pcռ���ڴ��СΪ��%d�ֽ�\n\n",sizeof pc);

	printf("char ��ָ��pa��ָ���ڴ�����Ĵ�СΪ��%d�ֽ�\n",sizeof(*pa));
	printf("int ��ָ��pb��ָ����ڴ�����Ĵ�СΪ��%d�ֽ�\n",sizeof(*pb));
	printf("double ��ָ��pc��ָ����ڴ�����Ĵ�СΪ��%d�ֽ�\n\n",sizeof(*pc));

	printf("char�ͱ���a�ĵ�ַΪ��%d\n",pa);
	printf("int �ͱ���b�ĵ�ַΪ��%d\n",pb);
	printf("double �ͱ���c�ĵ�ַΪ��%d\n",pc);

	getchar();

	return 0;
}

int second(void)
{
	char a[4];
	char (*pa)[4],*pb;

	pa = &a;			//pa��ָ�������ָ��
	pb = &a[0];

	printf("char ������ָ��pa��ռ�õ��ڴ�Ϊ:%d\n",sizeof(*pa));
	printf("char ��ָ��pb��ռ�õ��ڴ��СΪ��%d\n\n",sizeof(*pb));

	printf("pa = %d\tpa+1 = %d\n",pa,pa+1);
	printf("pb = %d\tpb+1 = %d\n",pb,pb+1);

	getchar();
	return 0;
}

int third()
{
	int a;
	int *pa;
	pa=&a;
	a=0x12345678;
	printf("int ��ָ��pa��ֵΪ��%x\n",pa);
	printf("char ��ָ��pa��ֵΪ��%x\n",(char*)pa);

	printf("int ��ָ��pa��ָ�ڴ浥Ԫ��ֵΪ��%x\n",*pa);
	printf("char ��ָ��pa��ָ�ڴ浥Ԫ��ֵΪ��%x\n",*(char*)pa);

	getchar();


	return 0;
}

int judgebig_store()		//�жϼ�������ô�˴洢����С�˴洢
{
	int a;
	int *pa;
	pa=&a;
	a=0x12345678;
	if(0x78==*(char*)pa)		//(char*)paָ���λ�ĵ�ַ
		printf("С��ģʽ!\n");
	else
	{
		printf("���ģʽ!\n");
	}
	getchar();

	return 0;
}

int error()					//����ָ���ʼ��ΪNULL�Ƿ��ܱ���ֵ
{
	int *pa;
	pa=NULL;
	/*int b;
	pa=&b;*/
	*pa=1;
	getchar();
	return 0;
}

int free_point()
{
	int *pa=(int *)malloc(sizeof(int)*9);
	int i;
	int a =12;

	for(i=0;i<9;i++)
	{
		*(pa+i)=rand()%100;
		printf("*(pa+%d)=%d\t",i,*(pa+i));
		if((i+1)%3==0)
			printf("\n");
	}
	free(pa);
	if(pa!=NULL)
	{
		pa=&a;
		printf("%d\n",*pa);
	}

	getchar();
	return 0;
}

int free_point2()
{
	int *pa = (int *)malloc(sizeof(int));
	*pa=726;

	printf("ʹ��free()����֮ǰpa = %d\n",pa);

	free(pa);
	printf("ʹ��free()����֮��pa = %d\n",pa);

	pa=NULL;				//�����ʹ��NULL��free��pa���ᱨ��
	free(pa);
	free(pa);
	getchar();
	return 0;
}

int advantage_option()
{
	int a[4];
	int *pa=NULL;
	int *pb=NULL;
	int i;
	printf("\nͨ������a��ֱ�Ӵ�ӡ���е�Ԫ��ֵ\n");
	for(i=0;i<4;i++)
	{
		a[i]=rand()%100;
		printf("a[%d] = %d\t",i,a[i]);
	}

	pa=a;
	printf("\nͨ��int��ָ��pa����Ӵ�ӡ����a�е�Ԫ��\n");
	for(i=0;i<4;i++)
	{
		printf("a[%d] = %d\t",i,*pa++);
	}

	pb =a;
	printf("\nͨ��int��ָ��pa����Ӵ�ӡ����a�е�Ԫ��\n");
	for(i=0;i<4;i++)
	{
		printf("a[%d] = %d\t",i,(*pb)++);
	}
	
	getchar();
	return 0;
}

int move_point()
{
	int a[4];
	int *pa=NULL;
	int *pb=NULL;
	int i;
	printf("\nͨ������a��ֱ�Ӵ�ӡ���е�Ԫ��ֵ\n");
	for(i=0;i<4;i++)
	{
		a[i]=i*2;
		printf("a[%d] = %d\t",i,a[i]);
	}
	printf("\n����a���׵�ַΪ%d\n",a);
	pa=a;
	
	for(i=0;i<4;i++)
	{
		printf("a[%d] = %d\t",i,*(pa++));
	}
	printf("\nͨ��*(pa+i)�����������a��Ԫ��֮��pa��ֵΪ��%d\n",pa);


	pb =a;
	for(i=0;i<4;i++)
	{
		printf("a[%d] = %d\t",i,*pb++);
	}
	printf("\nͨ��*pa+i�����������a��Ԫ��֮��pa��ֵΪ��%d\n",pb);
	getchar();
	return 0;
}

int array_point()
{
	int a[3][3];
	int i,j;
	int *pa;
	printf("ֱ�����ö�ά����a�е�Ԫ��\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			a[i][j]=i*3+j+1;
			printf("a[%d][%d] =%d\t ",i,j,a[i][j]);
		}
		printf("\n");
	}

	pa = a[0];
	printf("ͨ��ָ�����ö�ά����a�е�Ԫ��\n");
	for(i=0,j=0;pa<=&a[2][2];pa++)
	{
		printf("a[%d][%d]=%d\t",i,j,*pa);
		j++;
		if(3==j)
		{
			j=0;
			i++;
			printf("\n");
		}
	}
	getchar();
	return 0;
}

int dynamic_array()
{
	
	const int N=3;			//constȷ����ֵ������������֮��
	const int M=4;
	int *a[3];
	int i,j;

	for(i=0;i<N;i++)
	{
		if((a[i] = (int *)malloc(M*sizeof(int)))==NULL)
		{
			printf("����ʧ�ܣ�");
			exit(0);
		}
	}

	for(i=0;i<N;i++)
	{
		for(j=0;j<M;j++)
		{
			a[i][j]=i*M+j+1;
			printf("a[%d][%d]=%d\t",i,j,a[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<N;i++)			//��һ���ܹؼ�
	{
		free(a[i]);
	}
	getchar();
	return 0;
}

int dynamic_array_point_array()
{
	int (*a)[3];
	int i,j;
	const int N=3;
	const int M=4;
	if((a=(int(*)[3])malloc(N*M*sizeof(int)))==NULL)		//constȷ����ֵ������������֮��
	{
		printf("����ʧ�ܣ�");
		exit(0);
	}
	printf("����4X3��ά���鷽ʽ���ô����Ķ�̬����ʱ\n");
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
			a[i][j]=i*N+j+1;
			printf("a[%d][%d]=%d\t",i,j,a[i][j]);
		}
		printf("\n");
	}
	getchar();
	return 0;
}
//�ж��ļ��Ƿ���ȷ��
int error_ret(errno_t err)
{
	if(0==err)
	{
		printf("�ļ��򿪳ɹ���\n");
		return 0;
	}
	else
	{
		printf("�ļ���ʧ�ܣ�");
		return 0;
	}
}


void input(stu student [],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("������ѧ��������\n");
		scanf_s("%s",&student[i].name);
		printf("������ѧ���ܳɼ���\n");
		scanf_s("%d",&student[i].score);
	}
	return ;
}

/*********���static void ��ô�������ֻ���������ļ��ڱ�����***********/
/***********************�������������ĺ�����Ƚ�*********************/
static void input_1(stu student [],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("\n������ѧ��������");
		scanf_s("%s",&student[i].name, 10);
		printf("\n������ѧ���ܳɼ���");
		scanf_s("%d",&student[i].score);
	}
	return ;
}

void bubble_sort(stu student[],int n)		//ð������
{
	int i,j,flag;
	stu temp;
	
	for(i=0;i<n-1;i++)
	{
		flag=0;											//������治�ٱ仯flag=0
		for(j=0;j<n-i-1;j++)
		{
			if(student[j].score>student[j+1].score)
			{
				temp =student[j+1];
				student[j+1]=student[j];
				student[j]=temp;
				flag=1;
			}
		}
		if(0==flag)
			break;
	}
	return ;
}
void save_student_struct(stu student[],int n)		//����ṹ�嵽�ļ���
{
	int i;
	errno_t err;
	FILE *fpin;
	err=fopen_s(&fpin,"save_student_struct.txt","w");
	if(err==0)
	{
		printf("�򿪳ɹ���");
	}
	else
	{
		printf("�ļ���ʧ�ܣ�");
		return;
	}
	for(i=0;i<n;i++)
	{
		fprintf(fpin,"%s  %d\n",student[i].name,student[i].score);
	}
	fclose(fpin);
	return;
}

/*��fscanf_s���ļ��ж�ȡ�ṹ��,��ȡʱ������ַ�����
			�� _countof(student[i].name)ָ���ַ����Ĵ�С
			��Ȼ��sizeof()Ҳ�ǿ��Եģ����ѡ��
*/
void read_student_struct(stu student[],int n)				//���ļ��ж�ȡ�ṹ��
{
	int i;
	FILE *fpout;
	errno_t err;
	err=fopen_s(&fpout,"save_student_struct.txt","r");
	if(err==0)
	{
		printf("�򿪳ɹ���\n");
	}
	else
	{
		printf("�ļ���ʧ�ܣ�");
		return;
	}
	for(i=0;i<n;i++)
	{
		//fscanf_s(fpout,"%s",student[i].name,&student[i].score, _countof(student[i].name))��
		fscanf_s(fpout,"%s",student[i].name, sizeof(student[i].name));
		fscanf_s(fpout,"%d",&student[i].score);
		printf("%s%d\n",student[i].name,student[i].score);
	}
	fclose(fpout);
	return;
}
/*���԰�����ж�д��
	fwrite����������һ�����ݿ�д��fp�ļ�ָ����ָ����ļ��У����У�size������ÿ��д����ֽ���
*/
/*�����������򣬺�����+ҳ��*/
int fwrite_P268(stu student[],int n)
{
	int i;
	FILE *fpin;
	errno_t err;
	err=fopen_s(&fpin,"bina.txt","w");
	if(NULL==fpin)
	{
		printf("�ļ���ʧ�ܣ�");
		return 0;
	}

	for(i=0;i<n;i++)
	{
		fwrite(&student[i],sizeof(student[i]),1,fpin);
	}

	fclose(fpin);
	return 0;
}

int fread_P270(int n)
{
	int i;
	errno_t err;
	FILE *fpout;
	stu st[4];
	err=fopen_s(&fpout,"bina.txt","r");
	if(err==0)
	{
		printf("�ļ��򿪳ɹ���\n");
	}
	else
	{
		printf("�ļ���ʧ�ܣ�\n");
		return 0;
	}
	fread(st,sizeof(st[1]),n,fpout);
	for(i=0;i<n;i++)
	{
		printf("%s %d\n",st[i].name,st[i].score);
	}
	fclose(fpout);
	return 0;
}
/*
		fseek����������������Ҫ��ָ���ƶ�����Ӧλ��
		���һ������ֵ
		0��	�ļ���ͷ
		1��	λ��ָ�뵱ǰλ��
		2��	�ļ�ĩβ
*/
int fseek_P271(int n)
{
	int i;
	errno_t err;
	FILE *fpout;
	stu st[4];
	err=fopen_s(&fpout,"bina.txt","r");
	if(0==err)
	{
		printf("�ļ��򿪳ɹ���\n");
	}
	else
	{
		printf("�ļ���ʧ�ܣ�");
		return 0;
	}
	for(i=0;i<n;i++)
	{
		fseek(fpout,-(int)sizeof(st[i])*(i+1),2);
		fread(&st[i],sizeof(st[i]),1,fpout);						//��ȡָ�����ȵ�����
		printf("%s %d\n",st[i].name,st[i].score);
	}
	fclose(fpout);
	return 0;
}

void strerror_P277()
{
	FILE *fpout;
	errno_t err;
	err=fopen_s(&fpout,"bina.txt","r");
	perror("bina.txt");
	//error_ret(err);
	if(err!=0)
	{
		//printf("%s\n",strerror_s(errno),500);
		perror("test.txt");
		return ;
	}
	fclose(fpout);
	return ;
}
//����ֵ������Ҫ�÷ֺŽ���
enum Bool{
	True ,
	False
};

enum Bool is_number(char c)
{
	if(c>='0'&&c<='9')
		return True;
	else
		return False;
}

void enum_P173()
{
	enum Bool ret;
	char c;
	while(1)
	{
		printf("������:\n");
		c=getchar();
		putchar(c);
		putchar('\n');
		ret=is_number(c);
		if(!ret)
		{
			printf("����һ�����֣�\n");
			getchar();
		}
		else
		{
			printf("����һ���ַ�\n");
			getchar();
		}
	}
}


