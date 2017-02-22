#include<stdio.h>

int nuc;
int alpha=12;
char beta=13;
 main ()
{

printf(" YOCTO !!!");

int a,b;
a=45;
b=35;

char *name;
fun(&a,&b);

//printf("%s oops!!",*name);
}

int fun(int* c, int* d)
{
char *name;
printf("hi i am function");
printf("a=%d\nb=%d",*c,*d);
printf("enter and b values");

scanf("%d%d",&c,&d);
scanf(" %s", &name);
printf("%s", name);
//return name;
}


