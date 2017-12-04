#include "main_setting_page.h"
#include "pwm.h"
#include "sys.h"
#include "delay.h"
#include "lcd.h"
#include "flag.h"
#include "gui.h"
#include "key.h"

/*
使计数器为10K，0.1毫秒计数，72000000/（7199+1）=10K，自动装载值为400，PWM频率为25HZ
使计数器为10K，0.1毫秒计数，72000000/（7199+1）=10K，自动装载值为600，PWM频率为16HZ
使计数器为10K，0.1毫秒计数，72000000/（7199+1）=10K，自动装载值为200，PWM频率为50HZ
*/

/*
1，三个定时器的优先级问题
2，TIM5用于检测是否有级联和CHANNEL全部关闭时的低电平延时
*/
extern _flag_dev flag_dev;

u16 SEC_CNT=0;
u16 LINK_CNT;//标记联测是否有级联时间
u8 LINK_FLAG;//标记是否有级联
u8 CHAN_STATUS=1;//标记是否CHAN全部打开或者全部关闭
u8 LAST_KEY_STATUS=0;//储存按键状态
u8 FEQUENCE_FLAG;//标记接收到的频率
u8 DELAY_STA;//是否检测到延时标志位
u8 TIM3CH1_CAPTURE_STA=0;//输入状态
u32 TIM3CH1_CAPTURE_VAL;//输入捕获值
/*
定时器TIM1的初始化函数
*/
void Pwm_Init()
{
	
    GPIO_InitTypeDef  GPIO_InitStructure;
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3|RCC_APB1Periph_TIM2,ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO, ENABLE);//使能复用功能时钟、TIM1

   
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;		//NEXT脚
    GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_OD;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;		//UPPER脚
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
					
				 	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;		//UPPER脚
            GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPD;
            GPIO_Init(GPIOA, &GPIO_InitStructure);		
			      delay_ms(200);
					
				    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;		//UPPER脚
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
    TIM_TimeBaseStructure.TIM_ClockDivision=0;//设置定时器时钟(CK_INT)频率与数字滤波器(ETR，TIx)使用的采样频率之间的分频比例的（与输入捕获相关）， 0表示滤波器的频率和定时器的频率是一样的。
    TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;
    TIM_TimeBaseInit(TIM2,&TIM_TimeBaseStructure);

    TIM_OCInitStructure.TIM_OCMode=TIM_OCMode_PWM2;
    TIM_OCInitStructure.TIM_OutputState=TIM_OutputState_Enable;
    TIM_OCInitStructure.TIM_Pulse =0; //设置待装入捕获比较寄存器的脉冲值
    TIM_OCInitStructure.TIM_OCPolarity=TIM_OCPolarity_High;
    TIM_OC4Init(TIM2,&TIM_OCInitStructure);  
    TIM_OC4PreloadConfig(TIM2,TIM_OCPreload_Enable);//使能TIM2在CCR2上的预装载寄存器
	
    TIM_ARRPreloadConfig(TIM2, ENABLE); //使能TIMx在ARR上的预装载寄存器
    TIM_Cmd(TIM2,ENABLE);
	   
}


void Pwm_Input_Init()
{

    GPIO_InitTypeDef GPIO_InitStructure;
    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
    NVIC_InitTypeDef NVIC_InitStructure;
    TIM_ICInitTypeDef TIM3_InitStructure;

    TIM_TimeBaseStructure.TIM_Period = 0xFFFF; //设定计数器自动重装值
    TIM_TimeBaseStructure.TIM_Prescaler =72000-1; 	//预分频器
    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //设置时钟分割:TDTS = Tck_tim
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
    TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); //根据TIM_TimeBaseInitStruct中指定的参数初始化TIMx的时间基数单位

    TIM3_InitStructure.TIM_Channel=TIM_Channel_1;//CC1S=01  选择输入端IC1映射到TI1（参考TIM框图）
    TIM3_InitStructure.TIM_ICPolarity=TIM_ICPolarity_Rising;
    TIM3_InitStructure.TIM_ICSelection=TIM_ICSelection_DirectTI;//选择输入端IC1映射到TI1,选择间接会是输入端映射到TI2上
    TIM3_InitStructure.TIM_ICPrescaler=TIM_ICPSC_DIV1;//配置输入分频（选择几个上升沿捕获一次）
    TIM3_InitStructure.TIM_ICFilter=0x00;//IC1F=0000 配置输入滤波器 不滤波
    TIM_ICInit(TIM3,&TIM3_InitStructure);

    NVIC_InitStructure.NVIC_IRQChannel=TIM3_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1;//抢占优先级2级
    NVIC_InitStructure.NVIC_IRQChannelSubPriority=0;//从优先级
    NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;//使能IRQ通道
    NVIC_Init(&NVIC_InitStructure);//根据NVIC_InitStructure中指定的参数初始化外设NVIC寄存器

    TIM_ITConfig(TIM3,TIM_IT_Update|TIM_IT_CC1,ENABLE);//允许更新中断，允许CC1TE捕获中断
    TIM_Cmd(TIM3,ENABLE);
}

