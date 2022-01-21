.global _start
_start:
	b reset
	nop
	ldr pc, _swi_handler

reset:

	ldr r0, =_start
	mcr p15, 0 ,r0 ,c12, c0,0 @将r0的值写到c12协处理器的p15寄存器中
	stmfd sp! ,{r0-r12,lr}
	bl test
	ldmfd sp!,{r0-r12,pc}
	

stop:
	b stop

_swi_handler:
	.word swi_handler

swi_handler:
	ldr sp, =0x50000000	
	sub r0, lr, #4
	ldr r1,[r0]
	bic r0,r1,#0xff000000
	stmfd sp!,{r0-r12,lr}
	bl do_swi
	ldmfd sp!,{r0-r12,pc}^
