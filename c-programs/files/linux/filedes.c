#include<sys/types.h>
#include<stdlib.h>
#include<fcntl.h>
#include<stdio.h>
void main()
{
int a,b,c;
a=open("a.txt",O_RDONLY);
b=open("b.txt",O_RDONLY);
c=open("b.txt",O_RDONLY);
printf("a=%d\t b=%d\t c=%d",a,b,c);
}
