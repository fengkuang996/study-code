

#pragma once

#define GPX2BASE   0x11000000
#define GPX2CON    (*(volatile unsigned long *)(GPX2BASE+0x0C40))
#define GPX2DAT    (*(volatile unsigned long *)(GPX2BASE+0x0C44))

#define GPL2BASE   0x11000000
#define GPL2CON    (*(volatile unsigned long *)(GPL2BASE+0x0100))
#define GPL2DAT	   (*(volatile unsigned long *)(GPL2BASE+0x0104))

#define GPD0BASE   0x11400000
#define GPD0CON    (*(volatile unsigned long *)(GPD0BASE+0x00A0))
#define GPD0DAT    (*(volatile unsigned long *)(GPD0BASE+0x00A4))

#define GPBBASE		0x11400000
#define GPBCON     (*(volatile unsigned long *)(0X11400040))
#define GPBDAT	   (*(volatile unsigned long *)(0x11400044))

#define GPX1BASE	0x11000000
#define GPX1CON		(*(volatile unsigned long *)(GPX1BASE+0x0c20))
#define GPX1DAT		(*(volatile unsigned long *)(GPX1BASE+0x0c24))

#define EXT_INT41BASE		0x11000000
#define EXT_INT41CON	(*(volatile unsigned long *)(EXT_INT41BASE+0x0e04))
#define EXT_INT41MASK	(*(volatile unsigned long *)(EXT_INT41BASE+0x0f04))
#define EXT_INT41PEND	(*(volatile unsigned long *)(EXT_INT41BASE+0x0f44))
#define ICDDCR		(*(volatile unsigned long *)(0x10490000))

#define ICCICR_CPUBASE 		0x10480000
#define ICCICR_CPU0		(*(volatile unsigned long *)(ICCICR_CPUBASE+0x0000))
#define ICCICR_CPU1		(*(volatile unsigned long *)(ICCICR_CPUBASE+0X4000))
#define ICCICR_CPU2		(*(volatile unsigned long *)(ICCICR_CPUBASE+0X8000))
#define ICCICR_CPU3		(*(volatile unsigned long *)(ICCICR_CPUBASE+0XC000))

#define ICCPMR_CPUBASE		0x10480000
#define ICCPMR_CPU0		(*(volatile unsigned long *)(ICCPMR_CPUBASE+0x0004))
#define ICCPMR_CPU1		(*(volatile unsigned long *)(ICCPMR_CPUBASE+0x4004))
#define ICCPMR_CPU2		(*(volatile unsigned long *)(ICCPMR_CPUBASE+0x8004))
#define ICCPMR_CPU3		(*(volatile unsigned long *)(ICCPMR_CPUBASE+0xc004))

#define ICCIAR_CPUBASE		0x10480000
#define ICCIAR_CPU0		(*(volatile unsigned long *)(ICCIAR_CPUBASE+0x000C))
#define ICCIAR_CPU1		(*(volatile unsigned long *)(ICCIAR_CPUBASE+0x400C))
#define ICCIAR_CPU2		(*(volatile unsigned long *)(ICCIAR_CPUBASE+0x800C))
#define ICCIAR_CPU3		(*(volatile unsigned long *)(ICCIAR_CPUBASE+0xC00C))

#define ICDICPR_CPUBASE		0x10490000
#define ICDICPR0_CPU0	(*(volatile unsigned long *)(ICDICPR_CPUBASE+0x0280))
#define ICDICPR1_CPU0	(*(volatile unsigned long *)(ICDICPR_CPUBASE+0x0284))
#define ICDICPR2_CPU0	(*(volatile unsigned long *)(ICDICPR_CPUBASE+0x0288))
#define ICDICPR3_CPU0	(*(volatile unsigned long *)(ICDICPR_CPUBASE+0x028c))
#define ICDICPR4_CPU0	(*(volatile unsigned long *)(ICDICPR_CPUBASE+0x0290))
#define ICDICPR0_CPU1	(*(volatile unsigned long *)(ICDICPR_CPUBASE+0x4280))
#define ICDICPR0_CPU2	(*(volatile unsigned long *)(ICDICPR_CPUBASE+0x8280))
#define ICDICPR0_CPU3	(*(volatile unsigned long *)(ICDICPR_CPUBASE+0xc280))

