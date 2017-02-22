#include<stdio.h>
int main()
{
   int p,*q,**r; //assume the address of p to be 400
                 //assume the address of q to be 500
   p=50;
   q=p;
   r=q;

printf("Value of p-->%d",p);
printf("\nValue of q-->%d",q);
//printf("\nValue at address of q \"in the address displayed above\"-->%d",*p);
printf("\nValue of r \"which will be the address of q\"-->%d",r);
printf("\nValue of r \"which will be the adddress of p-->%d",*r);
printf("\nValue of r \"which will be the value of p\"-->%d",**r);
/*
Please change the format specifiers and replace the specifier from %d to %u in case the address value is not being displayed
*/
return 0;
}
