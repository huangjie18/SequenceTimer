#include "stm32f10x.h"
#include "delay.h"
#include "lcd.h"
#include "gui.h"
#include "page.h"
#include "main_setting_page.h"
#include "main_page.h"
#include "action.h"
#include "rtc.h"
#include "key.h"
#include  "flag.h"
#include  "timer.h"
#include "touch.h"
#include "action.h"
#include "key_board.h"
#include <stdio.h>
#include "adc.h"
#include "pwm.h"
#include "rs485.h"
#include "data.h"
#include "auz_page.h"
#include "rs232.h"
#include "usart3_wifi.h"

extern _lcd_dev lcddev;
extern _flag_dev flag_dev;
extern u32 ADCVAL;
extern u32 SECCOUNT;/*��ǰ��������*/

u8 _STA;//��¼ͨ����ʱ����ִ��״̬
u8 static flag_;
u32 adcx;
u32 adcy;
static u8 P_CNT;
u8 M_str=0;//0��Enable����ҳ�� 1��Disnable����ҳ��
u8 LAST_STA;//��¼��һ�ΰ���״̬


void  DelayOpenMachine() /*��ʱ��������*/
{
    if(M_str==0)/*��ʱ����*/
        {
            LCD_Show_picture(50,90,0xFBE4,3);/*����logo*/
            if(P_CNT<100)
                {
                    P_CNT++;
                }
            else
                {
                    M_str=1;
                    if(flag_==0)
                        {
                            LCD_Clear(BLACK);
                            main_page_activity();
                            flag_dev.activity_flag=HOME;
                            flag_dev.action_flag=HOME;
                            flag_dev.screen_flag=HOME;//��֧�ֳ���
                            flag_dev.anchor=0;
                            flag_=1;
                            flag_dev.page_num=1;
                        }
                    flag_dev.OPEN_PAGE_STR=1;
                }
            GetValOfAdc(ADC_Channel_0,&ADCVAL);
        }
}



void Executing_In_MainWhile()
{
    DelayOpenMachine();

    /*------------------------����ִ�к���---------------------------------------*/
    if(M_str==1)
        {


            /*�ɼ�ADC��ʾ��ѹ*/
            GetValOfAdc(ADC_Channel_0,&ADCVAL);
            /*��ѹǷѹ��������*/
            UVOVProtection(&ADCVAL);
            /*���Ӻ���*/
            TimerAction(SECCOUNT);
            /*�������������½������*/
            encoder();
            main_page_encoder_action();
            screen_action();
            relay_key();
            encoder_key();
            EncoderToAll();
            /*�ж��Ƿ���Ҫ�ȴ�һ������ʱ*/
            IsWaitOneSecDelay();
        }
    ArithmaticOfCommunication();
    KeyChangeFrequence();

}


void InitAll()/*ϵͳ��ʼ��*/
{

    delay_init();
    flag_dev.lock_sta=L_OPEN;/*Ĭ����Ļ����*/
    LCD_IO_FSMC_Init();
    LCD_Init();
    gui_init();
    key_init();
    RTC_Init();
    SECCOUNT=RTC_GetCounter();/*��ȡ��ǰ���������������Ӷ�ʱʱ��Ա�*/
    Adc_Init();
    tp_dev.init();
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//�����ж����ȼ�����Ϊ��2��2λ��ռ���ȼ���2λ��Ӧ���ȼ�
    GPIO_SetBits(GPIOD,GPIO_Pin_13);/*����LCD��Ļ����*/
    GPIO_SetBits(GPIOC,GPIO_Pin_13);/*�������������*/
    LCD_Clear(BLACK);/*���ú�ɫ��Ļ*/

    delay_ms(1000);

    TIM2_Init();/*TIM2������ʱ����ͨ��*/
    Pwm_Init();/*TIM4��׽PWM����*/
    Pwm_Input_Init();/*TIM4��׽PWM����*/

    TIM5_Init();/*TIM5������̨��������Ƿ��дӴӻ�UPPER�˵ĵ͵�ƽ��ʱ*/


    RS232_Init(9600);/*RS232-USART2��ʼ��*/
    RS485_Init(9600);/*RS485-USART2��ʼ��*/
    usart3_Init(9600);/*wifi-USART3��ʼ��*/

    ReadAndSave(ISWRITEALL,0);/*�״ο�����24C20ˢдĬ������,��ִ��һ��*/
    ReadAndSave(ISMAIN,0);/*������ȡ24C20����*/

    Authorization();/*����Ƿ�ע������ʹ������*/

}
int main(void)
{

    InitAll();
    while(1)
        {
            Executing_In_MainWhile();
        }
}