#define ICCEOIR_CPUBASE		0x10480000
#define ICCEOIR_CPU0 	(*(volatile unsigned long *)(ICCEOIR_CPUBASE+0x0010))
#define ICCEOIR_CPU1 	(*(volatile unsigned long *)(ICCEOIR_CPUBASE+0x4010))
#define ICCEOIR_CPU2 	(*(volatile unsigned long *)(ICCEOIR_CPUBASE+0x8010))
#define ICCEOIR_CPU3 	(*(volatile unsigned long *)(ICCEOIR_CPUBASE+0xc010))


#define ICDISER_CPUBASE		0x10490000
#define ICDISER0_CPU0	(*(volatile unsigned long *)(ICDISER_CPUBASE+0x0100))
#define ICDISER1_CPU0	(*(volatile unsigned long *)(ICDISER_CPUBASE+0x0104))
#define ICDISER2_CPU0	(*(volatile unsigned long *)(ICDISER_CPUBASE+0x0108))
#define ICDISER3_CPU0	(*(volatile unsigned long *)(ICDISER_CPUBASE+0x010c))
#define ICDISER4_CPU0	(*(volatile unsigned long *)(ICDISER_CPUBASE+0x0110))
#define ICDISER0_CPU1	(*(volatile unsigned long *)(ICDISER_CPUBASE+0x4100))
#define ICDISER0_CPU2	(*(volatile unsigned long *)(ICDISER_CPUBASE+0x8100))
#define ICDISER0_CPU3	(*(volatile unsigned long *)(ICDISER_CPUBASE+0xc100))

#define ICDIPTR_CPUBASE	0x10490000
#define ICDIPTR0_CPU0	(*(volatile unsigned long *)(ICDIPTR_CPUBASE+0X0800))
#define ICDIPTR1_CPU0	(*(volatile unsigned long *)(ICDIPTR_CPUBASE+0X0804))
#define ICDIPTR2_CPU0	(*(volatile unsigned long *)(ICDIPTR_CPUBASE+0X0808))
#define ICDIPTR3_CPU0	(*(volatile unsigned long *)(ICDIPTR_CPUBASE+0X080C))
#define ICDIPTR4_CPU0	(*(volatile unsigned long *)(ICDIPTR_CPUBASE+0X0810))
#define ICDIPTR5_CPU0	(*(volatile unsigned long *)(ICDIPTR_CPUBASE+0X0814))
#define ICDIPTR6_CPU0	(*(volatile unsigned long *)(ICDIPTR_CPUBASE+0X0818))
#define ICDIPTR7_CPU0	(*(volatile unsigned long *)(ICDIPTR_CPUBASE+0X081C))
#define ICDIPTR8_CPU0	(*(volatile unsigned long *)(ICDIPTR_CPUBASE+0X0820))
#define ICDIPTR9_CPU0	(*(volatile unsigned long *)(ICDIPTR_CPUBASE+0X0824))
#define ICDIPTR10_CPU0	(*(volatile unsigned long *)(ICDIPTR_CPUBASE+0X0828))
#define ICDIPTR11_CPU0	(*(volatile unsigned long *)(ICDIPTR_CPUBASE+0X082C))
#define ICDIPTR12_CPU0	(*(volatile unsigned long *)(ICDIPTR_CPUBASE+0X0830))
#define ICDIPTR13_CPU0	(*(volatile unsigned long *)(ICDIPTR_CPUBASE+0X0834))
#define ICDIPTR14_CPU0	(*(volatile unsigned long *)(ICDIPTR_CPUBASE+0X0838))
#define ICDIPTR15_CPU0	(*(volatile unsigned long *)(ICDIPTR_CPUBASE+0X083C))
#define ICDIPTR16_CPU0	(*(volatile unsigned long *)(ICDIPTR_CPUBASE+0X0840))
#define ICDIPTR17_CPU0	(*(volatile unsigned long *)(ICDIPTR_CPUBASE+0X0844))
#define ICDIPTR18_CPU0	(*(volatile unsigned long *)(ICDIPTR_CPUBASE+0X0848))




#define IICBASE		0x1386000
#define IICCON		(*(volatile unsigned long *)(IICBASE+0x0000))
#define IICSTAT		(*(volatile unsigned long *)(IICBASE+0x0004))
#define IICADD		(*(volatile unsigned long *)(IICBASE+0x0008))
#define IICDS		(*(volatile unsigned long *)(IICBASE+0x000c))
#define IICLC		(*(volatile unsigned long *)(IICBASE+0x0010))

#define udelay(us) ((void(*)(int))0xc3e01d68)(us)
#define printf      ((int(*)(const char *,...))0xc3e0cf28)

