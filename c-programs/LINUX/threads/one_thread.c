/*
How to compile
cc -D_REENTRANT one_thread.c -I/usr/include/nptl -o thread1 -lpthread
(or)
gcc one_thread.c -lpthread
-I // path is pational // that i slibrary path

*/


#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>

void * thread_function(void* arg);

void main()
{

	pthread_t thd;
//	char * name=(char *)malloc(24);
	char name[32]="thisislinux";
// Thread Created
	int res= pthread_create(&thd,NULL,thread_function,(void *)name);
	if( res!=0)
	{
		perror("Thread craton fialed");
		exit(EXIT_FAILURE);
	}
	printf(" waiting for thred to function curreenlty in main\n");
	void * thread_result;

// Thread joined
	res= pthread_join(thd,NULL);
	if(res!=0)
	{
		perror("thread joined fail");
		exit(EXIT_FAILURE);
	}
	printf("Thread joined, it returned %s\n", (char *)thread_result);
	printf("Message is now %s\n", name);
	exit(EXIT_SUCCESS);


}
void * thread_function(void *arg)
{
	printf("thread_function is running. Argument was %s\n", (char *)arg);
	sleep(3);
	strcpy(arg, "Bye!");
// Thread exit for closing the thread and  now it will return for  thread join
	pthread_exit("Thank you for the CPU time\n");
}
