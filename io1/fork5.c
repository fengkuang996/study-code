#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main(void)
{
	int i, fd, fd1[2];
	pid_t pid;

	int ret = pipe(fd1);
	if(ret == -1)
	{
		perror("pipe error:");
		exit(-1);
	}
	for(i = 0;i < 3; i++)
	{
	    pid = fork();
	    if(pid == -1)
	    {
		perror("fork error:\n");
		exit(-1);	
	    }else if(pid == 0){
		break;
	    }
	}

	if(i < 3){
		sleep(i);
		printf("*****************************\n");
		printf("i'm child %d,pid = %d, ppid = %d\n", i+1, getpid(), getppid());
		switch(i)
		{
		    case 0:
			execl("/bin/ls", "ls", "-l", "-a", NULL);
		    case 1:
			fd = open("ps.txt", O_RDWR | O_CREAT, 0644);
			if(fd < 0){
			    perror("open error:\n");
			    exit(-1);
			}
			dup2(fd,STDOUT_FILENO);
			execlp("ps", "ps", "aux", NULL);
		    case 2:
			close(fd1[0]);
			write(fd1[1], "hello pipe\n", strlen("hello pipe\n"));
		}
	}else{
		sleep(i);
		close(fd1[1]);
		char buf[128];
		printf("*****************************\n");
		printf("i'm parent,pid = %u\n", getpid());
	        ret = read(fd1[0], buf, sizeof(buf));
		if(ret == 0)
		{
			printf("-------\n");
		}
		write(STDOUT_FILENO, buf, ret);
	}
	return 0;
}

