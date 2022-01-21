/*====================================================
*   Copyright (C) 2021  All rights reserved.
*
*   文件名称：execl.c
*   创 建 者：wz  1275805381@qq.com
*   创建日期：2021年05月13日
*   描    述：
================================================================*/

#include <stdio.h>
#include "sys/types.h"
#include "unistd.h"
#include "stdlib.h"
int main()
{
	execlp("ls","ls","-al","/home/wz/test/high",(char *)0);
    return 0;
}
