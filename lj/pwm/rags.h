

#pragma once

#define GPX2BASE  				0x11000000
#define GPX2CON   				(*(volatile unsigned long *)(GPX2BASE+0x0C40))
#define GPX2DAT   				(*(volatile unsigned long *)(GPX2BASE+0x0C44))

#define GPL2BASE  				0x11000000
#define GPL2CON   				(*(volatile unsigned long *)(GPL2BASE+0x0100))
#define GPL2DAT	  				(*(volatile unsigned long *)(GPL2BASE+0x0104))

#define GPD0BASE  				0x11400000
#define GPD0CON    				(*(volatile unsigned long *)(GPD0BASE+0x00A0))
#define GPD0DAT    				(*(volatile unsigned long *)(GPD0BASE+0x00A4))

#define GPBBASE					0x11400000
#define GPBCON   			    (*(volatile unsigned long *)(0X11400040))
#define GPBDAT	  				(*(volatile unsigned long *)(0x11400044))

#define GPX1BASE			    0x11000000
#define GPX1CON					(*(volatile unsigned long *)(GPX1BASE+0x0c20))
#define GPX1DAT					(*(volatile unsigned long *)(GPX1BASE+0x0c24))

#define GPC1BASE			   	0x11400000
#define GPC1CON					(*(volatile unsigned long *)(GPC1BASE+0x0080))
#define GPC1DAT	  				(*(volatile unsigned long *)(GPC1BASE+0x0084))

#define EXT_INT41BASE		  	0x11000000
#define EXT_INT41CON			(*(volatile unsigned long *)(EXT_INT41BASE+0x0e04))
#define EXT_INT41MASK			(*(volatile unsigned long *)(EXT_INT41BASE+0x0f04))
#define EXT_INT41PEND			(*(volatile unsigned long *)(EXT_INT41BASE+0x0f44))
#define ICDDCR					(*(volatile unsigned long *)(0x10490000))

#define ICCICR_CPUBASE 			0x10480000
#define ICCICR_CPU0				(*(volatile unsigned long *)(ICCICR_CPUBASE+0x0000))
#define ICCICR_CPU1				(*(volatile unsigned long *)(ICCICR_CPUBASE+0X4000))
#define ICCICR_CPU2				(*(volatile unsigned long *)(ICCICR_CPUBASE+0X8000))
#define ICCICR_CPU3				(*(volatile unsigned long *)(ICCICR_CPUBASE+0XC000))

#define ICCPMR_CPUBASE			0x10480000
#define ICCPMR_CPU0				(*(volatile unsigned long *)(ICCPMR_CPUBASE+0x0004))
#define ICCPMR_CPU1				(*(volatile unsigned long *)(ICCPMR_CPUBASE+0x4004))
#define ICCPMR_CPU2				(*(volatile unsigned long *)(ICCPMR_CPUBASE+0x8004))
#define ICCPMR_CPU3				(*(volatile unsigned long *)(ICCPMR_CPUBASE+0xc004))

#define ICCIAR_CPUBASE			0x10480000
#define ICCIAR_CPU0				(*(volatile unsigned long *)(ICCIAR_CPUBASE+0x000C))
#define ICCIAR_CPU1				(*(volatile unsigned long *)(ICCIAR_CPUBASE+0x400C))
#define ICCIAR_CPU2				(*(volatile unsigned long *)(ICCIAR_CPUBASE+0x800C))
#define ICCIAR_CPU3				(*(volatile unsigned long *)(ICCIAR_CPUBASE+0xC00C))

