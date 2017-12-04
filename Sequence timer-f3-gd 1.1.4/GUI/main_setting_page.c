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


void main_setting_page_activity()
{


    gui_draw_bline1(91,100,319,100,1,WHITE);

    gui_draw_arcrectangle(120,210,80,30,1,1,BLUE,BLUE);
    
	
	if(flag_dev.lock_sta==L_CLOSE){
		
    LCD_Show_picture(150,210,WHITE,1);
		
	}else{
	LCD_Show_picture(150,210,WHITE,2);
	
	}

//		 LCD_Show_picture(160,210,WHITE,1);


//     LCD_Show_3030_String(92, 48,"Voltage:",GREEN);
   
	
	if(relay_key_dev.relay_key_state==RE_KEY_DOWN){
		
	  gui_draw_arcrectangle(94,0,151,40,1,1,RED,RED);
	  LCD_Show_3030_String(100,5,"CHAN OPEN",WHITE);
		
	}else if(relay_key_dev.relay_key_state==XNULL||relay_key_dev.relay_key_state==RE_KEY_UP){
	  gui_draw_arcrectangle(94,0,151,40,1,1,RED,RED);
	  LCD_Show_3030_String(100,5,"CHAN CLOSE",WHITE);
	}
   

    LCD_Show_2424_String(255,15,"  :  ",WHITE);
    LCD_Show_3030_String(260, 48,"V",WHITE);
    LCD_Show_3030_String(260, 78,"~",WHITE);

   LCD_ShowNum(162,38,flag_dev.lastVAL,3,64,WHITE,BLACK);

 if(GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_0))
        {

            gui_draw_arcrectangle(94,104, 55,50,1,1, GRAY,GRAY);//通道1~8
            LCD_Show_4848_String(109,104,"1",RED);
        }
    else
        {
  
            gui_draw_arcrectangle(94,104, 55,50,1,1, GRAY,GRAY);//通道1~8
            LCD_Show_4848_String(109,104,"1",WHITE);
        }
    if(GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_1))
        {
            gui_draw_arcrectangle(150,104, 55,50,1,1, GRAY,GRAY);
            LCD_Show_4848_String(165,104,"2",RED);

        }
    else
        {
            gui_draw_arcrectangle(150,104, 55,50,1,1, GRAY,GRAY);
            LCD_Show_4848_String(165,104,"2",WHITE);
        }
    if(GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_2))
        {

            gui_draw_arcrectangle(206,104, 55,50,1,1, GRAY,GRAY);
            LCD_Show_4848_String(221,104,"3",RED);
        }
    else
        {
            gui_draw_arcrectangle(206,104, 55,50,1,1, GRAY,GRAY);
            LCD_Show_4848_String(221,104,"3",WHITE);
        }

    if(GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_3))
        {
            gui_draw_arcrectangle(262,104, 55,50,1,1, GRAY,GRAY);
            LCD_Show_4848_String(277,104,"4",RED);

        }
    else
        {

            gui_draw_arcrectangle(262,104, 55,50,1,1, GRAY,GRAY);
            LCD_Show_4848_String(277,104,"4",WHITE);
        }

    if(GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_4))
        {
            gui_draw_arcrectangle(94,156,55,50,1,1,GRAY,GRAY);
            LCD_Show_4848_String(109,156,"5",RED);

        }
    else
        {

            gui_draw_arcrectangle(94,156,55,50,1,1,GRAY,GRAY);
            LCD_Show_4848_String(109,156,"5",WHITE);
        }

    if(GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_5))
        {
            gui_draw_arcrectangle(150,156,55,50,1,1,GRAY,GRAY);
            LCD_Show_4848_String(165,156,"6",RED);

        }
    else
        {

            gui_draw_arcrectangle(150,156,55,50,1,1,GRAY,GRAY);
            LCD_Show_4848_String(165,156,"6",WHITE);
        }

    if(GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_6))
        {


            gui_draw_arcrectangle(206,156,55,50,1,1,GRAY,GRAY);
            LCD_Show_4848_String(221,156,"7",RED);
        }
    else
        {
            gui_draw_arcrectangle(206,156,55,50,1,1,GRAY,GRAY);
            LCD_Show_4848_String(221,156,"7",WHITE);
        }

    if(GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_7))
        {


            gui_draw_arcrectangle(262,156,55,50,1,1,GRAY,GRAY);
            LCD_Show_4848_String(277,156,"8",RED);
        }
    else
        {
            gui_draw_arcrectangle(262,156,55,50,1,1,GRAY,GRAY);
            LCD_Show_4848_String(277,156,"8",WHITE);
        }


   

}


