#include<stdio.h>
void fun(int array[])
{
printf("address of array%p\n",array);
}



void main()
{
int a[22];

printf("a=%16p\n",a);
printf("a=%16p\n",a);
fun(a);

}
