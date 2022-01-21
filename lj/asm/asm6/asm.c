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
	int and,orr,bic,eor;

	asm volatile(
		"mov r0,#0x5\n"
		"mov r1,#0x6\n"
		"and %0,r0,r1\n"

		"mov r0,#0x5\n"
		"mov r1,#0x6\n"
		"orr %1,r0,r1\n"

		"mov r0,#0x5\n"
		"mov r1,#0x6\n"
		"eor %2,r0,r1\n"

		"mov r0,#0xff\n"
		"bic %3,r0,#(3<<2)\n"

		:"=&r"(and),"=&r"(orr),"=&r"(eor),"=&r"(bic)
		:
		:"r0","r1"
	);
	printf("and=%d\n",and);
	printf("orr=%d\n",orr);
	printf("eor=%d\n",eor);
	printf("bic=%0x\n",bic);

    return 0;
}
