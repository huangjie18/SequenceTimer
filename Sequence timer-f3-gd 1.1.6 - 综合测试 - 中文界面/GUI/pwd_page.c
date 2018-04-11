#include "pwd_page.h"
#include "gui.h"
#include "lcd.h"
#include "touch.h"
#include "flag.h"

extern _flag_dev flag_dev;
extern _m_tp_dev tp_dev;

void pwd_page_activity()
{

    gui_draw_arcrectangle(94,43,226,33,3,1, BLUE,BLUE);
    gui_draw_arcrectangle(94,79,226,62,3,1,BLUE,WHITE);
    gui_draw_arcrectangle(94,143,226,63,3,1,BLUE,WHITE);

    gui_draw_arcrectangle(160,48,158,24,1,1,WHITE,WHITE);
    LCD_DrawLtrigo(160,48,185,73,LEFT,BLUE);
    LCD_DrawLtrigo(292,48,317,73,RIGHT,BLUE);
    if(flag_dev.langage==1)
        {
            LCD_Show_3030_String(150,5,"PASSWORD",WHITE);
            LCD_Show_2424_String(95, 48,"TYPE",WHITE);
            LCD_Show_2424_String(100,82,"NEW PASSWORD:",WHITE);
            LCD_Show_2424_String(100,146,"RE-ENTER:",WHITE);
        }
    else
        {
            ShowTwoChineseChar(190,11,34,35,24,WHITE);

            ShowTwoChineseChar(95,48,36,37,24,WHITE);

            ShowTwoChineseChar(95,82,38,39,24,WHITE);
            ShowChineseChar(143,82,40,24,WHITE);
            ShowTwoChineseChar(167,82,34,35,24,WHITE);

            ShowTwoChineseChar(95,146,43,44,24,WHITE);

            ShowTwoChineseChar(143,146,38,39,24,WHITE);
            ShowChineseChar(191,146,40,24,WHITE);
            ShowTwoChineseChar(215,146,34,35,24,WHITE);
        }

    LCD_Show_2424_String(95,115,"******",BLACK);
    LCD_Show_2424_String(95,180,"******",BLACK);


    if(flag_dev.pwdtype==USER)
        {
            if(flag_dev.langage==1)
                LCD_Show_2424_String(215, 48,"USER",BLACK);
            else
                ShowTwoChineseChar(215,48,45,46,24,BLACK);
        }
    else
        {

            LCD_Show_2424_String(190, 48,"SETTINGS",BLACK);
        }


    gui_draw_arcrectangle(120,210,80,30,1,1,BLUE,BLUE);

}

/*页面上的动作函数*/
void pwd_page_action()
{
    if(flag_dev.action_flag==AUZ||flag_dev.action_flag==HOME||flag_dev.action_flag==UV_OV)
        flag_dev.PWDsta=0;
    if(flag_dev.action_flag==PWD&&(tp_dev.x[0]>160)&&(tp_dev.x[0]<185)&&(tp_dev.y[0]>48)&&(tp_dev.y[0]<73))
        {

            if(flag_dev.pwdtype==SETTINGS)
                {
                    gui_draw_arcrectangle(190,48,100,24,1,1,WHITE,WHITE);
                    if(flag_dev.langage==1)
                        LCD_Show_2424_String(215, 48,"USER",BLACK);
                    else
                        ShowTwoChineseChar(215,48,45,46,24,BLACK);
                }

            flag_dev.pwdtype=USER;
        }
    else if(flag_dev.action_flag==PWD&&(tp_dev.x[0]>292)&&(tp_dev.x[0]<317)&&(tp_dev.y[0]>48)&&(tp_dev.y[0]<73))
        {

            if(flag_dev.pwdtype==USER)
                {
                    gui_draw_arcrectangle(190,48,100,24,1,1,WHITE,WHITE);
                    if(flag_dev.langage==1)
                        LCD_Show_2424_String(215, 48,"USER",BLACK);
                    else
                        ShowTwoChineseChar(215,48,45,46,24,BLACK);
                }
            flag_dev.pwdtype=SETTINGS;
        }
    else if(flag_dev.action_flag==PWD&&(tp_dev.x[0]>95)&&(tp_dev.x[0]<319)&&(tp_dev.y[0]>109)&&(tp_dev.y[0]<139))
        {


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

        }
    else if(flag_dev.action_flag==PWD&&(tp_dev.x[0]>95)&&(tp_dev.x[0]<319)&&(tp_dev.y[0]>173)&&(tp_dev.y[0]<200))
        {

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
        }

}
