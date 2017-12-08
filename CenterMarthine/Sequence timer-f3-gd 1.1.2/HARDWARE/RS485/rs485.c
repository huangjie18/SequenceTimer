#include "rs485.h"
#include "delay.h"

#ifdef EN_USART2_RX  //如果接受使能

//接受缓存数组,最大64个字节
u8 RS485_RX_BUF[64];
//接受的数据长度
u8 RS485_RX_CNT;

/*USART2的中断函数*/


void USART2_IRQHandler(void)

{
    u8 res;

    if(USART_GetITStatus(USART2,USART_IT_RXNE)!=RESET)//接受到数据
        {
            res=USART_ReceiveData(USART2);//读取接受到的数据
            if(RS485_RX_CNT<64)
                {
                    RS485_RX_BUF[RS485_RX_CNT]=res;//接受值写入缓冲区
                    RS485_RX_CNT++;
                }


        }

}



#endif


/*Initailize GPIO and USART2
PCLK1:PLCK1 Clock Fequence(Hz)
*/
void RS485_Init(u32 bound)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    USART_InitTypeDef USART_InitStructure;
    NVIC_InitTypeDef NVIC_InitStructure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOD,ENABLE);//Enable clock of GPIOA
	  RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2,ENABLE);//Enable clock of USART2
	  
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;				 //Configurate PD7
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 	
 	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 	GPIO_Init(GPIOD, &GPIO_InitStructure);  //Initailize PD7
 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;	//Initailize PA2
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	
  GPIO_Init(GPIOA, &GPIO_InitStructure);
   
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  GPIO_Init(GPIOA, &GPIO_InitStructure);  

	RCC_APB1PeriphResetCmd(RCC_APB1Periph_USART2,ENABLE);//Reset USART
	RCC_APB1PeriphResetCmd(RCC_APB1Periph_USART2,DISABLE);//Stop the operation
 
	
 #ifdef EN_USART2_RX		 //if enable the reception function
	USART_InitStructure.USART_BaudRate = bound;//Configurate the bound
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;//8位数据长度
	USART_InitStructure.USART_StopBits = USART_StopBits_1;//一个停止位
	USART_InitStructure.USART_Parity = USART_Parity_No;///奇偶校验位
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//无硬件数据流控制
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;//收发模式

  USART_Init(USART2, &USART_InitStructure); ; //初始化串口
  
	NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn; //使能串口2中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2; //先占优先级2级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2; //从优先级2级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //使能外部中断通道
	NVIC_Init(&NVIC_InitStructure); //根据NVIC_InitStruct中指定的参数初始化外设NVIC寄存器
 
  USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);//开启发送中断
//  USART_ITConfig(USART2,USART_IT_TXE,ENABLE); //开启接受中断
	 
  USART_Cmd(USART2, ENABLE);                    //使能串口 

 #endif 
 
 RS485_TX_EN=0;			//默认为接收模式
 
}

/*RES485:发送数据函数
 *buf:发送数据首地址
 *len:发送数据的字节数（不要超过64个字节）
 */
void RS485_Send_Data(u8 *buf,u8 len)
{
   u8 t;
	 RS485_TX_EN=1;//设置为发送模式
   for(t=0;t<len;t++){
	 while(USART_GetFlagStatus(USART2,USART_FLAG_TC)==RESET)
	 USART_SendData(USART2,buf[t]);
	 } 
  	while(USART_GetFlagStatus(USART2,USART_FLAG_TC)==RESET);
	  RS485_RX_CNT=0;
    RS485_TX_EN=0;//设置为接受模式
	 
}
/*RS485:查询接收到的数据函数
 *buf:接受缓存首地址
 *len:读到的数据长度
*/
void RS485_Read_Data(u8 *buf,u8 *len)
{
 u8  rxlen=RS485_RX_CNT;
 u8 i;
 *len=0; //默认为0
 delay_ms(10);//等待10ms,连续超过10ms没有结束到一个数据，则认为接收结束
	if(rxlen==RS485_RX_CNT&&rxlen){//接受数据，且接受完成
	 for(i=0;i<rxlen;i++){
	  buf[i]=RS485_RX_BUF[i];
	
	 }
	 
	*len=RS485_RX_CNT;//记录本次数据长度
	 RS485_RX_CNT=0;//清零
	
	}
}



