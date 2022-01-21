#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
	pid_t pid;
	int i;
	for(i=0;i<3;i++)	{
		pid =fork();
		if(pid==-1)
		{			       perror("creat son process failed!\n");
		}		      
               else if(pid==0)			{
		break;
		}
		else
		{
			 printf("creat son process ok,son process pid is%u\t,parent process pid is %u\n",getpid(),getppid());

		}
	}
	printf("the programming will ending..\n");
	return 0;
}
