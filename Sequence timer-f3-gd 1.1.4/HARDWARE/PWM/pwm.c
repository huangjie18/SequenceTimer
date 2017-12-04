#include "main_setting_page.h"
#include "pwm.h"
#include "sys.h"
#include "delay.h"
#include "lcd.h"
#include "flag.h"
#include "gui.h"
#include "key.h"

/*
ʹ������Ϊ10K��0.1���������72000000/��7199+1��=10K���Զ�װ��ֵΪ400��PWMƵ��Ϊ25HZ
ʹ������Ϊ10K��0.1���������72000000/��7199+1��=10K���Զ�װ��ֵΪ600��PWMƵ��Ϊ16HZ
ʹ������Ϊ10K��0.1���������72000000/��7199+1��=10K���Զ�װ��ֵΪ200��PWMƵ��Ϊ50HZ
*/

/*
1��������ʱ�������ȼ�����
2��TIM5���ڼ���Ƿ��м�����CHANNELȫ���ر�ʱ�ĵ͵�ƽ��ʱ
*/
extern _flag_dev flag_dev;

u16 SEC_CNT=0;
u16 LINK_CNT;//��������Ƿ��м���ʱ��
u8 LINK_FLAG;//����Ƿ��м���
u8 CHAN_STATUS=1;//����Ƿ�CHANȫ���򿪻���ȫ���ر�
u8 LAST_KEY_STATUS=0;//���水��״̬
u8 FEQUENCE_FLAG;//��ǽ��յ���Ƶ��
u8 DELAY_STA;//�Ƿ��⵽��ʱ��־λ
u8 TIM3CH1_CAPTURE_STA=0;//����״̬
u32 TIM3CH1_CAPTURE_VAL;//���벶��ֵ
/*
��ʱ��TIM1�ĳ�ʼ������
*/
void Pwm_Init()
{
	
    GPIO_InitTypeDef  GPIO_InitStructure;
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3|RCC_APB1Periph_TIM2,ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO, ENABLE);//ʹ�ܸ��ù���ʱ�ӡ�TIM1

   
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;		//NEXT��
    GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_OD;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;		//UPPER��
    GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
  

}
void Set_Frequence(u16 arr){

					 TIM_SetAutoreload(TIM2,arr);
				   TIM_SetCompare4(TIM2,arr/2);

}

void Delay_One_Sec(){
   
	   GPIO_InitTypeDef  GPIO_InitStructure;
	
    if(FEQUENCE_FLAG==25){
			
		  if( relay_key_dev.relay_key_state==RE_KEY_UP){

			  if(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_0)==0){
					
				 	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;		//UPPER��
            GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPD;
            GPIO_Init(GPIOA, &GPIO_InitStructure);		
			      delay_ms(200);
					
				    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;		//UPPER��
            GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
            GPIO_Init(GPIOA, &GPIO_InitStructure); 		
					
				    FEQUENCE_FLAG=0;
				}		
			}			
		}



}
void Pwm_Output_Init()
{

    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
    TIM_OCInitTypeDef TIM_OCInitStructure;
	
    TIM_TimeBaseStructure.TIM_Period=0xFFFF;
    TIM_TimeBaseStructure.TIM_Prescaler=7199;
    TIM_TimeBaseStructure.TIM_ClockDivision=0;//���ö�ʱ��ʱ��(CK_INT)Ƶ���������˲���(ETR��TIx)ʹ�õĲ���Ƶ��֮��ķ�Ƶ�����ģ������벶����أ��� 0��ʾ�˲�����Ƶ�ʺͶ�ʱ����Ƶ����һ���ġ�
    TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;
    TIM_TimeBaseInit(TIM2,&TIM_TimeBaseStructure);

    TIM_OCInitStructure.TIM_OCMode=TIM_OCMode_PWM2;
    TIM_OCInitStructure.TIM_OutputState=TIM_OutputState_Enable;
    TIM_OCInitStructure.TIM_Pulse =0; //���ô�װ�벶��ȽϼĴ���������ֵ
    TIM_OCInitStructure.TIM_OCPolarity=TIM_OCPolarity_High;
    TIM_OC4Init(TIM2,&TIM_OCInitStructure);  
    TIM_OC4PreloadConfig(TIM2,TIM_OCPreload_Enable);//ʹ��TIM2��CCR2�ϵ�Ԥװ�ؼĴ���
	
    TIM_ARRPreloadConfig(TIM2, ENABLE); //ʹ��TIMx��ARR�ϵ�Ԥװ�ؼĴ���
    TIM_Cmd(TIM2,ENABLE);
	   
}


void Pwm_Input_Init()
{

    GPIO_InitTypeDef GPIO_InitStructure;
    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
    NVIC_InitTypeDef NVIC_InitStructure;
    TIM_ICInitTypeDef TIM3_InitStructure;

    TIM_TimeBaseStructure.TIM_Period = 0xFFFF; //�趨�������Զ���װֵ
    TIM_TimeBaseStructure.TIM_Prescaler =72000-1; 	//Ԥ��Ƶ��
    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //����ʱ�ӷָ�:TDTS = Tck_tim
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
    TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); //����TIM_TimeBaseInitStruct��ָ���Ĳ�����ʼ��TIMx��ʱ�������λ

    TIM3_InitStructure.TIM_Channel=TIM_Channel_1;//CC1S=01  ѡ�������IC1ӳ�䵽TI1���ο�TIM��ͼ��
    TIM3_InitStructure.TIM_ICPolarity=TIM_ICPolarity_Rising;
    TIM3_InitStructure.TIM_ICSelection=TIM_ICSelection_DirectTI;//ѡ�������IC1ӳ�䵽TI1,ѡ���ӻ��������ӳ�䵽TI2��
    TIM3_InitStructure.TIM_ICPrescaler=TIM_ICPSC_DIV1;//���������Ƶ��ѡ�񼸸������ز���һ�Σ�
    TIM3_InitStructure.TIM_ICFilter=0x00;//IC1F=0000 ���������˲��� ���˲�
    TIM_ICInit(TIM3,&TIM3_InitStructure);

    NVIC_InitStructure.NVIC_IRQChannel=TIM3_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1;//��ռ���ȼ�2��
    NVIC_InitStructure.NVIC_IRQChannelSubPriority=0;//�����ȼ�
    NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;//ʹ��IRQͨ��
    NVIC_Init(&NVIC_InitStructure);//����NVIC_InitStructure��ָ���Ĳ�����ʼ������NVIC�Ĵ���

    TIM_ITConfig(TIM3,TIM_IT_Update|TIM_IT_CC1,ENABLE);//��������жϣ�����CC1TE�����ж�
    TIM_Cmd(TIM3,ENABLE);
}