void TIM3_IRQHandler(void)
{
    if((TIM3CH1_CAPTURE_STA&0x80)==0)//还没有捕获
        {

            if(TIM_GetITStatus(TIM3,TIM_IT_Update)!=RESET)
                {
                    if(TIM3CH1_CAPTURE_STA&0x40)//已经捕获到高电平
                        {
                            if((TIM3CH1_CAPTURE_STA&0x3F)==0x3F)//高电平太长了
                                {
																	
                                    TIM3CH1_CAPTURE_STA|=0x80;//标记成功捕获一次
                                    TIM3CH1_CAPTURE_VAL=0xFFFF;

                                }
                            else TIM3CH1_CAPTURE_STA++;
                        }

                }
            if(TIM_GetITStatus(TIM3,TIM_IT_CC1)!=RESET)//捕获1发生捕获事件
                {
                    if(TIM3CH1_CAPTURE_STA&0x40)//捕获一个下降沿
                        {
                            TIM3CH1_CAPTURE_STA|=0x80;//标记成功捕获到一次高电平脉宽
                            TIM3CH1_CAPTURE_VAL=TIM_GetCapture1(TIM3);
                            TIM_OC1PolarityConfig(TIM3,TIM_ICPolarity_Rising);//CC1P=0 设置为上升沿捕获
                        }
                    else   //还没开始，第一次捕获上升沿
                        {
                            TIM3CH1_CAPTURE_STA=0;//清空
                            TIM3CH1_CAPTURE_VAL=0;
                            TIM_SetCounter(TIM3,0);
                            TIM3CH1_CAPTURE_STA|=0x40;//标记捕获上升沿
                            TIM_OC1PolarityConfig(TIM3,TIM_ICPolarity_Falling); //CC1P 设置为下降沿捕获
                        }

                }
        }
				
								
    TIM_ClearITPendingBit(TIM3,TIM_IT_CC1|TIM_IT_Update);//清除中断标志位
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
          
//------------------------主机识别是否有级联、从机CHANNEL是否全部关闭到最后一个---------------

            if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_3)==1)
                {
                    LINK_FLAG=1;            //标记有级联              
                    if(100<LINK_CNT&&LINK_CNT<500) //检测到有一秒的延时
                        {
                            DELAY_STA=1; //TODO：表示从机已经全部CHANNEL关闭了												  												 
                        }
                   LINK_CNT=0;
                }
								
            else if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_3)==0) //设置每
                {

                    if(LINK_CNT>1000) //持续三秒钟低电平
                        {
                            LINK_FLAG=0; //标记没有级联                     
                            TIM3CH1_CAPTURE_VAL=0;//清除检测到的值禁用KEY开关条件）
													  LINK_CNT=0;
                        }
                    LINK_CNT+=10;
										
                }
															
//---------------------------根据捕获频率改变按键状态----------------------------------
              if(TIM3CH1_CAPTURE_STA&0X80) //捕获到一次上升沿，表示有级联
                {									
                    if(150<TIM3CH1_CAPTURE_VAL&&TIM3CH1_CAPTURE_VAL<250)
                        {                          
                           relay_key_dev.relay_key_state=RE_KEY_DOWN;
													 FEQUENCE_FLAG=25;
													 LINK_FLAG=1;            //标记有级联 
                        }
                    else if(250<TIM3CH1_CAPTURE_VAL&&TIM3CH1_CAPTURE_VAL<350)
                        {
                            relay_key_dev.relay_key_state=RE_KEY_UP;
													  LINK_FLAG=1;            //标记有级联 
                            
                        }   	          		                 
                }
																							
						TIM_ClearITPendingBit(TIM5,TIM_IT_Update);//清除中断标志位
						
        }
}

