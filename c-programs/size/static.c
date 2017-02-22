#include<stdio.h>
int static a;
//int fun();
void main()
{
printf("main %d \n",a);
fun();
a++;
printf("main %d \n",a);
fun();
}


int fun()
{
int static b=2;
printf("func %d\n",b);
b++;
}

