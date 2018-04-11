#include "usart3_wifi.h"
#include "delay.h"
#include "data.h"
#include "lcd.h"

//接受缓存数组,最大64个字节
extern u8 RS232_RX_BUF[8];
//接受的数据长度
extern u8 RS232_RX_CNT;

extern u8 ReceiveData[8];
/*中断接受数据*/
extern u8 temp[8];
extern u8 ReceiveState;
void USART3_IRQHandler(void)
{
     u8 res;
	  u8 clear;
    if(USART_GetITStatus(USART3,USART_IT_RXNE)!=RESET)   //接受到数据
        {
            res=USART_ReceiveData(USART3);//读取接受到的数据				
            ReceiveData[RS232_RX_CNT++]=res;//接受值写入缓存数组					 
			}else if(USART_GetITStatus(USART3,USART_IT_IDLE)!=RESET){
			clear=USART1->SR;
			clear=USART1->DR;	
			ReceiveState=1;
							
			}		
}
/*usart3初始化*/
void usart3_Init(u32 bound)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    USART_InitTypeDef USART_InitStructure;
    NVIC_InitTypeDef NVIC_InitStructure;
	
    //开启时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);
	
    GPIO_InitStructure.GPIO_Pin=GPIO_Pin_10;//TX
    GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
    GPIO_Init(GPIOB,&GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin=GPIO_Pin_11;//RX
    GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOB,&GPIO_InitStructure);

    USART_InitStructure.USART_BaudRate=bound;//波特率
    USART_InitStructure.USART_WordLength=USART_WordLength_8b;//数据长度八位
    USART_InitStructure.USART_StopBits=USART_StopBits_1;//一个停止位
    USART_InitStructure.USART_Parity=USART_Parity_No;//无奇偶校验
    USART_InitStructure.USART_HardwareFlowControl=USART_HardwareFlowControl_None;//无硬件流控制
    USART_InitStructure.USART_Mode=USART_Mode_Rx|USART_Mode_Tx;//开启fa送和接受功能



    NVIC_InitStructure.NVIC_IRQChannel=USART3_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority=1;
    NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
    NVIC_Init(&NVIC_InitStructure);
		
    USART_Init(USART3,&USART_InitStructure);				
    USART_ITConfig(USART3,USART_IT_RXNE,ENABLE);//允许接受中断
		USART_ITConfig(USART3, USART_IT_IDLE, ENABLE);  
    USART_Cmd(USART3,ENABLE);//启动串口
}

/*
RS232发送函数
buf:发送数组首地址
len:发送数据长度
*/
void usart3_Send_Data(u8 *buf,u8 len)
{
    u8 t;
    for(t=0; t<len; t++)
        {
            while(USART_GetFlagStatus(USART3, USART_FLAG_TC) == RESET);
            USART_SendData(USART3,buf[t]);

        }
    while(USART_GetFlagStatus(USART3, USART_FLAG_TC) == RESET);

}

/*
RS232查询接受数据函数
buf:接受缓冲数组
len:接受数据长度
*/
void usart3_Receive_Data(u8 *buf,u8 *len)
{
    u8 rxlen=RS232_RX_CNT;
    u8 i=0;
    *len=0;//设置接收数据长度为0
    /*等待10毫秒，超过10毫秒RS2323_RX_CNT个数没有发生改变，则认为没有接受再接收到一个数据，接受结束*/
    delay_ms(10);
    /*接受到数据且接受完成*/
    if(rxlen==RS232_RX_CNT&&rxlen)
        {

            for(i=0; i<8; i++)
                {
                    buf[i]=RS232_RX_BUF[i];
                }
            *len=RS232_RX_CNT;/*记录原来的数据*/
            RS232_RX_CNT=0;/*新接受的数据阀盖旧数据*/
        }

}

