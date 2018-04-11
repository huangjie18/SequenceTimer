#include "rs485.h"
#include "delay.h"
#include "main_setting_page.h"
#include "key.h"
//���ܻ�������,���64���ֽ�
extern u8 RS232_RX_BUF[8];
//���ܵ����ݳ���
extern u8 RS232_RX_CNT;

extern u8 ReceiveData[8];
/*�жϽ�������*/
extern u8 temp[8];
extern u8 ReceiveState;
void USART2_IRQHandler(void)
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
    GPIO_ResetBits(GPIOA,GPIO_Pin_4);//ֻ���ܣ�������

    USART_InitStructure.USART_BaudRate = bound;//Configurate the bound
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;//8λ���ݳ���
    USART_InitStructure.USART_StopBits = USART_StopBits_1;//һ��ֹͣλ
    USART_InitStructure.USART_Parity = USART_Parity_No;//��żУ��λ
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//��Ӳ������������
    USART_InitStructure.USART_Mode = USART_Mode_Rx;//����ģʽ

    NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn; //ʹ�ܴ���2�ж�
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2; //��ռ���ȼ�2��
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2; //�����ȼ�2��
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //ʹ���ⲿ�ж�ͨ��
    NVIC_Init(&NVIC_InitStructure); //����NVIC_InitStruct��ָ���Ĳ�����ʼ������NVIC�Ĵ���

    USART_Init(USART2, &USART_InitStructure) ; //��ʼ������
    USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);//���������ж�
    USART_Cmd(USART2, ENABLE);//ʹ�ܴ���


}
