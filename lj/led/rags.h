


#pragma once 

#define gpl2base  0x11000000

#define gpl2con   (*(volatile unsigned long *)(gpl2base+0x0100))
#define gpl2dat   (*(volatile unsigned long *)(gpl2base+0x0104))
