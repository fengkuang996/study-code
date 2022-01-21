/*====================================================
*   Copyright (C) 2021  All rights reserved.
*
*   文件名称：thread1.c
*   创 建 者：wz  1275805381@qq.com
*   创建日期：2021年05月19日
*   描    述：
================================================================*/

#include <stdio.h>
#include "pthread.h"
#include "unistd.h"
void *thread1(void)
{
	int i;
	for(i=0;i<100;i++)
	{
		printf("NO.1 thread");
		sleep(1);
	}
}

void *thread2(void)
{
	int i;
	for(i=0;i<100;i++)
	{
		printf("NO.2 thread");
		sleep(1);
	}
}

int main()
{
	int i=0;
	int ret=0;
	pthread_t rd1,rd2;
	ret=pthread_create(&rd1,NULL,(void*)thread1,NULL);
	if(ret)
	{
		printf("error");
		return 1;
	}
	
	ret=pthread_create(&rd2,NULL,(void*)thread2,NULL);
	if(ret)
	{
		printf("error");
		return 1;
	}
	pthread_join(rd1,NULL);
	pthread_join(rd2,NULL);
    return 0;
}
