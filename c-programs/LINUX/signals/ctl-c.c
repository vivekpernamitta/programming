/*
Typing Ctrl+C (shown as ^C in the following output) for the first time causes the program to react and
then continue. When you type Ctrl+C again, the program ends because the behavior of SIGINT has
returned to the default behavior of causing the program to exit.

*/

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
void ouch(int sig)
{
printf("OUCH! - I got signal %d\n", sig);
(void) signal(SIGINT, SIG_DFL);   // restoring to default behavior of ctl-c . Default behavior is killing the process
}

int main()
{
(void) signal(SIGINT, ouch);
while(1) {
printf("Hello World!\n");
sleep(1);
}
}
