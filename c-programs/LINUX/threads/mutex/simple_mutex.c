/* the global variable i is locked
To lock particvulare variable both threads need to be locked in mutex
gcc simple_mutex.c -lpthread
*/

#include<pthread.h>
#include<unistd.h>
#include<error.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>

int count,i=2;

#define MAX 24
void * fun_thread(void*);
pthread_t tid;
pthread_mutex_t work_mutex;

void main()
{
	int res;
	res = pthread_mutex_init(&work_mutex, NULL);


	pthread_create(&tid,NULL,fun_thread,(void *) count);
	//lock
	pthread_mutex_lock(&work_mutex);

	if(i%2 == 0)
	{
		printf("Main thread\n");
	}
	else
		printf("NOUSE print main\n");
	sleep (10);
	pthread_mutex_unlock(&work_mutex);
	//unlocked
	pthread_join(tid,NULL);

}



void * fun_thread(void * s)
{
	pthread_mutex_lock(&work_mutex);
	i++;
	if(i%3==0)
	{
		printf("NEW thread");

	}
	//i++;
	pthread_mutex_unlock(&work_mutex);
	pthread_exit("tid");
}
