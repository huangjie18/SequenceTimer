#include "timer.h"
#include "page.h"
#include "delay.h"
#include "data.h"
#include "lcd.h"
#include  "key.h"
#include "flag.h"
#include "gui.h"
#include "adc.h"
#include "main_setting_page.h"
#include "rs232.h"
#include "pwm.h"
#include "usart3_wifi.h"

//ͨ�ö�ʱ��3�жϳ�ʼ��
//����ʱ��ѡ��ΪAPB1��2������APB1Ϊ36M
//arr���Զ���װֵ��
//psc��ʱ��Ԥ��Ƶ��
//����ʹ�õ��Ƕ�ʱ��3!



int gpio_pin[8]= {GPIO_Pin_0,GPIO_Pin_1,GPIO_Pin_2,GPIO_Pin_3,GPIO_Pin_4,GPIO_Pin_5,GPIO_Pin_6,GPIO_Pin_7};
extern _flag_dev flag_dev;
extern _chan_open_data chan_open_data;//ͨ������ʱ����
extern _chan_close_data chan_close_data;//ͨ������ʱ����
extern _relay_key_dev relay_key_dev;
extern u8 LINK_FLAG;
extern u8 DELAY_STA;
extern u32 ADCVAL;
extern u8 ISALARM;//�ز������Ƿ�����ֵ
u8 ex_open_flag=0;//1��ʾ������ɱ�־λ
u8 ex_close_flag=0;//1��ʾ�ػ���ɱ�ʾλ

