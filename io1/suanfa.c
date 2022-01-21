#include<stdio.h>
#include<stdlib.h>
typedef struct item
{
	int num;
	int time;
}pro;
int pn;
int mn;
void print(pro *page1);
int search(int num1,pro *memory1);
int main(void)
{
	int i;
	int curmemory;
	int missnum;
	float missrate;
	char c;
	pro *page;
	pro *memory;
	printf("输入系统分配给的作业的主存中的页面数：");
	scanf("%d",&pn);
	printf("输入内存页面数:");
	scanf("%d",&mn);
	page=(pro*)malloc(sizeof(pro)*pn);
	memory=(pro*)malloc(sizeof(pro)*mn);
	for(i=0;i<pn;i++)
	{
		printf("第%d个页面号为:",i);
		scanf("%d",&page[i].num);
		page[i].time=0;
	}
	do{
		for(i=0;i<mn;i++)
		{
			memory[i].num=-1;
			memory[i].time=-1;
		}
		printf("******f:fifo页面置换算法******\n");
		printf("******o:opt页面置换算法******\n");
		printf("******l:lru页面置换算法******\n");
		printf("******请选择操作类型（f,o,l）,按其他建结束******\n");
		getchar();
		scanf("%c",&c);
		i=0;
		curmemory=0;
		if(c=='f')
		{
			missnum=0;
			printf("fifo页面置换算法情况:\n");
			for(i=0;i<pn;i++)
			{
				if(search(page[i].num,memory)<0)
				{
					missnum++;
					memory[curmemory].num=page[i].num;
					print(memory);
					curmemory=(curmemory+1)%mn;
				}
			}
			missrate=(float)missnum/pn;
			printf("缺页次数:%d  缺页率: %f\n",missnum,missrate);
		}
		if(c=='o')
		{
			missnum=0;
			curmemory=0;
			printf("opt页面置换算法情况:\n");
			for(i=0;i<pn;i++)
			{
				if(search(page[i].num,memory)<0)
				{
					int tem;
					int opt=0;
					for(int k=0;k<mn;k++)
					{
						if(memory[k].num==-1)
						{
							curmemory=k;
							break;
						}
						tem=0;
						int j;
						for(j=i+1;j<pn;j++)
						{
							if(page[j].num==memory[k].num)
							{
								if(tem>opt)
								{
									opt=tem;
									curmemory=k;
								}
								break;
							}
                                                        else tem++;
						}
							if(j==pn)
							{
								opt=tem;
								curmemory=k;
							}
						}
						missnum++;
						memory[curmemory].num=page[i].num;
						print(memory);
					}
				}
				missrate=(float)missnum/pn;
				printf("缺页次数:%d   缺页率:  %f\n",missnum,missrate);
			}
			if(c=='l')
			{
				missnum=0;
				curmemory=0;
				printf("lru页面置换算法情况:\n");
				for(i=0;i<pn;i++)
				{
					int rec=search(page[i].num,memory);
					if(rec<0)
					{
						missnum++;
						for(int j=0;j<mn;j++)
							if(memory[j].time==-1)
							{
								curmemory=j;
								break;
							}
							else if(memory[j].time>memory[curmemory].time)
								curmemory=j;
						memory[curmemory].num=page[i].num;
						memory[curmemory].time=0;
						print(memory);
					}
					else memory[rec].time=0;
					for(int j=0;j<mn;j++)
						if(memory[j].num!=-1)
							memory[j].time++;
				}
				missrate=(float)missnum/pn;
				printf("缺页次数:%d   缺页率:  %f\n",missnum,missrate);
			}
		}
		while(c=='f'||c=='l'||c=='o');
		return 0;
	
}
void print(pro *memory1)
{
	int j;
	for(j=0;j<mn;j++)
		printf("%d",memory1[j].num);
	printf("\n");
}	
int search(int num1,pro *memory1)
{
	int j;
	for(j=0;j<mn;j++)
	{
		if(num1==memory1[j].num)
			return j;
	}
	return -1;
}
