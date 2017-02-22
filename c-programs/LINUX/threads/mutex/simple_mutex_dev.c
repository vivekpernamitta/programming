#include<pthread.h>
#include<unistd.h>
#include<error.h>
#include<stdlib.h>
#include<stdio.h>

int count,i;

#define MAX 12
void * fun_thread(void*);
pthread_t tid;
pthread_mutex_t work_mutex;

void main()
{
int res;
res = pthread_mutex_init(&work_mutex, NULL);

	pthread_create(&tid,NULL,fun_thread,(void *) count);
//sleep(1);
pthread_mutex_lock(&work_mutex);
	while (i < 12)
	{
		i++;
		count++;
		printf(" main thread=%d\n",count);
	}
pthread_mutex_unlock(&work_mutex);
	pthread_join(tid,NULL);
pthread_mutex_destroy(&work_mutex);

}



void * fun_thread(void * s)
{
//pthread_mutex_lock(&work_mutex);
	while(i<24)
	{
		i++;count++;
		printf(" child thread=%d\n",count);
	}
//pthread_mutex_unlock(&work_mutex);
sleep (10);
pthread_exit("tid");
}
