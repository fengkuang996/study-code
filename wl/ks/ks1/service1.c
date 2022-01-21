#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<string.h>
#include<unistd.h>
#include<signal.h>
#include<sys/ipc.h>
#include<errno.h>
#include<sys/shm.h>
#include<time.h>
#include<pthread.h>
#define PORT 4395
#define SIZE 1024
#define SIZE_SHMADD 2048
#define BACKLOG 3
int sockfd;
int fd[BACKLOG];

//显示当前数组
void prt(char username[][30],char password[][30])
{
    int j;
    for(j=0; j<BACKLOG; j++)
    {
        printf("fd[%d]:%d\n",j,fd[j]);
        printf("username[%d]:%s\n",j,username[j]);
        printf("password[%d]:%s\n",j,password[j]);
        printf("——————————\n");
    }
} 
//判断fd[]是否有空闲
int judgefree()
{
    int j;
    for(j=0; j<BACKLOG; j++)
    {
            if(fd[j]==0)
            return j;
    }
    return -1;}

 //判断是否是老用户? j:0
int judgeuser(char* name,char username[][30])
{
    int j;
    for(j=0; j<BACKLOG; j++)
    {
             if(name!="" && strcmp(name,username[j])==0)
            return j;
    }
    return -1;
}

//判断密码是否正确? 1:0
int judgepassword(int n,char* psd,char password[][30])
{
    if(psd!="" && strcmp(psd,password[n])==0)
        return 1;
    return 0;
}
 
//判断用户登录状态
int judge(char* name,char * psd,char username[][30],char password[][30])
{
    int i=judgeuser(name,username);
     int j=judgefree();
    if(i >= 0)
    {
         if(judgepassword(i,psd,password))
         {
            return 0;//老用户且密码正确
        }
         else
            return 1;//密码错误
    }
    else
    {
        if(j>=0)
        {
             return 2;//聊天室有空位
        }
        else
            return 3;//聊天室已满
    }

}
//套接字描述符
int get_sockfd()
{
    struct sockaddr_in server_addr;
    if((sockfd=socket(AF_INET,SOCK_STREAM,0))==-1)
    {
        fprintf(stderr,"Socket error(套接字创建错误):%s\n\a",strerror(errno));
        exit(1);
    }
    else
    {
        printf("Socket successful(套接字创建成功)!\n");
    }
    bzero(&server_addr,sizeof(struct sockaddr_in));
    server_addr.sin_family=AF_INET;
    server_addr.sin_addr.s_addr=htonl(INADDR_ANY);
    server_addr.sin_port=htons(PORT);
    /*绑定服务器的ip和服务器端口号*/
    if(bind(sockfd,(struct sockaddr *)(&server_addr),sizeof(struct sockaddr))==-1)
    {
        fprintf(stderr,"Bind error(绑定失败):%s\n\a",strerror(errno));
        exit(1);
    }
     else
     {
        printf("Bind successful(绑定成功)!\n");
    }
    /* 设置允许连接的最大客户端数 */
    if(listen(sockfd,BACKLOG)==-1)
     {
        fprintf(stderr,"Listen error(打开监听失败):%s\n\a",strerror(errno));
        exit(1);
    }
     else
    {
        printf("Listening(监听已打开).....\n");
    }
    return sockfd;
}

/*创建共享存储区*/
 int shmid_create()
{
     int shmid;
    if((shmid = shmget(IPC_PRIVATE,SIZE_SHMADD,0777)) < 0)
     {
         perror("shmid error(共享内存区创建失败)!");
         exit(1);
    }
     else
         printf("shmid success(共享内存区创建成功)!\n");
    return shmid;
 }
 
