/*
   Typing Ctrl+C (shown as ^C in the following output) for the first time causes the program to react and
   then continue. When you type Ctrl+C again, the program ends because the behavior of SIGINT has
   returned to the default behavior of causing the program to exit.

 */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include<sys/types.h>
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
			while (1)
			{
				printf("child process is executing=%d\n",getpid());
				sleep (1);
			}
			break;


		default:

			while(1) 
			{
				printf("Hello World! this is parent process=%d\n",getpid());
				sleep(1);
			}
			break;
	}
}

