/*Remember that once you’ve called free on a block of memory, it no longer belongs
to the process. It’s not being managed by the malloc library. Never try to read or
write memory after calling free on it.
*/

#include <stdlib.h>
#include <stdio.h>
#define ONE_K (1024)
int main()
{
	char *some_memory;
	int exit_code = EXIT_FAILURE;
	some_memory = (char *)malloc(ONE_K);
	if (some_memory != NULL) {
		free(some_memory);
		printf("Memory allocated and freed again\n");
		exit_code = EXIT_SUCCESS;
	}
	exit(exit_code);
}
