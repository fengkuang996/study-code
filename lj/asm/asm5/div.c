/*====================================================
*   Copyright (C) 2021  All rights reserved.
*
*   文件名称：div.c
*   创 建 者：wz  1275805381@qq.com
*   创建日期：2021年06月07日
*   描    述：
================================================================*/

#include <stdio.h>

int main()
{
	int a=10;
	int b=-2;
	int div;

	asm volatile(
		"mov r0,%0\n"
		"mov r1,%1\n"
		"sdiv %3,r0,r1\n"
		:"+r"(a),"+r"(b),"+r"(div)
		:
		:"r0","r1"
	);
	printf("div=%d\n",div);
    return 0;
}
