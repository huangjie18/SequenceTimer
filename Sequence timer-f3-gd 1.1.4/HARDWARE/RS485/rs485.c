#include "rs485.h"
#include "delay.h"

#ifdef EN_USART2_RX  //�������ʹ��

//���ܻ�������,���64���ֽ�
u8 RS485_RX_BUF[64];
//���ܵ����ݳ���
u8 RS485_RX_CNT;

/*USART2���жϺ���*/


void USART2_IRQHandler(void)

{
    u8 res;

    if(USART_GetITStatus(USART2,USART_IT_RXNE)!=RESET)//���ܵ�����
        {
            res=USART_ReceiveData(USART2);//��ȡ���ܵ�������
            if(RS485_RX_CNT<64)
                {
                    RS485_RX_BUF[RS485_RX_CNT]=res;//����ֵд�뻺����
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
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;//8λ���ݳ���
	USART_InitStructure.USART_StopBits = USART_StopBits_1;//һ��ֹͣλ
	USART_InitStructure.USART_Parity = USART_Parity_No;///��żУ��λ
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//��Ӳ������������
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;//�շ�ģʽ

  USART_Init(USART2, &USART_InitStructure); ; //��ʼ������
  
	NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn; //ʹ�ܴ���2�ж�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2; //��ռ���ȼ�2��
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2; //�����ȼ�2��
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //ʹ���ⲿ�ж�ͨ��
	NVIC_Init(&NVIC_InitStructure); //����NVIC_InitStruct��ָ���Ĳ�����ʼ������NVIC�Ĵ���
 
  USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);//���������ж�
//  USART_ITConfig(USART2,USART_IT_TXE,ENABLE); //���������ж�
	 
  USART_Cmd(USART2, ENABLE);                    //ʹ�ܴ��� 

 #endif 
 
 RS485_TX_EN=0;			//Ĭ��Ϊ����ģʽ
 
}

/*RES485:�������ݺ���
 *buf:���������׵�ַ
 *len:�������ݵ��ֽ�������Ҫ����64���ֽڣ�
 */
void RS485_Send_Data(u8 *buf,u8 len)
{
   u8 t;
	 RS485_TX_EN=1;//����Ϊ����ģʽ
   for(t=0;t<len;t++){
	 while(USART_GetFlagStatus(USART2,USART_FLAG_TC)==RESET)
	 USART_SendData(USART2,buf[t]);
	 } 
  	while(USART_GetFlagStatus(USART2,USART_FLAG_TC)==RESET);
	  RS485_RX_CNT=0;
    RS485_TX_EN=0;//����Ϊ����ģʽ
	 
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
	if(rxlen==RS485_RX_CNT&&rxlen){//�������ݣ��ҽ������
	 for(i=0;i<rxlen;i++){
	  buf[i]=RS485_RX_BUF[i];
	
	 }
	 
	*len=RS485_RX_CNT;//��¼�������ݳ���
	 RS485_RX_CNT=0;//����
	
	}
}



