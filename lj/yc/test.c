#include "rags.h"
//void (*printf)(char *,...)=0xc3e0cf28;

int test(void)
{
	int ret;
	unsigned char ch;
	//printf("hello");
	__asm__ __volatile__(
		"swi 100\n\t"
		:
	);
	return 0;
}
