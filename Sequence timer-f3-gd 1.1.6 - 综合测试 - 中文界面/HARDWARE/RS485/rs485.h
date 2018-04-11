#ifndef __RS485_H
#define __RS485_H
#include "sys.h"

extern u8 RS485_RX_BUF[64];//���ܻ�������
extern u8 RS485_RX_CNT;//�������ݳ���

//ģʽ����
#define RS485_TX_EN   PDout(7)  //485ģʽ���ƣ�0Ϊ���ܣ�1Ϊ����
//����봮���жϽ��ܣ��벻Ҫע������ĺ궨��
#define EN_USART2_RX  1 //0Ϊ�����ܣ�1Ϊ����

void RS485_Init(u32 bound);
void RS485_Send_Data(u8 *buf,u8 len);
void Rs485_Receive_Data(u8 *buf,u8 *len);


#endif

