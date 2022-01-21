#include "rags.h"


void uart_init()
{
	GPA1CON &=~0xff;
	GPA1CON |=0x22;


	ULCON = 0X3;
/*  
中断或者轮训模式
*/
	UCON &=~0xF;
	UCON |= 0x5;

	UFCON = 0;
/*波特率*/
    UBRDIV = 53;
	UFRACVAL = 4;
}

void uart_send(unsigned char ch)
{
	while(!((UTRSTAT >> 1) & 0x1))
	{}


	UTXH = ch;
}


unsigned char uart_rev(void)
{
	while(!(UTRSTAT & 0x1))
	{}

	return URXH;
}

void uart_sendstr(unsigned char *str)
{
	
	while(*str)
	{
		uart_send(*str);
		if(*str=='\n')
		{
			uart_send('\r');
		}
		str++;
	}
	
}




