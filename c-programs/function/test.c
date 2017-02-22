#include<stdio.h>
//#include"sometest.h"
inline int max(int a, int b);

// a definition mentioning inline
inline int max(int a, int b) {
printf("this is inline function");
  return a > b ? a : b;
}

//extern int alpa;


void main()

{
int i;
i=(1,2,3);
printf("%d",i);
int a=max(1,2);
printf("\n%d",a);
//alpa=10;
//printf("\n%d",alpa);

}

