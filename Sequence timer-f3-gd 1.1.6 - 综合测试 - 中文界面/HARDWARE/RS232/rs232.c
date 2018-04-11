#include "rs232.h"
#include "delay.h"
#include "data.h"
#include "lcd.h"

//接受缓存数组,最大64个字节
u8 RS232_RX_BUF[8];
//接受的数据长度
u8 RS232_RX_CNT=0;
/**/
u8 ReceiveData[8];
/*中断接受数据*/
u8 temp[8];
u8 ReceiveState;
void USART1_IRQHandler(void)
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

void TestUSART3sendFunction(){
   u8 sendbuf[8]={1,2,3,4,5,6,7,8};
	 u8 t;
	 for(t=0; t<8; t++)
        {
					  //delay_us(500);
            while(USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET);
            USART_SendData(USART1,ReceiveData[t]);
        }
						 while(USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET);
				delay_ms(1000);
				  if(ReceiveState){
											RS232_RX_CNT=0;   
											ReceiveState=0;	
			
					}


}

void Receiveshangweijidata(void){
		  
									  if(ReceiveState){
											RS232_RX_CNT=0;   
											ReceiveState=0;											
									 if(ReceiveData[0]==ip_data.ip){ 
                    RS232_RX_BUF[0]=ReceiveData[0];
                    RS232_RX_BUF[1]=ReceiveData[1];
                    RS232_RX_BUF[2]=ReceiveData[2];
                    RS232_RX_BUF[3]=ReceiveData[3];
                    RS232_RX_BUF[4]=ReceiveData[4];
                    RS232_RX_BUF[5]=ReceiveData[5];
                    RS232_RX_BUF[6]=ReceiveData[6];
                    RS232_RX_BUF[7]=ReceiveData[7];
                    temp[0]=ReceiveData[0];
                    temp[1]=ReceiveData[1];
                    temp[2]=ReceiveData[2];
                    temp[3]=ReceiveData[3];
                    temp[4]=ReceiveData[4];
                    temp[5]=ReceiveData[5];
                    temp[6]=ReceiveData[6];
                    temp[7]=ReceiveData[7]; 
					         
									}else{
	
						if(ReceiveData[0]==0&&ReceiveData[1]==0x02&&ReceiveData[2]==0x20&&ReceiveData[3]==0x17&&ReceiveData[4]==0xAA){
												 										 
		
										RS232_RX_BUF[0]=ReceiveData[0];
                    RS232_RX_BUF[1]=ReceiveData[1];
                    RS232_RX_BUF[2]=ReceiveData[2];
                    RS232_RX_BUF[3]=ReceiveData[3];
                    RS232_RX_BUF[4]=ReceiveData[4];
                    RS232_RX_BUF[5]=ReceiveData[5];
                    RS232_RX_BUF[6]=ReceiveData[6];
										RS232_RX_BUF[7]=ReceiveData[7];
												 
										temp[0]=ReceiveData[0];
                    temp[1]=ReceiveData[1];
                    temp[2]=ReceiveData[2];
                    temp[3]=ReceiveData[3];
                    temp[4]=ReceiveData[4];
                    temp[5]=ReceiveData[5];
                    temp[6]=ReceiveData[6];
                    temp[7]=ReceiveData[7];
												 
											 }
									}
     										
                }
							}

        
/*清空接受缓存数组并重新接受*/
void ClearBuf()
{
    /*清空接受数组*/
    ReceiveData[0]=0;
    ReceiveData[1]=0;
    ReceiveData[2]=0;
    ReceiveData[3]=0;
    ReceiveData[4]=0;
    ReceiveData[5]=0;
    ReceiveData[6]=0;
    ReceiveData[7]=0;
    /*清空命令数组*/
    RS232_RX_BUF[0]=0;
    RS232_RX_BUF[1]=0;
    RS232_RX_BUF[2]=0;
    RS232_RX_BUF[3]=0;
    RS232_RX_BUF[4]=0;
    RS232_RX_BUF[5]=0;
    RS232_RX_BUF[6]=0;
    RS232_RX_BUF[7]=0;			
	  RS232_RX_CNT=0;      										
}
/*RS232初始化函数*/
void RS232_Init(u32 bound)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    USART_InitTypeDef USART_InitStructure;
    NVIC_InitTypeDef NVIC_InitStructure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1|RCC_APB2Periph_GPIOA,ENABLE);

    GPIO_InitStructure.GPIO_Pin=GPIO_Pin_9;//TX
    GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
    GPIO_Init(GPIOA,&GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin=GPIO_Pin_10;//RX
    GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOA,&GPIO_InitStructure);

    USART_InitStructure.USART_BaudRate=bound;//波特率
    USART_InitStructure.USART_WordLength=USART_WordLength_8b;//数据长度八位
    USART_InitStructure.USART_StopBits=USART_StopBits_1;//一个停止位
    USART_InitStructure.USART_Parity=USART_Parity_No;//无奇偶校验
    USART_InitStructure.USART_HardwareFlowControl=USART_HardwareFlowControl_None;//无硬件流控制
    USART_InitStructure.USART_Mode=USART_Mode_Rx|USART_Mode_Tx;//开启fa送和接受功能
 

    NVIC_InitStructure.NVIC_IRQChannel=USART1_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority=1;
    NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
    NVIC_Init(&NVIC_InitStructure);

    USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);//允许接受中断
		USART_Init(USART1,&USART_InitStructure);
		USART_ITConfig(USART1, USART_IT_IDLE, ENABLE);  
    USART_Cmd(USART1,ENABLE);//启动串口
}
/*
RS232发送函数
buf:发送数组首地址
len:发送数据长度
*/
void RS232_Send_Data(u8 *buf,u8 len)
{
    u8 t;
    for(t=0; t<len; t++)
        {
					  //delay_us(500);
            while(USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET);
            USART_SendData(USART1,buf[t]);

        }
    while(USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET);

}
/*
RS232查询接受数据函数
buf:接受缓冲数组
len:接受数据长度
*/
void RS232_Receive_Data(u8 *buf,u8 *len)
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
/*查询*/
void RS232ReceiveData(u8 *buf)
{
    u8 rxlen=RS232_RX_CNT;
    /*等待10毫秒，超过10毫秒RS2323_RX_CNT个数没有发生改变，则认为没有接受再接收到一个数据，接受结束*/
    /*接受到数据且接受完成*/
    if(rxlen==RS232_RX_CNT&&rxlen)
        {
            buf[0]=RS232_RX_BUF[0];
            buf[1]=RS232_RX_BUF[1];
            buf[2]=RS232_RX_BUF[2];
            buf[3]=RS232_RX_BUF[3];
            buf[4]=RS232_RX_BUF[4];
            buf[5]=RS232_RX_BUF[5];
            buf[6]=RS232_RX_BUF[6];
            buf[7]=RS232_RX_BUF[7];
            RS232_RX_CNT=0;/*新接受的数据阀盖旧数据*/
        }
    //delay_us(10);
}

