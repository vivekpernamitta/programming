#include<stdio.h>
void main()
{
char **dou;
char *sin;
sin=malloc(10);
sin="vivek";
dou=&sin;
printf("%s\n",sin);
//printf("%p\n",sin);
printf("%p\n",sin);
sin=(1+sin);
printf("%p\n",sin);
printf("%s\n",*dou);
printf("%p\n",dou);
dou++;
printf("%p\n",dou);
printf("%s\n",*dou);

}
