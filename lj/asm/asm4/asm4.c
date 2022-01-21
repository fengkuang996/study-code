/*====================================================
*   Copyright (C) 2021  All rights reserved.
*
*   文件名称：asm4.c
*   创 建 者：wz  1275805381@qq.com
*   创建日期：2021年06月07日
*   描    述：
================================================================*/

#include <stdio.h>

int main()
{
	int a,b;
	asm volatile(
		
		"ldr r0, =0x00000006\n"
		"ldr r1, =0x00000007\n"
		"subs %0, r0, r1\n"
		"ldr r0, =0x12345678\n"
		"ldr r1, =0x11111111\n"
		"sbc %1, r0, r1\n"
		:"=&r"(b),"=&r"(a)
		:
		:"r0","r1"
	);
	printf("sub=%x%08x\n",a,b);
    return 0;
}
