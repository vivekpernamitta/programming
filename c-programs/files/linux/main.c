/* This program writes to one file "file.txt" form i_buffer 
and reads the data from "file1.txt" to o_buffer"
*/
#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>
//#include<unistd.h>
#include<string.h>
void main()
{
	int fd1,fd2;
	char i_buffer[512],o_buffer[312];

	fd1=open("file1.txt",O_RDWR|O_CREAT|O_TRUNC,S_IRWXU|S_IRWXO);
	printf("file descripptor1=%d\n",fd1);
	printf("enter the test you wnat to enter in to file=");
	//scanf("%s",buffer);

	gets(i_buffer);
	int length=strlen(i_buffer);
	printf("the length of string=%d\n",length);

	int w_err=write(fd1,i_buffer,length);
	if(w_err==-1)
		perror("write");


	lseek(fd1,0,SEEK_SET);
	//close(fd1);
	//fd1=open("file1.txt",O_RDONLY);
	printf("file descripptor1=%d\n",fd1);
	//	memset(o_buffer,0,5*sizeof(char));
	int r_err=read(fd1,o_buffer,length);
	if(r_err==-1)
		perror("read error");
	o_buffer[length+1]='\0';
	printf("hee cahractors read%d\n",r_err);
	printf("\n the o-buffer data is =%s\n",o_buffer);
	close(fd1);
}
