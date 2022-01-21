#include "rags.h"

void iic_con_init()
{	
	//SDA 初始化GPIO
	GPBCON &= ~(0xf<<8);
	GPBCON |= (0x3<<8);
	//SCL 
	GPBCON &= ~(0xf<<12);
	GPBCON |= (0x3<<12);
	
	//设置IIC控制器
	IICCON = (1<<7)|(0<<6)|(1<<5)|(15<<0);

	return;
}

//mr接受模式  mt发送模式

void iic_mt_start()
{
	IICSTAT = (3<<6)|(1<<5)|(1<<4);
	return;
}

void iic_mt_stop()
{
	IICSTAT = (3<<6)|(0<<5)|(1<<4);
	return;
}

void iic_mr_rtart()
{
	IICSTAT = (2<<6)|(1<<5)|(1<<4);
	return;
}

void iic_mr_rtart()
{
	IICSTAT = (2<<6)|(0<<5)|(1<<4);
	return;
}

void iic_ack()
{
	int flag;
	do{
	flag = IICCON & (1<<4);
	}while(!flag);
//重新使能IIC，将中断状态位清除
	IICCON &= ~(1<<4);
	return;
}

void iic_nack()
{
	IICCON &= ~(1<<7);
	return;
}

void iic_write(unsigned char data)
{
	IICDS = data;
	return;
}

unsigned char iic_read()
{
	return IICDS;
}

