/* Remove any file LCK.test2 in the current folder before  running.
   This program will create file using fcntl file in current directory 
   and sleeps for 1 sec ifor ten times and closed the file  and removes it
  Run this program parallel two time 
EX:/ ./a.out & ./a.out
 */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
const char *lock_file = "LCK.test2";
int main()
{
	int file_desc;
	int tries = 10;
	while (tries--) {
		file_desc = open(lock_file, O_RDWR | O_CREAT | O_EXCL, 0444);
		if (file_desc == -1) {
			printf("%d - Lock already present\n", getpid());
			sleep(3);
		}
		else {
			//The critical section starts here:
			printf("%d - I have exclusive access\n", getpid());
			sleep(1);
			(void)close(file_desc);
			(void)unlink(lock_file);

			//It ends here
			sleep(2);
		}
	}
	exit(EXIT_SUCCESS);
}
