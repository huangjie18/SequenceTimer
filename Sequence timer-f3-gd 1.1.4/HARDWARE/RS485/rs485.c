#include "rs485.h"
#include "delay.h"
#include "main_setting_page.h"
#include "key.h"
//���ܻ�������,���64���ֽ�
u8 RS485_RX_BUF[64];
//���ܵ����ݳ���
u8 RS485_RX_CNT;

void USART2_IRQHandler(void)
{
    u8 res;

    if(USART_GetITStatus(USART2,USART_IT_RXNE)!=RESET)   //���ܵ�����
        {
            res=USART_ReceiveData(USART2);//��ȡ���ܵ�������
            if(RS485_RX_CNT<64)
                {
                    RS485_RX_BUF[RS485_RX_CNT]=res;//����ֵд�뻺����
                    RS485_RX_CNT++;
                }


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

/*RS485:��ѯ���յ������ݺ���
 *buf:���ܻ����׵�ַ
 *len:���������ݳ���
*/
void RS485_Read_Data(u8 *buf,u8 *len)
{
    u8  rxlen=RS485_RX_CNT;
    u8 i;
    *len=0; //Ĭ��Ϊ0
    delay_ms(10);//�ȴ�10ms,��������10msû�н�����һ�����ݣ�����Ϊ���ս���
    if(rxlen==RS485_RX_CNT&&rxlen)   //�������ݣ��ҽ������
        {
            for(i=0; i<rxlen; i++)
                {
                    buf[i]=RS485_RX_BUF[i];

                }

            *len=RS485_RX_CNT;//��¼�������ݳ���
            RS485_RX_CNT=0;//����

        }
}
enum ChanNum {CH1=1,CH2,CH3,CH4,CH5,CH6,CH7,CH8,CH9};
void ArithmaticInUSART(u8 *buf)
{
    
    switch(buf[6])
        {
        case CH1:
					
            if(buf[5])
                {
                GPIO_SetBits(GPIOC,GPIO_Pin_0);
                }
            else
							{
						   GPIO_ResetBits(GPIOC,GPIO_Pin_0);
						  }
							
            break;
						
        case CH2:
            
            if(buf[5])
                {
                GPIO_SetBits(GPIOC,GPIO_Pin_1);
                }
            else
							{
						   GPIO_ResetBits(GPIOC,GPIO_Pin_1);
						  }
							
            break;
        case CH3:
            
            if(buf[5])
                {
                GPIO_SetBits(GPIOC,GPIO_Pin_2);
                }
            else
							{
						   GPIO_ResetBits(GPIOC,GPIO_Pin_2);
						  }							
            break;
        case CH4:
            
            if(buf[5])
                {
                GPIO_SetBits(GPIOC,GPIO_Pin_3);
                }
            else
							{
						   GPIO_ResetBits(GPIOC,GPIO_Pin_3);
						  }
							
            break;
        case CH5:
            
            if(buf[5])
                {
                GPIO_SetBits(GPIOC,GPIO_Pin_4);
                }
            else
							{
						   GPIO_ResetBits(GPIOC,GPIO_Pin_4);
						  }
							
            break;
        case CH6:
            
            if(buf[5])
                {
                GPIO_SetBits(GPIOC,GPIO_Pin_5);
                }
            else
							{
						   GPIO_ResetBits(GPIOC,GPIO_Pin_5);
						  }
							
            break;
        case CH7:
            
            if(buf[5])
                {
                GPIO_SetBits(GPIOC,GPIO_Pin_6);
                }
            else
							{
						   GPIO_ResetBits(GPIOC,GPIO_Pin_6);
						  }
							
            break;
        case CH8:
            
            if(buf[5])
                {
                GPIO_SetBits(GPIOC,GPIO_Pin_7);
                }
            else
							{
						   GPIO_ResetBits(GPIOC,GPIO_Pin_7);
						  }
							
            break;
        case CH9:
            if(buf[5])
                {
                   relay_key_dev.relay_key_state=RE_KEY_DOWN;
                }
            else
							{
								relay_key_dev.relay_key_state=RE_KEY_UP;
										
						  }
            break;
        }


              Channel_State_Show_();


}

