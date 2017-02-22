#include<stdio.h>
typedef int (* dble_ptr_array)[3][2];

void main()
{
//int (*pt)[3][2];
dble_ptr_array pt;

int array1[12];
pt=array1;
printf("%u",pt);
pt++;
printf("\n%u",pt);


}

