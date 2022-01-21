
#include <stdio.h>
#include "sys/types.h"
#include "dirent.h"
int main(int argc, char *argv[])
{
	DIR * dp=opendir("../dir");
	if(dp == NULL)
	{
		perror("opendir error");
		return -1;
	}
	while(1)
	{
		struct dirent *item = readdir(dp);
		if(item==NULL)
		{
			perror("readdir()");
			return -1;
		}
		printf("%s\n",item->d_name);
	}
    return 0;
}