void TIM3_IRQHandler(void)
{
    if((TIM3CH1_CAPTURE_STA&0x80)==0)//��û�в���
        {

            if(TIM_GetITStatus(TIM3,TIM_IT_Update)!=RESET)
                {
                    if(TIM3CH1_CAPTURE_STA&0x40)//�Ѿ����񵽸ߵ�ƽ
                        {
                            if((TIM3CH1_CAPTURE_STA&0x3F)==0x3F)//�ߵ�ƽ̫����
                                {
																	
                                    TIM3CH1_CAPTURE_STA|=0x80;//��ǳɹ�����һ��
                                    TIM3CH1_CAPTURE_VAL=0xFFFF;

                                }
                            else TIM3CH1_CAPTURE_STA++;
                        }

                }
            if(TIM_GetITStatus(TIM3,TIM_IT_CC1)!=RESET)//����1���������¼�
                {
                    if(TIM3CH1_CAPTURE_STA&0x40)//����һ���½���
                        {
                            TIM3CH1_CAPTURE_STA|=0x80;//��ǳɹ�����һ�θߵ�ƽ����
                            TIM3CH1_CAPTURE_VAL=TIM_GetCapture1(TIM3);
                            TIM_OC1PolarityConfig(TIM3,TIM_ICPolarity_Rising);//CC1P=0 ����Ϊ�����ز���
                        }
                    else   //��û��ʼ����һ�β���������
                        {
                            TIM3CH1_CAPTURE_STA=0;//���
                            TIM3CH1_CAPTURE_VAL=0;
                            TIM_SetCounter(TIM3,0);
                            TIM3CH1_CAPTURE_STA|=0x40;//��ǲ���������
                            TIM_OC1PolarityConfig(TIM3,TIM_ICPolarity_Falling); //CC1P ����Ϊ�½��ز���
                        }

                }
        }
				
								
    TIM_ClearITPendingBit(TIM3,TIM_IT_CC1|TIM_IT_Update);//����жϱ�־λ
}


void TIM5_Init()
{

    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
    NVIC_InitTypeDef NVIC_InitStructure;
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5,ENABLE);

    TIM_TimeBaseInitStructure.TIM_Period=99;
    TIM_TimeBaseInitStructure.TIM_Prescaler=7199;
    TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up;
    TIM_TimeBaseInit(TIM5,&TIM_TimeBaseInitStructure);
    TIM_ITConfig(TIM5,TIM_IT_Update,ENABLE);

    NVIC_InitStructure.NVIC_IRQChannel=TIM5_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=2;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority=0;
    NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
    NVIC_Init(&NVIC_InitStructure);

    TIM_Cmd(TIM5,ENABLE);

}


void TIM5_IRQHandler(void)
{

    if(TIM_GetITStatus(TIM5,TIM_IT_Update)!=RESET)
        {
          
//------------------------����ʶ���Ƿ��м������ӻ�CHANNEL�Ƿ�ȫ���رյ����һ��---------------

            if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_3)==1)
                {
                    LINK_FLAG=1;            //����м���              
                    if(100<LINK_CNT&&LINK_CNT<500) //��⵽��һ�����ʱ
                        {
                            DELAY_STA=1; //TODO����ʾ�ӻ��Ѿ�ȫ��CHANNEL�ر���												  												 
                        }
                   LINK_CNT=0;
                }
								
            else if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_3)==0) //����ÿ
                {

                    if(LINK_CNT>1000) //���������ӵ͵�ƽ
                        {
                            LINK_FLAG=0; //���û�м���                     
                            TIM3CH1_CAPTURE_VAL=0;//�����⵽��ֵ����KEY����������
													  LINK_CNT=0;
                        }
                    LINK_CNT+=10;
										
                }
															
//---------------------------���ݲ���Ƶ�ʸı䰴��״̬----------------------------------
              if(TIM3CH1_CAPTURE_STA&0X80) //����һ�������أ���ʾ�м���
                {									
                    if(150<TIM3CH1_CAPTURE_VAL&&TIM3CH1_CAPTURE_VAL<250)
                        {                          
                           relay_key_dev.relay_key_state=RE_KEY_DOWN;
													 FEQUENCE_FLAG=25;
													 LINK_FLAG=1;            //����м��� 
                        }
                    else if(250<TIM3CH1_CAPTURE_VAL&&TIM3CH1_CAPTURE_VAL<350)
                        {
                            relay_key_dev.relay_key_state=RE_KEY_UP;
													  LINK_FLAG=1;            //����м��� 
                            
                        }   	          		                 
                }
																							
						TIM_ClearITPendingBit(TIM5,TIM_IT_Update);//����жϱ�־λ
						
        }
}

