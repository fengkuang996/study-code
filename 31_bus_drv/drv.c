#include <linux/init.h>
#include <linux/module.h>
#include <linux/device.h>
#include "mydevice.h"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Wangz");

/*匹配设备成功返回1 失败返回0*/

extern struct bus_type mybus;

static int myprobe(struct device *dev)
{
	struct mydevice *pdev = container_of(dev,struct mydevice,dev);

	printk("in %s: %s device match ok %s dricer.\n",__func__, pdev->name,dev->driver->name);
	return 0;
}

static int myremove(struct device *dev)
{
	printk("in %s: %s dricer is remove.\n",__func__,dev->driver->name);
	return 0;
}

static struct device_driver mydrv ={
		.name	= "spring",
		.bus	= &mybus,
		.probe	= myprobe,
		.remove = myremove,
};

static int mydrv_init(void)
{
	return driver_register(&mydrv);
}

static void mydrv_exit(void)
{
	driver_unregister(&mydrv);
}

module_init(mydrv_init);
module_exit(mydrv_exit);