#define ICDICPR_CPUBASE			0x10490000
#define ICDICPR0_CPU0			(*(volatile unsigned long *)(ICDICPR_CPUBASE+0x0280))
#define ICDICPR1_CPU0			(*(volatile unsigned long *)(ICDICPR_CPUBASE+0x0284))
#define ICDICPR2_CPU0			(*(volatile unsigned long *)(ICDICPR_CPUBASE+0x0288))
#define ICDICPR3_CPU0		 	(*(volatile unsigned long *)(ICDICPR_CPUBASE+0x028c))
#define ICDICPR4_CPU0			(*(volatile unsigned long *)(ICDICPR_CPUBASE+0x0290))
#define ICDICPR0_CPU1			(*(volatile unsigned long *)(ICDICPR_CPUBASE+0x4280))
#define ICDICPR0_CPU2			(*(volatile unsigned long *)(ICDICPR_CPUBASE+0x8280))
#define ICDICPR0_CPU3			(*(volatile unsigned long *)(ICDICPR_CPUBASE+0xc280))

#define ICCEOIR_CPUBASE			0x10480000
#define ICCEOIR_CPU0 			(*(volatile unsigned long *)(ICCEOIR_CPUBASE+0x0010))
#define ICCEOIR_CPU1 			(*(volatile unsigned long *)(ICCEOIR_CPUBASE+0x4010))
#define ICCEOIR_CPU2 			(*(volatile unsigned long *)(ICCEOIR_CPUBASE+0x8010))
#define ICCEOIR_CPU3 			(*(volatile unsigned long *)(ICCEOIR_CPUBASE+0xc010))


#define ICDISER_CPUBASE			0x10490000
#define ICDISER0_CPU0			(*(volatile unsigned long *)(ICDISER_CPUBASE+0x0100))
#define ICDISER1_CPU0			(*(volatile unsigned long *)(ICDISER_CPUBASE+0x0104))
#define ICDISER2_CPU0			(*(volatile unsigned long *)(ICDISER_CPUBASE+0x0108))
#define ICDISER3_CPU0			(*(volatile unsigned long *)(ICDISER_CPUBASE+0x010c))
#define ICDISER4_CPU0			(*(volatile unsigned long *)(ICDISER_CPUBASE+0x0110))
#define ICDISER0_CPU1			(*(volatile unsigned long *)(ICDISER_CPUBASE+0x4100))
#define ICDISER0_CPU2			(*(volatile unsigned long *)(ICDISER_CPUBASE+0x8100))
#define ICDISER0_CPU3			(*(volatile unsigned long *)(ICDISER_CPUBASE+0xc100))

#define ICDIPTR_CPUBASE			0x10490000
#define ICDIPTR0_CPU0			(*(volatile unsigned long *)(ICDIPTR_CPUBASE+0X0800))
#define ICDIPTR1_CPU0			(*(volatile unsigned long *)(ICDIPTR_CPUBASE+0X0804))
#define ICDIPTR2_CPU0			(*(volatile unsigned long *)(ICDIPTR_CPUBASE+0X0808))
#define ICDIPTR3_CPU0		  	(*(volatile unsigned long *)(ICDIPTR_CPUBASE+0X080C))
#define ICDIPTR4_CPU0			(*(volatile unsigned long *)(ICDIPTR_CPUBASE+0X0810))
#define ICDIPTR5_CPU0			(*(volatile unsigned long *)(ICDIPTR_CPUBASE+0X0814))
#define ICDIPTR6_CPU0			(*(volatile unsigned long *)(ICDIPTR_CPUBASE+0X0818))
#define ICDIPTR7_CPU0			(*(volatile unsigned long *)(ICDIPTR_CPUBASE+0X081C))
#define ICDIPTR8_CPU0			(*(volatile unsigned long *)(ICDIPTR_CPUBASE+0X0820))
#define ICDIPTR9_CPU0			(*(volatile unsigned long *)(ICDIPTR_CPUBASE+0X0824))
#define ICDIPTR10_CPU0			(*(volatile unsigned long *)(ICDIPTR_CPUBASE+0X0828))
#define ICDIPTR11_CPU0			(*(volatile unsigned long *)(ICDIPTR_CPUBASE+0X082C))
#define ICDIPTR12_CPU0			(*(volatile unsigned long *)(ICDIPTR_CPUBASE+0X0830))
#define ICDIPTR13_CPU0			(*(volatile unsigned long *)(ICDIPTR_CPUBASE+0X0834))
#define ICDIPTR14_CPU0			(*(volatile unsigned long *)(ICDIPTR_CPUBASE+0X0838))
#define ICDIPTR15_CPU0			(*(volatile unsigned long *)(ICDIPTR_CPUBASE+0X083C))
#define ICDIPTR16_CPU0			(*(volatile unsigned long *)(ICDIPTR_CPUBASE+0X0840))
#define ICDIPTR17_CPU0			(*(volatile unsigned long *)(ICDIPTR_CPUBASE+0X0844))
#define ICDIPTR18_CPU0			(*(volatile unsigned long *)(ICDIPTR_CPUBASE+0X0848))

