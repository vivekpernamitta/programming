/*
When ps finishes, you get a new shell prompt. You don’t return to pexec, so the second message doesn’t
get printed. The PID of the new process is the same as the original, as are the parent PID and nice value.
In effect, all that has happened is that the running program has started to execute new code from a new
executable file specified in the call to exec.
There is a limit on the combined size of the argument list and environment for a process started by exec
functions. This is given by ARG_MAX and on Linux systems is 128K bytes. Other systems may set a more
reduced limit that can lead to problems. The POSIX specification indicates that ARG_MAX should be at
least 4,096 bytes.
The exec functions generally don’t return unless an error occurs, in which case the error variable errno
is set and the exec function returns -1.
The new process started by exec inherits many features from the original. In particular, open file descriptors
remain open in the new process unless their “close on exec flag” has been set (refer to the fcntl system call
in Chapter 3 for more details). Any open directory streams in the original process are closed.

*/

#include <unistd.h>
#include<stdio.h>
/* Example of an argument list */


/* Note that we need a program name for argv[0] */
char *const ps_argv[] =
{"ps", "ax", 0};
/* Example environment, not terribly useful */
char *const ps_envp[] =
{"PATH=$PATH:/bin:/usr/bin", "TERM=console", 0};


void main(){


/* Possible calls to exec functions */
execl("/bin/ps","ps","ax", NULL); /* assumes ps is in /bin */
execlp("ps","ps","ax", NULL); /* assumes /bin is in PATH */
execle("/bin/ps","ps","ax", NULL,ps_envp); /* passes own environment */
execv("/bin/ps",ps_argv);
execvp("ps",ps_argv);
execve("/bin/ps",ps_argv,ps_envp);
}
