/*====================================================
*   Copyright (C) 2021  All rights reserved.
*
*   文件名称：signal.c
*   创 建 者：wz  1275805381@qq.com
*   创建日期：2021年05月18日
*   描    述：
================================================================*/

#include <stdio.h>
#include "signal.h"
#include "stdlib.h"
void func(int sign_no)
{
	if(sign_no==SIGINT)
	{
		printf("one SIGINT\n");
	}
	else if(sign_no==SIGQUIT)
	{
		printf("get SIGQUIT	");
	}
}
int main()
{
	printf("sait for signal SIGINT or SIGQUIT\n");
	signal(SIGINT,func);
	signal(SIGQUIT,func);
    pause();
	exit(0);
}
