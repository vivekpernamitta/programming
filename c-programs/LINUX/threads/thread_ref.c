/*
Set run_now to 1 when the main function is executing and to 2 when your new thread is executing.
If run_now is 1, print “1” and set it to 2. Otherwise, you sleep briefly and check the value again. You are
waiting for the value to change to 1 by checking over and over again. This is called a busy wait, although
here it is slowed down by sleeping for a second between checks. You’ll see a better way to do this later in
the chapter

gcc pthread_ref.c -lpthread
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_function(void *arg);
char message[] = "Hello World";
int run_now = 1;

int main() {
	int res;
	pthread_t a_thread;
	void *thread_result;
	int print_count1 = 0;

	res = pthread_create(&a_thread, NULL, thread_function, (void *)message);
	if (res != 0) {
		perror("Thread creation failed");
		exit(EXIT_FAILURE);
	}

	while(print_count1++ < 20) {
		if (run_now == 1) {
			printf("1");
			run_now = 2;
		}
		else {
			sleep(1);
		}
	}

	printf("\nWaiting for thread to finish...\n");
	res = pthread_join(a_thread, &thread_result);
	if (res != 0) {
		perror("Thread join failed");
		exit(EXIT_FAILURE);
	}
	printf("Thread joined\n");
	exit(EXIT_SUCCESS);
}

void *thread_function(void *arg) {
	int print_count2 = 0;

	while(print_count2++ < 20) {
		if (run_now == 2) {
			printf("2");
			run_now = 1;
		}
		else {
			sleep(1);
		}
	}

	sleep(3);
}
