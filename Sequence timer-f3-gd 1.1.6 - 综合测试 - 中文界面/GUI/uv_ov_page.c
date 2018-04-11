#include "uv_ov_page.h"
#include "lcd.h"
#include "gui.h"
#include  "data.h"
#include "flag.h"
#include "touch.h"
#include "delay.h"
#include "key.h"

extern  _m_tp_dev tp_dev;//触屏结构体
extern  _flag_dev flag_dev;
extern _uv_ov_data uv_ov_data;

void uv_ov_page_activity()
{

    gui_draw_arcrectangle(95,65,225,35,1,1,BLUE,BLUE);
    gui_draw_arcrectangle(95,105,225,35,1,1,BLUE,BLUE);
    gui_draw_arcrectangle(95,145,225,35,1,1,BLUE,BLUE);


    gui_draw_arcrectangle(172,68, 145,30,1,1,WHITE,WHITE);
    gui_draw_arcrectangle(152,108, 80,30,1,1,WHITE,WHITE);
    gui_draw_arcrectangle(152,148,80,30,1,1,WHITE,WHITE);

    gui_draw_arcrectangle(234,108,85,30,1,1,WHITE,WHITE);
    gui_draw_arcrectangle(234,148,85,30,1,1,WHITE,WHITE);

    LCD_DrawLtrigo(234,110,259,135,LEFT,BLUE);
    LCD_DrawLtrigo(293,110,318,135,RIGHT,BLUE);
    LCD_DrawLtrigo(234,150,259,175,LEFT,BLUE);
    LCD_DrawLtrigo(293,150,318,175,RIGHT,BLUE);

    gui_draw_arcrectangle(120,210,80,30,1,1,BLUE,BLUE);
    gui_draw_arcrectangle(125,212,70,28,1,1,WHITE,WHITE);
	  if(flag_dev.langage==1)
      LCD_Show_3030_String(130,210,"SAVE",BLACK);
		else
      ShowTwoChineseChar(135,213,10,11,24,BLACK);
		if(flag_dev.langage==1){
    LCD_Show_3030_String(130,5,"PROTECTION",WHITE);
		}else{
		ShowTwoChineseChar(130,11,28,29,24,WHITE);
		ShowTwoChineseChar(178,11,30,31,24,WHITE);
		ShowTwoChineseChar(226,11,32,33,24,WHITE);
		}
		if(flag_dev.langage==1){
    LCD_Show_3030_String(110,70,"RDV",WHITE);
    LCD_Show_3030_String(110,110,"UV",WHITE);
    LCD_Show_3030_String(110,150,"OV",WHITE);
		}else{
		ShowTwoChineseChar(100,70,76,77,24,WHITE);	
		ShowTwoChineseChar(100,110,30,31,24,WHITE);
		ShowTwoChineseChar(100,150,28,31,24,WHITE);	
			
		}


    LCD_ShowNum(235,68,uv_ov_data.rdv,2,30,BLACK,WHITE);
    LCD_Show_3030_String(270,68,"V",BLACK);
    LCD_ShowNum(160,108,uv_ov_data.uv,3,30,BLACK,WHITE);
    LCD_Show_3030_String(210,108,"V",BLACK);
    LCD_ShowNum(160,148,uv_ov_data.ov,3,30,BLACK,WHITE);
    LCD_Show_3030_String(210,148,"V",BLACK);

    if(uv_ov_data.uv_state==ON)
        {
					
			if(flag_dev.langage==1)
      	      LCD_Show_3030_String(260,110,"ON",BLACK);
			else		
				ShowChineseChar(265,110,5,24,BLACK);
      	  }
    else if(uv_ov_data.uv_state==OFF)
        {
					
					if(flag_dev.langage==1)
          	  LCD_Show_3030_String(255,110,"OFF",BLACK);
					else
						ShowChineseChar(265,110,6,24,BLACK);
						
        }
    if(uv_ov_data.ov_state==ON)
        {
					if(flag_dev.langage==1)
          	  LCD_Show_3030_String(260,150,"ON",BLACK);
					else
						ShowChineseChar(265,150,5,24,BLACK);
        } 	
    else if(uv_ov_data.ov_state==OFF)
        {
					if(flag_dev.langage==1)
          	  LCD_Show_3030_String(255,150,"OFF",BLACK);				
					else
						ShowChineseChar(265,150,6,24,BLACK);
        } 	
}


