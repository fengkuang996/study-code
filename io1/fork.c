#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
	pid_t pid;
	printf("the program is begining ...\n");
	pid=fork();
	if(pid==-1)
	{
		perror("fork son process failed:\n");
		exit(-1);
	}
	else if (pid==0)
	{
		printf("creat son process successful!\n");
		printf("the son process id is %u\t,parent process id is %u\n",getpid(),getppid());
	}
	else
	{
		sleep(3);
		printf("the son process id is%u\t,parent process id is %u\n",getpid(),getppid());
	}
	printf("the program[%u] is ending ....\n",getpid());
	return 0;
}
