#include "main_page.h"
#include "gui.h"
#include "lcd.h"
#include "main_setting_page.h"
#include "flag.h"
#include "touch.h"
#include "delay.h"
#include "key.h"
extern _encoder_dev  encoder_dev;
extern  _m_tp_dev tp_dev;//触屏结构体
extern  _flag_dev flag_dev;


void main_page_activity()
{

    gui_draw_arcrectangle(0,0,319,40,1,1,RED,RED);

//     LCD_DrawLtrigo(95,0,125,40,LEFT,WHITE);
//     LCD_DrawLtrigo(290,0,319,40,RIGHT,WHITE);


    gui_draw_arcrectangle(2,43, 86,40,1,1, BLUE,BLUE);
    gui_draw_arcrectangle(2,84, 86,40,1,1, BLUE,BLUE);
    gui_draw_arcrectangle(2,125,86,40,1,1,BLUE,BLUE);
    gui_draw_arcrectangle(2,166,86,40,1,1,BLUE,BLUE);


    gui_draw_arcrectangle(0,210,319,30,1,1,BLUE,BLUE);
    LCD_Show_picture(250,210,WHITE,0);
    LCD_DrawLtrigo(230,215,255,240,LEFT,WHITE);
    LCD_DrawLtrigo(282,215,307,240,RIGHT,WHITE);

    LCD_DrawLtrigo(5,215,30,240,LEFT,WHITE);
    LCD_DrawLtrigo(57,215,82,240,RIGHT,WHITE);

    gui_draw_bline1(91,0,91,240,1,WHITE);

    LCD_Show_3030_String(22,212,"1/3",WHITE);
    LCD_Show_3030_String(20,5,"MENU",WHITE);

    LCD_Show_picture(25,47,WHITE,0);

    LCD_Show_3030_String(10,89,"DELAY",WHITE);
    LCD_Show_3030_String(1, 126,"SWUTCH",WHITE);
    LCD_Show_3030_String(15,168,"DATE",WHITE);


//       LCD_Show_3030_String(10,50,"Timer",WHITE);
//		   LCD_Show_3030_String(10, 89,"Reset",WHITE);
//       LCD_Show_3030_String(30,131,"IP",WHITE);
//		   LCD_Show_3030_String(10,170,"UV&OV",WHITE);

//        LCD_Show_3030_String(25,50,"PWD",WHITE);
//        LCD_Show_3030_String(25,89,"AUZ",WHITE);

//      reset_page_activity();

//		 timer_page_activity();

    main_setting_page_activity();



}

