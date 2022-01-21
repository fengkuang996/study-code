#include "linux/init.h"
#include "linux/module.h"
#include "linux/stat.h"
#include "linux/moduleparam.h"
#include "linux/fs.h"
#include "linux/cdev.h"
#include "linux/kdev_t.h"


#define DEVICE_NAME "ascdev"
#define DEVICE_MINOR_NUM 2
#define DEV_MAJOR 0
#define DEV_MINOR 0

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("wz");

int numdev_major = DEV_MAJOR;
int numdev_minor = DEV_MINOR;

module_param(numdev_major,int,S_IRUSR);
module_param(numdev_minor,int,S_IRUSR);


static int scdev_init(void)
{
	int ret = 0;
	dev_t num_dev;
	printk(KERN_EMERG "numdev_major is %d\n",numdev_major);
	printk(KERN_EMERG "numdev_minor is %d\n",numdev_minor);
	
	if(numdev_major)
	{
		num_dev = MKDEV(numdev_major,numdev_minor);
		ret = register_chrdev_region(num_dev,DEVICE_MINOR_NUM,DEVICE_NAME);
	}
	else
	{
		ret = alloc_chrdev_region(&num_dev,numdev_minor,DEVICE_MINOR_NUM,DEVICE_NAME);
		numdev_major = MAJOR(num_dev);
		printk(KERN_EMERG "request_ascdev req %d\n",numdev_major);
	}
	if(ret<0)
	{
		printk(KERN_EMERG "register_chrdev_region faild");
	}

	printk(KERN_EMERG "hello user enter\n");
	return 0;
}

static void scdev_exit(void)
{
	dev_t num_dev;
	num_dev = MKDEV(numdev_major,numdev_minor);
	printk(KERN_EMERG "hello user exit\n");
	unregister_chrdev_region(num_dev,DEVICE_MINOR_NUM);
}







module_init(scdev_init);
module_exit(scdev_exit);

