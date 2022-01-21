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

	int lsl,lsr,asr,ror;

	asm volatile(
	"mov r0, #-10\n"
	"mov %0 ,r0,lsl #1\n"
	"mov %1, r0,lsr #1\n"
	"mov %2, r0,asr #1\n"
	"mov r1,#0x000000ff\n"
	"mov %3, r1,ror #4\n"

	:"=&r"(lsl),"=&r"(lsr),"=&r"(asr),"=&r"(ror)
	:
	:"r0","r1"
	);

	printf("lsl=%d\n",lsl);
	printf("lsr=%d\n",lsr);
	printf("asr=%d\n",asr);
	printf("ror=%#x\n",ror);
    return 0;
}
