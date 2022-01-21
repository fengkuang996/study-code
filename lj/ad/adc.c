#include "rags.h"

void adc_init(void)
{

//位数，分频，频率
	ADCCON |= (1<<16)|(1<<14)|(19<<6);
//选择待机模式
	ADCCON &= ~(1<<2);
//选择通道
	ADCMUX = 0X0;

}

void adc_start(void)
{
	ADCCON |= 1;
}

unsigned int adc_read(void)
{
//检测AD是否转换完成
	while(!(ADCCON & (1<<15)))

	return (ADCDAT & 0xfff);
}


