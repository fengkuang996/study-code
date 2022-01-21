#include "rags.h"

void spi_init()
{
	GPC1CON &= ~(0xffff<<4);
	GPC1CON |= (0x5555<<4);
//传送通道的选择
	CH_CFG2 = (1<<1)|(1<<0);
//可以不写
	MODE_CFG2 = 0x0;

//从机选择手动还是自动      0：手动   1：自动
	CS_REG2 = (0<<1);
}

void software_reset()
{
//将所有寄存器进行复位
	CH_CFG2 |= (1<<5);
	udelay(500000);
	CH_CFG2 &= ~(1<<5);
}

void spi_tx_data(unsigned char data)
{
	int flag;
//软件复位
	software_reset();
	//将数据写入寄存器中
	SPI_TX_DATA2=data;
	do{
//0 没有发送完    1发送完成
		flag = SPI_STATUS2 & (1<<25);//判断寄存器状态
	}while(!flag);

	printf("send data!\r\n");
}

unsigned char spi_rx_data()
{
	int flag;

	software_reset();

	do{

		SPI_TX_DATA2(0);//发送一个空字节
//判断缓冲区里有没有值
		flag = SPI_STATUS2 & (0x1ff<<15);//判断RX——FIFO是否接受数据
	}while(!flag);

	return(SPI_RX_DATA2 & 0xff);//接受数据

}
