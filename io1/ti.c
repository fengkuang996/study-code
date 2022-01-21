#include<stdio.h>
int main()
{
	char c;
	printf("input a char");
	system("stty -echo");
	c=getchar();
	system("stty echo");
	printf("you have inputed:%c\n",c);
	return 0;
}
