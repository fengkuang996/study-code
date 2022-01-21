#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#define M 5
#define N 3
#define FLASE 0
#define TRUE 1
int MAX[M][N]={{7,5,3},{6,3,2},{9,0,5},{5,2,0},{3,2,1}};
int AVAILABLE[N]={11,2,9};
int ALLOCATION[M][N]={{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}};
int NEED[M][N]={{7,5,3},{6,3,2},{9,0,5},{5,2,0},{3,2,1}};
int Request[N]={0,0,0};
void main()
{
	int i=0,j=0;
	char flag;
	void showdata();
	void changdata(int);
	void rstordata(int);
	int chkerr();
	showdata();
enter:
	{
		printf("请输入需要申请资源的进程号（从0到");
		printf("%d",M-1);
		printf("):");
		scanf("%d",&i);
	}
	if(i<0||i>=M)
	{
		printf("输入的进程号不存在，重新输入！\n");
		goto enter;
	}
err:
	{
		printf("请输入进程");
		printf("%d",i);
		printf("申请的资源数");
		printf("类别:ABC\n");
		printf("");
		for(j=0;j<N;j++)
		{
			scanf(%d,&Request[j]);
			if(Request[j]>NEED[i][j])
			{
				printf("%d",i);
				printf("号进程");
				printf("申请的资源数>进程");
				printf("%d",i);
				printf("还需要");
				printf("%d",j);
				printf("类资源的资源量！申请不合理，出错！请重新选择!\n");
				goto err;
			}
			else
			{
				if(Request[j]>AVAILABLE[j])
				{
					printf("进程");
					printf("%d",i);
					printf("申请的资源数>系统可用");
					printf("%d",j);
					printf("类资源的资源量！申请不合理，出错！请重新选择！\n");
					goto err;
				}
			}
		}
	}
	changdata(i)
		if(chkerr())
		{
			rstordata(i);
			showdata();
		}
		else
			showdata();
	printf("\n");
	printf("按'y'或'Y'健继续，否则退出\n");
	flag=getch();
	if(flag=='y'||flag=='Y')
		goto enter;
	else
		exit(0);
}
void showdata()
{
	int i,j;
	printf("系统可用资源向量：\n");
	printf("***Available***\n");
	printf("资源类别：A B C\n");
	printf("资源数目：");
	for(j=0;j<N;j++)
	{
		printf("%2d",AVAILABLE[j]);
	}
	printf("\n");
	printf("\n");
	printf("各进程还需要的资源量：\n");
	printf("*******Need*******\n");
	printf("资源类别：ABC\n");
	for(i=0;i<M;i++)
	{
		printf("");
		printf("%d",i);
		printf("号进程：");
		for(j=0;j<N;j++)
		{
			printf("%d",NEED[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("各进程已经得到的资源量:\n");
	printf("***Allocation***\n");
	printf("资源类别:ABC\n");
	for(i=0;i<M;i++)
	{
		printf("");
		printf("%d",i);
		printf("号进程：");
		for(j=0;j<N;j++)
			printf("%d",ALLOCATION[i][j]);
		printf("\n");
	}
	printf("\n");
}
void changdata(int k)
{
	int j;
	for(j=0;j<N;j++)
	{
		AVAILABLE[j]=AVAILABLE[j]-Request[j];
		ALLOCATION[k][j]=ALLOCATION[k][j]+Request[j];
		NEED[k][j]=NEED[k][j]-Request[j];
	}
}
void rstordata(int k)
{
	int j;
	for(j=0;j<N;j++)
	{
		AVAILABLE[j]=AVAILABLE[j]+Request[j];
		ALLOCATION[k][j]=ALLOCATION[k][j]-Request[j];
		NEED[k][j]=NEED[k][j]+Request[j];
	}
}
int chkerr()
{
	int WORK[N],FINISH[M],temp[M];
	int i,j,m,k=0,count;
	for(i=0;i<M;i++)
		FINISH[i]=FALSE;
	for(j=0;j<N;j++)
		WORK[j]=AVAILABLE[j];
	for(i=0;i<M;i++)
	{
		count=0;
		for(j=0;j<N;j++)
			if(FINISH[i]==FALSE&&NEED[i][j]<=WORK[j])
				count++;
		if(count==N)
		{
			for(m=0;m<N;m++)
				WORK[m]=WORK[m]+ALLOCATION[i][m];
			FINISH[i]=TRUE;
			temp[k]=i;
			k++;
			i=-1;
		}
	}
	for(i=0;i<M;i++)
		if(FINISH[i]==FALSE)
		{
			printf("系统不安全!!!本次资源申请不成功!!!\n");
			return 1;
		}
	printf("\n");
	printf("经检查，系统安全，本次分配成功!!!\n");
	printf("\n");
	printf("本次安全序列:");
	for(i=0;i<M;i++)
	{
		printf("进程");
		printf("%d",temp[i]);
		if(i<M-1)
			printf("->");
	}
	printf("\n");
	return 0;
}
