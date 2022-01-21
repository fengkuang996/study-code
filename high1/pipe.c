/*====================================================
*   Copyright (C) 2021  All rights reserved.
*
*   文件名称：pipe.c
*   创 建 者：wz  1275805381@qq.com
*   创建日期：2021年05月16日
*   描    述：
================================================================*/

#include <stdio.h>
#include "errno.h"
#include "stdlib.h"
#include "unistd.h"
int main()
{
	int pipe_fd[2];
	if(pipe(pipe_fd)<0)
	{
		printf("pipe creat error!\r\n");
		return -1;
	}
	else 
	printf("pipe creat success!\r\n");
	close(pipe_fd[0]);
	close(pipe_fd[1]);
}
