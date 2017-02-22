#include <stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
int a=12,i,count=0;
char name[25]="linux hbf drfe";
char *pname;
pname=calloc(25,sizeof(char));
printf("\n size of string name= %d\n",sizeof(name));
char* d;
d=pname;
for(i=0;name[i]!='\0';i++)
{
*pname=name[i];
pname++;
count++;


}
//*((--pname))=NULL;
printf("%.*s  number= %d\n and   size(count)=%d",21,name,a,count);

pname=d;
int pcount=strlen(pname);
printf("\ncount=%dpname=%s\n",pcount,pname);
//scanf("%d\n",&a);
}