void TIM2_Init()
{
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
    NVIC_InitTypeDef NVIC_InitStructure;

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);

    TIM_TimeBaseStructure.TIM_Period = 999; //��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ
    TIM_TimeBaseStructure.TIM_Prescaler =7199; //����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ
    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //����ʱ�ӷָ�:TDTS = Tck_tim
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
    TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure); //����ָ���Ĳ�����ʼ��TIMx��ʱ�������λ

    TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE ); //��������ж�

    NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQͨ����ʹ��
    NVIC_Init(&NVIC_InitStructure);

    TIM_Cmd(TIM2, ENABLE);
}
u8 PIN_STA;//���GPIO_Pin_7״̬
u8 CHAN_O_C(u16 sec_cnt)
{

    u16 chan_1,chan_2,chan_3,chan_4,chan_5,chan_6,chan_7,chan_8;
    if(LINK_FLAG==0)
        {
            if(relay_key_dev.relay_key_state==RE_KEY_DOWN)
                {

                    chan_1=(chan_open_data.chan1)*1000;
                    chan_2=(chan_open_data.chan2)*1000;
                    chan_3=(chan_open_data.chan3)*1000;
                    chan_4=(chan_open_data.chan4)*1000;
                    chan_5=(chan_open_data.chan5)*1000;
                    chan_6=(chan_open_data.chan6)*1000;
                    chan_7=(chan_open_data.chan7)*1000;
                    chan_8=(chan_open_data.chan8)*1000;

                }
            else if(relay_key_dev.relay_key_state==RE_KEY_UP)
                {

                    chan_1=(chan_close_data.chan1)*1000;
                    chan_2=(chan_close_data.chan2)*1000;
                    chan_3=(chan_close_data.chan3)*1000;
                    chan_4=(chan_close_data.chan4)*1000;
                    chan_5=(chan_close_data.chan5)*1000;
                    chan_6=(chan_close_data.chan6)*1000;
                    chan_7=(chan_close_data.chan7)*1000;
                    chan_8=(chan_close_data.chan8)*1000;

                }
        }

    if(LINK_FLAG==1)
        {


            if(relay_key_dev.relay_key_state==RE_KEY_DOWN)
                {

                    chan_1=1000;
                    chan_2=2000;
                    chan_3=3000;
                    chan_4=4000;
                    chan_5=5000;
                    chan_6=6000;
                    chan_7=7000;
                    chan_8=8000;

                }
            else if(relay_key_dev.relay_key_state==RE_KEY_UP)
                {

                    chan_1=8000;
                    chan_2=7000;
                    chan_3=6000;
                    chan_4=5000;
                    chan_5=4000;
                    chan_6=3000;
                    chan_7=2000;
                    chan_8=1000;


                }
        }

    if(sec_cnt==chan_1)
        {

            if(EnCH1)
                {

                    if(relay_key_dev.relay_key_state==RE_KEY_DOWN)
                        {

                           SetCH1
                            if(flag_dev.action_flag==HOME)
                                LCD_Show_4848_String(109,104,"1",RED);

                        }
                    else if(relay_key_dev.relay_key_state==RE_KEY_UP)
                        {

                            ResetCH1
                            if(flag_dev.action_flag==HOME)
                                LCD_Show_4848_String(109,104,"1",WHITE);
														 PIN_STA=0;
                              DELAY_STA=0;//ȡ����ʱһ��ı��

                        }

                }
        }
    if(sec_cnt==chan_2)
        {
            if(EnCH2)
                {

                    if(relay_key_dev.relay_key_state==RE_KEY_DOWN)
                        {
                            SetCH2
                            if(flag_dev.action_flag==HOME)
                                LCD_Show_4848_String(167,104,"2",RED);
                        }
                    else if(relay_key_dev.relay_key_state==RE_KEY_UP)
                        {

                            ResetCH2
                            if(flag_dev.action_flag==HOME)
                                LCD_Show_4848_String(167,104,"2",WHITE);
														 PIN_STA=0;
                              DELAY_STA=0;//ȡ����ʱһ��ı��
                        }

                }
        }
    if(sec_cnt==chan_3)
        {
            if(EnCH3)
                {

                    if(relay_key_dev.relay_key_state==RE_KEY_DOWN)
                        {

                            SetCH3
                            if(flag_dev.action_flag==HOME)
                                LCD_Show_4848_String(223,104,"3",RED);

                        }
                    else if(relay_key_dev.relay_key_state==RE_KEY_UP)
                        {

                            ResetCH3
                            if(flag_dev.action_flag==HOME)
                                LCD_Show_4848_String(223,104,"3",WHITE);
														 PIN_STA=0;
                              DELAY_STA=0;//ȡ����ʱһ��ı��
                        }

                }
        }
    if(sec_cnt==chan_4)
        {
            if(EnCH4)
                {
                    if(relay_key_dev.relay_key_state==RE_KEY_DOWN)
                        {

                           SetCH4
                            if(flag_dev.action_flag==HOME)
                                LCD_Show_4848_String(279,104,"4",RED);
                        }
                    else if(relay_key_dev.relay_key_state==RE_KEY_UP)
                        {

                            ResetCH4
                            if(flag_dev.action_flag==HOME)
                                LCD_Show_4848_String(279,104,"4",WHITE);
														 PIN_STA=0;
                              DELAY_STA=0;//ȡ����ʱһ��ı��
                        }
                }


        }
    if(sec_cnt==chan_5)
        {
            if(EnCH5)
                {
                    if(relay_key_dev.relay_key_state==RE_KEY_DOWN)
                        {

                           SetCH5
                            if(flag_dev.action_flag==HOME)
                                LCD_Show_4848_String(109,156,"5",RED);

                        }
                    else if(relay_key_dev.relay_key_state==RE_KEY_UP)
                        {

                            ResetCH5
                            if(flag_dev.action_flag==HOME)
                                LCD_Show_4848_String(109,156,"5",WHITE);
														 PIN_STA=0;
                              DELAY_STA=0;//ȡ����ʱһ��ı��
                        }

                }

        }
    if(sec_cnt==chan_6)
        {

            if(EnCH6)
                {
                    if(relay_key_dev.relay_key_state==RE_KEY_DOWN)
                        {

                            SetCH6
                            if(flag_dev.action_flag==HOME)
                                LCD_Show_4848_String(167,156,"6",RED);

                        }
                    else if(relay_key_dev.relay_key_state==RE_KEY_UP)
                        {

                            ResetCH6
                            if(flag_dev.action_flag==HOME)
                                LCD_Show_4848_String(167,156,"6",WHITE);
														 PIN_STA=0;
                              DELAY_STA=0;//ȡ����ʱһ��ı��
                        }
                }

        }
    if(sec_cnt==chan_7)
        {

            if(EnCH7)
                {
                    if(relay_key_dev.relay_key_state==RE_KEY_DOWN)
                        {

                            SetCH7
                            if(flag_dev.action_flag==HOME)
                                LCD_Show_4848_String(223,156,"7",RED);

                        }
                    else if(relay_key_dev.relay_key_state==RE_KEY_UP)
                        {

                           ResetCH7
                            if(flag_dev.action_flag==HOME)
                                LCD_Show_4848_String(223,156,"7",WHITE);
														 PIN_STA=0;
                              DELAY_STA=0;//ȡ����ʱһ��ı��
                        }

                }
        }
    if(sec_cnt==chan_8)
        {
           
               if(EnCH8){
                    if(relay_key_dev.relay_key_state==RE_KEY_DOWN)
                        {
                             
                
                           SetCH8
                            if(flag_dev.action_flag==HOME)
                            LCD_Show_4848_String(279,156,"8",RED);
                            PIN_STA=1;

                        }
                    else if(relay_key_dev.relay_key_state==RE_KEY_UP)
                        {
                 
                            ResetCH8
                            if(flag_dev.action_flag==HOME)
                            LCD_Show_4848_String(279,156,"8",WHITE);
                               PIN_STA=0;
                              DELAY_STA=0;//ȡ����ʱһ��ı��
                        }
											}

        }
				
           if(EnCH8){
						if(ReadCH8)	
            PIN_STA=1;
						}
						else if(EnCH7){
						if(ReadCH7)	
            PIN_STA=1;
						}
						else if(EnCH6){
						if(ReadCH6)	
            PIN_STA=1;
						}
						else if(EnCH5){
						if(ReadCH5)	
            PIN_STA=1;
						}
						else if(EnCH4){
						if(ReadCH4)	
            PIN_STA=1;
						}
						else if(EnCH3){
						if(ReadCH3)	
            PIN_STA=1;
						}
						else if(EnCH2){
						if(ReadCH2)	
            PIN_STA=1;
						}
						else if(EnCH1){
						if(ReadCH1)	
            PIN_STA=1;
						}



    if(sec_cnt==8000&&relay_key_dev.relay_key_state==RE_KEY_DOWN)
        {
            return 1;
            
        }
    else if(sec_cnt==8000&&relay_key_dev.relay_key_state==RE_KEY_UP)
        {
            return 0;
          
        }
    else
        {
            return 2;
        }
}

