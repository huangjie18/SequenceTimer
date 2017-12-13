#include "stm32f10x.h"
#include "usart.h"
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
#include "usart.h"
#include "pwm.h"
#include "rs485.h"
extern _lcd_dev lcddev;
extern _flag_dev flag_dev;
extern u8 TIM3CH1_CAPTURE_STA;//输入状态
extern u16 TIM3CH1_CAPTURE_VAL;//输入捕获值

u8 _STA;//记录通道延时函数执行状态   
u8 static flag_;
u32 adcx;
u32 adcy;
static int sum;
static u8 CNT;
static u8 P_CNT;
static u8 M_str=1;//0：Enable开机页面 1：Disnable开机页面
u8 i;
u8 LAST_STA;//记录上一次按键状态


/*
计算市电电压
*/
void Calculating_Voltage(){

          
            if(flag_dev.action_flag==HOME)
            {
                adcx=2*Get_Adc_(ADC_Channel_0,60);

                adcy=(adcx)*220/3520;
                sum=sum+adcy;
                if(CNT==150){
                   sum=sum/150;
                   if(M_str==1){
                      LCD_ShowNum(162,38,sum,3,64,WHITE,BLACK);
            									 }
            									 flag_dev.lastVAL=sum;
                   sum=0;
                   CNT=0;
            								}else if(CNT==80){
            								    M_str=1;
            									  flag_dev.OPEN_PAGE_STR=1;
            								}
            					  	CNT++;
            }          
}
/*
main函数while循环执行的函数
*/
void Executing_In_MainWhile()
{
if(M_str==0)
                {
                    LCD_ShowNum(255,15,0,2,24,BLUE,BLUE);
                    LCD_ShowNum(290,15,0,2,24,BLUE,BLUE);
                    LCD_Show_2424_String(30,45,"POWER BY",WHITE);
                    for(i=0; i<6; i++)
                        {
                            LCD_ShowChar(30+44*i,60,i,88,WHITE);
                        }
                    LCD_Show_2424_String(180,210,"Version 1.0",WHITE);
                    LCD_Show_2424_String(180,185,"Init:",WHITE);
                    LCD_ShowNum(270,185,P_CNT,2,24,WHITE,BLUE);
                    LCD_Show_2424_String(300,185,"%",WHITE);
                    P_CNT+=2;
                    if(P_CNT>=99)
                        {
                            P_CNT=99;
                        }
												M_str=1;
                }

              if(TIM3CH1_CAPTURE_STA&0X80) //捕获到一次上升沿，表示有级联
                  { 
										
									 delay_ms(5);
                   TIM3CH1_CAPTURE_STA=0;//开启下一次捕获										
                }
						
            if(M_str==1)
                {
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

                    encoder();
                    main_page_encoder_action();
                    screen_action();
                    relay_key();




}
}

/*
根据按键状态选择输出频率
*/

void Test_Out(){  

				relay_key();
				
				if(relay_key_dev.relay_key_state==RE_KEY_DOWN){
					
					if(LAST_STA!=RE_KEY_DOWN){						
              LAST_STA=RE_KEY_DOWN;  	
               			
							}
					
				 if(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_7)==1){							 			   
					Set_Frequence(400);
					}    
				 
				}else if(relay_key_dev.relay_key_state==RE_KEY_UP){
								
				if(LAST_STA!=RE_KEY_UP){			
					
					 LAST_STA=RE_KEY_UP;		
					 Set_Frequence(600);
            					
				}
				
       Delay_One_Sec();
				
				}

}

int main(void)
{
   
	 void InitAll();
   void Rs485Action();		
	 InitAll();
    while(1)
        {	
					
			   //Test_Out();	
		  	 // Executing_In_MainWhile();			
		  	Rs485Action();		
        }

}

void InitAll(){
	
    delay_init();
    LCD_IO_FSMC_Init();
    LCD_Init();
    gui_init();
    key_init();
    //RTC_Init();
    Adc_Init();
    //tp_dev.init(); 注释了IIC的初始化函数
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置中断优先级分组为组2：2位抢占优先级，2位响应优先级     
    GPIO_SetBits(GPIOD,GPIO_Pin_13);
    GPIO_SetBits(GPIOC,GPIO_Pin_13);
    LCD_Clear(BLUE);
    flag_dev.lock_sta=L_OPEN;//屏幕lock
    flag_dev.action_flag=HOME;		
	  TIM2_Init();
	  TIM5_Init();
    Pwm_Init();
    Pwm_Input_Init();
		Pwm_Output_Init();  
	  RS485_Init(9600);
}

void Rs485Action(){
	
	  u8 rs485buf[8],key;
	  RS485_Read_Data(rs485buf,&key);
		if(key)//接收到有数据
		{
			if(key>8)key=8;//最大是5个数据.
			
 			for(i=0;i<key;i++) LCD_ShowNum(0+i*32,100,rs485buf[i],2,24,BLACK,WHITE);	//显示数据
			key=0;
 		}

}
