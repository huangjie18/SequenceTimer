#include "main_setting_page.h"
#include "lcd.h"
#include "gui.h"
#include "delay_setting_page.h"
#include "switch_setting_page_activity.h"
#include "date_setting_page.h"
#include "reset_page.h"
#include "uv_ov_page.h"
#include "timer_page.h"
#include "pwd_page.h"
#include "auz_page.h"
#include "flag.h"
#include "touch.h"
#include "delay.h"
#include "key.h"

extern _relay_key_dev relay_key_dev;
extern _m_tp_dev tp_dev;//触屏结构体
extern _flag_dev flag_dev;
extern u8 ISALARM;//回差条件是否正常值

void main_setting_page_activity()
{


    gui_draw_bline1(91,100,319,100,1,WHITE);
    gui_draw_arcrectangle(120,210,80,30,5,1,BLUE,BLUE);
 
	
	if(flag_dev.lock_sta==L_CLOSE){	
    LCD_Show_picture(150,210,WHITE,1);	
	}else{
	LCD_Show_picture(150,210,WHITE,2);
	
	}

	if(relay_key_dev.relay_key_state==RE_KEY_DOWN){
		
	   gui_draw_arcrectangle(94,0,151,40,4,1,RED,RED);
		if(flag_dev.langage==1){
     LCD_Show_3030_String(100,5,"CHAN OPEN",WHITE); 
		}else{
		 ShowTwoChineseChar(124,11,2,3,24,WHITE);
		 ShowChineseChar(172,11,5,24,WHITE);
		}
		
	}else if(relay_key_dev.relay_key_state==XNULL||relay_key_dev.relay_key_state==RE_KEY_UP){
	   gui_draw_arcrectangle(94,0,151,40,4,1,RED,RED);
		if(flag_dev.langage==1){
    LCD_Show_3030_String(100,5,"CHAN CLOSE",WHITE);
		}else{
		ShowTwoChineseChar(124,11,2,3,24,WHITE);
		 ShowChineseChar(172,11,6,24,WHITE);
		}
	}
   

    LCD_Show_2424_String(255,15,"  :  ",WHITE);
    LCD_Show_3030_String(260, 48,"V",WHITE);
    LCD_Show_3030_String(260, 78,"~",WHITE);

   LCD_ShowNum(162,38,flag_dev.lastVAL,3,64,WHITE,BLACK);

     if(ReadCH1)
        {
            gui_draw_arcrectangle(94,104, 55,50,3,1, GRAY,GRAY);//通道1~8
            LCD_Show_4848_String(109,104,"1",RED);
        }
    else
        {
            gui_draw_arcrectangle(94,104, 55,50,3,1, GRAY,GRAY);//通道1~8
            LCD_Show_4848_String(109,104,"1",WHITE);
        }
    if(ReadCH2)
        {
            gui_draw_arcrectangle(151,104, 55,50,3,1, GRAY,GRAY);
            LCD_Show_4848_String(167,104,"2",RED);
        }
    else
        {
            gui_draw_arcrectangle(151,104, 55,50,3,1, GRAY,GRAY);
            LCD_Show_4848_String(167,104,"2",WHITE);
        }
    if(ReadCH3)
        {
            gui_draw_arcrectangle(208,104, 55,50,3,1, GRAY,GRAY);
            LCD_Show_4848_String(223,104,"3",RED);
        }
    else
        {
            gui_draw_arcrectangle(208,104, 55,50,3,1, GRAY,GRAY);
            LCD_Show_4848_String(223,104,"3",WHITE);
        }
    if(ReadCH4)
        {
            gui_draw_arcrectangle(265,104, 55,50,3,1, GRAY,GRAY);
            LCD_Show_4848_String(279,104,"4",RED);
        }
    else
        {
            gui_draw_arcrectangle(265,104, 55,50,3,1, GRAY,GRAY);
            LCD_Show_4848_String(279,104,"4",WHITE);
        }
    if(ReadCH5)
        {
            gui_draw_arcrectangle(94,156,55,50,3,1,GRAY,GRAY);
            LCD_Show_4848_String(109,156,"5",RED);
        }
    else
        {
            gui_draw_arcrectangle(94,156,55,50,3,1,GRAY,GRAY);
            LCD_Show_4848_String(109,156,"5",WHITE);
        }
    if(ReadCH6)
        {
            gui_draw_arcrectangle(151,156,55,50,3,1,GRAY,GRAY);
            LCD_Show_4848_String(167,156,"6",RED);
        }
    else
        {
            gui_draw_arcrectangle(151,156,55,50,3,1,GRAY,GRAY);
            LCD_Show_4848_String(167,156,"6",WHITE);
        }
    if(ReadCH7)
        {
            gui_draw_arcrectangle(208,156,55,50,3,1,GRAY,GRAY);
            LCD_Show_4848_String(223,156,"7",RED);
        }
    else
        {
            gui_draw_arcrectangle(208,156,55,50,3,1,GRAY,GRAY);
            LCD_Show_4848_String(223,156,"7",WHITE);
        }
    if(ReadCH8)
        {
            gui_draw_arcrectangle(265,156,55,50,3,1,GRAY,GRAY);
            LCD_Show_4848_String(279,156,"8",RED);
        }
    else
        {
            gui_draw_arcrectangle(265,156,55,50,3,1,GRAY,GRAY);
            LCD_Show_4848_String(279,156,"8",WHITE);
        }
}
void main_setting_page_action()
{
  if(flag_dev.lock_sta==L_OPEN){
    if(flag_dev.action_flag==HOME&&(tp_dev.x[0]>94)&&(tp_dev.x[0]<149)&&(tp_dev.y[0]>104)&&(tp_dev.y[0]<154))
        {
            if(EnCH1){
							if(ISALARM==0){
            if(ReadCH1)
                {                 
                   LCD_Show_4848_String(109,104,"1",WHITE);
                   ResetCH1
                }
            else 
                {                
                    LCD_Show_4848_String(109,104,"1",RED);
                    SetCH1
                }
							}
						}
            delay_ms(200);
        }
    else if(flag_dev.action_flag==HOME&&(tp_dev.x[0]>150)&&(tp_dev.x[0]<205)&&(tp_dev.y[0]>104)&&(tp_dev.y[0]<154))
        {

          if(EnCH2){
						if(ISALARM==0){
            if(ReadCH2)
                {             
                    LCD_Show_4848_String(167,104,"2",WHITE);
                    ResetCH2
                }
            else 
                {                
                    LCD_Show_4848_String(167,104,"2",RED);
                    SetCH2
                }
							}
						}
            delay_ms(200);

        }
    else if(flag_dev.action_flag==HOME&&(tp_dev.x[0]>206)&&(tp_dev.x[0]<261)&&(tp_dev.y[0]>104)&&(tp_dev.y[0]<154))
        {
					if(EnCH3){
						if(ISALARM==0){
            if(ReadCH3)
                {
                
                    LCD_Show_4848_String(223,104,"3",WHITE);
                    ResetCH3
                }
            else 
                {
                
                    LCD_Show_4848_String(223,104,"3",RED);
                    SetCH3
                }
							}
						}
            delay_ms(200);
        }
    else if(flag_dev.action_flag==HOME&&(tp_dev.x[0]>262)&&(tp_dev.x[0]<317)&&(tp_dev.y[0]>104)&&(tp_dev.y[0]<154))
        {
         if(EnCH4){
					 if(ISALARM==0){
            if(ReadCH4)
                {
            
                    LCD_Show_4848_String(279,104,"4",WHITE);
                   ResetCH4
                }
            else 
                {
              
                    LCD_Show_4848_String(279,104,"4",RED);
                    SetCH4
                }
							}
				    }		
            delay_ms(200);
        }


    else if(flag_dev.action_flag==HOME&&(tp_dev.x[0]>94)&&(tp_dev.x[0]<149)&&(tp_dev.y[0]>156)&&(tp_dev.y[0]<206))
        {

         if(EnCH5){
					 if(ISALARM==0){
            if(ReadCH5)
                {
                
                    LCD_Show_4848_String(109,156,"5",WHITE);
                   ResetCH5
                }
            else 
                {
              
                    LCD_Show_4848_String(109,156,"5",RED);
                   SetCH5
                }
							}
						}
            delay_ms(200);

        }
    else if(flag_dev.action_flag==HOME&&(tp_dev.x[0]>150)&&(tp_dev.x[0]<205)&&(tp_dev.y[0]>156)&&(tp_dev.y[0]<206))
        {

           if(EnCH6){
						 if(ISALARM==0){
            if(ReadCH6)
                {
                 
                    LCD_Show_4848_String(167,156,"6",WHITE);
                    ResetCH6
                }
            else 
                {
                
                    LCD_Show_4848_String(167,156,"6",RED);
                    SetCH6
                }
							}
						}
            delay_ms(200);

        }
    else if(flag_dev.action_flag==HOME&&(tp_dev.x[0]>206)&&(tp_dev.x[0]<261)&&(tp_dev.y[0]>156)&&(tp_dev.y[0]<206))
        {

            if(EnCH7){
							if(ISALARM==0){
            if(ReadCH7)
                {
                 
                    LCD_Show_4848_String(223,156,"7",WHITE);
                    ResetCH7
                }
            else 
                {
                 
                    LCD_Show_4848_String(223,156,"7",RED);
                    SetCH7
                }
							}
						}
            delay_ms(200);

        }
    else if(flag_dev.action_flag==HOME&&(tp_dev.x[0]>262)&&(tp_dev.x[0]<317)&&(tp_dev.y[0]>156)&&(tp_dev.y[0]<206))
        {

         if(EnCH8){
					 if(ISALARM==0){
            if(ReadCH8)
                {
                 
                    LCD_Show_4848_String(279,156,"8",WHITE);
                    ResetCH8
                }
            else 
                {
                 
                    LCD_Show_4848_String(279,156,"8",RED);
                   SetCH8
                }
							}
						}
            delay_ms(200);
        }
				
			}
}

