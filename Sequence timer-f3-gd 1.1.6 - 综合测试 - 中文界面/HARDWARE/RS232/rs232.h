#ifndef __RS232_H
#define __RS232_H
#include "sys.h"

extern u8 RS232_RX_BUF[8];//8���ֽ���������
extern u8 RS232_RX_CNT;//�����ֽڸ���
extern u8 ReceiveData[8];//���ܻ�������
void ClearBuf(void);
void RS232_Init(u32 bound);
void RS232_Send_Data(u8 *buf,u8 len);
void RS232_Receive_Data(u8 *buf,u8 *len);
void RS232ReceiveData(u8 *buf);
void Receiveshangweijidata(void);
void TestUSART3sendFunction(void);
#endif 