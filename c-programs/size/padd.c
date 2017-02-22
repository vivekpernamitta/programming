#include<stdio.h>
struct size
{
char a:1;
int b:8;
short c;
char d;
}list;

void main()
{
printf("%d", sizeof(list));
struct size list={'a',12,4,'c'};
printf("%p\n",&(list.a));
printf("%p\n",&(list.b));
printf("%p\n",&(list.c));
printf("%p\n",&(list.d));
printf("%p\n",&(list.a));

}
