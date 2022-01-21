#include <linux/init.h>
#include <linux/module.h>
#include <linux/platform_device.h>
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Wangz");

static struct platform_device mypltdev2 = {
		.name	= "spring",
		.id		= 1,	
};



static int mypltdev_init(void)
{
	return platform_device_register(&mypltdev2);
}

static void mypltdev_exit(void)
{
	platform_device_unregister(&mypltdev2);
}

module_init(mypltdev_init);
module_exit(mypltdev_exit);


