#include<stdio.h>
#include<unistd.h>
void main(int argc,char *argv[])
{

extern char *optarg;
extern int optind;
int c, err = 0; 
char *fname, *sname;
int mflag=0, pflag=0, fflag=0;
while ((c = getopt(argc, argv, "df:mps:")) != -1)
{
	switch(c)
	{
		case 'd' :
			printf("you have d\n");
		break;
		case 'f' :
			printf("you gave enterd f");
			fname=optarg;
			break;
		case 's':
			sname = optarg;
			break;
		case '?':
			err = 1;
			break;
		}
}
}