#define IICBASE				 	0x13860000
#define IICCON					(*(volatile unsigned long *)(IICBASE+0x0000))
#define IICSTAT					(*(volatile unsigned long *)(IICBASE+0x0004))
#define IICADD					(*(volatile unsigned long *)(IICBASE+0x0008))
#define IICDS					(*(volatile unsigned long *)(IICBASE+0x000c))
#define IICLC					(*(volatile unsigned long *)(IICBASE+0x0010))

#define CH_CFG2					(*(volatile unsigned long *)(0x13940000))
#define MODE_CFG2				(*(volatile unsigned long *)(0x13940008))
#define CS_REG2					(*(volatile unsigned long *)(0x1394000c))
#define SPI_INT_EN2 			(*(volatile unsigned long *)(0x13940010))
#define SPI_STATUS2 			(*(volatile unsigned long *)(0X13940014))
#define SPI_TX_DATA2			(*(volatile unsigned long *)(0x13940018))
#define SPI_RX_DATA2			(*(volatile unsigned long *)(0x1394001c))
#define PACKET_CNT_REG2 		(*(volatile unsigned long *)(0x13940020))
#define PENDING_CLR_REG2		(*(volatile unsigned long *)(0x13940024))
#define SWAP_CFG2				(*(volatile unsigned long *)(0x13940028))
#define  FB_CLK_SEL2			(*(volatile unsigned long *)(0x1394002c))

#define CH_CFG1     			(*(volatile unsigned long *)(0x13930000))
#define MODE_CFG1				(*(volatile unsigned long *)(0x13930008))
#define CS_REG1					(*(volatile unsigned long *)(0x1393000c))
#define SPI_INT_EN1 			(*(volatile unsigned long *)(0x13930010))
#define SPI_STATUS1 			(*(volatile unsigned long *)(0X13930014))
#define SPI_TX_DATA1			(*(volatile unsigned long *)(0x13930018))
#define SPI_RX_DATA1			(*(volatile unsigned long *)(0x1393001c))
#define PACKET_CNT_REG1 		(*(volatile unsigned long *)(0x13930020))
#define PENDING_CLR_REG1		(*(volatile unsigned long *)(0x13930024))
#define SWAP_CFG1				(*(volatile unsigned long *)(0x13930028))
#define  FB_CLK_SEL1			(*(volatile unsigned long *)(0x1393002c))

#define CH_CFG0     			(*(volatile unsigned long *)(0x13920000))
#define MODE_CFG0				(*(volatile unsigned long *)(0x13920008))
#define CS_REG0					(*(volatile unsigned long *)(0x1392000c))
#define SPI_INT_EN0 			(*(volatile unsigned long *)(0x13920010))
#define SPI_STATUS0 			(*(volatile unsigned long *)(0X13920014))
#define SPI_TX_DATA0			(*(volatile unsigned long *)(0x13920018))
#define SPI_RX_DATA0			(*(volatile unsigned long *)(0x1392001c))
#define PACKET_CNT_REG0 		(*(volatile unsigned long *)(0x13920020))
#define PENDING_CLR_REG0		(*(volatile unsigned long *)(0x13920024))
#define SWAP_CFG0				(*(volatile unsigned long *)(0x13920028))
#define  FB_CLK_SEL0			(*(volatile unsigned long *)(0x1392002c))

