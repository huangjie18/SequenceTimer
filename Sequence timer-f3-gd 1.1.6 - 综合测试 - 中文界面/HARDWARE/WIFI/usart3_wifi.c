#include "usart3_wifi.h"
#include "delay.h"
#include "data.h"
#include "lcd.h"

//���ܻ�������,���64���ֽ�
extern u8 RS232_RX_BUF[8];
//���ܵ����ݳ���
extern u8 RS232_RX_CNT;

extern u8 ReceiveData[8];
/*�жϽ�������*/
extern u8 temp[8];
extern u8 ReceiveState;
void USART3_IRQHandler(void)
{
     u8 res;
	  u8 clear;
    if(USART_GetITStatus(USART3,USART_IT_RXNE)!=RESET)   //���ܵ�����
        {
            res=USART_ReceiveData(USART3);//��ȡ���ܵ�������				
            ReceiveData[RS232_RX_CNT++]=res;//����ֵд�뻺������					 
			}else if(USART_GetITStatus(USART3,USART_IT_IDLE)!=RESET){
			clear=USART1->SR;
			clear=USART1->DR;	
			ReceiveState=1;
							
			}		
}
/*usart3��ʼ��*/
void usart3_Init(u32 bound)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    USART_InitTypeDef USART_InitStructure;
    NVIC_InitTypeDef NVIC_InitStructure;
	
    //����ʱ��
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);
	
    GPIO_InitStructure.GPIO_Pin=GPIO_Pin_10;//TX
    GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
    GPIO_Init(GPIOB,&GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin=GPIO_Pin_11;//RX
    GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOB,&GPIO_InitStructure);

    USART_InitStructure.USART_BaudRate=bound;//������
    USART_InitStructure.USART_WordLength=USART_WordLength_8b;//���ݳ��Ȱ�λ
    USART_InitStructure.USART_StopBits=USART_StopBits_1;//һ��ֹͣλ
    USART_InitStructure.USART_Parity=USART_Parity_No;//����żУ��
    USART_InitStructure.USART_HardwareFlowControl=USART_HardwareFlowControl_None;//��Ӳ��������
    USART_InitStructure.USART_Mode=USART_Mode_Rx|USART_Mode_Tx;//����fa�ͺͽ��ܹ���



    NVIC_InitStructure.NVIC_IRQChannel=USART3_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority=1;
    NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
    NVIC_Init(&NVIC_InitStructure);
		
    USART_Init(USART3,&USART_InitStructure);				
    USART_ITConfig(USART3,USART_IT_RXNE,ENABLE);//��������ж�
		USART_ITConfig(USART3, USART_IT_IDLE, ENABLE);  
    USART_Cmd(USART3,ENABLE);//��������
}

/*
RS232���ͺ���
buf:���������׵�ַ
len:�������ݳ���
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
RS232��ѯ�������ݺ���
buf:���ܻ�������
len:�������ݳ���
*/
void usart3_Receive_Data(u8 *buf,u8 *len)
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