int main(int argc, char *argv[])
{
    int shmid;
    char *shmadd;
    /***********共享内存**************/
    shmid = shmid_create();
     //映射共享内存
    shmadd = shmat(shmid, 0, 0);

    char username[BACKLOG][30]= {"","",""};
    char password[BACKLOG][30]= {"","",""};
     
    int mark=0;
    char usermsg[SIZE];
     char shmadd_buffer[SIZE_SHMADD];
     char buffer[SIZE];

    struct sockaddr_in client_addr;
     int new_fd;
    int i;
     char* name="";
    char* psd="";
     int login=0;
    int sin_size;
    pid_t ppid,pid;
     //创建套接字描述符
    int sockfd = get_sockfd();
     
    //循环接收客户端
    
    while(1)//服务器阻塞,直到客户程序建立连接
   {
       
        sin_size=sizeof(struct sockaddr_in);
        if((new_fd=accept(sockfd,(struct sockaddr *)(&client_addr),&sin_size))==-1)
        {
            fprintf(stderr,"Accept error(连接分配失败):%s\n\a",strerror(errno));
            exit(1);
        }
        else
        {
             printf("Accept successful(连接分配成功)!\n");
			 perror("\n");
        }
		
	

        memset(usermsg,0,SIZE);

		
        memset(buffer,0,SIZE);

		
        if( recv(new_fd,buffer,SIZE,0) < 0)
		{
			perror("\n");
		}
        //截取用户名和密码
        strcpy(usermsg,buffer);
        name=strtok(usermsg,"&");
         psd=strtok(NULL,"&");
        mark=judgefree(fd);

		printf("dalong\n");
         printf("\n已连接了客户端%d : %d : %d \n",mark,inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
        printf("dalong\n");
		memset(buffer,0,SIZE);
        //判断用户登录状态
         switch(judge(name,psd,username,password))
         {
         case 0:
        {
            i=judgeuser(name,username);
            fd[i]=new_fd;
            login=1;
            strcpy(buffer,"\n-------欢迎进入聊天室，输入quit退出-------\n");
             break;
         }
        case 2:
        {
            mark=judgefree(fd);
            fd[mark] = new_fd;
            strcpy(username[mark],name);
            strcpy(password[mark],psd);
             login=1;
             strcpy(buffer,"\n-------欢迎进入聊天室，输入quit退出-------\n");
             break;
         }
         case 1:
         {
             login=0;
             stpcpy(buffer,"\n密码错误，请重新登录!");
            break;
        }
         case 3:
        {
            login=0;
            stpcpy(buffer,"\n聊天室已满!");
            break;
        }
        }
        ppid=fork();
         if(ppid==0)
        {
             send(new_fd,buffer,strlen(buffer),0);
            if(login==1)
             {
                prt(username,password);
                //将加入的新客户发送给所有在线的客户端
                 memset(buffer,0,SIZE);
                stpcpy(buffer,name);
                strcat(buffer," 进入了聊天室....");
                 for(i=0; i<BACKLOG; i++)
                {
                    if(fd[i]!=-1)
                    {
                        send(fd[i],buffer,strlen(buffer),0);
                    }
                }
                //创建子进程进行读写操作/
                pid = fork();//fork()创建时，复制父进程变量状态
                 while(1)
                {
                    if(pid > 0)
                    {
                        //父进程用于接收信息/
                         memset(buffer,0,SIZE);
                        if((recv(new_fd,buffer,SIZE,0)) <= 0)
                         {
                             close(new_fd);
                            exit(1);
                        }
                        strncpy(shmadd, buffer, SIZE_SHMADD);//将缓存区的客户端信息放入共享内存里
                         printf(" %s\n",buffer);
                     }
                     if(pid == 0)
                     {
                         //子进程用于发送信息/
                         sleep(1);//先执行父进程
                         if(strcmp(shmadd_buffer,shmadd) != 0)
                         {
                             strcpy(shmadd_buffer,shmadd);
                             if(new_fd  > 0)
                             {
                                 if(send(new_fd,shmadd,strlen(shmadd),0) == -1)
                                 {
                                     perror("error send(发送失败)!");
                                 }
                                 strcpy(shmadd,shmadd_buffer);
                             }
                         }
                     }
 
                 }
             }
         }
     }
     free(buffer);
     close(new_fd);
     close(sockfd);
     return 0;
}
