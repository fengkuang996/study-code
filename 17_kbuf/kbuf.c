#include <linux/init.h>
#include <linux/module.h>
#include <linux/uaccess.h>
#include <linux/kernel.h>
#include <linux/io.h>
#include <linux/cdev.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/slab.h>
#include <linux/sizes.h>
#include <linux/wait.h>


#define KBUFNUM 16
#define DEVNAME "kbuf"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("wangz");
 
struct kbuf{
	char *kbuf;
	size_t size;
	struct cdev cdev;
	wait_queue_head_t waitr;
	wait_queue_head_t waitw;
}kbufs[KBUFNUM];

static dev_t devnum;
static int major = 0;
static struct class *class;
static struct device *device;
static int kbuf_open (struct inode *inodp, struct file *filp)
{
	//1.可以拿到用户打开的设备文件的主次设备号
//	filp->private_data -->structcdev *i_cdev = &kbufs[x].cdev;
	//2.
	filp->private_data = container_of(inodp->i_cdev,struct kbuf,cdev);
	return 0;
}
static ssize_t kbuf_read (struct file *filp, char __user *buf, size_t cnt, loff_t *fops)
{
	struct kbuf *pdev = filp->private_data;
	//用户打开那个设备文件，读对应设备的数据到BUF

	//检查是否有可读的资源
	if(cnt == 0)
	{
		return cnt;
	}

	wait_event_interruptible(pdev->waitr,pdev->size != 0);
	if(!pdev->size)
	{
		return -EAGAIN;
	}
	cnt = min(cnt,pdev->size);
	if(copy_to_user(buf,pdev->kbuf,cnt))
	{
		return -EIO;
	}
	memmove(pdev->kbuf,pdev->kbuf+cnt,pdev->size - cnt);
	pdev->size -=cnt;
	wake_up(&pdev->waitw);
	return cnt;
}
static ssize_t kbuf_write (struct file *filp, const char __user *buf, size_t cnt, loff_t *fops)
{
	size_t ret;
	struct kbuf *pdev = filp->private_data;
	if(cnt == 0)
	{
		return cnt;
	}
	ret = wait_event_interruptible(pdev->waitw,pdev->size != SZ_512);
	
	if(ret < 0)
	{
		return ret;
	}

	if(pdev->size == SZ_512)
	{
		return -ENOSPC;
	}
	cnt = min(cnt,SZ_512-pdev->size);
	if(copy_from_user(pdev->kbuf + pdev->size,buf,cnt))
	{
		return -EIO;
	}
	pdev->size += cnt;
	wake_up_interruptible(&pdev->waitr);
	return cnt;
}
static int kbuf_release (struct inode *inodp, struct file *filp)
{
	return 0;
}
static struct file_operations fops = {
		.owner   = THIS_MODULE,
		.open    = kbuf_open,
		.read    = kbuf_read,
		.write   = kbuf_write, 
		.release = kbuf_release,
};
static int __init kbuf_init(void)
{
	int i;
	int ret;
	/*
		为每个设备，数组元素 分配空间
		申请注册设备号
		初始化字符设备驱动对象并注册字符设备驱动
	*/

	//申请注册设备号
	if(!major){
		ret = alloc_chrdev_region(&devnum,0,KBUFNUM,DEVNAME);
		if(!ret){
			major = MAJOR(devnum);
		}else{
				return ret;
		}
	}else{
		devnum = MKDEV(major,0);
		ret = register_chrdev_region(devnum,KBUFNUM,DEVNAME);
		if(ret<0)
		{
			return ret;
		}
	}

		class = class_create(THIS_MODULE,DEVNAME);
		if(IS_ERR(class))
		{
			ret = PTR_ERR(class);
			unregister_chrdev_region(devnum,KBUFNUM);
			goto error0;
		}
		

		for(i=0;i<KBUFNUM;i++)
		{
			kbufs[i].kbuf = kzalloc(SZ_512,GFP_KERNEL);
			//gfp_kernel申请空间有可能阻塞，GFP_ATOMIC:不会阻塞
			if(NULL == kbufs[i].kbuf)
			{	
				ret = -ENOMEM;
				goto error1;
			}
			cdev_init(&kbufs[i].cdev,&fops);
			ret = cdev_add(&kbufs[i].cdev,devnum+i,1);
			if(ret < 0){
				kfree(kbufs[i].kbuf);
				goto error1;
			}
			device = device_create(class,NULL,devnum+i,NULL,DEVNAME"%d",i);
			if(IS_ERR(device)){
				cdev_del(&kbufs[i].cdev);
				kfree(&kbufs[i].cdev);
				goto error1;
			}
			init_waitqueue_head(&kbufs[i].waitr);
			init_waitqueue_head(&kbufs[i].waitw);
		}
		return 0;
error1:
	while(i--)
	{
		device_destroy(class,devnum+i);
		kfree(kbufs[i].kbuf);
		cdev_del(&kbufs[i].cdev);
	}
	class_destroy(class);
error0:
	unregister_chrdev_region(devnum,KBUFNUM);
	return ret;
}
module_init(kbuf_init);

static void __exit kbuf_exit(void)
{
	int i = KBUFNUM;	
	while(i--)
	{
		device_destroy(class,devnum+i);
		kfree(kbufs[i].kbuf);
		cdev_del(&kbufs[i].cdev);
	}
	class_destroy(class);
	unregister_chrdev_region(devnum,KBUFNUM);
}
module_exit(kbuf_exit);


