
#include <stdio.h>
#include "stdlib.h"
#include "errno.h"
#include "string.h"
#include "unistd.h"
#include "sys/types.h"
#include "sys/stat.h"
#include "sys/ipc.h"
#include "sys/shm.h"
int main(int argc, char **argv)
{
    int shmid;
	char *p_addr,*c_addr;

	if(argc!=2)
	{
		fprintf(stderr,"Usage:%s\n\a",argv[0]);
		exit(1);
	}
	if((shmid=shmget(IPC_PRIVATE,1024,S_IRUSR|S_IWUSR))==-1)
	{
		fprintf(stderr,"creat share memory error:%s\n\a",strerror(errno));
		exit(1);
	}
	if(fork())
	{
		p_addr=shmat(shmid,0,0);
		memset(p_addr,'\0',1024);
		strncpy(p_addr,argv[1],1024);
		wait(NULL);
		exit(0);
	}
	else 
	{
		sleep(1);
		c_addr=shmat(shmid,0,0);
		printf("client get %s\n",c_addr);
		exit(0);
	}
}