u8 A=5;
u8 IS_EX_CLOSE=0;//����Ƿ����ִ��CHANNEL�رպ���
void TIM2_IRQHandler(void)   //TIM3�ж�
{

    u16 static SEC_CNT_O;
    u16 static SEC_CNT_C;

    if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET)  //���TIM3�����жϷ������
        {
					

            IsShowAUZPage();
            IsProtect();
            if(LINK_FLAG==0)
                {
                    if(relay_key_dev.relay_key_state==RE_KEY_DOWN)
                        {

                            if(ISREDLAYFLAGCHANGE==1)
                                {
                                    SEC_CNT_O=0;
                                    A=3;
                                    ISREDLAYFLAGCHANGE=0;
                                }
                            if(A!=1)
                                {
                                    SEC_CNT_O+=100;
                                    A=CHAN_O_C(SEC_CNT_O);
                                    SEC_CNT_C=0;
                                }
                        }
                    if(relay_key_dev.relay_key_state==RE_KEY_UP)
                        {

                            if(ISREDLAYFLAGCHANGE==1)
                                {
                                    SEC_CNT_C=0;
                                    A=3;
                                    ISREDLAYFLAGCHANGE=0;
                                }

                            if(A!=0)
                                {
                                    SEC_CNT_C+=100;
                                    A=CHAN_O_C(SEC_CNT_C);
                                    SEC_CNT_O=0;
                                }

                        }
                }
            else if(LINK_FLAG==1)
                {

                    if(relay_key_dev.relay_key_state==RE_KEY_DOWN)
                        {

                            if(A!=1)
                                {
                                    SEC_CNT_O+=100;
                                    A=CHAN_O_C(SEC_CNT_O);
                                    SEC_CNT_C=8000-SEC_CNT_O;
                                }
                            IsWaitOneSecDelay();
                        }
                    if(relay_key_dev.relay_key_state==RE_KEY_UP)
                        {
                            if(IS_EX_CLOSE==0)
                                {
                                    if(A!=0)
                                        {
                                            SEC_CNT_C+=100;
                                            A=CHAN_O_C(SEC_CNT_C);
                                            SEC_CNT_O=8000-SEC_CNT_C;
                                            Delay_One_Sec();
                                        }
                                }

                        }
                }


            TIM_ClearITPendingBit(TIM2, TIM_IT_Update); 		//���TIMx�����жϱ�־
        }

}








