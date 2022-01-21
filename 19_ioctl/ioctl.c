#include <linux/init.h>
#include <linux/module.h>
#include <linux/uaccess.h>
#include <linux/kernel.h>
#include <linux/io.h>
#include <linux/cdev.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/slab.h>
#include <linux/miscdevice.h>

#define DEVNAME "listmisc"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("wangz");
 
struct kbuf{
	char *kbuf;
	size_t size;
	struct cdev cdev;
}kbufs;


static int kbuf_open (struct inode *inodp, struct file *filp)
{
	return 0;
}
static ssize_t kbuf_read (struct file *filp, char __user *buf, size_t cnt, loff_t *fops)
{
	if(cnt == 0)
	{
		return cnt;
	}
	if(!kbufs.size)
	{
		return -EAGAIN;
	}
	cnt = min(cnt,kbufs.size);
	if(copy_to_user(buf,kbufs.kbuf,cnt))
	{
		return -EIO;
	}
	memmove(kbufs.kbuf,kbufs.kbuf+cnt,kbufs.size - cnt);
	kbufs.size -=cnt;
	return cnt;
}
static ssize_t kbuf_write (struct file *filp, const char __user *buf, size_t cnt, loff_t *fops)
{
	if(cnt == 0)
	{
		return cnt;
	}
	if(kbufs.size == SZ_512)
	{
		return -ENOSPC;
	}
	cnt = min(cnt,SZ_512-kbufs.size);
	if(copy_from_user(kbufs.kbuf + kbufs.size,buf,cnt))
	{
		return -EIO;
	}
	kbufs.size += cnt;
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

static struct miscdevice misc = {
		.minor  = MISC_DYNAMIC_MINOR,
		.name   = DEVNAME,
		.fops   = &fops,
};

static int __init kbuf_init(void)
{
	int ret;
	kbufs.kbuf = kzalloc(SZ_512,GFP_KERNEL);

	if(NULL == kbufs.kbuf)
	{
		return -ENOMEM;
	}

	ret = misc_register(&misc);
	if(ret < 0)
	{
		kfree(kbufs.kbuf);
		return ret;
	}
	return 0;
}
module_init(kbuf_init);

static void __exit kbuf_exit(void)
{
	kfree(kbufs.kbuf);
	misc_deregister(&misc);
}
module_exit(kbuf_exit);


