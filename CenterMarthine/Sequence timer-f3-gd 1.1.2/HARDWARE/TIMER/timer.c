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
u8 ex_open_flag=0;//1表示开机完成标志位
u8 ex_close_flag=0;//1表示关机完成表示位

void TIM4_Int_Init(u16 arr,u16 psc)
{
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
    NVIC_InitTypeDef NVIC_InitStructure;

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE); //时钟使能

    //定时器TIM3初始化
    TIM_TimeBaseStructure.TIM_Period = arr; //设置在下一个更新事件装入活动的自动重装载寄存器周期的值
    TIM_TimeBaseStructure.TIM_Prescaler =psc; //设置用来作为TIMx时钟频率除数的预分频值
    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //设置时钟分割:TDTS = Tck_tim
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
    TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure); //根据指定的参数初始化TIMx的时间基数单位

    TIM_ITConfig(TIM4,TIM_IT_Update,ENABLE ); //使能指定的TIM3中断,允许更新中断

    //中断优先级NVIC设置
    NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn;  //TIM3中断
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQ通道被使能
    NVIC_Init(&NVIC_InitStructure);  //初始化NVIC寄存器

    TIM_Cmd(TIM4, ENABLE);  //使能TIMx
}

u8 PIN_STA;//标记GPIO_Pin_7状态
u8 CHAN_O_C(u16 sec_cnt)
{

	 u16 chan_1,chan_2,chan_3,chan_4,chan_5,chan_6,chan_7,chan_8;
	 if(LINK_FLAG==0){
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
	 
			if(LINK_FLAG==1){
				
				
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
          
            if(relay_key_dev.relay_key_state==RE_KEY_DOWN)
                {

                    GPIO_SetBits(GPIOC,GPIO_Pin_0);
                 
                }
            else if(relay_key_dev.relay_key_state==RE_KEY_UP)
                {

                    GPIO_ResetBits(GPIOC,GPIO_Pin_0);
                }

        }
    if(sec_cnt==chan_2)
        {


            if(relay_key_dev.relay_key_state==RE_KEY_DOWN)
                {

                    GPIO_SetBits(GPIOC,GPIO_Pin_1);

                }
            else if(relay_key_dev.relay_key_state==RE_KEY_UP)
                {

                    GPIO_ResetBits(GPIOC,GPIO_Pin_1);
                }


        }
    if(sec_cnt==chan_3)
        {

            if(relay_key_dev.relay_key_state==RE_KEY_DOWN)
                {

                    GPIO_SetBits(GPIOC,GPIO_Pin_2);

                }
            else if(relay_key_dev.relay_key_state==RE_KEY_UP)
                {

                    GPIO_ResetBits(GPIOC,GPIO_Pin_2);
                }


        }
    if(sec_cnt==chan_4)
        {

            if(relay_key_dev.relay_key_state==RE_KEY_DOWN)
                {

                    GPIO_SetBits(GPIOC,GPIO_Pin_3);

                }
            else if(relay_key_dev.relay_key_state==RE_KEY_UP)
                {

                    GPIO_ResetBits(GPIOC,GPIO_Pin_3);
                }



        }
    if(sec_cnt==chan_5)
        {
            if(relay_key_dev.relay_key_state==RE_KEY_DOWN)
                {

                    GPIO_SetBits(GPIOC,GPIO_Pin_4);

                }
            else if(relay_key_dev.relay_key_state==RE_KEY_UP)
                {

                    GPIO_ResetBits(GPIOC,GPIO_Pin_4);
                }



        }
    if(sec_cnt==chan_6)
        {


            if(relay_key_dev.relay_key_state==RE_KEY_DOWN)
                {

                    GPIO_SetBits(GPIOC,GPIO_Pin_5);

                }
            else if(relay_key_dev.relay_key_state==RE_KEY_UP)
                {

                    GPIO_ResetBits(GPIOC,GPIO_Pin_5);
                }


        }
    if(sec_cnt==chan_7)
        {


            if(relay_key_dev.relay_key_state==RE_KEY_DOWN)
                {

                    GPIO_SetBits(GPIOC,GPIO_Pin_6);

                }
            else if(relay_key_dev.relay_key_state==RE_KEY_UP)
                {

                    GPIO_ResetBits(GPIOC,GPIO_Pin_6);
                }


        }
    if(sec_cnt==chan_8)
        {

            if(relay_key_dev.relay_key_state==RE_KEY_DOWN)
                {

                    GPIO_SetBits(GPIOC,GPIO_Pin_7);
									  PIN_STA=1;

                }
            else if(relay_key_dev.relay_key_state==RE_KEY_UP)
                {

                    GPIO_ResetBits(GPIOC,GPIO_Pin_7);
									  PIN_STA=0;
                }

             DELAY_STA=0;//取消延时一秒的标记
        }

				Channel_State_Show_();
				
				if(Pin(GPIO_Pin_0)==1&&Pin(GPIO_Pin_1)==1&&Pin(GPIO_Pin_2)==1&&Pin(GPIO_Pin_3)==1&&Pin(GPIO_Pin_4)==1&&Pin(GPIO_Pin_5)==1
					&&Pin(GPIO_Pin_6)==1&&Pin(GPIO_Pin_7)==1){
				
				  return 1;
						
				}else if(Pin(GPIO_Pin_0)==0&&Pin(GPIO_Pin_1)==0&&Pin(GPIO_Pin_2)==0&&Pin(GPIO_Pin_3)==0&&Pin(GPIO_Pin_4)==0&&Pin(GPIO_Pin_5)==0
					&&Pin(GPIO_Pin_6)==0&&Pin(GPIO_Pin_7)==0){
						
				  return 0;
				
			
				}else{
				
				  return 2;
					
				}
				  
    
								
}

  u8 A;
  u8 IS_EX_CLOSE=0;//标记是否可以执行CHANNEL关闭函数

void TIM4_IRQHandler(void)   //TIM3中断
{

    u16 static SEC_CNT_O;
    u16 static SEC_CNT_C;
	  u16 static SEV_CNT;
		   
    if (TIM_GetITStatus(TIM4, TIM_IT_Update) != RESET)  //检查TIM3更新中断发生与否
        {
       
				if(LINK_FLAG==0){	
        if(relay_key_dev.relay_key_state==RE_KEY_DOWN){
				      
				     if(A!=1){						 
				     SEC_CNT_O+=100;					  
						 A=CHAN_O_C(SEC_CNT_O); 					
             SEC_CNT_C=0;		
            
						 }										
				}
				LCD_ShowNum(0,100,DELAY_STA,1,30,WHITE,BLACK);
				
				if(relay_key_dev.relay_key_state==RE_KEY_UP){
				
					 if(A!=0){
					   SEC_CNT_C+=100;					  
						 A=CHAN_O_C(SEC_CNT_C); 
						 SEC_CNT_O=0;
					 }
					
				}		
			
			}else if(LINK_FLAG==1){
				 
				 if(relay_key_dev.relay_key_state==RE_KEY_DOWN){
				      
				     if(A!=1){						 
				     SEC_CNT_O+=100;					  
						 A=CHAN_O_C(SEC_CNT_O); 					
             SEC_CNT_C=8000-SEC_CNT_O;		
            
						 }										
				}
				 
				LCD_ShowNum(0,100,DELAY_STA,1,30,WHITE,BLACK);
										
				
			if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_3)==1){
             				
				  if(PIN_STA==1&&DELAY_STA==0){	//等待一秒延时到来					
						IS_EX_CLOSE=1;							 						
			    	}
				}
				
				
				if(DELAY_STA==1){
					  IS_EX_CLOSE=0;		   							 					
				   }
				
				
				if(IS_EX_CLOSE==0){
				if(relay_key_dev.relay_key_state==RE_KEY_UP){
				
					 if(A!=0){
					   SEC_CNT_C+=100;					  
						 A=CHAN_O_C(SEC_CNT_C); 
						 SEC_CNT_O=8000-SEC_CNT_C;
						 
					 }
					
				}		
			}
				
 
			
				 }
				
            TIM_ClearITPendingBit(TIM4, TIM_IT_Update); 		//清除TIMx更新中断标志
        }
}








