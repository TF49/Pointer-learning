#include<stdio.h>
#include<stdlib.h>//malloc��ͷ�ļ� 
struct infor{
	int id;
	float score;
}student[3]={
   	{101,77},
   	{102,88},
   	{103,99}
};
typedef struct link{
	int id;//������� 
	struct link *next;//ָ����һ����ָ�� 
}xuehao; 
void arrdemo()
{
	int a[]={33,22,11,66};
	int i,max,min;
	max=min=*a;//�ٶ���һ��Ԫ���������Ҳ����С�� 
	printf("��ͳ����ѭ���������Ԫ�أ�\n");
	for(i=0;i<4;i=i+1)
	{
		printf("%-3d",a[i]);
	}
	printf("\n");
	printf("��һ��Ԫ�صĵ�ַ=%p\n",&a[0]);
	printf("��һ��Ԫ�صĵ�ַ=%p\n",&a[1]);
	printf("��һ��Ԫ�صĵ�ַ=%p\n",&a[2]);
	printf("��һ��Ԫ�صĵ�ַ=%p\n",&a[3]);
	printf("ͨ��ָ��a�����һ��Ԫ�ص�ַ=%p\n",a);
	
	printf("ͨ��ָ��aѭ���������Ԫ�أ�\n");
	for(i=0;i<4;i=i+1)
	{
		printf("%-3d",*(a+i));
	 } 
	 printf("\n");
	 
	 printf("ͨ��ָ�룬����������������С����\n");
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
//�ṹ��ָ��
void structpdemo()
{
	struct infor *p=student;
	int i;
	printf("����һ������ṹ���е�ÿ����¼��\n");
	for(i=0;i<3;i=i+1)
	{
		printf("%d %.1f\n",student[i].id,student[i].score);
	}
	printf("\n");
	printf("������������ṹ���е�ÿ����¼��\n");
	for(i=0;i<3;i=i+1)
	{
		printf("%d %.1f\n",(*(p+i)).id,(*(p+i)).score);
	}
	printf("\n");
	printf("������������ṹ���е�ÿ����¼��\n");
	for(i=0;i<3;i=i+1)
	{
		printf("%d %.1f\n",(p+i)->id,(p+i)->score);
	}
	printf("\n");
	printf("�����ģ�����ṹ���е�ÿ����¼��\n");
	for(;p<student+3;p++)
	{
		printf("%d %.1f\n",p->id,p->score);
	}
	printf("\n");
 } 
//��̬�ڴ����
void mallocdemo()
{
	int *p,i;
	//��̬�ڴ����󷵻����������͵�ָ�룬ǿ��תΪint����
	p=(int*)malloc(3*sizeof(int));
	printf("��������������\n");
	for(i=0;i<3;i=i+1)
	{
		scanf("%d",p+i);
	}
	printf("������£�\n");
	for(i=0;i<3;i=i+1)
	{
		printf("%-3d",*(p+i));
	}
	free(p);//�ͷ��ڴ�ռ� 
 } 
//��̬����:ָ���ƶ�ʱ��ͨ����ֱ��ʹ��ͷָ�룬��ʹ�õ�����������ָ�� 
void linkdemo()
{
	xuehao stu1={101},stu2={102},stu3={103};
	xuehao *head,*p;//ͷָ��
	head=&stu1;//ͷָ��ָ���һ�����
	p=head; 
	stu1.next=&stu2;
	stu2.next=&stu3;
	stu3.next=NULL;
	printf("��һ��headָ��ĵ�ַ��%p\n",head);
	printf("ͨ��ͷָ��head������£�\n");
	while(!head==NULL)
	{
		printf("��ǰheadָ��ĵ�ַ��%p\n",head); 
		printf("%-4d",head->id);
		//head->nextΪ��һ�����ĵ�ַ������headָ����һ�����
		head=head->next; 
	 } 
	printf("\n");
	printf("���headָ��ĵ�ַ��%p\n",head);
	printf("ͨ��������ָ��p������£�\n");
	while(!p==NULL)
	{
		printf("%-4d",p->id);
		p=p->next;
	}
}
int main(){
	//int a=100;
	//int *p=&a;//��a�ĵ�ַ����p����ƺ�pΪָ��a��ָ�� 
	//printf("a=%d\n",a); 
	//printf("a�ĵ�ַ=%p\n",&a);
	//printf("ͨ��ָ��p���a�ĵ�ַ%p",p); 
    //arrdemo();
    //structpdemo();
    //mallocdemo();
    linkdemo();
}
