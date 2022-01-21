
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <assert.h>

#define cnt 512 

void usage(const char *str)
{
	fprintf(stderr,"usage:\n");
	fprintf(stderr,"      %s  /dev/kbufx file\n",str);
	exit(1);
}
//  ./wr  /dev/kbufx   file
int main(int argc,char *argv[])
{
	int fddev,fdsrc;
	int retr,retw;
	char buf[cnt];

	if(argc!=3)
	{
		usage(argv[0]);
	}
	fddev = open(argv[1],O_WRONLY);
	assert(fddev >= 0);

	fdsrc =open(argv[2],O_RDONLY);
	assert(fdsrc >= 0);

	retr = read(fdsrc,buf,cnt);
	assert(retr > 0);

	retw = write(fddev,buf,retr);
	assert(retw > 0 );

	printf("Write %d Byte ok!\n",retw);


	return 0;















}
