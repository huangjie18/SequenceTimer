#include "main_setting_page.h"
#include "pwm.h"
#include "sys.h"
#include "delay.h"
#include "lcd.h"
#include "flag.h"
#include "gui.h"
#include "key.h"
#include "adc.h"
#include "data.h"
/*
使计数器为10K，0.1毫秒计数，72000000/（7199+1）=10K，自动装载值为400，PWM频率为25HZ
使计数器为10K，0.1毫秒计数，72000000/（7199+1）=10K，自动装载值为600，PWM频率为16HZ
使计数器为10K，0.1毫秒计数，72000000/（7199+1）=10K，自动装载值为200，PWM频率为50HZ
*/


extern _flag_dev flag_dev;

u32 ADCVAL;//ADC采集值
u16 SEC_CNT=0;
u16 LINK_CNT;//标记联测是否有级联时间
u8 LINK_FLAG;//标记是否有级联
u8 CHAN_STATUS=1;//标记是否CHAN全部打开或者全部关闭
u8 LAST_KEY_STATUS=0;//储存按键状态
u8 FEQUENCE_FLAG;//标记接收到的频率
u8 DELAY_STA;//是否检测到延时标志位
u8 TIM3CH1_CAPTURE_STA=0;//输入状态
u32 TIM3CH1_CAPTURE_VAL;//输入捕获值
extern u8 IS_EX_CLOSE;
extern u8 temp[8];
void Pwm_Init()
{

    GPIO_InitTypeDef  GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_AFIO, ENABLE);//使能复用功能时钟、TIM1
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;		//NEXT脚
    GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_OD;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;		//UPPER脚
    GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
    GPIO_Init(GPIOB, &GPIO_InitStructure);


}
void Delay_One_Sec()
{

    GPIO_InitTypeDef  GPIO_InitStructure;

    if(FEQUENCE_FLAG==25)
        {

            if( relay_key_dev.relay_key_state==RE_KEY_UP)
                {

                    if(ReadCH1==0)
                        {

                            GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;		//UPPER脚
                            GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
													  GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
                            GPIO_Init(GPIOB, &GPIO_InitStructure);
													  GPIO_ResetBits(GPIOB,GPIO_Pin_9);
                            delay_ms(200);													 
													  //GPIO_SetBits(GPIOB,GPIO_Pin_9);
                            GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;		//UPPER脚
                            GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
                            GPIO_Init(GPIOB, &GPIO_InitStructure);
                            FEQUENCE_FLAG=0;

                        }
                }
        }



}
void KeyChangeFrequence()
{


    if(relay_key_dev.relay_key_state==RE_KEY_DOWN)
       {
				    if(EnCH8){
						if(ReadCH8)	
            flag_dev.FREQUENCE=25;
						}
						else if(EnCH7){
						if(ReadCH7)	
            flag_dev.FREQUENCE=25;
						}
						else if(EnCH6){
						if(ReadCH6)	
            flag_dev.FREQUENCE=25;
						}
						else if(EnCH5){
						if(ReadCH5)	
            flag_dev.FREQUENCE=25;
						}
						else if(EnCH4){
						if(ReadCH4)	
            flag_dev.FREQUENCE=25;
						}
						else if(EnCH3){
						if(ReadCH3)	
            flag_dev.FREQUENCE=25;
						}
						else if(EnCH2){
						if(ReadCH2)	
            flag_dev.FREQUENCE=25;
						}
						else if(EnCH1){
						if(ReadCH1)	
            flag_dev.FREQUENCE=25;
						}
        }
    else if(relay_key_dev.relay_key_state==RE_KEY_UP)
        {
            flag_dev.FREQUENCE=16;
        }


}
u16  cntA=0;
void PwmOutput()
{

    u8 static LastFrequence;
    if(LastFrequence!=flag_dev.FREQUENCE)
        {
            cntA=0;

            LastFrequence=flag_dev.FREQUENCE;
        }
    if(flag_dev.FREQUENCE==25)
        {
            switch(cntA)
                {
                case 0x00:
                    GPIO_SetBits(GPIOB,GPIO_Pin_8);
                    cntA=1;
                    break;
                case 0x01:
                    GPIO_SetBits(GPIOB,GPIO_Pin_8);
                    cntA=2;
                    break;
                case 0x02:
                    GPIO_ResetBits(GPIOB,GPIO_Pin_8);
                    cntA=3;
                    break;
                case 0x03:
                    cntA=4;
                    GPIO_ResetBits(GPIOB,GPIO_Pin_8);
                    break;
                case 0x04:
                    GPIO_SetBits(GPIOB,GPIO_Pin_8);
                    cntA=1;
                    break;
                }

        }
    else if(flag_dev.FREQUENCE==16)
        {
            switch(cntA)
                {
                case 0x00:
                    GPIO_SetBits(GPIOB,GPIO_Pin_8);
                    cntA=1;
                    break;
                case 0x01:
                    GPIO_SetBits(GPIOB,GPIO_Pin_8);
                    cntA=2;
                    break;
                case 0x02:
                    GPIO_SetBits(GPIOB,GPIO_Pin_8);
                    cntA=3;
                    break;
                case 0x03:
                    GPIO_ResetBits(GPIOB,GPIO_Pin_8);
                    cntA=4;
                    break;
                case 0x04:
                    GPIO_ResetBits(GPIOB,GPIO_Pin_8);
                    cntA+=1;
                    break;
                case 0x05:
                    GPIO_ResetBits(GPIOB,GPIO_Pin_8);
                    cntA+=1;
                    break;
                case 0x06:
                    GPIO_SetBits(GPIOB,GPIO_Pin_8);
                    cntA=1;
                    break;
                }

        }
    else if(flag_dev.FREQUENCE==0)
        {
            switch(cntA)
                {
                case 0x00:
                    GPIO_SetBits(GPIOB,GPIO_Pin_8);
                    cntA=1;
                    break;
                case 0x01:
                    GPIO_ResetBits(GPIOB,GPIO_Pin_8);
                    cntA=0;
                    break;
                }

        }
}



