
#ifndef _IIC_H_
#define _IIC_H_

void iic_con_init(void);
void iic_mt_start(void);
void iic_mt_stop(void);
void iic_mr_start(void);
void iic_mr_shop(void);
void iic_ack(void);
void iic_nack(void);
void iic_write(unsigned char data);
unsigned char iic_read();




#endif 
