#include<stdio.h>
void main(int argc, char* argv[])
{
int i;
printf("enter the works while executing");
printf("\nthese many number you have enetred = %d",argc);
for(i=0;i<argc;i++)
	{
	printf("\n%s",argv[i]);
	printf("\n%p",argv[i]);
	}
}
