/*====================================================
*   Copyright (C) 2021  All rights reserved.
*
*   文件名称：asm.c
*   创 建 者：wz  1275805381@qq.com
*   创建日期：2021年06月08日
*   描    述：
================================================================*/

#include <stdio.h>

int main()
{
int ret=0;
#if 0
	asm volatile(
	"mov r0,#1\n"
	"mov r1,#2\n"
	"bl jia\n"
	"mov %0,r0\n"
	:"=&r"(ret)
	::"r0","r1"
	);

#endif

	asm volatile(
	"mov r0,#5\n"
	"mov r1,#6\n"
	"push {r0,r1}\n"
	"mov r0,#1\n"
	"mov r1,#2\n"
	"mov r2,#3\n"
	"mov r3,#4\n"
	"bl jiajia\n"
	"mov %0,r0\n"
	"pop {r0,r1}\n"
	:"=&r"(ret)
	::"r0","r1","r2","r3"

	);
	printf("ret=%d\n",ret);
    return 0;
}


int jiajia(int a,int b,int c,int d,int e,int f)
{
	return a+b+c+d+e+f;
}

int  jia(int a,int b)
{
	
	return a+b;
}
