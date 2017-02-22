#include<stdio.h>
//int fun(int a);
typedef int (pgm)(int);         // alias function pointer alias is only used for function pointer

int fun(int a)
{
printf("/nthis is sample test /n");
}

struct node{
int a; char name[23]; int b;
};


struct node alpa={.b=23};


void main()

{
int a=12;
printf("\n%d",alpa.b);
//int (*funptr)(int);
//pgm *funptr;
//funptr=&fun;
//funptr(4);
lastfunction(&fun,5);
}
//int fun(int a)
//{
//printf("/nthis is sample test /n");
//}



lastfunction(pgm* funptr, int a)
{

(*funptr)(5);
}
