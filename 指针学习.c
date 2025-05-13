#include<stdio.h>
#include<stdlib.h>//malloc的头文件 
struct infor{
	int id;
	float score;
}student[3]={
   	{101,77},
   	{102,88},
   	{103,99}
};
typedef struct link{
	int id;//结点数据 
	struct link *next;//指向下一结点的指针 
}xuehao; 
void arrdemo()
{
	int a[]={33,22,11,66};
	int i,max,min;
	max=min=*a;//假定第一个元素是最大数也是最小数 
	printf("传统方法循环输出数组元素：\n");
	for(i=0;i<4;i=i+1)
	{
		printf("%-3d",a[i]);
	}
	printf("\n");
	printf("第一个元素的地址=%p\n",&a[0]);
	printf("第一个元素的地址=%p\n",&a[1]);
	printf("第一个元素的地址=%p\n",&a[2]);
	printf("第一个元素的地址=%p\n",&a[3]);
	printf("通过指针a输出第一个元素地址=%p\n",a);
	
	printf("通过指针a循环输出数组元素：\n");
	for(i=0;i<4;i=i+1)
	{
		printf("%-3d",*(a+i));
	 } 
	 printf("\n");
	 
	 printf("通过指针，输出数组最大数，最小数：\n");
	 for(i=0;i<4;i=i+1)
	 {
	 	if(*(a+i)>max)
	 	{
	 		max=*(a+i);
		 }
		else if((*a+i)<min)
		{
			min=*(a+i);
		}
	  } 
	  printf("max=%d,min%d",max,min);
 } 
//结构体指针
void structpdemo()
{
	struct infor *p=student;
	int i;
	printf("方法一，输出结构体中的每条记录：\n");
	for(i=0;i<3;i=i+1)
	{
		printf("%d %.1f\n",student[i].id,student[i].score);
	}
	printf("\n");
	printf("方法二，输出结构体中的每条记录：\n");
	for(i=0;i<3;i=i+1)
	{
		printf("%d %.1f\n",(*(p+i)).id,(*(p+i)).score);
	}
	printf("\n");
	printf("方法三，输出结构体中的每条记录：\n");
	for(i=0;i<3;i=i+1)
	{
		printf("%d %.1f\n",(p+i)->id,(p+i)->score);
	}
	printf("\n");
	printf("方法四，输出结构体中的每条记录：\n");
	for(;p<student+3;p++)
	{
		printf("%d %.1f\n",p->id,p->score);
	}
	printf("\n");
 } 
//动态内存分配
void mallocdemo()
{
	int *p,i;
	//动态内存分配后返回无数据类型的指针，强制转为int类型
	p=(int*)malloc(3*sizeof(int));
	printf("请输入三个数：\n");
	for(i=0;i<3;i=i+1)
	{
		scanf("%d",p+i);
	}
	printf("输出如下：\n");
	for(i=0;i<3;i=i+1)
	{
		printf("%-3d",*(p+i));
	}
	free(p);//释放内存空间 
 } 
//静态链表:指针移动时，通常不直接使用头指针，而使用第三方独立的指针 
void linkdemo()
{
	xuehao stu1={101},stu2={102},stu3={103};
	xuehao *head,*p;//头指针
	head=&stu1;//头指针指向第一个结点
	p=head; 
	stu1.next=&stu2;
	stu2.next=&stu3;
	stu3.next=NULL;
	printf("第一次head指向的地址：%p\n",head);
	printf("通过头指针head输出如下：\n");
	while(!head==NULL)
	{
		printf("当前head指向的地址：%p\n",head); 
		printf("%-4d",head->id);
		//head->next为下一个结点的地址，即将head指向下一个结点
		head=head->next; 
	 } 
	printf("\n");
	printf("最后head指向的地址：%p\n",head);
	printf("通过第三方指针p输出如下：\n");
	while(!p==NULL)
	{
		printf("%-4d",p->id);
		p=p->next;
	}
}
int main(){
	//int a=100;
	//int *p=&a;//把a的地址赋给p，则称呼p为指向a的指针 
	//printf("a=%d\n",a); 
	//printf("a的地址=%p\n",&a);
	//printf("通过指针p输出a的地址%p",p); 
    //arrdemo();
    //structpdemo();
    //mallocdemo();
    linkdemo();
}
