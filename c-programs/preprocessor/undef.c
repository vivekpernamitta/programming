#define MAX (200 *300)
#define MAX (200+300)
#define MAX (200-300)
#include<stdio.h>
void main()
{
int i ;
char name[100],bame[20]="vivek";
//strcpy(name,"vivek") ;
for ( i=0;i<7;i++)
name[i]=bame[i];
int d=strlen(bame);
printf("%s\n%d",bame,d);
//printf("%d",MAX);
do

{
printf("name\t%d",d);
d--;
}while( d != 0 );
}


