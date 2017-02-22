#include<stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#include<sys/types.h>
#include <stdlib.h>
int main()
{
char c,buffer[19];
int in, out;
in = open("file.in", O_RDONLY);

read(in,buffer,18); 
//buffer[18]='\0';	
printf("%s??\n",buffer);
int count=lseek(in,10,SEEK_CUR);

printf("\n the count value is ==%d\n",count);


if(read(in,buffer,18) != 18)  return 1;
        printf("%s\n",buffer);
//out = open("file.out", O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);
//while(read(in,&c,1) == 1)
//write(out,&c,1);
//exit(0);

printf("task done");
}
