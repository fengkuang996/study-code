/*====================================================
*   Copyright (C) 2021  All rights reserved.
*
*   文件名称：fork1.c
*   创 建 者：wz  1275805381@qq.com
*   创建日期：2021年05月13日
*   描    述：
================================================================*/

#include <stdio.h>
#include "stdlib.h"
#include "sys/types.h"
#include "unistd.h"
int main()
{
	pid_t pid;
	int count=0;
	pid=vfork();
	count++;
	printf("PID=%d\n",getppid());
	printf("count=%d\n",count);
    return 0;
}
