#include<stdio.h>
struct name {
int a;
int b;
char c;
} llop,toop;


void main()
{
	char *array[12];	//char *array[12]={"sumewfre","trandf"};
//char *naam="vivek";
//char *baam="sum";
//array[0]=naam;

//array[1]=baam;


struct name llop={.a=5, \
.b=6,.c='s'};


printf("%d\t%d\t%c\t",llop.a,llop.b,llop.c);
printf("%p\n%p\n%d",array[0],array[1],sizeof(array));


}

