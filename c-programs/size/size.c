#include<stdio.h>
#include<memory.h>
enum day {mon,tue,wed};
void main()
{

int a=10;
int *p;
char *r;
int **q;
p=&a;
q=&p;
long unsigned int ohh=9999999999;
long unsigned int l=2444443345667;
printf("p= %p\t r= %p\t q=%p\n",p,r,q);
printf("p(increment)=  %p\t r (increment)= %p\tq (increment)= %p i\n",++p,++r,++q);
printf("%lu\n%lu",ohh,mon);
char *name1="viva";
char *name2;
name2=malloc(12);
int ret=memset(name2,name1,3);
printf("/n return=%s/n",name2 );


}
