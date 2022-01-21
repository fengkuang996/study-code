#include <stdio.h>
#include "sys/stat.h"
#include "sys/types.h"
#include "fcntl.h"
#include "unistd.h"
#include "sys/ioctl.h"

int main()
{
	int fd;
	char *hello_node0 = "/dev/hahaha0";
	char *hello_node1 = "/dev/hahaha1";

	fd = open(hello_node0,O_RDWR|O_NDELAY);
	if(fd<0)
	{
		printf("open %s error\n",hello_node0);
	}
	else
	{
		printf("open %s success\n",hello_node0);
	}
	close(fd);

	fd = open(hello_node1,O_RDWR|O_NDELAY);
	if(fd<0)
	{
		printf("open %s error\n",hello_node1);
	}
	else
	{
		printf("open %s success\n",hello_node1);
	}
}
