#include <linux/init.h>
#include <linux/module.h>
#include <linux/uaccess.h>
#include <linux/kernel.h>
#include <linux/io.h>
#include <linux/cdev.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/slab.h>
#include <linux/miscdevice.h>
#include <linux/interrupt.h>

#define DEVNAME "listmisc"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("wangz");

//四个按键连接到GPX1_2  GPX2_0 GPX2_1  GPX3_3
//中断号分别为10 16 17 27
static struct key_t {
	int irq;//中断号
	char irqname[SZ_16];//中断名
	int cnt;
}key[4] = {
	{ IRQ_EINT(16),"key1",0},
	{ IRQ_EINT(17),"key2",0},
	{ IRQ_EINT(27),"key3",0},
	{ IRQ_EINT(10),"key4",0},	
};

static void free_irq_key(void)
{
	int i;
	for(i=0;i<4;i++)
	{
		free_irq(key[i].irq,&key[i]);
	}
}

static irqreturn_t do_key_irq(int irq,void *dev)//中断服务函数
{
	struct key_t *pdev = dev;

	pdev->cnt++;

	printk("%s is %s!\n",pdev->irqname,pdev->cnt%2?"down":"up");
	
	return IRQ_HANDLED;
}
static int request_irq_key(void)
{
	int i;
	int ret;
	for(i=0;i<4;i++)
	{
		ret = request_irq(key[i].irq,do_key_irq,
							IRQF_TRIGGER_RISING | IRQF_TRIGGER_FALLING,
							key[i].irqname, &key[i]);//申请中断号，并且注册中断
		if(ret < 0)
		{
			goto error0;
		}
	}
	return 0;
error0:
	while(i--)
	{
		free_irq(key[i].irq,&key[i]);//释放中断
	}
	return ret;
}
static int __init kbuf_init(void)
{
	return request_irq_key();
}
module_init(kbuf_init);

static void __exit kbuf_exit(void)
{
	free_irq_key();
}
module_exit(kbuf_exit);


