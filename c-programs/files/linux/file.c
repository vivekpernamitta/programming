#include<stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
void main()
{

int fd;
fd= open("/home/vpernami/work/experiment/exp1/c_files/files/linux/vivek.txt",O_CREAT|O_EXCL,S_IRUSR);
printf("The fd =%d",fd);
//fclose(fd);
}
