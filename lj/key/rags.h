

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



#define udelay(us) ((void(*)(int))0xc3e01d68)(us)
#define printf		((int(*)(const char *,...))0xc3e0cf28)
