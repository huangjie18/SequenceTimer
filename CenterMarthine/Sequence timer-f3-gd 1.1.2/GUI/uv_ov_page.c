#include "uv_ov_page.h"
#include "lcd.h"
#include "gui.h"
#include  "data.h"
#include "flag.h"
#include "touch.h"
#include "delay.h"

extern  _m_tp_dev tp_dev;//´¥ÆÁ½á¹¹Ìå
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
		LCD_Show_3030_String(130,210,"SAVE",BLUE);
		
    LCD_Show_3030_String(130,5,"PROTECTION",WHITE);
    LCD_Show_3030_String(110,70,"RDV",WHITE);
    LCD_Show_3030_String(110,110,"UV",WHITE);
    LCD_Show_3030_String(110,150,"OV",WHITE);



    LCD_ShowNum(220,68,uv_ov_data.rdv,3,30,BLACK,WHITE);
    LCD_Show_3030_String(270,68,"V",BLACK);
    LCD_ShowNum(160,108,uv_ov_data.uv,3,30,BLACK,WHITE);
    LCD_Show_3030_String(210,108,"V",BLACK);
    LCD_ShowNum(160,148,uv_ov_data.ov,3,30,BLACK,WHITE);
    LCD_Show_3030_String(210,148,"V",BLACK);

    if(uv_ov_data.uv_state==ON)
        {
            LCD_Show_3030_String(260,110,"ON",BLACK);
        }
    else if(uv_ov_data.uv_state==OFF)
        {
            LCD_Show_3030_String(255,110,"OFF",BLACK);
        }
    if(uv_ov_data.ov_state==ON)
        {
            LCD_Show_3030_String(260,150,"ON",BLACK);
        }
    else if(uv_ov_data.ov_state==OFF)
        {
            LCD_Show_3030_String(255,150,"OFF",BLACK);
        }
}


void uv_ov_page_action()
{

    if(flag_dev.action_flag==UV_OV&&(tp_dev.x[0]>172)&&(tp_dev.x[0]<319)&&(tp_dev.y[0]>68)&&(tp_dev.y[0]<98))
        {
            LCD_ShowNum(235,68,uv_ov_data.rdv,2,30,WHITE,RED);
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
            LCD_ShowNum(160,108,uv_ov_data.uv,3,30,WHITE,RED);
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
            LCD_ShowNum(160,148,uv_ov_data.ov,3,30,WHITE,RED);
            LCD_Show_3030_String(210,148,"V",BLACK);
            flag_dev.anchor=3;
        }
    else if(flag_dev.action_flag==UV_OV&&(tp_dev.x[0]>234)&&(tp_dev.x[0]<259)&&(tp_dev.y[0]>110)&&(tp_dev.y[0]<135))
        {
            if(uv_ov_data.uv_state==ON)
                {
                    uv_ov_data.uv_state=OFF;
                    gui_draw_arcrectangle(234,108,85,30,1,1,WHITE,WHITE);
                    LCD_DrawLtrigo(234,110,259,135,LEFT,BLUE);
                    LCD_DrawLtrigo(293,110,318,135,RIGHT,BLUE);
                    LCD_Show_3030_String(255,110,"OFF",BLACK);
                }
        }
    else if(flag_dev.action_flag==UV_OV&&(tp_dev.x[0]>293)&&(tp_dev.x[0]<318)&&(tp_dev.y[0]>110)&&(tp_dev.y[0]<135))
        {
            if(uv_ov_data.uv_state==OFF)
                {
                    uv_ov_data.uv_state=ON;
                    gui_draw_arcrectangle(234,108,85,30,1,1,WHITE,WHITE);
                    LCD_DrawLtrigo(234,110,259,135,LEFT,BLUE);
                    LCD_DrawLtrigo(293,110,318,135,RIGHT,BLUE);
                    LCD_Show_3030_String(260,110,"ON",BLACK);
                }
        }
    else if(flag_dev.action_flag==UV_OV&&(tp_dev.x[0]>234)&&(tp_dev.x[0]<259)&&(tp_dev.y[0]>150)&&(tp_dev.y[0]<175))
        {

            if(uv_ov_data.ov_state==ON)
                {
                    uv_ov_data.ov_state=OFF;
                    gui_draw_arcrectangle(234,148,85,30,1,1,WHITE,WHITE);
                    LCD_DrawLtrigo(234,150,259,175,LEFT,BLUE);
                    LCD_DrawLtrigo(293,150,318,175,RIGHT,BLUE);
                    LCD_Show_3030_String(255,150,"OFF",BLACK);
                }
        }
    else if(flag_dev.action_flag==UV_OV&&(tp_dev.x[0]>293)&&(tp_dev.x[0]<318)&&(tp_dev.y[0]>150)&&(tp_dev.y[0]<175))
        {

            if(uv_ov_data.ov_state==OFF)
                {
                    uv_ov_data.ov_state=ON;
                    gui_draw_arcrectangle(234,148,85,30,1,1,WHITE,WHITE);
                    LCD_DrawLtrigo(234,150,259,175,LEFT,BLUE);
                    LCD_DrawLtrigo(293,150,318,175,RIGHT,BLUE);
                    LCD_Show_3030_String(260,150,"ON",BLACK);
                }
        }
}
