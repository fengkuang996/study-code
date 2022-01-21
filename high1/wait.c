/*====================================================
*   Copyright (C) 2021  All rights reserved.
*
*   文件名称：wait.c
*   创 建 者：wz  1275805381@qq.com
*   创建日期：2021年05月13日
*   描    述：
================================================================*/

#include <stdio.h>
#include "sys/wait.h"
#include "unistd.h"
#include "stdlib.h"
int main()
{
	pid_t pid,ppid;
	pid=fork();
	if(pid==0)
	{
		printf("PID=%d\n",getpid());
		sleep(5);
	}
	else if(pid>0)
	{
		ppid=wait(NULL);
		printf("pid=%d\n",ppid);
	}
	exit(0);
}
