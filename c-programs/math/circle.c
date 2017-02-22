#include<stdio.h>
void circle(char c, int x);
void main()
{
circle('A',12);
}

void circle(char c,int x)
{
     int i,j;
    for(i=-x;i<x;i++)
    {
        for(j=-x;j<x;j++)
        {
            if(i*i+j*j<x*x)
                printf("%c",c);
            else
                printf(" ");
                 
        }
        printf("\n");
    }
}
