#include<stdio.h>
void main()
{
int data[12],i,j,a,b,n;
printf("enter the list to sort");
scanf("%d",&n);
printf("enter the elements in list");
//printf("enter the elements");
for(i=0;i<n;i++)
{ 
scanf("%d",&data[i]); 
}
a=n;
for(i=0;i<n-1;i++)
{
for(j=0;j<n-i-1;j++)
{
//n=n-1;
if(data[j]>data[j+1])
{
b=data[j];
data[j]=data[j+1];
data[j+1]=b;
}
//n=n-1;
}

}
printf("displaying sorted numbers");
for(i=0;i<n;i++)
{printf("%d",data[i]);}
}