void main_setting_page_action()
{
  if(flag_dev.lock_sta==L_OPEN){
    if(flag_dev.action_flag==HOME&&(tp_dev.x[0]>94)&&(tp_dev.x[0]<149)&&(tp_dev.y[0]>104)&&(tp_dev.y[0]<154))
        {


            if(GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_0))
                {
                    gui_draw_arcrectangle(94,104, 55,50,1,1, GRAY,GRAY);//通道1~8
                    LCD_Show_4848_String(109,104,"1",WHITE);
                    GPIO_ResetBits(GPIOC,GPIO_Pin_0);
                }
            else
                {
                    gui_draw_arcrectangle(94,104, 55,50,1,1, GRAY,GRAY);//通道1~8
                    LCD_Show_4848_String(109,104,"1",RED);
                    GPIO_SetBits(GPIOC,GPIO_Pin_0);
                }
            delay_ms(200);

        }
    else if(flag_dev.action_flag==HOME&&(tp_dev.x[0]>150)&&(tp_dev.x[0]<205)&&(tp_dev.y[0]>104)&&(tp_dev.y[0]<154))
        {


            if(GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_1))
                {
                    gui_draw_arcrectangle(150,104, 55,50,1,1, GRAY,GRAY);
                    LCD_Show_4848_String(165,104,"2",WHITE);
                    GPIO_ResetBits(GPIOC,GPIO_Pin_1);
                }
            else
                {
                    gui_draw_arcrectangle(150,104, 55,50,1,1, GRAY,GRAY);
                    LCD_Show_4848_String(165,104,"2",RED);
                    GPIO_SetBits(GPIOC,GPIO_Pin_1);
                }
            delay_ms(200);

        }
    else if(flag_dev.action_flag==HOME&&(tp_dev.x[0]>206)&&(tp_dev.x[0]<261)&&(tp_dev.y[0]>104)&&(tp_dev.y[0]<154))
        {



            if(GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_2))
                {
                    gui_draw_arcrectangle(206,104, 55,50,1,1, GRAY,GRAY);
                    LCD_Show_4848_String(221,104,"3",WHITE);
                    GPIO_ResetBits(GPIOC,GPIO_Pin_2);
                }
            else
                {
                    gui_draw_arcrectangle(206,104, 55,50,1,1, GRAY,GRAY);
                    LCD_Show_4848_String(221,104,"3",RED);
                    GPIO_SetBits(GPIOC,GPIO_Pin_2);
                }

            delay_ms(200);
        }
    else if(flag_dev.action_flag==HOME&&(tp_dev.x[0]>262)&&(tp_dev.x[0]<317)&&(tp_dev.y[0]>104)&&(tp_dev.y[0]<154))
        {




            if(GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_3))
                {
                    gui_draw_arcrectangle(262,104, 55,50,1,1, GRAY,GRAY);
                    LCD_Show_4848_String(277,104,"4",WHITE);
                    GPIO_ResetBits(GPIOC,GPIO_Pin_3);
                }
            else
                {
                    gui_draw_arcrectangle(262,104, 55,50,1,1, GRAY,GRAY);
                    LCD_Show_4848_String(277,104,"4",RED);
                    GPIO_SetBits(GPIOC,GPIO_Pin_3);
                }

            delay_ms(200);
        }


    else if(flag_dev.action_flag==HOME&&(tp_dev.x[0]>94)&&(tp_dev.x[0]<149)&&(tp_dev.y[0]>156)&&(tp_dev.y[0]<206))
        {


            if(GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_4))
                {
                    gui_draw_arcrectangle(94,156,55,50,1,1,GRAY,GRAY);
                    LCD_Show_4848_String(109,156,"5",WHITE);

                    GPIO_ResetBits(GPIOC,GPIO_Pin_4);
                }
            else
                {
                    gui_draw_arcrectangle(94,156,55,50,1,1,GRAY,GRAY);
                    LCD_Show_4848_String(109,156,"5",RED);

                    GPIO_SetBits(GPIOC,GPIO_Pin_4);
                }
            delay_ms(200);

        }
    else if(flag_dev.action_flag==HOME&&(tp_dev.x[0]>150)&&(tp_dev.x[0]<205)&&(tp_dev.y[0]>156)&&(tp_dev.y[0]<206))
        {



            if(GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_5))
                {
                    gui_draw_arcrectangle(150,156,55,50,1,1,GRAY,GRAY);
                    LCD_Show_4848_String(165,156,"6",WHITE);

                    GPIO_ResetBits(GPIOC,GPIO_Pin_5);
                }
            else
                {
                    gui_draw_arcrectangle(150,156,55,50,1,1,GRAY,GRAY);
                    LCD_Show_4848_String(165,156,"6",RED);

                    GPIO_SetBits(GPIOC,GPIO_Pin_5);
                }

            delay_ms(200);

        }
    else if(flag_dev.action_flag==HOME&&(tp_dev.x[0]>206)&&(tp_dev.x[0]<261)&&(tp_dev.y[0]>156)&&(tp_dev.y[0]<206))
        {


            if(GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_6))
                {
                    gui_draw_arcrectangle(206,156,55,50,1,1,GRAY,GRAY);
                    LCD_Show_4848_String(221,156,"7",WHITE);


                    GPIO_ResetBits(GPIOC,GPIO_Pin_6);
                }
            else
                {
                    gui_draw_arcrectangle(206,156,55,50,1,1,GRAY,GRAY);
                    LCD_Show_4848_String(221,156,"7",RED);


                    GPIO_SetBits(GPIOC,GPIO_Pin_6);
                }

            delay_ms(200);

        }
    else if(flag_dev.action_flag==HOME&&(tp_dev.x[0]>262)&&(tp_dev.x[0]<317)&&(tp_dev.y[0]>156)&&(tp_dev.y[0]<206))
        {


            if(GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_7))
                {
                    gui_draw_arcrectangle(262,156,55,50,1,1,GRAY,GRAY);
                    LCD_Show_4848_String(277,156,"8",WHITE);


                    GPIO_ResetBits(GPIOC,GPIO_Pin_7);
                }
            else
                {
                    gui_draw_arcrectangle(262,156,55,50,1,1,GRAY,GRAY);
                    LCD_Show_4848_String(277,156,"8",RED);


                    GPIO_SetBits(GPIOC,GPIO_Pin_7);
                }

            delay_ms(200);
        }


			}




}

