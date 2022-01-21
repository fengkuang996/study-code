
#ifndef _SPI_H_
#define _SPI_H_

extern void spi_init(void);
extern void software_reset(void);
extern void spi_tx_data(unsigned char data);
extern unsigned char spi_rx_data(void);


#endif 
