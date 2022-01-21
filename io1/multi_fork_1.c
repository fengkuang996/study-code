#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
	pid_t pid;
	int i;
	for(i=0;i<3;i++)
	{
		pid=fork();

		if(pid==-1)
		{
			perror("create son process failed !\n");
		}
		else if(pid==0)
		{
			printf("creat son process ok,son process pid is %u\t,parent process pid is %u\n",getpid(),getppid());
		}
		else
		{
			printf("creat son process ok,son process pid is %u\tt,parent process pid is %u\n",getpid(),getppid());
		}
	}
	printf("the programming[%d] will ending..\n",getpid());
	return 0;
}
