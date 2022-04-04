#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

pthread_t t_1,t_2;

pthread_mutex_t mutex;

int a = 0;
int b = 0;

void *task1(void * args){
	pthread_mutex_lock(&mutex);
	printf("\n thread 1 inicio\n");
	int res = a + b;
	printf("%d",res);
	printf("\n thread 1 final\n");
	pthread_mutex_unlock(&mutex);
}

void *task2(void * args){
	pthread_mutex_lock(&mutex);
	printf("\n thread 2 inicio\n");
	int res = a * b;
	printf("%d",res);
	printf("\n thread 2 final\n");
	pthread_mutex_unlock(&mutex);
}

int init_var(){
	printf("\n digite a: ");
	scanf("%d",&a);
	printf("\n digite b: "); 
	scanf("%d",&b);
	return 0;
}

int main (void){
	init_var();
	pthread_mutex_init(&mutex,NULL);
	pthread_create(&t_1,NULL,task1,NULL);
	pthread_create(&t_2,NULL,task2,NULL);
	pthread_join(t_1,NULL);
	pthread_join(t_2,NULL);
	pthread_mutex_destroy(&mutex);
	return 0;
}