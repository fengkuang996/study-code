/*====================================================
*   Copyright (C) 2021  All rights reserved.
*
*   文件名称：thread2.c
*   创 建 者：wz  1275805381@qq.com
*   创建日期：2021年05月19日
*   描    述：
================================================================*/

#include <stdio.h>
#include "unistd.h"
#include "pthread.h"

int a=2;
void *create(void *arg)
{
	printf("new pthread\n");
	printf("a=%d\n",a);
	a++;
	return (void *)0;
}
int main(int argc, char *argv[])
{
	pthread_t tidp;
	int error;
//	int a=5;
	printf("a=%d\n",a);
	error=pthread_create(&tidp,NULL,create,NULL);
	if(error!=0)
	{
		printf("create error");
		return -1;
	}
	sleep(1);
	printf("a=%d\n",a);
	printf("create success");
    return 0;
}
