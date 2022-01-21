#include <unistd.h>

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "fcntl.h"
int main(int argc, char *argv[])
{
	int ret = mkfifo("myfifo",0666);
	if(ret==-1)
	{
		perror("mkfifo()");
		return -1;
	}
	int fd;
	fd = open("myfifo",O_WRONLY);
	write(fd,"1234567890\n",11);
	
    return 0;
}
