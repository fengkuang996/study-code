.global _start
_start:
	ldr r0, =0x10060000
	mov r1, #0
	str r1, [r0]

	mrc p15, 0, r0, c1, c0, 0

	ldr sp, =0x02050000
	bl test

