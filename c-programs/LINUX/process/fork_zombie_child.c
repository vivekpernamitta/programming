/* run ./a.out & in background and check status
child will be zomie state for last two cycles */

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

void main()
{
	pid_t pid;
	pid=fork();
	int n=0;
	char * message;
	switch(pid)
	{
		case -1:
			perror("fork failed");
			exit(1);
		case 0:
			message = "This is the child";
			n = 3;
			break;
		default:
			message = "This is the parent";
			n = 5;
			break;
	}
	for(; n > 0; n--) {
		puts(message);
		sleep(1);
	}
	exit (0);
}
