//#define CONFIG_SYS_ICACHE_OFF  

.global _start

_start:
	//disable watch dog
	ldr	r0, =0x10060000
      	mov	r1, #0
      	str	r1, [r0]

	//turn on icache
	mrc	p15, 0, r0, c1, c0, 0
	//bic	r0, r0, #0x00002300	/* clear bits 13, 9:8 (--V- --RS) */
	//bic	r0, r0, #0x00000087	/* clear bits 7, 2:0 (B--- -CAM) */
	//orr	r0, r0, #0x00000002	/* set bit 2 (A) Align */
	//orr	r0, r0, #0x00001000	/* set bit 12 (I) I-Cache */
	
#ifdef CONFIG_SYS_ICACHE_OFF
    	// clear bit 12 (I) I-cache
    	bic	r0, r0, #0x00001000
#else
    	// set bit 12 (I) I-cache
    	orr	r0, r0, #0x00001000
#endif
       	mcr	p15, 0, r0, c1, c0, 0
	//mcr p15, 0, r0, c7, c5, 0	@ invalidate icache

	//set stack
	ldr	sp, =0x02050000

	bl	test

halt:
	b halt

