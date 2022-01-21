#include "rags.h"
#include "pwm.h"

int test()
{
	int i;
	while(1)
	{
		pwm_init(100,50);
		pwm_start();
		udelay(1000000);
		udelay(1000000);
		pwm_stop();
		pwm_init(100,30);
		pwm_start();
		udelay(1000000);
		udelay(1000000);
		pwm_stop();
		pwm_init(100,70);
		pwm_start();
		udelay(1000000);
		udelay(1000000);
		pwm_stop();
	}
	return 0;
}
