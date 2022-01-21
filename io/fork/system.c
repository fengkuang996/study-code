#include "sys/types.h"
#include <stdio.h>
#include "stdlib.h"
#include "unistd.h"
#include "sys/wait.h"
int main(int argc, char *argv[])
{

	char cmd[1024];
	while(1)
	{
		printf("please shuru command!\n\r");
		fgets(cmd,sizeof(cmd),stdin);

		pid_t pid=fork();
		if(pid==0)
		{
			system(cmd);
			exit(0);
		}
		if(pid>0)
		{
			wait(NULL);
		}
	}
 	printf("over\n\r");
    return 0;
}
