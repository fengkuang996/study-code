#include "linux/init.h"
#include "linux/module.h"
#include "linux/stat.h"
#include "linux/moduleparam.h"
#include "linux/fs.h"
#include "linux/cdev.h"
#include "linux/kdev_t.h"
#include "linux/slab.h"

#define DEVICE_NAME "ascdev"    //设备名
#define DEVICE_MINOR_NUM 2    //次设备个数
#define DEV_MAJOR 0
#define DEV_MINOR 0
#define reg_size  3000    //内存空间大小

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("wz");

int numdev_major = DEV_MAJOR;
int numdev_minor = DEV_MINOR;

module_param(numdev_major,int,S_IRUSR);
module_param(numdev_minor,int,S_IRUSR);
//两个结构体数组  my_dev[]
struct reg_dev{
	char *data;
	unsigned long size;
	struct cdev cdev;
};

struct reg_dev *my_dev;

struct file_operations my_ops = {
	.owner = THIS_MODULE,
};
//设备注册
static void reg_init_cdev(struct reg_dev *dev,int index)
{
	int err;
	int devno;
//将设备号mkdev    +index 加偏移  多个次设备号
	devno = MKDEV(numdev_major,numdev_major+index);
//数据初始化
	cdev_init(&dev->cdev,&my_ops);
	dev->cdev.owner = THIS_MODULE;
	dev->cdev.ops = &my_ops;
//注册字符设备
	err = cdev_add(&dev->cdev,devno,1);

	if(err)
	{
		printk(KERN_EMERG "cdev_add failed\n");
	}
	else
	{
		printk(KERN_EMERG "cdev_add success\n");
	}
}


static int scdev_init(void)
{
	int ret = 0;
	int i;
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
	//动态注册设备号
		ret = alloc_chrdev_region(&num_dev,numdev_minor,DEVICE_MINOR_NUM,DEVICE_NAME);
		numdev_major = MAJOR(num_dev);
		printk(KERN_EMERG "request_ascdev req %d\n",numdev_major);
	}
	if(ret<0)
	{
		printk(KERN_EMERG "register_chrdev_region faild");
	}

	//注册字符设备 开辟空间

	my_dev = kmalloc(DEVICE_MINOR_NUM * sizeof(struct reg_dev),GFP_KERNEL);
	if(!my_dev)
	{
		ret = -ENOMEM;
		goto fail;
	}
	memset(my_dev,0,DEVICE_MINOR_NUM * sizeof(struct reg_dev));

	//设备初始化
	for(i=0;i<DEVICE_MINOR_NUM;i++)
	{
	//为每一个设备开辟空间
		my_dev[i].data = kmalloc(reg_size,GFP_KERNEL);
		//空间初始化
		memset(my_dev[i].data,0,reg_size);
		reg_init_cdev(&my_dev[i],i);     //设备注册
	}

	printk(KERN_EMERG "hello user enter\n");
	return 0;

fail:
//注销设备号
	unregister_chrdev_region(MKDEV(numdev_major,numdev_minor),DEVICE_MINOR_NUM);
	printk(KERN_EMERG "kmalloc failed\n");

	return ret;
}

static void scdev_exit(void)
{
	dev_t num_dev;
	int i;
	num_dev = MKDEV(numdev_major,numdev_minor);
	printk(KERN_EMERG "hello user exit\n");
	//卸载字符设备
	for(i = 0;i < DEVICE_MINOR_NUM;i++);
	{
		cdev_del(&(my_dev[i].cdev));
	}
	unregister_chrdev_region(num_dev,DEVICE_MINOR_NUM);
}

module_init(scdev_init);
module_exit(scdev_exit);

