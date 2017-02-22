/* New cheared wiil be created and will be destroyed and main thread does'nt expect return"
There are many attributed one among it

The two possible flag values for pthread_attr_setdetachstate are
PTHREAD_CREATE_JOINABLE and PTHREAD_CREATE_DETACHED.
*/


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_function(void *arg);

char message[] = "Hello World";
int thread_finished = 0;

int main() {
	int res;
	pthread_t a_thread;
	void *thread_result;

// thread attribute created . This is only attribute not the actual thread
	pthread_attr_t thread_attr;

	res = pthread_attr_init(&thread_attr);
	if (res != 0) {
		perror("Attribute creation failed");
		exit(EXIT_FAILURE);
	}
// thread attribute set for detach new thread from parent
	res = pthread_attr_setdetachstate(&thread_attr, PTHREAD_CREATE_DETACHED);
	if (res != 0) {
		perror("Setting detached attribute failed");
		exit(EXIT_FAILURE);
	}
// Create a new thread and passing thread attributes
	res = pthread_create(&a_thread, &thread_attr, thread_function, (void *)message);
	if (res != 0) {
		perror("Thread creation failed");
		exit(EXIT_FAILURE);
	}

// destroying thread attributes
	(void)pthread_attr_destroy(&thread_attr);
	while(!thread_finished) {
		printf("Waiting for thread to say it's finished...\n");
		sleep(1);
	}
	printf("Other thread finished, bye!\n");
	exit(EXIT_SUCCESS);
}

void *thread_function(void *arg) {
	printf("thread_function is running. Argument was %s\n", (char *)arg);
	sleep(4);
	printf("Second thread setting finished flag, and exiting now\n");
	thread_finished = 1;
	pthread_exit(NULL);
}

