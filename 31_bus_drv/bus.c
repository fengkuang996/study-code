#include <linux/init.h>
#include <linux/module.h>
#include <linux/device.h>
#include "mydevice.h"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Wangz");
extern struct device_driver mydry; 
/*匹配设备成功返回1 失败返回0*/
static int mymatch(struct device *dev, struct device_driver *drv)
{	
	struct mydevice *pdev = container_of(dev,struct mydevice, dev);
	return !strncmp(drv->name,pdev->name, strlen(drv->name));
}

struct bus_type mybus = {
		.name	= "myplatform",
		.match	= mymatch,
};

EXPORT_SYMBOL_GPL(mybus);
static int mybus_init(void)
{
	return bus_register(&mybus);	
}

static void mybus_exit(void)
{
	bus_unregister(&mybus);
}

module_init(mybus_init);
module_exit(mybus_exit);

