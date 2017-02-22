
/* This program reads from one file and writes to another files and checkes the status of \
by writing.txt file. For this program to run you should have reading.txt in current directory*/
#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>
#include<sys/stat.h>
void main()
{	
	struct stat data;
	int fd1,fd2;
	char i_buffer[512],o_buffer[BUFSIZ];

	fd1=open("reading.txt",O_RDWR,S_IRWXU|S_IRWXO);
	printf("file descripptor1=%d\n",fd1);


	int r_err,w_err;

	fd2=open("writing.txt",O_CREAT|O_RDWR|O_TRUNC,S_IRWXU|S_IRWXO);
	lseek(fd1,0,SEEK_SET);
	printf("file descripptor1=%d\n",fd1);
	while((r_err=read(fd1,o_buffer,1))>0)
	{
		w_err=write(fd2,o_buffer,1);
		if(w_err==-1)
			perror("write failed");
	}

	fstat(fd2 ,  &data);
	printf("data in structure: Inode no=%d\t protection=%d,\
			user ID=%d\n ",data.st_ino,data.st_mode,data.st_uid);
	printf("\n the o-buffer data is =%s\t%d\n",o_buffer,BUFSIZ);
	close(fd1);
}
