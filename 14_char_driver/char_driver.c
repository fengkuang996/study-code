#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/stat.h>
#include <linux/fs.h>
#include <linux/kdev_t.h>
#include <linux/cdev.h>
#include <linux/slab.h>
#include <linux/device.h>

#define DEVICE_NAME "hahaha"
#define DEVICE_MINOR_NUM 2
#define DEV_MAJOR 0
#define DEV_MINOR 0
#define REGDEV_SIZE 3000

MODULE_LICENSE("Dual BSD/GPL");
/*声明是开源的，没有内核版本限制*/
MODULE_AUTHOR("wz");
/*声明作者*/

int numdev_major = DEV_MAJOR;
int numdev_minor = DEV_MINOR;

/*输入主设备号*/
module_param(numdev_major,int,S_IRUSR);
/*输入次设备号*/
module_param(numdev_minor,int,S_IRUSR);

static struct class *my_class;

struct reg_dev
{
	char *data;
	unsigned long size;
	
	struct cdev cdev;
};
struct reg_dev *my_dev;
/*打开操作*/
static int hahaha_open(struct inode *inode, struct file *file){
	printk(KERN_EMERG "hahaha_open is success!\n");
	
	return 0;
}
/*关闭操作*/
static int hahaha_release(struct inode *inode, struct file *file){
	printk(KERN_EMERG "hahaha_release is success!\n");
	
	return 0;
}
/*IO操作*/
static long hahaha_ioctl(struct file *file, unsigned int cmd, unsigned long arg){
	printk(KERN_EMERG "hahaha_ioctl is success! cmd is %d,arg is %d \n",cmd,arg);
	
	return 0;
}

ssize_t hahaha_read(struct file *file, char __user *buf, size_t count, loff_t *f_ops){
	return 0;
}

ssize_t hahaha_write(struct file *file, const char __user *buf, size_t count, loff_t *f_ops){
	return 0;
}

loff_t hahaha_llseek(struct file *file, loff_t offset, int ence){
	return 0;
}
struct file_operations my_ops = {
	.owner = THIS_MODULE,
	.open = hahaha_open,
	.release = hahaha_release,
	.unlocked_ioctl = hahaha_ioctl,
	.read = hahaha_read,
	.write = hahaha_write,
	.llseek = hahaha_llseek,
};


/*设备注册到系统*/
static void reg_init_cdev(struct reg_dev *dev,int index){
	int err;
	int devno = MKDEV(numdev_major,numdev_minor+index);
	
	/*数据初始化*/
	cdev_init(&dev->cdev,&my_ops);
	dev->cdev.owner = THIS_MODULE;
	dev->cdev.ops = &my_ops;
	
	/*注册到系统*/
	err = cdev_add(&dev->cdev,devno,1);
	if(err){
		printk(KERN_EMERG "cdev_add %d is fail! %d\n",index,err);
	}
	else{
		printk(KERN_EMERG "cdev_add %d is success!\n",numdev_minor+index);
	}
}

static int scdev_init(void)
{
	int ret = 0,i;
	dev_t num_dev;
	
	
	printk(KERN_EMERG "numdev_major is %d!\n",numdev_major);
	printk(KERN_EMERG "numdev_minor is %d!\n",numdev_minor);
	
	if(numdev_major){
		num_dev = MKDEV(numdev_major,numdev_minor);
		ret = register_chrdev_region(num_dev,DEVICE_MINOR_NUM,DEVICE_NAME);
	}
	else{
		/*动态注册设备号*/
		ret = alloc_chrdev_region(&num_dev,numdev_minor,DEVICE_MINOR_NUM,DEVICE_NAME);
		/*获得主设备号*/
		numdev_major = MAJOR(num_dev);
		printk(KERN_EMERG "adev_region req %d !\n",numdev_major);
	}
	if(ret<0){
		printk(KERN_EMERG "register_chrdev_region req %d is failed!\n",numdev_major);		
	}
	my_class = class_create(THIS_MODULE,DEVICE_NAME);
	
	
	my_dev = kmalloc(DEVICE_MINOR_NUM * sizeof(struct reg_dev),GFP_KERNEL);
	if(!my_dev){
		ret = -ENOMEM;
		goto fail;
	}
	memset(my_dev,0,DEVICE_MINOR_NUM * sizeof(struct reg_dev));
	
	/*设备初始化*/
	for(i=0;i<DEVICE_MINOR_NUM;i++){
		my_dev[i].data = kmalloc(REGDEV_SIZE,GFP_KERNEL);
		memset(my_dev[i].data,0,REGDEV_SIZE);
		/*设备注册到系统*/
		reg_init_cdev(&my_dev[i],i);
		
		/*创建设备节点*/
		device_create(my_class,NULL,MKDEV(numdev_major,numdev_minor+i),NULL,DEVICE_NAME"%d",i);
	}
	
		
	printk(KERN_EMERG "scdev_init!\n");
	/*打印信息，KERN_EMERG表示紧急信息*/
	return 0;

fail:
	/*注销设备号*/
	unregister_chrdev_region(MKDEV(numdev_major,numdev_minor),DEVICE_MINOR_NUM);
	printk(KERN_EMERG "kmalloc is fail!\n");
	
	return ret;
}

static void scdev_exit(void)
{
	int i;
	printk(KERN_EMERG "scdev_exit!\n");
	
	/*除去字符设备*/
	for(i=0;i<DEVICE_MINOR_NUM;i++){
		cdev_del(&(my_dev[i].cdev));
		/*摧毁设备节点函数d*/
		device_destroy(my_class,MKDEV(numdev_major,numdev_minor+i));
	}
	/*释放设备class*/
	class_destroy(my_class);
	/*释放内存*/
	kfree(my_dev);
	
	unregister_chrdev_region(MKDEV(numdev_major,numdev_minor),DEVICE_MINOR_NUM);
}


module_init(scdev_init);
/*初始化函数*/
module_exit(scdev_exit);
/*卸载函数*/
