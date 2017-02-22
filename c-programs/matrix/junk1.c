#include<stdio.h>
int i,j,c[3][3];
int sub_fp(int (*p)[3],int col);


enum harm{har,man,cisco};
void main()
{
int i,j,one[3][3] = { {1,2,3}, {3,4,5}, {6,7,8} };
int  two[3][3] =  { {1,2,3}, {3,4,5}, {6,7,8} } ,output[3][3],value;
enum harm symp;
printf("harm%d",cisco);
//enter_martix(&one);
int (*fp_sub)(int (*p)[3],int);

//char *ap[21];
//printf("size of ap=%d",sizeof(ap));
printf("enter the numeber for operation");
scanf("%d",&value);

switch (value)
{
case 1:
	break;
case 2:
	break;
case 3:
	sub(one,two);
	break;
case 4:
//	sub_fp(one,two);
	fp_sub=sub_fp;
	printf("one -> %p \n", one);
char qonk;
int *donk=&qonk;
	printf("ddonk and qonk -> %p\t%p \n",donk,++donk);
	printf("ddonk and qonk -> %p\t%p \n",++donk,(donk));
	printf("one size-> %d \n",sizeof( one));
	int (*test)[3]=one;
	printf("test -> %p \n", test);
	printf("test size-> %d \n", sizeof(test));
	fp_sub(test,3);
	break;
default: 
	printf("Invalid number");
	break;

}}

int sub(int *p,int *q)
{
	for(i=0;i<3;i++)
        {       for(j=0;j<3;j++)
        {
	c[i][j]=(*p)-(*q);
	printf("address of p[%d][%d]==%d\n",i,j,p);
	printf("address of p[%d][%d]==%d\n",i,j,c[i][j]);
	q++;
	p++;
        }}
 for(i=0;i<3;i++)
        {       for(j=0;j<3;j++)
                   printf("%d",c[i][j]);
         printf("\n");
        }

}

int sub_fp(int (*p)[3],int col)
{
	int *q;
	printf("p -> %p \n", p);
	for(i=0;i<3;i++)
        {       
		q=(int *)(p+i);
		for(j=0;j<3;j++)
        	{
         		 printf("%d",*(q+j));
        	}
	}
// for(i=0;i<3;i++)
  //      {       for(j=0;j<3;j++)
    //               printf("%d",c[i][j]);
      //   printf("\n");
        

}

