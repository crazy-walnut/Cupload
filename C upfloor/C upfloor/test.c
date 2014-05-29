#include "test.h"
/*函数命名规则，函数名+类型+页号*/
int first()
{
	char *pa,a = 1 ;
	int		b= 2, *pb;
	double c =3,*pc;
	pa=&a;
	pb=&b;
	pc=&c;

	printf("char 型指针pa占用内存大小为：%d字节\n",sizeof pa);
	printf("int 型指针pb占用内存大小为：%d字节\n",sizeof pb);
	printf("double 型指针pc占用内存大小为：%d字节\n\n",sizeof pc);

	printf("char 型指针pa所指向内存区域的大小为：%d字节\n",sizeof(*pa));
	printf("int 型指针pb所指向的内存区域的大小为：%d字节\n",sizeof(*pb));
	printf("double 型指针pc所指向的内存区域的大小为：%d字节\n\n",sizeof(*pc));

	printf("char型变量a的地址为：%d\n",pa);
	printf("int 型变量b的地址为：%d\n",pb);
	printf("double 型变量c的地址为：%d\n",pc);

	getchar();

	return 0;
}

int second(void)
{
	char a[4];
	char (*pa)[4],*pb;

	pa = &a;			//pa，指向数组的指针
	pb = &a[0];

	printf("char 型数组指针pa所占用的内存为:%d\n",sizeof(*pa));
	printf("char 型指针pb所占用的内存大小为：%d\n\n",sizeof(*pb));

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
	printf("int 型指针pa的值为：%x\n",pa);
	printf("char 型指针pa的值为：%x\n",(char*)pa);

	printf("int 型指针pa所指内存单元的值为：%x\n",*pa);
	printf("char 型指针pa所指内存单元的值为：%x\n",*(char*)pa);

	getchar();


	return 0;
}

int judgebig_store()		//判断计算机采用大端存储还是小端存储
{
	int a;
	int *pa;
	pa=&a;
	a=0x12345678;
	if(0x78==*(char*)pa)		//(char*)pa指向低位的地址
		printf("小端模式!\n");
	else
	{
		printf("大端模式!\n");
	}
	getchar();

	return 0;
}

int error()					//测试指针初始化为NULL是否能被赋值
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

	printf("使用free()函数之前pa = %d\n",pa);

	free(pa);
	printf("使用free()函数之后pa = %d\n",pa);

	pa=NULL;				//如果不使用NULL，free（pa）会报错
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
	printf("\n通过数组a来直接打印其中的元素值\n");
	for(i=0;i<4;i++)
	{
		a[i]=rand()%100;
		printf("a[%d] = %d\t",i,a[i]);
	}

	pa=a;
	printf("\n通过int型指针pa来间接打印数组a中的元素\n");
	for(i=0;i<4;i++)
	{
		printf("a[%d] = %d\t",i,*pa++);
	}

	pb =a;
	printf("\n通过int型指针pa来间接打印数组a中的元素\n");
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
	printf("\n通过数组a来直接打印其中的元素值\n");
	for(i=0;i<4;i++)
	{
		a[i]=i*2;
		printf("a[%d] = %d\t",i,a[i]);
	}
	printf("\n数组a的首地址为%d\n",a);
	pa=a;
	
	for(i=0;i<4;i++)
	{
		printf("a[%d] = %d\t",i,*(pa++));
	}
	printf("\n通过*(pa+i)间接引用数组a中元素之后pa的值为：%d\n",pa);


	pb =a;
	for(i=0;i<4;i++)
	{
		printf("a[%d] = %d\t",i,*pb++);
	}
	printf("\n通过*pa+i间接引用数组a中元素之后pa的值为：%d\n",pb);
	getchar();
	return 0;
}

