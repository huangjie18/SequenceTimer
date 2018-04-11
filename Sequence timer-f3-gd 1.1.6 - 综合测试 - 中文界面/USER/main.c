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
extern u32 SECCOUNT;/*当前日期秒数*/

u8 _STA;//记录通道延时函数执行状态
u8 static flag_;
u32 adcx;
u32 adcy;
static u8 P_CNT;
u8 M_str=0;//0：Enable开机页面 1：Disnable开机页面
u8 LAST_STA;//记录上一次按键状态


void  DelayOpenMachine() /*延时开机函数*/
{
    if(M_str==0)/*延时开机*/
        {
            LCD_Show_picture(50,90,0xFBE4,3);/*开机logo*/
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
                            flag_dev.screen_flag=HOME;//不支持长按
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

    /*------------------------核心执行函数---------------------------------------*/
    if(M_str==1)
        {


            /*采集ADC显示电压*/
            GetValOfAdc(ADC_Channel_0,&ADCVAL);
            /*过压欠压保护函数*/
            UVOVProtection(&ADCVAL);
            /*闹钟函数*/
            TimerAction(SECCOUNT);
            /*按键编码器更新界面操作*/
            encoder();
            main_page_encoder_action();
            screen_action();
            relay_key();
            encoder_key();
            EncoderToAll();
            /*判断是否需要等待一毫秒延时*/
            IsWaitOneSecDelay();
        }
    ArithmaticOfCommunication();
    KeyChangeFrequence();

}


void InitAll()/*系统初始化*/
{

    delay_init();
    flag_dev.lock_sta=L_OPEN;/*默认屏幕开锁*/
    LCD_IO_FSMC_Init();
    LCD_Init();
    gui_init();
    key_init();
    RTC_Init();
    SECCOUNT=RTC_GetCounter();/*获取当前日期秒数用于闹钟定时时间对比*/
    Adc_Init();
    tp_dev.init();
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置中断优先级分组为组2：2位抢占优先级，2位响应优先级
    GPIO_SetBits(GPIOD,GPIO_Pin_13);/*点亮LCD屏幕背光*/
    GPIO_SetBits(GPIOC,GPIO_Pin_13);/*点亮发光二极管*/
    LCD_Clear(BLACK);/*设置黑色屏幕*/

    delay_ms(1000);

    TIM2_Init();/*TIM2用于延时开关通道*/
    Pwm_Init();/*TIM4捕捉PWM波形*/
    Pwm_Input_Init();/*TIM4捕捉PWM波形*/

    TIM5_Init();/*TIM5用作多台级联检查是否有从从机UPPER端的低电平延时*/


    RS232_Init(9600);/*RS232-USART2初始化*/
    RS485_Init(9600);/*RS485-USART2初始化*/
    usart3_Init(9600);/*wifi-USART3初始化*/

    ReadAndSave(ISWRITEALL,0);/*首次开机向24C20刷写默认数据,仅执行一次*/
    ReadAndSave(ISMAIN,0);/*开机读取24C20数据*/

    Authorization();/*检测是否注册和免费使用天数*/

}
int main(void)
{

    InitAll();
    while(1)
        {
            Executing_In_MainWhile();
        }
}

