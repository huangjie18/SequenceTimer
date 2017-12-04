#include "rs232.h"

///*RS232初始化函数*/
//void RS232_Init(u32 bound)
//{
//   GPIO_InitTypeDef GPIO_InitStructure;
//   USART_InitTypeDef USART_InitStructure;
//   NVIC_InitTypeDef NVIC_InitStructure;
// 
//	 RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1|RCC_APB2Periph_AFIO|RCC_APB2Periph_GPIOA,ENABLE);
//	
//	 GPIO_InitStructure.GPIO_Pin=GPIO_Pin_9;//RX            
//   GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
//	 GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
//	 GPIO_Init(GPIOA,&GPIO_InitStructure);
//	
//	 GPIO_InitStructure.GPIO_Pin=GPIO_Pin_10;//TX
//	 GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;
//	 GPIO_Init(GPIOA,&GPIO_InitStructure);
//	
//	 USART_InitStructure.USART_BaudRate=bound;//波特率
//	 USART_InitStructure.USART_WordLength=USART_WordLength_8b;//数据长度八位
//	 USART_InitStructure.USART_StopBits=USART_StopBits_1;//一个停止位
//	 USART_InitStructure.USART_Parity=USART_Parity_No;//无奇偶校验
//	 USART_InitStructure.USART_HardwareFlowControl=USART_HardwareFlowControl_None;//无硬件流控制
//	 USART_InitStructure.USART_Mode=USART_Mode_Rx|USART_Mode_Tx;//开启fa送和接受功能
//	 USART_Init(USART1,&USART_InitStructure);
//	
//	
//	 NVIC_InitStructure.NVIC_IRQChannel=USART1_IRQn;
//	 NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0;
//	 NVIC_InitStructure.NVIC_IRQChannelSubPriority=1;
//	 NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
//	 NVIC_Init(&NVIC_InitStructure);
//	
//	
//	USART_ITConfig(USART1,USART_IT_TXE,ENABLE);//允许发送中断
//	USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);//允许接受中断
//	
//	USART_Cmd(USART1,ENABLE);//启动串口
//	USART_ClearFlag(USART1,USART_FLAG_TC);//清除发送完成标志位
//	
//}

///*USART中断函数*/
//void USART1_IRQHandler(void)
//{
// u8 RX_dat;
// if(USART_GetITStatus(USART1,USART_IT_RXNE)==SET)
//	 {
//    USART_ClearITPendingBit(USART1,USART_IT_RXNE);
//    RX_dat=USART_ReceiveData(USART1);
//		while(USART_GetITStatus(USART1,USART_IT_RXNE)==RESET) {}
//		 
//		USART_SendData(USART1,RX_dat); 
//		while(USART_GetITStatus(USART1,USART_IT_RXNE)==RESET) {}
//			
//   }






//}
