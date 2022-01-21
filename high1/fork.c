
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
	pid_t pid;
	pid=fork();
	if(pid<0)
	{
		printf("erroe");
	}
	else if(pid==0)
	{
		printf("PID=%d\n",getpid());
	}
	else 
	printf("PPID=%d\n",getpid());
    return 0;
}
