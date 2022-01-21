/*====================================================
*   Copyright (C) 2021  All rights reserved.
*
*   文件名称：thread3.c
*   创 建 者：wz  1275805381@qq.com
*   创建日期：2021年05月19日
*   描    述：
================================================================*/

#include <stdio.h>
#include "unistd.h"
#include "pthread.h"

void *thread(void *str)
{
	int i;
	for(i=0;i<3;++i)
	{
		sleep(2);
		printf("the thread %d\n",i);
	}
	return NULL;
}
int main()
{
	pthread_t tid;
	int ret=0;
	int i;
	ret=pthread_create(&tid,NULL,thread, (void *)&i);
	pthread_join(tid,NULL);
	printf("123\n");
	for(i=0;i<3;++i)
	{
		sleep(1);
		printf("main %d\n",i);
	}
	

    return 0;
}
