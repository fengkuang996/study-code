
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <assert.h>


#define cnt  512

void usage(const char *str)
{
	fprintf(stderr,"usage:\n");
	fprintf(stderr,"      %s  /dev/kbufx\n",str);
	exit(1);
}
//  ./rd  /dev/kbufx
int main(int argc,char *argv[])
{
	int fddev,fdsrc,ret;
	int retr,retw;
	char buf[cnt];

	if(argc!=2)
	{
		usage(argv[0]);
	}
	fddev = open(argv[1],O_RDONLY);
	assert(fddev >= 0);

	retr = read(fddev,buf,cnt-1);
	assert(retr > 0);
	buf[retr] = '\0';

	printf("---Read %d Byte ok!\n",retr);
	printf("%s\n",buf);

	return 0;















}
