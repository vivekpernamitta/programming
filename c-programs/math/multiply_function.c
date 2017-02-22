#include<stdio.h>
void main()
{

	int value1=0,value2=0,value3=0,i;
	printf("enter the value1 and value2\n");
	scanf("%d %d",&value1,&value2);
	for(i=0;i<value2;i++)
	{
		value3+=value1;
	}
printf("the output is =%d",value3);
}
