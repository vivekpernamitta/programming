/*
Alarm afetr certain time 
 */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include<sys/types.h>
void doom();

int alpa=1;

void ouch(int sig)
{
	printf("OUCH! - I got signal %d\t %d\n", sig,getpid());
	(void) signal(SIGINT, SIG_DFL);   // restoring to default behavior of ctl-c . Default behavior is killing the process
}

int main()
{
int beta=2;
	signal(SIGALRM,doom); 		//  signal handler for ALARM
	alarm(12);			//  alarm after 12 seconds
	
	int pid=fork();
	switch (pid) 
	{
		case 0:
			alpa=5,beta=6;
			printf("child process is executing\talpa=%d\tbeta=%d\t%d\n",alpa,beta,getpid());
			sleep (5);
			printf("child process is executing=%d\n",getpid());
			printf("child process is executing=%d\n",getpid());
			break;

		default:
			alpa=10,beta=11;
			while(1) 
			
			{
				printf("Hello World! this is parent process\talpa=%d\tbeta=%d\t%d\n",alpa,beta,getpid());
				sleep(1);
			}
			break;
	}
}


void doom()
{
printf("!!!!!!ALARM!!!!!!!!!\n");
}

