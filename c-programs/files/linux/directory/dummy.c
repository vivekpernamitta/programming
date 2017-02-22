#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
void printdir(char *dir, int depth)
{
DIR *dp;
struct dirent *entry;
struct stat statbuf;
dp = opendir(dir);// {
//fprintf(stderr,"cannot open directory: %s\n", dir);
//return;
//}

}

int main()
{
printf("Directory scan of /home:\n");
printdir("/home/vpernami/work",0);
printf("done.\n");
exit(0);
}
