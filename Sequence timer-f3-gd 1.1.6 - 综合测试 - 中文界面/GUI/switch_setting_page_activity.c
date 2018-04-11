#include "switch_setting_page_activity.h"
#include "lcd.h"
#include "gui.h"
#include "flag.h"
#include "touch.h"
#include "delay.h"
#include "data.h"

extern _m_tp_dev tp_dev;//´¥ÆÁ½á¹¹Ìå
extern _flag_dev flag_dev;

void switch_setting_page_activity()
{

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
            LCD_Show_3030_String(110,5,"CHAN SWITCH1/2",WHITE);
        }
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

//    LCD_Show_2424_String(100,50,"Chan5",WHITE);
//    LCD_Show_2424_String(100,90,"Chan6",WHITE);
//    LCD_Show_2424_String(100,130,"Chan7",WHITE);
//    LCD_Show_2424_String(100,170,"Chan8",WHITE);

//	   LCD_Show_3030_String(230,50,"ON",BLACK);
//		 LCD_Show_3030_String(230,90,"ON",BLACK);
//		 LCD_Show_3030_String(230,130,"ON",BLACK);
//		 LCD_Show_3030_String(230,170,"ON",BLACK);

//    LCD_Show_3030_String(230,50,"OFF",BLACK);
//    LCD_Show_3030_String(230,90,"OFF",BLACK);
//    LCD_Show_3030_String(230,130,"OFF",BLACK);
//    LCD_Show_3030_String(230,170,"OFF",BLACK);

    gui_draw_arcrectangle(120,210,80,30,1,1,BLUE,BLUE);

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
    gui_draw_arcrectangle(120,210,80,30,1,1,BLUE,BLUE);
    gui_draw_arcrectangle(125,212,70,28,1,1,WHITE,WHITE);
    if(flag_dev.langage==0)
        ShowTwoChineseChar(135,213,10,11,24,BLACK);
    else
        LCD_Show_3030_String(130,210,"SAVE",BLACK);
    flag_dev.activity_num=1;

}