void Pwm_Input_Init()
{

    GPIO_InitTypeDef GPIO_InitStructure;
    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
    NVIC_InitTypeDef NVIC_InitStructure;
    TIM_ICInitTypeDef TIM4_InitStructure;

    TIM_TimeBaseStructure.TIM_Period = 0xFFFF; //设定计数器自动重装值
    TIM_TimeBaseStructure.TIM_Prescaler =72000-1; 	//预分频器
    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //设置时钟分割:TDTS = Tck_tim
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
    TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure); //根据TIM_TimeBaseInitStruct中指定的参数初始化TIMx的时间基数单位

    TIM4_InitStructure.TIM_Channel=TIM_Channel_4;//CC1S=01  选择输入端IC1映射到TI1（参考TIM框图）
    TIM4_InitStructure.TIM_ICPolarity=TIM_ICPolarity_Rising;
    TIM4_InitStructure.TIM_ICSelection=TIM_ICSelection_DirectTI;//选择输入端IC1映射到TI1,选择间接会是输入端映射到TI2上
    TIM4_InitStructure.TIM_ICPrescaler=TIM_ICPSC_DIV1;//配置输入分频（选择几个上升沿捕获一次）
    TIM4_InitStructure.TIM_ICFilter=0x00;//IC1F=0000 配置输入滤波器 不滤波
    TIM_ICInit(TIM4,&TIM4_InitStructure);

	
	  NVIC_InitStructure.NVIC_IRQChannel=TIM4_IRQn;
	  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1;//抢占优先级2级
    NVIC_InitStructure.NVIC_IRQChannelSubPriority=1;//从优先级
    NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;//使能IRQ通道
    NVIC_Init(&NVIC_InitStructure);//根据NVIC_InitStructure中指定的参数初始化外设NVIC寄存器

    TIM_ITConfig(TIM4,TIM_IT_Update|TIM_IT_CC4,ENABLE);//允许更新中断，允许CC1TE捕获中断
    TIM_Cmd(TIM4,ENABLE);
}
extern u8 ISALARM;
extern u8 PIN_STA;
static u8 CAPTURECNTA;
static u8 CAPTURECNTB;
static u8 CAPTURECNTC;
static u8 CAPTURETIME;
void TIM4_IRQHandler(void)
{

    if(TIM_GetITStatus(TIM4,TIM_IT_CC4)!=RESET)//捕获1发生捕获事件
        {
            if(TIM3CH1_CAPTURE_STA&0x40)//捕获一个下降沿
                {
                    TIM3CH1_CAPTURE_STA=0;
                    TIM3CH1_CAPTURE_VAL=TIM_GetCapture4(TIM4);
                    TIM_OC4PolarityConfig(TIM4,TIM_ICPolarity_Rising);//CC1P=0 设置为上升沿捕获

                }
            else if(TIM3CH1_CAPTURE_STA==0)  //还没开始，第一次捕获上升沿
                {
                    TIM3CH1_CAPTURE_STA=0;//清空
                    TIM_SetCounter(TIM4,0);
                    TIM3CH1_CAPTURE_STA|=0x40;//标记捕获上升沿
                    TIM_OC4PolarityConfig(TIM4,TIM_ICPolarity_Falling); //CC1P 设置为下降沿捕获
                }
						
        }
    if(flag_dev.OPEN_PAGE_STR==1)
        {
            if(70<TIM3CH1_CAPTURE_VAL&&TIM3CH1_CAPTURE_VAL<150)
                {
                    if(CAPTURECNTC>5)
                        {
                            flag_dev.link=1;
                            CAPTURECNTC=0;
                            LINK_FLAG=1;            //标记有级联
                        }
                    TIM3CH1_CAPTURE_VAL=0;
                    CAPTURECNTA=0;
                    CAPTURECNTB=0;
                    CAPTURECNTC++;				
                    CAPTURETIME=CAPTURECNTC|0x40;												
                }
            else if(170<TIM3CH1_CAPTURE_VAL&&TIM3CH1_CAPTURE_VAL<250)
                {
                    if(CAPTURECNTA>5)
                        {
                            relay_key_dev.relay_key_state=RE_KEY_DOWN;
                            FEQUENCE_FLAG=25;
                            LINK_FLAG=1;            //标记有级联
                            CAPTURECNTA=0;
                            flag_dev.link=1;
                        }
                    TIM3CH1_CAPTURE_VAL=0;
                    CAPTURECNTB=0;
                    CAPTURECNTC=0;
                    CAPTURECNTA++;							
										CAPTURETIME=CAPTURECNTA|0x10;		
                }
            else if(270<TIM3CH1_CAPTURE_VAL&&TIM3CH1_CAPTURE_VAL<360)
                {
                    if(CAPTURECNTB>5)
                        {
                            relay_key_dev.relay_key_state=RE_KEY_UP;
                            LINK_FLAG=1;            //标记有级联
                            CAPTURECNTB=0;
                            flag_dev.link=1;
                        }
                    TIM3CH1_CAPTURE_VAL=0;
                    CAPTURECNTA=0;
                    CAPTURECNTC=0;
                    CAPTURECNTB++;
                    CAPTURETIME=CAPTURECNTB|0x20;												
                }
        }
    TIM_ClearITPendingBit(TIM4,TIM_IT_CC4|TIM_IT_Update);//清除中断标志位
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
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority=0;
    NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
    NVIC_Init(&NVIC_InitStructure);
    TIM_Cmd(TIM5,ENABLE);

}
void TIM5_IRQHandler(void)
{
	  static u16 CPATURECNT_TIME;
	  static u8 CNT;
    if(TIM_GetITStatus(TIM5,TIM_IT_Update)!=RESET)
        {

            PwmOutput();

            
            if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_8)==1)
                {

                    LINK_FLAG=1;            //标记有级联
                    flag_dev.ONESECDELAY=1;  //可以等待一秒延时
									  if(IS_EX_CLOSE==1){
                    if(70<LINK_CNT&&LINK_CNT<400)
                        {
                            DELAY_STA=1;
                            IS_EX_CLOSE=0;
                        }
											}
                    LINK_CNT=0;
                }
            if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_8)==0) //设置每
                {

                    if(LINK_CNT>2000) //持续一秒钟低电平
                        {
                            LINK_FLAG=0; //标记没有级联
                            flag_dev.link=0;//清除检测到的值禁用KEY开关条件）
                            LINK_CNT=0;
                            flag_dev.ONESECDELAY=0;
													  IS_EX_CLOSE=0;
                        }
                    LINK_CNT+=10;

                }
								//消除捕捉PWM毛刺积累的次数
								if(CPATURECNT_TIME>1000){
									
									if(CNT==CAPTURETIME){
								    switch(CAPTURETIME&0xF0){											
											case 0x10:
												CAPTURECNTA=0;								
												break;
											case 0x20:
												CAPTURECNTB=0;
												break;
											case 0x40:
												CAPTURECNTC=0;
												break;										
										}
										 CAPTURETIME=0;										
									}
 									
											CNT=CAPTURETIME;
									    CPATURECNT_TIME=0;
										}
							     
				    CPATURECNT_TIME+=10;
								
            IsWaitOneSecDelay();

            TIM_ClearITPendingBit(TIM5,TIM_IT_Update);//清除中断标志位
        }

}
void IsProtect()
{
    if(ISALARM==1||ISALARM==2)
        {
            relay_key_dev.relay_key_state=RE_KEY_UP;//当有警告延时关闭通道
            IS_EX_CLOSE=0;
            PIN_STA=0;
        }
				
}
void IsWaitOneSecDelay()
{
    
    if(PIN_STA==1&&flag_dev.ONESECDELAY==1&&DELAY_STA==0) 	//chan8已经打开，等待一秒钟延时
        {
            IS_EX_CLOSE=1;
        }
    if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_8)==1)
        {
            flag_dev.ONESECDELAY=1;
        }
    if(DELAY_STA==1&&IS_EX_CLOSE==1)
        {
            IS_EX_CLOSE=0;
        }
			
}
void shoudetail(){
	static u16 i; 
	if(i>1000){
      LCD_ShowNum(0,0,flag_dev.ONESECDELAY,1,30,WHITE,BLACK);
			LCD_ShowNum(30,0,DELAY_STA,1,30,WHITE,BLACK);	
			LCD_ShowNum(60,0,IS_EX_CLOSE,1,30,WHITE,BLACK);		
			LCD_ShowNum(90,0,PIN_STA,1,30,WHITE,BLACK);	
		  LCD_ShowNum(0,50,CAPTURECNTA,1,30,WHITE,BLACK);
			LCD_ShowNum(30,50,CAPTURECNTB,1,30,WHITE,BLACK);	
			LCD_ShowNum(60,50,CAPTURECNTC,1,30,WHITE,BLACK);		
			LCD_ShowNum(90,50,CAPTURETIME,1,30,WHITE,BLACK);			
					i=0;
}
				i++;
}
