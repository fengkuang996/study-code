#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, int *argv[])
{
	int temp;
	FILE *fpr;	if(argc==1)
{		printf("parameter missing!\n");
		exit(0);
	}
	if((fpr=fopen(argv[1],"r"))==NULL)
	{
		printf("can not open the source file!\n");
		exit(0);
	fseek(fpr,0L,0);
	while(!feof(fpr))
	{
		temp=fgetc(fpr);
		putchar(temp);
	}
	fclose(fpr);
	return 0;
}
