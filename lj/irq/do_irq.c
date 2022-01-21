#include "rags.h"


void do_irq()
{
	unsigned int irqno = ICCIAR_CPU0 & 0x3ff;
	printf("irqno=%d",irqno);
//清除外部中断控制器
	EXT_INT41PEND |= (0x1<<1);
//清除gic分发器控制器
	ICDICPR1_CPU0 |= (1<<25);

	ICCEOIR_CPU0 |= irqno;
}

