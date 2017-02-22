#include<stdio.h>
int i,j,c[3][3];
int sub_fp(int (*p)[3],int col);



void main()
{
int i,j,one[3][3] = { {1,2,3}, {3,4,5}, {6,7,8} };
int  two[3][3] =  { {1,2,3}, {3,4,5}, {6,7,8} } ,output[3][3],value;

//enter_martix(&one);
int (*fp_sub)(int (*ptr)[],int);


printf("enter the numeber for operation");
scanf("%d",&value);

switch (value)
{
case 1:
	print(one,two);
	break;
case 2:
	add(one,two);
	break;
case 3:
	sub(one,two);
	break;
case 4:
//	sub_fp(one,two);
	fp_sub=sub_fp;
	int (*test)[3]= one;
	(*fp_sub)(test,3);
	break;
default: 
	printf("Invalid number");
	break;

}}




int add(int term_1[3][3],int term_2[3][3])
{
	for(i=0;i<3;i++)
        {       for(j=0;j<3;j++)
	c[i][j]=term_1[i][j]+term_2[i][j];
	}
	printf("Display addition of one and two matrix");
	for(i=0;i<3;i++)
        {       for(j=0;j<3;j++)
                   printf("%d",c[i][j]);
         printf("\n");
        }

}




int print(int term_1[3][3],int term_2[3][3]){

	for(i=0;i<3;i++)
        {       for(j=0;j<3;j++)
                   printf("%d",term_1[i][j]);
	 printf("\n");
	}
	for(i=0;i<3;i++)
 	{         for(j=0;j<3;j++)
		    printf("%d",term_2[i][j]);

	printf("\n");
	}
}
//int enter_matrix(int one[3][3],int two[3][3])
//{

//   

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
	for(i=0;i<col;i++)
        {       
		q= (int *)(p+i);
		for(j=0;j<col;j++)
        	{
         		 printf("%d",*(q+j));
        	}
		printf("\n");
	}
// for(i=0;i<3;i++)
  //      {       for(j=0;j<3;j++)
    //               printf("%d",c[i][j]);
      //   printf("\n");
        

}

