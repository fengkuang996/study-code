/*====================================================
*   Copyright (C) 2021  All rights reserved.
*
*   文件名称：asm.c
*   创 建 者：wz  1275805381@qq.com
*   创建日期：2021年06月07日
*   描    述：
================================================================*/

#include <stdio.h>

int main()
{
	char *s="hello\n";
	int ret;
	ret=write(1,s,strlen(s));
	ret=syscall(4,1,s,strlen(s));

	asm volatile(
		"mov r0,#1\n"
		"mov r1,%[s]\n"
		"mov r2,#10\n"
		"swi 0x900004\n"
		"mov %0,r0\n"
		:"=&r"(ret)
		:[s]"r"(s)
		:"r0","r1","r2"
	);
	printf("ret=%d\n",ret);
    return 0;
}