void Channel_State_Show_(){
//
 if(flag_dev.action_flag==HOME){
    if(GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_0))
        {
            
            gui_draw_arcrectangle(94,104, 55,50,1,1, GRAY,GRAY);//通道1~8
            LCD_Show_4848_String(109,104,"1",RED);
        }
    else
        {
  
            gui_draw_arcrectangle(94,104, 55,50,1,1, GRAY,GRAY);//通道1~8
            LCD_Show_4848_String(109,104,"1",WHITE);
        }
    if(GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_1))
        {
            gui_draw_arcrectangle(150,104, 55,50,1,1, GRAY,GRAY);
            LCD_Show_4848_String(165,104,"2",RED);

        }
    else
        {
            gui_draw_arcrectangle(150,104, 55,50,1,1, GRAY,GRAY);
            LCD_Show_4848_String(165,104,"2",WHITE);
        }
    if(GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_2))
        {

            gui_draw_arcrectangle(206,104, 55,50,1,1, GRAY,GRAY);
            LCD_Show_4848_String(221,104,"3",RED);
        }
    else
        {
            gui_draw_arcrectangle(206,104, 55,50,1,1, GRAY,GRAY);
            LCD_Show_4848_String(221,104,"3",WHITE);
        }

    if(GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_3))
        {
            gui_draw_arcrectangle(262,104, 55,50,1,1, GRAY,GRAY);
            LCD_Show_4848_String(277,104,"4",RED);

        }
    else
        {

            gui_draw_arcrectangle(262,104, 55,50,1,1, GRAY,GRAY);
            LCD_Show_4848_String(277,104,"4",WHITE);
        }

    if(GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_4))
        {
            gui_draw_arcrectangle(94,156,55,50,1,1,GRAY,GRAY);
            LCD_Show_4848_String(109,156,"5",RED);

        }
    else
        {

            gui_draw_arcrectangle(94,156,55,50,1,1,GRAY,GRAY);
            LCD_Show_4848_String(109,156,"5",WHITE);
        }

    if(GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_5))
        {
            gui_draw_arcrectangle(150,156,55,50,1,1,GRAY,GRAY);
            LCD_Show_4848_String(165,156,"6",RED);

        }
    else
        {

            gui_draw_arcrectangle(150,156,55,50,1,1,GRAY,GRAY);
            LCD_Show_4848_String(165,156,"6",WHITE);
        }

    if(GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_6))
        {


            gui_draw_arcrectangle(206,156,55,50,1,1,GRAY,GRAY);
            LCD_Show_4848_String(221,156,"7",RED);
        }
    else
        {
            gui_draw_arcrectangle(206,156,55,50,1,1,GRAY,GRAY);
            LCD_Show_4848_String(221,156,"7",WHITE);
        }

    if(GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_7))
        {


            gui_draw_arcrectangle(262,156,55,50,1,1,GRAY,GRAY);
            LCD_Show_4848_String(277,156,"8",RED);
        }
    else
        {
            gui_draw_arcrectangle(262,156,55,50,1,1,GRAY,GRAY);
            LCD_Show_4848_String(277,156,"8",WHITE);
        }
			}
}