void uv_ov_page_action()
{

    if(flag_dev.action_flag==UV_OV&&(tp_dev.x[0]>172)&&(tp_dev.x[0]<319)&&(tp_dev.y[0]>68)&&(tp_dev.y[0]<98))
        {
            LCD_ShowNum(235,68,uv_ov_data.rdv,2,30,RED,WHITE);
            LCD_Show_3030_String(270,68,"V",BLACK);
            LCD_ShowNum(160,108,uv_ov_data.uv,3,30,BLACK,WHITE);
            LCD_Show_3030_String(210,108,"V",BLACK);
            LCD_ShowNum(160,148,uv_ov_data.ov,3,30,BLACK,WHITE);
            LCD_Show_3030_String(210,148,"V",BLACK);
            flag_dev.anchor=1;
        }
    else if(flag_dev.action_flag==UV_OV&&(tp_dev.x[0]>152)&&(tp_dev.x[0]<234)&&(tp_dev.y[0]>108)&&(tp_dev.y[0]<138))
        {
            LCD_ShowNum(235,68,uv_ov_data.rdv,2,30,BLACK,WHITE);
            LCD_Show_3030_String(270,68,"V",BLACK);
            LCD_ShowNum(160,108,uv_ov_data.uv,3,30,RED,WHITE);
            LCD_Show_3030_String(210,108,"V",BLACK);
            LCD_ShowNum(160,148,uv_ov_data.ov,3,30,BLACK,WHITE);
            LCD_Show_3030_String(210,148,"V",BLACK);
            flag_dev.anchor=2;
        }
    else if(flag_dev.action_flag==UV_OV&&(tp_dev.x[0]>152)&&(tp_dev.x[0]<234)&&(tp_dev.y[0]>148)&&(tp_dev.y[0]<178))
        {
            LCD_ShowNum(235,68,uv_ov_data.rdv,2,30,BLACK,WHITE);
            LCD_Show_3030_String(270,68,"V",BLACK);
            LCD_ShowNum(160,108,uv_ov_data.uv,3,30,BLACK,WHITE);
            LCD_Show_3030_String(210,108,"V",BLACK);
            LCD_ShowNum(160,148,uv_ov_data.ov,3,30,RED,WHITE);
            LCD_Show_3030_String(210,148,"V",BLACK);
            flag_dev.anchor=3;
        }
    else if(flag_dev.action_flag==UV_OV&&(tp_dev.x[0]>234)&&(tp_dev.x[0]<318)&&(tp_dev.y[0]>110)&&(tp_dev.y[0]<135))
        {
            if(uv_ov_data.uv_state==ON)
                {
                    uv_ov_data.uv_state=OFF;
                    gui_draw_arcrectangle(234,108,85,30,1,1,WHITE,WHITE);
                    LCD_DrawLtrigo(234,110,259,135,LEFT,BLUE);
                    LCD_DrawLtrigo(293,110,318,135,RIGHT,BLUE);
									if(flag_dev.langage==1)
                  	  LCD_Show_3030_String(255,110,"OFF",BLACK);
									else
										ShowChineseChar(265,110,6,24,BLACK);
                } 	
            else if(uv_ov_data.uv_state==OFF)
                {
                    uv_ov_data.uv_state=ON;
                    gui_draw_arcrectangle(234,108,85,30,1,1,WHITE,WHITE);
                    LCD_DrawLtrigo(234,110,259,135,LEFT,BLUE);
                    LCD_DrawLtrigo(293,110,318,135,RIGHT,BLUE);
									if(flag_dev.langage==1)
                  	  LCD_Show_3030_String(260,110,"ON",BLACK);
									else
										ShowChineseChar(265,110,5,24,BLACK);
                } 	
            delay_ms(300);
        }
    else if(flag_dev.action_flag==UV_OV&&(tp_dev.x[0]>234)&&(tp_dev.x[0]<318)&&(tp_dev.y[0]>150)&&(tp_dev.y[0]<175))
        {

            if(uv_ov_data.ov_state==ON)
                {
                    uv_ov_data.ov_state=OFF;
                    gui_draw_arcrectangle(234,148,85,30,1,1,WHITE,WHITE);
                    LCD_DrawLtrigo(234,150,259,175,LEFT,BLUE);
                    LCD_DrawLtrigo(293,150,318,175,RIGHT,BLUE);
									if(flag_dev.langage==1)
                  	  LCD_Show_3030_String(255,150,"OFF",BLACK);
									else
										ShowChineseChar(265,150,6,24,BLACK);
                } 	
            else if(uv_ov_data.ov_state==OFF)
                {
                    uv_ov_data.ov_state=ON;
                    gui_draw_arcrectangle(234,148,85,30,1,1,WHITE,WHITE);
                    LCD_DrawLtrigo(234,150,259,175,LEFT,BLUE);
                    LCD_DrawLtrigo(293,150,318,175,RIGHT,BLUE);
									if(flag_dev.langage==1)
                  	  LCD_Show_3030_String(260,150,"ON",BLACK);									  
									else
										ShowChineseChar(265,150,5,24,BLACK);
                } 	
            delay_ms(300);
        }
}
/*过压欠压函数*/
u8 ISALARM;
void UVOVProtection(u32* Val)
{
    u8 rdval;
    u8  tempval;

    /*高压计算模式*/
    tempval=(*Val)*236/5440;
    /*低压计算模式*/
    if(tempval<150)
        {

            tempval=(*Val)*120/2676;
        }
    /*超过阈值*/
    if(tempval<uv_ov_data.uv)
        {
            /*判断功能状态*/
            if(uv_ov_data.uv_state)
                {
                    ISALARM=1;//超过阈值标志位
                }
        }

    if(uv_ov_data.ov<tempval)
        {
            /*判断功能状态*/
            if(uv_ov_data.ov_state)
                {
                    ISALARM=2;//超过阈值标志位
                }

        }
    if(uv_ov_data.ov_state==OFF&&uv_ov_data.uv_state==OFF)
        {
            ISALARM=0;
        }
    if(ISALARM==1)
        {
            /*回差值满足条件，取消保护功能*/
            if(uv_ov_data.uv_state)
                {
                    if((uv_ov_data.uv+uv_ov_data.rdv)<tempval)
                        {
                            ISALARM=0;
													  relay_key_dev.relay_key_state=RE_KEY_DOWN;//当有警告消除延时打开通道
													 
                        }
                }

        }
    if(ISALARM==2)
        {
            if(uv_ov_data.ov_state)
                {
                    if(tempval<(uv_ov_data.ov-uv_ov_data.rdv))
                        {
                            ISALARM=0;
													  relay_key_dev.relay_key_state=RE_KEY_DOWN;//当有警告消除延时打开通道
                        }
                }
        }

}
