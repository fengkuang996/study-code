#include "rags.h"
#include "adc.h"

int test()
{
	int val;
//	int i;
	adc_init();

	while(1)
	{
	//	i++;
	//	if(i%200==0)
	//	{
			val=adc_read();
			adc_start();
			printf("val=%d\r\n",val);
			udelay(1000000);
	//	}
	}
	return 0;
}
