/*====================================================
*   Copyright (C) 2021  All rights reserved.
*
*   文件名称：uart.h
*   创 建 者：wz  1275805381@qq.com
*   创建日期：2021年06月18日
*   描    述：
================================================================*/

#ifndef _UART_H_
#define _UART_H_


void uart_init();
void uart_send(unsigned char ch);
unsigned char uart_rev(void);
void uart_sendstr(unsigned char *str);

#endif 
