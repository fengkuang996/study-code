#include <linux/init.h>
#include <linux/module.h>

/*驱动注册的头文件，包含驱动的结构体和注册和卸载的函数*/
#include <linux/platform_device.h>
/*注册杂项设备头文件*/
#include <linux/miscdevice.h>
/*注册设备节点的文件结构体*/
#include <linux/fs.h>

#define DEVICE_NAME "hello123"
MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("wz");

static long hello_ioctl( struct file *files, unsigned int cmd, unsigned long arg){

	
	printk("cmd is %d,arg is %ld\n",cmd,arg);
	return 0;
}

static int hello_release(struct inode *inode, struct file *file){
	printk(KERN_EMERG "hello release\n");
	return 0;
}

static int hello_open(struct inode *inode, struct file *file){
	printk(KERN_EMERG "hello open\n");
	return 0;
}

static struct file_operations hello_ops = {
	.owner = THIS_MODULE,
	.open = hello_open,
	.release = hello_release,
	.unlocked_ioctl = hello_ioctl,
};

static  struct miscdevice hello_dev = {
	.minor = MISC_DYNAMIC_MINOR,
	.name = DEVICE_NAME,
	.fops = &hello_ops,
};


static int hello_init(void)
{
	
	printk(KERN_EMERG "HELLO WORLD enter!\n");
	misc_register(&hello_dev);
	return 0;
}


static void hello_exit(void)
{
	printk(KERN_EMERG "HELLO WORLD exit!\n");
	
	misc_deregister(&hello_dev);	
}

module_init(hello_init);
module_exit(hello_exit);