void switch_setting_page_action()
{
    if(flag_dev.action_flag==SWITCH&&(tp_dev.x[0]>92)&&(tp_dev.x[0]<132)&&(tp_dev.y[0]>0)&&(tp_dev.y[0]<40))
        {
            delay_ms(200);
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
                            LCD_Show_2424_String(241,14,"1/2",WHITE);
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
                            ShowTwoChineseChar(145,11,14,15,24,WHITE);
                            ShowTwoChineseChar(193,11,5,6,24,WHITE);
                            LCD_Show_2424_String(241,14,"2/2",WHITE);
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
                                LCD_Show_3030_String(230,50,"OFF",BLACK);
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
                    gui_draw_arcrectangle(94,0,226,40,3,1, RED,RED);
                    LCD_DrawLtrigo(95,0,125,40,LEFT,WHITE);
                    LCD_DrawLtrigo(290,0,319,40,RIGHT,WHITE);
                    if(flag_dev.langage==1)
                        {
                            LCD_Show_3030_String(110,5,"CHAN SWITCH1/2",WHITE);
                        }
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
                            ShowTwoChineseChar(145,11,14,15,24,WHITE);
                            ShowTwoChineseChar(193,11,5,6,24,WHITE);
                            LCD_Show_2424_String(241,14,"1/2",WHITE);
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


        }
    else if(flag_dev.action_flag==SWITCH&&(tp_dev.x[0]>279)&&(tp_dev.x[0]<319)&&(tp_dev.y[0]>0)&&(tp_dev.y[0]<40))
        {

            delay_ms(300);
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
                            ShowTwoChineseChar(145,11,14,15,24,WHITE);
                            ShowTwoChineseChar(193,11,5,6,24,WHITE);
                            LCD_Show_2424_String(241,14,"2/2",WHITE);
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
                                LCD_Show_3030_String(230,50,"OFF",BLACK);
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
                    LCD_DrawLtrigo(95,0,125,40,LEFT,WHITE);
                    LCD_DrawLtrigo(290,0,319,40,RIGHT,WHITE);
                    if(flag_dev.langage==1)
                        {
                            LCD_Show_3030_String(110,5,"CHAN SWITCH1/2",WHITE);
                        }
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
                            ShowTwoChineseChar(145,11,14,15,24,WHITE);
                            ShowTwoChineseChar(193,11,5,6,24,WHITE);
                            LCD_Show_2424_String(241,14,"1/2",WHITE);
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
        }
    if(flag_dev.action_flag==SWITCH&&(tp_dev.x[0]>172)&&(tp_dev.x[0]<319)&&(tp_dev.y[0]>48)&&(tp_dev.y[0]<78))
        {

            if(flag_dev.activity_num==1)
                {
                    if(EnCH1)
                        {

                            gui_draw_arcrectangle(222,48, 60,30,1,1,WHITE,WHITE);
                            if(flag_dev.langage==1)
                                LCD_Show_3030_String(230,50,"OFF",BLACK);
                            else
                                ShowChineseChar(235,50,6,24,BLACK);
														ResetCH1
                            EnCH1=0;
                        }
                    else
                        {
                            gui_draw_arcrectangle(222,48, 60,30,1,1,WHITE,WHITE);
                            if(flag_dev.langage==1)
                                LCD_Show_3030_String(230,50,"ON",BLACK);
                            else
                                ShowChineseChar(235,50,5,24,BLACK);
                            EnCH1=1;
                        }

                }
            else if(flag_dev.activity_num==2)
                {
                    if(EnCH5)
                        {
                            gui_draw_arcrectangle(222,48, 60,30,1,1,WHITE,WHITE);
                            if(flag_dev.langage==1)
                                LCD_Show_3030_String(230,50,"OFF",BLACK);
                            else
                                ShowChineseChar(235,50,6,24,BLACK);
                            ResetCH5
                            EnCH5=0;
                        }
                    else
                        {

                            gui_draw_arcrectangle(222,48, 60,30,1,1,WHITE,WHITE);
                            if(flag_dev.langage==1)
                                LCD_Show_3030_String(230,50,"ON",BLACK);
                            else
                                ShowChineseChar(235,50,5,24,BLACK);
                            EnCH5=1;

                        }

                }
            delay_ms(300);
        }
    else if(flag_dev.action_flag==SWITCH&&(tp_dev.x[0]>172)&&(tp_dev.x[0]<319)&&(tp_dev.y[0]>88)&&(tp_dev.y[0]<118))
        {

            if(flag_dev.activity_num==1)
                {

                    if(EnCH2)
                        {

                            gui_draw_arcrectangle(222,89, 60,30,1,1,WHITE,WHITE);
                            if(flag_dev.langage==1)
                                LCD_Show_3030_String(230,90,"OFF",BLACK);
                            else
                                ShowChineseChar(235,90,6,24,BLACK);
                            ResetCH2
                            EnCH2=0;
                        }
                    else
                        {

                            gui_draw_arcrectangle(222,89, 60,30,1,1,WHITE,WHITE);
                            if(flag_dev.langage==1)
                                LCD_Show_3030_String(230,90,"ON",BLACK);
                            else
                                ShowChineseChar(235,90,5,24,BLACK);
                            EnCH2=1;

                        }

                }
            else if(flag_dev.activity_num==2)
                {

                    if(EnCH6)
                        {
                            gui_draw_arcrectangle(222,89, 60,30,1,1,WHITE,WHITE);
                            if(flag_dev.langage==1)
                                LCD_Show_3030_String(230,90,"OFF",BLACK);
                            else
                                ShowChineseChar(235,90,6,24,BLACK);
                            ResetCH6
                            EnCH6=0;
                        }
                    else
                        {
                            gui_draw_arcrectangle(222,89, 60,30,1,1,WHITE,WHITE);
                            if(flag_dev.langage==1)
                                LCD_Show_3030_String(230,90,"ON",BLACK);

                            else
                                ShowChineseChar(235,90,5,24,BLACK);
                            EnCH6=1;
                        }

                }
            delay_ms(300);
        }
    else if(flag_dev.action_flag==SWITCH&&(tp_dev.x[0]>172)&&(tp_dev.x[0]<319)&&(tp_dev.y[0]>128)&&(tp_dev.y[0]<158))
        {

            if(flag_dev.activity_num==1)
                {

                    if(EnCH3)
                        {

                            gui_draw_arcrectangle(222,130, 60,30,1,1,WHITE,WHITE);
                            if(flag_dev.langage==1)
                                LCD_Show_3030_String(230,130,"OFF",BLACK);
                            else
                                ShowChineseChar(235,130,6,24,BLACK);
                            ResetCH3
                            EnCH3=0;
                        }
                    else
                        {
                            gui_draw_arcrectangle(222,130, 60,30,1,1,WHITE,WHITE);
                            if(flag_dev.langage==1)
                                LCD_Show_3030_String(230,130,"ON",BLACK);
                            else
                                ShowChineseChar(235,130,5,24,BLACK);
                            EnCH3=1;
                        }
                }
            else if(flag_dev.activity_num==2)
                {

                    if(EnCH7)
                        {
                            gui_draw_arcrectangle(222,130, 60,30,1,1,WHITE,WHITE);
                            if(flag_dev.langage==1)
                                LCD_Show_3030_String(230,130,"OFF",BLACK);
                            else
                                ShowChineseChar(235,130,6,24,BLACK);
                           ResetCH7
                            EnCH7=0;
                        }
                    else
                        {
                            gui_draw_arcrectangle(222,130, 60,30,1,1,WHITE,WHITE);
                            if(flag_dev.langage==1)
                                LCD_Show_3030_String(230,130,"ON",BLACK);
                            else
                                ShowChineseChar(235,130,5,24,BLACK);
                            EnCH7=1;
                        }

                }
            delay_ms(300);
        }
    else if(flag_dev.action_flag==SWITCH&&(tp_dev.x[0]>172)&&(tp_dev.x[0]<319)&&(tp_dev.y[0]>168)&&(tp_dev.y[0]<208))
        {

            if(flag_dev.activity_num==1)
                {

                    if(EnCH4)
                        {
                            gui_draw_arcrectangle(222,171, 60,30,1,1,WHITE,WHITE);
                            if(flag_dev.langage==1)
                                LCD_Show_3030_String(230,170,"OFF",BLACK);
                            else
                                ShowChineseChar(235,170,6,24,BLACK);
                                ResetCH4
                            EnCH4=0;
                        }
                    else
                        {
                            gui_draw_arcrectangle(222,171, 60,30,1,1,WHITE,WHITE);
                            if(flag_dev.langage==1)
                                LCD_Show_3030_String(230,170,"ON",BLACK);
                            else
                                ShowChineseChar(235,170,5,24,BLACK);
                            EnCH4=1;
                        }
                }
            else if(flag_dev.activity_num==2)
                {

                    if(EnCH8)
                        {
                            gui_draw_arcrectangle(222,171, 60,30,1,1,WHITE,WHITE);
                            if(flag_dev.langage==1)
                                LCD_Show_3030_String(230,170,"OFF",BLACK);
                            else
                                ShowChineseChar(235,170,6,24,BLACK);
                            ResetCH8
                            EnCH8=0;
                        }
                    else
                        {

                            gui_draw_arcrectangle(222,171, 60,30,1,1,WHITE,WHITE);
                            if(flag_dev.langage==1)
                                LCD_Show_3030_String(230,170,"ON",BLACK);
                            else
                                ShowChineseChar(235,170,5,24,BLACK);
                            EnCH8=1;
                        }

                }
            delay_ms(300);

        }
}




