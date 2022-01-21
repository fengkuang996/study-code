


#include "rags.h"
#include "uart.h"
void (*printf)(char *, ...)=0xc3e0cf28;       
int test()
{
	char ret;
	unsigned char ch=0;
	printf("nihao\n\r");
	uart_init();
	uart_send('\r');
	uart_send('\n');
	uart_send('a');
	uart_send('b');
	uart_send('c');
	uart_send('\r');
	uart_send('\n');
	uart_sendstr("hello\n");


	ch=uart_rev();
//	uart_send(ch);
	printf("%c\n\r",ch);

}
