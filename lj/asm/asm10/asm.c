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

	asm volatile(
		"mov r0, #1\n"
		"mov r1, #2\n"
		"mov r2, #3\n"
		"push {r0,r1,r2}\n"
		"mov r0,#10\n"
		"mov r1, #10\n"
		"mov r2,#10\n"
		"pop {r0,r1,r2}\n"
		:::"r0","r1","r2"
	);
    return 0;
}
