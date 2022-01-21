#include <stdio.h>
#include "sys/stat.h"
#include "sys/types.h"
#include "fcntl.h"
#include "unistd.h"
#include "sys/ioctl.h"

int main(int argc,char **argv)
{
	int fd;
	char *hello_node = "/dev/hahaha0";

	fd = open(hello_node,O_RDWR|O_NDELAY);
	if(fd<0)
	{
		printf("open %s error\n",hello_node);
	}
	else
	{
		printf("open %s success\n",hello_node);
		ioctl(fd,atoi(argv[1]),atoi(argv[2]));
		printf("ioctl %d,cmd is %s!io_arg is %s!\n",hello_node,argv[1],argv[2]);
	}
	close(fd);
}
