#include "rags.h"
#include "key.h"



void key_init()
{
	GPX1CON &= ~(0xf<<4);
}

int key_scan()
{
	return GPX1DAT & (0x1<<1);
}

void key_ext_interupt_init()
{
	GPX1CON &= ~(0xf<<4);
	GPX1DAT |= (0xf<<4);

	//设置中断的触发方式
	EXT_INT41CON &= ~(0x7<<4);
	EXT_INT41CON |= (0x2<<2);


	EXT_INT41MASK &= ~(0x1<<1);
	//ICDDCR 全局中断
	ICDDCR =1;//监控所有的中断并且传送给cpu
	
	ICDISER1_CPU0 &= ~(1<<25);
	ICDISER1_CPU0 |= (1<<25);

	ICDIPTR14_CPU0 &= ~(0xff<<8);
	ICDIPTR14_CPU0 |= (0x1<<8);

	ICCICR_CPU0=1;

	ICCPMR_CPU0 = 0xff;//CPU接口的优先级

}


//void do_irq(void)
//{
//	unsigned int irqno = ICCIAR_CPU0 & 0x3ff;
//	printf("irqno=%d",irqno);
//清除外部中断控制器
//	EXT_INT41PEND |= (0x1<<1);
//清除gic分发器控制器
//	ICDICPR_CPU0 |= (1<<25);

//	ICCEOIR_CPU0 |= irqno;
//}