void Channel_State_Show_(){

 if(flag_dev.action_flag==HOME){
    if(ReadCH1)
        {
            LCD_Show_4848_String(109,104,"1",RED);
        }
    else
        {        
            LCD_Show_4848_String(109,104,"1",WHITE);
        }
    if(ReadCH2)
        {       
            LCD_Show_4848_String(167,104,"2",RED);
        }
    else
        {         
            LCD_Show_4848_String(167,104,"2",WHITE);
        }
    if(ReadCH3)
        {       
            LCD_Show_4848_String(223,104,"3",RED);
        }
    else
        {        
            LCD_Show_4848_String(223,104,"3",WHITE);
        }

    if(ReadCH4)
        {    
            LCD_Show_4848_String(279,104,"4",RED);
        }
    else
        {        
            LCD_Show_4848_String(279,104,"4",WHITE);
        }

    if(ReadCH5)
        {          
            LCD_Show_4848_String(109,156,"5",RED);
        }
    else
        {         
            LCD_Show_4848_String(109,156,"5",WHITE);
        }

    if(ReadCH6)
        {         
            LCD_Show_4848_String(167,156,"6",RED);
        }
    else
        {        
            LCD_Show_4848_String(167,156,"6",WHITE);
        }

    if(ReadCH7)
        {        
            LCD_Show_4848_String(223,156,"7",RED);
        }
    else
        {     
            LCD_Show_4848_String(223,156,"7",WHITE);
        }

    if(ReadCH8)
        {       
            LCD_Show_4848_String(279,156,"8",RED);
        }
    else
        {         
            LCD_Show_4848_String(279,156,"8",WHITE);
        }
			}
}

