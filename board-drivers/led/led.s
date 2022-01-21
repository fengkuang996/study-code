
.global _start

_start:
/*初始化*/
	ldr r0, =0x020c4068
	ldr r1, =0xffffffff
	str r1, [r0]

	ldr r0, =0x020c406c
	str r1, [r0]

	ldr r0, =0x020c4070
	str r1, [r0]

    ldr r0, =0x020c4074
	str r1, [r0]

    ldr r0, =0x020c4078
	str r1, [r0]

    ldr r0, =0x020c407c
	str r1, [r0]

	ldr r0, =0x020c4080
	str r1, [r0]

/*配置GPIO1_IO03 PIN 的复用为GPIO，*/
	ldr r0, =0x020e0068
	ldr r1, =0x5
	str r1, [r0]
/*配置gpio1_io03的电气属性*/

	ldr r0, =0x020e02f4
	ldr r1, =0x10b0
	str r1, [r0]
/*设置GPIO
设置GPIO1_GDIR寄存器，设置GPIO1_GPIO03为输出
*/
	ldr r0, =0x0209c004
	ldr r1, =0x8
	str r1, [r0]

/*打开LED*/
	ldr r0, =0x0209c000
	ldr r1, =0
	str r1, [r0]

loop:
	b loop 
