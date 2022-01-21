#include "linux/init.h"
#include "linux/module.h"
#include "linux/stat.h"
#include "linux/moduleparam.h"

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("wz");

static int module_arg1,module_arg2;
static int module_array[50];
static int int_num;
module_param(module_arg1,int,S_IRUSR);
module_param(module_arg2,int,S_IRUSR);
module_param_array(module_array,int,&int_num,S_IRUSR);


static int scdev_init(void)
{
	int i;
	printk(KERN_EMERG "module_arg1 is %d\n",module_arg1);
	printk(KERN_EMERG "module_arg2 is %d\n",module_arg2);
	
	for(i=0;i<int_num;i++)
	{
		printk(KERN_EMERG "module_array[%d] is %d\n",i,module_array[i]);
	}

	printk(KERN_EMERG "hello user enter\n");
	return 0;
}

static void scdev_exit(void)
{
	printk(KERN_EMERG "hello user exit\n");
}






module_init(scdev_init);
module_exit(scdev_exit);

