#include "rags.h"


//void (*printf)(char *, ...)=0xc3e0cf28;


void test()
{
	GPL2CON=0x00000001;
	GPX2CON=0x00000003;
	GPD0CON=0x00000001;
	GPX2CON=0x00000030;
	int flag=1;
	printf("hello key");
	while(1)
	{
		if((GPX2DAT &0X01)==0)
		{
			udelay(1000);
			if((GPX2DAT & 0x01)==0)
			{
				if(flag==1)
				{
				//	GPL2DAT=1;
					GPD0DAT=1;
					flag=0;
					printf("vol1 down\n");
					printf("beep on\n");
				}
			}
		}
		if((GPX2DAT & 0X01)==0)
		{
			udelay(1000);
			if((GPX2DAT & 0x01)==0)
			{
				if(flag==0)
				{
					//GPL2DAT=0;
					GPD0DAT=0;
					flag=1;
					printf("vol1 down\n");
					printf("beep off\n");
				}
			}
		}
		if((GPX2DAT & 0x02)==0)
		{
			udelay(1000);
			if((GPX2DAT & 0x02)==0)
			{
				if(flag==1)
				{
					GPL2DAT=1;
					flag=0;
					printf("vol2 down\n");
					printf("led on\n");
				}
			}
		}
		if((GPX2DAT & 0x02)==0)
		{
			udelay(1000);
			if((GPX2DAT & 0x02)==0)
			{
				if(flag==0)
				{
					GPL2DAT=0;
					flag=1;
					printf("vol2 down\n");
					printf("led off\n");
				}
			}
		}
	}

}
