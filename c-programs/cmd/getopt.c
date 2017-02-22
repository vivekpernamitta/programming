#include <stdio.h>
#include <unistd.h>
//#include <stdlib.h>
int main(int argc, char *argv[])
{
	int opt;
	while((opt=getopt(argc,argv,"f:ls:"))!=-1)			// char follwed by colon has option
	{
		switch (opt){
			case 'l':
				printf("this is only option=%c\n",opt);
				break;
			case 's':
				printf("this is  only  option=%c\t the value=%s\n",opt,optarg);
				break;
			case 'f':
				printf("this option contains =%c \t this value=%s\n",opt,optarg);
				break;
			case ':':					// the ":"  options the value fot that option not entered
				printf("options needs a value\n");
				break;

			case '?':					// "?" indicates options entered that si not present in getopt
				printf(" this option is not valid\n");
				break;
		}
	}
printf("the optin=%d\n",optind);					// this optin will print the number of args entered in cmd line NOTE "1" for program name
}
