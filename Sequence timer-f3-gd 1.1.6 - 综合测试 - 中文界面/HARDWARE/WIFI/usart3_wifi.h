#ifndef __USART_WIFI_H
#define  __USART_WIFI_H

#include "sys.h"
//wifi模组接发收数据
extern u8 RS232_RX_BUF[8];//8个字节命令数组
extern u8 RS232_RX_CNT;//接受字节个数
extern u8 ReceiveData[8];//接受缓存数组

void usart3_Init(u32 bound);
void usart3_Send_Data(u8 *buf,u8 len);
void uasrt3_Receive_Data(u8 *buf,u8 *len);

#endif