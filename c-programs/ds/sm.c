#include<stdio.h>
void main()
{
int a[3]={1,2,3};
char b[3]={'1','2','3'};
/*printf("%d\n",sizeof(a));
printf("%p int\n",&a[0]);
printf("%pint 2 \n",&a[1]);
printf("%pint 3\n",&a[2]);

printf("%p cahr 1\n",&b[0]);

printf("%p char 2\n",&b[1]);
printf("%p\ char 3 \n",&b[2]);
*/char *p="string";
char **q=p;
printf("%s",q);

//char a=q+1;

printf("%p a\n",a);
printf("%p q\n",a);
printf("%p *p\n",p);

printf("%p a++",(q+1));


}
