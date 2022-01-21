

#pragma once

#define GPX2BASE   0x11000000
#define GPX2CON    (*(volatile unsigned long *)(GPX2BASE+0x0C40))
#define GPX2DAT    (*(volatile unsigned long *)(GPX2BASE+0x0C44))

#define GPL2BASE   0x11000000
#define GPL2CON    (*(volatile unsigned long *)(GPL2BASE+0x0100))
#define GPL2DAT	   (*(volatile unsigned long *)(GPL2BASE+0x0104))

#define GPD0BASE   0x11400000
#define GPD0CON    (*(volatile unsigned long *)(GPD0BASE+0x00A0))
#define GPD0DAT    (*(volatile unsigned long *)(GPD0BASE+0x00A4))

#define GPA1BASE   0x11400000
#define GPA1CON		(*(volatile unsigned long *)(GPA1BASE+0x0020))
#define GPA1DAT		(*(volatile unsigned long *)(GPA1BASE+0x0024))


#define ULCON		(*((volatile unsigned int *)0x13820000))
#define UBRDIV		(*((volatile unsigned int *)0x13820028))
#define UFRACVAL	(*((volatile unsigned int *)0x1382002C))
#define UCON		(*((volatile unsigned int *)0x13820004))
#define UFCON		(*((volatile unsigned int *)0x13820008))
#define UTXH		(*((volatile unsigned int *)0x13820020))
#define URXH		(*((volatile unsigned int *)0x13820024))
#define UTRSTAT		(*((volatile unsigned int *)0x13820010))


#define udelay(us) ((void(*)(int))0xc3e01d68)(us)


extern void uar_init(void);
extern void uart_send(unsigned char ch);
extern unsigned char uart_rev(void);
extern void uart_sendstr(unsigned char *str);

