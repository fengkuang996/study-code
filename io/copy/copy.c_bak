
#include <stdio.h>

int main(int argc, char *argv[])
{
	FILE * s_fp = fopen("copy.c","r");
	if(s_fp == NULL)
	{
		perror("perror()1");
		return -1;
	}

	FILE * d_fp = fopen("copy.c_bak","w");
	if(d_fp == NULL)
	{
		perror("perror()2");
		return -1;
	}

	while(1)
	{
		int ch;


		ch = fgetc(s_fp);
		if(ch == EOF)
		{
			break;
		}
		fputc(ch, d_fp);
	}
	pclose(s_fp);

	pclose(d_fp);
    return 0;
}