void main_page_action()
{
    if(flag_dev.lock_sta==L_OPEN)
        {
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
                            if(flag_dev.screen_flag!=AUZ)
                                {
                                    flag_dev.activity_flag=AUZ;
                                    flag_dev.action_flag=AUZ;
                                    flag_dev.screen_flag=AUZ;//不支持长按
                                    flag_dev.anchor=0;
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
                            LCD_Fill(93,0,319,40,RED);
                            LCD_Show_3030_String(22,212,"2/3",WHITE);

                            gui_draw_arcrectangle(2,43, 86,40,1,1, RED,RED);
                            gui_draw_arcrectangle(2,84, 86,40,1,1, BLUE,BLUE);
                            gui_draw_arcrectangle(2,125,86,40,1,1,BLUE,BLUE);
                            gui_draw_arcrectangle(2,166,86,40,1,1,BLUE,BLUE);

                            LCD_Show_3030_String(10,50,"TIMER",WHITE);
                            LCD_Show_3030_String(10, 89,"RESET",WHITE);
                            LCD_Show_3030_String(30,131,"IP",WHITE);
                            LCD_Show_3030_String(10,170,"UV&OV",WHITE);
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
                            LCD_Fill(93,0,319,40,RED);
                            LCD_Show_3030_String(22,212,"3/3",WHITE);
                            flag_dev.page_num=3;
                            flag_dev.screen_flag=PWD;
                            flag_dev.action_flag=PWD;
                            gui_draw_arcrectangle(2,43, 86,40,1,1, RED,RED);
                            gui_draw_arcrectangle(2,84, 86,40,1,1, BLUE,BLUE);
                            gui_draw_arcrectangle(2,125,86,40,1,1,BLACK,BLACK);
                            gui_draw_arcrectangle(2,166,86,40,1,1,BLACK,BLACK);

                            LCD_Show_3030_String(25,50,"PWD",WHITE);
                            LCD_Show_3030_String(25,89,"AUZ",WHITE);
                            pwd_page_activity();
                            flag_dev.anchor=0;
                            delay_ms(200);

                        }
                    else if(flag_dev.page_num==3)
                        {
                            LCD_Fill(22,212,52,239,BLUE);
                            LCD_Fill(93,42,319,208,BLACK);
                            LCD_Fill(93,0,319,40,RED);
                            LCD_Show_3030_String(22,212,"1/3",WHITE);

                            gui_draw_arcrectangle(2,43, 86,40,1,1, RED,RED);
                            gui_draw_arcrectangle(2,84, 86,40,1,1, BLUE,BLUE);
                            gui_draw_arcrectangle(2,125,86,40,1,1,BLUE,BLUE);
                            gui_draw_arcrectangle(2,166,86,40,1,1,BLUE,BLUE);
                            LCD_Show_picture(25,47,WHITE,0);
                            LCD_Show_3030_String(10,89,"DELAY",WHITE);
                            LCD_Show_3030_String(1, 126,"SWITCH",WHITE);
                            LCD_Show_3030_String(15,168,"DATE",WHITE);
                        
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
                            LCD_Fill(93,0,319,40,RED);
                            LCD_Show_3030_String(22,212,"3/3",WHITE);
                            flag_dev.page_num=3;
                            flag_dev.screen_flag=PWD;
                            flag_dev.action_flag=PWD;
                            gui_draw_arcrectangle(2,43, 86,40,1,1, RED,RED);
                            gui_draw_arcrectangle(2,84, 86,40,1,1, BLUE,BLUE);
                            gui_draw_arcrectangle(2,125,86,40,1,1,BLACK,BLACK);
                            gui_draw_arcrectangle(2,166,86,40,1,1,BLACK,BLACK);
                            LCD_Show_3030_String(25,50,"PWD",WHITE);
                            LCD_Show_3030_String(25,89,"AUZ",WHITE);


                            pwd_page_activity();
                            delay_ms(200);
                            flag_dev.anchor=0;
                        }
                    else if(flag_dev.page_num==3)
                        {
                            LCD_Fill(22,212,52,239,BLUE);
                            LCD_Fill(93,42,319,208,BLACK);
                            LCD_Fill(93,0,319,40,RED);
                            LCD_Show_3030_String(22,212,"2/3",WHITE);

                            gui_draw_arcrectangle(2,43, 86,40,1,1, RED,RED);
                            gui_draw_arcrectangle(2,84, 86,40,1,1, BLUE,BLUE);
                            gui_draw_arcrectangle(2,125,86,40,1,1,BLUE,BLUE);
                            gui_draw_arcrectangle(2,166,86,40,1,1,BLUE,BLUE);

                            LCD_Show_3030_String(10,50,"TIMER",WHITE);
                            LCD_Show_3030_String(10, 89,"RESET",WHITE);
                            LCD_Show_3030_String(30,131,"IP",WHITE);
                            LCD_Show_3030_String(10,170,"UV&OV",WHITE);
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
                            LCD_Fill(93,0,319,40,RED);
                            LCD_Show_3030_String(22,212,"1/3",WHITE);

                            gui_draw_arcrectangle(2,43, 86,40,1,1, RED,RED);
                            gui_draw_arcrectangle(2,84, 86,40,1,1, BLUE,BLUE);
                            gui_draw_arcrectangle(2,125,86,40,1,1,BLUE,BLUE);
                            gui_draw_arcrectangle(2,166,86,40,1,1,BLUE,BLUE);

                            LCD_Show_picture(25,47,WHITE,0);
                            LCD_Show_3030_String(10,89,"DELAY",WHITE);
                            LCD_Show_3030_String(1, 126,"SWITCH",WHITE);
                            LCD_Show_3030_String(15,168,"DATE",WHITE);
                 
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
                    gui_draw_arcrectangle(120,210,80,30,1,1,BLUE,BLUE);
                    LCD_Show_picture(150,210,WHITE,1);
                }


        }







}

