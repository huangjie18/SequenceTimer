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

//Í¨ÓÃ¶¨Ê±Æ÷3ÖÐ¶Ï³õÊ¼»¯
//ÕâÀïÊ±ÖÓÑ¡ÔñÎªAPB1µÄ2±¶£¬¶øAPB1Îª36M
//arr£º×Ô¶¯ÖØ×°Öµ¡£
//psc£ºÊ±ÖÓÔ¤·ÖÆµÊý
//ÕâÀïÊ¹ÓÃµÄÊÇ¶¨Ê±Æ÷3!



int gpio_pin[8]= {GPIO_Pin_0,GPIO_Pin_1,GPIO_Pin_2,GPIO_Pin_3,GPIO_Pin_4,GPIO_Pin_5,GPIO_Pin_6,GPIO_Pin_7};


extern _flag_dev flag_dev;
extern _chan_open_data chan_open_data;//Í¨µÀ¿ªÑÓÊ±Êý¾Ý
extern _chan_close_data chan_close_data;//Í¨µÀ¹ØÑÓÊ±Êý¾Ý
extern _relay_key_dev relay_key_dev;
extern u8 LINK_FLAG;
extern u8 DELAY_STA;
u8 ex_open_flag=0;//1±íÊ¾¿ª»úÍê³É±êÖ¾Î»
u8 ex_close_flag=0;//1±íÊ¾¹Ø»úÍê³É±íÊ¾Î»

void TIM2_Init()
{
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
    NVIC_InitTypeDef NVIC_InitStructure;

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE); //Ê±ÖÓÊ¹ÄÜ

    //¶¨Ê±Æ÷TIM3³õÊ¼»¯
    TIM_TimeBaseStructure.TIM_Period = 999; //ÉèÖÃÔÚÏÂÒ»¸ö¸üÐÂÊÂ¼þ×°Èë»î¶¯µÄ×Ô¶¯ÖØ×°ÔØ¼Ä´æÆ÷ÖÜÆÚµÄÖµ
    TIM_TimeBaseStructure.TIM_Prescaler =7199; //ÉèÖÃÓÃÀ´×÷ÎªTIMxÊ±ÖÓÆµÂÊ³ýÊýµÄÔ¤·ÖÆµÖµ
    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //ÉèÖÃÊ±ÖÓ·Ö¸î:TDTS = Tck_tim
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIMÏòÉÏ¼ÆÊýÄ£Ê½
    TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure); //¸ù¾ÝÖ¸¶¨µÄ²ÎÊý³õÊ¼»¯TIMxµÄÊ±¼ä»ùÊýµ¥Î»

    TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE ); //Ê¹ÄÜÖ¸¶¨µÄTIM3ÖÐ¶Ï,ÔÊÐí¸üÐÂÖÐ¶Ï

    //ÖÐ¶ÏÓÅÏÈ¼¶NVICÉèÖÃ
    NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;  //TIM3ÖÐ¶Ï
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQÍ¨µÀ±»Ê¹ÄÜ
    NVIC_Init(&NVIC_InitStructure);  //³õÊ¼»¯NVIC¼Ä´æÆ÷

    TIM_Cmd(TIM2, ENABLE);  //Ê¹ÄÜTIMx
}

u8 PIN_STA;//±ê¼ÇGPIO_Pin_7×´Ì¬
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

             DELAY_STA=0;//È¡ÏûÑÓÊ±Ò»ÃëµÄ±ê¼Ç
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
  u8 IS_EX_CLOSE=0;//±ê¼ÇÊÇ·ñ¿ÉÒÔÖ´ÐÐCHANNEL¹Ø±Õº¯Êý

void TIM2_IRQHandler(void)   //TIM3ÖÐ¶Ï
{

    u16 static SEC_CNT_O;
    u16 static SEC_CNT_C;
	  u16 static SEV_CNT;
		   
    if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET)  //¼ì²éTIM3¸üÐÂÖÐ¶Ï·¢ÉúÓë·ñ
        {
       
				if(LINK_FLAG==0){	
        if(relay_key_dev.relay_key_state==RE_KEY_DOWN){
				      
				     if(A!=1){						 
				     SEC_CNT_O+=100;					  
						 A=CHAN_O_C(SEC_CNT_O); 					
             SEC_CNT_C=0;		
            
						 }										
				}
	
				
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

				
			if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_7)==1){//¼ì²éNEXT½ÅÊÇ·ñÎª¸ßµçÆ½
             				
				  if(PIN_STA==1&&DELAY_STA==0){	//µÚ°ËÈç¹ûµÀ´					
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
				
            TIM_ClearITPendingBit(TIM4, TIM_IT_Update); 		//Çå³ýTIMx¸üÐÂÖÐ¶Ï±êÖ¾
        }
}