int array_point()
{
	int a[3][3];
	int i,j;
	int *pa;
	printf("直接引用二维数组a中的元素\n");
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
	printf("通过指针引用二维数组a中的元素\n");
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
	
	const int N=3;			//const确定的值不能用在数组之中
	const int M=4;
	int *a[3];
	int i,j;

	for(i=0;i<N;i++)
	{
		if((a[i] = (int *)malloc(M*sizeof(int)))==NULL)
		{
			printf("分配失败！");
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
	for(i=0;i<N;i++)			//这一步很关键
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
	if((a=(int(*)[3])malloc(N*M*sizeof(int)))==NULL)		//const确定的值不能用在数组之中
	{
		printf("分配失败！");
		exit(0);
	}
	printf("当以4X3二维数组方式引用创建的动态数组时\n");
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
//判断文件是否正确打开
int error_ret(errno_t err)
{
	if(0==err)
	{
		printf("文件打开成功！\n");
		return 0;
	}
	else
	{
		printf("文件打开失败！");
		return 0;
	}
}


void input(stu student [],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("请输入学生姓名：\n");
		scanf_s("%s",&student[i].name);
		printf("请输入学生总成绩：\n");
		scanf_s("%d",&student[i].score);
	}
	return ;
}

/*********如果static void 那么这个函数只能在所属文件内被调用***********/
/***********************这个函数与上面的函数相比较*********************/
static void input_1(stu student [],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("\n请输入学生姓名：");
		scanf_s("%s",&student[i].name, 10);
		printf("\n请输入学生总成绩：");
		scanf_s("%d",&student[i].score);
	}
	return ;
}

void bubble_sort(stu student[],int n)		//冒泡排序
{
	int i,j,flag;
	stu temp;
	
	for(i=0;i<n-1;i++)
	{
		flag=0;											//如果后面不再变化flag=0
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
void save_student_struct(stu student[],int n)		//保存结构体到文件中
{
	int i;
	errno_t err;
	FILE *fpin;
	err=fopen_s(&fpin,"save_student_struct.txt","w");
	if(err==0)
	{
		printf("打开成功！");
	}
	else
	{
		printf("文件打开失败！");
		return;
	}
	for(i=0;i<n;i++)
	{
		fprintf(fpin,"%s  %d\n",student[i].name,student[i].score);
	}
	fclose(fpin);
	return;
}

/*用fscanf_s从文件中读取结构体,读取时如果是字符串，
			用 _countof(student[i].name)指定字符串的大小
			当然用sizeof()也是可以的，灵活选择
*/
void read_student_struct(stu student[],int n)				//从文件中读取结构体
{
	int i;
	FILE *fpout;
	errno_t err;
	err=fopen_s(&fpout,"save_student_struct.txt","r");
	if(err==0)
	{
		printf("打开成功！\n");
	}
	else
	{
		printf("文件打开失败！");
		return;
	}
	for(i=0;i<n;i++)
	{
		//fscanf_s(fpout,"%s",student[i].name,&student[i].score, _countof(student[i].name))；
		fscanf_s(fpout,"%s",student[i].name, sizeof(student[i].name));
		fscanf_s(fpout,"%d",&student[i].score);
		printf("%s%d\n",student[i].name,student[i].score);
	}
	fclose(fpout);
	return;
}
/*测试按组进行读写，
	fwrite（）函数将一个数据块写入fp文件指针所指向的文件中，其中，size参数是每次写入的字节数
*/
/*函数命名规则，函数名+页号*/
int fwrite_P268(stu student[],int n)
{
	int i;
	FILE *fpin;
	errno_t err;
	err=fopen_s(&fpin,"bina.txt","w");
	if(NULL==fpin)
	{
		printf("文件打开失败！");
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
		printf("文件打开成功！\n");
	}
	else
	{
		printf("文件打开失败！\n");
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
		fseek函数，按照任意需要将指针移动到相应位置
		最后一个参数值
		0：	文件开头
		1：	位置指针当前位置
		2：	文件末尾
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
		printf("文件打开成功！\n");
	}
	else
	{
		printf("文件打开失败！");
		return 0;
	}
	for(i=0;i<n;i++)
	{
		fseek(fpout,-(int)sizeof(st[i])*(i+1),2);
		fread(&st[i],sizeof(st[i]),1,fpout);						//读取指定长度的数据
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
//布尔值定义完要用分号结束
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
		printf("请输入:\n");
		c=getchar();
		putchar(c);
		putchar('\n');
		ret=is_number(c);
		if(!ret)
		{
			printf("这是一个数字！\n");
			getchar();
		}
		else
		{
			printf("这是一个字符\n");
			getchar();
		}
	}
}


