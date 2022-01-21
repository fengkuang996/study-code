#include <stdio.h>

int main()
{
	//int a=1;
	int i=0;
	int arr[5]={1,2,3,4,5};
#if 0	
		asm volatile(
		"ldr r0, %0\n"
		"add r0,#1\n"
		"str r0, %0\n"
		:
		:"m"(a)
		:"r0"
	);
	#endif
		asm volatile(
			"mov r0, %0\n"
			"ldr r1, [r0]\n"
			"add r1, #1\n"
			"str r1, [r0],#4\n"
			"ldr r1, [r0]\n"
            "add r1, #1\n"
             "str r1, [r0],#4\n"
			"ldr r1, [r0]\n"
			"add r1, #1\n"
			"str r1, [r0],#4\n"
			"ldr r1, [r0]\n"
			"add r1, #1\n"
            "str r1, [r0],#4\n"


			:
			:"r"(arr)
			:"r0","r1"
		);
		for(i=0;i<5;i++)
			printf("a=%d\n",arr[i]);
    return 0;
}