void main_page_encoder_action()
{
   if(flag_dev.lock_sta==L_OPEN&& flag_dev.anchor==0){
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
                            gui_draw_arcrectangle(2,166,86,40,1,1,BLUE,BLUE);
													LCD_Show_3030_String(15,168,"DATE",WHITE);
                            LCD_DrawLtrigo(57,215,82,240,RIGHT,RED);

                            delay_ms(300);
                            LCD_Fill(22,212,52,239,BLUE);
                            LCD_Fill(93,42,319,208,BLACK);
                            LCD_Fill(93,0,319,40,RED);
                            LCD_Show_3030_String(22,212,"2/3",WHITE);

                            gui_draw_arcrectangle(2,43, 86,40,1,1, RED,RED);
                            gui_draw_arcrectangle(2,84, 86,40,1,1, BLUE,BLUE);
                            gui_draw_arcrectangle(2,125,86,40,1,1,BLUE,BLUE);
                            gui_draw_arcrectangle(2,166,86,40,1,1,BLUE,BLUE);

                            LCD_Show_3030_String(10,50,"TIMER",WHITE);
                            LCD_Show_3030_String(10, 89,"RESET",WHITE);
                            LCD_Show_3030_String(30,131,"IP",WHITE);
                            LCD_Show_3030_String(10,170,"UV&OV",WHITE);
                            timer_page_activity();
                            flag_dev.page_num=2;
                            flag_dev.screen_flag=TIMER;
                            flag_dev.action_flag=TIMER;

                            LCD_DrawLtrigo(57,215,82,240,RIGHT,WHITE);
                            delay_ms(200);
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
                            gui_draw_arcrectangle(2,166,86,40,1,1,BLUE,BLUE);
												  	 LCD_Show_3030_String(10,170,"UV&OV",WHITE);
                            LCD_DrawLtrigo(57,215,82,240,RIGHT,RED);
                            delay_ms(300);
                            LCD_Fill(22,212,52,239,BLUE);
                            LCD_Fill(93,42,319,208,BLACK);
                            LCD_Fill(93,0,319,40,RED);
                            LCD_Show_3030_String(22,212,"3/3",WHITE);
                            flag_dev.page_num=3;
                            flag_dev.screen_flag=PWD;
                            flag_dev.action_flag=PWD;
                            gui_draw_arcrectangle(2,43, 86,40,1,1, RED,RED);
                            gui_draw_arcrectangle(2,84, 86,40,1,1, BLUE,BLUE);
                            gui_draw_arcrectangle(2,125,86,40,1,1,BLACK,BLACK);
                            gui_draw_arcrectangle(2,166,86,40,1,1,BLACK,BLACK);
                            LCD_Show_3030_String(25,50,"PWD",WHITE);
                            LCD_Show_3030_String(25,89,"AUZ",WHITE);
                            pwd_page_activity();
                            LCD_DrawLtrigo(57,215,82,240,RIGHT,WHITE);
                            delay_ms(200);
                            flag_dev.anchor=0;


                        }
                }
            else if(flag_dev.page_num==3)
                {
                    if(flag_dev.action_flag==PWD)
                        {
                            flag_dev.activity_flag=AUZ;
                            flag_dev.action_flag=AUZ;
                            flag_dev.screen_flag=AUZ;//不支持长按
                            flag_dev.anchor=0;
                        }
                    else if(flag_dev.action_flag==AUZ)
                        {
                            gui_draw_arcrectangle(2,84, 86,40,1,1, BLUE,BLUE);
													 LCD_Show_3030_String(25,89,"AUZ",WHITE);
                            LCD_DrawLtrigo(57,215,82,240,RIGHT,RED);
                            delay_ms(300);
                            LCD_Fill(22,212,52,239,BLUE);
                            LCD_Fill(93,42,319,208,BLACK);
                            LCD_Fill(93,0,319,40,RED);
                            LCD_Show_3030_String(22,212,"1/3",WHITE);

                            gui_draw_arcrectangle(2,43, 86,40,1,1, RED,RED);
                            gui_draw_arcrectangle(2,84, 86,40,1,1, BLUE,BLUE);
                            gui_draw_arcrectangle(2,125,86,40,1,1,BLUE,BLUE);
                            gui_draw_arcrectangle(2,166,86,40,1,1,BLUE,BLUE);

                            LCD_Show_picture(25,47,WHITE,0);
                            LCD_Show_3030_String(10,89,"DELAY",WHITE);
                            LCD_Show_3030_String(1, 126,"SWITCH",WHITE);
                            LCD_Show_3030_String(15,168,"DATE",WHITE);
                            main_setting_page_activity();
                            LCD_DrawLtrigo(57,215,82,240,RIGHT,WHITE);
                            flag_dev.page_num=1;
                            flag_dev.screen_flag=HOME;
                            flag_dev.action_flag=HOME;
                            delay_ms(200);
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
                            gui_draw_arcrectangle(2,43, 86,40,1,1, BLUE,BLUE);
													  LCD_Show_picture(25,47,WHITE,0);
                            LCD_DrawLtrigo(5,215,30,240,LEFT,RED);
                            delay_ms(300);
                            LCD_Fill(22,212,52,239,BLUE);
                            LCD_Fill(93,42,319,208,BLACK);
                            LCD_Fill(93,0,319,40,RED);
                            LCD_Show_3030_String(22,212,"3/3",WHITE);
                            flag_dev.page_num=3;
                            flag_dev.screen_flag=PWD;
                            flag_dev.action_flag=PWD;
                            gui_draw_arcrectangle(2,43, 86,40,1,1, RED,RED);
                            gui_draw_arcrectangle(2,84, 86,40,1,1, BLUE,BLUE);
                            gui_draw_arcrectangle(2,125,86,40,1,1,BLACK,BLACK);
                            gui_draw_arcrectangle(2,166,86,40,1,1,BLACK,BLACK);
                            LCD_Show_3030_String(25,50,"PWD",WHITE);
                            LCD_Show_3030_String(25,89,"AUZ",WHITE);


                            pwd_page_activity();
                            LCD_DrawLtrigo(5,215,30,240,LEFT,WHITE);
                            delay_ms(200);
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
                            gui_draw_arcrectangle(2,43, 86,40,1,1, BLUE,BLUE);
													 LCD_Show_3030_String(10,50,"TIMER",WHITE);
                            LCD_DrawLtrigo(5,215,30,240,LEFT,RED);
                            delay_ms(300);
                            LCD_Fill(22,212,52,239,BLUE);
                            LCD_Fill(93,42,319,208,BLACK);
                            LCD_Fill(93,0,319,40,RED);
                            LCD_Show_3030_String(22,212,"1/3",WHITE);

                            gui_draw_arcrectangle(2,43, 86,40,1,1, RED,RED);
                            gui_draw_arcrectangle(2,84, 86,40,1,1, BLUE,BLUE);
                            gui_draw_arcrectangle(2,125,86,40,1,1,BLUE,BLUE);
                            gui_draw_arcrectangle(2,166,86,40,1,1,BLUE,BLUE);

                            LCD_Show_picture(25,47,WHITE,0);
                            LCD_Show_3030_String(10,89,"DELAY",WHITE);
                            LCD_Show_3030_String(1, 126,"SWITCH",WHITE);
                            LCD_Show_3030_String(15,168,"DATE",WHITE);
                            main_setting_page_activity();
                            LCD_DrawLtrigo(5,215,30,240,LEFT,WHITE);
                            flag_dev.page_num=1;
                            flag_dev.screen_flag=HOME;
                            flag_dev.action_flag=HOME;
                            delay_ms(200);
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
                            gui_draw_arcrectangle(2,43, 86,40,1,1, BLUE,BLUE);
													 LCD_Show_3030_String(25,50,"PWD",WHITE);
                            LCD_DrawLtrigo(5,215,30,240,LEFT,RED);
                            delay_ms(300);

                            LCD_Fill(22,212,52,239,BLUE);
                            LCD_Fill(93,42,319,208,BLACK);
                            LCD_Fill(93,0,319,40,RED);
                            LCD_Show_3030_String(22,212,"2/3",WHITE);

                            gui_draw_arcrectangle(2,43, 86,40,1,1, RED,RED);
                            gui_draw_arcrectangle(2,84, 86,40,1,1, BLUE,BLUE);
                            gui_draw_arcrectangle(2,125,86,40,1,1,BLUE,BLUE);
                            gui_draw_arcrectangle(2,166,86,40,1,1,BLUE,BLUE);

                            LCD_Show_3030_String(10,50,"TIMER",WHITE);
                            LCD_Show_3030_String(10, 89,"RESET",WHITE);
                            LCD_Show_3030_String(30,131,"IP",WHITE);
                            LCD_Show_3030_String(10,170,"UV&OV",WHITE);
                            timer_page_activity();
                            LCD_DrawLtrigo(5,215,30,240,LEFT,WHITE);
                            flag_dev.page_num=2;
                            flag_dev.screen_flag=TIMER;
                            flag_dev.action_flag=TIMER;
                            delay_ms(200);
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

			 if(flag_dev.anchor!=0){
				 if(encoder_dev.EN_STATE==TURN_L){
					 encoder_dev.EN_STATE=XNULL;
					 flag_dev.screen_key=LEFT;
				 }else if(encoder_dev.EN_STATE==TURN_R){
				 encoder_dev.EN_STATE=XNULL;
				    flag_dev.screen_key=RIGHT;
				 }
					 
				 
				 }

}