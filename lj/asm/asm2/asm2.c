/*====================================================
*   Copyright (C) 2021  All rights reserved.
*
*   文件名称：asm2.c
*   创 建 者：wz  1275805381@qq.com
*   创建日期：2021年06月07日
*   描    述：
================================================================*/

#include <stdio.h>

int main()
{
	int a=4;
	int b=5;
	int c=0;
	asm volatile(
		"mov r0,%0\n"
		"mov r1,%1\n"
		"add r0,r1\n"
		"mov %2,r0\n"
		:"+r"(a),"+r"(b),"=&r"(c)
		:
		:"r0","r1"
	);
	printf("c=%d",c);

    return 0;
}
