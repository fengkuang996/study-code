/* ex5-8.c*/
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include "stdlib.h"
#include "unistd.h"
/* 处理并打印状态字的子函数*/
void h_exit(int status)
{
		if(WIFEXITED(status))
			printf("normal termination, exit status=%d \n", WEXITSTATUS(status));
		else if(WIFSIGNALED(status))
		{

		printf("abnormal termination, signal number =%d %s\n", WTERMSIG(status),
		#ifdef WCOREDUMP
			WCOREDUMP(status) ? " )" : "(core file generated)");
		#else
			") ");
		#endif
		}
}
	/*主函数。示范三种结束进程的不同方式，并调用h_exit函数处理返回状态字*/
int main()
{
		pid_t pid;
		int status;
		/*子程序正常退出 */
		if((pid=fork())<0)
		{
			printf("fork error \n");
			exit(0);
		}
		else if (pid==0)
			exit(7);
		if(wait(&status)!=pid)		/*等待子进程*/
		{
			printf("wait error \n");
			exit(0);
		}
		h_exit(status);			/*打印状态 */
		/*子进程abort终止 */
		if((pid=fork())<0)
		{
			printf("fork errof\n");
			exit(0);
		}
		else if(pid==0)			/*子进程*/
			abort();			/*产生信号SIGABRT终止进程*/
		if(wait(&status)!=pid)		/*等待子进程*/
		{
			printf("wait error.\n");
			exit(0);
		}
		h_exit(status);			/*打印状态*/
		/* 子进程除零终止 */
		if((pid=fork())<0)
		{
			printf("fork errof\n");
			exit(0);
		}
		else if(pid==0)			/*子进程 */
			status /=0;			/*除数为0产生SIGFPE */
		if(wait(&status)!=pid)
		{
			printf("wait error.\n");
			exit(0);
		}
		h_exit(status);			/*打印状态*/

		exit(0);
}





