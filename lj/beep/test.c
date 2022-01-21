

#include "rags.h"

void test()
{

	GPD0CON = 0x00000001;
	
	while(1)
	{
		GPD0DAT = 1;
		udelay(1000000);
		GPD0DAT = 0;
		udelay(1000000);
	}
}
