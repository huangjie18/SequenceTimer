#include "main_page.h"
#include "gui.h"
#include "lcd.h"
#include "main_setting_page.h"
#include "flag.h"
#include "touch.h"
#include "delay.h"
#include "key.h"
#include "data.h"
extern _encoder_dev  encoder_dev;
extern  _m_tp_dev tp_dev;//触屏结构体
extern  _flag_dev flag_dev;
extern _chan_data chan_data;
extern _date_time_data date_time_data;
extern _uv_ov_data uv_ov_data;
extern  u32 SECCOUNT;
extern u8 a;
extern _timer_dev chan_dev;
extern u8 ISALARM;
u8 ItemAnchor;
u8 ItemElementAnchor;
void main_page_activity()
{

    gui_draw_arcrectangle(0,0,320,40,1,1,RED,RED);
    gui_draw_arcrectangle(0,43, 90,40,3,1, BLUE,BLUE);
    gui_draw_arcrectangle(0,84, 90,40,3,1, BLUE,BLUE);
    gui_draw_arcrectangle(0,125,90,40,3,1,BLUE,BLUE);
    gui_draw_arcrectangle(0,166,90,41,3,1,BLUE,BLUE);

    gui_draw_arcrectangle(0,209,319,31,1,1,BLUE,BLUE);
    LCD_Show_picture(250,210,WHITE,0);
    LCD_DrawLtrigo(230,215,255,240,LEFT,WHITE);
    LCD_DrawLtrigo(282,215,307,240,RIGHT,WHITE);

    LCD_DrawLtrigo(5,215,30,240,LEFT,WHITE);
    LCD_DrawLtrigo(57,215,82,240,RIGHT,WHITE);

    gui_draw_bline1(91,40,91,207,1,WHITE);
    gui_draw_bline1(3,40,317,40,0,WHITE);
    gui_draw_bline1(3,209,315,209,0,WHITE);
    gui_draw_bline1(3,239,315,239,0,BLUE);

    LCD_Show_3030_String(22,212,"1/3",WHITE);

    if(flag_dev.langage==1)
        LCD_Show_3030_String(30,5,"En",WHITE);
    else
        ShowTwoChineseChar(15,5,34,35,30,WHITE);

    LCD_Show_picture(25,47,WHITE,0);
    if(flag_dev.langage==0)
        {
            ShowTwoChineseChar(15,89,6,2,30,WHITE);
            ShowTwoChineseChar(15,131,4,5,30,WHITE);
            ShowTwoChineseChar(15,171,20,7,30,WHITE);
        }
    else
        {
            LCD_Show_3030_String(10,89,"DELAY",WHITE);
            LCD_Show_3030_String(1, 131,"SWITCH",WHITE);
            LCD_Show_3030_String(15,171,"DATE",WHITE);
        }

//  LCD_Show_3030_String(10,50,"Timer",WHITE);
//	LCD_Show_3030_String(10, 89,"Reset",WHITE);
//  LCD_Show_3030_String(30,131,"IP",WHITE);
//	LCD_Show_3030_String(10,170,"UV&OV",WHITE);
//  LCD_Show_3030_String(25,50,"PWD",WHITE);
//  LCD_Show_3030_String(25,89,"AUZ",WHITE);

    main_setting_page_activity();
}

void main_page_action()
{
    if(flag_dev.lock_sta==L_OPEN)
        {
            if(flag_dev.page_num==1&&(tp_dev.x[0]>0)&&(tp_dev.x[0]<91)&&(tp_dev.y[0]>0)&&(tp_dev.y[0]<40))
                {

                    if(flag_dev.langage==0)
                        {
                            AT24CXX_WriteOneByte(235,1);
                            flag_dev.langage=1;
                        }
                    else
                        {
                            AT24CXX_WriteOneByte(235,0);
                            flag_dev.langage=0;

                        }
                    LCD_Fill(22,212,52,239,BLUE);
                    LCD_Fill(93,42,319,208,BLACK);
                    gui_draw_arcrectangle(94,0,226,40,3,1, RED,RED);
                    LCD_Show_3030_String(22,212,"1/3",WHITE);

                    gui_draw_arcrectangle(0,43, 90,40,3,1, RED,RED);
                    gui_draw_arcrectangle(0,84, 90,40,3,1, BLUE,BLUE);
                    gui_draw_arcrectangle(0,125,90,40,3,1,BLUE,BLUE);
                    gui_draw_arcrectangle(0,166,90,41,3,1,BLUE,BLUE);

                    LCD_Show_picture(25,47,WHITE,0);
                    if(flag_dev.langage==0)
                        {
                            ShowTwoChineseChar(15,89,6,2,30,WHITE);
                            ShowTwoChineseChar(15,131,4,5,30,WHITE);
                            ShowTwoChineseChar(15,171,20,7,30,WHITE);
                        }
                    else
                        {
                            LCD_Show_3030_String(10,89,"DELAY",WHITE);
                            LCD_Show_3030_String(1, 131,"SWITCH",WHITE);
                            LCD_Show_3030_String(15,171,"DATE",WHITE);

                        }
                    gui_draw_arcrectangle(0,0,90,40,1,1,RED,RED);
                    if(flag_dev.langage==1)
                        LCD_Show_3030_String(30,5,"En",WHITE);
                    else
                        ShowTwoChineseChar(15,5,34,35,30,WHITE);
                    flag_dev.screen_flag=HOME;
                    flag_dev.action_flag=HOME;
                    main_setting_page_activity();
                    delay_ms(200);
                    flag_dev.anchor=0;
                }
            if(flag_dev.page_num==2&&(tp_dev.x[0]>0)&&(tp_dev.x[0]<91)&&(tp_dev.y[0]>0)&&(tp_dev.y[0]<40))
                {
                    if(flag_dev.langage==0)
                        {
                            AT24CXX_WriteOneByte(235,1);

                            flag_dev.langage=1;

                        }
                    else
                        {
                            AT24CXX_WriteOneByte(235,0);
                            flag_dev.langage=0;

                        }
                    LCD_Fill(22,212,52,239,BLUE);
                    LCD_Fill(93,42,319,208,BLACK);
                    gui_draw_arcrectangle(94,0,226,40,3,1, RED,RED);
                    LCD_Show_3030_String(22,212,"2/3",WHITE);

                    gui_draw_arcrectangle(0,43, 90,40,3,1, RED,RED);
                    gui_draw_arcrectangle(0,84, 90,40,3,1, BLUE,BLUE);
                    gui_draw_arcrectangle(0,125,90,40,3,1,BLUE,BLUE);
                    gui_draw_arcrectangle(0,166,90,41,3,1,BLUE,BLUE);
                    if(flag_dev.langage==0)
                        {
                            ShowTwoChineseChar(15,50,8,9,30,WHITE);
                            ShowTwoChineseChar(15,89,10,11,30,WHITE);
                            ShowTwoChineseChar(15,131,12,13,30,WHITE);
                            ShowTwoChineseChar(15,171,14,15,30,WHITE);
                        }
                    else
                        {
                            LCD_Show_3030_String(10,50,"TIMER",WHITE);
                            LCD_Show_3030_String(10, 89,"RESET",WHITE);
                            LCD_Show_3030_String(30,131,"IP",WHITE);
                            LCD_Show_3030_String(10,170,"UV&OV",WHITE);
                        }
                    gui_draw_arcrectangle(0,0,90,40,1,1,RED,RED);
                    if(flag_dev.langage==1)
                        LCD_Show_3030_String(30,5,"En",WHITE);
                    else
                        ShowTwoChineseChar(15,5,34,35,30,WHITE);
                    flag_dev.screen_flag=TIMER;
                    flag_dev.action_flag=TIMER;
                    timer_page_activity();
                    flag_dev.anchor=0;
                    delay_ms(200);

                }
            if(flag_dev.page_num==3&&(tp_dev.x[0]>0)&&(tp_dev.x[0]<91)&&(tp_dev.y[0]>0)&&(tp_dev.y[0]<40))
                {

                    if(flag_dev.langage==0)
                        {
                            AT24CXX_WriteOneByte(235,1);

                            flag_dev.langage=1;

                        }
                    else
                        {
                            AT24CXX_WriteOneByte(235,0);
                            flag_dev.langage=0;

                        }
                    LCD_Fill(22,212,52,239,BLUE);
                    LCD_Fill(93,42,319,208,BLACK);
                    gui_draw_arcrectangle(94,0,226,40,3,1, RED,RED);
                    LCD_Show_3030_String(22,212,"3/3",WHITE);
                    flag_dev.page_num=3;
                    flag_dev.screen_flag=PWD;
                    flag_dev.action_flag=PWD;
                    gui_draw_arcrectangle(0,43, 90,40,3,1, RED,RED);
                    if(flag_dev.ISSHOWAUZ==1)
                        gui_draw_arcrectangle(0,84, 90,40,3,1, BLUE,BLUE);
                    else
                        gui_draw_arcrectangle(0,84, 90,40,3,1, BLACK,BLACK);
                    gui_draw_arcrectangle(0,125,90,40,3,1,BLACK,BLACK);
                    gui_draw_arcrectangle(0,166,90,41,3,1,BLACK,BLACK);

                    if(flag_dev.langage==1)
                        LCD_Show_3030_String(25,50,"PWD",WHITE);
                    else
                        ShowTwoChineseChar(15,50,28,29,30,WHITE);

                    if(flag_dev.ISSHOWAUZ==1)
                        {
                            if(flag_dev.langage==1)
                                LCD_Show_3030_String(25,89,"AUZ",WHITE);
                            else
                                ShowTwoChineseChar(15,89,30,31,30,WHITE);
                        }
                    gui_draw_arcrectangle(0,0,90,40,1,1,RED,RED);
                    if(flag_dev.langage==1)
                        LCD_Show_3030_String(30,5,"En",WHITE);
                    else
                        ShowTwoChineseChar(15,5,34,35,30,WHITE);
                    pwd_page_activity();
                    flag_dev.anchor=0;
                    delay_ms(200);
                }
            if(flag_dev.page_num==3&&(tp_dev.x[0]>0)&&(tp_dev.x[0]<91)&&(tp_dev.y[0]>84)&&(tp_dev.y[0]<200))
                {
                    flag_dev.ISMENU=1;
                }
            else
                {
                    flag_dev.ISMENU=0;
                }



            if((tp_dev.x[0]>0)&&(tp_dev.x[0]<86)&&(tp_dev.y[0]>43)&&(tp_dev.y[0]<83))
                {
                    if(flag_dev.page_num==1)
                        {
                            if(flag_dev.screen_flag!=HOME)
                                {
                                    flag_dev.activity_flag=HOME;
                                    flag_dev.action_flag=HOME;
                                    flag_dev.screen_flag=HOME;//不支持长按
                                    flag_dev.anchor=0;
                                }
                        }
                    else if(flag_dev.page_num==2)
                        {
                            if(flag_dev.screen_flag!=TIMER)
                                {
                                    flag_dev.activity_flag=TIMER;
                                    flag_dev.action_flag=TIMER;
                                    flag_dev.screen_flag=TIMER;//不支持长按
                                    flag_dev.anchor=0;
                                }
                        }
                    else if(flag_dev.page_num==3)
                        {
                            if(flag_dev.screen_flag!=PWD)
                                {
                                    flag_dev.activity_flag=PWD;
                                    flag_dev.action_flag=PWD;
                                    flag_dev.screen_flag=PWD;//不支持长按
                                    flag_dev.anchor=0;
                                }
                        }
                }
            else if((tp_dev.x[0]>0)&&(tp_dev.x[0]<86)&&(tp_dev.y[0]>84)&&(tp_dev.y[0]<124))
                {
                    if(flag_dev.page_num==1)
                        {
                            if(flag_dev.screen_flag!=DELAY)
                                {
                                    flag_dev.activity_flag=DELAY;
                                    flag_dev.action_flag=DELAY;
                                    flag_dev.screen_flag=DELAY;//不支持长按
                                    flag_dev.anchor=0;
                                }
                        }
                    else if(flag_dev.page_num==2)
                        {
                            if(flag_dev.screen_flag!=RESET)
                                {
                                    flag_dev.activity_flag=RESET;
                                    flag_dev.action_flag=RESET;
                                    flag_dev.screen_flag=RESET;//不支持长按
                                    flag_dev.anchor=0;
                                }
                        }
                    else if(flag_dev.page_num==3)
                        {
                            if(flag_dev.ISSHOWAUZ==1)
                                {
                                    if(flag_dev.screen_flag!=AUZ)
                                        {
                                            flag_dev.activity_flag=AUZ;
                                            flag_dev.action_flag=AUZ;
                                            flag_dev.screen_flag=AUZ;//不支持长按
                                            flag_dev.anchor=0;
                                        }
                                }
                        }
                }
            else if((tp_dev.x[0]>0)&&(tp_dev.x[0]<86)&&(tp_dev.y[0]>125)&&(tp_dev.y[0]<165))
                {
                    if(flag_dev.page_num==1)
                        {
                            if(flag_dev.screen_flag!=SWITCH)
                                {
                                    flag_dev.activity_flag=SWITCH;
                                    flag_dev.action_flag=SWITCH;
                                    flag_dev.screen_flag=SWITCH;//不支持长按
                                    flag_dev.anchor=0;
                                }
                        }
                    else if(flag_dev.page_num==2)
                        {
                            if(flag_dev.screen_flag!=IP)
                                {
                                    flag_dev.activity_flag=IP;
                                    flag_dev.action_flag=IP;
                                    flag_dev.screen_flag=IP;//不支持长按
                                    flag_dev.anchor=0;
                                }
                        }
                }
            else if((tp_dev.x[0]>0)&&(tp_dev.x[0]<86)&&(tp_dev.y[0]>166)&&(tp_dev.y[0]<206))
                {

                    if(flag_dev.page_num==1)
                        {
                            if(flag_dev.screen_flag!=DATE)
                                {
                                    flag_dev.activity_flag=DATE;
                                    flag_dev.action_flag=DATE;
                                    flag_dev.screen_flag=DATE;//不支持长按
                                    flag_dev.anchor=0;
                                }
                        }
                    else if(flag_dev.page_num==2)
                        {
                            if(flag_dev.screen_flag!=UV_OV)
                                {
                                    flag_dev.activity_flag=UV_OV;
                                    flag_dev.action_flag=UV_OV;
                                    flag_dev.screen_flag=UV_OV;//不支持长按
                                    flag_dev.anchor=0;
                                }

                        }
                }
            else if((tp_dev.x[0]>255)&&(tp_dev.x[0]<285)&&(tp_dev.y[0]>215)&&(tp_dev.y[0]<240))
                {
                    if(flag_dev.screen_flag!=HOME_X)
                        {
                            flag_dev.activity_flag=HOME;
                            flag_dev.action_flag=HOME;
                            flag_dev.anchor=0;
                            flag_dev.screen_flag=HOME_X;//不支持长按，避免与if(flag_dev.screen_flag!=HOME)
                        }

                }
            else if((tp_dev.x[0]>45)&&(tp_dev.x[0]<90)&&(tp_dev.y[0]>215)&&(tp_dev.y[0]<240))
                {
                    if(flag_dev.page_num==1)
                        {
                            LCD_Fill(22,212,52,239,BLUE);
                            LCD_Fill(93,42,319,208,BLACK);
                            gui_draw_arcrectangle(94,0,226,40,3,1, RED,RED);
                            LCD_Show_3030_String(22,212,"2/3",WHITE);

                            gui_draw_arcrectangle(0,43, 90,40,3,1, RED,RED);
                            gui_draw_arcrectangle(0,84, 90,40,3,1, BLUE,BLUE);
                            gui_draw_arcrectangle(0,125,90,40,3,1,BLUE,BLUE);
                            gui_draw_arcrectangle(0,166,90,41,3,1,BLUE,BLUE);
                            if(flag_dev.langage==0)
                                {
                                    ShowTwoChineseChar(15,50,8,9,30,WHITE);
                                    ShowTwoChineseChar(15,89,10,11,30,WHITE);
                                    ShowTwoChineseChar(15,131,12,13,30,WHITE);
                                    ShowTwoChineseChar(15,171,14,15,30,WHITE);
                                }
                            else
                                {
                                    LCD_Show_3030_String(10,50,"TIMER",WHITE);
                                    LCD_Show_3030_String(10, 89,"RESET",WHITE);
                                    LCD_Show_3030_String(30,131,"IP",WHITE);
                                    LCD_Show_3030_String(10,170,"UV&OV",WHITE);
                                }
                            flag_dev.page_num=2;
                            flag_dev.screen_flag=TIMER;
                            flag_dev.action_flag=TIMER;
                            timer_page_activity();
                            flag_dev.anchor=0;

                            delay_ms(200);
                        }
                    else if(flag_dev.page_num==2)
                        {
                            LCD_Fill(22,212,52,239,BLUE);
                            LCD_Fill(93,42,319,208,BLACK);
                            gui_draw_arcrectangle(94,0,226,40,3,1, RED,RED);
                            LCD_Show_3030_String(22,212,"3/3",WHITE);
                            flag_dev.page_num=3;
                            flag_dev.screen_flag=PWD;
                            flag_dev.action_flag=PWD;
                            gui_draw_arcrectangle(0,43, 90,40,3,1, RED,RED);
                            if(flag_dev.ISSHOWAUZ==1)
                                gui_draw_arcrectangle(0,84, 90,40,3,1, BLUE,BLUE);
                            else
                                gui_draw_arcrectangle(0,84, 90,40,3,1, BLACK,BLACK);
                            gui_draw_arcrectangle(0,125,90,40,3,1,BLACK,BLACK);
                            gui_draw_arcrectangle(0,166,90,41,3,1,BLACK,BLACK);

                            if(flag_dev.langage==1)
                                LCD_Show_3030_String(25,50,"PWD",WHITE);
                            else
                                ShowTwoChineseChar(15,50,28,29,30,WHITE);

                            if(flag_dev.ISSHOWAUZ==1)
                                {
                                    if(flag_dev.langage==1)
                                        LCD_Show_3030_String(25,89,"AUZ",WHITE);
                                    else
                                        ShowTwoChineseChar(15,89,30,31,30,WHITE);
                                }
                            pwd_page_activity();
                            flag_dev.anchor=0;
                            delay_ms(200);

                        }
                    else if(flag_dev.page_num==3)
                        {
                            LCD_Fill(22,212,52,239,BLUE);
                            LCD_Fill(93,42,319,208,BLACK);
                            gui_draw_arcrectangle(94,0,226,40,3,1, RED,RED);
                            LCD_Show_3030_String(22,212,"1/3",WHITE);

                            gui_draw_arcrectangle(0,43, 90,40,3,1, RED,RED);
                            gui_draw_arcrectangle(0,84, 90,40,3,1, BLUE,BLUE);
                            gui_draw_arcrectangle(0,125,90,40,3,1,BLUE,BLUE);
                            gui_draw_arcrectangle(0,166,90,41,3,1,BLUE,BLUE);
                            LCD_Show_picture(25,47,WHITE,0);
                            if(flag_dev.langage==0)
                                {
                                    ShowTwoChineseChar(15,89,6,2,30,WHITE);
                                    ShowTwoChineseChar(15,131,4,5,30,WHITE);
                                    ShowTwoChineseChar(15,171,20,7,30,WHITE);
                                }
                            else
                                {
                                    LCD_Show_3030_String(10,89,"DELAY",WHITE);
                                    LCD_Show_3030_String(1, 131,"SWITCH",WHITE);
                                    LCD_Show_3030_String(15,171,"DATE",WHITE);

                                }
                            flag_dev.page_num=1;
                            flag_dev.screen_flag=HOME;
                            flag_dev.action_flag=HOME;
                            flag_dev.anchor=0;
                            main_setting_page_activity();
                            delay_ms(200);
                        }
                }
            else if((tp_dev.x[0]>0)&&(tp_dev.x[0]<45)&&(tp_dev.y[0]>215)&&(tp_dev.y[0]<240))
                {
                    if(flag_dev.page_num==1)
                        {
                            LCD_Fill(22,212,52,239,BLUE);
                            LCD_Fill(93,42,319,208,BLACK);
                            gui_draw_arcrectangle(94,0,226,40,3,1, RED,RED);
                            LCD_Show_3030_String(22,212,"3/3",WHITE);
                            flag_dev.page_num=3;
                            flag_dev.screen_flag=PWD;
                            flag_dev.action_flag=PWD;
                            gui_draw_arcrectangle(0,43, 90,40,3,1, RED,RED);
                            if(flag_dev.ISSHOWAUZ==1)
                                gui_draw_arcrectangle(0,84, 90,40,3,1, BLUE,BLUE);
                            else
                                gui_draw_arcrectangle(0,84, 90,40,3,1, BLACK,BLACK);
                            gui_draw_arcrectangle(0,125,90,40,3,1,BLACK,BLACK);
                            gui_draw_arcrectangle(0,166,90,41,3,1,BLACK,BLACK);
                            if(flag_dev.langage==1)
                                LCD_Show_3030_String(25,50,"PWD",WHITE);
                            else
                                ShowTwoChineseChar(15,50,28,29,30,WHITE);

                            if(flag_dev.ISSHOWAUZ==1)
                                {
                                    if(flag_dev.langage==1)
                                        LCD_Show_3030_String(25,89,"AUZ",WHITE);
                                    else
                                        ShowTwoChineseChar(15,89,30,31,30,WHITE);
                                }
                            pwd_page_activity();
                            delay_ms(200);
                            flag_dev.anchor=0;
                        }
                    else if(flag_dev.page_num==3)
                        {
                            LCD_Fill(22,212,52,239,BLUE);
                            LCD_Fill(93,42,319,208,BLACK);
                            gui_draw_arcrectangle(94,0,226,40,3,1, RED,RED);
                            LCD_Show_3030_String(22,212,"2/3",WHITE);

                            gui_draw_arcrectangle(0,43, 90,40,3,1, RED,RED);
                            gui_draw_arcrectangle(0,84, 90,40,3,1, BLUE,BLUE);
                            gui_draw_arcrectangle(0,125,90,40,3,1,BLUE,BLUE);
                            gui_draw_arcrectangle(0,166,90,41,3,1,BLUE,BLUE);
                            if(flag_dev.langage==0)
                                {
                                    ShowTwoChineseChar(15,50,8,9,30,WHITE);
                                    ShowTwoChineseChar(15,89,10,11,30,WHITE);
                                    ShowTwoChineseChar(15,131,12,13,30,WHITE);
                                    ShowTwoChineseChar(15,171,14,15,30,WHITE);
                                }
                            else
                                {
                                    LCD_Show_3030_String(10,50,"TIMER",WHITE);
                                    LCD_Show_3030_String(10, 89,"RESET",WHITE);
                                    LCD_Show_3030_String(30,131,"IP",WHITE);
                                    LCD_Show_3030_String(10,170,"UV&OV",WHITE);

                                }
                            timer_page_activity();
                            flag_dev.page_num=2;
                            flag_dev.screen_flag=TIMER;
                            flag_dev.action_flag=TIMER;
                            delay_ms(200);
                            flag_dev.anchor=0;
                        }
                    else if(flag_dev.page_num==2)
                        {
                            LCD_Fill(22,212,52,239,BLUE);
                            LCD_Fill(93,42,319,208,BLACK);
                            gui_draw_arcrectangle(94,0,226,40,3,1, RED,RED);
                            LCD_Show_3030_String(22,212,"1/3",WHITE);

                            gui_draw_arcrectangle(0,43, 90,40,3,1, RED,RED);
                            gui_draw_arcrectangle(0,84, 90,40,3,1, BLUE,BLUE);
                            gui_draw_arcrectangle(0,125,90,40,3,1,BLUE,BLUE);
                            gui_draw_arcrectangle(0,166,90,41,3,1,BLUE,BLUE);

                            LCD_Show_picture(25,47,WHITE,0);
                            if(flag_dev.langage==0)
                                {
                                    ShowTwoChineseChar(15,89,6,2,30,WHITE);
                                    ShowTwoChineseChar(15,131,4,5,30,WHITE);
                                    ShowTwoChineseChar(15,171,20,7,30,WHITE);
                                }
                            else
                                {
                                    LCD_Show_3030_String(10,89,"DELAY",WHITE);
                                    LCD_Show_3030_String(1, 131,"SWITCH",WHITE);
                                    LCD_Show_3030_String(15,171,"DATE",WHITE);

                                }
                            flag_dev.page_num=1;
                            flag_dev.screen_flag=HOME;
                            flag_dev.action_flag=HOME;
                            main_setting_page_activity();
                            delay_ms(200);
                            flag_dev.anchor=0;
                        }
                }
        }
    if((tp_dev.x[0]>125)&&(tp_dev.x[0]<195)&&(tp_dev.y[0]>210)&&(tp_dev.y[0]<240))
        {

            flag_dev.save_flag=SAVE;
            flag_dev.anchor=0;
            flag_dev.encodermode=0;
            if(flag_dev.lock_sta==L_OPEN&&flag_dev.action_flag==HOME)
                {
                    flag_dev.save_flag=0;
                    flag_dev.lock_sta=L_CLOSE;
                    gui_draw_arcrectangle(120,210,80,30,4,1,BLUE,BLUE);
                    LCD_Show_picture(150,210,WHITE,1);
                }
        }
}
void main_page_encoder_action()
{
    if(flag_dev.lock_sta==L_OPEN&& flag_dev.anchor==0)
        {
            if(encoder_dev.EN_STATE==TURN_R)
                {
                    encoder_dev.EN_STATE=XNULL;

                    if(flag_dev.page_num==1)
                        {
                            if(flag_dev.action_flag==HOME)
                                {
                                    flag_dev.activity_flag=DELAY;
                                    flag_dev.action_flag=DELAY;
                                    flag_dev.screen_flag=DELAY;//不支持长按
                                    flag_dev.anchor=0;

                                }
                            else if(flag_dev.action_flag==DELAY)
                                {
                                    flag_dev.activity_flag=SWITCH;
                                    flag_dev.action_flag=SWITCH;
                                    flag_dev.screen_flag=SWITCH;//不支持长按
                                    flag_dev.anchor=0;

                                }
                            else if(flag_dev.action_flag==SWITCH)
                                {
                                    flag_dev.activity_flag=DATE;
                                    flag_dev.action_flag=DATE;
                                    flag_dev.screen_flag=DATE;//不支持长按
                                    flag_dev.anchor=0;

                                }
                            else if(flag_dev.action_flag==DATE)
                                {
                                    delay_ms(100);
                                    LCD_Fill(22,212,52,239,BLUE);
                                    LCD_Fill(93,42,319,208,BLACK);
                                    gui_draw_arcrectangle(94,0,226,40,3,1, RED,RED);
                                    LCD_Show_3030_String(22,212,"2/3",WHITE);

                                    gui_draw_arcrectangle(0,43, 90,40,3,1, RED,RED);
                                    gui_draw_arcrectangle(0,84, 90,40,3,1, BLUE,BLUE);
                                    gui_draw_arcrectangle(0,125,90,40,3,1,BLUE,BLUE);
                                    gui_draw_arcrectangle(0,166,90,41,3,1,BLUE,BLUE);

                                    if(flag_dev.langage==1)
                                        {
                                            LCD_Show_3030_String(10,50,"TIMER",WHITE);
                                            LCD_Show_3030_String(10, 89,"RESET",WHITE);
                                            LCD_Show_3030_String(30,131,"IP",WHITE);
                                            LCD_Show_3030_String(10,171,"UV&OV",WHITE);
                                        }
                                    else
                                        {
                                            ShowTwoChineseChar(15,50,8,9,30,WHITE);
                                            ShowTwoChineseChar(15,89,10,11,30,WHITE);
                                            ShowTwoChineseChar(15,131,12,13,30,WHITE);
                                            ShowTwoChineseChar(15,171,14,15,30,WHITE);
                                        }
                                    timer_page_activity();
                                    flag_dev.page_num=2;
                                    flag_dev.screen_flag=TIMER;
                                    flag_dev.action_flag=TIMER;

                                    LCD_DrawLtrigo(57,215,82,240,RIGHT,WHITE);

                                    flag_dev.anchor=0;
                                }
                        }
                    else if(flag_dev.page_num==2)
                        {
                            if(flag_dev.action_flag==TIMER)
                                {
                                    flag_dev.activity_flag=RESET;
                                    flag_dev.action_flag=RESET;
                                    flag_dev.screen_flag=RESET;//不支持长按
                                    flag_dev.anchor=0;

                                }
                            else if(flag_dev.action_flag==RESET)
                                {
                                    flag_dev.activity_flag=IP;
                                    flag_dev.action_flag=IP;
                                    flag_dev.screen_flag=IP;//不支持长按
                                    flag_dev.anchor=0;

                                }
                            else if(flag_dev.action_flag==IP)
                                {
                                    flag_dev.activity_flag=UV_OV;
                                    flag_dev.action_flag=UV_OV;
                                    flag_dev.screen_flag=UV_OV;//不支持长按
                                    flag_dev.anchor=0;

                                }
                            else if(flag_dev.action_flag==UV_OV)
                                {

                                    delay_ms(100);
                                    LCD_Fill(22,212,52,239,BLUE);
                                    LCD_Fill(93,42,319,208,BLACK);
                                    gui_draw_arcrectangle(94,0,226,40,3,1, RED,RED);
                                    LCD_Show_3030_String(22,212,"3/3",WHITE);
                                    flag_dev.page_num=3;
                                    flag_dev.screen_flag=PWD;
                                    flag_dev.action_flag=PWD;
                                    gui_draw_arcrectangle(0,43, 90,40,3,1, RED,RED);
                                    if(flag_dev.ISSHOWAUZ==1)
                                        {
                                            gui_draw_arcrectangle(0,84, 90,40,3,1, BLUE,BLUE);

                                            if(flag_dev.langage)
                                                LCD_Show_3030_String(25,89,"AUZ",WHITE);
                                            else
                                                ShowTwoChineseChar(15,89,30,31,30,WHITE);

                                        }
                                    else
                                        {
                                            gui_draw_arcrectangle(0,84, 90,40,3,1, BLACK,BLACK);
                                        }
                                    gui_draw_arcrectangle(0,125,90,40,3,1,BLACK,BLACK);
                                    gui_draw_arcrectangle(0,166,90,41,3,1,BLACK,BLACK);
                                    if(flag_dev.langage)
                                        LCD_Show_3030_String(25,50,"PWD",WHITE);
                                    else
                                        ShowTwoChineseChar(15,50,28,29,30,WHITE);
                                    pwd_page_activity();
                                    LCD_DrawLtrigo(57,215,82,240,RIGHT,WHITE);

                                    flag_dev.anchor=0;


                                }
                        }
                    else if(flag_dev.page_num==3)
                        {
                            if(flag_dev.action_flag==PWD)
                                {
                                    if(flag_dev.ISSHOWAUZ==1)
                                        {
                                            flag_dev.activity_flag=AUZ;
                                            flag_dev.action_flag=AUZ;
                                            flag_dev.screen_flag=AUZ;//不支持长按
                                            flag_dev.anchor=0;
                                        }
                                    else
                                        {
                                            delay_ms(100);
                                            LCD_Fill(22,212,52,239,BLUE);
                                            LCD_Fill(93,42,319,208,BLACK);
                                            gui_draw_arcrectangle(94,0,226,40,3,1, RED,RED);
                                            LCD_Show_3030_String(22,212,"1/3",WHITE);

                                            gui_draw_arcrectangle(0,43, 90,40,3,1, RED,RED);
                                            gui_draw_arcrectangle(0,84, 90,40,3,1, BLUE,BLUE);
                                            gui_draw_arcrectangle(0,125,90,40,3,1,BLUE,BLUE);
                                            gui_draw_arcrectangle(0,166,90,41,3,1,BLUE,BLUE);

                                            LCD_Show_picture(25,47,WHITE,0);
                                            if(flag_dev.langage==1)
                                                {
                                                    LCD_Show_3030_String(10,89,"DELAY",WHITE);
                                                    LCD_Show_3030_String(1, 131,"SWITCH",WHITE);
                                                    LCD_Show_3030_String(15,171,"DATE",WHITE);
                                                }
                                            else
                                                {
                                                    ShowTwoChineseChar(15,89,6,2,30,WHITE);
                                                    ShowTwoChineseChar(15,131,4,5,30,WHITE);
                                                    ShowTwoChineseChar(15,171,20,7,30,WHITE);
                                                }
                                            main_setting_page_activity();
                                            LCD_DrawLtrigo(57,215,82,240,RIGHT,WHITE);
                                            flag_dev.page_num=1;
                                            flag_dev.screen_flag=HOME;
                                            flag_dev.action_flag=HOME;

                                            flag_dev.anchor=0;

                                        }
                                }
                            else if(flag_dev.action_flag==AUZ)
                                {
                                    delay_ms(100);
                                    LCD_Fill(22,212,52,239,BLUE);
                                    LCD_Fill(93,42,319,208,BLACK);
                                    gui_draw_arcrectangle(94,0,226,40,3,1, RED,RED);
                                    LCD_Show_3030_String(22,212,"1/3",WHITE);

                                    gui_draw_arcrectangle(0,43, 90,40,3,1, RED,RED);
                                    gui_draw_arcrectangle(0,84, 90,40,3,1, BLUE,BLUE);
                                    gui_draw_arcrectangle(0,125,90,40,3,1,BLUE,BLUE);
                                    gui_draw_arcrectangle(0,166,90,41,3,1,BLUE,BLUE);

                                    LCD_Show_picture(25,47,WHITE,0);
                                    if(flag_dev.langage==1)
                                        {
                                            LCD_Show_3030_String(10,89,"DELAY",WHITE);
                                            LCD_Show_3030_String(1, 131,"SWITCH",WHITE);
                                            LCD_Show_3030_String(15,171,"DATE",WHITE);
                                        }
                                    else
                                        {
                                            ShowTwoChineseChar(15,89,6,2,30,WHITE);
                                            ShowTwoChineseChar(15,131,4,5,30,WHITE);
                                            ShowTwoChineseChar(15,171,20,7,30,WHITE);
                                        }
                                    main_setting_page_activity();
                                    LCD_DrawLtrigo(57,215,82,240,RIGHT,WHITE);
                                    flag_dev.page_num=1;
                                    flag_dev.screen_flag=HOME;
                                    flag_dev.action_flag=HOME;

                                    flag_dev.anchor=0;

                                }
                        }



                }
            else if(encoder_dev.EN_STATE==TURN_L)
                {
                    encoder_dev.EN_STATE=XNULL;
                    if(flag_dev.page_num==1)
                        {
                            if(flag_dev.action_flag==HOME)
                                {

                                    delay_ms(100);
                                    LCD_Fill(22,212,52,239,BLUE);
                                    LCD_Fill(93,42,319,208,BLACK);
                                    gui_draw_arcrectangle(94,0,226,40,3,1, RED,RED);
                                    LCD_Show_3030_String(22,212,"3/3",WHITE);
                                    flag_dev.page_num=3;
                                    if(flag_dev.ISSHOWAUZ==1)
                                        {
                                            flag_dev.screen_flag=AUZ;
                                            flag_dev.action_flag=AUZ;
                                            gui_draw_arcrectangle(0,43, 90,40,3,1, BLUE,BLUE);
                                            gui_draw_arcrectangle(0,84, 90,40,3,1, RED,RED);
                                            gui_draw_arcrectangle(0,125,90,40,3,1,BLACK,BLACK);
                                            gui_draw_arcrectangle(0,166,90,41,3,1,BLACK,BLACK);
                                            if(flag_dev.langage==1)
                                                {
                                                    LCD_Show_3030_String(25,50,"PWD",WHITE);
                                                    LCD_Show_3030_String(25,89,"AUZ",WHITE);
                                                }
                                            else
                                                {
                                                    ShowTwoChineseChar(15,50,28,29,30,WHITE);
                                                    ShowTwoChineseChar(15,89,30,31,30,WHITE);
                                                }
                                            auz_page_activity();
                                        }
                                    else
                                        {
                                            flag_dev.screen_flag=PWD;
                                            flag_dev.action_flag=PWD;
                                            gui_draw_arcrectangle(0,43, 90,40,3,1, RED,RED);
                                            gui_draw_arcrectangle(0,84, 90,40,3,1, BLACK,BLACK);
                                            gui_draw_arcrectangle(0,125,90,40,3,1,BLACK,BLACK);
                                            gui_draw_arcrectangle(0,166,90,41,3,1,BLACK,BLACK);
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(25,50,"PWD",WHITE);
                                            else
                                                ShowTwoChineseChar(15,50,28,29,30,WHITE);

                                            pwd_page_activity();
                                        }
                                    LCD_DrawLtrigo(5,215,30,240,LEFT,WHITE);

                                    flag_dev.anchor=0;

                                }
                            else if(flag_dev.action_flag==DATE)
                                {
                                    flag_dev.activity_flag=SWITCH;
                                    flag_dev.action_flag=SWITCH;
                                    flag_dev.screen_flag=SWITCH;//不支持长按
                                    flag_dev.anchor=0;

                                }
                            else if(flag_dev.action_flag==SWITCH)
                                {
                                    flag_dev.activity_flag=DELAY;
                                    flag_dev.action_flag=DELAY;
                                    flag_dev.screen_flag=DELAY;//不支持长按
                                    flag_dev.anchor=0;

                                }
                            else if(flag_dev.action_flag==DELAY)
                                {
                                    flag_dev.activity_flag=HOME;
                                    flag_dev.action_flag=HOME;
                                    flag_dev.screen_flag=HOME;//不支持长按
                                    flag_dev.anchor=0;

                                }
                        }
                    else if(flag_dev.page_num==2)
                        {
                            if(flag_dev.action_flag==TIMER)
                                {
//                                    gui_draw_arcrectangle(0,43,90,40,3,1, BLUE,BLUE);
//                                    LCD_Show_3030_String(10,50,"TIMER",WHITE);
//                                    LCD_DrawLtrigo(5,215,30,240,LEFT,WHITE);
//
                                    delay_ms(100);
                                    LCD_Fill(22,212,52,239,BLUE);
                                    LCD_Fill(93,42,319,208,BLACK);
                                    gui_draw_arcrectangle(94,0,226,40,3,1, RED,RED);
                                    LCD_Show_3030_String(22,212,"1/3",WHITE);

                                    gui_draw_arcrectangle(0,43, 90,40,3,1, BLUE,BLUE);
                                    gui_draw_arcrectangle(0,84, 90,40,3,1, BLUE,BLUE);
                                    gui_draw_arcrectangle(0,125,90,40,3,1,BLUE,BLUE);
                                    gui_draw_arcrectangle(0,166,90,41,3,1,RED,RED);

                                    LCD_Show_picture(25,47,WHITE,0);
                                    if(flag_dev.langage==1)
                                        {
                                            LCD_Show_3030_String(10,89,"DELAY",WHITE);
                                            LCD_Show_3030_String(1, 131,"SWITCH",WHITE);
                                            LCD_Show_3030_String(15,171,"DATE",WHITE);
                                        }
                                    else
                                        {
                                            ShowTwoChineseChar(15,89,6,2,30,WHITE);
                                            ShowTwoChineseChar(15,131,4,5,30,WHITE);
                                            ShowTwoChineseChar(15,171,20,7,30,WHITE);
                                        }
                                    date_setting_page_activity();
                                    LCD_DrawLtrigo(5,215,30,240,LEFT,WHITE);
                                    flag_dev.page_num=1;
                                    flag_dev.screen_flag=DATE;
                                    flag_dev.action_flag=DATE;

                                    flag_dev.anchor=0;

                                }
                            else if(flag_dev.action_flag==UV_OV)
                                {
                                    flag_dev.activity_flag=IP;
                                    flag_dev.action_flag=IP;
                                    flag_dev.screen_flag=IP;//不支持长按
                                    flag_dev.anchor=0;

                                }
                            else if(flag_dev.action_flag==IP)
                                {
                                    flag_dev.activity_flag=RESET;
                                    flag_dev.action_flag=RESET;
                                    flag_dev.screen_flag=RESET;//不支持长按
                                    flag_dev.anchor=0;

                                }
                            else if(flag_dev.action_flag==RESET)
                                {
                                    flag_dev.activity_flag=TIMER;
                                    flag_dev.action_flag=TIMER;
                                    flag_dev.screen_flag=TIMER;//不支持长按
                                    flag_dev.anchor=0;

                                }
                        }
                    else if(flag_dev.page_num==3)
                        {
                            if(flag_dev.action_flag==PWD)
                                {
//                                    gui_draw_arcrectangle(0,43, 90,40,3,1, BLUE,BLUE);
//                                    LCD_Show_3030_String(25,50,"PWD",WHITE);
//                                    LCD_DrawLtrigo(5,215,30,240,LEFT,WHITE);

                                    delay_ms(100);
                                    LCD_Fill(22,212,52,239,BLUE);
                                    LCD_Fill(93,42,319,208,BLACK);
                                    gui_draw_arcrectangle(94,0,226,40,3,1, RED,RED);
                                    LCD_Show_3030_String(22,212,"2/3",WHITE);
                                    gui_draw_arcrectangle(0,43, 90,40,3,1, BLUE,BLUE);
                                    gui_draw_arcrectangle(0,84, 90,40,3,1, BLUE,BLUE);
                                    gui_draw_arcrectangle(0,125,90,40,3,1,BLUE,BLUE);
                                    gui_draw_arcrectangle(0,166,90,41,3,1,RED,RED);
                                    if(flag_dev.langage==1)
                                        {
                                            LCD_Show_3030_String(10,50,"TIMER",WHITE);
                                            LCD_Show_3030_String(10, 89,"RESET",WHITE);
                                            LCD_Show_3030_String(30,131,"IP",WHITE);
                                            LCD_Show_3030_String(10,171,"UV&OV",WHITE);
                                        }
                                    else
                                        {
                                            ShowTwoChineseChar(15,50,8,9,30,WHITE);
                                            ShowTwoChineseChar(15,89,10,11,30,WHITE);
                                            ShowTwoChineseChar(15,131,12,13,30,WHITE);
                                            ShowTwoChineseChar(15,171,14,15,30,WHITE);
                                        }
                                    uv_ov_page_activity();
                                    LCD_DrawLtrigo(5,215,30,240,LEFT,WHITE);
                                    flag_dev.page_num=2;
                                    flag_dev.screen_flag=UV_OV;
                                    flag_dev.action_flag=UV_OV;
                                    flag_dev.anchor=0;
                                }
                            else if(flag_dev.action_flag==AUZ)
                                {
                                    flag_dev.activity_flag=PWD;
                                    flag_dev.action_flag=PWD;
                                    flag_dev.screen_flag=PWD;//不支持长按
                                    flag_dev.anchor=0;
                                }
                        }


                }

        }

    //数字加减

    if(flag_dev.anchor!=0)
        {
            if(encoder_dev.EN_STATE==TURN_L||encoder_dev.EN_STATE==SUBLEFT)
                {
                    encoder_dev.EN_STATE=XNULL;
                    flag_dev.screen_key=LEFT;
                }
            else if(encoder_dev.EN_STATE==TURN_R||encoder_dev.EN_STATE==SUBRIGHT)
                {
                    encoder_dev.EN_STATE=XNULL;
                    flag_dev.screen_key=RIGHT;
                }


        }

}
/*编码器操作全部界面函数*/
u8 Lastaction;
u8 SubAnchor;//子页面游标
void EncoderToAll()
{
    static u8 lastmode=0;
    if(flag_dev.action_flag!=Lastaction)
        {
            if(flag_dev.action_flag!=KEY_BOARD)
                {
                    SubAnchor=0;
                    flag_dev.TOSUBPAGE=0;
                    ItemAnchor=0;
                    ItemElementAnchor=0;
                    Lastaction=flag_dev.action_flag;
                }
            else
                {
                    Lastaction=flag_dev.action_flag;
                    flag_dev.TOSUBPAGE=1;
                }
            LCD_DrawLtrigo(230,215,255,240,LEFT,WHITE);
            LCD_Show_picture(250,210,WHITE,0);
            LCD_DrawLtrigo(282,215,307,240,RIGHT,WHITE);

        }

    if(encoder_dev.EN_KEY==EN_KEY_DOWN)
        {
            flag_dev.TOSUBPAGE=1;
        }
    if(encoder_dev.EN_KEY==EN_KEY_DOWN&&flag_dev.anchor!=0&&SubAnchor==0)
        {
            flag_dev.anchor=0;
        }

    if(lastmode!=chan_dev.mode)
        {
            ItemAnchor=0;
            ItemElementAnchor=0;
            lastmode=chan_dev.mode;
        }
    /*---------HOME----------------*/
    EncoderMain(&SubAnchor);
    EncoderDelay(&SubAnchor);
    EncoderSwitch(&SubAnchor);
    EncoderDate(&SubAnchor);
    EncoderReset(&SubAnchor);
    EncoderIP(&SubAnchor);
    EncoderUVOV(&SubAnchor);
    EncoderPWD(&SubAnchor);
    EncoderAUZ(&SubAnchor);
    EncoderKeyboard(&SubAnchor);
    EncoderTimer(&SubAnchor);
    EncoderTimerSub();
}
void EncoderChanState(u8* SubAnchor)
{

    if(EnCH1&&(*SubAnchor)!=1)
        {
            LCD_Show_4848_String(109,104,"1",RED);
        }
    else
        {
            LCD_Show_4848_String(109,104,"1",WHITE);
        }
    if(ReadCH2&&(*SubAnchor)!=2)
        {
            LCD_Show_4848_String(167,104,"2",RED);
        }
    else
        {
            LCD_Show_4848_String(167,104,"2",WHITE);
        }
    if(ReadCH3&&(*SubAnchor)!=3)
        {
            LCD_Show_4848_String(223,104,"3",RED);
        }
    else
        {
            LCD_Show_4848_String(223,104,"3",WHITE);
        }
    if(ReadCH4&&(*SubAnchor)!=4)
        {
            LCD_Show_4848_String(279,104,"4",RED);
        }
    else
        {
            LCD_Show_4848_String(279,104,"4",WHITE);
        }
    if(ReadCH5&&(*SubAnchor)!=5)
        {
            LCD_Show_4848_String(109,156,"5",RED);
        }
    else
        {
            LCD_Show_4848_String(109,156,"5",WHITE);
        }
    if(ReadCH6&&(*SubAnchor)!=6)
        {
            LCD_Show_4848_String(167,156,"6",RED);
        }
    else
        {
            LCD_Show_4848_String(167,156,"6",WHITE);
        }
    if(ReadCH7&&(*SubAnchor)!=7)
        {
            LCD_Show_4848_String(223,156,"7",RED);
        }
    else
        {
            LCD_Show_4848_String(223,156,"7",WHITE);
        }
    if(ReadCH8&&(*SubAnchor)!=8)
        {
            LCD_Show_4848_String(279,156,"8",RED);
        }
    else
        {
            LCD_Show_4848_String(279,156,"8",WHITE);
        }
}
void EncoderMain(u8* SubAnchor)
{
    if(flag_dev.action_flag==HOME)
        {
            if(encoder_dev.EN_STATE==SUBRIGHT)
                {

                    switch(*SubAnchor)
                        {
                        case 0x00:
                            gui_draw_arcrectangle(94,104, 55,50,3,1, RED,RED);
                            gui_draw_arcrectangle(151,104, 55,50,3,1, GRAY,GRAY);


                            *SubAnchor=1;
                            break;
                        case 0x01:
                            gui_draw_arcrectangle(94,104, 55,50,3,1, GRAY,GRAY);
                            gui_draw_arcrectangle(151,104, 55,50,3,1, RED,RED);
                            *SubAnchor=2;

                            break;
                        case 0x02:
                            gui_draw_arcrectangle(151,104, 55,50,3,1, GRAY,GRAY);
                            gui_draw_arcrectangle(208,104, 55,50,3,1, RED,RED);
                            *SubAnchor=3;
                            break;
                        case 0x03:
                            gui_draw_arcrectangle(208,104, 55,50,3,1, GRAY,GRAY);
                            gui_draw_arcrectangle(265,104, 55,50,3,1, RED,RED);
                            *SubAnchor=4;
                            break;
                        case 0x04:
                            gui_draw_arcrectangle(265,104, 55,50,3,1, GRAY,GRAY);
                            gui_draw_arcrectangle(94,156,55,50,3,1,RED,RED);
                            *SubAnchor=5;
                            break;
                        case 0x05:
                            gui_draw_arcrectangle(94,156,55,50,3,1,GRAY,GRAY);
                            gui_draw_arcrectangle(151,156,55,50,3,1,RED,RED);
                            *SubAnchor=6;
                            break;
                        case 0x06:
                            gui_draw_arcrectangle(151,156,55,50,3,1,GRAY,GRAY);
                            gui_draw_arcrectangle(208,156,55,50,3,1,RED,RED);

                            *SubAnchor=7;
                            break;
                        case 0x07:
                            gui_draw_arcrectangle(208,156,55,50,3,1,GRAY,GRAY);
                            gui_draw_arcrectangle(265,156,55,50,3,1,RED,RED);
                            *SubAnchor=8;
                            break;
                        case 0x08:
                            gui_draw_arcrectangle(265,156,55,50,3,1,GRAY,GRAY);
                            if(flag_dev.lock_sta==L_CLOSE)
                                {
                                    gui_draw_arcrectangle(120,210,80,30,4,1,BLUE,BLUE);
                                    LCD_Show_picture(150,210,RED,1);
                                }
                            else
                                {
                                    gui_draw_arcrectangle(120,210,80,30,4,1,BLUE,BLUE);
                                    LCD_Show_picture(150,210,RED,2);
                                }
                            *SubAnchor=9;
                            break;
                        case 0x09:
                            if(flag_dev.lock_sta==L_CLOSE)
                                {
                                    gui_draw_arcrectangle(120,210,80,30,4,1,BLUE,BLUE);
                                    LCD_Show_picture(150,210,WHITE,1);
                                }
                            else
                                {
                                    gui_draw_arcrectangle(120,210,80,30,4,1,BLUE,BLUE);
                                    LCD_Show_picture(150,210,WHITE,2);
                                }
                            LCD_Show_picture(250,210,RED,0);
                            LCD_DrawLtrigo(230,215,255,240,LEFT,WHITE);
                            LCD_DrawLtrigo(282,215,307,240,RIGHT,WHITE);
                            *SubAnchor=10;
                            break;
                        }
                    EncoderChanState(SubAnchor);
                }
            else if(encoder_dev.EN_STATE==SUBLEFT)
                {
                    switch(*SubAnchor)
                        {
                        case 0x0A:
                            LCD_DrawLtrigo(230,215,255,240,LEFT,WHITE);
                            LCD_DrawLtrigo(282,215,307,240,RIGHT,WHITE);
                            if(flag_dev.lock_sta==L_CLOSE)
                                {
                                    gui_draw_arcrectangle(120,210,80,30,4,1,BLUE,BLUE);
                                    LCD_Show_picture(150,210,RED,1);
                                }
                            else
                                {
                                    gui_draw_arcrectangle(120,210,80,30,4,1,BLUE,BLUE);
                                    LCD_Show_picture(150,210,RED,2);
                                }
                            LCD_Show_picture(250,210,WHITE,0);
                            *SubAnchor=9;
                            break;
                        case 0x09:
                            gui_draw_arcrectangle(265,156,55,50,3,1,RED,RED);

                            if(flag_dev.lock_sta==L_CLOSE)
                                {
                                    gui_draw_arcrectangle(120,210,80,30,4,1,BLUE,BLUE);
                                    LCD_Show_picture(150,210,WHITE,1);
                                }
                            else
                                {
                                    gui_draw_arcrectangle(120,210,80,30,4,1,BLUE,BLUE);
                                    LCD_Show_picture(150,210,WHITE,2);
                                }
                            *SubAnchor=8;
                            break;
                        case 0x08:
                            gui_draw_arcrectangle(208,156,55,50,3,1,RED,RED);
                            gui_draw_arcrectangle(265,156,55,50,3,1,GRAY,GRAY);
                            *SubAnchor=0x07;
                            break;
                        case 0x07:
                            gui_draw_arcrectangle(151,156,55,50,3,1,RED,RED);
                            gui_draw_arcrectangle(208,156,55,50,3,1,GRAY,GRAY);
                            *SubAnchor=0x06;
                            break;
                        case 0x06:
                            gui_draw_arcrectangle(94,156,55,50,3,1,RED,RED);
                            gui_draw_arcrectangle(151,156,55,50,3,1,GRAY,GRAY);
                            *SubAnchor=0x05;
                            break;
                        case 0x05:
                            gui_draw_arcrectangle(265,104, 55,50,3,1, RED,RED);
                            gui_draw_arcrectangle(94,156,55,50,3,1,GRAY,GRAY);
                            *SubAnchor=0x04;
                            break;
                        case 0x04:
                            gui_draw_arcrectangle(208,104, 55,50,3,1, RED,RED);
                            gui_draw_arcrectangle(265,104, 55,50,3,1, GRAY,GRAY);
                            *SubAnchor=0x03;
                            break;
                        case 0x03:
                            gui_draw_arcrectangle(151,104, 55,50,3,1, RED,RED);
                            gui_draw_arcrectangle(208,104, 55,50,3,1, GRAY,GRAY);
                            *SubAnchor=0x02;
                            break;
                        case 0x02:
                            gui_draw_arcrectangle(94,104, 55,50,3,1, RED,RED);
                            gui_draw_arcrectangle(151,104, 55,50,3,1, GRAY,GRAY);
                            *SubAnchor=0x01;
                            break;

                        }
                    EncoderChanState(SubAnchor);
                }

        }
    if(flag_dev.action_flag==HOME&&encoder_dev.EN_KEY==EN_KEY_DOWN)
        {

            switch(*SubAnchor)
                {
                case 0x01:

                    if(ReadCH1)
                        {
                            ResetCH1
                        }
                    else
                        {
                            if(EnCH1&&ISALARM==0&&flag_dev.lock_sta==L_OPEN)
                                SetCH1
                        }
                    break;
                case 0x02:
                    if(ReadCH2)
                        {
                            ResetCH2
                        }
                    else
                        {
                            if(EnCH2&&ISALARM==0&&flag_dev.lock_sta==L_OPEN)
                               SetCH2
                        }
                    break;
                case 0x03:
                    if(ReadCH3)
                        {
                            ResetCH3
                        }
                    else
                        {
                            if(EnCH3&&ISALARM==0&&flag_dev.lock_sta==L_OPEN)
                                SetCH3
                        }
                    break;
                case 0x04:
                    if(ReadCH4)
                        {
                            ResetCH4
                        }
                    else
                        {
                            if(EnCH4&&ISALARM==0&&flag_dev.lock_sta==L_OPEN)
                               SetCH4
                        }
                    break;
                case 0x05:
                    if(ReadCH5)
                        {
                            ResetCH5
                        }
                    else
                        {
                            if(EnCH5&&ISALARM==0&&flag_dev.lock_sta==L_OPEN)
                                ResetCH5
                        }
                    break;
                case 0x06:
                    if(ReadCH6)
                        {
                            ResetCH6
                        }
                    else
                        {
                            if(EnCH6&&ISALARM==0&&flag_dev.lock_sta==L_OPEN)
                               SetCH6
                        }
                    break;
                case 0x07:
                    if(ReadCH7)
                        {
                            ResetCH7
                        }
                    else
                        {
                            if(EnCH7&&ISALARM==0&&flag_dev.lock_sta==L_OPEN)
                               SetCH7
                        }
                    break;
                case 0x08:
                    if(ReadCH8)
                        {
                            ResetCH8
                        }
                    else
                        {
                            if(EnCH8&&ISALARM==0&&flag_dev.lock_sta==L_OPEN)
                                SetCH8
                        }
                    break;
                case 0x09:
                    flag_dev.save_flag=SAVE;
                    if(flag_dev.lock_sta==L_OPEN&&flag_dev.action_flag==HOME)
                        {
                            flag_dev.save_flag=0;
                            flag_dev.lock_sta=L_CLOSE;
                            gui_draw_arcrectangle(120,210,80,30,4,1,BLUE,BLUE);
                            LCD_Show_picture(150,210,WHITE,1);
                            flag_dev.TOSUBPAGE=0;
                            *SubAnchor=0;
                        }

                    break;
                case 0x0A:
                    flag_dev.TOSUBPAGE=0;
                    *SubAnchor=0;
                    LCD_Show_picture(250,210,WHITE,0);

                    break;
                }
        }

}

void EncoderDelay(u8* SubAnchor)
{
    if(flag_dev.action_flag==DELAY)
        {

            if(encoder_dev.EN_STATE==SUBRIGHT)
                {



                    switch(*SubAnchor)
                        {
                        case 0x00:
                            gui_draw_arcrectangle(94,43,226,40,4,1,RED,RED);
                            gui_draw_arcrectangle(172,48, 145,30,4,1,WHITE,WHITE);
                            if(flag_dev.activity_num==1||flag_dev.activity_num==3)
                                {
                                    if(flag_dev.langage==1)
                                        {
                                            LCD_Show_2424_String(100,50,"CHAN1",WHITE);
                                        }
                                    else
                                        {
                                            ShowTwoChineseChar(100,50,0,1,24,WHITE);
                                            LCD_Show_2424_String(148,50,"1",WHITE);
                                        }

                                }
                            else if(flag_dev.activity_num==2||flag_dev.activity_num==4)
                                {
                                    if(flag_dev.langage==1)
                                        {
                                            LCD_Show_2424_String(100,50,"CHAN5",WHITE);
                                        }
                                    else
                                        {
                                            ShowTwoChineseChar(100,50,0,1,24,WHITE);
                                            LCD_Show_2424_String(148,50,"5",WHITE);
                                        }

                                }

                            LCD_ShowNum(220,48,chan_data.data1,3,30,BLACK,WHITE);
                            LCD_Show_3030_String(265,48,"s",BLACK);
                            *SubAnchor=0x01;
                            break;
                        case 0x01:
                            gui_draw_arcrectangle(94,43,226,40,4,1,BLUE,BLUE);
                            gui_draw_arcrectangle(94,85,226,40,4,1,RED,RED);
                            gui_draw_arcrectangle(172,48, 145,30,4,1,WHITE,WHITE);
                            gui_draw_arcrectangle(172,90, 145,30,4,1,WHITE,WHITE);
                            if(flag_dev.activity_num==1||flag_dev.activity_num==3)
                                {
                                    if(flag_dev.langage==1)
                                        {
                                            LCD_Show_2424_String(100,50,"CHAN1",WHITE);
                                            LCD_Show_2424_String(100,92,"CHAN2",WHITE);
                                        }
                                    else
                                        {
                                            ShowTwoChineseChar(100,50,0,1,24,WHITE);
                                            LCD_Show_2424_String(148,50,"1",WHITE);
                                            ShowTwoChineseChar(100,92,0,1,24,WHITE);
                                            LCD_Show_2424_String(148,92,"2",WHITE);
                                        }
                                }
                            else if(flag_dev.activity_num==2||flag_dev.activity_num==4)
                                {
                                    if(flag_dev.langage==1)
                                        {
                                            LCD_Show_2424_String(100,50,"CHAN5",WHITE);
                                            LCD_Show_2424_String(100,92,"CHAN6",WHITE);
                                        }
                                    else
                                        {
                                            ShowTwoChineseChar(100,50,0,1,24,WHITE);
                                            LCD_Show_2424_String(148,50,"5",WHITE);
                                            ShowTwoChineseChar(100,92,0,1,24,WHITE);
                                            LCD_Show_2424_String(148,92,"6",WHITE);
                                        }

                                }
                            LCD_ShowNum(220,48,chan_data.data1,3,30,BLACK,WHITE);
                            LCD_Show_3030_String(265,48,"s",BLACK);
                            LCD_ShowNum(220,90,chan_data.data2,3,30,BLACK,WHITE);
                            LCD_Show_3030_String(265,90,"s",BLACK);
                            *SubAnchor=0x02;
                            break;
                        case 0x02:
                            gui_draw_arcrectangle(94,85,226,40,4,1,BLUE,BLUE);
                            gui_draw_arcrectangle(94,127,226,40,4,1,RED,RED);
                            gui_draw_arcrectangle(172,90, 145,30,4,1,WHITE,WHITE);
                            gui_draw_arcrectangle(172,131,145,30,4,1,WHITE,WHITE);
                            if(flag_dev.activity_num==3||flag_dev.activity_num==1)
                                {
                                    if(flag_dev.langage==1)
                                        {
                                            LCD_Show_2424_String(100,92,"CHAN2",WHITE);
                                            LCD_Show_2424_String(100,133,"CHAN3",WHITE);
                                        }
                                    else
                                        {
                                            ShowTwoChineseChar(100,92,0,1,24,WHITE);
                                            LCD_Show_2424_String(148,92,"2",WHITE);
                                            ShowTwoChineseChar(100,133,0,1,24,WHITE);
                                            LCD_Show_2424_String(148,133,"3",WHITE);
                                        }

                                }
                            else if(flag_dev.activity_num==2||flag_dev.activity_num==4)
                                {
                                    if(flag_dev.langage==1)
                                        {
                                            LCD_Show_2424_String(100,92,"CHAN6",WHITE);
                                            LCD_Show_2424_String(100,133,"CHAN7",WHITE);
                                        }
                                    else
                                        {
                                            ShowTwoChineseChar(100,92,0,1,24,WHITE);
                                            LCD_Show_2424_String(148,92,"6",WHITE);
                                            ShowTwoChineseChar(100,133,0,1,24,WHITE);
                                            LCD_Show_2424_String(148,133,"7",WHITE);
                                        }
                                }
                            LCD_ShowNum(220,90,chan_data.data2,3,30,BLACK,WHITE);
                            LCD_Show_3030_String(265,90,"s",BLACK);
                            LCD_ShowNum(220,131,chan_data.data3,3,30,BLACK,WHITE);
                            LCD_Show_3030_String(265,131,"s",BLACK);
                            *SubAnchor=0x03;
                            break;
                        case 0x03:

                            gui_draw_arcrectangle(94,127,226,40,4,1,BLUE,BLUE);
                            gui_draw_arcrectangle(94,169,226,38,4,1,RED,RED);
                            gui_draw_arcrectangle(172,131,145,30,4,1,WHITE,WHITE);
                            gui_draw_arcrectangle(172,173,145,30,4,1,WHITE,WHITE);
                            if(flag_dev.activity_num==1||flag_dev.activity_num==3)
                                {
                                    if(flag_dev.langage==1)
                                        {
                                            LCD_Show_2424_String(100,133,"CHAN3",WHITE);
                                            LCD_Show_2424_String(100,175,"CHAN4",WHITE);
                                        }
                                    else
                                        {
                                            ShowTwoChineseChar(100,133,0,1,24,WHITE);
                                            LCD_Show_2424_String(148,133,"3",WHITE);
                                            ShowTwoChineseChar(100,175,0,1,24,WHITE);
                                            LCD_Show_2424_String(148,175,"4",WHITE);
                                        }

                                }
                            else if(flag_dev.activity_num==2||flag_dev.activity_num==4)
                                {
                                    if(flag_dev.langage==1)
                                        {
                                            LCD_Show_2424_String(100,133,"CHAN7",WHITE);
                                            LCD_Show_2424_String(100,175,"CHAN8",WHITE);
                                        }
                                    else
                                        {
                                            ShowTwoChineseChar(100,133,0,1,24,WHITE);
                                            LCD_Show_2424_String(148,133,"7",WHITE);
                                            ShowTwoChineseChar(100,175,0,1,24,WHITE);
                                            LCD_Show_2424_String(148,175,"8",WHITE);
                                        }
                                }
                            LCD_ShowNum(220,131,chan_data.data3,3,30,BLACK,WHITE);
                            LCD_Show_3030_String(265,131,"s",BLACK);
                            LCD_ShowNum(220,173,chan_data.data4,3,30,BLACK,WHITE);
                            LCD_Show_3030_String(265,173,"s",BLACK);
                            *SubAnchor=0x04;
                            break;
                        case 0x04:
                            gui_draw_arcrectangle(94,169,226,38,4,1,BLUE,BLUE);
                            gui_draw_arcrectangle(172,173,145,30,4,1,WHITE,WHITE);
                            if(flag_dev.activity_num==1||flag_dev.activity_num==3)
                                {
                                    if(flag_dev.langage==1)
                                        LCD_Show_2424_String(100,175,"CHAN4",WHITE);
                                    else
                                        {
                                            ShowTwoChineseChar(100,175,0,1,24,WHITE);
                                            LCD_Show_2424_String(148,175,"4",WHITE);
                                        }
                                }
                            else if(flag_dev.activity_num==2||flag_dev.activity_num==4)
                                {
                                    if(flag_dev.langage==1)
                                        LCD_Show_2424_String(100,175,"CHAN8",WHITE);
                                    else
                                        {
                                            ShowTwoChineseChar(100,175,0,1,24,WHITE);
                                            LCD_Show_2424_String(148,175,"8",WHITE);
                                        }
                                }
                            LCD_ShowNum(220,173,chan_data.data4,3,30,BLACK,WHITE);
                            LCD_Show_3030_String(265,173,"s",BLACK);

                            gui_draw_arcrectangle(120,210,80,30,1,1,BLUE,BLUE);
                            gui_draw_arcrectangle(125,212,70,28,1,1,RED,RED);
                            if(flag_dev.langage==1)
                                {
                                    LCD_Show_3030_String(130,210,"SAVE",WHITE);
                                }
                            else
                                {
                                    ShowTwoChineseChar(135,213,10,11,24,WHITE);
                                }
                            *SubAnchor=0x05;
                            break;
                        case 0x05:

                            gui_draw_arcrectangle(120,210,80,30,1,1,BLUE,BLUE);
                            gui_draw_arcrectangle(125,212,70,28,1,1,WHITE,WHITE);
                            if(flag_dev.langage==1)
                                LCD_Show_3030_String(130,210,"SAVE",BLACK);
                            else
                                ShowTwoChineseChar(135,213,10,11,24,BLACK);


                            LCD_DrawLtrigo(230,215,255,240,LEFT,RED);
                            LCD_DrawLtrigo(282,215,307,240,RIGHT,WHITE);
                            LCD_Show_picture(250,210,WHITE,0);
                            *SubAnchor=0x06;
                            break;
                        case 0x06:
                            LCD_DrawLtrigo(230,215,255,240,LEFT,WHITE);
                            LCD_Show_picture(250,210,RED,0);
                            *SubAnchor=0x07;
                            break;
                        case 0x07:
                            LCD_Show_picture(250,210,WHITE,0);
                            LCD_DrawLtrigo(282,215,307,240,RIGHT,RED);
                            *SubAnchor=0x08;
                            break;
                        }
                }
            else if(encoder_dev.EN_STATE==SUBLEFT)
                {


                    switch(*SubAnchor)
                        {
                        case 0x02:
                            gui_draw_arcrectangle(94,43,226,40,4,1,RED,RED);
                            gui_draw_arcrectangle(94,85,226,40,4,1,BLUE,BLUE);
                            gui_draw_arcrectangle(172,48, 145,30,4,1,WHITE,WHITE);
                            gui_draw_arcrectangle(172,90, 145,30,4,1,WHITE,WHITE);
                            if(flag_dev.activity_num==1||flag_dev.activity_num==3)
                                {
                                    if(flag_dev.langage==1)
                                        {
                                            LCD_Show_2424_String(100,50,"CHAN1",WHITE);
                                            LCD_Show_2424_String(100,92,"CHAN2",WHITE);
                                        }
                                    else
                                        {

                                            ShowTwoChineseChar(100,50,0,1,24,WHITE);
                                            LCD_Show_2424_String(148,50,"1",WHITE);
                                            ShowTwoChineseChar(100,92,0,1,24,WHITE);
                                            LCD_Show_2424_String(148,92,"2",WHITE);
                                        }
                                }
                            else if(flag_dev.activity_num==2||flag_dev.activity_num==4)
                                {
                                    if(flag_dev.langage==1)
                                        {
                                            LCD_Show_2424_String(100,50,"CHAN5",WHITE);
                                            LCD_Show_2424_String(100,92,"CHAN6",WHITE);
                                        }
                                    else
                                        {
                                            ShowTwoChineseChar(100,50,0,1,24,WHITE);
                                            LCD_Show_2424_String(148,50,"5",WHITE);
                                            ShowTwoChineseChar(100,92,0,1,24,WHITE);
                                            LCD_Show_2424_String(148,92,"6",WHITE);
                                        }
                                }
                            LCD_ShowNum(220,48,chan_data.data1,3,30,BLACK,WHITE);
                            LCD_Show_3030_String(265,48,"s",BLACK);
                            LCD_ShowNum(220,90,chan_data.data2,3,30,BLACK,WHITE);
                            LCD_Show_3030_String(265,90,"s",BLACK);
                            *SubAnchor=0x01;
                            break;
                        case 0x03:
                            gui_draw_arcrectangle(94,85,226,40,4,1,RED,RED);
                            gui_draw_arcrectangle(94,127,226,40,4,1,BLUE,BLUE);
                            gui_draw_arcrectangle(172,90, 145,30,4,1,WHITE,WHITE);
                            gui_draw_arcrectangle(172,131,145,30,4,1,WHITE,WHITE);
                            if(flag_dev.activity_num==3||flag_dev.activity_num==1)
                                {
                                    if(flag_dev.langage==1)
                                        {
                                            LCD_Show_2424_String(100,92,"CHAN2",WHITE);
                                            LCD_Show_2424_String(100,133,"CHAN3",WHITE);
                                        }
                                    else
                                        {
                                            ShowTwoChineseChar(100,92,0,1,24,WHITE);
                                            LCD_Show_2424_String(148,92,"2",WHITE);
                                            ShowTwoChineseChar(100,133,0,1,24,WHITE);
                                            LCD_Show_2424_String(148,133,"3",WHITE);
                                        }
                                }
                            else if(flag_dev.activity_num==2||flag_dev.activity_num==4)
                                {
                                    if(flag_dev.langage==1)
                                        {
                                            LCD_Show_2424_String(100,92,"CHAN6",WHITE);
                                            LCD_Show_2424_String(100,133,"CHAN7",WHITE);
                                        }
                                    else
                                        {
                                            ShowTwoChineseChar(100,92,0,1,24,WHITE);
                                            LCD_Show_2424_String(148,92,"6",WHITE);
                                            ShowTwoChineseChar(100,133,0,1,24,WHITE);
                                            LCD_Show_2424_String(148,133,"7",WHITE);
                                        }

                                }
                            LCD_ShowNum(220,90,chan_data.data2,3,30,BLACK,WHITE);
                            LCD_Show_3030_String(265,90,"s",BLACK);
                            LCD_ShowNum(220,131,chan_data.data3,3,30,BLACK,WHITE);
                            LCD_Show_3030_String(265,131,"s",BLACK);
                            *SubAnchor=0x02;
                            break;
                        case 0x04:
                            gui_draw_arcrectangle(94,127,226,40,4,1,RED,RED);
                            gui_draw_arcrectangle(94,169,226,38,4,1,BLUE,BLUE);
                            gui_draw_arcrectangle(172,131,145,30,4,1,WHITE,WHITE);
                            gui_draw_arcrectangle(172,173,145,30,4,1,WHITE,WHITE);
                            if(flag_dev.activity_num==1||flag_dev.activity_num==3)
                                {
                                    if(flag_dev.langage==1)
                                        {
                                            LCD_Show_2424_String(100,133,"CHAN3",WHITE);
                                            LCD_Show_2424_String(100,175,"CHAN4",WHITE);
                                        }
                                    else
                                        {
                                            ShowTwoChineseChar(100,133,0,1,24,WHITE);
                                            LCD_Show_2424_String(148,133,"3",WHITE);
                                            ShowTwoChineseChar(100,175,0,1,24,WHITE);
                                            LCD_Show_2424_String(148,175,"4",WHITE);
                                        }
                                }
                            else if(flag_dev.activity_num==2||flag_dev.activity_num==4)
                                {
                                    if(flag_dev.langage==1)
                                        {
                                            LCD_Show_2424_String(100,133,"CHAN7",WHITE);
                                            LCD_Show_2424_String(100,175,"CHAN8",WHITE);
                                        }
                                    else
                                        {
                                            ShowTwoChineseChar(100,133,0,1,24,WHITE);
                                            LCD_Show_2424_String(148,133,"7",WHITE);
                                            ShowTwoChineseChar(100,175,0,1,24,WHITE);
                                            LCD_Show_2424_String(148,175,"8",WHITE);
                                        }
                                }
                            LCD_ShowNum(220,131,chan_data.data3,3,30,BLACK,WHITE);
                            LCD_Show_3030_String(265,131,"s",BLACK);
                            LCD_ShowNum(220,173,chan_data.data4,3,30,BLACK,WHITE);
                            LCD_Show_3030_String(265,173,"s",BLACK);
                            *SubAnchor=0x03;
                            break;
                        case 0x05:
                            gui_draw_arcrectangle(94,169,226,38,4,1,RED,RED);
                            gui_draw_arcrectangle(172,173,145,30,4,1,WHITE,WHITE);

                            if(flag_dev.activity_num==1||flag_dev.activity_num==3)
                                {
                                    if(flag_dev.langage==1)
                                        LCD_Show_2424_String(100,175,"CHAN4",WHITE);
                                    else
                                        {
                                            ShowTwoChineseChar(100,175,0,1,24,WHITE);
                                            LCD_Show_2424_String(148,175,"4",WHITE);
                                        }
                                }
                            else if(flag_dev.activity_num==2||flag_dev.activity_num==4)
                                {
                                    if(flag_dev.langage==1)
                                        LCD_Show_2424_String(100,175,"CHAN8",WHITE);
                                    else
                                        {
                                            ShowTwoChineseChar(100,175,0,1,24,WHITE);
                                            LCD_Show_2424_String(148,175,"8",WHITE);
                                        }
                                }
                            LCD_ShowNum(220,173,chan_data.data4,3,30,BLACK,WHITE);
                            LCD_Show_3030_String(265,173,"s",BLACK);
                            gui_draw_arcrectangle(120,210,80,30,1,1,BLUE,BLUE);
                            gui_draw_arcrectangle(125,212,70,28,1,1,WHITE,WHITE);
                            if(flag_dev.langage==1)
                                LCD_Show_3030_String(130,210,"SAVE",BLACK);
                            else
                                ShowTwoChineseChar(135,213,10,11,24,BLACK);
                            *SubAnchor=0x04;
                            break;
                        case 0x06:
                            gui_draw_arcrectangle(120,210,80,30,1,1,BLUE,BLUE);
                            gui_draw_arcrectangle(125,212,70,28,1,1,RED,RED);
                            if(flag_dev.langage==1)
                                LCD_Show_3030_String(130,210,"SAVE",WHITE);
                            else
                                ShowTwoChineseChar(135,213,10,11,24,WHITE);
                            LCD_DrawLtrigo(230,215,255,240,LEFT,WHITE);
                            *SubAnchor=0x05;
                            break;
                        case 0x07:
                            LCD_DrawLtrigo(230,215,255,240,LEFT,RED);
                            LCD_Show_picture(250,210,WHITE,0);
                            *SubAnchor=0x06;
                            break;
                        case 0x08:
                            LCD_Show_picture(250,210,RED,0);
                            LCD_DrawLtrigo(282,215,307,240,RIGHT,WHITE);
                            *SubAnchor=0x07;
                            break;

                        }
                }
        }

    if(flag_dev.action_flag==DELAY&&encoder_dev.EN_KEY==EN_KEY_DOWN)
        {

            switch(*SubAnchor)
                {
                case 0x01:
                    if(flag_dev.anchor!=0)
                        flag_dev.anchor=0;
                    else
                        flag_dev.anchor=1;
                    break;
                case 0x02:
                    if(flag_dev.anchor!=0)
                        flag_dev.anchor=0;

                    else
                        flag_dev.anchor=0x02;
                    break;
                case 0x03:
                    if(flag_dev.anchor!=0)
                        flag_dev.anchor=0;
                    else
                        flag_dev.anchor=0x03;
                    break;
                case 0x04:
                    if(flag_dev.anchor!=0)
                        flag_dev.anchor=0;
                    else
                        flag_dev.anchor=0x04;
                    break;
                case 0x05:
                    if(flag_dev.anchor!=0)
                        flag_dev.anchor=0;

                    if(flag_dev.activity_num==1)
                        {
                            chan_open_data.chan1=chan_data.data1;
                            chan_open_data.chan2=chan_data.data2;
                            chan_open_data.chan3=chan_data.data3;
                            chan_open_data.chan4=chan_data.data4;
                        }
                    else if(flag_dev.activity_num==2)
                        {
                            chan_open_data.chan5=chan_data.data1;
                            chan_open_data.chan6=chan_data.data2;
                            chan_open_data.chan7=chan_data.data3;
                            chan_open_data.chan8=chan_data.data4;
                        }
                    else if(flag_dev.activity_num==3)
                        {
                            chan_close_data.chan1=chan_data.data1;
                            chan_close_data.chan2=chan_data.data2;
                            chan_close_data.chan3=chan_data.data3;
                            chan_close_data.chan4=chan_data.data4;
                        }
                    else if(flag_dev.activity_num==4)
                        {
                            chan_close_data.chan5=chan_data.data1;
                            chan_close_data.chan6=chan_data.data2;
                            chan_close_data.chan7=chan_data.data3;
                            chan_close_data.chan8=chan_data.data4;
                        }
                    ReadAndSave(ISDELAY,1);
                    break;
                case 0x06:
                    if(flag_dev.activity_num==2)
                        {
                            gui_draw_arcrectangle(115,0,190,40,1,1,RED,RED);
                            if(flag_dev.langage==1)
                                LCD_Show_3030_String(125,5,"CHAN OPEN1/2",WHITE);
                            else
                                {
                                    ShowTwoChineseChar(145,11,2,3,24,WHITE);
                                    ShowTwoChineseChar(193,11,4,5,24,WHITE);
                                    LCD_Show_2424_String(241,14,"1/2",WHITE);
                                }
                            gui_draw_arcrectangle(94,43,226,40,4,1,BLUE,BLUE);
                            gui_draw_arcrectangle(94,85,226,40,4,1,BLUE,BLUE);
                            gui_draw_arcrectangle(94,127,226,40,4,1,BLUE,BLUE);
                            gui_draw_arcrectangle(94,169,226,38,4,1,BLUE,BLUE);

                            gui_draw_arcrectangle(172,48, 145,30,4,1,WHITE,WHITE);
                            gui_draw_arcrectangle(172,90, 145,30,4,1,WHITE,WHITE);
                            gui_draw_arcrectangle(172,131,145,30,4,1,WHITE,WHITE);
                            gui_draw_arcrectangle(172,173,145,30,4,1,WHITE,WHITE);
                            if(flag_dev.langage==1)
                                {
                                    LCD_Show_2424_String(100,50,"CHAN1",WHITE);
                                    LCD_Show_2424_String(100,92,"CHAN2",WHITE);
                                    LCD_Show_2424_String(100,133,"CHAN3",WHITE);
                                    LCD_Show_2424_String(100,175,"CHAN4",WHITE);
                                }
                            else
                                {
                                    ShowTwoChineseChar(100,50,0,1,24,WHITE);
                                    LCD_Show_2424_String(148,50,"1",WHITE);
                                    ShowTwoChineseChar(100,92,0,1,24,WHITE);
                                    LCD_Show_2424_String(148,92,"2",WHITE);
                                    ShowTwoChineseChar(100,133,0,1,24,WHITE);
                                    LCD_Show_2424_String(148,133,"3",WHITE);
                                    ShowTwoChineseChar(100,175,0,1,24,WHITE);
                                    LCD_Show_2424_String(148,175,"4",WHITE);
                                }
                            LCD_ShowNum(220,48,chan_open_data.chan1,3,30,BLACK,WHITE);
                            LCD_Show_3030_String(265,48,"s",BLACK);
                            LCD_ShowNum(220,90,chan_open_data.chan2,3,30,BLACK,WHITE);
                            LCD_Show_3030_String(265,90,"s",BLACK);
                            LCD_ShowNum(220,131,chan_open_data.chan3,3,30,BLACK,WHITE);
                            LCD_Show_3030_String(265,131,"s",BLACK);
                            LCD_ShowNum(220,173,chan_open_data.chan4,3,30,BLACK,WHITE);
                            LCD_Show_3030_String(265,173,"s",BLACK);

                            chan_data.data1=chan_open_data.chan1;
                            chan_data.data2=chan_open_data.chan2;
                            chan_data.data3=chan_open_data.chan3;
                            chan_data.data4=chan_open_data.chan4;

                            flag_dev.anchor=0;
                            flag_dev.activity_num=1;
                        }
                    else if(flag_dev.activity_num==1)
                        {

                            gui_draw_arcrectangle(115,0,190,40,1,1,RED,RED);
                            if(flag_dev.langage==1)
                                LCD_Show_3030_String(115,5,"CHAN CLOSE2/2",WHITE);
                            else
                                {
                                    ShowTwoChineseChar(145,11,2,3,24,WHITE);
                                    ShowTwoChineseChar(193,11,6,7,24,WHITE);
                                    LCD_Show_2424_String(241,14,"2/2",WHITE);
                                }
                            gui_draw_arcrectangle(94,43,226,40,4,1,BLUE,BLUE);
                            gui_draw_arcrectangle(94,85,226,40,4,1,BLUE,BLUE);
                            gui_draw_arcrectangle(94,127,226,40,4,1,BLUE,BLUE);
                            gui_draw_arcrectangle(94,169,226,38,4,1,BLUE,BLUE);

                            gui_draw_arcrectangle(172,48, 145,30,4,1,WHITE,WHITE);
                            gui_draw_arcrectangle(172,90, 145,30,4,1,WHITE,WHITE);
                            gui_draw_arcrectangle(172,131,145,30,4,1,WHITE,WHITE);
                            gui_draw_arcrectangle(172,173,145,30,4,1,WHITE,WHITE);

                            if(flag_dev.langage==1)
                                {
                                    LCD_Show_2424_String(100,50,"CHAN5",WHITE);
                                    LCD_Show_2424_String(100,92,"CHAN6",WHITE);
                                    LCD_Show_2424_String(100,133,"CHAN7",WHITE);
                                    LCD_Show_2424_String(100,175,"CHAN8",WHITE);
                                }
                            else
                                {
                                    ShowTwoChineseChar(100,50,0,1,24,WHITE);
                                    LCD_Show_2424_String(148,50,"5",WHITE);
                                    ShowTwoChineseChar(100,92,0,1,24,WHITE);
                                    LCD_Show_2424_String(148,92,"6",WHITE);
                                    ShowTwoChineseChar(100,133,0,1,24,WHITE);
                                    LCD_Show_2424_String(148,133,"7",WHITE);
                                    ShowTwoChineseChar(100,175,0,1,24,WHITE);
                                    LCD_Show_2424_String(148,175,"8",WHITE);
                                }
                            LCD_ShowNum(220,48,chan_close_data.chan5,3,30,BLACK,WHITE);
                            LCD_Show_3030_String(265,48,"s",BLACK);
                            LCD_ShowNum(220,90,chan_close_data.chan6,3,30,BLACK,WHITE);
                            LCD_Show_3030_String(265,90,"s",BLACK);
                            LCD_ShowNum(220,131,chan_close_data.chan7,3,30,BLACK,WHITE);
                            LCD_Show_3030_String(265,131,"s",BLACK);
                            LCD_ShowNum(220,173,chan_close_data.chan8,3,30,BLACK,WHITE);
                            LCD_Show_3030_String(265,173,"s",BLACK);

                            flag_dev.activity_num=4;

                            chan_data.data1=chan_close_data.chan5;
                            chan_data.data2=chan_close_data.chan6;
                            chan_data.data3=chan_close_data.chan7;
                            chan_data.data4=chan_close_data.chan8;
                            flag_dev.anchor=0;

                        }
                    else if(flag_dev.activity_num==4)
                        {

                            gui_draw_arcrectangle(115,0,190,40,1,1,RED,RED);
                            if(flag_dev.langage==1)
                                {
                                    LCD_Show_3030_String(115,5,"CHAN CLOSE1/2",WHITE);
                                }
                            else
                                {
                                    ShowTwoChineseChar(145,11,2,3,24,WHITE);
                                    ShowTwoChineseChar(193,11,6,7,24,WHITE);
                                    LCD_Show_2424_String(241,14,"1/2",WHITE);
                                }
                            gui_draw_arcrectangle(94,43,226,40,4,1,BLUE,BLUE);
                            gui_draw_arcrectangle(94,85,226,40,4,1,BLUE,BLUE);
                            gui_draw_arcrectangle(94,127,226,40,4,1,BLUE,BLUE);
                            gui_draw_arcrectangle(94,169,226,38,4,1,BLUE,BLUE);

                            gui_draw_arcrectangle(172,48, 145,30,4,1,WHITE,WHITE);
                            gui_draw_arcrectangle(172,90, 145,30,4,1,WHITE,WHITE);
                            gui_draw_arcrectangle(172,131,145,30,4,1,WHITE,WHITE);
                            gui_draw_arcrectangle(172,173,145,30,4,1,WHITE,WHITE);

                            LCD_ShowNum(220,48,chan_close_data.chan1,3,30,BLACK,WHITE);
                            LCD_Show_3030_String(265,48,"s",BLACK);
                            LCD_ShowNum(220,90,chan_close_data.chan2,3,30,BLACK,WHITE);
                            LCD_Show_3030_String(265,90,"s",BLACK);
                            LCD_ShowNum(220,131,chan_close_data.chan3,3,30,BLACK,WHITE);
                            LCD_Show_3030_String(265,131,"s",BLACK);
                            LCD_ShowNum(220,173,chan_close_data.chan4,3,30,BLACK,WHITE);
                            LCD_Show_3030_String(265,173,"s",BLACK);

                            if(flag_dev.langage==1)
                                {
                                    LCD_Show_2424_String(100,50,"CHAN1",WHITE);
                                    LCD_Show_2424_String(100,92,"CHAN2",WHITE);
                                    LCD_Show_2424_String(100,133,"CHAN3",WHITE);
                                    LCD_Show_2424_String(100,175,"CHAN4",WHITE);
                                }
                            else
                                {
                                    ShowTwoChineseChar(100,50,0,1,24,WHITE);
                                    LCD_Show_2424_String(148,50,"1",WHITE);
                                    ShowTwoChineseChar(100,92,0,1,24,WHITE);
                                    LCD_Show_2424_String(148,92,"2",WHITE);
                                    ShowTwoChineseChar(100,133,0,1,24,WHITE);
                                    LCD_Show_2424_String(148,133,"3",WHITE);
                                    ShowTwoChineseChar(100,175,0,1,24,WHITE);
                                    LCD_Show_2424_String(148,175,"4",WHITE);
                                }
                            flag_dev.activity_num=3;

                            chan_data.data1=chan_close_data.chan1;
                            chan_data.data2=chan_close_data.chan2;
                            chan_data.data3=chan_close_data.chan3;
                            chan_data.data4=chan_close_data.chan4;

                            flag_dev.anchor=0;

                        }
                    else if(flag_dev.activity_num==3)
                        {
                            gui_draw_arcrectangle(115,0,190,40,1,1,RED,RED);
                            if(flag_dev.langage==1)
                                {
                                    LCD_Show_3030_String(125,5,"CHAN OPEN2/2",WHITE);
                                }
                            else
                                {
                                    ShowTwoChineseChar(145,11,2,3,24,WHITE);
                                    ShowTwoChineseChar(193,11,4,5,24,WHITE);
                                    LCD_Show_2424_String(241,14,"2/2",WHITE);
                                }
                            gui_draw_arcrectangle(94,43,226,40,4,1,BLUE,BLUE);
                            gui_draw_arcrectangle(94,85,226,40,4,1,BLUE,BLUE);
                            gui_draw_arcrectangle(94,127,226,40,4,1,BLUE,BLUE);
                            gui_draw_arcrectangle(94,169,226,38,4,1,BLUE,BLUE);

                            gui_draw_arcrectangle(172,48, 145,30,4,1,WHITE,WHITE);
                            gui_draw_arcrectangle(172,90, 145,30,4,1,WHITE,WHITE);
                            gui_draw_arcrectangle(172,131,145,30,4,1,WHITE,WHITE);
                            gui_draw_arcrectangle(172,173,145,30,4,1,WHITE,WHITE);

                            LCD_ShowNum(220,48,chan_open_data.chan5,3,30,BLACK,WHITE);
                            LCD_Show_3030_String(265,48,"s",BLACK);
                            LCD_ShowNum(220,90,chan_open_data.chan6,3,30,BLACK,WHITE);
                            LCD_Show_3030_String(265,90,"s",BLACK);
                            LCD_ShowNum(220,131,chan_open_data.chan7,3,30,BLACK,WHITE);
                            LCD_Show_3030_String(265,131,"s",BLACK);
                            LCD_ShowNum(220,173,chan_open_data.chan8,3,30,BLACK,WHITE);
                            LCD_Show_3030_String(265,173,"s",BLACK);
                            if(flag_dev.langage==1)
                                {
                                    LCD_Show_2424_String(100,50,"CHAN5",WHITE);
                                    LCD_Show_2424_String(100,92,"CHAN6",WHITE);
                                    LCD_Show_2424_String(100,133,"CHAN7",WHITE);
                                    LCD_Show_2424_String(100,175,"CHAN8",WHITE);
                                }
                            else
                                {
                                    ShowTwoChineseChar(100,50,0,1,24,WHITE);
                                    LCD_Show_2424_String(148,50,"5",WHITE);
                                    ShowTwoChineseChar(100,92,0,1,24,WHITE);
                                    LCD_Show_2424_String(148,92,"6",WHITE);
                                    ShowTwoChineseChar(100,133,0,1,24,WHITE);
                                    LCD_Show_2424_String(148,133,"7",WHITE);
                                    ShowTwoChineseChar(100,175,0,1,24,WHITE);
                                    LCD_Show_2424_String(148,175,"8",WHITE);
                                }
                            flag_dev.activity_num=2;

                            chan_data.data1=chan_open_data.chan5;
                            chan_data.data2=chan_open_data.chan6;
                            chan_data.data3=chan_open_data.chan7;
                            chan_data.data4=chan_open_data.chan8;

                            flag_dev.anchor=0;
                        }
                    break;
                case 0x07:
                    flag_dev.TOSUBPAGE=0;
                    LCD_Show_picture(250,210,WHITE,0);
                    *SubAnchor=0;
                    break;
                case 0x08:
                    if(flag_dev.activity_num==1)
                        {
                            gui_draw_arcrectangle(115,0,190,40,1,1,RED,RED);
                            if(flag_dev.langage==1)
                                {
                                    LCD_Show_3030_String(125,5,"CHAN OPEN2/2",WHITE);
                                }
                            else
                                {
                                    ShowTwoChineseChar(145,11,2,3,24,WHITE);
                                    ShowTwoChineseChar(193,11,4,5,24,WHITE);
                                    LCD_Show_2424_String(241,14,"2/2",WHITE);
                                }
                            gui_draw_arcrectangle(94,43,226,40,4,1,BLUE,BLUE);
                            gui_draw_arcrectangle(94,85,226,40,4,1,BLUE,BLUE);
                            gui_draw_arcrectangle(94,127,226,40,4,1,BLUE,BLUE);
                            gui_draw_arcrectangle(94,169,226,38,4,1,BLUE,BLUE);

                            gui_draw_arcrectangle(172,48, 145,30,4,1,WHITE,WHITE);
                            gui_draw_arcrectangle(172,90, 145,30,4,1,WHITE,WHITE);
                            gui_draw_arcrectangle(172,131,145,30,4,1,WHITE,WHITE);
                            gui_draw_arcrectangle(172,173,145,30,4,1,WHITE,WHITE);

                            LCD_ShowNum(220,48,chan_open_data.chan5,3,30,BLACK,WHITE);
                            LCD_Show_3030_String(265,48,"s",BLACK);
                            LCD_ShowNum(220,90,chan_open_data.chan6,3,30,BLACK,WHITE);
                            LCD_Show_3030_String(265,90,"s",BLACK);
                            LCD_ShowNum(220,131,chan_open_data.chan7,3,30,BLACK,WHITE);
                            LCD_Show_3030_String(265,131,"s",BLACK);
                            LCD_ShowNum(220,173,chan_open_data.chan8,3,30,BLACK,WHITE);
                            LCD_Show_3030_String(265,173,"s",BLACK);

                            if(flag_dev.langage==1)
                                {
                                    LCD_Show_2424_String(100,50,"CHAN5",WHITE);
                                    LCD_Show_2424_String(100,92,"CHAN6",WHITE);
                                    LCD_Show_2424_String(100,133,"CHAN7",WHITE);
                                    LCD_Show_2424_String(100,175,"CHAN8",WHITE);
                                }
                            else
                                {
                                    ShowTwoChineseChar(100,50,0,1,24,WHITE);
                                    LCD_Show_2424_String(148,50,"5",WHITE);
                                    ShowTwoChineseChar(100,92,0,1,24,WHITE);
                                    LCD_Show_2424_String(148,92,"6",WHITE);
                                    ShowTwoChineseChar(100,133,0,1,24,WHITE);
                                    LCD_Show_2424_String(148,133,"7",WHITE);
                                    ShowTwoChineseChar(100,175,0,1,24,WHITE);
                                    LCD_Show_2424_String(148,175,"8",WHITE);
                                }
                            chan_data.data1=chan_open_data.chan5;
                            chan_data.data2=chan_open_data.chan6;
                            chan_data.data3=chan_open_data.chan7;
                            chan_data.data4=chan_open_data.chan8;


                            flag_dev.activity_num=2;

                            flag_dev.anchor=0;

                        }
                    else if( flag_dev.activity_num==2)
                        {

                            gui_draw_arcrectangle(115,0,190,40,1,1,RED,RED);
                            if(flag_dev.langage==1)
                                LCD_Show_3030_String(115,5,"CHAN CLOSE1/2",WHITE);
                            else
                                {
                                    ShowTwoChineseChar(145,11,2,3,24,WHITE);
                                    ShowTwoChineseChar(193,11,6,7,24,WHITE);
                                    LCD_Show_2424_String(241,14,"1/2",WHITE);
                                }
                            gui_draw_arcrectangle(94,43,226,40,4,1,BLUE,BLUE);
                            gui_draw_arcrectangle(94,85,226,40,4,1,BLUE,BLUE);
                            gui_draw_arcrectangle(94,127,226,40,4,1,BLUE,BLUE);
                            gui_draw_arcrectangle(94,169,226,38,4,1,BLUE,BLUE);

                            gui_draw_arcrectangle(172,48, 145,30,4,1,WHITE,WHITE);
                            gui_draw_arcrectangle(172,90, 145,30,4,1,WHITE,WHITE);
                            gui_draw_arcrectangle(172,131,145,30,4,1,WHITE,WHITE);
                            gui_draw_arcrectangle(172,173,145,30,4,1,WHITE,WHITE);

                            LCD_ShowNum(220,48,chan_close_data.chan1,3,30,BLACK,WHITE);
                            LCD_Show_3030_String(265,48,"s",BLACK);
                            LCD_ShowNum(220,90,chan_close_data.chan2,3,30,BLACK,WHITE);
                            LCD_Show_3030_String(265,90,"s",BLACK);
                            LCD_ShowNum(220,131,chan_close_data.chan3,3,30,BLACK,WHITE);
                            LCD_Show_3030_String(265,131,"s",BLACK);
                            LCD_ShowNum(220,173,chan_close_data.chan4,3,30,BLACK,WHITE);
                            LCD_Show_3030_String(265,173,"s",BLACK);
                            if(flag_dev.langage==0)
                                {
                                    ShowTwoChineseChar(100,50,0,1,24,WHITE);
                                    LCD_Show_2424_String(148,50,"1",WHITE);
                                    ShowTwoChineseChar(100,92,0,1,24,WHITE);
                                    LCD_Show_2424_String(148,92,"2",WHITE);
                                    ShowTwoChineseChar(100,133,0,1,24,WHITE);
                                    LCD_Show_2424_String(148,133,"3",WHITE);
                                    ShowTwoChineseChar(100,175,0,1,24,WHITE);
                                    LCD_Show_2424_String(148,175,"4",WHITE);
                                }
                            else
                                {
                                    LCD_Show_2424_String(100,50,"CHAN1",WHITE);
                                    LCD_Show_2424_String(100,92,"CHAN2",WHITE);
                                    LCD_Show_2424_String(100,133,"CHAN3",WHITE);
                                    LCD_Show_2424_String(100,175,"CHAN4",WHITE);
                                }
                            flag_dev.activity_num=3;

                            chan_data.data1=chan_close_data.chan1;
                            chan_data.data2=chan_close_data.chan2;
                            chan_data.data3=chan_close_data.chan3;
                            chan_data.data4=chan_close_data.chan4;
                            flag_dev.anchor=0;

                        }
                    else if( flag_dev.activity_num==3)
                        {

                            gui_draw_arcrectangle(115,0,190,40,1,1,RED,RED);
                            if(flag_dev.langage==1)
                                LCD_Show_3030_String(115,5,"CHAN CLOSE2/2",WHITE);
                            else
                                {
                                    ShowTwoChineseChar(145,11,2,3,24,WHITE);
                                    ShowTwoChineseChar(193,11,6,7,24,WHITE);
                                    LCD_Show_2424_String(241,14,"2/2",WHITE);
                                }
                            gui_draw_arcrectangle(94,43,226,40,4,1,BLUE,BLUE);
                            gui_draw_arcrectangle(94,85,226,40,4,1,BLUE,BLUE);
                            gui_draw_arcrectangle(94,127,226,40,4,1,BLUE,BLUE);
                            gui_draw_arcrectangle(94,169,226,38,4,1,BLUE,BLUE);



                            gui_draw_arcrectangle(172,48, 145,30,4,1,WHITE,WHITE);
                            gui_draw_arcrectangle(172,90, 145,30,4,1,WHITE,WHITE);
                            gui_draw_arcrectangle(172,131,145,30,4,1,WHITE,WHITE);
                            gui_draw_arcrectangle(172,173,145,30,4,1,WHITE,WHITE);


                            LCD_ShowNum(220,48,chan_close_data.chan5,3,30,BLACK,WHITE);
                            LCD_Show_3030_String(265,48,"s",BLACK);
                            LCD_ShowNum(220,90,chan_close_data.chan6,3,30,BLACK,WHITE);
                            LCD_Show_3030_String(265,90,"s",BLACK);
                            LCD_ShowNum(220,131,chan_close_data.chan7,3,30,BLACK,WHITE);
                            LCD_Show_3030_String(265,131,"s",BLACK);
                            LCD_ShowNum(220,173,chan_close_data.chan8,3,30,BLACK,WHITE);
                            LCD_Show_3030_String(265,173,"s",BLACK);

                            if(flag_dev.langage==1)
                                {
                                    LCD_Show_2424_String(100,50,"CHAN5",WHITE);
                                    LCD_Show_2424_String(100,92,"CHAN6",WHITE);
                                    LCD_Show_2424_String(100,133,"CHAN7",WHITE);
                                    LCD_Show_2424_String(100,175,"CHAN8",WHITE);
                                }
                            else
                                {
                                    ShowTwoChineseChar(100,50,0,1,24,WHITE);
                                    LCD_Show_2424_String(148,50,"5",WHITE);
                                    ShowTwoChineseChar(100,92,0,1,24,WHITE);
                                    LCD_Show_2424_String(148,92,"6",WHITE);
                                    ShowTwoChineseChar(100,133,0,1,24,WHITE);
                                    LCD_Show_2424_String(148,133,"7",WHITE);
                                    ShowTwoChineseChar(100,175,0,1,24,WHITE);
                                    LCD_Show_2424_String(148,175,"8",WHITE);
                                }
                            flag_dev.activity_num=4;

                            chan_data.data1=chan_close_data.chan5;
                            chan_data.data2=chan_close_data.chan6;
                            chan_data.data3=chan_close_data.chan7;
                            chan_data.data4=chan_close_data.chan8;
                            flag_dev.anchor=0;

                        }
                    else if( flag_dev.activity_num==4)
                        {
                            gui_draw_arcrectangle(115,0,190,40,1,1,RED,RED);
                            if(flag_dev.langage==1)
                                LCD_Show_3030_String(125,5,"CHAN OPEN1/2",WHITE);
                            else
                                {
                                    ShowTwoChineseChar(145,11,2,3,24,WHITE);
                                    ShowTwoChineseChar(193,11,4,5,24,WHITE);
                                    LCD_Show_2424_String(241,14,"1/2",WHITE);
                                }
                            gui_draw_arcrectangle(94,43,226,40,4,1,BLUE,BLUE);
                            gui_draw_arcrectangle(94,85,226,40,4,1,BLUE,BLUE);
                            gui_draw_arcrectangle(94,127,226,40,4,1,BLUE,BLUE);
                            gui_draw_arcrectangle(94,169,226,38,4,1,BLUE,BLUE);


                            gui_draw_arcrectangle(172,48, 145,30,4,1,WHITE,WHITE);
                            gui_draw_arcrectangle(172,90, 145,30,4,1,WHITE,WHITE);
                            gui_draw_arcrectangle(172,131,145,30,4,1,WHITE,WHITE);
                            gui_draw_arcrectangle(172,173,145,30,4,1,WHITE,WHITE);


                            LCD_ShowNum(220,48,chan_open_data.chan1,3,30,BLACK,WHITE);
                            LCD_Show_3030_String(265,48,"s",BLACK);
                            LCD_ShowNum(220,90,chan_open_data.chan2,3,30,BLACK,WHITE);
                            LCD_Show_3030_String(265,90,"s",BLACK);
                            LCD_ShowNum(220,131,chan_open_data.chan3,3,30,BLACK,WHITE);
                            LCD_Show_3030_String(265,131,"s",BLACK);
                            LCD_ShowNum(220,173,chan_open_data.chan4,3,30,BLACK,WHITE);
                            LCD_Show_3030_String(265,173,"s",BLACK);
                            if(flag_dev.langage==1)
                                {
                                    LCD_Show_2424_String(100,50,"CHAN1",WHITE);
                                    LCD_Show_2424_String(100,92,"CHAN2",WHITE);
                                    LCD_Show_2424_String(100,133,"CHAN3",WHITE);
                                    LCD_Show_2424_String(100,175,"CHAN4",WHITE);
                                }
                            else
                                {
                                    ShowTwoChineseChar(100,50,0,1,24,WHITE);
                                    LCD_Show_2424_String(148,50,"1",WHITE);
                                    ShowTwoChineseChar(100,92,0,1,24,WHITE);
                                    LCD_Show_2424_String(148,92,"2",WHITE);
                                    ShowTwoChineseChar(100,133,0,1,24,WHITE);
                                    LCD_Show_2424_String(148,133,"3",WHITE);
                                    ShowTwoChineseChar(100,175,0,1,24,WHITE);
                                    LCD_Show_2424_String(148,175,"4",WHITE);
                                }
                            flag_dev.activity_num=1;

                            chan_data.data1=chan_open_data.chan1;
                            chan_data.data2=chan_open_data.chan2;
                            chan_data.data3=chan_open_data.chan3;
                            chan_data.data4=chan_open_data.chan4;
                            flag_dev.anchor=0;
                        }

                    break;
                }
        }
}
void EncoderSwitch(u8 *SubAnchor)
{

    if(flag_dev.action_flag==SWITCH)
        {
            if(encoder_dev.EN_STATE==SUBRIGHT)
                {
                    switch(*SubAnchor)
                        {
                        case 0x00:
                            if(flag_dev.activity_num==1)
                                {
                                    if(EnCH1)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,50,"ON",RED);
                                            else
                                                ShowChineseChar(235,50,5,24,RED);

                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,50,"0FF",RED);
                                            else
                                                ShowChineseChar(235,50,6,24,RED);

                                        }

                                    if(EnCH2)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,90,"ON",BLACK);
                                            else
                                                ShowChineseChar(235,90,5,24,BLACK);

                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,90,"OFF",BLACK);
                                            else
                                                ShowChineseChar(235,90,6,24,BLACK);
                                        }
                                    if(EnCH3)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,130,"ON",BLACK);
                                            else
                                                ShowChineseChar(235,130,5,24,BLACK);
                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,130,"OFF",BLACK);
                                            else
                                                ShowChineseChar(235,130,6,24,BLACK);
                                        }

                                    if(EnCH4)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,170,"ON",BLACK);
                                            else
                                                ShowChineseChar(235,170,5,24,BLACK);

                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,170,"OFF",BLACK);
                                            else
                                                ShowChineseChar(235,170,6,24,BLACK);
                                        }
                                }
                            else if(flag_dev.activity_num==2)
                                {
                                    if(EnCH5)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,50,"ON",RED);
                                            else
                                                ShowChineseChar(235,50,5,24,RED);
                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,50,"0FF",RED);
                                            else
                                                ShowChineseChar(235,50,6,24,RED);
                                        }

                                    if(EnCH6)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,90,"ON",BLACK);
                                            else
                                                ShowChineseChar(235,90,5,24,BLACK);
                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,90,"OFF",BLACK);
                                            else
                                                ShowChineseChar(235,90,6,24,BLACK);
                                        }
                                    if(EnCH7)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,130,"ON",BLACK);
                                            else
                                                ShowChineseChar(235,130,5,24,BLACK);
                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,130,"OFF",BLACK);
                                            else
                                                ShowChineseChar(235,130,6,24,BLACK);

                                        }
                                    if(EnCH8)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,170,"ON",BLACK);
                                            else
                                                ShowChineseChar(235,170,5,24,BLACK);
                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,170,"OFF",BLACK);
                                            else
                                                ShowChineseChar(235,170,6,24,BLACK);

                                        }

                                }
                            *SubAnchor=0x01;
                            break;
                        case 0x01:
                            if(flag_dev.activity_num==1)
                                {
                                    if(EnCH1)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,50,"ON",BLACK);
                                            else
                                                ShowChineseChar(235,50,5,24,BLACK);

                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,50,"0FF",BLACK);
                                            else
                                                ShowChineseChar(235,50,6,24,BLACK);

                                        }

                                    if(EnCH2)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,90,"ON",RED);
                                            else
                                                ShowChineseChar(235,90,5,24,RED);

                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,90,"OFF",RED);
                                            else
                                                ShowChineseChar(235,90,6,24,RED);
                                        }
                                    if(EnCH3)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,130,"ON",BLACK);
                                            else
                                                ShowChineseChar(235,130,5,24,BLACK);
                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,130,"OFF",BLACK);
                                            else
                                                ShowChineseChar(235,130,6,24,BLACK);
                                        }

                                    if(EnCH4)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,170,"ON",BLACK);
                                            else
                                                ShowChineseChar(235,170,5,24,BLACK);

                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,170,"OFF",BLACK);
                                            else
                                                ShowChineseChar(235,170,6,24,BLACK);
                                        }
                                }
                            else if(flag_dev.activity_num==2)
                                {
                                    if(EnCH5)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,50,"ON",BLACK);
                                            else
                                                ShowChineseChar(235,50,5,24,BLACK);
                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,50,"0FF",BLACK);
                                            else
                                                ShowChineseChar(235,50,6,24,BLACK);
                                        }

                                    if(EnCH6)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,90,"ON",RED);
                                            else
                                                ShowChineseChar(235,90,5,24,RED);
                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,90,"OFF",RED);
                                            else
                                                ShowChineseChar(235,90,6,24,RED);
                                        }
                                    if(EnCH7)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,130,"ON",BLACK);
                                            else
                                                ShowChineseChar(235,130,5,24,BLACK);
                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,130,"OFF",BLACK);
                                            else
                                                ShowChineseChar(235,130,6,24,BLACK);

                                        }
                                    if(EnCH8)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,170,"ON",BLACK);
                                            else
                                                ShowChineseChar(235,170,5,24,BLACK);
                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,170,"OFF",BLACK);
                                            else
                                                ShowChineseChar(235,170,6,24,BLACK);

                                        }

                                }
                            *SubAnchor=0x02;
                            break;
                        case 0x02:

                            if(flag_dev.activity_num==1)
                                {
                                    if(EnCH1)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,50,"ON",BLACK);
                                            else
                                                ShowChineseChar(235,50,5,24,BLACK);

                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,50,"0FF",BLACK);
                                            else
                                                ShowChineseChar(235,50,6,24,BLACK);

                                        }

                                    if(EnCH2)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,90,"ON",BLACK);
                                            else
                                                ShowChineseChar(235,90,5,24,BLACK);

                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,90,"OFF",BLACK);
                                            else
                                                ShowChineseChar(235,90,6,24,BLACK);
                                        }
                                    if(EnCH3)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,130,"ON",RED);
                                            else
                                                ShowChineseChar(235,130,5,24,RED);
                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,130,"OFF",RED);
                                            else
                                                ShowChineseChar(235,130,6,24,RED);
                                        }

                                    if(EnCH4)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,170,"ON",BLACK);
                                            else
                                                ShowChineseChar(235,170,5,24,BLACK);

                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,170,"OFF",BLACK);
                                            else
                                                ShowChineseChar(235,170,6,24,BLACK);
                                        }
                                }
                            else if(flag_dev.activity_num==2)
                                {
                                    if(EnCH5)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,50,"ON",BLACK);
                                            else
                                                ShowChineseChar(235,50,5,24,BLACK);
                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,50,"0FF",BLACK);
                                            else
                                                ShowChineseChar(235,50,6,24,BLACK);
                                        }

                                    if(EnCH6)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,90,"ON",BLACK);
                                            else
                                                ShowChineseChar(235,90,5,24,BLACK);
                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,90,"OFF",BLACK);
                                            else
                                                ShowChineseChar(235,90,6,24,BLACK);
                                        }
                                    if(EnCH7)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,130,"ON",RED);
                                            else
                                                ShowChineseChar(235,130,5,24,RED);
                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,130,"OFF",RED);
                                            else
                                                ShowChineseChar(235,130,6,24,RED);

                                        }
                                    if(EnCH8)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,170,"ON",BLACK);
                                            else
                                                ShowChineseChar(235,170,5,24,BLACK);
                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,170,"OFF",BLACK);
                                            else
                                                ShowChineseChar(235,170,6,24,BLACK);

                                        }

                                }
                            *SubAnchor=0x03;
                            break;
                        case 0x03:
                            if(flag_dev.activity_num==1)
                                {
                                    if(EnCH1)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,50,"ON",BLACK);
                                            else
                                                ShowChineseChar(235,50,5,24,BLACK);

                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,50,"0FF",BLACK);
                                            else
                                                ShowChineseChar(235,50,6,24,BLACK);

                                        }

                                    if(EnCH2)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,90,"ON",BLACK);
                                            else
                                                ShowChineseChar(235,90,5,24,BLACK);

                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,90,"OFF",BLACK);
                                            else
                                                ShowChineseChar(235,90,6,24,BLACK);
                                        }
                                    if(EnCH3)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,130,"ON",BLACK);
                                            else
                                                ShowChineseChar(235,130,5,24,BLACK);
                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,130,"OFF",BLACK);
                                            else
                                                ShowChineseChar(235,130,6,24,BLACK);
                                        }

                                    if(EnCH4)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,170,"ON",RED);
                                            else
                                                ShowChineseChar(235,170,5,24,RED);

                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,170,"OFF",RED);
                                            else
                                                ShowChineseChar(235,170,6,24,RED);
                                        }
                                }
                            else if(flag_dev.activity_num==2)
                                {
                                    if(EnCH5)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,50,"ON",BLACK);
                                            else
                                                ShowChineseChar(235,50,5,24,BLACK);
                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,50,"0FF",BLACK);
                                            else
                                                ShowChineseChar(235,50,6,24,BLACK);
                                        }

                                    if(EnCH6)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,90,"ON",BLACK);
                                            else
                                                ShowChineseChar(235,90,5,24,BLACK);
                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,90,"OFF",BLACK);
                                            else
                                                ShowChineseChar(235,90,6,24,BLACK);
                                        }
                                    if(EnCH7)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,130,"ON",BLACK);
                                            else
                                                ShowChineseChar(235,130,5,24,BLACK);
                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,130,"OFF",BLACK);
                                            else
                                                ShowChineseChar(235,130,6,24,BLACK);

                                        }
                                    if(EnCH8)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,170,"ON",RED);
                                            else
                                                ShowChineseChar(235,170,5,24,RED);
                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,170,"OFF",RED);
                                            else
                                                ShowChineseChar(235,170,6,24,RED);

                                        }

                                }
                            *SubAnchor=0x04;
                            break;
                        case 0x04:
                            if(flag_dev.activity_num==1)
                                {
                                    if(EnCH1)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,50,"ON",BLACK);
                                            else
                                                ShowChineseChar(235,50,5,24,BLACK);

                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,50,"0FF",BLACK);
                                            else
                                                ShowChineseChar(235,50,6,24,BLACK);

                                        }

                                    if(EnCH2)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,90,"ON",BLACK);
                                            else
                                                ShowChineseChar(235,90,5,24,BLACK);

                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,90,"OFF",BLACK);
                                            else
                                                ShowChineseChar(235,90,6,24,BLACK);
                                        }
                                    if(EnCH3)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,130,"ON",BLACK);
                                            else
                                                ShowChineseChar(235,130,5,24,BLACK);
                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,130,"OFF",BLACK);
                                            else
                                                ShowChineseChar(235,130,6,24,BLACK);
                                        }

                                    if(EnCH4)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,170,"ON",BLACK);
                                            else
                                                ShowChineseChar(235,170,5,24,BLACK);

                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,170,"OFF",BLACK);
                                            else
                                                ShowChineseChar(235,170,6,24,BLACK);
                                        }
                                }
                            else if(flag_dev.activity_num==2)
                                {
                                    if(EnCH5)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,50,"ON",BLACK);
                                            else
                                                ShowChineseChar(235,50,5,24,BLACK);
                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,50,"0FF",BLACK);
                                            else
                                                ShowChineseChar(235,50,6,24,BLACK);
                                        }

                                    if(EnCH6)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,90,"ON",BLACK);
                                            else
                                                ShowChineseChar(235,90,5,24,BLACK);
                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,90,"OFF",BLACK);
                                            else
                                                ShowChineseChar(235,90,6,24,BLACK);
                                        }
                                    if(EnCH7)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,130,"ON",BLACK);
                                            else
                                                ShowChineseChar(235,130,5,24,BLACK);
                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,130,"OFF",BLACK);
                                            else
                                                ShowChineseChar(235,130,6,24,BLACK);

                                        }
                                    if(EnCH8)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,170,"ON",BLACK);
                                            else
                                                ShowChineseChar(235,170,5,24,BLACK);
                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,170,"OFF",BLACK);
                                            else
                                                ShowChineseChar(235,170,6,24,BLACK);

                                        }

                                }
                            gui_draw_arcrectangle(120,210,80,30,1,1,BLUE,BLUE);
                            gui_draw_arcrectangle(125,212,70,28,1,1,RED,RED);
                            if(flag_dev.langage==1)
                                LCD_Show_3030_String(130,210,"SAVE",WHITE);
                            else
                                ShowTwoChineseChar(135,213,10,11,24,WHITE);
                            *SubAnchor=0x05;
                            break;
                        case 0x05:
                            gui_draw_arcrectangle(120,210,80,30,1,1,BLUE,BLUE);
                            gui_draw_arcrectangle(125,212,70,28,1,1,WHITE,WHITE);
                            if(flag_dev.langage==1)
                                LCD_Show_3030_String(130,210,"SAVE",BLACK);
                            else
                                ShowTwoChineseChar(135,213,10,11,24,BLACK);
                            LCD_DrawLtrigo(230,215,255,240,LEFT,RED);

                            *SubAnchor=0x06;
                            break;
                        case 0x06:
                            LCD_DrawLtrigo(230,215,255,240,LEFT,WHITE);
                            LCD_Show_picture(250,210,RED,0);
                            *SubAnchor=0x07;
                            break;
                        case 0x07:
                            LCD_Show_picture(250,210,WHITE,0);
                            LCD_DrawLtrigo(282,215,307,240,RIGHT,RED);
                            *SubAnchor=0x08;
                            break;
                        }
                }
            else if(encoder_dev.EN_STATE==SUBLEFT)
                {
                    switch(*SubAnchor)
                        {
                        case 0x02:

                            if(flag_dev.activity_num==1)
                                {
                                    if(EnCH1)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,50,"ON",RED);
                                            else
                                                ShowChineseChar(235,50,5,24,RED);

                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,50,"0FF",RED);
                                            else
                                                ShowChineseChar(235,50,6,24,RED);

                                        }

                                    if(EnCH2)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,90,"ON",BLACK);
                                            else
                                                ShowChineseChar(235,90,5,24,BLACK);

                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,90,"OFF",BLACK);
                                            else
                                                ShowChineseChar(235,90,6,24,BLACK);
                                        }
                                    if(EnCH3)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,130,"ON",BLACK);
                                            else
                                                ShowChineseChar(235,130,5,24,BLACK);
                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,130,"OFF",BLACK);
                                            else
                                                ShowChineseChar(235,130,6,24,BLACK);
                                        }

                                    if(EnCH4)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,170,"ON",BLACK);
                                            else
                                                ShowChineseChar(235,170,5,24,BLACK);

                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,170,"OFF",BLACK);
                                            else
                                                ShowChineseChar(235,170,6,24,BLACK);
                                        }
                                }
                            else if(flag_dev.activity_num==2)
                                {
                                    if(EnCH5)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,50,"ON",RED);
                                            else
                                                ShowChineseChar(235,50,5,24,RED);
                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,50,"0FF",RED);
                                            else
                                                ShowChineseChar(235,50,6,24,RED);
                                        }

                                    if(EnCH6)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,90,"ON",BLACK);
                                            else
                                                ShowChineseChar(235,90,5,24,BLACK);
                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,90,"OFF",BLACK);
                                            else
                                                ShowChineseChar(235,90,6,24,BLACK);
                                        }
                                    if(EnCH7)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,130,"ON",BLACK);
                                            else
                                                ShowChineseChar(235,130,5,24,BLACK);
                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,130,"OFF",BLACK);
                                            else
                                                ShowChineseChar(235,130,6,24,BLACK);

                                        }
                                    if(EnCH8)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,170,"ON",BLACK);
                                            else
                                                ShowChineseChar(235,170,5,24,BLACK);
                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,170,"OFF",BLACK);
                                            else
                                                ShowChineseChar(235,170,6,24,BLACK);

                                        }

                                }
                            *SubAnchor=0x01;
                            break;
                        case 0x03:
                            if(flag_dev.activity_num==1)
                                {
                                    if(EnCH1)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,50,"ON",BLACK);
                                            else
                                                ShowChineseChar(235,50,5,24,BLACK);

                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,50,"0FF",BLACK);
                                            else
                                                ShowChineseChar(235,50,6,24,BLACK);

                                        }

                                    if(EnCH2)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,90,"ON",RED);
                                            else
                                                ShowChineseChar(235,90,5,24,RED);

                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,90,"OFF",RED);
                                            else
                                                ShowChineseChar(235,90,6,24,RED);
                                        }
                                    if(EnCH3)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,130,"ON",BLACK);
                                            else
                                                ShowChineseChar(235,130,5,24,BLACK);
                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,130,"OFF",BLACK);
                                            else
                                                ShowChineseChar(235,130,6,24,BLACK);
                                        }

                                    if(EnCH4)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,170,"ON",BLACK);
                                            else
                                                ShowChineseChar(235,170,5,24,BLACK);

                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,170,"OFF",BLACK);
                                            else
                                                ShowChineseChar(235,170,6,24,BLACK);
                                        }
                                }
                            else if(flag_dev.activity_num==2)
                                {
                                    if(EnCH5)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,50,"ON",BLACK);
                                            else
                                                ShowChineseChar(235,50,5,24,BLACK);
                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,50,"0FF",BLACK);
                                            else
                                                ShowChineseChar(235,50,6,24,BLACK);
                                        }

                                    if(EnCH6)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,90,"ON",RED);
                                            else
                                                ShowChineseChar(235,90,5,24,RED);
                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,90,"OFF",RED);
                                            else
                                                ShowChineseChar(235,90,6,24,RED);
                                        }
                                    if(EnCH7)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,130,"ON",BLACK);
                                            else
                                                ShowChineseChar(235,130,5,24,BLACK);
                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,130,"OFF",BLACK);
                                            else
                                                ShowChineseChar(235,130,6,24,BLACK);

                                        }
                                    if(EnCH8)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,170,"ON",BLACK);
                                            else
                                                ShowChineseChar(235,170,5,24,BLACK);
                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,170,"OFF",BLACK);
                                            else
                                                ShowChineseChar(235,170,6,24,BLACK);

                                        }

                                }
                            *SubAnchor=0x02;
                            break;
                        case 0x04:
                            if(flag_dev.activity_num==1)
                                {
                                    if(EnCH1)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,50,"ON",BLACK);
                                            else
                                                ShowChineseChar(235,50,5,24,BLACK);

                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,50,"0FF",BLACK);
                                            else
                                                ShowChineseChar(235,50,6,24,BLACK);

                                        }

                                    if(EnCH2)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,90,"ON",BLACK);
                                            else
                                                ShowChineseChar(235,90,5,24,BLACK);

                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,90,"OFF",BLACK);
                                            else
                                                ShowChineseChar(235,90,6,24,BLACK);
                                        }
                                    if(EnCH3)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,130,"ON",RED);
                                            else
                                                ShowChineseChar(235,130,5,24,RED);
                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,130,"OFF",RED);
                                            else
                                                ShowChineseChar(235,130,6,24,RED);
                                        }

                                    if(EnCH4)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,170,"ON",BLACK);
                                            else
                                                ShowChineseChar(235,170,5,24,BLACK);

                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,170,"OFF",BLACK);
                                            else
                                                ShowChineseChar(235,170,6,24,BLACK);
                                        }
                                }
                            else if(flag_dev.activity_num==2)
                                {
                                    if(EnCH5)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,50,"ON",BLACK);
                                            else
                                                ShowChineseChar(235,50,5,24,BLACK);
                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,50,"0FF",BLACK);
                                            else
                                                ShowChineseChar(235,50,6,24,BLACK);
                                        }

                                    if(EnCH6)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,90,"ON",BLACK);
                                            else
                                                ShowChineseChar(235,90,5,24,BLACK);
                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,90,"OFF",BLACK);
                                            else
                                                ShowChineseChar(235,90,6,24,BLACK);
                                        }
                                    if(EnCH7)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,130,"ON",RED);
                                            else
                                                ShowChineseChar(235,130,5,24,RED);
                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,130,"OFF",RED);
                                            else
                                                ShowChineseChar(235,130,6,24,RED);

                                        }
                                    if(EnCH8)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,170,"ON",BLACK);
                                            else
                                                ShowChineseChar(235,170,5,24,BLACK);
                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,170,"OFF",BLACK);
                                            else
                                                ShowChineseChar(235,170,6,24,BLACK);

                                        }

                                }
                            *SubAnchor=0x03;
                            break;
                        case 0x05:
                            if(flag_dev.activity_num==1)
                                {
                                    if(EnCH1)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,50,"ON",BLACK);
                                            else
                                                ShowChineseChar(235,50,5,24,BLACK);

                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,50,"0FF",BLACK);
                                            else
                                                ShowChineseChar(235,50,6,24,BLACK);

                                        }

                                    if(EnCH2)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,90,"ON",BLACK);
                                            else
                                                ShowChineseChar(235,90,5,24,BLACK);

                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,90,"OFF",BLACK);
                                            else
                                                ShowChineseChar(235,90,6,24,BLACK);
                                        }
                                    if(EnCH3)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,130,"ON",BLACK);
                                            else
                                                ShowChineseChar(235,130,5,24,BLACK);
                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,130,"OFF",BLACK);
                                            else
                                                ShowChineseChar(235,130,6,24,BLACK);
                                        }

                                    if(EnCH4)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,170,"ON",RED);
                                            else
                                                ShowChineseChar(235,170,5,24,RED);

                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,170,"OFF",RED);
                                            else
                                                ShowChineseChar(235,170,6,24,RED);
                                        }
                                }
                            else if(flag_dev.activity_num==2)
                                {
                                    if(EnCH5)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,50,"ON",BLACK);
                                            else
                                                ShowChineseChar(235,50,5,24,BLACK);
                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,50,"0FF",BLACK);
                                            else
                                                ShowChineseChar(235,50,6,24,BLACK);
                                        }

                                    if(EnCH6)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,90,"ON",BLACK);
                                            else
                                                ShowChineseChar(235,90,5,24,BLACK);
                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,90,"OFF",BLACK);
                                            else
                                                ShowChineseChar(235,90,6,24,BLACK);
                                        }
                                    if(EnCH7)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,130,"ON",BLACK);
                                            else
                                                ShowChineseChar(235,130,5,24,BLACK);
                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,130,"OFF",BLACK);
                                            else
                                                ShowChineseChar(235,130,6,24,BLACK);

                                        }
                                    if(EnCH8)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,170,"ON",RED);
                                            else
                                                ShowChineseChar(235,170,5,24,RED);
                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,170,"OFF",RED);
                                            else
                                                ShowChineseChar(235,170,6,24,RED);

                                        }

                                }
                            gui_draw_arcrectangle(120,210,80,30,1,1,BLUE,BLUE);
                            gui_draw_arcrectangle(125,212,70,28,1,1,WHITE,WHITE);
                            if(flag_dev.langage==1)
                                LCD_Show_3030_String(130,210,"SAVE",BLACK);
                            else
                                ShowTwoChineseChar(135,213,10,11,24,BLACK);

                            *SubAnchor=0x04;
                            break;
                        case 0x06:
                            gui_draw_arcrectangle(120,210,80,30,1,1,BLUE,BLUE);
                            gui_draw_arcrectangle(125,212,70,28,1,1,RED,RED);
                            if(flag_dev.langage==1)
                                LCD_Show_3030_String(130,210,"SAVE",WHITE);
                            else
                                ShowTwoChineseChar(135,213,10,11,24,WHITE);
                            LCD_DrawLtrigo(230,215,255,240,LEFT,WHITE);
                            *SubAnchor=0x05;
                            break;
                        case 0x07:
                            LCD_Show_picture(250,210,WHITE,0);
                            LCD_DrawLtrigo(230,215,255,240,LEFT,RED);
                            *SubAnchor=0x06;
                            break;
                        case 0x08:
                            LCD_DrawLtrigo(282,215,307,240,RIGHT,WHITE);
                            LCD_Show_picture(250,210,RED,0);
                            *SubAnchor=0x07;
                            break;
                        }
                }



            if(flag_dev.action_flag==SWITCH&&encoder_dev.EN_KEY==EN_KEY_DOWN)
                {

                    switch(*SubAnchor)
                        {
                        case 0x01:
                            if(flag_dev.activity_num==1)
                                {
                                    gui_draw_arcrectangle(222,48, 60,30,1,1,WHITE,WHITE);
                                    if(EnCH1)
                                        {
																																								
																					  if(flag_dev.langage==1)
                                            LCD_Show_3030_String(230,50,"OFF",RED);
																						else
																						ShowChineseChar(235,50,6,24,RED);	
																						ResetCH1
                                            EnCH1=0;
                                        }
                                    else
                                        {																				
																					
																					if(flag_dev.langage==1)
                                          	  LCD_Show_3030_String(230,50,"ON",RED);
																					else
																						ShowChineseChar(235,50,5,24,RED);	
                                            EnCH1=1;
                                        }
                                }
                            else if(flag_dev.activity_num==2)
                                {
                                    gui_draw_arcrectangle(222,48, 60,30,1,1,WHITE,WHITE);
                                    if(EnCH5)
                                        {
																					if(flag_dev.langage==1)
                                          	  LCD_Show_3030_String(230,50,"OFF",RED);
																					else
																						ShowChineseChar(235,50,6,24,RED);	
																					  ResetCH5
                                            EnCH5=0;
                                        }
                                    else
                                        {
																					if(flag_dev.langage==1)
                                          	  LCD_Show_3030_String(230,50,"ON",RED);
																					else
																						ShowChineseChar(235,50,5,24,RED);	
                                           EnCH5=1;
                                        }
                                }
                            break;
                        case 0x02:
                            if(flag_dev.activity_num==1)
                                {
                                    gui_draw_arcrectangle(222,89, 60,30,1,1,WHITE,WHITE);
                                    if(EnCH2)
                                        {
																					if(flag_dev.langage==1)
                                          	  LCD_Show_3030_String(230,90,"OFF",RED);
																					else
																						ShowChineseChar(235,90,6,24,RED);	
																					ResetCH2
                                            EnCH2=0;
                                        }
                                    else
                                        {
																					if(flag_dev.langage==1)
                                          	  LCD_Show_3030_String(230,90,"ON",RED);
																					else
																						ShowChineseChar(235,90,5,24,RED);	
                                            EnCH2=1;
                                        }
                                }
                            else if(flag_dev.activity_num==2)
                                {
                                    gui_draw_arcrectangle(222,89, 60,30,1,1,WHITE,WHITE);
                                    if(EnCH6)
                                        {
																					if(flag_dev.langage==1)
                                          	  LCD_Show_3030_String(230,90,"OFF",RED);
																					else
																					 	ShowChineseChar(235,90,6,24,RED);	
																					  ResetCH6
                                            EnCH6=0;
                                        }
                                    else
                                        {
																					if(flag_dev.langage==1)
                                          	  LCD_Show_3030_String(230,90,"ON",RED);
																					else
																						ShowChineseChar(235,90,5,24,RED);	
                                            EnCH6=1;
                                        }
                                }
                            break;
                        case 0x03:
                            if(flag_dev.activity_num==1)
                                {
                                    gui_draw_arcrectangle(222,130, 60,30,1,1,WHITE,WHITE);
                                    if(EnCH3)
                                        {
																					if(flag_dev.langage==1)
                                          	  LCD_Show_3030_String(230,130,"OFF",RED);
																					else
																						ShowChineseChar(235,130,6,24,RED);	
																					  ResetCH3
                                            EnCH3=0;
                                        }
                                    else
                                        {
																					if(flag_dev.langage==1)
                                          	  LCD_Show_3030_String(230,130,"ON",RED);
																					else
																						ShowChineseChar(235,130,5,24,RED);	
                                            EnCH3=1;
                                        }
                                }
                            else if(flag_dev.activity_num==2)
                                {
                                    gui_draw_arcrectangle(222,130, 60,30,1,1,WHITE,WHITE);
                                    if(EnCH7)
                                        {
																					if(flag_dev.langage==1)
                                          	  LCD_Show_3030_String(230,130,"OFF",RED);
																					else
																						  ShowChineseChar(235,130,6,24,RED);	
																					 ResetCH7
                                            EnCH7=0;
                                        }
                                    else
                                        {
																					if(flag_dev.langage==1)
                                          	  LCD_Show_3030_String(230,130,"ON",RED);
																					else
																						  ShowChineseChar(235,130,5,24,RED);	
                                            EnCH7=1;
                                        }
                                }
                            break;
                        case 0x04:
                            if(flag_dev.activity_num==1)
                                {
                                    gui_draw_arcrectangle(222,171, 60,30,1,1,WHITE,WHITE);
                                    if(EnCH4)
                                        {
																					if(flag_dev.langage==1)
                                          	  LCD_Show_3030_String(230,170,"OFF",RED);
																					else
																						  ShowChineseChar(235,170,6,24,RED);	
																					ResetCH4
                                            EnCH4=0;
                                        }
                                    else
                                        {
																					if(flag_dev.langage==1)
                                          	  LCD_Show_3030_String(230,170,"ON",RED);
																					else
																						  ShowChineseChar(235,170,5,24,RED);	
                                            EnCH4=1;
																					
                                        }
                                }
                            else if(flag_dev.activity_num==2)
                                {
                                    gui_draw_arcrectangle(222,171, 60,30,1,1,WHITE,WHITE);
                                    if(EnCH8)
                                        {
																					if(flag_dev.langage==1)
                                          	  LCD_Show_3030_String(230,170,"OFF",RED);
																					else
																						  ShowChineseChar(235,170,6,24,RED);	
																					ResetCH8
                                            EnCH8=0;
                                        }
                                    else
                                        {
																					if(flag_dev.langage==1)
                                          	  LCD_Show_3030_String(230,170,"ON",RED);
																					else
																						  ShowChineseChar(235,170,5,24,RED);	
                                            EnCH8=1;
                                        }
                                }
                            break;
                        case 0x05:
                            flag_dev.save_flag=1;
                            break;
                        case 0x06:
                            if(flag_dev.activity_num==1)
                                {
                                    gui_draw_arcrectangle(115,0,190,40,1,1,RED,RED);
                                    gui_draw_arcrectangle(95,44,225,39,3,1,BLUE,BLUE);
                                    gui_draw_arcrectangle(95,85,225,39, 3,1,BLUE,BLUE);
                                    gui_draw_arcrectangle(95,126,225,39,3,1,BLUE,BLUE);
                                    gui_draw_arcrectangle(95,167,225,39,3,1,BLUE,BLUE);

                                    gui_draw_arcrectangle(172,48, 145,30,1,1,WHITE,WHITE);
                                    gui_draw_arcrectangle(172,89, 145,30,1,1,WHITE,WHITE);
                                    gui_draw_arcrectangle(172,130,145,30,1,1,WHITE,WHITE);
                                    gui_draw_arcrectangle(172,171,145,30,1,1,WHITE,WHITE);

                                    LCD_DrawLtrigo(172, 48,202,78,LEFT,BLUE);
                                    LCD_DrawLtrigo(287, 48,317,78,RIGHT,BLUE);

                                    LCD_DrawLtrigo(172, 89,202,118,LEFT,BLUE);
                                    LCD_DrawLtrigo(287, 89,317,118,RIGHT,BLUE);

                                    LCD_DrawLtrigo(172, 130,202,158,LEFT,BLUE);
                                    LCD_DrawLtrigo(287, 130,317,158,RIGHT,BLUE);

                                    LCD_DrawLtrigo(172, 172,202,198,LEFT,BLUE);
                                    LCD_DrawLtrigo(287, 172,317,198,RIGHT,BLUE);

                                    LCD_DrawLtrigo(95,0,125,40,LEFT,WHITE);
                                    LCD_DrawLtrigo(290,0,319,40,RIGHT,WHITE);
                                    if(flag_dev.langage==1)
                                        {
                                            LCD_Show_3030_String(110,5,"CHAN SWITCH2/2",WHITE);
                                        }
                                    else
                                        {
                                            ShowTwoChineseChar(145,11,14,15,24,WHITE);
                                            ShowTwoChineseChar(193,11,5,6,24,WHITE);
                                            LCD_Show_2424_String(241,14,"2/2",WHITE);
                                        }
                                    if(flag_dev.langage==1)
                                        {
                                            LCD_Show_2424_String(100,50,"CHAN5",WHITE);
                                            LCD_Show_2424_String(100,91,"CHAN6",WHITE);
                                            LCD_Show_2424_String(100,132,"CHAN7",WHITE);
                                            LCD_Show_2424_String(100,173,"CHAN8",WHITE);
                                        }
                                    else
                                        {
                                            ShowTwoChineseChar(100,50,0,1,24,WHITE);
                                            LCD_Show_2424_String(148,50,"5",WHITE);
                                            ShowTwoChineseChar(100,92,0,1,24,WHITE);
                                            LCD_Show_2424_String(148,92,"6",WHITE);
                                            ShowTwoChineseChar(100,133,0,1,24,WHITE);
                                            LCD_Show_2424_String(148,133,"7",WHITE);
                                            ShowTwoChineseChar(100,175,0,1,24,WHITE);
                                            LCD_Show_2424_String(148,175,"8",WHITE);
                                        }

                                    if(EnCH5)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,50,"ON",BLACK);
                                            else
                                                ShowChineseChar(235,50,5,24,BLACK);
                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,50,"0FF",BLACK);
                                            else
                                                ShowChineseChar(235,50,6,24,BLACK);
                                        }

                                    if(EnCH6)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,90,"ON",BLACK);
                                            else
                                                ShowChineseChar(235,90,5,24,BLACK);
                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,90,"OFF",BLACK);
                                            else
                                                ShowChineseChar(235,90,6,24,BLACK);
                                        }
                                    if(EnCH7)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,130,"ON",BLACK);
                                            else
                                                ShowChineseChar(235,130,5,24,BLACK);
                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,130,"OFF",BLACK);
                                            else
                                                ShowChineseChar(235,130,6,24,BLACK);

                                        }
                                    if(EnCH8)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,170,"ON",BLACK);
                                            else
                                                ShowChineseChar(235,170,5,24,BLACK);
                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,170,"OFF",BLACK);
                                            else
                                                ShowChineseChar(235,170,6,24,BLACK);

                                        }


                                    flag_dev.activity_num=2;

                                }
                            else if(flag_dev.activity_num==2)
                                {

                                    gui_draw_arcrectangle(115,0,190,40,1,1,RED,RED);
                                    gui_draw_arcrectangle(95,44,225,39,3,1,BLUE,BLUE);
                                    gui_draw_arcrectangle(95,85,225,39, 3,1,BLUE,BLUE);
                                    gui_draw_arcrectangle(95,126,225,39,3,1,BLUE,BLUE);
                                    gui_draw_arcrectangle(95,167,225,39,3,1,BLUE,BLUE);

                                    gui_draw_arcrectangle(172,48, 145,30,1,1,WHITE,WHITE);
                                    gui_draw_arcrectangle(172,89, 145,30,1,1,WHITE,WHITE);
                                    gui_draw_arcrectangle(172,130,145,30,1,1,WHITE,WHITE);
                                    gui_draw_arcrectangle(172,171,145,30,1,1,WHITE,WHITE);

                                    LCD_DrawLtrigo(172, 48,202,78,LEFT,BLUE);
                                    LCD_DrawLtrigo(287, 48,317,78,RIGHT,BLUE);

                                    LCD_DrawLtrigo(172, 89,202,118,LEFT,BLUE);
                                    LCD_DrawLtrigo(287, 89,317,118,RIGHT,BLUE);

                                    LCD_DrawLtrigo(172, 130,202,158,LEFT,BLUE);
                                    LCD_DrawLtrigo(287, 130,317,158,RIGHT,BLUE);

                                    LCD_DrawLtrigo(172, 172,202,198,LEFT,BLUE);
                                    LCD_DrawLtrigo(287, 172,317,198,RIGHT,BLUE);

                                    LCD_DrawLtrigo(95,0,125,40,LEFT,WHITE);
                                    LCD_DrawLtrigo(290,0,319,40,RIGHT,WHITE);
                                    if(flag_dev.langage==1)
                                        LCD_Show_3030_String(110,5,"CHAN SWITCH1/2",WHITE);
                                    else
                                        {
                                            ShowTwoChineseChar(145,11,14,15,24,WHITE);
                                            ShowTwoChineseChar(193,11,5,6,24,WHITE);
                                            LCD_Show_2424_String(241,14,"1/2",WHITE);
                                        }
                                    if(flag_dev.langage==1)
                                        {
                                            LCD_Show_2424_String(100,50,"CHAN1",WHITE);
                                            LCD_Show_2424_String(100,91,"CHAN2",WHITE);
                                            LCD_Show_2424_String(100,132,"CHAN3",WHITE);
                                            LCD_Show_2424_String(100,173,"CHAN4",WHITE);
                                        }
                                    else
                                        {
                                            ShowTwoChineseChar(100,50,0,1,24,WHITE);
                                            LCD_Show_2424_String(148,50,"1",WHITE);
                                            ShowTwoChineseChar(100,92,0,1,24,WHITE);
                                            LCD_Show_2424_String(148,92,"2",WHITE);
                                            ShowTwoChineseChar(100,133,0,1,24,WHITE);
                                            LCD_Show_2424_String(148,133,"3",WHITE);
                                            ShowTwoChineseChar(100,175,0,1,24,WHITE);
                                            LCD_Show_2424_String(148,175,"4",WHITE);
                                        }

                                    if(EnCH1)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,50,"ON",BLACK);
                                            else
                                                ShowChineseChar(235,50,5,24,BLACK);

                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,50,"0FF",BLACK);
                                            else
                                                ShowChineseChar(235,50,6,24,BLACK);

                                        }

                                    if(EnCH2)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,90,"ON",BLACK);
                                            else
                                                ShowChineseChar(235,90,5,24,BLACK);

                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,90,"OFF",BLACK);
                                            else
                                                ShowChineseChar(235,90,6,24,BLACK);
                                        }
                                    if(EnCH3)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,130,"ON",BLACK);
                                            else
                                                ShowChineseChar(235,130,5,24,BLACK);
                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,130,"OFF",BLACK);
                                            else
                                                ShowChineseChar(235,130,6,24,BLACK);
                                        }

                                    if(EnCH4)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,170,"ON",BLACK);
                                            else
                                                ShowChineseChar(235,170,5,24,BLACK);

                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,170,"OFF",BLACK);
                                            else
                                                ShowChineseChar(235,170,6,24,BLACK);
                                        }


                                    flag_dev.activity_num=1;
                                }
                            break;
                        case 0x07:
                            flag_dev.TOSUBPAGE=0;
                            *SubAnchor=0;
                            LCD_Show_picture(250,210,WHITE,0);
                            break;
                        case 0x08:
                            if(flag_dev.activity_num==1)
                                {

                                    gui_draw_arcrectangle(115,0,190,40,1,1,RED,RED);

                                    gui_draw_arcrectangle(95,44,225,39,3,1,BLUE,BLUE);
                                    gui_draw_arcrectangle(95,85,225,39, 3,1,BLUE,BLUE);
                                    gui_draw_arcrectangle(95,126,225,39,3,1,BLUE,BLUE);
                                    gui_draw_arcrectangle(95,167,225,39,3,1,BLUE,BLUE);

                                    gui_draw_arcrectangle(172,48, 145,30,1,1,WHITE,WHITE);
                                    gui_draw_arcrectangle(172,89, 145,30,1,1,WHITE,WHITE);
                                    gui_draw_arcrectangle(172,130,145,30,1,1,WHITE,WHITE);
                                    gui_draw_arcrectangle(172,171,145,30,1,1,WHITE,WHITE);

                                    LCD_DrawLtrigo(172, 48,202,78,LEFT,BLUE);
                                    LCD_DrawLtrigo(287, 48,317,78,RIGHT,BLUE);

                                    LCD_DrawLtrigo(172, 89,202,118,LEFT,BLUE);
                                    LCD_DrawLtrigo(287, 89,317,118,RIGHT,BLUE);

                                    LCD_DrawLtrigo(172, 130,202,158,LEFT,BLUE);
                                    LCD_DrawLtrigo(287, 130,317,158,RIGHT,BLUE);

                                    LCD_DrawLtrigo(172, 172,202,198,LEFT,BLUE);
                                    LCD_DrawLtrigo(287, 172,317,198,RIGHT,BLUE);

                                    LCD_DrawLtrigo(95,0,125,40,LEFT,WHITE);
                                    LCD_DrawLtrigo(290,0,319,40,RIGHT,WHITE);
                                    if(flag_dev.langage==1)
                                        LCD_Show_3030_String(110,5,"CHAN SWITCH2/2",WHITE);
                                    else
                                        {
                                            ShowTwoChineseChar(145,11,14,15,24,WHITE);
                                            ShowTwoChineseChar(193,11,5,6,24,WHITE);
                                            LCD_Show_2424_String(241,14,"2/2",WHITE);
                                        }
                                    if(flag_dev.langage==1)
                                        {
                                            LCD_Show_2424_String(100,50,"CHAN5",WHITE);
                                            LCD_Show_2424_String(100,91,"CHAN6",WHITE);
                                            LCD_Show_2424_String(100,132,"CHAN7",WHITE);
                                            LCD_Show_2424_String(100,173,"CHAN8",WHITE);
                                        }
                                    else
                                        {
                                            ShowTwoChineseChar(100,50,0,1,24,WHITE);
                                            LCD_Show_2424_String(148,50,"5",WHITE);
                                            ShowTwoChineseChar(100,92,0,1,24,WHITE);
                                            LCD_Show_2424_String(148,92,"6",WHITE);
                                            ShowTwoChineseChar(100,133,0,1,24,WHITE);
                                            LCD_Show_2424_String(148,133,"7",WHITE);
                                            ShowTwoChineseChar(100,175,0,1,24,WHITE);
                                            LCD_Show_2424_String(148,175,"8",WHITE);
                                        }

                                    if(EnCH5)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,50,"ON",BLACK);
                                            else
                                                ShowChineseChar(235,50,5,24,BLACK);
                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,50,"0FF",BLACK);
                                            else
                                                ShowChineseChar(235,50,6,24,BLACK);
                                        }

                                    if(EnCH6)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,90,"ON",BLACK);
                                            else
                                                ShowChineseChar(235,90,5,24,BLACK);
                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,90,"OFF",BLACK);
                                            else
                                                ShowChineseChar(235,90,6,24,BLACK);
                                        }
                                    if(EnCH7)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,130,"ON",BLACK);
                                            else
                                                ShowChineseChar(235,130,5,24,BLACK);
                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,130,"OFF",BLACK);
                                            else
                                                ShowChineseChar(235,130,6,24,BLACK);

                                        }
                                    if(EnCH8)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,170,"ON",BLACK);
                                            else
                                                ShowChineseChar(235,170,5,24,BLACK);
                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,170,"OFF",BLACK);
                                            else
                                                ShowChineseChar(235,170,6,24,BLACK);

                                        }



                                    flag_dev.activity_num=2;

                                }
                            else if(flag_dev.activity_num==2)
                                {
                                    gui_draw_arcrectangle(115,0,190,40,1,1,RED,RED);
                                    gui_draw_arcrectangle(95,44,225,39,3,1,BLUE,BLUE);
                                    gui_draw_arcrectangle(95,85,225,39, 3,1,BLUE,BLUE);
                                    gui_draw_arcrectangle(95,126,225,39,3,1,BLUE,BLUE);
                                    gui_draw_arcrectangle(95,167,225,39,3,1,BLUE,BLUE);

                                    gui_draw_arcrectangle(172,48, 145,30,1,1,WHITE,WHITE);
                                    gui_draw_arcrectangle(172,89, 145,30,1,1,WHITE,WHITE);
                                    gui_draw_arcrectangle(172,130,145,30,1,1,WHITE,WHITE);
                                    gui_draw_arcrectangle(172,171,145,30,1,1,WHITE,WHITE);

                                    LCD_DrawLtrigo(172, 48,202,78,LEFT,BLUE);
                                    LCD_DrawLtrigo(287, 48,317,78,RIGHT,BLUE);

                                    LCD_DrawLtrigo(172, 89,202,118,LEFT,BLUE);
                                    LCD_DrawLtrigo(287, 89,317,118,RIGHT,BLUE);

                                    LCD_DrawLtrigo(172, 130,202,158,LEFT,BLUE);
                                    LCD_DrawLtrigo(287, 130,317,158,RIGHT,BLUE);

                                    LCD_DrawLtrigo(172, 172,202,198,LEFT,BLUE);
                                    LCD_DrawLtrigo(287, 172,317,198,RIGHT,BLUE);

                                    LCD_DrawLtrigo(95,0,125,40,LEFT,WHITE);
                                    LCD_DrawLtrigo(290,0,319,40,RIGHT,WHITE);
                                    if(flag_dev.langage==1)
                                        LCD_Show_3030_String(110,5,"CHAN SWITCH1/2",WHITE);
                                    else
                                        {
                                            ShowTwoChineseChar(145,11,14,15,24,WHITE);
                                            ShowTwoChineseChar(193,11,5,6,24,WHITE);
                                            LCD_Show_2424_String(241,14,"1/2",WHITE);
                                        }

                                    if(flag_dev.langage==1)
                                        {
                                            LCD_Show_2424_String(100,50,"CHAN1",WHITE);
                                            LCD_Show_2424_String(100,91,"CHAN2",WHITE);
                                            LCD_Show_2424_String(100,132,"CHAN3",WHITE);
                                            LCD_Show_2424_String(100,173,"CHAN4",WHITE);
                                        }
                                    else
                                        {
                                            ShowTwoChineseChar(100,50,0,1,24,WHITE);
                                            LCD_Show_2424_String(148,50,"1",WHITE);
                                            ShowTwoChineseChar(100,92,0,1,24,WHITE);
                                            LCD_Show_2424_String(148,92,"2",WHITE);
                                            ShowTwoChineseChar(100,133,0,1,24,WHITE);
                                            LCD_Show_2424_String(148,133,"3",WHITE);
                                            ShowTwoChineseChar(100,175,0,1,24,WHITE);
                                            LCD_Show_2424_String(148,175,"4",WHITE);
                                        }

                                    if(EnCH1)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,50,"ON",BLACK);
                                            else
                                                ShowChineseChar(235,50,5,24,BLACK);

                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,50,"0FF",BLACK);
                                            else
                                                ShowChineseChar(235,50,6,24,BLACK);

                                        }

                                    if(EnCH2)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,90,"ON",BLACK);
                                            else
                                                ShowChineseChar(235,90,5,24,BLACK);

                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,90,"OFF",BLACK);
                                            else
                                                ShowChineseChar(235,90,6,24,BLACK);
                                        }
                                    if(EnCH3)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,130,"ON",BLACK);
                                            else
                                                ShowChineseChar(235,130,5,24,BLACK);
                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,130,"OFF",BLACK);
                                            else
                                                ShowChineseChar(235,130,6,24,BLACK);
                                        }

                                    if(EnCH4)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,170,"ON",BLACK);
                                            else
                                                ShowChineseChar(235,170,5,24,BLACK);

                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_3030_String(230,170,"OFF",BLACK);
                                            else
                                                ShowChineseChar(235,170,6,24,BLACK);
                                        }

                                    flag_dev.activity_num=1;
                                }
                            break;
                        }



                }
        }


}

void EncoderDate(u8 *SubAnchor)
{

    if(flag_dev.action_flag==DATE)
        {

            if(encoder_dev.EN_STATE==SUBRIGHT)
                {

                    switch(*SubAnchor)
                        {
                        case 0x00:
                            LCD_ShowNum(135,90,date_time_data.date_year,4,30,RED,WHITE);
                            LCD_ShowNum(211,90,date_time_data.date_month,2,30,BLACK,WHITE);
                            LCD_ShowNum(255,90,date_time_data.date_day,2,30,BLACK,WHITE);
                            LCD_ShowNum(175,172,date_time_data.time_hour,2,30,BLACK,WHITE);
                            LCD_ShowNum(215,172,date_time_data.time_min,2,30,BLACK,WHITE);
                            *SubAnchor=0x01;
                            break;
                        case 0x01:
                            LCD_ShowNum(135,90,date_time_data.date_year,4,30,BLACK,WHITE);
                            LCD_ShowNum(211,90,date_time_data.date_month,2,30,RED,WHITE);
                            LCD_ShowNum(255,90,date_time_data.date_day,2,30,BLACK,WHITE);
                            LCD_ShowNum(175,172,date_time_data.time_hour,2,30,BLACK,WHITE);
                            LCD_ShowNum(215,172,date_time_data.time_min,2,30,BLACK,WHITE);
                            *SubAnchor=0x02;
                            break;
                        case 0x02:
                            LCD_ShowNum(135,90,date_time_data.date_year,4,30,BLACK,WHITE);
                            LCD_ShowNum(211,90,date_time_data.date_month,2,30,BLACK,WHITE);
                            LCD_ShowNum(255,90,date_time_data.date_day,2,30,RED,WHITE);
                            LCD_ShowNum(175,172,date_time_data.time_hour,2,30,BLACK,WHITE);
                            LCD_ShowNum(215,172,date_time_data.time_min,2,30,BLACK,WHITE);
                            *SubAnchor=0x03;
                            break;
                        case 0x03:
                            LCD_ShowNum(135,90,date_time_data.date_year,4,30,BLACK,WHITE);
                            LCD_ShowNum(211,90,date_time_data.date_month,2,30,BLACK,WHITE);
                            LCD_ShowNum(255,90,date_time_data.date_day,2,30,BLACK,WHITE);
                            LCD_ShowNum(175,172,date_time_data.time_hour,2,30,RED,WHITE);
                            LCD_ShowNum(215,172,date_time_data.time_min,2,30,BLACK,WHITE);
                            *SubAnchor=0x04;
                            break;
                        case 0x04:
                            LCD_ShowNum(135,90,date_time_data.date_year,4,30,BLACK,WHITE);
                            LCD_ShowNum(211,90,date_time_data.date_month,2,30,BLACK,WHITE);
                            LCD_ShowNum(255,90,date_time_data.date_day,2,30,BLACK,WHITE);
                            LCD_ShowNum(175,172,date_time_data.time_hour,2,30,BLACK,WHITE);
                            LCD_ShowNum(215,172,date_time_data.time_min,2,30,RED,WHITE);
                            *SubAnchor=0x05;
                            break;
                        case 0x05:
                            LCD_ShowNum(215,172,date_time_data.time_min,2,30,BLACK,WHITE);
                            gui_draw_arcrectangle(120,210,80,30,1,1,BLUE,BLUE);
                            gui_draw_arcrectangle(125,212,70,28,1,1,RED,RED);
                            if(flag_dev.langage==1)
                                LCD_Show_3030_String(130,210,"SAVE",WHITE);
                            else
                                ShowTwoChineseChar(135,213,10,11,24,WHITE);
                            LCD_DrawLtrigo(230,215,255,240,LEFT,WHITE);

                            *SubAnchor=0x06;
                            break;
                        case 0x06:
                            gui_draw_arcrectangle(120,210,80,30,1,1,BLUE,BLUE);
                            gui_draw_arcrectangle(125,212,70,28,1,1,WHITE,WHITE);
                            if(flag_dev.langage==1)
                                LCD_Show_3030_String(130,210,"SAVE",BLACK);
                            else
                                ShowTwoChineseChar(135,213,10,11,24,BLACK);
                            LCD_DrawLtrigo(230,215,255,240,LEFT,RED);
                            *SubAnchor=0x07;
                            break;
                        case 0x07:
                            LCD_DrawLtrigo(230,215,255,240,LEFT,WHITE);
                            LCD_Show_picture(250,210,RED,0);

                            *SubAnchor=0x08;
                            break;
                        case 0x08:
                            LCD_DrawLtrigo(282,215,307,240,RIGHT,RED);
                            LCD_Show_picture(250,210,WHITE,0);

                            *SubAnchor=0x09;
                            break;
                        }
                }
            else if(encoder_dev.EN_STATE==SUBLEFT)
                {

                    switch(*SubAnchor)
                        {

                        case 0x02:
                            LCD_ShowNum(135,90,date_time_data.date_year,4,30,RED,WHITE);
                            LCD_ShowNum(211,90,date_time_data.date_month,2,30,BLACK,WHITE);
                            LCD_ShowNum(255,90,date_time_data.date_day,2,30,BLACK,WHITE);
                            LCD_ShowNum(175,172,date_time_data.time_hour,2,30,BLACK,WHITE);
                            LCD_ShowNum(215,172,date_time_data.time_min,2,30,BLACK,WHITE);
                            *SubAnchor=0x01;
                            break;
                        case 0x03:
                            LCD_ShowNum(135,90,date_time_data.date_year,4,30,BLACK,WHITE);
                            LCD_ShowNum(211,90,date_time_data.date_month,2,30,RED,WHITE);
                            LCD_ShowNum(255,90,date_time_data.date_day,2,30,BLACK,WHITE);
                            LCD_ShowNum(175,172,date_time_data.time_hour,2,30,BLACK,WHITE);
                            LCD_ShowNum(215,172,date_time_data.time_min,2,30,BLACK,WHITE);
                            *SubAnchor=0x02;
                            break;
                        case 0x04:
                            LCD_ShowNum(135,90,date_time_data.date_year,4,30,BLACK,WHITE);
                            LCD_ShowNum(211,90,date_time_data.date_month,2,30,BLACK,WHITE);
                            LCD_ShowNum(255,90,date_time_data.date_day,2,30,RED,WHITE);
                            LCD_ShowNum(175,172,date_time_data.time_hour,2,30,BLACK,WHITE);
                            LCD_ShowNum(215,172,date_time_data.time_min,2,30,BLACK,WHITE);
                            *SubAnchor=0x03;
                            break;
                        case 0x05:
                            LCD_ShowNum(135,90,date_time_data.date_year,4,30,BLACK,WHITE);
                            LCD_ShowNum(211,90,date_time_data.date_month,2,30,BLACK,WHITE);
                            LCD_ShowNum(255,90,date_time_data.date_day,2,30,BLACK,WHITE);
                            LCD_ShowNum(175,172,date_time_data.time_hour,2,30,RED,WHITE);
                            LCD_ShowNum(215,172,date_time_data.time_min,2,30,BLACK,WHITE);
                            *SubAnchor=0x04;
                            break;
                        case 0x06:
                            LCD_ShowNum(215,172,date_time_data.time_min,2,30,RED,WHITE);
                            gui_draw_arcrectangle(120,210,80,30,1,1,BLUE,BLUE);
                            gui_draw_arcrectangle(125,212,70,28,1,1,WHITE,WHITE);
                            if(flag_dev.langage==1)
                                LCD_Show_3030_String(130,210,"SAVE",BLACK);
                            else
                                ShowTwoChineseChar(135,213,10,11,24,BLACK);
                            LCD_DrawLtrigo(230,215,255,240,LEFT,WHITE);
                            *SubAnchor=0x05;
                            break;
                        case 0x07:
                            gui_draw_arcrectangle(120,210,80,30,1,1,BLUE,BLUE);
                            gui_draw_arcrectangle(125,212,70,28,1,1,RED,RED);
                            if(flag_dev.langage==1)
                                LCD_Show_3030_String(130,210,"SAVE",WHITE);
                            else
                                ShowTwoChineseChar(135,213,10,11,24,WHITE);
                            LCD_DrawLtrigo(230,215,255,240,LEFT,WHITE);
                            *SubAnchor=0x06;
                            break;
                        case 0x08:
                            LCD_DrawLtrigo(230,215,255,240,LEFT,RED);
                            LCD_Show_picture(250,210,WHITE,0);

                            *SubAnchor=0x07;
                            break;
                        case 0x09:
                            LCD_DrawLtrigo(282,215,307,240,RIGHT,WHITE);
                            LCD_Show_picture(250,210,RED,0);

                            *SubAnchor=0x08;
                            break;
                        }

                }
        }
    if(flag_dev.action_flag==DATE&&encoder_dev.EN_KEY==EN_KEY_DOWN)
        {

            switch(*SubAnchor)
                {

                case 0x01:
                    if(flag_dev.anchor!=0)
                        flag_dev.anchor=0;
                    else
                        flag_dev.anchor=1;
                    break;
                case 0x02:
                    if(flag_dev.anchor!=0)
                        flag_dev.anchor=0;
                    else
                        flag_dev.anchor=2;
                    break;
                case 0x03:
                    if(flag_dev.anchor!=0)
                        flag_dev.anchor=0;
                    else
                        flag_dev.anchor=3;
                    break;
                case 0x04:
                    if(flag_dev.anchor!=0)
                        flag_dev.anchor=0;
                    else
                        flag_dev.anchor=4;
                    break;
                case 0x05:
                    if(flag_dev.anchor!=0)
                        flag_dev.anchor=0;
                    else
                        flag_dev.anchor=5;
                    break;
                case 0x06:
                    if(flag_dev.anchor!=0)
                        flag_dev.anchor=0;
                    RTC_Set(date_time_data.date_year,date_time_data.date_month,date_time_data.date_day,date_time_data.time_hour,date_time_data.time_min,0);
                    /*更新秒数用于闹钟*/
                    SECCOUNT=RTC_GetCounter();
                    break;
                case 0x08:
                    flag_dev.TOSUBPAGE=0;
                    *SubAnchor=0;
                    LCD_Show_picture(250,210,WHITE,0);
                    break;
                }


        }


}
void EncoderReset(u8 *SubAnchor)
{

    if(flag_dev.action_flag==RESET)
        {

            if(encoder_dev.EN_STATE==SUBRIGHT)
                {

                    switch(*SubAnchor)
                        {

                        case 0x00:
                            gui_draw_arcrectangle(98,125,50,30,1,1,BLUE,BLUE);
                            gui_draw_arcrectangle(268,125,50,30,1,1,BLUE,BLUE);
                            if(flag_dev.langage==1)
                                {
                                    LCD_Show_3030_String(100,125,"Yes",RED);
                                    LCD_Show_3030_String(280,125,"No",WHITE);
                                }
                            else
                                {
                                    ShowChineseChar(110,127,17,24,RED);
                                    ShowChineseChar(280,127,18,24,WHITE);
                                }
                            *SubAnchor=1;
                            break;
                        case 0x01:
                            gui_draw_arcrectangle(98,125,50,30,1,1,BLUE,BLUE);
                            gui_draw_arcrectangle(268,125,50,30,1,1,BLUE,BLUE);
                            if(flag_dev.langage==1)
                                {
                                    LCD_Show_3030_String(100,125,"Yes",WHITE);
                                    LCD_Show_3030_String(280,125,"No",RED);
                                }
                            else
                                {
                                    ShowChineseChar(110,127,17,24,WHITE);
                                    ShowChineseChar(280,127,18,24,RED);
                                }
                            *SubAnchor=2;
                            break;
                        case 0x02:
                            gui_draw_arcrectangle(98,125,50,30,1,1,BLUE,BLUE);
                            gui_draw_arcrectangle(268,125,50,30,1,1,BLUE,BLUE);
                            if(flag_dev.langage==1)
                                {
                                    LCD_Show_3030_String(100,125,"Yes",WHITE);
                                    LCD_Show_3030_String(280,125,"No",WHITE);
                                }
                            else
                                {
                                    ShowChineseChar(110,127,17,24,WHITE);
                                    ShowChineseChar(280,127,18,24,WHITE);
                                }
                            LCD_Show_picture(250,210,RED,0);
                            *SubAnchor=3;
                            break;
                        }
                }
            else if(encoder_dev.EN_STATE==SUBLEFT)
                {

                    switch(*SubAnchor)
                        {

                        case 0x03:
                            gui_draw_arcrectangle(98,125,50,30,1,1,BLUE,BLUE);
                            gui_draw_arcrectangle(268,125,50,30,1,1,BLUE,BLUE);
                            if(flag_dev.langage)
                                {
                                    LCD_Show_3030_String(100,125,"Yes",WHITE);
                                    LCD_Show_3030_String(280,125,"No",RED);
                                }
                            else
                                {
                                    ShowChineseChar(110,127,17,24,WHITE);
                                    ShowChineseChar(280,127,18,24,RED);
                                }
                            LCD_Show_picture(250,210,WHITE,0);
                            *SubAnchor=2;
                            break;
                        case 0x02:
                            gui_draw_arcrectangle(98,125,50,30,1,1,BLUE,BLUE);
                            gui_draw_arcrectangle(268,125,50,30,1,1,BLUE,BLUE);
                            if(flag_dev.langage==1)
                                {
                                    LCD_Show_3030_String(100,125,"Yes",RED);
                                    LCD_Show_3030_String(280,125,"No",WHITE);
                                }
                            else
                                {
                                    ShowChineseChar(110,127,17,24,RED);
                                    ShowChineseChar(280,127,18,24,WHITE);
                                }
                            LCD_Show_picture(250,210,WHITE,0);
                            *SubAnchor=1;
                            break;
                        }

                }

            if(flag_dev.action_flag==RESET&&encoder_dev.EN_KEY==EN_KEY_DOWN)
                {
                    switch(*SubAnchor)
                        {
                        case 0x01:
                            Reset_deflaut();
                            flag_dev.activity_flag=HOME;
                            flag_dev.action_flag=HOME;
                            flag_dev.screen_flag=HOME;//不支持长按
                            flag_dev.anchor=0;
                            flag_dev.TOSUBPAGE=0;
                            *SubAnchor=0;
                            break;
                        case 0x02:
                            flag_dev.activity_flag=HOME;
                            flag_dev.action_flag=HOME;
                            flag_dev.screen_flag=HOME;//不支持长按
                            flag_dev.anchor=0;
                            flag_dev.TOSUBPAGE=0;
                            *SubAnchor=0;
                            break;
                        case 0x03:
                            flag_dev.TOSUBPAGE=0;
                            *SubAnchor=0;
                            LCD_Show_picture(250,210,WHITE,0);
                            break;
                        }

                }


        }


}
void EncoderIP(u8 *SubAnchor)
{

    if(flag_dev.action_flag==IP)
        {

            if(encoder_dev.EN_STATE==SUBRIGHT)
                {
                    switch(*SubAnchor)
                        {
                        case 0x00:
                            LCD_ShowNum(185,125,ip_data.ip,3,30,RED,WHITE);
                            *SubAnchor=0x01;
                            break;
                        case 0x01:
                            LCD_ShowNum(185,125,ip_data.ip,3,30,BLACK,WHITE);
                            LCD_Show_picture(250,210,RED,0);
                            *SubAnchor=0x02;
                            break;
                        }



                }
            else if(encoder_dev.EN_STATE==SUBLEFT)
                {

                    switch(*SubAnchor)
                        {

                        case 0x02:
                            LCD_ShowNum(185,125,ip_data.ip,3,30,RED,WHITE);
                            LCD_Show_picture(250,210,WHITE,0);
                            *SubAnchor=0x01;
                            break;
                        }
                }

            if(flag_dev.action_flag==IP&&encoder_dev.EN_KEY==EN_KEY_DOWN)
                {

                    switch(*SubAnchor)
                        {
                        case 0x01:
                            if(flag_dev.anchor!=0)
                                flag_dev.anchor=0;
                            else
                                flag_dev.anchor=0x01;
                            break;
                        case 0x02:
                            flag_dev.TOSUBPAGE=0;
                            *SubAnchor=0;
                            LCD_Show_picture(250,210,WHITE,0);
                            break;
                        }
                }

        }


}
void EncoderUVOV(u8 *SubAnchor)
{

    if(flag_dev.action_flag==UV_OV)
        {

            if(encoder_dev.EN_STATE==SUBRIGHT)
                {

                    switch(*SubAnchor)
                        {
                        case 0x00:

                            LCD_ShowNum(235,68,uv_ov_data.rdv,2,30,RED,WHITE);
                            LCD_Show_3030_String(270,68,"V",BLACK);
                            LCD_ShowNum(160,108,uv_ov_data.uv,3,30,BLACK,WHITE);
                            LCD_Show_3030_String(210,108,"V",BLACK);
                            LCD_ShowNum(160,148,uv_ov_data.ov,3,30,BLACK,WHITE);
                            LCD_Show_3030_String(210,148,"V",BLACK);

                            if(uv_ov_data.uv_state==ON)
                                {
                                    gui_draw_arcrectangle(234,108,85,30,1,1,WHITE,WHITE);
                                    LCD_DrawLtrigo(234,110,259,135,LEFT,BLUE);
                                    LCD_DrawLtrigo(293,110,318,135,RIGHT,BLUE);

                                    if(flag_dev.langage==1)
                                        LCD_Show_3030_String(260,110,"ON",BLACK);
                                    else
                                        ShowChineseChar(265,110,5,24,BLACK);
                                }
                            else if(uv_ov_data.uv_state==OFF)
                                {

                                    gui_draw_arcrectangle(234,108,85,30,1,1,WHITE,WHITE);
                                    LCD_DrawLtrigo(234,110,259,135,LEFT,BLUE);
                                    LCD_DrawLtrigo(293,110,318,135,RIGHT,BLUE);
                                    if(flag_dev.langage==1)
                                        LCD_Show_3030_String(255,110,"OFF",BLACK);
                                    else
                                        ShowChineseChar(265,110,6,24,BLACK);
                                }
                            if(uv_ov_data.ov_state==ON)
                                {

                                    gui_draw_arcrectangle(234,148,85,30,1,1,WHITE,WHITE);
                                    LCD_DrawLtrigo(234,150,259,175,LEFT,BLUE);
                                    LCD_DrawLtrigo(293,150,318,175,RIGHT,BLUE);
                                    if(flag_dev.langage==1)
                                        LCD_Show_3030_String(260,150,"ON",BLACK);
                                    else
                                        ShowChineseChar(265,150,5,24,BLACK);
                                }
                            else if(uv_ov_data.ov_state==OFF)
                                {

                                    gui_draw_arcrectangle(234,148,85,30,1,1,WHITE,WHITE);
                                    LCD_DrawLtrigo(234,150,259,175,LEFT,BLUE);
                                    LCD_DrawLtrigo(293,150,318,175,RIGHT,BLUE);
                                    if(flag_dev.langage==1)
                                        LCD_Show_3030_String(255,150,"OFF",BLACK);
                                    else
                                        ShowChineseChar(265,150,6,24,BLACK);
                                }


                            *SubAnchor=1;
                            break;
                        case 0x01:

                            LCD_ShowNum(235,68,uv_ov_data.rdv,2,30,BLACK,WHITE);
                            LCD_Show_3030_String(270,68,"V",BLACK);
                            LCD_ShowNum(160,108,uv_ov_data.uv,3,30,RED,WHITE);
                            LCD_Show_3030_String(210,108,"V",BLACK);
                            LCD_ShowNum(160,148,uv_ov_data.ov,3,30,BLACK,WHITE);
                            LCD_Show_3030_String(210,148,"V",BLACK);

                            if(uv_ov_data.uv_state==ON)
                                {

                                    gui_draw_arcrectangle(234,108,85,30,1,1,WHITE,WHITE);
                                    LCD_DrawLtrigo(234,110,259,135,LEFT,BLUE);
                                    LCD_DrawLtrigo(293,110,318,135,RIGHT,BLUE);
                                    if(flag_dev.langage==1)
                                        LCD_Show_3030_String(260,110,"ON",BLACK);
                                    else
                                        ShowChineseChar(265,110,5,24,BLACK);
                                }
                            else if(uv_ov_data.uv_state==OFF)
                                {

                                    gui_draw_arcrectangle(234,108,85,30,1,1,WHITE,WHITE);
                                    LCD_DrawLtrigo(234,110,259,135,LEFT,BLUE);
                                    LCD_DrawLtrigo(293,110,318,135,RIGHT,BLUE);
                                    if(flag_dev.langage==1)
                                        LCD_Show_3030_String(255,110,"OFF",BLACK);
                                    else
                                        ShowChineseChar(265,110,6,24,BLACK);
                                }
                            if(uv_ov_data.ov_state==ON)
                                {

                                    gui_draw_arcrectangle(234,148,85,30,1,1,WHITE,WHITE);
                                    LCD_DrawLtrigo(234,150,259,175,LEFT,BLUE);
                                    LCD_DrawLtrigo(293,150,318,175,RIGHT,BLUE);
                                    if(flag_dev.langage==1)
                                        LCD_Show_3030_String(260,150,"ON",BLACK);
                                    else
                                        ShowChineseChar(265,150,5,24,BLACK);
                                }
                            else if(uv_ov_data.ov_state==OFF)
                                {

                                    gui_draw_arcrectangle(234,148,85,30,1,1,WHITE,WHITE);
                                    LCD_DrawLtrigo(234,150,259,175,LEFT,BLUE);
                                    LCD_DrawLtrigo(293,150,318,175,RIGHT,BLUE);
                                    if(flag_dev.langage==1)
                                        LCD_Show_3030_String(255,150,"OFF",BLACK);
                                    else
                                        ShowChineseChar(265,150,6,24,BLACK);
                                }
                            *SubAnchor=0x02;
                            break;
                        case 0x02:
                            LCD_ShowNum(235,68,uv_ov_data.rdv,2,30,BLACK,WHITE);
                            LCD_Show_3030_String(270,68,"V",BLACK);
                            LCD_ShowNum(160,108,uv_ov_data.uv,3,30,BLACK,WHITE);
                            LCD_Show_3030_String(210,108,"V",BLACK);
                            LCD_ShowNum(160,148,uv_ov_data.ov,3,30,BLACK,WHITE);
                            LCD_Show_3030_String(210,148,"V",BLACK);

                            if(uv_ov_data.uv_state==ON)
                                {


                                    gui_draw_arcrectangle(234,108,85,30,1,1,WHITE,WHITE);
                                    LCD_DrawLtrigo(234,110,259,135,LEFT,BLUE);
                                    LCD_DrawLtrigo(293,110,318,135,RIGHT,BLUE);
                                    if(flag_dev.langage==1)
                                        LCD_Show_3030_String(260,110,"ON",RED);
                                    else
                                        ShowChineseChar(265,110,5,24,RED);
                                }
                            else if(uv_ov_data.uv_state==OFF)
                                {


                                    gui_draw_arcrectangle(234,108,85,30,1,1,WHITE,WHITE);
                                    LCD_DrawLtrigo(234,110,259,135,LEFT,BLUE);
                                    LCD_DrawLtrigo(293,110,318,135,RIGHT,BLUE);
                                    if(flag_dev.langage==1)
                                        LCD_Show_3030_String(255,110,"OFF",RED);
                                    else
                                        ShowChineseChar(265,110,6,24,RED);
                                }
                            if(uv_ov_data.ov_state==ON)
                                {

                                    gui_draw_arcrectangle(234,148,85,30,1,1,WHITE,WHITE);
                                    LCD_DrawLtrigo(234,150,259,175,LEFT,BLUE);
                                    LCD_DrawLtrigo(293,150,318,175,RIGHT,BLUE);
                                    if(flag_dev.langage==1)
                                        LCD_Show_3030_String(260,150,"ON",BLACK);
                                    else
                                        ShowChineseChar(265,150,5,24,BLACK);
                                }
                            else if(uv_ov_data.ov_state==OFF)
                                {

                                    gui_draw_arcrectangle(234,148,85,30,1,1,WHITE,WHITE);
                                    LCD_DrawLtrigo(234,150,259,175,LEFT,BLUE);
                                    LCD_DrawLtrigo(293,150,318,175,RIGHT,BLUE);
                                    if(flag_dev.langage==1)
                                        LCD_Show_3030_String(255,150,"OFF",BLACK);
                                    else
                                        ShowChineseChar(265,150,6,24,BLACK);
                                }
                            *SubAnchor=0x03;
                            break;
                        case 0x03:

                            LCD_ShowNum(235,68,uv_ov_data.rdv,2,30,BLACK,WHITE);
                            LCD_Show_3030_String(270,68,"V",BLACK);
                            LCD_ShowNum(160,108,uv_ov_data.uv,3,30,BLACK,WHITE);
                            LCD_Show_3030_String(210,108,"V",BLACK);
                            LCD_ShowNum(160,148,uv_ov_data.ov,3,30,RED,WHITE);
                            LCD_Show_3030_String(210,148,"V",BLACK);

                            if(uv_ov_data.uv_state==ON)
                                {

                                    gui_draw_arcrectangle(234,108,85,30,1,1,WHITE,WHITE);
                                    LCD_DrawLtrigo(234,110,259,135,LEFT,BLUE);
                                    LCD_DrawLtrigo(293,110,318,135,RIGHT,BLUE);
                                    if(flag_dev.langage==1)
                                        LCD_Show_3030_String(260,110,"ON",BLACK);
                                    else
                                        ShowChineseChar(265,110,5,24,BLACK);
                                }
                            else if(uv_ov_data.uv_state==OFF)
                                {

                                    gui_draw_arcrectangle(234,108,85,30,1,1,WHITE,WHITE);
                                    LCD_DrawLtrigo(234,110,259,135,LEFT,BLUE);
                                    LCD_DrawLtrigo(293,110,318,135,RIGHT,BLUE);
                                    if(flag_dev.langage==1)
                                        LCD_Show_3030_String(255,110,"OFF",BLACK);
                                    else
                                        ShowChineseChar(265,110,6,24,BLACK);
                                }
                            if(uv_ov_data.ov_state==ON)
                                {

                                    gui_draw_arcrectangle(234,148,85,30,1,1,WHITE,WHITE);
                                    LCD_DrawLtrigo(234,150,259,175,LEFT,BLUE);
                                    LCD_DrawLtrigo(293,150,318,175,RIGHT,BLUE);
                                    if(flag_dev.langage==1)
                                        LCD_Show_3030_String(260,150,"ON",BLACK);
                                    else
                                        ShowChineseChar(265,150,5,24,BLACK);
                                }
                            else if(uv_ov_data.ov_state==OFF)
                                {

                                    gui_draw_arcrectangle(234,148,85,30,1,1,WHITE,WHITE);
                                    LCD_DrawLtrigo(234,150,259,175,LEFT,BLUE);
                                    LCD_DrawLtrigo(293,150,318,175,RIGHT,BLUE);
                                    if(flag_dev.langage==1)
                                        LCD_Show_3030_String(255,150,"OFF",BLACK);
                                    else
                                        ShowChineseChar(265,150,6,24,BLACK);
                                }


                            *SubAnchor=0x04;
                            break;
                        case 0x04:

                            LCD_ShowNum(235,68,uv_ov_data.rdv,2,30,BLACK,WHITE);
                            LCD_Show_3030_String(270,68,"V",BLACK);
                            LCD_ShowNum(160,108,uv_ov_data.uv,3,30,BLACK,WHITE);
                            LCD_Show_3030_String(210,108,"V",BLACK);
                            LCD_ShowNum(160,148,uv_ov_data.ov,3,30,BLACK,WHITE);
                            LCD_Show_3030_String(210,148,"V",BLACK);

                            if(uv_ov_data.uv_state==ON)
                                {

                                    gui_draw_arcrectangle(234,108,85,30,1,1,WHITE,WHITE);
                                    LCD_DrawLtrigo(234,110,259,135,LEFT,BLUE);
                                    LCD_DrawLtrigo(293,110,318,135,RIGHT,BLUE);
                                    if(flag_dev.langage==1)
                                        LCD_Show_3030_String(260,110,"ON",BLACK);
                                    else
                                        ShowChineseChar(265,110,5,24,BLACK);
                                }
                            else if(uv_ov_data.uv_state==OFF)
                                {

                                    gui_draw_arcrectangle(234,108,85,30,1,1,WHITE,WHITE);
                                    LCD_DrawLtrigo(234,110,259,135,LEFT,BLUE);
                                    LCD_DrawLtrigo(293,110,318,135,RIGHT,BLUE);
                                    if(flag_dev.langage==1)
                                        LCD_Show_3030_String(255,110,"OFF",BLACK);
                                    else
                                        ShowChineseChar(265,110,6,24,BLACK);
                                }
                            if(uv_ov_data.ov_state==ON)
                                {

                                    gui_draw_arcrectangle(234,148,85,30,1,1,WHITE,WHITE);
                                    LCD_DrawLtrigo(234,150,259,175,LEFT,BLUE);
                                    LCD_DrawLtrigo(293,150,318,175,RIGHT,BLUE);
                                    if(flag_dev.langage==1)
                                        LCD_Show_3030_String(260,150,"ON",RED);
                                    else
                                        ShowChineseChar(265,150,5,24,RED);
                                }
                            else if(uv_ov_data.ov_state==OFF)
                                {

                                    gui_draw_arcrectangle(234,148,85,30,1,1,WHITE,WHITE);
                                    LCD_DrawLtrigo(234,150,259,175,LEFT,BLUE);
                                    LCD_DrawLtrigo(293,150,318,175,RIGHT,BLUE);
                                    if(flag_dev.langage==1)
                                        LCD_Show_3030_String(255,150,"OFF",RED);
                                    else
                                        ShowChineseChar(265,150,6,24,RED);
                                }
                            *SubAnchor=0x05;
                            break;
                        case 0x05:

                            if(uv_ov_data.ov_state==ON)
                                {


                                    gui_draw_arcrectangle(234,148,85,30,1,1,WHITE,WHITE);
                                    LCD_DrawLtrigo(234,150,259,175,LEFT,BLUE);
                                    LCD_DrawLtrigo(293,150,318,175,RIGHT,BLUE);
                                    if(flag_dev.langage==1)
                                        LCD_Show_3030_String(260,150,"ON",BLACK);
                                    else
                                        ShowChineseChar(265,150,5,24,BLACK);
                                }
                            else if(uv_ov_data.ov_state==OFF)
                                {

                                    gui_draw_arcrectangle(234,148,85,30,1,1,WHITE,WHITE);
                                    LCD_DrawLtrigo(234,150,259,175,LEFT,BLUE);
                                    LCD_DrawLtrigo(293,150,318,175,RIGHT,BLUE);
                                    if(flag_dev.langage==1)
                                        LCD_Show_3030_String(255,150,"OFF",BLACK);
                                    else
                                        ShowChineseChar(265,150,6,24,BLACK);
                                }
                            gui_draw_arcrectangle(120,210,80,30,1,1,BLUE,BLUE);
                            gui_draw_arcrectangle(125,212,70,28,1,1,RED,RED);
                            if(flag_dev.langage==1)
                                LCD_Show_3030_String(130,210,"SAVE",WHITE);
                            else
                                ShowTwoChineseChar(135,213,10,11,24,WHITE);
                            *SubAnchor=0x06;
                            break;
                        case 0x06:
                            gui_draw_arcrectangle(120,210,80,30,1,1,BLUE,BLUE);
                            gui_draw_arcrectangle(125,212,70,28,1,1,WHITE,WHITE);
                            if(flag_dev.langage==1)
                                LCD_Show_3030_String(130,210,"SAVE",BLACK);
                            else
                                ShowTwoChineseChar(135,213,10,11,24,BLACK);
                            LCD_DrawLtrigo(230,215,255,240,LEFT,RED);
                            LCD_Show_picture(250,210,WHITE,0);
                            *SubAnchor=0x07;
                            break;
                        case 0x07:
                            LCD_DrawLtrigo(230,215,255,240,LEFT,WHITE);
                            LCD_Show_picture(250,210,RED,0);
                            LCD_DrawLtrigo(282,215,307,240,RIGHT,WHITE);
                            *SubAnchor=0x08;
                            break;
                        case 0x08:
                            LCD_DrawLtrigo(230,215,255,240,LEFT,WHITE);
                            LCD_Show_picture(250,210,WHITE,0);
                            LCD_DrawLtrigo(282,215,307,240,RIGHT,RED);
                            *SubAnchor=0x09;
                            break;
                        }

                }
            else if(encoder_dev.EN_STATE==SUBLEFT)
                {
                    switch(*SubAnchor)
                        {
                        case 0x02:

                            LCD_ShowNum(235,68,uv_ov_data.rdv,2,30,RED,WHITE);
                            LCD_Show_3030_String(270,68,"V",BLACK);
                            LCD_ShowNum(160,108,uv_ov_data.uv,3,30,BLACK,WHITE);
                            LCD_Show_3030_String(210,108,"V",BLACK);
                            LCD_ShowNum(160,148,uv_ov_data.ov,3,30,BLACK,WHITE);
                            LCD_Show_3030_String(210,148,"V",BLACK);

                            if(uv_ov_data.uv_state==ON)
                                {

                                    gui_draw_arcrectangle(234,108,85,30,1,1,WHITE,WHITE);
                                    LCD_DrawLtrigo(234,110,259,135,LEFT,BLUE);
                                    LCD_DrawLtrigo(293,110,318,135,RIGHT,BLUE);
                                    if(flag_dev.langage==1)
                                        LCD_Show_3030_String(260,110,"ON",BLACK);
                                    else
                                        ShowChineseChar(265,110,5,24,BLACK);
                                }
                            else if(uv_ov_data.uv_state==OFF)
                                {

                                    gui_draw_arcrectangle(234,108,85,30,1,1,WHITE,WHITE);
                                    LCD_DrawLtrigo(234,110,259,135,LEFT,BLUE);
                                    LCD_DrawLtrigo(293,110,318,135,RIGHT,BLUE);
                                    if(flag_dev.langage==1)
                                        LCD_Show_3030_String(255,110,"OFF",BLACK);
                                    else
                                        ShowChineseChar(265,110,6,24,BLACK);
                                }
                            if(uv_ov_data.ov_state==ON)
                                {

                                    gui_draw_arcrectangle(234,148,85,30,1,1,WHITE,WHITE);
                                    LCD_DrawLtrigo(234,150,259,175,LEFT,BLUE);
                                    LCD_DrawLtrigo(293,150,318,175,RIGHT,BLUE);
                                    if(flag_dev.langage==1)
                                        LCD_Show_3030_String(260,150,"ON",BLACK);
                                    else
                                        ShowChineseChar(265,150,5,24,BLACK);
                                }
                            else if(uv_ov_data.ov_state==OFF)
                                {

                                    gui_draw_arcrectangle(234,148,85,30,1,1,WHITE,WHITE);
                                    LCD_DrawLtrigo(234,150,259,175,LEFT,BLUE);
                                    LCD_DrawLtrigo(293,150,318,175,RIGHT,BLUE);
                                    if(flag_dev.langage==1)
                                        LCD_Show_3030_String(255,150,"OFF",BLACK);
                                    else
                                        ShowChineseChar(265,150,6,24,BLACK);
                                }
                            *SubAnchor=0x01;
                            break;
                        case 0x03:

                            LCD_ShowNum(235,68,uv_ov_data.rdv,2,30,BLACK,WHITE);
                            LCD_Show_3030_String(270,68,"V",BLACK);
                            LCD_ShowNum(160,108,uv_ov_data.uv,3,30,RED,WHITE);
                            LCD_Show_3030_String(210,108,"V",BLACK);
                            LCD_ShowNum(160,148,uv_ov_data.ov,3,30,BLACK,WHITE);
                            LCD_Show_3030_String(210,148,"V",BLACK);

                            if(uv_ov_data.uv_state==ON)
                                {
                                    gui_draw_arcrectangle(234,108,85,30,1,1,WHITE,WHITE);
                                    LCD_DrawLtrigo(234,110,259,135,LEFT,BLUE);
                                    LCD_DrawLtrigo(293,110,318,135,RIGHT,BLUE);
                                    if(flag_dev.langage==1)
                                        LCD_Show_3030_String(260,110,"ON",BLACK);
                                    else
                                        ShowChineseChar(265,110,5,24,BLACK);
                                }
                            else if(uv_ov_data.uv_state==OFF)
                                {

                                    gui_draw_arcrectangle(234,108,85,30,1,1,WHITE,WHITE);
                                    LCD_DrawLtrigo(234,110,259,135,LEFT,BLUE);
                                    LCD_DrawLtrigo(293,110,318,135,RIGHT,BLUE);
                                    if(flag_dev.langage==1)
                                        LCD_Show_3030_String(255,110,"OFF",BLACK);
                                    else
                                        ShowChineseChar(265,110,6,24,BLACK);
                                }
                            if(uv_ov_data.ov_state==ON)
                                {

                                    gui_draw_arcrectangle(234,148,85,30,1,1,WHITE,WHITE);
                                    LCD_DrawLtrigo(234,150,259,175,LEFT,BLUE);
                                    LCD_DrawLtrigo(293,150,318,175,RIGHT,BLUE);
                                    if(flag_dev.langage==1)
                                        LCD_Show_3030_String(260,150,"ON",BLACK);
                                    else
                                        ShowChineseChar(265,150,5,24,BLACK);
                                }
                            else if(uv_ov_data.ov_state==OFF)
                                {

                                    gui_draw_arcrectangle(234,148,85,30,1,1,WHITE,WHITE);
                                    LCD_DrawLtrigo(234,150,259,175,LEFT,BLUE);
                                    LCD_DrawLtrigo(293,150,318,175,RIGHT,BLUE);
                                    if(flag_dev.langage==1)
                                        LCD_Show_3030_String(255,150,"OFF",BLACK);
                                    else
                                        ShowChineseChar(265,150,6,24,BLACK);
                                }
                            *SubAnchor=0x02;
                            break;
                        case 0x04:

                            LCD_ShowNum(235,68,uv_ov_data.rdv,2,30,BLACK,WHITE);
                            LCD_Show_3030_String(270,68,"V",BLACK);
                            LCD_ShowNum(160,108,uv_ov_data.uv,3,30,BLACK,WHITE);
                            LCD_Show_3030_String(210,108,"V",BLACK);
                            LCD_ShowNum(160,148,uv_ov_data.ov,3,30,BLACK,WHITE);
                            LCD_Show_3030_String(210,148,"V",BLACK);

                            if(uv_ov_data.uv_state==ON)
                                {

                                    gui_draw_arcrectangle(234,108,85,30,1,1,WHITE,WHITE);
                                    LCD_DrawLtrigo(234,110,259,135,LEFT,BLUE);
                                    LCD_DrawLtrigo(293,110,318,135,RIGHT,BLUE);
                                    if(flag_dev.langage==1)
                                        LCD_Show_3030_String(260,110,"ON",RED);
                                    else
                                        ShowChineseChar(265,110,5,24,RED);
                                }
                            else if(uv_ov_data.uv_state==OFF)
                                {

                                    gui_draw_arcrectangle(234,108,85,30,1,1,WHITE,WHITE);
                                    LCD_DrawLtrigo(234,110,259,135,LEFT,BLUE);
                                    LCD_DrawLtrigo(293,110,318,135,RIGHT,BLUE);
                                    if(flag_dev.langage==1)
                                        LCD_Show_3030_String(255,110,"OFF",RED);
                                    else
                                        ShowChineseChar(265,110,6,24,RED);
                                }
                            if(uv_ov_data.ov_state==ON)
                                {

                                    gui_draw_arcrectangle(234,148,85,30,1,1,WHITE,WHITE);
                                    LCD_DrawLtrigo(234,150,259,175,LEFT,BLUE);
                                    LCD_DrawLtrigo(293,150,318,175,RIGHT,BLUE);
                                    if(flag_dev.langage==1)
                                        LCD_Show_3030_String(260,150,"ON",BLACK);
                                    else
                                        ShowChineseChar(265,150,5,24,BLACK);
                                }
                            else if(uv_ov_data.ov_state==OFF)
                                {

                                    gui_draw_arcrectangle(234,148,85,30,1,1,WHITE,WHITE);
                                    LCD_DrawLtrigo(234,150,259,175,LEFT,BLUE);
                                    LCD_DrawLtrigo(293,150,318,175,RIGHT,BLUE);
                                    if(flag_dev.langage==1)
                                        LCD_Show_3030_String(255,150,"OFF",BLACK);
                                    else
                                        ShowChineseChar(265,150,6,24,BLACK);
                                }


                            *SubAnchor=0x03;
                            break;
                        case 0x05:

                            LCD_ShowNum(235,68,uv_ov_data.rdv,2,30,BLACK,WHITE);
                            LCD_Show_3030_String(270,68,"V",BLACK);
                            LCD_ShowNum(160,108,uv_ov_data.uv,3,30,BLACK,WHITE);
                            LCD_Show_3030_String(210,108,"V",BLACK);
                            LCD_ShowNum(160,148,uv_ov_data.ov,3,30,RED,WHITE);
                            LCD_Show_3030_String(210,148,"V",BLACK);

                            if(uv_ov_data.uv_state==ON)
                                {

                                    gui_draw_arcrectangle(234,108,85,30,1,1,WHITE,WHITE);
                                    LCD_DrawLtrigo(234,110,259,135,LEFT,BLUE);
                                    LCD_DrawLtrigo(293,110,318,135,RIGHT,BLUE);
                                    if(flag_dev.langage==1)
                                        LCD_Show_3030_String(260,110,"ON",BLACK);
                                    else
                                        ShowChineseChar(265,110,5,24,BLACK);
                                }
                            else if(uv_ov_data.uv_state==OFF)
                                {

                                    gui_draw_arcrectangle(234,108,85,30,1,1,WHITE,WHITE);
                                    LCD_DrawLtrigo(234,110,259,135,LEFT,BLUE);
                                    LCD_DrawLtrigo(293,110,318,135,RIGHT,BLUE);
                                    if(flag_dev.langage==1)
                                        LCD_Show_3030_String(255,110,"OFF",BLACK);
                                    else
                                        ShowChineseChar(265,110,6,24,BLACK);
                                }
                            if(uv_ov_data.ov_state==ON)
                                {

                                    gui_draw_arcrectangle(234,148,85,30,1,1,WHITE,WHITE);
                                    LCD_DrawLtrigo(234,150,259,175,LEFT,BLUE);
                                    LCD_DrawLtrigo(293,150,318,175,RIGHT,BLUE);
                                    if(flag_dev.langage==1)
                                        LCD_Show_3030_String(260,150,"ON",BLACK);
                                    else
                                        ShowChineseChar(265,150,5,24,BLACK);
                                }
                            else if(uv_ov_data.ov_state==OFF)
                                {

                                    gui_draw_arcrectangle(234,148,85,30,1,1,WHITE,WHITE);
                                    LCD_DrawLtrigo(234,150,259,175,LEFT,BLUE);
                                    LCD_DrawLtrigo(293,150,318,175,RIGHT,BLUE);
                                    if(flag_dev.langage==1)
                                        LCD_Show_3030_String(255,150,"OFF",BLACK);
                                    else
                                        ShowChineseChar(265,150,6,24,BLACK);
                                }
                            *SubAnchor=0x04;
                            break;
                        case 0x06:

                            LCD_ShowNum(235,68,uv_ov_data.rdv,2,30,BLACK,WHITE);
                            LCD_Show_3030_String(270,68,"V",BLACK);
                            LCD_ShowNum(160,108,uv_ov_data.uv,3,30,BLACK,WHITE);
                            LCD_Show_3030_String(210,108,"V",BLACK);
                            LCD_ShowNum(160,148,uv_ov_data.ov,3,30,BLACK,WHITE);
                            LCD_Show_3030_String(210,148,"V",BLACK);
                            if(uv_ov_data.uv_state==ON)
                                {

                                    gui_draw_arcrectangle(234,108,85,30,1,1,WHITE,WHITE);
                                    LCD_DrawLtrigo(234,110,259,135,LEFT,BLUE);
                                    LCD_DrawLtrigo(293,110,318,135,RIGHT,BLUE);
                                    if(flag_dev.langage==1)
                                        LCD_Show_3030_String(260,110,"ON",BLACK);
                                    else
                                        ShowChineseChar(265,110,5,24,BLACK);
                                }
                            else if(uv_ov_data.uv_state==OFF)
                                {

                                    gui_draw_arcrectangle(234,108,85,30,1,1,WHITE,WHITE);
                                    LCD_DrawLtrigo(234,110,259,135,LEFT,BLUE);
                                    LCD_DrawLtrigo(293,110,318,135,RIGHT,BLUE);
                                    if(flag_dev.langage==1)
                                        LCD_Show_3030_String(255,110,"OFF",BLACK);
                                    else
                                        ShowChineseChar(265,110,6,24,BLACK);
                                }
                            if(uv_ov_data.ov_state==ON)
                                {

                                    gui_draw_arcrectangle(234,148,85,30,1,1,WHITE,WHITE);
                                    LCD_DrawLtrigo(234,150,259,175,LEFT,BLUE);
                                    LCD_DrawLtrigo(293,150,318,175,RIGHT,BLUE);
                                    if(flag_dev.langage==1)
                                        LCD_Show_3030_String(260,150,"ON",RED);
                                    else
                                        ShowChineseChar(265,150,5,24,RED);

                                }
                            else if(uv_ov_data.ov_state==OFF)
                                {

                                    gui_draw_arcrectangle(234,148,85,30,1,1,WHITE,WHITE);
                                    LCD_DrawLtrigo(234,150,259,175,LEFT,BLUE);
                                    LCD_DrawLtrigo(293,150,318,175,RIGHT,BLUE);
                                    if(flag_dev.langage==1)
                                        LCD_Show_3030_String(255,150,"OFF",RED);
                                    else
                                        ShowChineseChar(265,150,6,24,RED);
                                }
                            gui_draw_arcrectangle(120,210,80,30,1,1,BLUE,BLUE);
                            gui_draw_arcrectangle(125,212,70,28,1,1,WHITE,WHITE);
                            //LCD_Show_3030_String(130,210,"SAVE",BLACK);
                            ShowTwoChineseChar(135,213,10,11,24,BLACK);
                            *SubAnchor=0x05;
                            break;
                        case 0x07:
                            gui_draw_arcrectangle(120,210,80,30,1,1,BLUE,BLUE);
                            gui_draw_arcrectangle(125,212,70,28,1,1,RED,RED);
                            if(flag_dev.langage==1)
                                LCD_Show_3030_String(130,210,"SAVE",WHITE);
                            else
                                ShowTwoChineseChar(135,213,10,11,24,WHITE);
                            LCD_DrawLtrigo(230,215,255,240,LEFT,WHITE);
                            LCD_Show_picture(250,210,WHITE,0);
                            *SubAnchor=0x06;
                            break;
                        case 0x08:
                            LCD_DrawLtrigo(230,215,255,240,LEFT,RED);
                            LCD_Show_picture(250,210,WHITE,0);
                            LCD_DrawLtrigo(282,215,307,240,RIGHT,WHITE);
                            *SubAnchor=0x07;
                            break;
                        case 0x09:
                            LCD_DrawLtrigo(230,215,255,240,LEFT,WHITE);
                            LCD_Show_picture(250,210,RED,0);
                            LCD_DrawLtrigo(282,215,307,240,RIGHT,WHITE);
                            *SubAnchor=0x08;
                            break;


                        }
                }

            if(flag_dev.action_flag==UV_OV&&encoder_dev.EN_KEY==EN_KEY_DOWN)
                {
                    switch(*SubAnchor)
                        {

                        case 0x01:
                            if(flag_dev.anchor!=0)
                                flag_dev.anchor=0;
                            else
                                flag_dev.anchor=1;
                            break;
                        case 0x02:

                            if(flag_dev.anchor!=0)
                                flag_dev.anchor=0;
                            else
                                flag_dev.anchor=2;
                            break;
                        case 0x03:
                            if(flag_dev.anchor!=0)
                                {
                                    flag_dev.anchor=0;
                                }
                            if(uv_ov_data.uv_state==ON)
                                {
                                    uv_ov_data.uv_state=OFF;
                                    gui_draw_arcrectangle(234,108,85,30,1,1,WHITE,WHITE);
                                    LCD_DrawLtrigo(234,110,259,135,LEFT,BLUE);
                                    LCD_DrawLtrigo(293,110,318,135,RIGHT,BLUE);
                                    if(flag_dev.langage==1)
                                        LCD_Show_3030_String(255,110,"OFF",RED);
                                    else
                                        ShowChineseChar(265,110,6,24,RED);
                                }
                            else if(uv_ov_data.uv_state==OFF)
                                {
                                    uv_ov_data.uv_state=ON;
                                    gui_draw_arcrectangle(234,108,85,30,1,1,WHITE,WHITE);
                                    LCD_DrawLtrigo(234,110,259,135,LEFT,BLUE);
                                    LCD_DrawLtrigo(293,110,318,135,RIGHT,BLUE);
                                    if(flag_dev.langage==1)
                                        LCD_Show_3030_String(260,110,"ON",RED);
                                    else
                                        ShowChineseChar(265,110,5,24,RED);
                                }
                            break;
                        case 0x04:
                            if(flag_dev.anchor!=0)
                                flag_dev.anchor=0;
                            else
                                flag_dev.anchor=3;
                            break;
                        case 0x05:
                            if(flag_dev.anchor!=0)
                                {
                                    flag_dev.anchor=0;
                                }
                            if(uv_ov_data.ov_state==ON)
                                {
                                    uv_ov_data.ov_state=OFF;
                                    gui_draw_arcrectangle(234,148,85,30,1,1,WHITE,WHITE);
                                    LCD_DrawLtrigo(234,150,259,175,LEFT,BLUE);
                                    LCD_DrawLtrigo(293,150,318,175,RIGHT,BLUE);
                                    if(flag_dev.langage==1)
                                        LCD_Show_3030_String(255,150,"OFF",RED);
                                    else
                                        ShowChineseChar(265,150,6,24,RED);
                                }
                            else if(uv_ov_data.ov_state==OFF)
                                {
                                    uv_ov_data.ov_state=ON;
                                    gui_draw_arcrectangle(234,148,85,30,1,1,WHITE,WHITE);
                                    LCD_DrawLtrigo(234,150,259,175,LEFT,BLUE);
                                    LCD_DrawLtrigo(293,150,318,175,RIGHT,BLUE);
                                    if(flag_dev.langage==1)
                                        LCD_Show_3030_String(260,150,"ON",RED);
                                    else
                                        ShowChineseChar(265,150,5,24,RED);
                                }
                            break;
                        case 0x06:
                            ReadAndSave(ISUV_OV,1);
                            break;
                        case 0x08:
                            flag_dev.TOSUBPAGE=0;
                            *SubAnchor=0;
                            LCD_Show_picture(250,210,WHITE,0);
                            break;

                        }


                }
        }

}
void EncoderPWD(u8 *SubAnchor)
{
    if(flag_dev.action_flag==AUZ||flag_dev.action_flag==HOME||flag_dev.action_flag==UV_OV)
        flag_dev.PWDsta=0;
    if(flag_dev.action_flag==PWD)
        {

            if(encoder_dev.EN_STATE==SUBRIGHT)
                {
                    switch(*SubAnchor)
                        {
                        case 0x00:
                            LCD_Show_2424_String(95,115,"******",RED);
                            LCD_Show_2424_String(95,180,"******",BLACK);
                            *SubAnchor=0x02;
                            break;
                        case 0x02:
                            LCD_Show_2424_String(95,115,"******",BLACK);
                            LCD_Show_2424_String(95,180,"******",RED);
                            *SubAnchor=0x03;
                            break;
                        case 0x03:
                            LCD_Show_2424_String(95,115,"******",BLACK);
                            LCD_Show_2424_String(95,180,"******",BLACK);
                            LCD_Show_picture(250,210,RED,0);
                            *SubAnchor=0x04;
                            break;


                        }

                }
            else if(encoder_dev.EN_STATE==SUBLEFT)
                {
                    switch(*SubAnchor)
                        {
                        case 0x03:
                            LCD_Show_2424_String(95,115,"******",RED);
                            LCD_Show_2424_String(95,180,"******",BLACK);
                            *SubAnchor=0x02;
                            break;
                        case 0x04:
                            LCD_Show_2424_String(95,115,"******",BLACK);
                            LCD_Show_2424_String(95,180,"******",RED);
                            LCD_Show_picture(250,210,WHITE,0);
                            *SubAnchor=0x03;
                            break;
                        }
                }
            if(flag_dev.action_flag==PWD&&encoder_dev.EN_KEY==EN_KEY_DOWN)
                {

                    switch(*SubAnchor)
                        {
                        case 0x02:
                            flag_dev.action_flag=KEY_BOARD;
                            flag_dev.KEY_board_sta=1;
                            LCD_Fill(93,42,319,208,BLACK);
                            key_board_activity();

                            if(flag_dev.PWDsta==1)
                                {
                                    gui_draw_arcrectangle(94,0,226,40,3,1, RED,RED);
                                    if(flag_dev.langage==0)
                                        {
                                            ShowTwoChineseChar(145,11,38,39,24,WHITE);
                                            ShowChineseChar(193,11,40,24,WHITE);
                                            ShowTwoChineseChar(217,11,34,35,24,WHITE);
                                        }
                                    else
                                        {
                                            LCD_Show_2424_String(130,11,"NEW PASSWORD",WHITE);

                                        }
                                    flag_dev.pwd_anchor=1;
                                }
                            else
                                {
                                    gui_draw_arcrectangle(94,0,226,40,3,1, RED,RED);
                                    if(flag_dev.langage==0)
                                        {
                                            ShowTwoChineseChar(145,11,38,39,24,WHITE);
                                            ShowChineseChar(193,11,75,24,WHITE);
                                            ShowTwoChineseChar(217,11,34,35,24,WHITE);
                                        }
                                    else
                                        {

                                            LCD_Show_2424_String(130,11,"OLD PASSWORD",WHITE);

                                        }
                                    flag_dev.pwd_anchor=5;
                                }

                            *SubAnchor=0;
                            break;
                        case 0x03:
                            flag_dev.action_flag=KEY_BOARD;
                            flag_dev.KEY_board_sta=1;
                            LCD_Fill(93,42,319,208,BLACK);
                            key_board_activity();

                            if(flag_dev.PWDsta==1)
                                {
                                    flag_dev.pwd_anchor=2;
                                    gui_draw_arcrectangle(94,0,226,40,3,1, RED,RED);
                                    if(flag_dev.langage==0)
                                        {
                                            ShowTwoChineseChar(125,11,43,44,24,WHITE);
                                            ShowTwoChineseChar(173,11,38,39,24,WHITE);
                                            ShowChineseChar(221,11,40,24,WHITE);
                                            ShowTwoChineseChar(245,11,34,35,24,WHITE);
                                        }
                                    else
                                        {
                                            LCD_Show_2424_String(130,11,"  0RE-ENTER",WHITE);

                                        }

                                }
                            else
                                {
                                    gui_draw_arcrectangle(94,0,226,40,3,1, RED,RED);
                                    if(flag_dev.langage==0)
                                        {
                                            ShowTwoChineseChar(145,11,38,39,24,WHITE);
                                            ShowChineseChar(193,11,75,24,WHITE);
                                            ShowTwoChineseChar(217,11,34,35,24,WHITE);
                                        }
                                    else
                                        {

                                            LCD_Show_2424_String(130,11,"OLD PASSWORD",WHITE);

                                        }

                                    flag_dev.pwd_anchor=5;
                                }

                            *SubAnchor=0;
                            break;
                        case 0x04:
                            flag_dev.TOSUBPAGE=0;
                            *SubAnchor=0;
                            LCD_Show_picture(250,210,WHITE,0);
                            break;

                        }
                }

        }
}
void EncoderAUZ(u8 *SubAnchor)
{
    if(flag_dev.action_flag==PWD||flag_dev.action_flag==HOME||flag_dev.action_flag==UV_OV)
        flag_dev.IsShowAUZNumset=0;//取消显示更改使用次数
    if(flag_dev.action_flag==AUZ)
        {

            if(encoder_dev.EN_STATE==SUBRIGHT)
                {
                    switch(*SubAnchor)
                        {
                        case 0x00:
                            gui_draw_arcrectangle(202,48, 117-2,30,4,1,WHITE,WHITE);
                            LCD_Show_2424_String(222,52,"******",RED);
                            *SubAnchor=0x02;

                            break;
                        case 0x02:

                            gui_draw_arcrectangle(202,48, 117-2,30,4,1,WHITE,WHITE);
                            LCD_Show_2424_String(222,52,"******",BLACK);
                            if(flag_dev.IsShowAUZNumset==1)
                                {
                                    gui_draw_arcrectangle(202,173,117-2,30,4,1,WHITE,WHITE);
                                    if(AuzCntData.SetCnt>100)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_2424_String(204,175,"PERMANENT",RED);
                                            else
                                                {
                                                    ShowTwoChineseChar(210,175,71,72,24,RED);
                                                    ShowTwoChineseChar(258,175,73,45,24,RED);
                                                }
                                        }
                                    else
                                        {
                                            LCD_ShowNum(242,175,AuzCntData.SetCnt,3,24,RED,WHITE);
                                        }
                                    *SubAnchor=0x03;
                                }
                            else
                                {
                                    LCD_Show_picture(250,210,RED,0);
                                    *SubAnchor=0x05;
                                }
                            break;
                        case 0x03:

                            gui_draw_arcrectangle(202,173,117-2,30,4,1,WHITE,WHITE);
                            if(AuzCntData.SetCnt>100)
                                {
                                    if(flag_dev.langage==1)
                                        LCD_Show_2424_String(204,175,"PERMANENT",BLACK);
                                    else
                                        {
                                            ShowTwoChineseChar(210,175,71,72,24,BLACK);
                                            ShowTwoChineseChar(258,175,73,45,24,BLACK);
                                        }
                                }
                            else
                                {
                                    LCD_ShowNum(242,175,AuzCntData.SetCnt,3,24,BLACK,WHITE);
                                }
                            gui_draw_arcrectangle(120,210,80,30,1,1,BLUE,BLUE);
                            gui_draw_arcrectangle(125,212,70,28,1,1,RED,RED);
                            if(flag_dev.langage==1)
                                LCD_Show_3030_String(130,210,"SAVE",WHITE);
                            else
                                ShowTwoChineseChar(135,213,10,11,24,WHITE);
                            *SubAnchor=0x04;
                            break;
                        case 0x04:
                            gui_draw_arcrectangle(120,210,80,30,1,1,BLUE,BLUE);
                            gui_draw_arcrectangle(125,212,70,28,1,1,WHITE,WHITE);
                            if(flag_dev.langage==1)
                                LCD_Show_3030_String(130,210,"SAVE",BLACK);
                            else
                                ShowTwoChineseChar(135,213,10,11,24,BLACK);

                            LCD_Show_picture(250,210,RED,0);
                            *SubAnchor=0x05;
                            break;


                        }


                }
            else if(encoder_dev.EN_STATE==SUBLEFT)
                {
                    switch(*SubAnchor)
                        {
                        case 0x03:
                            gui_draw_arcrectangle(202,48, 117-2,30,4,1,WHITE,WHITE);
                            LCD_Show_2424_String(222,52,"******",RED);
                            gui_draw_arcrectangle(202,173,117-2,30,4,1,WHITE,WHITE);
                            if(AuzCntData.SetCnt>100)
                                {
                                    if(flag_dev.langage==1)
                                        {
                                            LCD_Show_2424_String(204,175,"PERMANENT",BLACK);
                                        }
                                    else
                                        {
                                            ShowTwoChineseChar(210,175,71,72,24,BLACK);
                                            ShowTwoChineseChar(258,175,73,45,24,BLACK);
                                        }
                                }
                            else
                                {
                                    LCD_ShowNum(242,175,AuzCntData.SetCnt,3,24,BLACK,WHITE);

                                }
                            *SubAnchor=0x02;
                            break;
                        case 0x04:
                            gui_draw_arcrectangle(202,173,117-2,30,4,1,WHITE,WHITE);
                            if(AuzCntData.SetCnt>100)
                                {
                                    if(flag_dev.langage==1)
                                        LCD_Show_2424_String(204,175,"PERMANENT",RED);
                                    else
                                        {
                                            ShowTwoChineseChar(210,175,71,72,24,RED);
                                            ShowTwoChineseChar(258,175,73,45,24,RED);
                                        }
                                }
                            else
                                {
                                    LCD_ShowNum(242,175,AuzCntData.SetCnt,3,24,RED,WHITE);
                                }
                            gui_draw_arcrectangle(120,210,80,30,1,1,BLUE,BLUE);
                            gui_draw_arcrectangle(125,212,70,28,1,1,WHITE,WHITE);
                            if(flag_dev.langage==1)
                                LCD_Show_3030_String(130,210,"SAVE",BLACK);
                            else
                                ShowTwoChineseChar(135,213,10,11,24,BLACK);
                            *SubAnchor=0x03;
                            break;
                        case 0x05:
                            LCD_Show_picture(250,210,WHITE,0);

                            if(flag_dev.IsShowAUZNumset==1)
                                {
                                    gui_draw_arcrectangle(120,210,80,30,1,1,BLUE,BLUE);
                                    gui_draw_arcrectangle(125,212,70,28,1,1,RED,RED);
                                    if(flag_dev.langage==1)
                                        LCD_Show_3030_String(130,210,"SAVE",WHITE);
                                    else
                                        ShowTwoChineseChar(135,213,10,11,24,WHITE);

                                    *SubAnchor=0x04;
                                }
                            else
                                {
                                    gui_draw_arcrectangle(202,48, 117-2,30,4,1,WHITE,WHITE);
                                    LCD_Show_2424_String(222,52,"******",RED);
                                    *SubAnchor=0x02;
                                }
                            break;
                        }
                }
            if(flag_dev.action_flag==AUZ&&encoder_dev.EN_KEY==EN_KEY_DOWN)
                {

                    switch(*SubAnchor)
                        {
                        case 0x02:
                            flag_dev.action_flag=KEY_BOARD;
                            flag_dev.KEY_board_sta=1;
                            LCD_Fill(93,42,319,208,BLACK);
                            key_board_activity();
                            flag_dev.pwd_anchor=3;//设置为注册授权情况
                            break;
                        case 0x03:
                            if(flag_dev.anchor!=0)
                                flag_dev.anchor=0;
                            else
                                flag_dev.anchor=1;
                            break;
                        case 0x04:
                            flag_dev.save_flag=1;
                            break;
                        case 0x05:
                            flag_dev.TOSUBPAGE=0;
                            *SubAnchor=0;
                            LCD_Show_picture(250,210,WHITE,0);
                            break;

                        }


                }

        }


}
void EncoderKeyboard(u8 *SubAnchor)
{

    if(flag_dev.action_flag==KEY_BOARD)
        {

            if(encoder_dev.EN_STATE==SUBRIGHT)
                {
                    switch(*SubAnchor)
                        {
                        case 0x00:

                            LCD_Draw_arrow_key(294,90,314,110,RIGHT,RED);

                            LCD_Show_3030_String(114,114,"1",BLACK);
                            LCD_Show_3030_String(170,114,"2",BLACK);
                            LCD_Show_3030_String(226,114,"3",BLACK);
                            LCD_Show_3030_String(282,114,"0",BLACK);

                            LCD_Show_3030_String(114,146,"4",BLACK);
                            LCD_Show_3030_String(170,146,"5",BLACK);
                            LCD_Show_3030_String(226,146,"6",BLACK);
                            LCD_Show_2424_String(272,148,"DEL",BLACK);

                            LCD_Show_3030_String(114,178,"7",BLACK);
                            LCD_Show_3030_String(170,178,"8",BLACK);
                            LCD_Show_3030_String(226,178,"9",BLACK);
                            LCD_Show_2424_String(277,180,"OK",BLACK);
                            *SubAnchor=0x01;
                            break;
                        case 0x01:
                            LCD_Draw_arrow_key(294,90,314,110,RIGHT,BLACK);

                            LCD_Show_3030_String(114,114,"1",RED);
                            LCD_Show_3030_String(170,114,"2",BLACK);
                            LCD_Show_3030_String(226,114,"3",BLACK);
                            LCD_Show_3030_String(282,114,"0",BLACK);

                            LCD_Show_3030_String(114,146,"4",BLACK);
                            LCD_Show_3030_String(170,146,"5",BLACK);
                            LCD_Show_3030_String(226,146,"6",BLACK);
                            LCD_Show_2424_String(272,148,"DEL",BLACK);

                            LCD_Show_3030_String(114,178,"7",BLACK);
                            LCD_Show_3030_String(170,178,"8",BLACK);
                            LCD_Show_3030_String(226,178,"9",BLACK);
                            LCD_Show_2424_String(277,180,"OK",BLACK);
                            *SubAnchor=0x02;
                            break;
                        case 0x02:


                            LCD_Draw_arrow_key(294,90,314,110,RIGHT,BLACK);

                            LCD_Show_3030_String(114,114,"1",BLACK);
                            LCD_Show_3030_String(170,114,"2",RED);
                            LCD_Show_3030_String(226,114,"3",BLACK);
                            LCD_Show_3030_String(282,114,"0",BLACK);

                            LCD_Show_3030_String(114,146,"4",BLACK);
                            LCD_Show_3030_String(170,146,"5",BLACK);
                            LCD_Show_3030_String(226,146,"6",BLACK);
                            LCD_Show_2424_String(272,148,"DEL",BLACK);

                            LCD_Show_3030_String(114,178,"7",BLACK);
                            LCD_Show_3030_String(170,178,"8",BLACK);
                            LCD_Show_3030_String(226,178,"9",BLACK);
                            LCD_Show_2424_String(277,180,"OK",BLACK);
                            *SubAnchor=0x03;
                            break;
                        case 0x03:


                            LCD_Draw_arrow_key(294,90,314,110,RIGHT,BLACK);

                            LCD_Show_3030_String(114,114,"1",BLACK);
                            LCD_Show_3030_String(170,114,"2",BLACK);
                            LCD_Show_3030_String(226,114,"3",RED);
                            LCD_Show_3030_String(282,114,"0",BLACK);

                            LCD_Show_3030_String(114,146,"4",BLACK);
                            LCD_Show_3030_String(170,146,"5",BLACK);
                            LCD_Show_3030_String(226,146,"6",BLACK);
                            LCD_Show_2424_String(272,148,"DEL",BLACK);

                            LCD_Show_3030_String(114,178,"7",BLACK);
                            LCD_Show_3030_String(170,178,"8",BLACK);
                            LCD_Show_3030_String(226,178,"9",BLACK);
                            LCD_Show_2424_String(277,180,"OK",BLACK);
                            *SubAnchor=0x04;
                            break;
                        case 0x04:

                            LCD_Draw_arrow_key(294,90,314,110,RIGHT,BLACK);

                            LCD_Show_3030_String(114,114,"1",BLACK);
                            LCD_Show_3030_String(170,114,"2",BLACK);
                            LCD_Show_3030_String(226,114,"3",BLACK);
                            LCD_Show_3030_String(282,114,"0",RED);

                            LCD_Show_3030_String(114,146,"4",BLACK);
                            LCD_Show_3030_String(170,146,"5",BLACK);
                            LCD_Show_3030_String(226,146,"6",BLACK);
                            LCD_Show_2424_String(272,148,"DEL",BLACK);

                            LCD_Show_3030_String(114,178,"7",BLACK);
                            LCD_Show_3030_String(170,178,"8",BLACK);
                            LCD_Show_3030_String(226,178,"9",BLACK);
                            LCD_Show_2424_String(277,180,"OK",BLACK);
                            *SubAnchor=0x05;
                            break;
                        case 0x05:

                            LCD_Draw_arrow_key(294,90,314,110,RIGHT,BLACK);

                            LCD_Show_3030_String(114,114,"1",BLACK);
                            LCD_Show_3030_String(170,114,"2",BLACK);
                            LCD_Show_3030_String(226,114,"3",BLACK);
                            LCD_Show_3030_String(282,114,"0",BLACK);

                            LCD_Show_3030_String(114,146,"4",RED);
                            LCD_Show_3030_String(170,146,"5",BLACK);
                            LCD_Show_3030_String(226,146,"6",BLACK);
                            LCD_Show_2424_String(272,148,"DEL",BLACK);

                            LCD_Show_3030_String(114,178,"7",BLACK);
                            LCD_Show_3030_String(170,178,"8",BLACK);
                            LCD_Show_3030_String(226,178,"9",BLACK);
                            LCD_Show_2424_String(277,180,"OK",BLACK);
                            *SubAnchor=0x06;
                            break;
                        case 0x06:

                            LCD_Draw_arrow_key(294,90,314,110,RIGHT,BLACK);

                            LCD_Show_3030_String(114,114,"1",BLACK);
                            LCD_Show_3030_String(170,114,"2",BLACK);
                            LCD_Show_3030_String(226,114,"3",BLACK);
                            LCD_Show_3030_String(282,114,"0",BLACK);

                            LCD_Show_3030_String(114,146,"4",BLACK);
                            LCD_Show_3030_String(170,146,"5",RED);
                            LCD_Show_3030_String(226,146,"6",BLACK);
                            LCD_Show_2424_String(272,148,"DEL",BLACK);

                            LCD_Show_3030_String(114,178,"7",BLACK);
                            LCD_Show_3030_String(170,178,"8",BLACK);
                            LCD_Show_3030_String(226,178,"9",BLACK);
                            LCD_Show_2424_String(277,180,"OK",BLACK);
                            *SubAnchor=0x07;
                            break;
                        case 0x07:

                            LCD_Draw_arrow_key(294,90,314,110,RIGHT,BLACK);

                            LCD_Show_3030_String(114,114,"1",BLACK);
                            LCD_Show_3030_String(170,114,"2",BLACK);
                            LCD_Show_3030_String(226,114,"3",BLACK);
                            LCD_Show_3030_String(282,114,"0",BLACK);

                            LCD_Show_3030_String(114,146,"4",BLACK);
                            LCD_Show_3030_String(170,146,"5",BLACK);
                            LCD_Show_3030_String(226,146,"6",RED);
                            LCD_Show_2424_String(272,148,"DEL",BLACK);

                            LCD_Show_3030_String(114,178,"7",BLACK);
                            LCD_Show_3030_String(170,178,"8",BLACK);
                            LCD_Show_3030_String(226,178,"9",BLACK);
                            LCD_Show_2424_String(277,180,"OK",BLACK);
                            *SubAnchor=0x08;
                            break;
                        case 0x08:

                            LCD_Draw_arrow_key(294,90,314,110,RIGHT,BLACK);

                            LCD_Show_3030_String(114,114,"1",BLACK);
                            LCD_Show_3030_String(170,114,"2",BLACK);
                            LCD_Show_3030_String(226,114,"3",BLACK);
                            LCD_Show_3030_String(282,114,"0",BLACK);

                            LCD_Show_3030_String(114,146,"4",BLACK);
                            LCD_Show_3030_String(170,146,"5",BLACK);
                            LCD_Show_3030_String(226,146,"6",BLACK);
                            LCD_Show_2424_String(272,148,"DEL",RED);

                            LCD_Show_3030_String(114,178,"7",BLACK);
                            LCD_Show_3030_String(170,178,"8",BLACK);
                            LCD_Show_3030_String(226,178,"9",BLACK);
                            LCD_Show_2424_String(277,180,"OK",BLACK);
                            *SubAnchor=0x09;
                            break;
                        case 0x09:

                            LCD_Draw_arrow_key(294,90,314,110,RIGHT,BLACK);

                            LCD_Show_3030_String(114,114,"1",BLACK);
                            LCD_Show_3030_String(170,114,"2",BLACK);
                            LCD_Show_3030_String(226,114,"3",BLACK);
                            LCD_Show_3030_String(282,114,"0",BLACK);

                            LCD_Show_3030_String(114,146,"4",BLACK);
                            LCD_Show_3030_String(170,146,"5",BLACK);
                            LCD_Show_3030_String(226,146,"6",BLACK);
                            LCD_Show_2424_String(272,148,"DEL",BLACK);

                            LCD_Show_3030_String(114,178,"7",RED);
                            LCD_Show_3030_String(170,178,"8",BLACK);
                            LCD_Show_3030_String(226,178,"9",BLACK);
                            LCD_Show_2424_String(277,180,"OK",BLACK);
                            *SubAnchor=0x0A;
                            break;
                        case 0x0A:


                            LCD_Draw_arrow_key(294,90,314,110,RIGHT,BLACK);

                            LCD_Show_3030_String(114,114,"1",BLACK);
                            LCD_Show_3030_String(170,114,"2",BLACK);
                            LCD_Show_3030_String(226,114,"3",BLACK);
                            LCD_Show_3030_String(282,114,"0",BLACK);

                            LCD_Show_3030_String(114,146,"4",BLACK);
                            LCD_Show_3030_String(170,146,"5",BLACK);
                            LCD_Show_3030_String(226,146,"6",BLACK);
                            LCD_Show_2424_String(272,148,"DEL",BLACK);

                            LCD_Show_3030_String(114,178,"7",BLACK);
                            LCD_Show_3030_String(170,178,"8",RED);
                            LCD_Show_3030_String(226,178,"9",BLACK);
                            LCD_Show_2424_String(277,180,"OK",BLACK);
                            *SubAnchor=0x0B;
                            break;
                        case 0x0B:


                            LCD_Draw_arrow_key(294,90,314,110,RIGHT,BLACK);

                            LCD_Show_3030_String(114,114,"1",BLACK);
                            LCD_Show_3030_String(170,114,"2",BLACK);
                            LCD_Show_3030_String(226,114,"3",BLACK);
                            LCD_Show_3030_String(282,114,"0",BLACK);

                            LCD_Show_3030_String(114,146,"4",BLACK);
                            LCD_Show_3030_String(170,146,"5",BLACK);
                            LCD_Show_3030_String(226,146,"6",BLACK);
                            LCD_Show_2424_String(272,148,"DEL",BLACK);

                            LCD_Show_3030_String(114,178,"7",BLACK);
                            LCD_Show_3030_String(170,178,"8",BLACK);
                            LCD_Show_3030_String(226,178,"9",RED);
                            LCD_Show_2424_String(277,180,"OK",BLACK);
                            *SubAnchor=0x0C;
                            break;
                        case 0x0C:

                            LCD_Draw_arrow_key(294,90,314,110,RIGHT,BLACK);

                            LCD_Show_3030_String(114,114,"1",BLACK);
                            LCD_Show_3030_String(170,114,"2",BLACK);
                            LCD_Show_3030_String(226,114,"3",BLACK);
                            LCD_Show_3030_String(282,114,"0",BLACK);

                            LCD_Show_3030_String(114,146,"4",BLACK);
                            LCD_Show_3030_String(170,146,"5",BLACK);
                            LCD_Show_3030_String(226,146,"6",BLACK);
                            LCD_Show_2424_String(272,148,"DEL",BLACK);

                            LCD_Show_3030_String(114,178,"7",BLACK);
                            LCD_Show_3030_String(170,178,"8",BLACK);
                            LCD_Show_3030_String(226,178,"9",BLACK);
                            LCD_Show_2424_String(277,180,"OK",RED);
                            *SubAnchor=0x0D;
                            break;



                        }
                }
            else if(encoder_dev.EN_STATE==SUBLEFT)
                {

                    switch(*SubAnchor)
                        {
                        case 0x0D:
                            LCD_Draw_arrow_key(294,90,314,110,RIGHT,BLACK);
                            LCD_Show_3030_String(114,114,"1",BLACK);
                            LCD_Show_3030_String(170,114,"2",BLACK);
                            LCD_Show_3030_String(226,114,"3",BLACK);
                            LCD_Show_3030_String(282,114,"0",BLACK);

                            LCD_Show_3030_String(114,146,"4",BLACK);
                            LCD_Show_3030_String(170,146,"5",BLACK);
                            LCD_Show_3030_String(226,146,"6",BLACK);
                            LCD_Show_2424_String(272,148,"DEL",BLACK);

                            LCD_Show_3030_String(114,178,"7",BLACK);
                            LCD_Show_3030_String(170,178,"8",BLACK);
                            LCD_Show_3030_String(226,178,"9",RED);
                            LCD_Show_2424_String(277,180,"OK",BLACK);
                            *SubAnchor=0x0C;
                            break;
                        case 0x0C:
                            LCD_Draw_arrow_key(294,90,314,110,RIGHT,BLACK);

                            LCD_Show_3030_String(114,114,"1",BLACK);
                            LCD_Show_3030_String(170,114,"2",BLACK);
                            LCD_Show_3030_String(226,114,"3",BLACK);
                            LCD_Show_3030_String(282,114,"0",BLACK);

                            LCD_Show_3030_String(114,146,"4",BLACK);
                            LCD_Show_3030_String(170,146,"5",BLACK);
                            LCD_Show_3030_String(226,146,"6",BLACK);
                            LCD_Show_2424_String(272,148,"DEL",BLACK);

                            LCD_Show_3030_String(114,178,"7",BLACK);
                            LCD_Show_3030_String(170,178,"8",RED);
                            LCD_Show_3030_String(226,178,"9",BLACK);
                            LCD_Show_2424_String(277,180,"OK",BLACK);
                            *SubAnchor=0x0B;
                            break;
                        case 0x0B:
                            LCD_Draw_arrow_key(294,90,314,110,RIGHT,BLACK);

                            LCD_Show_3030_String(114,114,"1",BLACK);
                            LCD_Show_3030_String(170,114,"2",BLACK);
                            LCD_Show_3030_String(226,114,"3",BLACK);
                            LCD_Show_3030_String(282,114,"0",BLACK);

                            LCD_Show_3030_String(114,146,"4",BLACK);
                            LCD_Show_3030_String(170,146,"5",BLACK);
                            LCD_Show_3030_String(226,146,"6",BLACK);
                            LCD_Show_2424_String(272,148,"DEL",BLACK);

                            LCD_Show_3030_String(114,178,"7",RED);
                            LCD_Show_3030_String(170,178,"8",BLACK);
                            LCD_Show_3030_String(226,178,"9",BLACK);
                            LCD_Show_2424_String(277,180,"OK",BLACK);
                            *SubAnchor=0x0A;
                            break;
                        case 0x0A:
                            LCD_Draw_arrow_key(294,90,314,110,RIGHT,BLACK);

                            LCD_Show_3030_String(114,114,"1",BLACK);
                            LCD_Show_3030_String(170,114,"2",BLACK);
                            LCD_Show_3030_String(226,114,"3",BLACK);
                            LCD_Show_3030_String(282,114,"0",BLACK);

                            LCD_Show_3030_String(114,146,"4",BLACK);
                            LCD_Show_3030_String(170,146,"5",BLACK);
                            LCD_Show_3030_String(226,146,"6",BLACK);
                            LCD_Show_2424_String(272,148,"DEL",RED);

                            LCD_Show_3030_String(114,178,"7",BLACK);
                            LCD_Show_3030_String(170,178,"8",BLACK);
                            LCD_Show_3030_String(226,178,"9",BLACK);
                            LCD_Show_2424_String(277,180,"OK",BLACK);
                            *SubAnchor=0x09;
                            break;
                        case 0x09:
                            LCD_Draw_arrow_key(294,90,314,110,RIGHT,BLACK);

                            LCD_Show_3030_String(114,114,"1",BLACK);
                            LCD_Show_3030_String(170,114,"2",BLACK);
                            LCD_Show_3030_String(226,114,"3",BLACK);
                            LCD_Show_3030_String(282,114,"0",BLACK);

                            LCD_Show_3030_String(114,146,"4",BLACK);
                            LCD_Show_3030_String(170,146,"5",BLACK);
                            LCD_Show_3030_String(226,146,"6",RED);
                            LCD_Show_2424_String(272,148,"DEL",BLACK);

                            LCD_Show_3030_String(114,178,"7",BLACK);
                            LCD_Show_3030_String(170,178,"8",BLACK);
                            LCD_Show_3030_String(226,178,"9",BLACK);
                            LCD_Show_2424_String(277,180,"OK",BLACK);
                            *SubAnchor=0x08;
                            break;
                        case 0x08:
                            LCD_Draw_arrow_key(294,90,314,110,RIGHT,BLACK);

                            LCD_Show_3030_String(114,114,"1",BLACK);
                            LCD_Show_3030_String(170,114,"2",BLACK);
                            LCD_Show_3030_String(226,114,"3",BLACK);
                            LCD_Show_3030_String(282,114,"0",BLACK);

                            LCD_Show_3030_String(114,146,"4",BLACK);
                            LCD_Show_3030_String(170,146,"5",RED);
                            LCD_Show_3030_String(226,146,"6",BLACK);
                            LCD_Show_2424_String(272,148,"DEL",BLACK);

                            LCD_Show_3030_String(114,178,"7",BLACK);
                            LCD_Show_3030_String(170,178,"8",BLACK);
                            LCD_Show_3030_String(226,178,"9",BLACK);
                            LCD_Show_2424_String(277,180,"OK",BLACK);
                            *SubAnchor=0x07;
                            break;
                        case 0x07:
                            LCD_Draw_arrow_key(294,90,314,110,RIGHT,BLACK);

                            LCD_Show_3030_String(114,114,"1",BLACK);
                            LCD_Show_3030_String(170,114,"2",BLACK);
                            LCD_Show_3030_String(226,114,"3",BLACK);
                            LCD_Show_3030_String(282,114,"0",BLACK);

                            LCD_Show_3030_String(114,146,"4",RED);
                            LCD_Show_3030_String(170,146,"5",BLACK);
                            LCD_Show_3030_String(226,146,"6",BLACK);
                            LCD_Show_2424_String(272,148,"DEL",BLACK);

                            LCD_Show_3030_String(114,178,"7",BLACK);
                            LCD_Show_3030_String(170,178,"8",BLACK);
                            LCD_Show_3030_String(226,178,"9",BLACK);
                            LCD_Show_2424_String(277,180,"OK",BLACK);
                            *SubAnchor=0x06;
                            break;
                        case 0x06:
                            LCD_Draw_arrow_key(294,90,314,110,RIGHT,BLACK);

                            LCD_Show_3030_String(114,114,"1",BLACK);
                            LCD_Show_3030_String(170,114,"2",BLACK);
                            LCD_Show_3030_String(226,114,"3",BLACK);
                            LCD_Show_3030_String(282,114,"0",RED);

                            LCD_Show_3030_String(114,146,"4",BLACK);
                            LCD_Show_3030_String(170,146,"5",BLACK);
                            LCD_Show_3030_String(226,146,"6",BLACK);
                            LCD_Show_2424_String(272,148,"DEL",BLACK);

                            LCD_Show_3030_String(114,178,"7",BLACK);
                            LCD_Show_3030_String(170,178,"8",BLACK);
                            LCD_Show_3030_String(226,178,"9",BLACK);
                            LCD_Show_2424_String(277,180,"OK",BLACK);
                            *SubAnchor=0x05;
                            break;
                        case 0x05:
                            LCD_Draw_arrow_key(294,90,314,110,RIGHT,BLACK);

                            LCD_Show_3030_String(114,114,"1",BLACK);
                            LCD_Show_3030_String(170,114,"2",BLACK);
                            LCD_Show_3030_String(226,114,"3",RED);
                            LCD_Show_3030_String(282,114,"0",BLACK);

                            LCD_Show_3030_String(114,146,"4",BLACK);
                            LCD_Show_3030_String(170,146,"5",BLACK);
                            LCD_Show_3030_String(226,146,"6",BLACK);
                            LCD_Show_2424_String(272,148,"DEL",BLACK);

                            LCD_Show_3030_String(114,178,"7",BLACK);
                            LCD_Show_3030_String(170,178,"8",BLACK);
                            LCD_Show_3030_String(226,178,"9",BLACK);
                            LCD_Show_2424_String(277,180,"OK",BLACK);
                            *SubAnchor=0x04;
                            break;
                        case 0x04:
                            LCD_Draw_arrow_key(294,90,314,110,RIGHT,BLACK);

                            LCD_Show_3030_String(114,114,"1",BLACK);
                            LCD_Show_3030_String(170,114,"2",RED);
                            LCD_Show_3030_String(226,114,"3",BLACK);
                            LCD_Show_3030_String(282,114,"0",BLACK);

                            LCD_Show_3030_String(114,146,"4",BLACK);
                            LCD_Show_3030_String(170,146,"5",BLACK);
                            LCD_Show_3030_String(226,146,"6",BLACK);
                            LCD_Show_2424_String(272,148,"DEL",BLACK);

                            LCD_Show_3030_String(114,178,"7",BLACK);
                            LCD_Show_3030_String(170,178,"8",BLACK);
                            LCD_Show_3030_String(226,178,"9",BLACK);
                            LCD_Show_2424_String(277,180,"OK",BLACK);
                            *SubAnchor=0x03;
                            break;
                        case 0x03:
                            LCD_Draw_arrow_key(294,90,314,110,RIGHT,BLACK);

                            LCD_Show_3030_String(114,114,"1",RED);
                            LCD_Show_3030_String(170,114,"2",BLACK);
                            LCD_Show_3030_String(226,114,"3",BLACK);
                            LCD_Show_3030_String(282,114,"0",BLACK);

                            LCD_Show_3030_String(114,146,"4",BLACK);
                            LCD_Show_3030_String(170,146,"5",BLACK);
                            LCD_Show_3030_String(226,146,"6",BLACK);
                            LCD_Show_2424_String(272,148,"DEL",BLACK);

                            LCD_Show_3030_String(114,178,"7",BLACK);
                            LCD_Show_3030_String(170,178,"8",BLACK);
                            LCD_Show_3030_String(226,178,"9",BLACK);
                            LCD_Show_2424_String(277,180,"OK",BLACK);
                            *SubAnchor=0x02;
                            break;
                        case 0x02:
                            LCD_Draw_arrow_key(294,90,314,110,RIGHT,RED);

                            LCD_Show_3030_String(114,114,"1",BLACK);
                            LCD_Show_3030_String(170,114,"2",BLACK);
                            LCD_Show_3030_String(226,114,"3",BLACK);
                            LCD_Show_3030_String(282,114,"0",BLACK);

                            LCD_Show_3030_String(114,146,"4",BLACK);
                            LCD_Show_3030_String(170,146,"5",BLACK);
                            LCD_Show_3030_String(226,146,"6",BLACK);
                            LCD_Show_2424_String(272,148,"DEL",BLACK);

                            LCD_Show_3030_String(114,178,"7",BLACK);
                            LCD_Show_3030_String(170,178,"8",BLACK);
                            LCD_Show_3030_String(226,178,"9",BLACK);
                            LCD_Show_2424_String(277,180,"OK",BLACK);
                            *SubAnchor=0x01;
                            break;



                        }
                }

            if(flag_dev.action_flag==KEY_BOARD&&encoder_dev.EN_KEY==EN_KEY_DOWN)
                {
                    switch(*SubAnchor)
                        {
                        case 0x01:
                            if(flag_dev.lock_sta==L_CLOSE)
                                {

                                    LCD_Fill(93,42,319,208,BLACK);
                                    flag_dev.save_flag=0;
                                    main_setting_page_activity();
                                    flag_dev.action_flag=HOME;
                                    delay_ms(300);
                                    a=0;

                                }
                            else if(flag_dev.lock_sta==L_OPEN)
                                {

                                    if(flag_dev.pwd_anchor==1||flag_dev.pwd_anchor==2||flag_dev.pwd_anchor==5)
                                        {
                                            LCD_Fill(93,42,319,208,BLACK);
                                            flag_dev.save_flag=0;
                                            gui_draw_arcrectangle(94,0,226,40,3,1, RED,RED);
                                            pwd_page_activity();
                                            flag_dev.action_flag=PWD;
                                            delay_ms(300);
                                            a=0;
                                            Lastaction=PWD;
                                            flag_dev.TOSUBPAGE=1;
                                            *SubAnchor=0;
                                        }
                                    else if(flag_dev.pwd_anchor==3)
                                        {
                                            LCD_Fill(93,42,319,208,BLACK);
                                            flag_dev.save_flag=0;
                                            auz_page_activity();
                                            flag_dev.action_flag=AUZ;
                                            delay_ms(300);
                                            a=0;
                                        }
                                    else if(flag_dev.pwd_anchor==4)
                                        {
                                            LCD_Clear(BLUE);
                                            gui_draw_arcrectangle(50,109,226,30,1,1,WHITE,WHITE);
                                            LCD_Show_2424_String(50,80,"AUZ CODE:",WHITE);
                                            flag_dev.action_flag=AUZ;
                                            a=0;


                                        }
                                }

                            break;
                        case 0x02:
                            flag_dev.key_board_num=1;
                            flag_dev.key_board_state=1;
                            break;
                        case 0x03:
                            flag_dev.key_board_num=2;
                            flag_dev.key_board_state=1;
                            break;
                        case 0x04:
                            flag_dev.key_board_num=3;
                            flag_dev.key_board_state=1;
                            break;
                        case 0x05:
                            flag_dev.key_board_num=0;
                            flag_dev.key_board_state=1;
                            break;
                        case 0x06:
                            flag_dev.key_board_num=4;
                            flag_dev.key_board_state=1;
                            break;
                        case 0x07:
                            flag_dev.key_board_num=5;
                            flag_dev.key_board_state=1;
                            break;
                        case 0x08:
                            flag_dev.key_board_num=6;
                            flag_dev.key_board_state=1;
                            break;
                        case 0x09:
                            flag_dev.key_board_num=DEL;
                            flag_dev.key_board_state=1;
                            break;
                        case 0x0A:
                            flag_dev.key_board_num=7;
                            flag_dev.key_board_state=1;
                            break;
                        case 0x0B:
                            flag_dev.key_board_num=8;
                            flag_dev.key_board_state=1;
                            break;
                        case 0x0C:
                            flag_dev.key_board_num=9;
                            flag_dev.key_board_state=1;
                            break;
                        case 0x0D:
                            flag_dev.key_board_num=OK;
                            flag_dev.key_board_state=1;
                            break;
                        }

                }

        }
}

void EncoderTimer(u8 *SubAnchor)
{

    if(flag_dev.action_flag==TIMER&&ItemAnchor==0)
        {


            if(encoder_dev.EN_STATE==SUBRIGHT)
                {
                    switch(*SubAnchor)
                        {
                        case 0x00:

                            gui_draw_arcrectangle(95,45,225,30,1,1,RED,RED);
                            gui_draw_arcrectangle(160,48,158,24, 1,1,WHITE,WHITE);
                            LCD_DrawLtrigo(160,48,185,73,LEFT,RED);
                            LCD_DrawLtrigo(292,48,317,73,RIGHT,RED);
                            if(flag_dev.langage==1)
                                LCD_Show_2424_String(95, 48,"STATE",WHITE);
                            else
                                ShowTwoChineseChar(102,48,47,48,24,WHITE);

                            if(chan_dev.timer_state==0)
                                {

                                    if(flag_dev.langage==1)
                                        LCD_Show_2424_String(225, 48,"OFF",BLACK);
                                    else
                                        ShowChineseChar(230,48,6,24,BLACK);
                                }
                            if(chan_dev.timer_state==1)
                                {
                                    if(flag_dev.langage==1)
                                        LCD_Show_2424_String(218, 48, "OPEN",BLACK);
                                    else
                                        {
                                            ShowTwoChineseChar(206,48,0,1,24,BLACK);
                                            ShowChineseChar(254,48,5,24,BLACK);
                                        }

                                }
                            if(chan_dev.timer_state==2)
                                {
                                    if(flag_dev.langage==1)
                                        LCD_Show_2424_String(212, 48,"CLOSE",BLACK);
                                    else
                                        {
                                            ShowTwoChineseChar(206,48,0,1,24,BLACK);
                                            ShowChineseChar(254,48,6,24,BLACK);
                                        }

                                }

                            *SubAnchor=0x01;//STATE
                            break;
                        case 0x01:
                            gui_draw_arcrectangle(95,45,225,30,1,1,BLUE,BLUE);
                            gui_draw_arcrectangle(160,48,158,24,1,1,WHITE,WHITE);
                            LCD_DrawLtrigo(160,48,185,73,LEFT,BLUE);
                            LCD_DrawLtrigo(292,48,317,73,RIGHT,BLUE);
                            if(flag_dev.langage==1)
                                LCD_Show_2424_String(95, 48,"STATE",WHITE);
                            else
                                ShowTwoChineseChar(102,48,47,48,24,WHITE);

                            if(chan_dev.timer_state==0)
                                {
                                    LCD_Fill(180,48,300,71,WHITE);
                                    if(flag_dev.langage==1)
                                        LCD_Show_2424_String(225, 48,"OFF",BLACK);
                                    else
                                        ShowChineseChar(230,48,6,24,BLACK);


                                }
                            if(chan_dev.timer_state==1)
                                {
                                    LCD_Fill(180,48,300,71,WHITE);
                                    if(flag_dev.langage==1)
                                        LCD_Show_2424_String(218, 48, "OPEN",BLACK);
                                    else
                                        {
                                            ShowTwoChineseChar(206,48,0,1,24,BLACK);
                                            ShowChineseChar(254,48,5,24,BLACK);
                                        }

                                }
                            if(chan_dev .timer_state==2)
                                {
                                    LCD_Fill(180,48,300,71,WHITE);
                                    if(flag_dev.langage==1)
                                        LCD_Show_2424_String(212, 48,"CLOSE",BLACK);
                                    else
                                        {
                                            ShowTwoChineseChar(206,48,0,1,24,BLACK);
                                            ShowChineseChar(254,48,6,24,BLACK);
                                        }

                                }

                            gui_draw_arcrectangle(95,77,225,30, 1,1,RED,RED);
                            gui_draw_arcrectangle(160,80,158,24, 1,1,WHITE,WHITE);
                            if(flag_dev.langage==1)
                                LCD_Show_2424_String(95,80,"CHAN",WHITE);
                            else
                                ShowTwoChineseChar(102,80,0,1,24,WHITE);

                            if(chan_dev.chan1)
                                {
                                    LCD_Show_2424_String(165,80,"1",RED);
                                }
                            else
                                {
                                    LCD_Show_2424_String(165,80,"1",BLACK);
                                }

                            if(chan_dev.chan2)
                                {
                                    LCD_Show_2424_String(185,80,"2",RED);

                                }
                            else
                                {
                                    LCD_Show_2424_String(185,80,"2",BLACK);

                                }
                            if(chan_dev.chan3)
                                {
                                    LCD_Show_2424_String(205,80,"3",RED);

                                }
                            else
                                {
                                    LCD_Show_2424_String(205,80,"3",BLACK);

                                }
                            if(chan_dev.chan4)
                                {
                                    LCD_Show_2424_String(225,80,"4",RED);

                                }
                            else
                                {
                                    LCD_Show_2424_String(225,80,"4",BLACK);

                                }

                            if(chan_dev.chan5)
                                {
                                    LCD_Show_2424_String(245,80,"5",RED);

                                }
                            else
                                {
                                    LCD_Show_2424_String(245,80,"5",BLACK);

                                }
                            if(chan_dev.chan6)
                                {
                                    LCD_Show_2424_String(265,80,"6",RED);

                                }
                            else
                                {
                                    LCD_Show_2424_String(265,80,"6",BLACK);

                                }

                            if(chan_dev.chan7)
                                {
                                    LCD_Show_2424_String(285,80,"7",RED);
                                }
                            else
                                {
                                    LCD_Show_2424_String(285,80,"7",BLACK);

                                }
                            if(chan_dev.chan8)
                                {
                                    LCD_Show_2424_String(305,80,"8",RED);

                                }
                            else
                                {
                                    LCD_Show_2424_String(305,80,"8",BLACK);
                                }
                            *SubAnchor=0x02;//CHAN
                            break;
                        case 0x02:
                            gui_draw_arcrectangle(95,77,225,30, 1,1,BLUE,BLUE);
                            gui_draw_arcrectangle(160,80,158,24, 1,1,WHITE,WHITE);
                            if(flag_dev.langage==1)
                                LCD_Show_2424_String(95,80,"CHAN",WHITE);
                            else
                                ShowTwoChineseChar(102,80,0,1,24,WHITE);

                            if(chan_dev.chan1)
                                {
                                    LCD_Show_2424_String(165,80,"1",RED);
                                }
                            else
                                {
                                    LCD_Show_2424_String(165,80,"1",BLACK);
                                }

                            if(chan_dev.chan2)
                                {
                                    LCD_Show_2424_String(185,80,"2",RED);

                                }
                            else
                                {
                                    LCD_Show_2424_String(185,80,"2",BLACK);

                                }


                            if(chan_dev.chan3)
                                {
                                    LCD_Show_2424_String(205,80,"3",RED);

                                }
                            else
                                {
                                    LCD_Show_2424_String(205,80,"3",BLACK);

                                }
                            if(chan_dev.chan4)
                                {
                                    LCD_Show_2424_String(225,80,"4",RED);

                                }
                            else
                                {
                                    LCD_Show_2424_String(225,80,"4",BLACK);

                                }

                            if(chan_dev.chan5)
                                {
                                    LCD_Show_2424_String(245,80,"5",RED);

                                }
                            else
                                {
                                    LCD_Show_2424_String(245,80,"5",BLACK);

                                }
                            if(chan_dev.chan6)
                                {
                                    LCD_Show_2424_String(265,80,"6",RED);

                                }
                            else
                                {
                                    LCD_Show_2424_String(265,80,"6",BLACK);

                                }

                            if(chan_dev.chan7)
                                {
                                    LCD_Show_2424_String(285,80,"7",RED);
                                }
                            else
                                {
                                    LCD_Show_2424_String(285,80,"7",BLACK);

                                }
                            if(chan_dev.chan8)
                                {
                                    LCD_Show_2424_String(305,80,"8",RED);

                                }
                            else
                                {
                                    LCD_Show_2424_String(305,80,"8",BLACK);
                                }
                            gui_draw_arcrectangle(95,109,225,30,1,1,RED,RED);
                            gui_draw_arcrectangle(160,112,158,24,1,1,WHITE,WHITE);
                            LCD_DrawLtrigo(160,112,185,137,LEFT,RED);
                            LCD_DrawLtrigo(292,112,317,137,RIGHT,RED);
                            if(flag_dev.langage==1)
                                LCD_Show_2424_String(95,112,"MODE",WHITE);
                            else
                                ShowTwoChineseChar(102,112,49,50,24,WHITE);
                            if(chan_dev.mode==ONCE)
                                {
                                    LCD_Fill(180,112,280,135,WHITE);
                                    if(flag_dev.langage==1)
                                        LCD_Show_2424_String(220,112,"ONCE",BLACK);
                                    else
                                        ShowTwoChineseChar(217,112,54,44,24,BLACK);
                                }
                            else  if(chan_dev.mode==LOOP)
                                {
                                    LCD_Fill(180,112,280,135,WHITE);
                                    if(flag_dev.langage==1)
                                        LCD_Show_2424_String(220,112,"LOOP",BLACK);
                                    else
                                        ShowTwoChineseChar(217,112,52,53,24,BLACK);
                                }
                            *SubAnchor=0x03;//MODE
                            break;
                        case 0x03:
                            gui_draw_arcrectangle(95,109,225,30,1,1,BLUE,BLUE);
                            gui_draw_arcrectangle(160,112,158,24,1,1,WHITE,WHITE);
                            LCD_DrawLtrigo(160,112,185,137,LEFT,BLUE);
                            LCD_DrawLtrigo(292,112,317,137,RIGHT,BLUE);
                            if(flag_dev.langage==1)
                                LCD_Show_2424_String(95,112,"MODE",WHITE);
                            else
                                ShowTwoChineseChar(102,112,49,50,24,WHITE);
                            if(chan_dev.mode==ONCE)
                                {
                                    LCD_Fill(180,112,280,135,WHITE);
                                    if(flag_dev.langage==1)
                                        LCD_Show_2424_String(220,112,"ONCE",BLACK);
                                    else
                                        ShowTwoChineseChar(217,112,54,44,24,BLACK);
                                }
                            else  if(chan_dev.mode==LOOP)
                                {
                                    LCD_Fill(180,112,280,135,WHITE);
                                    if(flag_dev.langage==1)
                                        LCD_Show_2424_String(220,112,"LOOP",BLACK);
                                    else
                                        ShowTwoChineseChar(217,112,52,53,24,BLACK);
                                }
                            if(chan_dev.mode==ONCE)
                                {

                                    gui_draw_arcrectangle(95,141,225,30,1,1,RED,RED);
                                    gui_draw_arcrectangle(160,144,158,24,1,1,WHITE,WHITE);
                                    if(flag_dev.langage==1)
                                        LCD_Show_2424_String(95,144,"DATE",WHITE);
                                    else
                                        ShowTwoChineseChar(102,144,8,9,24,WHITE);

                                    LCD_Show_2424_String(180,144,"    -  -  ",BLACK);
                                    LCD_ShowNum(180,144,chan_dev.date_year,4,24,BLACK,WHITE);
                                    LCD_ShowNum(240,144,chan_dev.date_month,2,24,BLACK,WHITE);
                                    LCD_ShowNum(276,144,chan_dev.date_day,2,24,BLACK,WHITE);



                                }
                            else  if(chan_dev.mode==LOOP)
                                {
                                    gui_draw_arcrectangle(95,141,225,30,1,1,RED,RED);
                                    gui_draw_arcrectangle(160,144,158,24,1,1,WHITE,WHITE);
                                    LCD_DrawLtrigo(160,144,185,169,LEFT,BLUE);
                                    LCD_DrawLtrigo(292,144,317,169,RIGHT,BLUE);
                                    if(flag_dev.langage==1)
                                        LCD_Show_2424_String(95,144,"WEEK",WHITE);
                                    else
                                        ShowTwoChineseChar(102,144,51,9,24,WHITE);

                                    if(chan_dev.week&0x01)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_2424_String(200,144,"  SUN  ",RED);
                                            else
                                                {
                                                    ShowTwoChineseChar(206,144,51,9,24,RED);
                                                    ShowChineseChar(254,144,8,24,RED);
                                                }
                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_2424_String(200,144,"  SUN  ",BLACK);
                                            else
                                                {
                                                    ShowTwoChineseChar(206,144,51,9,24,BLACK);
                                                    ShowChineseChar(254,144,8,24,BLACK);
                                                }
                                        }
                                    flag_dev.WeekAnchor=0x01;

                                }
                            *SubAnchor=0x04;//DATE
                            break;
                        case 0x04:
                            if(chan_dev.mode==ONCE)
                                {

                                    gui_draw_arcrectangle(95,141,225,30,1,1,BLUE,BLUE);
                                    gui_draw_arcrectangle(160,144,158,24,1,1,WHITE,WHITE);
                                    if(flag_dev.langage==1)
                                        LCD_Show_2424_String(95,144,"DATE",WHITE);
                                    else
                                        ShowTwoChineseChar(102,144,8,9,24,WHITE);

                                    LCD_Show_2424_String(180,144,"    -  -  ",BLACK);
                                    LCD_ShowNum(180,144,chan_dev.date_year,4,24,BLACK,WHITE);
                                    LCD_ShowNum(240,144,chan_dev.date_month,2,24,BLACK,WHITE);
                                    LCD_ShowNum(276,144,chan_dev.date_day,2,24,BLACK,WHITE);



                                }
                            else  if(chan_dev.mode==LOOP)
                                {
                                    gui_draw_arcrectangle(95,141,225,30,1,1,BLUE,BLUE);
                                    gui_draw_arcrectangle(160,144,158,24,1,1,WHITE,WHITE);
                                    LCD_DrawLtrigo(160,144,185,169,LEFT,BLUE);
                                    LCD_DrawLtrigo(292,144,317,169,RIGHT,BLUE);
                                    if(flag_dev.langage==1)
                                        LCD_Show_2424_String(95,144,"WEEK",WHITE);
                                    else
                                        ShowTwoChineseChar(102,144,51,9,24,WHITE);

                                    if(chan_dev.week&0x01)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_2424_String(200,144,"  SUN  ",RED);
                                            else
                                                {
                                                    ShowTwoChineseChar(206,144,51,9,24,RED);
                                                    ShowChineseChar(254,144,8,24,RED);
                                                }
                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_2424_String(200,144,"  SUN  ",BLACK);
                                            else
                                                {
                                                    ShowTwoChineseChar(206,144,51,9,24,BLACK);
                                                    ShowChineseChar(254,144,8,24,BLACK);
                                                }
                                        }
                                    flag_dev.WeekAnchor=0x01;

                                }
                            gui_draw_arcrectangle(95,173,225,32,1,1,RED,RED);
                            gui_draw_arcrectangle(160,176,158,24,1,1,WHITE,WHITE);
                            if(flag_dev.langage==1)
                                LCD_Show_2424_String(95,176,"TIME",WHITE);
                            else
                                ShowTwoChineseChar(102,176,3,16,24,WHITE);
                            LCD_Show_2424_String(180,176,"  :  :  ",BLACK);
                            LCD_ShowNum(180,176,chan_dev.time_hour,2,24,BLACK,WHITE);
                            LCD_ShowNum(216,176,chan_dev.time_min,2,24,BLACK,WHITE);
                            LCD_ShowNum(252,176,chan_dev.time_sec,2,24,BLACK,WHITE);
                            *SubAnchor=0x05;//TIME
                            break;
                        case 0x05:
                            gui_draw_arcrectangle(95,173,225,32,1,1,BLUE,BLUE);
                            gui_draw_arcrectangle(160,176,158,24,1,1,WHITE,WHITE);
                            if(flag_dev.langage==1)
                                LCD_Show_2424_String(95,176,"TIME",WHITE);
                            else
                                ShowTwoChineseChar(102,176,3,16,24,WHITE);
                            LCD_Show_2424_String(180,176,"  :  :  ",BLACK);
                            LCD_ShowNum(180,176,chan_dev.time_hour,2,24,BLACK,WHITE);
                            LCD_ShowNum(216,176,chan_dev.time_min,2,24,BLACK,WHITE);
                            LCD_ShowNum(252,176,chan_dev.time_sec,2,24,BLACK,WHITE);

                            gui_draw_arcrectangle(120,210,80,30,1,1,BLUE,BLUE);
                            gui_draw_arcrectangle(125,212,70,28,1,1,RED,RED);
                            if(flag_dev.langage==1)
                                LCD_Show_3030_String(130,210,"SAVE",WHITE);
                            else
                                ShowTwoChineseChar(135,213,10,11,24,WHITE);
                            *SubAnchor=0x06;//SAVE
                            break;
                        case 0x06:
                            gui_draw_arcrectangle(120,210,80,30,1,1,BLUE,BLUE);
                            gui_draw_arcrectangle(125,212,70,28,1,1,WHITE,WHITE);
                            if(flag_dev.langage==1)
                                LCD_Show_3030_String(130,210,"SAVE",BLACK);
                            else
                                ShowTwoChineseChar(135,213,10,11,24,BLACK);
                            LCD_DrawLtrigo(230,215,255,240,LEFT,RED);
                            LCD_Show_picture(250,210,WHITE,0);
                            *SubAnchor=0x07;//LEFT
                            break;
                        case 0x07:
                            LCD_DrawLtrigo(230,215,255,240,LEFT,WHITE);
                            LCD_Show_picture(250,210,RED,0);
                            *SubAnchor=0x08;
                            break;
                        case 0x08:
                            LCD_Show_picture(250,210,WHITE,0);
                            LCD_DrawLtrigo(282,215,307,240,RIGHT,RED);
                            *SubAnchor=0x09;//RIGHT
                            break;
                        }

                }
            else if(encoder_dev.EN_STATE==SUBLEFT)
                {
                    switch(*SubAnchor)
                        {

                        case 0x02:
                            gui_draw_arcrectangle(95,45,225,30,1,1,RED,RED);
                            gui_draw_arcrectangle(160,48,158,24,1,1,WHITE,WHITE);
                            LCD_DrawLtrigo(160,48,185,73,LEFT,RED);
                            LCD_DrawLtrigo(292,48,317,73,RIGHT,RED);
                            if(flag_dev.langage==1)
                                LCD_Show_2424_String(95, 48,"STATE",WHITE);
                            else
                                ShowTwoChineseChar(102,48,47,48,24,WHITE);

                            if(chan_dev.timer_state==0)
                                {
                                    LCD_Fill(180,48,300,71,WHITE);
																	  if(flag_dev.langage==1)
                                    LCD_Show_2424_String(225, 48,"OFF",BLACK);
                                    else
                                    ShowChineseChar(230,48,6,24,BLACK);
                                }
                            if(chan_dev.timer_state==1)
                                {
                                    LCD_Fill(180,48,300,71,WHITE);
                                    if(flag_dev.langage==1)
                                        LCD_Show_2424_String(218, 48, "OPEN",BLACK);
                                    else
                                        {
                                            ShowTwoChineseChar(206,48,0,1,24,BLACK);
                                            ShowChineseChar(254,48,5,24,BLACK);
                                        }

                                }
                            if(chan_dev.timer_state==2)
                                {
                                    LCD_Fill(180,48,300,71,WHITE);
                                    if(flag_dev.langage==1)
                                        LCD_Show_2424_String(212, 48,"CLOSE",BLACK);
                                    else
                                        {
                                            ShowTwoChineseChar(206,48,0,1,24,BLACK);
                                            ShowChineseChar(254,48,6,24,BLACK);
                                        }

                                }

                            gui_draw_arcrectangle(95,77,225,30, 1,1,BLUE,BLUE);
                            gui_draw_arcrectangle(160,80,158,24, 1,1,WHITE,WHITE);
                            if(flag_dev.langage==1)
                                LCD_Show_2424_String(95,80,"CHAN",WHITE);
                            else
                                ShowTwoChineseChar(102,80,0,1,24,WHITE);

                            if(chan_dev.chan1)
                                {
                                    LCD_Show_2424_String(165,80,"1",RED);
                                }
                            else
                                {
                                    LCD_Show_2424_String(165,80,"1",BLACK);
                                }

                            if(chan_dev.chan2)
                                {
                                    LCD_Show_2424_String(185,80,"2",RED);

                                }
                            else
                                {
                                    LCD_Show_2424_String(185,80,"2",BLACK);

                                }
                            if(chan_dev.chan3)
                                {
                                    LCD_Show_2424_String(205,80,"3",RED);

                                }
                            else
                                {
                                    LCD_Show_2424_String(205,80,"3",BLACK);

                                }
                            if(chan_dev.chan4)
                                {
                                    LCD_Show_2424_String(225,80,"4",RED);

                                }
                            else
                                {
                                    LCD_Show_2424_String(225,80,"4",BLACK);

                                }

                            if(chan_dev.chan5)
                                {
                                    LCD_Show_2424_String(245,80,"5",RED);

                                }
                            else
                                {
                                    LCD_Show_2424_String(245,80,"5",BLACK);

                                }
                            if(chan_dev.chan6)
                                {
                                    LCD_Show_2424_String(265,80,"6",RED);

                                }
                            else
                                {
                                    LCD_Show_2424_String(265,80,"6",BLACK);

                                }

                            if(chan_dev.chan7)
                                {
                                    LCD_Show_2424_String(285,80,"7",RED);
                                }
                            else
                                {
                                    LCD_Show_2424_String(285,80,"7",BLACK);

                                }
                            if(chan_dev.chan8)
                                {
                                    LCD_Show_2424_String(305,80,"8",RED);

                                }
                            else
                                {
                                    LCD_Show_2424_String(305,80,"8",BLACK);
                                }
                            *SubAnchor=0x01;
                            break;
                        case 0x03:
                            gui_draw_arcrectangle(95,77,225,30, 1,1,RED,RED);
                            gui_draw_arcrectangle(160,80,158,24, 1,1,WHITE,WHITE);
                            if(flag_dev.langage==1)
                                LCD_Show_2424_String(95,80,"CHAN",WHITE);
                            else
                                ShowTwoChineseChar(102,80,0,1,24,WHITE);
                            if(chan_dev.chan1)
                                {
                                    LCD_Show_2424_String(165,80,"1",RED);
                                }
                            else
                                {
                                    LCD_Show_2424_String(165,80,"1",BLACK);
                                }

                            if(chan_dev.chan2)
                                {
                                    LCD_Show_2424_String(185,80,"2",RED);

                                }
                            else
                                {
                                    LCD_Show_2424_String(185,80,"2",BLACK);

                                }


                            if(chan_dev.chan3)
                                {
                                    LCD_Show_2424_String(205,80,"3",RED);

                                }
                            else
                                {
                                    LCD_Show_2424_String(205,80,"3",BLACK);

                                }
                            if(chan_dev.chan4)
                                {
                                    LCD_Show_2424_String(225,80,"4",RED);

                                }
                            else
                                {
                                    LCD_Show_2424_String(225,80,"4",BLACK);

                                }

                            if(chan_dev.chan5)
                                {
                                    LCD_Show_2424_String(245,80,"5",RED);

                                }
                            else
                                {
                                    LCD_Show_2424_String(245,80,"5",BLACK);

                                }
                            if(chan_dev.chan6)
                                {
                                    LCD_Show_2424_String(265,80,"6",RED);

                                }
                            else
                                {
                                    LCD_Show_2424_String(265,80,"6",BLACK);

                                }

                            if(chan_dev.chan7)
                                {
                                    LCD_Show_2424_String(285,80,"7",RED);
                                }
                            else
                                {
                                    LCD_Show_2424_String(285,80,"7",BLACK);

                                }
                            if(chan_dev.chan8)
                                {
                                    LCD_Show_2424_String(305,80,"8",RED);

                                }
                            else
                                {
                                    LCD_Show_2424_String(305,80,"8",BLACK);
                                }
                            gui_draw_arcrectangle(95,109,225,30,1,1,BLUE,BLUE);
                            gui_draw_arcrectangle(160,112,158,24,1,1,WHITE,WHITE);
                            LCD_DrawLtrigo(160,112,185,137,LEFT,BLUE);
                            LCD_DrawLtrigo(292,112,317,137,RIGHT,BLUE);
                            if(flag_dev.langage==1)
                                LCD_Show_2424_String(95,112,"MODE",WHITE);
                            else
                                ShowTwoChineseChar(102,112,49,50,24,WHITE);
                            if(chan_dev.mode==ONCE)
                                {
                                    LCD_Fill(180,112,280,135,WHITE);
                                    if(flag_dev.langage==1)
                                        LCD_Show_2424_String(220,112,"ONCE",BLACK);
                                    else
                                        ShowTwoChineseChar(217,112,54,44,24,BLACK);
                                }
                            else  if(chan_dev.mode==LOOP)
                                {
                                    LCD_Fill(180,112,280,135,WHITE);
                                    if(flag_dev.langage==1)
                                        LCD_Show_2424_String(220,112,"LOOP",BLACK);
                                    else
                                        ShowTwoChineseChar(217,112,52,53,24,BLACK);
                                }
                            *SubAnchor=0x02;
                            break;
                        case 0x04:
                            gui_draw_arcrectangle(95,109,225,30,1,1,RED,RED);
                            gui_draw_arcrectangle(160,112,158,24,1,1,WHITE,WHITE);
                            LCD_DrawLtrigo(160,112,185,137,LEFT,RED);
                            LCD_DrawLtrigo(292,112,317,137,RIGHT,RED);
                            if(flag_dev.langage==1)
                                LCD_Show_2424_String(95,112,"MODE",WHITE);
                            else
                                ShowTwoChineseChar(102,112,49,50,24,WHITE);
                            if(chan_dev.mode==ONCE)
                                {
                                    LCD_Fill(180,112,280,135,WHITE);
                                    if(flag_dev.langage==1)
                                        LCD_Show_2424_String(220,112,"ONCE",BLACK);
                                    else
                                        ShowTwoChineseChar(217,112,54,44,24,BLACK);
                                }
                            else  if(chan_dev.mode==LOOP)
                                {
                                    LCD_Fill(180,112,280,135,WHITE);
                                    if(flag_dev.langage==1)
                                        LCD_Show_2424_String(220,112,"LOOP",BLACK);
                                    else
                                        ShowTwoChineseChar(217,112,52,53,24,BLACK);
                                }
                            if(chan_dev.mode==ONCE)
                                {

                                    gui_draw_arcrectangle(95,141,225,30,1,1,BLUE,BLUE);
                                    gui_draw_arcrectangle(160,144,158,24,1,1,WHITE,WHITE);
                                    if(flag_dev.langage==1)
                                        LCD_Show_2424_String(95,144,"DATE",WHITE);
                                    else
                                        ShowTwoChineseChar(102,144,8,9,24,WHITE);

                                    LCD_Show_2424_String(180,144,"    -  -  ",BLACK);
                                    LCD_ShowNum(180,144,chan_dev.date_year,4,24,BLACK,WHITE);
                                    LCD_ShowNum(240,144,chan_dev.date_month,2,24,BLACK,WHITE);
                                    LCD_ShowNum(276,144,chan_dev.date_day,2,24,BLACK,WHITE);



                                }
                            else  if(chan_dev.mode==LOOP)
                                {
                                    gui_draw_arcrectangle(95,141,225,30,1,1,BLUE,BLUE);
                                    gui_draw_arcrectangle(160,144,158,24,1,1,WHITE,WHITE);
                                    LCD_DrawLtrigo(160,144,185,169,LEFT,BLUE);
                                    LCD_DrawLtrigo(292,144,317,169,RIGHT,BLUE);
                                    if(flag_dev.langage==1)
                                        LCD_Show_2424_String(95,144,"WEEK",WHITE);
                                    else
                                        ShowTwoChineseChar(102,144,51,9,24,WHITE);

                                    if(chan_dev.week&0x01)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_2424_String(200,144,"  SUN  ",RED);
                                            else
                                                {
                                                    ShowTwoChineseChar(206,144,51,9,24,RED);
                                                    ShowChineseChar(254,144,8,24,RED);
                                                }
                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_2424_String(200,144,"  SUN  ",BLACK);
                                            else
                                                {
                                                    ShowTwoChineseChar(206,144,51,9,24,BLACK);
                                                    ShowChineseChar(254,144,8,24,BLACK);
                                                }
                                        }
                                    flag_dev.WeekAnchor=0x01;

                                }
                            *SubAnchor=0x03;//DATE
                            break;
                        case 0x05:
                            if(chan_dev.mode==ONCE)
                                {

                                    gui_draw_arcrectangle(95,141,225,30,1,1,RED,RED);
                                    gui_draw_arcrectangle(160,144,158,24,1,1,WHITE,WHITE);
                                    if(flag_dev.langage==1)
                                        LCD_Show_2424_String(95,144,"DATE",WHITE);
                                    else
                                        ShowTwoChineseChar(102,144,8,9,24,WHITE);

                                    LCD_Show_2424_String(180,144,"    -  -  ",BLACK);
                                    LCD_ShowNum(180,144,chan_dev.date_year,4,24,BLACK,WHITE);
                                    LCD_ShowNum(240,144,chan_dev.date_month,2,24,BLACK,WHITE);
                                    LCD_ShowNum(276,144,chan_dev.date_day,2,24,BLACK,WHITE);



                                }
                            else  if(chan_dev.mode==LOOP)
                                {
                                    gui_draw_arcrectangle(95,141,225,30,1,1,RED,RED);
                                    gui_draw_arcrectangle(160,144,158,24,1,1,WHITE,WHITE);
                                    LCD_DrawLtrigo(160,144,185,169,LEFT,BLUE);
                                    LCD_DrawLtrigo(292,144,317,169,RIGHT,BLUE);
                                    if(flag_dev.langage==1)
                                        LCD_Show_2424_String(95,144,"WEEK",WHITE);
                                    else
                                        ShowTwoChineseChar(102,144,51,9,24,WHITE);

                                    if(chan_dev.week&0x01)
                                        {
                                            if(flag_dev.langage==1)
                                                {
                                                    LCD_Show_2424_String(200,144,"  SUN  ",RED);
                                                }
                                            else
                                                {
                                                    ShowTwoChineseChar(206,144,51,9,24,RED);
                                                    ShowChineseChar(254,144,8,24,RED);
                                                }
                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                {
                                                    LCD_Show_2424_String(200,144,"  SUN  ",BLACK);
                                                }
                                            else
                                                {
                                                    ShowTwoChineseChar(206,144,51,9,24,BLACK);
                                                    ShowChineseChar(254,144,8,24,BLACK);
                                                }
                                        }
                                    flag_dev.WeekAnchor=0x01;

                                }
                            gui_draw_arcrectangle(95,173,225,32,1,1,BLUE,BLUE);
                            gui_draw_arcrectangle(160,176,158,24,1,1,WHITE,WHITE);
                            if(flag_dev.langage==1)
                                LCD_Show_2424_String(95,176,"TIME",WHITE);
                            else
                                ShowTwoChineseChar(102,176,3,16,24,WHITE);

                            LCD_Show_2424_String(180,176,"  :  :  ",BLACK);
                            LCD_ShowNum(180,176,chan_dev.time_hour,2,24,BLACK,WHITE);
                            LCD_ShowNum(216,176,chan_dev.time_min,2,24,BLACK,WHITE);
                            LCD_ShowNum(252,176,chan_dev.time_sec,2,24,BLACK,WHITE);
                            *SubAnchor=0x04;//TIME
                            break;
                        case 0x06:
                            gui_draw_arcrectangle(95,173,225,32,1,1,RED,RED);
                            gui_draw_arcrectangle(160,176,158,24,1,1,WHITE,WHITE);
                            if(flag_dev.langage==1)
                                LCD_Show_2424_String(95,176,"TIME",WHITE);
                            else
                                ShowTwoChineseChar(102,176,3,16,24,WHITE);
                            LCD_Show_2424_String(180,176,"  :  :  ",BLACK);
                            LCD_ShowNum(180,176,chan_dev.time_hour,2,24,BLACK,WHITE);
                            LCD_ShowNum(216,176,chan_dev.time_min,2,24,BLACK,WHITE);
                            LCD_ShowNum(252,176,chan_dev.time_sec,2,24,BLACK,WHITE);

                            gui_draw_arcrectangle(120,210,80,30,1,1,BLUE,BLUE);
                            gui_draw_arcrectangle(125,212,70,28,1,1,WHITE,WHITE);
                            if(flag_dev.langage==1)
                                LCD_Show_3030_String(130,210,"SAVE",BLACK);
                            else
                                ShowTwoChineseChar(135,213,10,11,24,BLACK);
                            *SubAnchor=0x05;//SAVE
                            break;
                        case 0x07:
                            gui_draw_arcrectangle(120,210,80,30,1,1,BLUE,BLUE);
                            gui_draw_arcrectangle(125,212,70,28,1,1,RED,RED);
                            if(flag_dev.langage==1)
                                LCD_Show_3030_String(130,210,"SAVE",WHITE);
                            else
                                ShowTwoChineseChar(135,213,10,11,24,WHITE);
                            LCD_DrawLtrigo(230,215,255,240,LEFT,WHITE);
                            LCD_Show_picture(250,210,WHITE,0);
                            *SubAnchor=0x06;//LEFT
                            break;
                        case 0x08:
                            LCD_DrawLtrigo(230,215,255,240,LEFT,RED);
                            LCD_Show_picture(250,210,WHITE,0);
                            LCD_DrawLtrigo(282,215,307,240,RIGHT,WHITE);
                            *SubAnchor=0x07;
                            break;
                        case 0x09:
                            LCD_DrawLtrigo(230,215,255,240,LEFT,WHITE);
                            LCD_Show_picture(250,210,RED,0);
                            LCD_DrawLtrigo(282,215,307,240,RIGHT,WHITE);
                            *SubAnchor=0x08;
                            break;
                        }

                }
            if(flag_dev.action_flag==TIMER&&encoder_dev.EN_KEY==EN_KEY_DOWN)
                {

                    switch(*SubAnchor)
                        {
                        case 0x01:
                            if(chan_dev.timer_state==PROHIBIT)
                                {
                                    LCD_Fill(180,48,300,71,WHITE);
                                    if(flag_dev.langage==1)
                                        LCD_Show_2424_String(218, 48, "OPEN",BLACK);
                                    else
                                        {
                                            ShowTwoChineseChar(206,48,0,1,24,BLACK);
                                            ShowChineseChar(254,48,5,24,BLACK);
                                        }
                                    chan_dev.timer_state=CHAN_OPEN;
                                }
                            else if(chan_dev.timer_state==CHAN_OPEN)
                                {
                                    LCD_Fill(180,48,300,71,WHITE);
                                    if(flag_dev.langage==1)
                                        LCD_Show_2424_String(212, 48,"CLOSE",BLACK);
                                    else
                                        {
                                            ShowTwoChineseChar(206,48,0,1,24,BLACK);
                                            ShowChineseChar(254,48,6,24,BLACK);
                                        }
                                    chan_dev.timer_state=CHAN_CLOSE;
                                }
                            else if(chan_dev.timer_state==CHAN_CLOSE)
                                {
                                    LCD_Fill(180,48,300,71,WHITE);
                                    if(flag_dev.langage==1)
                                        LCD_Show_2424_String(225, 48,"OFF",BLACK);
                                    else
                                        ShowChineseChar(230,48,6,24,BLACK);
                                    chan_dev.timer_state=PROHIBIT;
                                }
                            break;
                        case 0x02:
                            ItemAnchor=1;
                            break;
                        case 0x03:
                            if(chan_dev.mode==LOOP)
                                {
                                    LCD_Fill(180,112,300,135,WHITE);
                                    if(flag_dev.langage==1)
                                        LCD_Show_2424_String(220,112,"ONCE",BLACK);
                                    else
                                        ShowTwoChineseChar(217,112,54,44,24,BLACK);
                                    chan_dev.mode=ONCE;

                                    gui_draw_arcrectangle(95,141,225,30,1,1,BLUE,BLUE);
                                    gui_draw_arcrectangle(160,144,158,24,1,1,WHITE,WHITE);
                                    if(flag_dev.langage==1)
                                        LCD_Show_2424_String(95,144,"DATE",WHITE);
                                    else
                                        ShowTwoChineseChar(102,144,8,9,24,WHITE);

                                    LCD_Show_2424_String(180,144,"    -  -  ",BLACK);
                                    LCD_ShowNum(180,144,chan_dev.date_year,4,24,BLACK,WHITE);
                                    LCD_ShowNum(240,144,chan_dev.date_month,2,24,BLACK,WHITE);
                                    LCD_ShowNum(276,144,chan_dev.date_day,2,24,BLACK,WHITE);



                                }
                            else if(chan_dev.mode==ONCE)
                                {
                                    LCD_Fill(180,112,300,135,WHITE);
                                    if(flag_dev.langage==1)
                                        LCD_Show_2424_String(220,112,"LOOP",BLACK);
                                    else
                                        ShowTwoChineseChar(217,112,52,53,24,BLACK);
                                    chan_dev.mode=LOOP;

                                    gui_draw_arcrectangle(95,141,225,30,1,1,BLUE,BLUE);
                                    gui_draw_arcrectangle(160,144,158,24,1,1,WHITE,WHITE);
                                    LCD_DrawLtrigo(160,144,185,169,LEFT,BLUE);
                                    LCD_DrawLtrigo(292,144,317,169,RIGHT,BLUE);
                                    if(flag_dev.langage==1)
                                        LCD_Show_2424_String(95,144,"WEEK",WHITE);
                                    else
                                        ShowTwoChineseChar(102,144,51,9,24,WHITE);

                                    //	  LCD_Show_2424_String(200,144,"SUN MON",BLACK);
                                    //		LCD_Show_2424_String(200,144,"TUE WED",BLACK);
                                    //	  LCD_Show_2424_String(200,144,"THU FRI",BLACK);
                                    if(chan_dev.week&0x01)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_2424_String(200,144,"  SUN  ",RED);
                                            else
                                                {
                                                    ShowTwoChineseChar(206,144,51,9,24,RED);
                                                    ShowChineseChar(254,144,8,24,RED);
                                                }
                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_2424_String(200,144,"  SUN  ",BLACK);
                                            else
                                                {
                                                    ShowTwoChineseChar(206,144,51,9,24,BLACK);
                                                    ShowChineseChar(254,144,8,24,BLACK);
                                                }
                                        }
                                    flag_dev.WeekAnchor=0x01;

                                    flag_dev.anchor=0;

                                }
                            break;
                        case 0x04:
                            if(chan_dev.mode==ONCE)
                                ItemAnchor=2;
                            if(chan_dev.mode==LOOP)
                                ItemAnchor=3;
                            break;
                        case 0x05:
                            ItemAnchor=4;
                            break;
                        case 0x06:
                            switch(flag_dev.activity_num)
                                {

                                case ISTIMER1:
                                    timer_dev_1=chan_dev;
                                    break;
                                case ISTIMER2:
                                    timer_dev_2=chan_dev;
                                    break;
                                case ISTIMER3:
                                    timer_dev_3=chan_dev;
                                    break;
                                case ISTIMER4:
                                    timer_dev_4=chan_dev;
                                    break;
                                case ISTIMER5:
                                    timer_dev_5=chan_dev;
                                    break;
                                case ISTIMER6:
                                    timer_dev_6=chan_dev;
                                    break;
                                case ISTIMER7:
                                    timer_dev_7=chan_dev;
                                    break;
                                case ISTIMER8:
                                    timer_dev_8=chan_dev;
                                    break;
                                case ISTIMER9:
                                    timer_dev_9=chan_dev;
                                    break;
                                case ISTIMER10:
                                    timer_dev_10=chan_dev;
                                    break;
                                }
                            ReadAndSave(ISTIMER,1);
                            break;
                        case 0x07:
                            switch(flag_dev.activity_num)
                                {
                                case ISTIMER1:
                                    LCD_Fill(170,0,280,35,RED);
                                    if(flag_dev.langage==1)
                                        LCD_Show_3030_String(170,5,"TIMER10",WHITE);
                                    else
                                        {
                                            ShowTwoChineseChar(185,11,12,13,24,WHITE);
                                            LCD_Show_2424_String(233,12,"10",WHITE);
                                        }
                                    flag_dev.activity_num=10;
                                    chan_dev=timer_dev_10;
                                    break;
                                case ISTIMER10:
                                    LCD_Fill(170,0,280,35,RED);
                                    if(flag_dev.langage==1)
                                        LCD_Show_3030_String(170,5,"TIMER9",WHITE);
                                    else
                                        {
                                            ShowTwoChineseChar(185,11,12,13,24,WHITE);
                                            LCD_Show_2424_String(233,12,"9",WHITE);
                                        }
                                    flag_dev.activity_num=9;
                                    chan_dev=timer_dev_9;
                                    break;
                                case ISTIMER9:
                                    LCD_Fill(170,0,280,35,RED);
                                    if(flag_dev.langage==1)
                                        LCD_Show_3030_String(170,5,"TIMER8",WHITE);
                                    else
                                        {
                                            ShowTwoChineseChar(185,11,12,13,24,WHITE);
                                            LCD_Show_2424_String(233,12,"8",WHITE);
                                        }
                                    flag_dev.activity_num=8;
                                    chan_dev=timer_dev_8;
                                    break;
                                case ISTIMER8:
                                    LCD_Fill(170,0,280,35,RED);
                                    if(flag_dev.langage==1)
                                        LCD_Show_3030_String(170,5,"TIMER7",WHITE);
                                    else
                                        {
                                            ShowTwoChineseChar(185,11,12,13,24,WHITE);
                                            LCD_Show_2424_String(233,12,"7",WHITE);
                                        }
                                    flag_dev.activity_num=7;
                                    chan_dev=timer_dev_7;
                                    break;
                                case ISTIMER7:
                                    LCD_Fill(170,0,280,35,RED);
                                    if(flag_dev.langage==1)
                                        LCD_Show_3030_String(170,5,"TIMER6",WHITE);
                                    else
                                        {
                                            ShowTwoChineseChar(185,11,12,13,24,WHITE);
                                            LCD_Show_2424_String(233,12,"6",WHITE);
                                        }
                                    flag_dev.activity_num=6;
                                    chan_dev=timer_dev_6;
                                    break;
                                case ISTIMER6:
                                    LCD_Fill(170,0,280,35,RED);
                                    if(flag_dev.langage==1)
                                        LCD_Show_3030_String(170,5,"TIMER5",WHITE);
                                    else
                                        {
                                            ShowTwoChineseChar(185,11,12,13,24,WHITE);
                                            LCD_Show_2424_String(233,12,"5",WHITE);
                                        }
                                    flag_dev.activity_num=5;
                                    chan_dev=timer_dev_5;
                                    break;
                                case ISTIMER5:
                                    LCD_Fill(170,0,280,35,RED);
                                    if(flag_dev.langage==1)
                                        LCD_Show_3030_String(170,5,"TIMER4",WHITE);
                                    else
                                        {
                                            ShowTwoChineseChar(185,11,12,13,24,WHITE);
                                            LCD_Show_2424_String(233,12,"4",WHITE);
                                        }
                                    flag_dev.activity_num=4;
                                    chan_dev=timer_dev_4;
                                    break;
                                case ISTIMER4:
                                    LCD_Fill(170,0,280,35,RED);
                                    if(flag_dev.langage==1)
                                        LCD_Show_3030_String(170,5,"TIMER3",WHITE);
                                    else
                                        {
                                            ShowTwoChineseChar(185,11,12,13,24,WHITE);
                                            LCD_Show_2424_String(233,12,"3",WHITE);
                                        }
                                    flag_dev.activity_num=3;
                                    chan_dev=timer_dev_3;
                                    break;
                                case ISTIMER3:
                                    LCD_Fill(170,0,280,35,RED);
                                    if(flag_dev.langage==1)
                                        LCD_Show_3030_String(170,5,"TIMER2",WHITE);
                                    else
                                        {
                                            ShowTwoChineseChar(185,11,12,13,24,WHITE);
                                            LCD_Show_2424_String(233,12,"2",WHITE);
                                        }
                                    flag_dev.activity_num=2;
                                    chan_dev=timer_dev_2;
                                    break;
                                case ISTIMER2:
                                    LCD_Fill(170,0,280,35,RED);
                                    if(flag_dev.langage==1)
                                        LCD_Show_3030_String(170,5,"TIMER1",WHITE);
                                    else
                                        {
                                            ShowTwoChineseChar(185,11,12,13,24,WHITE);
                                            LCD_Show_2424_String(233,12,"1",WHITE);
                                        }
                                    flag_dev.activity_num=1;
                                    chan_dev=timer_dev_1;
                                    break;
                                }
                            timer_data_flash();
                            break;
                        case 0x08:
                            flag_dev.TOSUBPAGE=0;
                            *SubAnchor=0;
                            LCD_Show_picture(250,210,WHITE,0);
                            break;
                        case 0x09:
                            switch(flag_dev.activity_num)
                                {
                                case ISTIMER10:
                                    LCD_Fill(170,0,280,35,RED);
                                    if(flag_dev.langage==1)
                                        LCD_Show_3030_String(170,5,"TIMER1",WHITE);
                                    else
                                        {
                                            ShowTwoChineseChar(185,11,12,13,24,WHITE);
                                            LCD_Show_2424_String(233,12,"1",WHITE);
                                        }
                                    flag_dev.activity_num=1;
                                    chan_dev=timer_dev_1;
                                    break;
                                case ISTIMER1:
                                    LCD_Fill(170,0,280,35,RED);
                                    if(flag_dev.langage==1)
                                        LCD_Show_3030_String(170,5,"TIMER2",WHITE);
                                    else
                                        {
                                            ShowTwoChineseChar(185,11,12,13,24,WHITE);
                                            LCD_Show_2424_String(233,12,"2",WHITE);
                                        }
                                    flag_dev.activity_num=2;
                                    chan_dev=timer_dev_2;
                                    break;
                                case ISTIMER2:
                                    LCD_Fill(170,0,280,35,RED);
                                    if(flag_dev.langage==1)
                                        LCD_Show_3030_String(170,5,"TIMER3",WHITE);
                                    else
                                        {
                                            ShowTwoChineseChar(185,11,12,13,24,WHITE);
                                            LCD_Show_2424_String(233,12,"3",WHITE);
                                        }
                                    flag_dev.activity_num=3;
                                    chan_dev=timer_dev_3;
                                    break;
                                case ISTIMER3:
                                    LCD_Fill(170,0,280,35,RED);
                                    if(flag_dev.langage==1)
                                        LCD_Show_3030_String(170,5,"TIMER4",WHITE);
                                    else
                                        {
                                            ShowTwoChineseChar(185,11,12,13,24,WHITE);
                                            LCD_Show_2424_String(233,12,"4",WHITE);
                                        }
                                    flag_dev.activity_num=4;
                                    chan_dev=timer_dev_4;
                                    break;
                                case ISTIMER4:
                                    LCD_Fill(170,0,280,35,RED);
                                    if(flag_dev.langage==1)
                                        LCD_Show_3030_String(170,5,"TIMER5",WHITE);
                                    else
                                        {
                                            ShowTwoChineseChar(185,11,12,13,24,WHITE);
                                            LCD_Show_2424_String(233,12,"5",WHITE);
                                        }
                                    flag_dev.activity_num=5;
                                    chan_dev=timer_dev_5;
                                    break;
                                case ISTIMER5:
                                    LCD_Fill(170,0,280,35,RED);
                                    if(flag_dev.langage==1)
                                        LCD_Show_3030_String(170,5,"TIMER6",WHITE);
                                    else
                                        {
                                            ShowTwoChineseChar(185,11,12,13,24,WHITE);
                                            LCD_Show_2424_String(233,12,"6",WHITE);
                                        }
                                    flag_dev.activity_num=6;
                                    chan_dev=timer_dev_6;
                                    break;
                                case ISTIMER6:
                                    LCD_Fill(170,0,280,35,RED);
                                    if(flag_dev.langage==1)
                                        LCD_Show_3030_String(170,5,"TIMER7",WHITE);
                                    else
                                        {
                                            ShowTwoChineseChar(185,11,12,13,24,WHITE);
                                            LCD_Show_2424_String(233,12,"7",WHITE);
                                        }
                                    flag_dev.activity_num=7;
                                    chan_dev=timer_dev_7;
                                    break;
                                case ISTIMER7:
                                    LCD_Fill(170,0,280,35,RED);
                                    if(flag_dev.langage==1)
                                        LCD_Show_3030_String(170,5,"TIMER8",WHITE);
                                    else
                                        {
                                            ShowTwoChineseChar(185,11,12,13,24,WHITE);
                                            LCD_Show_2424_String(233,12,"8",WHITE);
                                        }
                                    flag_dev.activity_num=8;
                                    chan_dev=timer_dev_8;
                                    break;
                                case ISTIMER8:
                                    LCD_Fill(170,0,280,35,RED);
                                    if(flag_dev.langage==1)
                                        LCD_Show_3030_String(170,5,"TIMER9",WHITE);
                                    else
                                        {
                                            ShowTwoChineseChar(185,11,12,13,24,WHITE);
                                            LCD_Show_2424_String(233,12,"9",WHITE);
                                        }
                                    flag_dev.activity_num=9;
                                    chan_dev=timer_dev_9;
                                    break;
                                case ISTIMER9:
                                    LCD_Fill(170,0,280,35,RED);
                                    if(flag_dev.langage==1)
                                        LCD_Show_3030_String(170,5,"TIMER10",WHITE);
                                    else
                                        {
                                            ShowTwoChineseChar(185,11,12,13,24,WHITE);
                                            LCD_Show_2424_String(233,12,"10",WHITE);
                                        }
                                    flag_dev.activity_num=10;
                                    chan_dev=timer_dev_10;
                                    break;
                                }
                            timer_data_flash();
                            break;

                        }

                }

        }


}
void EncoderTimerSub()
{

    if(flag_dev.action_flag==TIMER&&ItemAnchor!=0)
        {


            if(ItemAnchor==1)
                {

                    if(encoder_dev.EN_STATE==SUBRIGHT)
                        {

                            switch(ItemElementAnchor)
                                {
                                case 0x00:
                                    LCD_Show_2424_String(165,80,"1",0x07E0);
                                    ItemElementAnchor=0x01;
                                    break;
                                case 0x01:
                                    if(chan_dev.chan1)
                                        {
                                            LCD_Show_2424_String(165,80,"1",RED);
                                        }
                                    else
                                        {
                                            LCD_Show_2424_String(165,80,"1",BLACK);
                                        }
                                    LCD_Show_2424_String(185,80,"2",0x07E0);
                                    ItemElementAnchor=0x02;
                                    break;
                                case 0x02:
                                    if(chan_dev.chan2)
                                        {
                                            LCD_Show_2424_String(185,80,"2",RED);
                                        }
                                    else
                                        {
                                            LCD_Show_2424_String(185,80,"2",BLACK);
                                        }
                                    LCD_Show_2424_String(205,80,"3",0x07E0);
                                    ItemElementAnchor=0x03;
                                    break;
                                case 0x03:
                                    if(chan_dev.chan3)
                                        {
                                            LCD_Show_2424_String(205,80,"3",RED);
                                        }
                                    else
                                        {
                                            LCD_Show_2424_String(205,80,"3",BLACK);
                                        }
                                    LCD_Show_2424_String(225,80,"4",0x07E0);
                                    ItemElementAnchor=0x04;
                                    break;
                                case 0x04:
                                    if(chan_dev.chan4)
                                        {
                                            LCD_Show_2424_String(225,80,"4",RED);
                                        }
                                    else
                                        {
                                            LCD_Show_2424_String(225,80,"4",BLACK);
                                        }
                                    LCD_Show_2424_String(245,80,"5",0x07E0);
                                    ItemElementAnchor=0x05;
                                    break;
                                case 0x05:
                                    if(chan_dev.chan5)
                                        {
                                            LCD_Show_2424_String(245,80,"5",RED);
                                        }
                                    else
                                        {
                                            LCD_Show_2424_String(245,80,"5",BLACK);
                                        }
                                    LCD_Show_2424_String(265,80,"6",0x07E0);
                                    ItemElementAnchor=0x06;
                                    break;
                                case 0x06:
                                    if(chan_dev.chan6)
                                        {
                                            LCD_Show_2424_String(265,80,"6",RED);
                                        }
                                    else
                                        {
                                            LCD_Show_2424_String(265,80,"6",BLACK);
                                        }
                                    LCD_Show_2424_String(285,80,"7",0x07E0);
                                    ItemElementAnchor=0x07;
                                    break;
                                case 0x07:
                                    if(chan_dev.chan7)
                                        {
                                            LCD_Show_2424_String(285,80,"7",RED);
                                        }
                                    else
                                        {
                                            LCD_Show_2424_String(285,80,"7",BLACK);
                                        }
                                    LCD_Show_2424_String(305,80,"8",0x07E0);
                                    ItemElementAnchor=0x08;
                                    break;
                                case 0x08:
                                    if(chan_dev.chan8)
                                        {
                                            LCD_Show_2424_String(305,80,"8",RED);
                                        }
                                    else
                                        {
                                            LCD_Show_2424_String(305,80,"8",BLACK);
                                        }
                                    ItemAnchor=0;
                                    ItemElementAnchor=0;
                                    break;
                                }
                        }
                    else if(encoder_dev.EN_STATE==SUBLEFT)
                        {

                            switch(ItemElementAnchor)
                                {
                                case 0x01:
                                    if(chan_dev.chan1)
                                        {
                                            LCD_Show_2424_String(165,80,"1",RED);
                                        }
                                    else
                                        {
                                            LCD_Show_2424_String(165,80,"1",BLACK);
                                        }
                                    ItemAnchor=0;
                                    ItemElementAnchor=0;
                                    break;
                                case 0x02:
                                    if(chan_dev.chan2)
                                        {
                                            LCD_Show_2424_String(185,80,"2",RED);
                                        }
                                    else
                                        {
                                            LCD_Show_2424_String(185,80,"2",BLACK);
                                        }
                                    LCD_Show_2424_String(165,80,"1",0x07E0);
                                    ItemElementAnchor=0x01;
                                    break;
                                case 0x03:
                                    if(chan_dev.chan3)
                                        {
                                            LCD_Show_2424_String(205,80,"3",RED);
                                        }
                                    else
                                        {
                                            LCD_Show_2424_String(205,80,"3",BLACK);
                                        }
                                    LCD_Show_2424_String(185,80,"2",0x07E0);
                                    ItemElementAnchor=0x02;
                                    break;
                                case 0x04:
                                    if(chan_dev.chan4)
                                        {
                                            LCD_Show_2424_String(225,80,"4",RED);
                                        }
                                    else
                                        {
                                            LCD_Show_2424_String(225,80,"4",BLACK);
                                        }
                                    LCD_Show_2424_String(205,80,"3",0x07E0);
                                    ItemElementAnchor=0x03;
                                    break;
                                case 0x05:
                                    if(chan_dev.chan5)
                                        {
                                            LCD_Show_2424_String(245,80,"5",RED);
                                        }
                                    else
                                        {
                                            LCD_Show_2424_String(245,80,"5",BLACK);
                                        }
                                    LCD_Show_2424_String(225,80,"4",0x07E0);
                                    ItemElementAnchor=0x04;
                                    break;
                                case 0x06:
                                    if(chan_dev.chan6)
                                        {
                                            LCD_Show_2424_String(265,80,"6",RED);
                                        }
                                    else
                                        {
                                            LCD_Show_2424_String(265,80,"6",BLACK);
                                        }
                                    LCD_Show_2424_String(245,80,"5",0x07E0);
                                    ItemElementAnchor=0x05;
                                    break;
                                case 0x07:
                                    if(chan_dev.chan7)
                                        {
                                            LCD_Show_2424_String(285,80,"7",RED);
                                        }
                                    else
                                        {
                                            LCD_Show_2424_String(285,80,"7",BLACK);
                                        }
                                    LCD_Show_2424_String(265,80,"6",0x07E0);
                                    ItemElementAnchor=0x06;
                                    break;
                                case 0x08:
                                    if(chan_dev.chan8)
                                        {
                                            LCD_Show_2424_String(305,80,"8",RED);
                                        }
                                    else
                                        {
                                            LCD_Show_2424_String(305,80,"8",BLACK);
                                        }
                                    LCD_Show_2424_String(285,80,"7",0x07E0);
                                    ItemElementAnchor=0x07;
                                    break;
                                }


                        }


                }
            if(ItemAnchor==2)
                {
                    if(encoder_dev.EN_STATE==SUBRIGHT)
                        {

                            switch(ItemElementAnchor)
                                {
                                case 0x00:
                                    LCD_ShowNum(180,144,chan_dev.date_year,4,24,RED,WHITE);
                                    LCD_ShowNum(240,144,chan_dev.date_month,2,24,BLACK,WHITE);
                                    LCD_ShowNum(276,144,chan_dev.date_day,2,24,BLACK,WHITE);
                                    ItemElementAnchor=0x01;
                                    break;
                                case 0x01:
                                    LCD_ShowNum(180,144,chan_dev.date_year,4,24,BLACK,WHITE);
                                    LCD_ShowNum(240,144,chan_dev.date_month,2,24,RED,WHITE);
                                    LCD_ShowNum(276,144,chan_dev.date_day,2,24,BLACK,WHITE);
                                    ItemElementAnchor=0x02;
                                    break;
                                case 0x02:
                                    LCD_ShowNum(180,144,chan_dev.date_year,4,24,BLACK,WHITE);
                                    LCD_ShowNum(240,144,chan_dev.date_month,2,24,BLACK,WHITE);
                                    LCD_ShowNum(276,144,chan_dev.date_day,2,24,RED,WHITE);
                                    ItemElementAnchor=0x03;
                                    break;
                                case 0x03:
                                    LCD_ShowNum(180,144,chan_dev.date_year,4,24,BLACK,WHITE);
                                    LCD_ShowNum(240,144,chan_dev.date_month,2,24,BLACK,WHITE);
                                    LCD_ShowNum(276,144,chan_dev.date_day,2,24,BLACK,WHITE);
                                    ItemAnchor=0;
                                    ItemElementAnchor=0;
                                    break;

                                }

                        }
                    else if(encoder_dev.EN_STATE==SUBLEFT)
                        {

                            switch(ItemElementAnchor)
                                {
                                case 0x01:
                                    LCD_ShowNum(180,144,chan_dev.date_year,4,24,BLACK,WHITE);
                                    LCD_ShowNum(240,144,chan_dev.date_month,2,24,BLACK,WHITE);
                                    LCD_ShowNum(276,144,chan_dev.date_day,2,24,BLACK,WHITE);
                                    ItemAnchor=0;
                                    ItemElementAnchor=0;
                                    break;
                                case 0x02:
                                    LCD_ShowNum(180,144,chan_dev.date_year,4,24,RED,WHITE);
                                    LCD_ShowNum(240,144,chan_dev.date_month,2,24,BLACK,WHITE);
                                    LCD_ShowNum(276,144,chan_dev.date_day,2,24,BLACK,WHITE);
                                    ItemElementAnchor=0x01;
                                    break;
                                case 0x03:
                                    LCD_ShowNum(180,144,chan_dev.date_year,4,24,BLACK,WHITE);
                                    LCD_ShowNum(240,144,chan_dev.date_month,2,24,RED,WHITE);
                                    LCD_ShowNum(276,144,chan_dev.date_day,2,24,BLACK,WHITE);
                                    ItemElementAnchor=0x02;
                                    break;
                                }
                        }
                }
            if(ItemAnchor==3)
                {
                    if(encoder_dev.EN_STATE==SUBRIGHT)
                        {
                            switch(ItemElementAnchor)
                                {
                                case 0x00:
                                    ItemElementAnchor=0x01;
                                    gui_draw_arcrectangle(198,144,85,24,1,1,WHITE,WHITE);
                                    if(chan_dev.week&0x01)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_2424_String(200,144,"  SUN  ",RED);
                                            else
                                                {
                                                    ShowTwoChineseChar(206,144,51,9,24,RED);
                                                    ShowChineseChar(254,144,8,24,RED);
                                                }
                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_2424_String(200,144,"  SUN  ",BLACK);
                                            else
                                                {
                                                    ShowTwoChineseChar(206,144,51,9,24,BLACK);
                                                    ShowChineseChar(254,144,8,24,BLACK);
                                                }
                                        }
                                    break;
                                case 0x01:
                                    gui_draw_arcrectangle(198,144,85,24,1,1,WHITE,WHITE);
                                    if(chan_dev.week&0x02)
                                        {
                                            if(flag_dev.langage==1)
                                                {
                                                    LCD_Show_2424_String(200,144,"  MON  ",RED);
                                                }
                                            else
                                                {
                                                    ShowTwoChineseChar(206,144,51,9,24,RED);
                                                    ShowChineseChar(254,144,65,24,RED);
                                                }
                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_2424_String(200,144,"  MON  ",BLACK);
                                            else
                                                {
                                                    ShowTwoChineseChar(206,144,51,9,24,BLACK);
                                                    ShowChineseChar(254,144,65,24,BLACK);
                                                }
                                        }
                                    ItemElementAnchor=0x02;
                                    break;
                                case 0x02:
                                    gui_draw_arcrectangle(198,144,85,24,1,1,WHITE,WHITE);
                                    if(chan_dev.week&0x04)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_2424_String(200,144,"  TUE  ",RED);
                                            else
                                                {
                                                    ShowTwoChineseChar(206,144,51,9,24,RED);
                                                    ShowChineseChar(254,144,66,24,RED);
                                                }
                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_2424_String(200,144,"  TUE  ",BLACK);
                                            else
                                                {
                                                    ShowTwoChineseChar(206,144,51,9,24,BLACK);
                                                    ShowChineseChar(254,144,66,24,BLACK);
                                                }
                                        }
                                    ItemElementAnchor=0x03;
                                    break;
                                case 0x03:
                                    gui_draw_arcrectangle(198,144,85,24,1,1,WHITE,WHITE);
                                    if(chan_dev.week&0x08)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_2424_String(200,144,"  WED  ",RED);
                                            else
                                                {
                                                    ShowTwoChineseChar(206,144,51,9,24,RED);
                                                    ShowChineseChar(254,144,67,24,RED);
                                                }
                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_2424_String(200,144,"  WED  ",BLACK);
                                            else
                                                {
                                                    ShowTwoChineseChar(206,144,51,9,24,BLACK);
                                                    ShowChineseChar(254,144,67,24,BLACK);
                                                }
                                        }
                                    ItemElementAnchor=0x04;
                                    break;
                                case 0x04:
                                    gui_draw_arcrectangle(198,144,85,24,1,1,WHITE,WHITE);
                                    if(chan_dev.week&0x10)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_2424_String(200,144,"  THU  ",RED);
                                            else
                                                {
                                                    ShowTwoChineseChar(206,144,51,9,24,RED);
                                                    ShowChineseChar(254,144,68,24,RED);
                                                }
                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_2424_String(200,144,"  THU  ",BLACK);
                                            else
                                                {
                                                    ShowTwoChineseChar(206,144,51,9,24,BLACK);
                                                    ShowChineseChar(254,144,68,24,BLACK);
                                                }
                                        }
                                    ItemElementAnchor=0x05;
                                    break;
                                case 0x05:
                                    gui_draw_arcrectangle(198,144,85,24,1,1,WHITE,WHITE);
                                    if(chan_dev.week&0x20)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_2424_String(200,144,"  FRI  ",RED);
                                            else
                                                {
                                                    ShowTwoChineseChar(206,144,51,9,24,RED);
                                                    ShowChineseChar(254,144,69,24,RED);
                                                }
                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_2424_String(200,144,"  FRI  ",BLACK);
                                            else
                                                {
                                                    ShowTwoChineseChar(206,144,51,9,24,BLACK);
                                                    ShowChineseChar(254,144,69,24,BLACK);
                                                }
                                        }
                                    ItemElementAnchor=0x06;
                                    break;
                                case 0x06:
                                    gui_draw_arcrectangle(198,144,85,24,1,1,WHITE,WHITE);
                                    if(chan_dev.week&0x40)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_2424_String(200,144,"  SAT  ",RED);
                                            else
                                                {
                                                    ShowTwoChineseChar(206,144,51,9,24,RED);
                                                    ShowChineseChar(254,144,70,24,RED);
                                                }
                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_2424_String(200,144,"  SAT  ",BLACK);
                                            else
                                                {
                                                    ShowTwoChineseChar(206,144,51,9,24,BLACK);
                                                    ShowChineseChar(254,144,70,24,BLACK);
                                                }
                                        }
                                    ItemElementAnchor=0x07;
                                    break;
                                case 0x07:
                                    ItemAnchor=0;
                                    ItemElementAnchor=0;
                                    break;
                                }
                        }
                    else if(encoder_dev.EN_STATE==SUBLEFT)
                        {
                            switch(ItemElementAnchor)
                                {
                                case 0x01:
                                    ItemAnchor=0;
                                    ItemElementAnchor=0;
                                    gui_draw_arcrectangle(198,144,85,24,1,1,WHITE,WHITE);
                                    if(chan_dev.week&0x01)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_2424_String(200,144,"  SUN  ",RED);
                                            else
                                                {
                                                    ShowTwoChineseChar(206,144,51,9,24,RED);
                                                    ShowChineseChar(254,144,8,24,RED);
                                                }
                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_2424_String(200,144,"  SUN  ",BLACK);
                                            else
                                                {
                                                    ShowTwoChineseChar(206,144,51,9,24,BLACK);
                                                    ShowChineseChar(254,144,8,24,BLACK);
                                                }
                                        }
                                    break;
                                case 0x02:
                                    gui_draw_arcrectangle(198,144,85,24,1,1,WHITE,WHITE);
                                    if(chan_dev.week&0x01)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_2424_String(200,144,"  SUN  ",RED);
                                            else
                                                {
                                                    ShowTwoChineseChar(206,144,51,9,24,RED);
                                                    ShowChineseChar(254,144,8,24,RED);
                                                }
                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_2424_String(200,144,"  SUN  ",BLACK);
                                            else
                                                {
                                                    ShowTwoChineseChar(206,144,51,9,24,BLACK);
                                                    ShowChineseChar(254,144,8,24,BLACK);
                                                }
                                        }
                                    ItemElementAnchor=0x01;
                                    break;
                                case 0x03:
                                    gui_draw_arcrectangle(198,144,85,24,1,1,WHITE,WHITE);
                                    if(chan_dev.week&0x02)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_2424_String(200,144,"  MON  ",RED);
                                            else
                                                {
                                                    ShowTwoChineseChar(206,144,51,9,24,RED);
                                                    ShowChineseChar(254,144,65,24,RED);
                                                }
                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_2424_String(200,144,"  MON  ",BLACK);
                                            else
                                                {
                                                    ShowTwoChineseChar(206,144,51,9,24,BLACK);
                                                    ShowChineseChar(254,144,65,24,BLACK);
                                                }
                                        }
                                    ItemElementAnchor=0x02;
                                    break;
                                case 0x04:
                                    gui_draw_arcrectangle(198,144,85,24,1,1,WHITE,WHITE);
                                    if(chan_dev.week&0x04)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_2424_String(200,144,"  TUE  ",RED);
                                            else
                                                {
                                                    ShowTwoChineseChar(206,144,51,9,24,RED);
                                                    ShowChineseChar(254,144,66,24,RED);
                                                }
                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_2424_String(200,144,"  TUE  ",BLACK);
                                            else
                                                {
                                                    ShowTwoChineseChar(206,144,51,9,24,BLACK);
                                                    ShowChineseChar(254,144,66,24,BLACK);
                                                }
                                        }

                                    ItemElementAnchor=0x03;
                                    break;
                                case 0x05:
                                    gui_draw_arcrectangle(198,144,85,24,1,1,WHITE,WHITE);
                                    if(chan_dev.week&0x08)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_2424_String(200,144,"  WED  ",RED);
                                            else
                                                {
                                                    ShowTwoChineseChar(206,144,51,9,24,RED);
                                                    ShowChineseChar(254,144,67,24,RED);
                                                }
                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_2424_String(200,144,"  WED  ",BLACK);
                                            else
                                                {
                                                    ShowTwoChineseChar(206,144,51,9,24,BLACK);
                                                    ShowChineseChar(254,144,67,24,BLACK);
                                                }
                                        }
                                    ItemElementAnchor=0x04;
                                    break;
                                case 0x06:
                                    gui_draw_arcrectangle(198,144,85,24,1,1,WHITE,WHITE);
                                    if(chan_dev.week&0x10)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_2424_String(200,144,"  THU  ",RED);
                                            else
                                                {
                                                    ShowTwoChineseChar(206,144,51,9,24,RED);
                                                    ShowChineseChar(254,144,68,24,RED);
                                                }
                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_2424_String(200,144,"  THU  ",BLACK);
                                            else
                                                {
                                                    ShowTwoChineseChar(206,144,51,9,24,BLACK);
                                                    ShowChineseChar(254,144,68,24,BLACK);
                                                }
                                        }
                                    ItemElementAnchor=0x05;
                                    break;
                                case 0x07:
                                    gui_draw_arcrectangle(198,144,85,24,1,1,WHITE,WHITE);
                                    if(chan_dev.week&0x20)
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_2424_String(200,144,"  FRI  ",RED);
                                            else
                                                {
                                                    ShowTwoChineseChar(206,144,51,9,24,RED);
                                                    ShowChineseChar(254,144,69,24,RED);
                                                }
                                        }
                                    else
                                        {
                                            if(flag_dev.langage==1)
                                                LCD_Show_2424_String(200,144,"  FRI  ",BLACK);
                                            else
                                                {
                                                    ShowTwoChineseChar(206,144,51,9,24,BLACK);
                                                    ShowChineseChar(254,144,69,24,BLACK);
                                                }
                                        }
                                    ItemElementAnchor=0x06;
                                    break;
                                }
                        }

                }


            if(ItemAnchor==4)
                {
                    if(encoder_dev.EN_STATE==SUBRIGHT)
                        {
                            switch(ItemElementAnchor)
                                {
                                case 0x00:
                                    LCD_ShowNum(180,176,chan_dev.time_hour,2,24,RED,WHITE);
                                    LCD_ShowNum(216,176,chan_dev.time_min,2,24,BLACK,WHITE);
                                    LCD_ShowNum(252,176,chan_dev.time_sec,2,24,BLACK,WHITE);
                                    ItemElementAnchor=1;
                                    break;
                                case 0x01:
                                    LCD_ShowNum(180,176,chan_dev.time_hour,2,24,BLACK,WHITE);
                                    LCD_ShowNum(216,176,chan_dev.time_min,2,24,RED,WHITE);
                                    LCD_ShowNum(252,176,chan_dev.time_sec,2,24,BLACK,WHITE);
                                    ItemElementAnchor=2;
                                    break;
                                case 0x02:
                                    LCD_ShowNum(180,176,chan_dev.time_hour,2,24,BLACK,WHITE);
                                    LCD_ShowNum(216,176,chan_dev.time_min,2,24,BLACK,WHITE);
                                    LCD_ShowNum(252,176,chan_dev.time_sec,2,24,RED,WHITE);
                                    ItemElementAnchor=3;
                                    break;
                                case 0x03:
                                    LCD_ShowNum(180,176,chan_dev.time_hour,2,24,BLACK,WHITE);
                                    LCD_ShowNum(216,176,chan_dev.time_min,2,24,BLACK,WHITE);
                                    LCD_ShowNum(252,176,chan_dev.time_sec,2,24,BLACK,WHITE);
                                    ItemAnchor=0;
                                    ItemElementAnchor=0;
                                    break;


                                }

                        }
                    else if(encoder_dev.EN_STATE==SUBLEFT)
                        {

                            switch(ItemElementAnchor)
                                {

                                case 0x01:
                                    LCD_ShowNum(180,176,chan_dev.time_hour,2,24,BLACK,WHITE);
                                    LCD_ShowNum(216,176,chan_dev.time_min,2,24,BLACK,WHITE);
                                    LCD_ShowNum(252,176,chan_dev.time_sec,2,24,BLACK,WHITE);
                                    ItemAnchor=0;
                                    ItemElementAnchor=0;
                                    break;
                                case 0x02:
                                    LCD_ShowNum(180,176,chan_dev.time_hour,2,24,RED,WHITE);
                                    LCD_ShowNum(216,176,chan_dev.time_min,2,24,BLACK,WHITE);
                                    LCD_ShowNum(252,176,chan_dev.time_sec,2,24,BLACK,WHITE);
                                    ItemElementAnchor=1;
                                    break;
                                case 0x03:
                                    LCD_ShowNum(180,176,chan_dev.time_hour,2,24,BLACK,WHITE);
                                    LCD_ShowNum(216,176,chan_dev.time_min,2,24,RED,WHITE);
                                    LCD_ShowNum(252,176,chan_dev.time_sec,2,24,BLACK,WHITE);
                                    ItemElementAnchor=2;
                                    break;
                                }

                        }

                }
            if(flag_dev.action_flag==TIMER&&ItemAnchor!=0&&encoder_dev.EN_KEY==EN_KEY_DOWN)
                {
                    if(ItemAnchor==1)
                        {
                            switch(ItemElementAnchor)
                                {
                                case 0x01:
                                    if(chan_dev.chan1)
                                        {
                                            chan_dev.chan1=0;
                                        }
                                    else
                                        {
                                            chan_dev.chan1=1;
                                            LCD_Show_2424_String(165,80,"1",RED);

                                        }
                                    break;
                                case 0x02:
                                    if(chan_dev.chan2)
                                        {
                                            chan_dev.chan2=0;
                                        }
                                    else
                                        {
                                            chan_dev.chan2=1;
                                            LCD_Show_2424_String(185,80,"2",RED);

                                        }
                                    break;
                                case 0x03:
                                    if(chan_dev.chan3)
                                        {
                                            chan_dev.chan3=0;
                                        }
                                    else
                                        {
                                            chan_dev.chan3=1;
                                            LCD_Show_2424_String(205,80,"3",RED);

                                        }
                                    break;
                                case 0x04:
                                    if(chan_dev.chan4)
                                        {
                                            chan_dev.chan4=0;
                                        }
                                    else
                                        {
                                            chan_dev.chan4=1;
                                            LCD_Show_2424_String(225,80,"4",RED);

                                        }
                                    break;
                                case 0x05:
                                    if(chan_dev.chan5)
                                        {
                                            chan_dev.chan5=0;
                                        }
                                    else
                                        {
                                            chan_dev.chan5=1;
                                            LCD_Show_2424_String(245,80,"5",RED);
                                        }
                                    break;
                                case 0x06:
                                    if(chan_dev.chan6)
                                        {
                                            chan_dev.chan6=0;
                                        }
                                    else
                                        {
                                            chan_dev.chan6=1;
                                            LCD_Show_2424_String(265,80,"6",RED);
                                        }
                                    break;
                                case 0x07:
                                    if(chan_dev.chan7)
                                        {
                                            chan_dev.chan7=0;

                                        }
                                    else
                                        {
                                            chan_dev.chan7=1;
                                            LCD_Show_2424_String(285,80,"7",RED);
                                        }
                                    break;
                                case 0x08:
                                    if(chan_dev.chan8)
                                        {
                                            chan_dev.chan8=0;

                                        }
                                    else
                                        {
                                            chan_dev.chan8=1;
                                            LCD_Show_2424_String(305,80,"8",RED);
                                        }
                                    break;

                                }

                        }
                    else if(ItemAnchor==3)
                        {
                            switch(ItemElementAnchor)
                                {

                                case 0x01:
                                    if(chan_dev.week&0x01)
                                        {
                                            chan_dev.week&=0x7E;
                                            if(flag_dev.langage==1)
                                                LCD_Show_2424_String(200,144,"  SUN  ",BLACK);
                                            else
                                                {
                                                    ShowTwoChineseChar(206,144,51,9,24,BLACK);
                                                    ShowChineseChar(254,144,8,24,BLACK);
                                                }
                                        }
                                    else
                                        {
                                            chan_dev.week|=0x01;
                                            if(flag_dev.langage==1)
                                                LCD_Show_2424_String(200,144,"  SUN  ",RED);
                                            else
                                                {
                                                    ShowTwoChineseChar(206,144,51,9,24,RED);
                                                    ShowChineseChar(254,144,8,24,RED);
                                                }
                                        }
                                    break;
                                case 0x02:
                                    if(chan_dev.week&0x02)
                                        {
                                            chan_dev.week&=0x7D;
                                            if(flag_dev.langage==1)
                                                LCD_Show_2424_String(200,144,"  MON  ",BLACK);
                                            else
                                                {
                                                    ShowTwoChineseChar(206,144,51,9,24,BLACK);
                                                    ShowChineseChar(254,144,65,24,BLACK);
                                                }
                                        }
                                    else
                                        {
                                            chan_dev.week|=0x02;
                                            if(flag_dev.langage==1)
                                                LCD_Show_2424_String(200,144,"  MON  ",RED);
                                            else
                                                {
                                                    ShowTwoChineseChar(206,144,51,9,24,RED);
                                                    ShowChineseChar(254,144,65,24,RED);
                                                }
                                        }
                                    break;
                                case 0x03:
                                    if(chan_dev.week&0x04)
                                        {
                                            chan_dev.week&=0x7B;
                                            if(flag_dev.langage==1)
                                                LCD_Show_2424_String(200,144,"  TUE  ",BLACK);
                                            else
                                                {
                                                    ShowTwoChineseChar(206,144,51,9,24,BLACK);
                                                    ShowChineseChar(254,144,66,24,BLACK);
                                                }
                                        }
                                    else
                                        {
                                            chan_dev.week|=0x04;
                                            if(flag_dev.langage==1)
                                                LCD_Show_2424_String(200,144,"  TUE  ",RED);
                                            else
                                                {
                                                    ShowTwoChineseChar(206,144,51,9,24,RED);
                                                    ShowChineseChar(254,144,66,24,RED);
                                                }
                                        }
                                    break;
                                case 0x04:
                                    if(chan_dev.week&0x08)
                                        {
                                            chan_dev.week&=0x77;
                                            if(flag_dev.langage==1)
                                                LCD_Show_2424_String(200,144,"  WED  ",BLACK);
                                            else
                                                {
                                                    ShowTwoChineseChar(206,144,51,9,24,BLACK);
                                                    ShowChineseChar(254,144,67,24,BLACK);
                                                }
                                        }
                                    else
                                        {
                                            chan_dev.week|=0x08;
                                            if(flag_dev.langage==1)
                                                LCD_Show_2424_String(200,144,"  WED  ",RED);
                                            else
                                                {
                                                    ShowTwoChineseChar(206,144,51,9,24,RED);
                                                    ShowChineseChar(254,144,67,24,RED);
                                                }
                                        }
                                    break;
                                case 0x05:
                                    if(chan_dev.week&0x10)
                                        {
                                            chan_dev.week&=0x6F;
                                            if(flag_dev.langage==1)
                                                LCD_Show_2424_String(200,144,"  THU  ",BLACK);
                                            else
                                                {
                                                    ShowTwoChineseChar(206,144,51,9,24,BLACK);
                                                    ShowChineseChar(254,144,68,24,BLACK);
                                                }
                                        }
                                    else
                                        {
                                            chan_dev.week|=0x10;
                                            if(flag_dev.langage==1)
                                                LCD_Show_2424_String(200,144,"  THU  ",RED);
                                            else
                                                {
                                                    ShowTwoChineseChar(206,144,51,9,24,RED);
                                                    ShowChineseChar(254,144,68,24,RED);
                                                }
                                        }
                                    break;
                                case 0x06:
                                    if(chan_dev.week&0x20)
                                        {
                                            chan_dev.week&=0x5F;
                                            if(flag_dev.langage==1)
                                                LCD_Show_2424_String(200,144,"  FRI  ",BLACK);
                                            else
                                                {
                                                    ShowTwoChineseChar(206,144,51,9,24,BLACK);
                                                    ShowChineseChar(254,144,69,24,BLACK);
                                                }
                                        }
                                    else
                                        {
                                            chan_dev.week|=0x20;
                                            if(flag_dev.langage==1)
                                                LCD_Show_2424_String(200,144,"  FRI  ",RED);
                                            else
                                                {
                                                    ShowTwoChineseChar(206,144,51,9,24,RED);
                                                    ShowChineseChar(254,144,69,24,RED);
                                                }
                                        }
                                    break;
                                case 0x07:
                                    if(chan_dev.week&0x40)
                                        {
                                            chan_dev.week&=0x3F;
                                            if(flag_dev.langage==1)
                                                LCD_Show_2424_String(200,144,"  SAT  ",BLACK);
                                            else
                                                {
                                                    ShowTwoChineseChar(206,144,51,9,24,BLACK);
                                                    ShowChineseChar(254,144,70,24,BLACK);
                                                }
                                        }
                                    else
                                        {
                                            chan_dev.week|=0x40;
                                            if(flag_dev.langage==1)
                                                LCD_Show_2424_String(200,144,"  SAT  ",RED);
                                            else
                                                {
                                                    ShowTwoChineseChar(206,144,51,9,24,RED);
                                                    ShowChineseChar(254,144,70,24,RED);
                                                }
                                        }
                                    break;

                                }



                        }
                    else if(ItemAnchor==2)
                        {

                            switch(ItemElementAnchor)
                                {
                                case 0x01:
                                    if(flag_dev.anchor!=0)
                                        flag_dev.anchor=0;
                                    else
                                        flag_dev.anchor=1;
                                    break;
                                case 0x02:
                                    if(flag_dev.anchor!=0)
                                        flag_dev.anchor=0;
                                    else
                                        flag_dev.anchor=2;
                                    break;
                                case 0x03:
                                    if(flag_dev.anchor!=0)
                                        flag_dev.anchor=0;
                                    else
                                        flag_dev.anchor=3;
                                    break;

                                }

                        }
                    else if(ItemAnchor==4)
                        {

                            switch(ItemElementAnchor)
                                {
                                case 0x01:
                                    if(flag_dev.anchor!=0)
                                        flag_dev.anchor=0;
                                    else
                                        flag_dev.anchor=4;
                                    break;
                                case 0x02:
                                    if(flag_dev.anchor!=0)
                                        flag_dev.anchor=0;
                                    else
                                        flag_dev.anchor=5;
                                    break;
                                case 0x03:
                                    if(flag_dev.anchor!=0)
                                        flag_dev.anchor=0;
                                    else
                                        flag_dev.anchor=6;
                                    break;

                                }
                        }

                }
        }



}