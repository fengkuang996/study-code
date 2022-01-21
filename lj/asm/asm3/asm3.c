/*====================================================
*   Copyright (C) 2021  All rights reserved.
*
*   文件名称：asm3.c
*   创 建 者：wz  1275805381@qq.com
*   创建日期：2021年06月07日
*   描    述：
================================================================*/

#include <stdio.h>

int main()
{

	int a,b;
	asm volatile(
		"ldr r0, =0xfffffff8\n"
		"ldr r1, =0x0000000a\n"
		"adds %0, r0, r1\n"
		"ldr r0, =0x12222222\n"
		"ldr r1, =0x00000000\n"
		"adc %1, r0, r1\n"
		:"=&r"(b),"=&r"(a)
	);
	printf("%x%08x",a,b);
    return 0;
}
