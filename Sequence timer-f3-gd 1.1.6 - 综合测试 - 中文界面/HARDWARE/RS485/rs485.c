#include "rs485.h"
#include "delay.h"
#include "main_setting_page.h"
#include "key.h"
//接受缓存数组,最大64个字节
extern u8 RS232_RX_BUF[8];
//接受的数据长度
extern u8 RS232_RX_CNT;

extern u8 ReceiveData[8];
/*中断接受数据*/
extern u8 temp[8];
extern u8 ReceiveState;
void USART2_IRQHandler(void)
{
    u8 res;
	  u8 clear;
    if(USART_GetITStatus(USART1,USART_IT_RXNE)!=RESET)   //接受到数据
        {
            res=USART_ReceiveData(USART1);//读取接受到的数据				
            ReceiveData[RS232_RX_CNT++]=res;//接受值写入缓存数组					 
			}else if(USART_GetITStatus(USART1,USART_IT_IDLE)!=RESET){
			clear=USART1->SR;
			clear=USART1->DR;	
			ReceiveState=1;
							
			}	

}
void RS485_Init(u32 bound)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    USART_InitTypeDef USART_InitStructure;
    NVIC_InitTypeDef NVIC_InitStructure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);//Enable clock of GPIOA
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2,ENABLE);//Enable clock of USART2

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;	//Initailize PA2
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;	//Initailize PA2
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    GPIO_ResetBits(GPIOA,GPIO_Pin_4);//只接受，不发送

    USART_InitStructure.USART_BaudRate = bound;//Configurate the bound
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;//8位数据长度
    USART_InitStructure.USART_StopBits = USART_StopBits_1;//一个停止位
    USART_InitStructure.USART_Parity = USART_Parity_No;//奇偶校验位
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//无硬件数据流控制
    USART_InitStructure.USART_Mode = USART_Mode_Rx;//接受模式

    NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn; //使能串口2中断
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2; //先占优先级2级
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2; //从优先级2级
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //使能外部中断通道
    NVIC_Init(&NVIC_InitStructure); //根据NVIC_InitStruct中指定的参数初始化外设NVIC寄存器

    USART_Init(USART2, &USART_InitStructure) ; //初始化串口
    USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);//开启接受中端
    USART_Cmd(USART2, ENABLE);//使能串口


}
