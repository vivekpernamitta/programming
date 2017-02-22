/*
when child processs is exited , thensignal is recieved. Then it  prints child process is exited
 */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include<sys/types.h>
void doom();
void ouch(int sig)
{
	printf("OUCH! - I got signal %d\t %d\n", sig,getpid());
	(void) signal(SIGINT, SIG_DFL);   // restoring to default behavior of ctl-c . Default behavior is killing the process
}

int main()
{
	(void) signal(SIGINT, ouch);

	int pid=fork();
	switch (pid) 
	{
		case 0:
			printf("child process is executing=%d\n",getpid());
			sleep (5);
			printf("child process is executing=%d\n",getpid());
			printf("child process is executing=%d\n",getpid());
			break;

		default:
			signal(SIGCHLD,doom);
			while(1) 
			{
				printf("Hello World! this is parent process=%d\n",getpid());
				sleep(1);
			}
			break;
	}
}


void doom()
{
printf("Child procvess has exited");
}

