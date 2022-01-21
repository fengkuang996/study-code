#include "rags.h"
#include "iic.h"

void thing_iic_read(u8 addr,u8 in_addr,int len,u8 buf[])
{
	u8 i;
	u8 addr_rw;
	iic_con_init();
	//写从机地址
	addr_rw=(addr<<1)；
	iic_write(addr_rw);
	//主从模式产生开始信号
	iic_mt_start();
	iic_ack();
	//发送从机内部寄存器地址
	iic_write(in_addr);
	iic_ack();

	addr_rw=(addt<<1);
	iic_write(addr_rw);

	iic_mr_start();
	iic_ack();

	for(i=0;i<len;i++)
	{
		if(i==len-1)
		{
			iic_nack();
		}
		//等待数据到来(产生中断，发送或接受完成)
		iic_ack();
		//读一个字节
		buf[i]=iic_read();
	}
	iic_mr_stop();
	return 0;
}

void thing_iic_write(u8 addr/*从机地址*/,u8 in_addr/*内部寄存器地址*/,int len/*数据长度*/,u8 buf[])
{
	u8 i;
	u8 addr_rw;
	iic_con_init();
	addr_rw(addr<<1);
	iic_write(addr_rw);

	iic_mt_start();
	iic_ack();

	icc_write(in_addr);
	iic_ack();

	for(i=0;i<len;i++)
	{
		iic_write(buf[i]);
		iic_ack();
	}
	iic_stop();
}
