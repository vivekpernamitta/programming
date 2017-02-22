#include<stdio.h>
#include<stdlib.h>
void main()
{

char array[12]="vivek";
char *ptr=NULL;
ptr=calloc(12,sizeof(char));
int i=0;
while(array[i]!='\0')
{
printf("loop\n");
i++;
}
printf("loop terminated=%d\n",i);
strcpy(ptr,array);

printf("loop terminated=%d\t  %s\n",i,ptr);
i=0;
while(*ptr != '\0')
{
printf("loop\n");
ptr++;i++;
}
printf("loop terminated=%d\t\n  %s \n",i,ptr);


}
