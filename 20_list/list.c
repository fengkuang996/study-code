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
#include <linux/list.h>
#include <linux/sizes.h>
#define DEVNAME "listmisc"
#define LIMIT_STU 50
MODULE_LICENSE("GPL");
MODULE_AUTHOR("wangz");
 
struct stu {
	char name[SZ_32];
	size_t old;
};

struct stu_node {
	struct stu stu;
	struct list_head list;
};
struct stu_head_t {
	struct list_head head;
	size_t num;
}stuhead = {
	.num = 0
};


static ssize_t list_read (struct file *filp, char __user *buf, size_t cnt, loff_t *fops)
{	
	struct stu_node *stu;
	if(cnt != sizeof(struct stu))  //一次读一个的信息
	{
		return -EINVAL;
	}

	if(stuhead.num == 0)
	{
		return 0;
	}

	stu = container_of(stuhead.head.next, struct stu_node, list);
	if(copy_to_user(buf,&stu->stu,cnt))
	{
		return -EINVAL;
	}

	list_del(stuhead.head.next);
	
	stuhead.num--;
	kfree(stu);

	return cnt;
}

static ssize_t list_write (struct file *filp, const char __user *buf, size_t cnt, loff_t *fops)
{	
	struct stu_node *n;
	int ret;
	if(cnt != sizeof(struct stu))//一次写一个信息
	{
		return -EINVAL;
	}
	if(stuhead.num > LIMIT_STU)
	{
		return -EAGAIN;
	}

	n = kmalloc(sizeof(struct stu_node),GFP_KERNEL);//分配内核空间
	if(NULL == n){
		return -ENOMEM;
	}

	if((ret = copy_from_user(&n->stu,buf,cnt)))//拷贝到内核空间
	{
		return ret;
	}

	list_add_tail(&n->list,&stuhead.head);

	stuhead.num++;

	return cnt;
}
static int list_release (struct inode *inodp, struct file *filp)
{
	return 0;
}
static struct file_operations fops = {
		.owner   = THIS_MODULE,
		.read    = list_read,
		.write   = list_write, 
		.release = list_release,
};

static struct miscdevice misc = {
		.minor  = MISC_DYNAMIC_MINOR,
		.name   = DEVNAME,
		.fops   = &fops,
};

static int __init list_init(void)
{
	int ret;
	INIT_LIST_HEAD(&stuhead.head);   //让头节点自己指向自己
	ret = misc_register(&misc);
	if(ret < 0)
	{
		return ret;
	}
	return 0;
}
module_init(list_init);

static void __exit list_exit(void)
{
	struct list_head *n, *pos;
	struct stu_node *pstu;
	list_for_each_safe(pos,n,&stuhead.head){
		pstu = container_of(pos,struct stu_node,list);
		printk("%s %lu years old\n",pstu->stu.name,pstu->stu.old);
		kfree(pstu);
	}
	misc_deregister(&misc);
}
module_exit(list_exit);


