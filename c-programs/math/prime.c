#include<stdio.h>
void main()
{
int i,j,a;
//a=2;
//i=1;
//printf("%d",a%i);

for(a=0;a<20;a++)
{	for(j=1;j<a;j++)
	{
	if((a%j)==0)
	 {printf("%d\n is prime",a);	
	}
	}

}
}
