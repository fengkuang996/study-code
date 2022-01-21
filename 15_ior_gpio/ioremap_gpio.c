#include <linux/init.h>
#include <linux/module.h>
#include "asm/io.h"

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("wz");


volatile unsigned long phy_addr,virt_addr;
volatile unsigned long *GPL2CON,*GPL2DAT,*GPL2PUD;

void gpio_init(void)
{
	phy_addr = 0x11000100;
	virt_addr = (unsigned long)ioremap(phy_addr,0x10);

	GPL2CON = (unsigned long *)(virt_addr+0x00);
	GPL2DAT = (unsigned long *)(virt_addr+0x04);
	GPL2PUD = (unsigned long *)(virt_addr+0x08);
}

void gpio_config(void)
{
	*GPL2CON &= 0xfffffff1;
	*GPL2CON |= 0x00000001;
	*GPL2PUD |= 0X0003;
}

void gpio_on(void)
{
	*GPL2DAT |= 0x01;
}

void gpio_off(void)
{
	*GPL2DAT &= 0xfe;
}



static int hello_init(void)
{
	printk(KERN_EMERG "HELLO WORLD enter!\n");
	gpio_init();
	gpio_config();
	gpio_on();
	return 0;
}

static void hello_exit(void)
{
	printk(KERN_EMERG "HELLO WORLD exit!\n");
	gpio_off();
}

module_init(hello_init);
module_exit(hello_exit);
