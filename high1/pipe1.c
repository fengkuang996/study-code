/*====================================================
*   Copyright (C) 2021  All rights reserved.
*
*   文件名称：pipe1.c
*   创 建 者：wz  1275805381@qq.com
*   创建日期：2021年05月16日
*   描    述：
================================================================*/

#include <stdio.h>
#include "unistd.h"
#include "stdlib.h"
#include "sys/types.h"
#include "errno.h"
#include "string.h"
int main()
{
	int pipe_fd[2];
	pid_t pid;
	char buf_r[100];
	char* p_wbuf;
	int r_num;

	memset(buf_r,0,sizeof(buf_r));

	if(pipe(pipe_fd)<0)
	{
		printf("error");
		return -1;
	}

	if((pid=fork())==0)
	{
		printf("\n");
		close(pipe_fd[1]);
		sleep(2);
		if((r_num=read(pipe_fd[0],buf_r,100))>0)
		{
			printf("%d number read from the pipe is %s\n",r_num,buf_r);
		}
		close(pipe_fd[0]);
		exit(0);
	}
	else if(pid>0)
	{
		close(pipe_fd[0]);
		if(write(pipe_fd[1],"hello",5)!=-1)
		printf("parent write1 hello!\n");
		if(write(pipe_fd[1],"Pipe",5)!=-1)
		printf("parent write2 Pipe!\n");
		close(pipe_fd[1]);
		sleep(3);
		waitpid(pid,NULL,0);
		exit(0);
	}
}