#define ADCBASE					0x126c0000
#define ADCCON					(*(volatile unsigned long *)(ADCBASE+0x0000))
#define ADCDLY					(*(volatile unsigned long *)(ADCBASE+0x0008))
#define ADCDAT					(*(volatile unsigned long *)(ADCBASE+0x000c))
#define CLRINTADC				(*(volatile unsigned long *)(ADCBASE+0x0018))
#define ADCMUX					(*(volatile unsigned long *)(ADCBASE+0x001C))

#define PWM_TCFG0				(*(volatile unsigned long *)(0x139D0000))
#define PWM_TCFG1				(*(volatile unsigned long *)(0x139D0004))
#define PWM_TCON				(*(volatile unsigned long *)(0x139D0008))
#define PWM_TCNTB0				(*(volatile unsigned long *)(0x139D000c))
#define PWM_TCMPB0				(*(volatile unsigned long *)(0x139D0010))
#define PWM_TCNTO0				(*(volatile unsigned long *)(0x139D0014))
#define PWM_TCNTB1				(*(volatile unsigned long *)(0x139D0018))
#define PWM_TCMPB1				(*(volatile unsigned long *)(0x139D001c))
#define PWM_TCNTO1				(*(volatile unsigned long *)(0X139d0020))
#define PWM_TCNTB2				(*(volatile unsigned long *)(0x139D0024))
#define PWM_TCMPB2				(*(volatile unsigned long *)(0x139D0028))
#define PWM_TCNTO2				(*(volatile unsigned long *)(0x139D002c))
#define PWM_TCNTB3				(*(volatile unsigned long *)(0x139D0030))
#define PWM_TCMPB3				(*(volatile unsigned long *)(0x139D0034))
#define PWM_TCNTO3				(*(volatile unsigned long *)(0X139d0038))
#define PWM_TCNTB4				(*(volatile unsigned long *)(0X139d003C))
#define PWM_TCNTO4				(*(volatile unsigned long *)(0x139d0040))
#define PWM_TINT_CSTAT			(*(volatile unsigned long *)(0x139d0044))

#define PWM_ISP_TCFG0			(*(volatile unsigned long *)(0x12160000))
#define PWM_ISP_TCFG1			(*(volatile unsigned long *)(0x12160004))
#define PWM_ISP_TCON			(*(volatile unsigned long *)(0x12160008))
#define PWM_ISP_TCNTB0			(*(volatile unsigned long *)(0x1216000c))
#define PWM_ISP_TCMPB0			(*(volatile unsigned long *)(0x12160010))
#define PWM_ISP_TCNTO0			(*(volatile unsigned long *)(0x12160014))
#define PWM_ISP_TCNTB1			(*(volatile unsigned long *)(0x12160018))
#define PWM_ISP_TCMPB1			(*(volatile unsigned long *)(0x1216001c))
#define PWM_ISP_TCNTO1			(*(volatile unsigned long *)(0X12160020))
#define PWM_ISP_TCNTB2			(*(volatile unsigned long *)(0x12160024))
#define PWM_ISP_TCMPB2			(*(volatile unsigned long *)(0x12160028))
#define PWM_ISP_TCNTO2			(*(volatile unsigned long *)(0x1216002c))
#define PWM_ISP_TCNTB3			(*(volatile unsigned long *)(0x12160030))
#define PWM_ISP_TCMPB3			(*(volatile unsigned long *)(0x12160034))
#define PWM_ISP_TCNTO3			(*(volatile unsigned long *)(0X12160038))
#define PWM_ISP_TCNTB4			(*(volatile unsigned long *)(0X1216003C))
#define PWM_ISP_TCNTO4			(*(volatile unsigned long *)(0x12160040))
#define PWM_ISP_TINT_CSTAT		(*(volatile unsigned long *)(0x12160044))

#define udelay(us) 				((void(*)(int))0xc3e01d68)(us)
#define printf      			((int(*)(const char *,...))0xc3e0cf28)

