#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <conio.h>
typedef struct _stu
{
	char name[10];
	int   score;
}stu;

int first();
int second(void);
int third();
int judgebig_store();
int error();
int free_point();
int free_point2();
int advantage_option();
int move_point();
int array_point();
int dynamic_array();
int dynamic_array_point_array();
extern void read_student_struct(stu student[],int n);
extern void save_student_struct(stu student[],int n);
extern void sort(stu student[],int n);
extern void bubble_sort(stu student[],int n);
extern void print(stu student[],int n);
int fwrite_P268(stu student[],int n);
int fread_P270(int n);
int fseek_P271(int n);
void strerror_P277();
void enum_P173();