#include<stdio.h>
void main()

{


char p[12]="vivek",*q;

q=p;
printf("%p\n%p",q,p);
*q++ = (p[2]);

printf("\nq=%p\n*q=%c",q,*q);
//*p++;
}


