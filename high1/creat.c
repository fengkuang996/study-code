*====================================================
*   Copyright (C) 2021  All rights reserved.
*
*   文件名称：creat.c
*   创 建 者：wz  1275805381@qq.com
*   创建日期：2021年05月11日
*   描    述：
================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void creat_file(char *filename)
{
	if(creat(filename,0755)<0)
	{
		printf("error");
		exit(EXIT_FAILURE);
	}
	else 
	{
		printf("creat file %s success",filename);
	}
}
int main(int argc, char *argv[])
{
	int i=0;
	if(argc<2)
	{
		printf("please again");
		exit(EXIT_FAILURE);
	}
	for(i=1;i<argc;i++)
	{
		creat_file(argv[i]);
	}
	exit(EXIT_SUCCESS);
}
