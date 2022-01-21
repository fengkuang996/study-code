#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
	int fd1,fd2,ret,count;
	char buf[128];
	char code[]="wangzhuang\n";
	char num[]="184070301\n";
	if((fd1=open("A.txt",O_RDWR | O_CREAT,0644))==-1)
	{
		perror("open file 'A' faild:");
		exit(-1);
	}
	if((write(fd1,code,sizeof(code)))==-1)
	{
		perror("write for file 'A' faild:\n");
		exit(-1);
	}
	lseek(fd1,0,SEEK_SET);
	if((count=(read(fd1,buf,sizeof(buf))))==-1)
	{
		perror("read buf filed:\n");
		exit(-1);
	}
	ret=lseek(fd1,0,SEEK_END);
	printf("文件A的长度为：%d\n",ret);
	if((fd2=open("B.txt",O_RDWR | O_CREAT,0644))==-1)
	{
		perror("open file 'b' filed:\n");
		exit(-1);
	}
	write(fd2,buf,count);
	lseek(fd2,0,SEEK_END);
	if((write(fd2,num,sizeof(num)))==-1)
	{
		perror("write for file 'B' filed:\n");
		exit(-1);
	}
	close(fd1);
	close(fd2);
}
