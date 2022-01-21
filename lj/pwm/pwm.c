#include "rags.h"


void pwm_init(int cnt,int cmp)
{
	
	GPD0CON &= ~(0Xf<<0);
	GPD0CON |= (0x2<<0);

	PWM_TCFG0 &= ~(0Xff<<0);
	PWM_TCFG0 |= (0Xc7<<0);

	PWM_TCFG1 &= ~(0Xf<<0);
	PWM_TCFG1 |= (0x2<<0);

	PWM_TCNTB0 = cnt;
	PWM_TCMPB0 = cmp;

	PWM_TCON |= (0x1<<1);
	PWM_TCON &= ~(0x1<<1);

	PWM_TCON |= (0x1<<3);

}

void pwm_start()
{
	PWM_TCON |= 0x1;
}

void pwm_stop()
{
	PWM_TCON &= ~0x1;
}

