#pragma once

#define GPD0BASE 0x11400000

#define GPD0CON  (*(volatile unsigned long *)(GPD0BASE+0x00A0))
#define GPD0DAT  (*(volatile unsigned long *)(GPD0BASE+0x00A4))

#define udelay(us)   ((void(*)(int))0xc3e01d68)(us)
