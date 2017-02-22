
/*

#include <pthread.h>

int pthread_cancel(pthread_t thread);

This is pretty straightforward: Given a thread identifier, you can request that it be canceled. On the receiving
end of the cancel request, things are slightly more complicated, but not much. A thread can set its cancel
state using pthread_setcancelstate.

#include <pthread.h>

int pthread_setcancelstate(int state, int *oldstate);

The first parameter is either PTHREAD_CANCEL_ENABLE, which allows it to receive cancel requests,
or PTHREAD_CANCEL_DISABLE, which causes them to be ignored. The oldstate pointer allows the
previous state to be retrieved. If you are not interested, you can simply pass NULL. If cancel requests
are accepted, there is a second level of control the thread can take, the cancel type, which is set with
pthread_setcanceltype.

#include <pthread.h>

int pthread_setcanceltype(int type, int *oldtype);

The type can take one of two values, PTHREAD_CANCEL_ASYNCHRONOUS, which causes cancellation requests
to be acted upon immediately, and PTHREAD_CANCEL_DEFERRED, which makes cancellation requests wait
until the thread executes one of these functions: pthread_join, pthread_cond_wait,
pthread_cond_timedwait, pthread_testcancel, sem_wait, or sigwait.
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_function(void *arg);

int main() {
	int res;
	pthread_t a_thread;
	void *thread_result;

	res = pthread_create(&a_thread, NULL, thread_function, NULL);
	if (res != 0) {
		perror("Thread creation failed");
		exit(EXIT_FAILURE);
	}
	sleep(3);
	printf("Canceling thread...\n");
	res = pthread_cancel(a_thread);
	if (res != 0) {
		perror("Thread cancelation failed");
		exit(EXIT_FAILURE);
	}
	printf("Waiting for thread to finish...\n");
	res = pthread_join(a_thread, &thread_result);
	if (res != 0) {
		perror("Thread join failed");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}

void *thread_function(void *arg) {
	int i, res, j;
	res = pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
	if (res != 0) {
		perror("Thread pthread_setcancelstate failed");
		exit(EXIT_FAILURE);
	}
	res = pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, NULL);
	if (res != 0) {
		perror("Thread pthread_setcanceltype failed");
		exit(EXIT_FAILURE);
	}
	printf("thread_function is running\n");
	for(i = 0; i < 10; i++) {
		printf("Thread is still running (%d)...\n", i);
		sleep(1);
	}
	pthread_exit(0);
}

