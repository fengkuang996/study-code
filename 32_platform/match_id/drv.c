#include <linux/init.h>
#include <linux/module.h>
#include <linux/platform_device.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Wangz");


static int myprobe(struct platform_device *pdev)
{
	printk("%s device piwei %s driver...\n",pdev->name,pdev->dev.driver->name);
	
	return 0;
}
static int myremove(struct platform_device *pdev)
{
	
	printk("%s driver remove ok...\n",pdev->dev.driver->name);
	return 0;
}

static struct platform_driver mypltdrv = {
		.probe		= myprobe,
		.remove		= myremove,
		.driver		= {
				.name	= "spring",
		},
};


static int mypltdrv_init(void)
{
	return platform_driver_register(&mypltdrv);
}

static void mypltdrv_exit(void)
{
	platform_driver_unregister(&mypltdrv);
}

module_init(mypltdrv_init);
module_exit(mypltdrv_exit);

