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

//通用定时器3中断初始化
//这里时钟选择为APB1的2倍，而APB1为36M
//arr：自动重装值。
//psc：时钟预分频数
//这里使用的是定时器3!



int gpio_pin[8]= {GPIO_Pin_0,GPIO_Pin_1,GPIO_Pin_2,GPIO_Pin_3,GPIO_Pin_4,GPIO_Pin_5,GPIO_Pin_6,GPIO_Pin_7};
extern _flag_dev flag_dev;
extern _chan_open_data chan_open_data;//通道开延时数据
extern _chan_close_data chan_close_data;//通道关延时数据
extern _relay_key_dev relay_key_dev;
extern u8 LINK_FLAG;
extern u8 DELAY_STA;
extern u32 ADCVAL;
extern u8 ISALARM;//回差条件是否正常值
u8 ex_open_flag=0;//1表示开机完成标志位
u8 ex_close_flag=0;//1表示关机完成表示位

void TIM2_Init()
{
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
    NVIC_InitTypeDef NVIC_InitStructure;

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);

    TIM_TimeBaseStructure.TIM_Period = 999; //设置在下一个更新事件装入活动的自动重装载寄存器周期的值
    TIM_TimeBaseStructure.TIM_Prescaler =7199; //设置用来作为TIMx时钟频率除数的预分频值
    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //设置时钟分割:TDTS = Tck_tim
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
    TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure); //根据指定的参数初始化TIMx的时间基数单位

    TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE ); //允许更新中断

    NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQ通道被使能
    NVIC_Init(&NVIC_InitStructure);

    TIM_Cmd(TIM2, ENABLE);
}
u8 PIN_STA;//标记GPIO_Pin_7状态
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
                              DELAY_STA=0;//取消延时一秒的标记

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
                              DELAY_STA=0;//取消延时一秒的标记
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
                              DELAY_STA=0;//取消延时一秒的标记
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
                              DELAY_STA=0;//取消延时一秒的标记
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
                              DELAY_STA=0;//取消延时一秒的标记
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
                              DELAY_STA=0;//取消延时一秒的标记
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
                              DELAY_STA=0;//取消延时一秒的标记
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
                              DELAY_STA=0;//取消延时一秒的标记
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
u8 IS_EX_CLOSE=0;//标记是否可以执行CHANNEL关闭函数
void TIM2_IRQHandler(void)   //TIM3中断
{

    u16 static SEC_CNT_O;
    u16 static SEC_CNT_C;

    if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET)  //检查TIM3更新中断发生与否
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


            TIM_ClearITPendingBit(TIM2, TIM_IT_Update); 		//清除TIMx更新中断标志
        }

}








