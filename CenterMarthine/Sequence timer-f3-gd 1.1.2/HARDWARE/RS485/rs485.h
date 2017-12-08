#ifndef __RS485_H
#define __RS485_H
#include "sys.h"

extern u8 RS485_RX_BUF[64];//接受缓存数组
extern u8 RS485_RX_CNT;//缓存数据长度

//模式控制
#define RS485_TX_EN   PDout(7)  //485模式控制：0为接受，1为发送
//如果想串口中断接受，请不要注释下面的宏定义
#define EN_USART2_RX  1 //0为不接受，1为接受

void RS485_Init(u32 bound);
void RS485_Send_Data(u8 *buf,u8 len);
void Rs485_Receive_Data(u8 *buf,u8 *len);


#endif

