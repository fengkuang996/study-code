#include "rags.h"
#include "key.h"
int test(void)
{
	int ret;
	unsigned char ch;
	
	key_init();
	key_scan();
	key_ext_interupt_init();
	

	return 0;
}
