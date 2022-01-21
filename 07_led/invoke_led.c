#include <stdio.h>
#include "sys/stat.h"
#include "sys/types.h"
#include "fcntl.h"
#include "unistd.h"
#include "sys/ioctl.h"

int main()
{
	int fd;
	char *hello_node = "/dev/hello_ctl";

	fd = open(hello_node,O_RDWR|O_NDELAY);
	if(fd<0)
	{
		printf("open %s error\n",hello_node);
	}
	else
	{
		printf("open %s success\n",hello_node);
		while(1)
		{
			ioctl(fd,0,1);
			sleep(2);
			ioctl(fd,1,1);
			sleep(2);
		}
	}
	close(fd);
}
