#include "sys/types.h"
#include "sys/stat.h"
#include <stdio.h>
#include "fcntl.h"
#include <unistd.h>

int main(int argc, char *argv[])
{
	char buf[128];
	int fd;
	fd = open("myfifo",O_RDONLY);
	read(fd,buf,sizeof(buf));
	printf("%s",buf);
    return 0;
}
