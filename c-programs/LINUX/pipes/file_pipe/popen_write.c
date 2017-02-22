/*
The program uses popen with the parameter “w” to start the od -c command, so that it can send data to
that command. It then sends a string that the od -c command receives and processes; the od -c command
then prints the result of the processing on its standard output.

Ex: From the command line, you can get the same output with the command
$ echo “Once upon a time, there was...” | od -c

*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
	FILE *write_fp;
	char buffer[BUFSIZ + 1];

	sprintf(buffer, "Once upon a time, there was...\n");
	write_fp = popen("od -c", "w");
	if (write_fp != NULL) {
		fwrite(buffer, sizeof(char), strlen(buffer), write_fp);
		pclose(write_fp);
		exit(EXIT_SUCCESS);
	}
	exit(EXIT_FAILURE);
}
