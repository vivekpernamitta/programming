#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
static int alarm_fired = 0;
void ding(int sig)
{
	alarm_fired = 1;
}
// In main, you tell the child process to wait for five seconds before sending a SIGALRM signal to its parent.
int main()
{
	pid_t pid;
	printf("alarm application starting\n0");
	pid = fork();
	switch(pid) {
		case -1:
			/* Failure */
			perror("fork failed");
			exit(1);
		case 0:
			/* child */
			sleep(15);
			kill(getppid(), SIGALRM);
			exit(0);
	}
	//the parent process arranges to catch SIGALRM with a call to signal and then waits for the inevitable.
	/* if we get here we are the parent process */
	printf("waiting for alarm to go off\n");
	(void) signal(SIGALRM, ding);
 	pause();
	if (alarm_fired)
		printf("Ding!\n");
	printf("done\n");
	exit(0);
}
