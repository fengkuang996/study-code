
#include "rags.h"

void led_on(void);
void led_off(void);
void delay(int r0);
void delay(int r0)
{
    volatile int count = r0;
    while (count--)
        ;
}

int test(void)
{
	gpl2con = 0x00000001;

	
	while(1)							
	{
		gpl2dat = 1;
		delay(0x80000);
		gpl2dat = 0;
		delay(0x80000);
	}
}

