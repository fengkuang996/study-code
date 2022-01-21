#include <stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<pthread.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<semaphore.h>
#define CONSUMERS_COUNT 1
#define PRODUCERS_COUNT 1
#define BUFFSIZE 10
int g_buffsize[BUFFSIZE];
unsigned short in=0;
unsigned short out=0;
unsigned short produce_id=0;
unsigned short consume_id=0;
sem_t g_sem_full;
sem_t  g_sem_empty;
pthread_mutex_t g_mutex;
pthread_t g_thread[CONSUMERS_COUNT+PRODUCERS_COUNT];
void* consume(void *arg)
{
 int i;
 int num=*((int*)arg);
 while(1)
 {
  //打印等待线程
  printf("%d consume wait \n",num);
  sem_wait(&g_sem_empty);
  pthread_mutex_lock(&g_mutex);
  for(i=0;i<BUFFSIZE;i++)
  {
   printf("%02d",i);
   if(g_buffsize[i]==-1)
   printf("%s","null");
   else
   printf("%d",g_buffsize[i]);
   if(i==out)
   printf("\t<--consume");
   printf("\n");
  }
  consume_id=g_buffsize[out];
  printf("begin consume product %d\n",consume_id);
  g_buffsize[out]=-1;
  out=(out+1)%BUFFSIZE;
  printf("end consume product %d\n",consume_id);
  pthread_mutex_unlock(&g_mutex);
  sem_post(&g_sem_full);
  sleep(5);
 }
 return NULL;
}
void *produce(void *arg)
{
  int i;
  int num=*((int*)arg);
  while(1)
  {
    printf("%d produce wait \n",num);
	sem_wait(&g_sem_full);
	pthread_mutex_lock(&g_mutex);
	for(i=0;i<BUFFSIZE;i++)
	{
	  printf("%02d",i);
	  if(g_buffsize[i]==-1)
	  printf("%s","null");
	  else
	  printf("%d",g_buffsize[i]);
	  if(i==in)
      printf("\t<--produce");
	  printf("\n");
	}
	printf("begin produce product %d\n",produce_id);
	g_buffsize[in]=produce_id;
	in=(in+1)%BUFFSIZE;
	printf("end produce product %d\n",produce_id);
	produce_id++;
	pthread_mutex_unlock(&g_mutex);
	sem_post(&g_sem_empty);
	sleep(1);
  }
  return NULL;
}
int main(void)
{
  int i;
  for(i=0;i<BUFFSIZE;i++)
  {
    g_buffsize[i]=-1;
  }
  sem_init(&g_sem_full,0,BUFFSIZE);
  sem_init(&g_sem_empty,0,0);
  pthread_mutex_init(&g_mutex,NULL);
  for(i=0;i<CONSUMERS_COUNT;i++)
  {
    pthread_create(&g_thread[i],NULL,consume,(void*)(&i));
  }
  for(i=0;i<PRODUCERS_COUNT;i++)
  {
    pthread_create(&g_thread[i+CONSUMERS_COUNT],NULL,produce,(void*)(&i));
  }
  for(i=0;i<CONSUMERS_COUNT+PRODUCERS_COUNT;i++)
  {
    pthread_join(g_thread[i],NULL);
  }
  sem_destroy(&g_sem_full);
  sem_destroy(&g_sem_empty);
  pthread_mutex_destroy(&g_mutex);
    return 0;
}
