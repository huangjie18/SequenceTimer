#ifndef __USART_WIFI_H
#define  __USART_WIFI_H

#include "sys.h"
//wifiģ��ӷ�������
extern u8 RS232_RX_BUF[8];//8���ֽ���������
extern u8 RS232_RX_CNT;//�����ֽڸ���
extern u8 ReceiveData[8];//���ܻ�������

void usart3_Init(u32 bound);
void usart3_Send_Data(u8 *buf,u8 len);
void uasrt3_Receive_Data(u8 *buf,u8 *len);

#endif