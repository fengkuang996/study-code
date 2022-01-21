#include <linux/init.h>
#include <linux/module.h>
#include <linux/device.h>
#include "mydevice.h"
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Wangz");

extern struct bus_type mybus;


static void devrelease(struct device *dev)
{
	printk(KERN_INFO "%s device is release \n",dev->init_name);
}

static struct mydevice mydev ={
	.dev = {
		.init_name		= "spring0",
		.bus			= &mybus,
		.release		= devrelease,
	},
	.name = "spring0",
};


static int mydev_init(void)
{
	return device_register(&mydev.dev);
}

static void mydev_exit(void)
{
	device_unregister(&mydev.dev);
}

module_init(mydev_init);
module_exit(mydev_exit);


