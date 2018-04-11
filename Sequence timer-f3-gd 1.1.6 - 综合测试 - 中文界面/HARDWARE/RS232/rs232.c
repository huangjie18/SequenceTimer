#include "rs232.h"
#include "delay.h"
#include "data.h"
#include "lcd.h"

//���ܻ�������,���64���ֽ�
u8 RS232_RX_BUF[8];
//���ܵ����ݳ���
u8 RS232_RX_CNT=0;
/**/
u8 ReceiveData[8];
/*�жϽ�������*/
u8 temp[8];
u8 ReceiveState;
void USART1_IRQHandler(void)
{
    u8 res;
	  u8 clear;
    if(USART_GetITStatus(USART1,USART_IT_RXNE)!=RESET)   //���ܵ�����
        {
            res=USART_ReceiveData(USART1);//��ȡ���ܵ�������				
            ReceiveData[RS232_RX_CNT++]=res;//����ֵд�뻺������					 
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

        
/*��ս��ܻ������鲢���½���*/
void ClearBuf()
{
    /*��ս�������*/
    ReceiveData[0]=0;
    ReceiveData[1]=0;
    ReceiveData[2]=0;
    ReceiveData[3]=0;
    ReceiveData[4]=0;
    ReceiveData[5]=0;
    ReceiveData[6]=0;
    ReceiveData[7]=0;
    /*�����������*/
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
/*RS232��ʼ������*/
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

    USART_InitStructure.USART_BaudRate=bound;//������
    USART_InitStructure.USART_WordLength=USART_WordLength_8b;//���ݳ��Ȱ�λ
    USART_InitStructure.USART_StopBits=USART_StopBits_1;//һ��ֹͣλ
    USART_InitStructure.USART_Parity=USART_Parity_No;//����żУ��
    USART_InitStructure.USART_HardwareFlowControl=USART_HardwareFlowControl_None;//��Ӳ��������
    USART_InitStructure.USART_Mode=USART_Mode_Rx|USART_Mode_Tx;//����fa�ͺͽ��ܹ���
 

    NVIC_InitStructure.NVIC_IRQChannel=USART1_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority=1;
    NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
    NVIC_Init(&NVIC_InitStructure);

    USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);//��������ж�
		USART_Init(USART1,&USART_InitStructure);
		USART_ITConfig(USART1, USART_IT_IDLE, ENABLE);  
    USART_Cmd(USART1,ENABLE);//��������
}
/*
RS232���ͺ���
buf:���������׵�ַ
len:�������ݳ���
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
RS232��ѯ�������ݺ���
buf:���ܻ�������
len:�������ݳ���
*/
void RS232_Receive_Data(u8 *buf,u8 *len)
{
    u8 rxlen=RS232_RX_CNT;
    u8 i=0;
    *len=0;//���ý������ݳ���Ϊ0
    /*�ȴ�10���룬����10����RS2323_RX_CNT����û�з����ı䣬����Ϊû�н����ٽ��յ�һ�����ݣ����ܽ���*/
    delay_ms(10);
    /*���ܵ������ҽ������*/
    if(rxlen==RS232_RX_CNT&&rxlen)
        {

            for(i=0; i<8; i++)
                {
                    buf[i]=RS232_RX_BUF[i];
                }
            *len=RS232_RX_CNT;/*��¼ԭ��������*/
            RS232_RX_CNT=0;/*�½��ܵ����ݷ��Ǿ�����*/
        }

}
/*��ѯ*/
void RS232ReceiveData(u8 *buf)
{
    u8 rxlen=RS232_RX_CNT;
    /*�ȴ�10���룬����10����RS2323_RX_CNT����û�з����ı䣬����Ϊû�н����ٽ��յ�һ�����ݣ����ܽ���*/
    /*���ܵ������ҽ������*/
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
            RS232_RX_CNT=0;/*�½��ܵ����ݷ��Ǿ�����*/
        }
    //delay_us(10);
}

