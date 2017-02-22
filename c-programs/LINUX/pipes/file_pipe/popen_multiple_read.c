#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
	FILE *read_fp;
	int chars_read;
//	char buffer[BUFSIZ + 1];
	char buffer[100 + 1];
int i=0;
	memset(buffer, '\0', sizeof(buffer));
	read_fp = popen("ps ax", "r");
	if (read_fp != NULL) {
		chars_read = fread(buffer, sizeof(char), 100, read_fp);
		printf("the read char=%d\n",chars_read);
i=strlen(buffer);
printf("%d\n",i);
		while (chars_read > 0) {
			buffer[chars_read - 1] = '\0';
			printf("Reading %d:-\n %s\n", BUFSIZ/10, buffer);
			chars_read = fread(buffer, sizeof(char), BUFSIZ/10, read_fp);
		}
*/		pclose(read_fp);
		exit(EXIT_SUCCESS);
	}
	exit(EXIT_FAILURE);
}
