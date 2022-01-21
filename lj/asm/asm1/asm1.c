/*====================================================
*   Copyright (C) 2021  All rights reserved.
*
*   文件名称：asm1.c
*   创 建 者：wz  1275805381@qq.com
*   创建日期：2021年06月07日
*   描    述：
================================================================*/

#include <stdio.h>
int main(void)
{
	int a=1;
	int b=2;
	int c=3;
	#if 0
		a=b;
		b=c;
	#endif
	__asm__ __volatile__(
	"mov %1,%0\n"
	"mov %0,%2\n"
	:"+r"(b), "=&r"(a)
	:"r"(c)
	);
	printf("b=%d\n",b);
	printf("c=%d\n",c);
	printf("a=%d\n",a);
	return 0;
}
