#include "action.h"
#include "touch.h"
#include "delay.h"
#include "flag.h"
#include "lcd.h"
#include "gui.h"
#include "main_page.h"
#include "main_setting_page.h"
#include "delay_setting_page.h"
#include "switch_setting_page_activity.h"
#include "date_setting_page.h"
#include "reset_page.h"
#include "ip_setting_page.h"
#include "uv_ov_page.h"
#include "timer_page.h"
#include "pwd_page.h"
#include "auz_page.h"
#include "data.h"
#include "uv_ov_page.h"
#include "rtc.h"
#include "key_board.h"
#include "auz_page.h"
#include "key.h"

extern _encoder_dev  encoder_dev;
extern _uv_ov_data uv_ov_data;
extern _date_time_data date_time_data;
extern _ip_data ip_data;
extern _m_tp_dev tp_dev;//触屏结构体
extern _flag_dev flag_dev;
extern _chan_open_data  chan_open_data;
extern _chan_close_data  chan_close_data;
extern _chan_data chan_data;
extern _timer_dev chan_dev;
extern u32 SECCOUNT;
/*触摸屏操作*/
void screen_action()
{

    tp_dev.scan(0);
    if(tp_dev.sta&TP_PRES_DOWN)
        {
            delay_ms(10);//消抖
            if(tp_dev.sta&TP_PRES_DOWN)
                {

                    key_board_action();
                    main_page_action();//main_activity上的屏幕动作主要更新标志位，来更新页面
                    uv_ov_page_action();//选取uv_ov_page上的锚点，用于加减箭头确定跟新数据对象
                    delay_setting_page_action();//chan页面切换和选取页面上的锚点，用于加减箭头确定跟新数据对象
                    date_setting_page_action();
                    main_setting_page_action();
                    switch_setting_page_action();
                    reset_page_action();
                    pwd_page_action();
                    auz_page_action();
                    timer_page_action();
                    ip_setting_page_action();
                    add_sb();//判断加减法箭头是否按下
                }

        }

    page_flash();//MUNE栏动作和上下两个栏动作(可以函数里面增加刷新时间延时来防止长按刷新过快)
    data_flash();
    save_action();
    key_board_event();

}


/*左侧栏切换时界面刷新*/
void page_flash()
{
    if(flag_dev.activity_flag==HOME)
        {
            flag_dev.activity_flag=NUll;
            LCD_Fill(93,42,319,208,BLACK);
            gui_draw_arcrectangle(94,0,226,40,3,1, RED,RED);
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
            main_setting_page_activity();
            LCD_Fill(22,212,52,239,BLUE);
            LCD_Show_3030_String(22,212,"1/3",WHITE);
            flag_dev.page_num=1;
            flag_dev.anchor=0;//清除切换界面前锚点
        }
    else if(flag_dev.activity_flag==DELAY)
        {

            flag_dev.activity_flag=NUll;
            LCD_Fill(93,42,319,208,BLACK);
            gui_draw_arcrectangle(94,0,226,40,3,1, RED,RED);
            gui_draw_arcrectangle(0,43, 90,40,3,1, BLUE,BLUE);
            gui_draw_arcrectangle(0,84, 90,40,3,1, RED,RED);
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
            delay_setting_page_activity();
            flag_dev.screen_flag=DELAY;
            flag_dev.anchor=0;//清除切换界面前锚点

        }
    else if(flag_dev.activity_flag==SWITCH)
        {

            flag_dev.activity_flag=NUll;
            LCD_Fill(93,42,319,208,BLACK);
            gui_draw_arcrectangle(94,0,226,40,3,1, RED,RED);
            gui_draw_arcrectangle(0,43, 90,40,3,1, BLUE,BLUE);
            gui_draw_arcrectangle(0,84, 90,40,3,1, BLUE,BLUE);
            gui_draw_arcrectangle(0,125,90,40,3,1,RED,RED);
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
            switch_setting_page_activity();
            flag_dev.screen_flag=SWITCH;
            flag_dev.anchor=0;//清除切换界面前锚点

        }
    else if(flag_dev.activity_flag==DATE)
        {
            flag_dev.activity_flag=NUll;
            LCD_Fill(93,42,319,208,BLACK);
            gui_draw_arcrectangle(94,0,226,40,3,1, RED,RED);
            gui_draw_arcrectangle(0,43, 90,40,3,1, BLUE,BLUE);
            gui_draw_arcrectangle(0,84, 90,40,3,1, BLUE,BLUE);
            gui_draw_arcrectangle(0,125,90,40,3,1,BLUE,BLUE);
            gui_draw_arcrectangle(0,166,90,41,3,1,RED,RED);
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
            date_setting_page_activity();
            flag_dev.anchor=0;//清除切换界面前锚点

        }
    else if(flag_dev.activity_flag==TIMER)
        {
            flag_dev.activity_flag=NUll;
            LCD_Fill(93,42,319,208,BLACK);
            gui_draw_arcrectangle(94,0,226,40,3,1, RED,RED);
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
                    LCD_Show_3030_String(10,171,"UV&OV",WHITE);
                }
            timer_page_activity();
            flag_dev.anchor=0;//清除切换界面前锚点

        }
    else if(flag_dev.activity_flag==RESET)
        {
            flag_dev.activity_flag=NUll;
            LCD_Fill(93,42,319,208,BLACK);
            gui_draw_arcrectangle(94,0,226,40,3,1, RED,RED);
            gui_draw_arcrectangle(0,43, 90,40,3,1, BLUE,BLUE);
            gui_draw_arcrectangle(0,84, 90,40,3,1, RED,RED);
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
                    LCD_Show_3030_String(10,171,"UV&OV",WHITE);

                }
            reset_page_activity();
            flag_dev.anchor=0;//清除切换界面前锚点

        }
    else if(flag_dev.activity_flag==IP)
        {
            flag_dev.activity_flag=NUll;
            LCD_Fill(93,42,319,208,BLACK);
            gui_draw_arcrectangle(94,0,226,40,3,1, RED,RED);
            gui_draw_arcrectangle(0,43, 90,40,3,1, BLUE,BLUE);
            gui_draw_arcrectangle(0,84, 90,40,3,1, BLUE,BLUE);
            gui_draw_arcrectangle(0,125,90,40,3,1,RED,RED);
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
                    LCD_Show_3030_String(10,171,"UV&OV",WHITE);

                }
            ip_setting_page_activity();
            flag_dev.anchor=0;//清除切换界面前锚点

        }
    else if(flag_dev.activity_flag==UV_OV)
        {
            flag_dev.activity_flag=NUll;
            LCD_Fill(93,42,319,208,BLACK);
            gui_draw_arcrectangle(94,0,226,40,3,1, RED,RED);
            gui_draw_arcrectangle(0,43, 90,40,3,1, BLUE,BLUE);
            gui_draw_arcrectangle(0,84, 90,40,3,1, BLUE,BLUE);
            gui_draw_arcrectangle(0,125,90,40,3,1,BLUE,BLUE);
            gui_draw_arcrectangle(0,166,90,41,3,1,RED,RED);
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
                    LCD_Show_3030_String(10,171,"UV&OV",WHITE);

                }
            uv_ov_page_activity();
            flag_dev.anchor=0;//清除切换界面前锚点

        }
    else if(flag_dev.activity_flag==PWD)
        {
            flag_dev.activity_flag=NUll;
            LCD_Fill(93,42,319,208,BLACK);
            gui_draw_arcrectangle(94,0,226,40,3,1, RED,RED);
            gui_draw_arcrectangle(0,43, 90,40,3,1, RED,RED);
            gui_draw_arcrectangle(0,84, 90,40,3,1, BLUE,BLUE);
            gui_draw_arcrectangle(0,125,90,40,3,1,BLACK,BLACK);
            gui_draw_arcrectangle(0,166,90,41,3,1,BLACK,BLACK);
            if(flag_dev.langage==0)
                {
                    ShowTwoChineseChar(15,50,28,29,30,WHITE);
                    ShowTwoChineseChar(15,89,30,31,30,WHITE);
                }
            else
                {
                    LCD_Show_3030_String(25,50,"PWD",WHITE);
                    LCD_Show_3030_String(25,89,"AUZ",WHITE);

                }
            pwd_page_activity();
            flag_dev.anchor=0;//清除切换界面前锚点

        }
    else if(flag_dev.activity_flag==AUZ)
        {
            flag_dev.activity_flag=NUll;
            LCD_Fill(93,42,319,208,BLACK);
            gui_draw_arcrectangle(94,0,226,40,3,1, RED,RED);
            gui_draw_arcrectangle(0,43, 90,40,3,1, BLUE,BLUE);
            gui_draw_arcrectangle(0,84, 90,40,3,1, RED,RED);
            gui_draw_arcrectangle(0,125,90,40,3,1,BLACK,BLACK);
            gui_draw_arcrectangle(0,166,90,41,3,1,BLACK,BLACK);

            if(flag_dev.langage==0)
                {
                    ShowTwoChineseChar(15,50,28,29,30,WHITE);
                    ShowTwoChineseChar(15,89,30,31,30,WHITE);
                }
            else
                {
                    LCD_Show_3030_String(25,50,"PWD",WHITE);
                    LCD_Show_3030_String(25,89,"AUZ",WHITE);
                }
            auz_page_activity();
            flag_dev.anchor=0;//清除切换界面前锚点

        }
}
/*home按键左右的两个箭头用于加减法*/
void add_sb()
{

    if((tp_dev.x[0]>225)&&(tp_dev.x[0]<255)&&(tp_dev.y[0]>215)&&(tp_dev.y[0]<240))
        {

            flag_dev.screen_key=LEFT;

        }
    else if((tp_dev.x[0]>285)&&(tp_dev.x[0]<319)&&(tp_dev.y[0]>215)&&(tp_dev.y[0]<240))
        {

            flag_dev.screen_key=RIGHT;


        }


}


//使用屏幕按钮或者编码器时候的数据刷新
void data_flash()
{

//-----------------------------IP-----------------------------
    if(flag_dev.action_flag==IP&&flag_dev.anchor==1&&flag_dev.screen_key==RIGHT)
        {
            delay_ms(70);
            ip_data.ip=ip_data.ip+1;

            flag_dev.screen_key=0;
            if(ip_data.ip>127)
                {
                    ip_data.ip=1;
                }
            LCD_ShowNum(185,125,ip_data.ip,3,30,RED,WHITE);
            flag_dev.screen_key=0;

            ReadAndSave(ISIP,1);
        }
    else if(flag_dev.action_flag==IP&&flag_dev.anchor==1&&flag_dev.screen_key==LEFT)
        {
            delay_ms(70);
            ip_data.ip=ip_data.ip-1;


            if(ip_data.ip>127|ip_data.ip==0)
                {
                    ip_data.ip=127;
                }
            LCD_ShowNum(185,125,ip_data.ip,3,30,RED,WHITE);
            flag_dev.screen_key=0;
            ReadAndSave(ISIP,1);
        }
//-----------------------protection----------------------------------
    if(flag_dev.action_flag==UV_OV&&flag_dev.anchor==1&&flag_dev.screen_key==RIGHT)
        {
            delay_ms(70);
            uv_ov_data.rdv=uv_ov_data.rdv+1;
            if(uv_ov_data.rdv>20)
                {
                    uv_ov_data.rdv=20;
                }
            LCD_ShowNum(235,68,uv_ov_data.rdv,2,30,RED,WHITE);
            flag_dev.screen_key=0;

        }
    else if(flag_dev.action_flag==UV_OV&&flag_dev.anchor==1&&flag_dev.screen_key==LEFT)
        {
            delay_ms(70);
            uv_ov_data.rdv=uv_ov_data.rdv-1;
            if(uv_ov_data.rdv<5)
                {
                    uv_ov_data.rdv=5;
                }
            LCD_ShowNum(235,68,uv_ov_data.rdv,2,30,RED,WHITE);
            flag_dev.screen_key=0;
        }
    else if(flag_dev.action_flag==UV_OV&&flag_dev.anchor==2&&flag_dev.screen_key==RIGHT)
        {
            delay_ms(70);
            uv_ov_data.uv=uv_ov_data.uv+1;
            if(uv_ov_data.uv>210)
                {
                    uv_ov_data.uv=210;
                }
            LCD_ShowNum(160,108,uv_ov_data.uv,3,30,RED,WHITE);
            flag_dev.screen_key=0;


        }
    else if(flag_dev.action_flag==UV_OV&&flag_dev.anchor==2&&flag_dev.screen_key==LEFT)
        {
            delay_ms(70);
            uv_ov_data.uv=uv_ov_data.uv-1;
            if(uv_ov_data.uv<85)
                {
                    uv_ov_data.uv=85;
                }
            LCD_ShowNum(160,108,uv_ov_data.uv,3,30,RED,WHITE);
            flag_dev.screen_key=0;
        }
    else if(flag_dev.action_flag==UV_OV&&flag_dev.anchor==3&&flag_dev.screen_key==RIGHT)
        {
            delay_ms(70);
            uv_ov_data.ov=uv_ov_data.ov+1;

            if(uv_ov_data.ov>280)
                {
                    uv_ov_data.ov=280;
                }
            LCD_ShowNum(160,148,uv_ov_data.ov,3,30,RED,WHITE);
            flag_dev.screen_key=0;
        }
    else if(flag_dev.action_flag==UV_OV&&flag_dev.anchor==3&&flag_dev.screen_key==LEFT)
        {
            delay_ms(70);
            uv_ov_data.ov=uv_ov_data.ov-1;

            if(uv_ov_data.ov<120)
                {
                    uv_ov_data.ov=120;
                }
            LCD_ShowNum(160,148,uv_ov_data.ov,3,30,RED,WHITE);
            flag_dev.screen_key=0;
        }
//--------------------------------date--------------------------------
    if(flag_dev.action_flag==DATE&&flag_dev.anchor==1&&flag_dev.screen_key==RIGHT)
        {
            delay_ms(70);
            date_time_data.date_year=date_time_data.date_year+1;
            if(date_time_data.date_year>2099)
                {
                    date_time_data.date_year=2017;

                }
            LCD_ShowNum(135,90,date_time_data.date_year,4,30,RED,WHITE);
//	       LCD_ShowNum(211,90,date_time_data.date_month,2,30,BLACK,WHITE);
//		     LCD_ShowNum(255,90,date_time_data.date_day,2,30,BLACK,WHITE);
//         LCD_ShowNum(175,170,date_time_data.time_hour,2,30,BLACK,WHITE);
//         LCD_ShowNum(215,170,date_time_data.time_min,2,30,WHITE,RED);
//
            flag_dev.screen_key=0;

        }
    else if(flag_dev.action_flag==DATE&&flag_dev.anchor==1&&flag_dev.screen_key==LEFT)
        {
            delay_ms(70);
            date_time_data.date_year=date_time_data.date_year-1;
            if(date_time_data.date_year<2017)
                {
                    date_time_data.date_year=2017;

                }
            LCD_ShowNum(135,90,date_time_data.date_year,4,30,RED,WHITE);
            flag_dev.screen_key=0;
        }
    else if(flag_dev.action_flag==DATE&&flag_dev.anchor==2&&flag_dev.screen_key==RIGHT)
        {

            delay_ms(70);
            date_time_data.date_month=date_time_data.date_month+1;
            if(date_time_data.date_month>12)
                {
                    date_time_data.date_month=1;
                }
            LCD_ShowNum(211,90,date_time_data.date_month,2,30,RED,WHITE);
            flag_dev.screen_key=0;
        }
    else if(flag_dev.action_flag==DATE&&flag_dev.anchor==2&&flag_dev.screen_key==LEFT)
        {
            delay_ms(70);
            date_time_data.date_month=date_time_data.date_month-1;
            if(date_time_data.date_month==0)
                {
                    date_time_data.date_month=1;
                }
            LCD_ShowNum(211,90,date_time_data.date_month,2,30,RED,WHITE);
            flag_dev.screen_key=0;
        }
    else if(flag_dev.action_flag==DATE&&flag_dev.anchor==3&&flag_dev.screen_key==RIGHT)
        {
            delay_ms(70);
            date_time_data.date_day=date_time_data.date_day+1;
            if(date_time_data.date_day>31)
                {
                    date_time_data.date_day=1;

                }
            LCD_ShowNum(255,90,date_time_data.date_day,2,30,RED,WHITE);
            flag_dev.screen_key=0;
        }
    else if(flag_dev.action_flag==DATE&&flag_dev.anchor==3&&flag_dev.screen_key==LEFT)
        {
            delay_ms(70);
            date_time_data.date_day=date_time_data.date_day-1;
            if(date_time_data.date_day==0)
                {
                    date_time_data.date_day=1;

                }
            LCD_ShowNum(255,90,date_time_data.date_day,2,30,RED,WHITE);
            flag_dev.screen_key=0;
        }
    else if(flag_dev.action_flag==DATE&&flag_dev.anchor==4&&flag_dev.screen_key==RIGHT)
        {
            delay_ms(70);
            date_time_data.time_hour=date_time_data.time_hour+1;
            if(date_time_data.time_hour>23)
                {
                    date_time_data.time_hour=0;

                }
            LCD_ShowNum(175,172,date_time_data.time_hour,2,30,RED,WHITE);
            flag_dev.screen_key=0;
        }
    else if(flag_dev.action_flag==DATE&&flag_dev.anchor==4&&flag_dev.screen_key==LEFT)
        {
            delay_ms(70);
            date_time_data.time_hour=date_time_data.time_hour-1;
            if(date_time_data.time_hour>23)
                {
                    date_time_data.time_hour=23;

                }
            LCD_ShowNum(175,172,date_time_data.time_hour,2,30,RED,WHITE);
            flag_dev.screen_key=0;
        }
    else if(flag_dev.action_flag==DATE&&flag_dev.anchor==5&&flag_dev.screen_key==RIGHT)
        {
            delay_ms(70);
            date_time_data.time_min=date_time_data.time_min+1;
            if(date_time_data.time_min>59)
                {
                    date_time_data.time_min=0;
                }
            LCD_ShowNum(215,172,date_time_data.time_min,2,30,RED,WHITE);
            flag_dev.screen_key=0;
        }
    else if(flag_dev.action_flag==DATE&&flag_dev.anchor==5&&flag_dev.screen_key==LEFT)
        {
            delay_ms(70);
            date_time_data.time_min=date_time_data.time_min-1;
            if(date_time_data.time_min>59)
                {
                    date_time_data.time_min=59;

                }
            LCD_ShowNum(215,172,date_time_data.time_min,2,30,RED,WHITE);
            flag_dev.screen_key=0;
        }

//------------------------------------------CHAN DELAY----------------------------------------
    if(flag_dev.action_flag==DELAY&&flag_dev.anchor==1&&flag_dev.screen_key==RIGHT)
        {
            flag_dev.screen_key=0;

            chan_data.data1=chan_data.data1+1;
            if(chan_data.data1>255)
                {
                    chan_data.data1=0;
                }
            LCD_ShowNum(220,48,chan_data.data1,3,30,RED,WHITE);
            LCD_Show_3030_String(265,48,"s",BLACK);
            delay_ms(70);
        }
    else if(flag_dev.action_flag==DELAY&&flag_dev.anchor==1&&flag_dev.screen_key==LEFT)
        {


            flag_dev.screen_key=0;

            chan_data.data1=chan_data.data1-1;

            if(chan_data.data1==0)
                {
                    chan_data.data1=1;
                }
            LCD_ShowNum(220,48,chan_data.data1,3,30,RED,WHITE);
            LCD_Show_3030_String(265,48,"s",BLACK);
            delay_ms(70);


        }
    else if(flag_dev.action_flag==DELAY&&flag_dev.anchor==2&&flag_dev.screen_key==RIGHT)
        {
            flag_dev.screen_key=0;
            chan_data.data2=chan_data.data2+1;
            if(chan_data.data2>255)
                {
                    chan_data.data2=0;
                }
            LCD_ShowNum(220,90,chan_data.data2,3,30,RED,WHITE);
            LCD_Show_3030_String(265,90,"s",BLACK);

            delay_ms(70);

        }
    else if(flag_dev.action_flag==DELAY&&flag_dev.anchor==2&&flag_dev.screen_key==LEFT)
        {
            flag_dev.screen_key=0;

            chan_data.data2=chan_data.data2-1;
            if(chan_data.data2==0)
                {
                    chan_data.data2=1;
                }
            LCD_ShowNum(220,90,chan_data.data2,3,30,RED,WHITE);
            LCD_Show_3030_String(265,90,"s",BLACK);
            delay_ms(70);
        }
    else if(flag_dev.action_flag==DELAY&&flag_dev.anchor==3&&flag_dev.screen_key==RIGHT)
        {

            flag_dev.screen_key=0;
            chan_data.data3=chan_data.data3+1;
            if(chan_data.data3>255)
                {
                    chan_data.data3=0;
                }
            LCD_ShowNum(220,131,chan_data.data3,3,30,RED,WHITE);
            LCD_Show_3030_String(265,131,"s",BLACK);
            delay_ms(70);
        }
    else if(flag_dev.action_flag==DELAY&&flag_dev.anchor==3&&flag_dev.screen_key==LEFT)
        {
            flag_dev.screen_key=0;

            chan_data.data3=chan_data.data3-1;
            if(chan_data.data3==0)
                {
                    chan_data.data3=1;
                }
            LCD_ShowNum(220,131,chan_data.data3,3,30,RED,WHITE);
            LCD_Show_3030_String(265,131,"s",BLACK);
            delay_ms(70);


        }
    else if(flag_dev.action_flag==DELAY&&flag_dev.anchor==4&&flag_dev.screen_key==RIGHT)
        {


            flag_dev.screen_key=0;

            chan_data.data4=chan_data.data4+1;
            if(chan_data.data4>255)
                {
                    chan_data.data4=0;
                }
            LCD_ShowNum(220,173,chan_data.data4,3,30,RED,WHITE);
            LCD_Show_3030_String(265,173,"s",BLACK);
            delay_ms(70);


        }
    else if(flag_dev.action_flag==DELAY&&flag_dev.anchor==4&&flag_dev.screen_key==LEFT)
        {

            flag_dev.screen_key=0;

            chan_data.data4=chan_data.data4-1;

            if(chan_data.data4==0)
                {
                    chan_data.data4=1;
                }
            LCD_ShowNum(220,173,chan_data.data4,3,30,RED,WHITE);
            LCD_Show_3030_String(265,173,"s",BLACK);


            delay_ms(70);



        }
//------------------------------------------TIMER----------------------------------------
    else if(flag_dev.action_flag==TIMER&&flag_dev.anchor==1&&flag_dev.screen_key==LEFT)
        {
            flag_dev.screen_key=0;
            chan_dev.date_year=chan_dev.date_year-1;
            if(chan_dev.date_year<2017)
                {
                    chan_dev.date_year=2017;
                }
            LCD_ShowNum(180,144,chan_dev.date_year,4,24,RED,WHITE);

            delay_ms(100);

        }
    else if(flag_dev.action_flag==TIMER&&flag_dev.anchor==1&&flag_dev.screen_key==RIGHT)
        {
            flag_dev.screen_key=0;
            chan_dev.date_year=chan_dev.date_year+1;
            if(chan_dev.date_year>2099)
                {
                    chan_dev.date_year=2017;
                }
            LCD_ShowNum(180,144,chan_dev.date_year,4,24,RED,WHITE);
            delay_ms(100);

        }
    else if(flag_dev.action_flag==TIMER&&flag_dev.anchor==2&&flag_dev.screen_key==LEFT)
        {
            flag_dev.screen_key=0;
            chan_dev.date_month=chan_dev.date_month-1;
            if(chan_dev.date_month==0)
                {
                    chan_dev.date_month=1;
                }
            LCD_ShowNum(240,144,chan_dev.date_month,2,24,RED,WHITE);
            delay_ms(100);
        }
    else if(flag_dev.action_flag==TIMER&&flag_dev.anchor==2&&flag_dev.screen_key==RIGHT)
        {
            flag_dev.screen_key=0;
            chan_dev.date_month=chan_dev.date_month+1;
            if(chan_dev.date_month>12)
                {
                    chan_dev.date_month=1;
                }
            LCD_ShowNum(240,144,chan_dev.date_month,2,24,RED,WHITE);
            delay_ms(100);
        }
    else if(flag_dev.action_flag==TIMER&&flag_dev.anchor==3&&flag_dev.screen_key==LEFT)
        {
            flag_dev.screen_key=0;
            chan_dev.date_day=chan_dev.date_day-1;
            if(chan_dev.date_day==0)
                {
                    chan_dev.date_day=1;
                }
            LCD_ShowNum(276,144,chan_dev.date_day,2,24,RED,WHITE);
            delay_ms(100);
        }
    else if(flag_dev.action_flag==TIMER&&flag_dev.anchor==3&&flag_dev.screen_key==RIGHT)
        {
            flag_dev.screen_key=0;
            chan_dev.date_day=chan_dev.date_day+1;
            if(chan_dev.date_day>31)
                {
                    chan_dev.date_day=1;
                }
            LCD_ShowNum(276,144,chan_dev.date_day,2,24,RED,WHITE);
            delay_ms(100);
        }
    else if(flag_dev.action_flag==TIMER&&flag_dev.anchor==4&&flag_dev.screen_key==LEFT)
        {
            flag_dev.screen_key=0;

            chan_dev.time_hour=chan_dev.time_hour-1;
            if(chan_dev.time_hour>23)
                {
                    chan_dev.time_hour=23;
                }
            LCD_ShowNum(180,176,chan_dev.time_hour,2,24,RED,WHITE);

            delay_ms(100);
        }
    else if(flag_dev.action_flag==TIMER&&flag_dev.anchor==4&&flag_dev.screen_key==RIGHT)
        {
            flag_dev.screen_key=0;

            chan_dev.time_hour=chan_dev.time_hour+1;
            if(chan_dev.time_hour>23)
                {
                    chan_dev.time_hour=0;
                }
            LCD_ShowNum(180,176,chan_dev.time_hour,2,24,RED,WHITE);
            delay_ms(100);
        }
    else if(flag_dev.action_flag==TIMER&&flag_dev.anchor==5&&flag_dev.screen_key==LEFT)
        {
            flag_dev.screen_key=0;

            chan_dev.time_min=chan_dev.time_min-1;
            if(chan_dev.time_min>59)
                {
                    chan_dev.time_min=59;
                }

            LCD_ShowNum(216,176,chan_dev.time_min,2,24,RED,WHITE);
            delay_ms(100);

        }
    else if(flag_dev.action_flag==TIMER&&flag_dev.anchor==5&&flag_dev.screen_key==RIGHT)
        {
            flag_dev.screen_key=0;

            chan_dev.time_min=chan_dev.time_min+1;
            if(chan_dev.time_min>59)
                {
                    chan_dev.time_min=0;
                }

            LCD_ShowNum(216,176,chan_dev.time_min,2,24,RED,WHITE);

            delay_ms(100);
        }
    else if(flag_dev.action_flag==TIMER&&flag_dev.anchor==6&&flag_dev.screen_key==LEFT)
        {
            flag_dev.screen_key=0;

            chan_dev.time_sec=chan_dev.time_sec-1;
            if(chan_dev.time_sec>59)
                {
                    chan_dev.time_sec=59;
                }

            LCD_ShowNum(252,176,chan_dev.time_sec,2,24,RED,WHITE);


            delay_ms(100);
        }
    else if(flag_dev.action_flag==TIMER&&flag_dev.anchor==6&&flag_dev.screen_key==RIGHT)
        {
            flag_dev.screen_key=0;


            chan_dev.time_sec=chan_dev.time_sec+1;
            if(chan_dev.time_sec>59)
                {
                    chan_dev.time_sec=0;
                }
            LCD_ShowNum(252,176,chan_dev.time_sec,2,24,RED,WHITE);


            delay_ms(100);
        }
    //------------------------------------------AUZ----------------------------------------
    if(flag_dev.action_flag==AUZ&&flag_dev.anchor==1&&flag_dev.screen_key==LEFT)
        {
            flag_dev.screen_key=0;
            AuzCntData.SetCnt=AuzCntData.SetCnt-1;
            if(AuzCntData.SetCnt<5)
                {
                    AuzCntData.SetCnt=5;
                }
            if(AuzCntData.SetCnt<101)
                {
                    gui_draw_arcrectangle(202,90, 117-2,30,4,1,WHITE,WHITE);
                    gui_draw_arcrectangle(202,131,117-2,30,4,1,WHITE,WHITE);
                    gui_draw_arcrectangle(202,173,117-2,30,4,1,WHITE,WHITE);
                    LCD_ShowNum(242,92,AuzCnt.CurrentCnt,3,24,BLACK,WHITE);
                    LCD_ShowNum(242,133,AuzCnt.SurplusCnt,3,24,BLACK,WHITE);
                    LCD_ShowNum(242,175,AuzCntData.SetCnt,3,24,RED,WHITE);
                }


            delay_ms(100);


        }
    else if(flag_dev.action_flag==AUZ&&flag_dev.anchor==1&&flag_dev.screen_key==RIGHT)
        {
            flag_dev.screen_key=0;
            AuzCntData.SetCnt=AuzCntData.SetCnt+1;

            if(AuzCntData.SetCnt>100)
                {
                    gui_draw_arcrectangle(202,90, 117-2,30,4,1,WHITE,WHITE);
                    gui_draw_arcrectangle(202,131,117-2,30,4,1,WHITE,WHITE);
                    gui_draw_arcrectangle(202,173,117-2,30,4,1,WHITE,WHITE);
                    AuzCntData.SetCnt=101;
                    LCD_Show_2424_String(244,94,"***",BLACK);
                    LCD_Show_2424_String(244,135,"***",BLACK);
									  if(flag_dev.langage==1){
                    LCD_Show_2424_String(204,175,"PERMANENT",RED);
										}else{
                    ShowTwoChineseChar(210,175,71,72,24,RED);
                    ShowTwoChineseChar(258,175,73,45,24,RED);
										}
                }
            else
                {

                    LCD_ShowNum(242,175,AuzCntData.SetCnt,3,24,RED,WHITE);
                }



            delay_ms(100);
        }


}

//保存数据操作
u32 Timer_[4];
void save_action()
{

    if(flag_dev.action_flag==DATE&&flag_dev.save_flag==SAVE)
        {
            gui_draw_arcrectangle(125,212,70,28,1,1,GRAY,GRAY);
            if(flag_dev.langage==1)
                LCD_Show_3030_String(130,210,"SAVE",BLACK);
            else
                ShowTwoChineseChar(135,213,10,11,24,BLACK);
            flag_dev.save_flag=0;
            RTC_Set(date_time_data.date_year,date_time_data.date_month,date_time_data.date_day,date_time_data.time_hour,date_time_data.time_min,0);
            /*更新秒数用于闹钟*/
            SECCOUNT=RTC_GetCounter();
            LCD_ShowNum(135,90,date_time_data.date_year,4,30,BLACK,WHITE);
            LCD_ShowNum(211,90,date_time_data.date_month,2,30,BLACK,WHITE);
            LCD_ShowNum(255,90,date_time_data.date_day,2,30,BLACK,WHITE);
            LCD_ShowNum(175,172,date_time_data.time_hour,2,30,BLACK,WHITE);
            LCD_ShowNum(215,172,date_time_data.time_min,2,30,BLACK,WHITE);
						delay_ms(100);
            gui_draw_arcrectangle(125,212,70,28,1,1,WHITE,WHITE);
            if(flag_dev.langage==1)
                LCD_Show_3030_String(130,210,"SAVE",BLACK);
            else
                ShowTwoChineseChar(135,213,10,11,24,BLACK);
        }
    else if(flag_dev.action_flag==UV_OV&&flag_dev.save_flag==SAVE)
        {
					 gui_draw_arcrectangle(125,212,70,28,1,1,GRAY,GRAY);
            if(flag_dev.langage==1)
                LCD_Show_3030_String(130,210,"SAVE",BLACK);
            else
                ShowTwoChineseChar(135,213,10,11,24,BLACK);
            flag_dev.save_flag=0;
            ReadAndSave(ISUV_OV,1);
            LCD_ShowNum(235,68,uv_ov_data.rdv,2,30,BLACK,WHITE);
            LCD_Show_3030_String(270,68,"V",BLACK);
            LCD_ShowNum(160,108,uv_ov_data.uv,3,30,BLACK,WHITE);
            LCD_Show_3030_String(210,108,"V",BLACK);
            LCD_ShowNum(160,148,uv_ov_data.ov,3,30,BLACK,WHITE);
            LCD_Show_3030_String(210,148,"V",BLACK);
            flag_dev.anchor=0;
						delay_ms(100);
            gui_draw_arcrectangle(125,212,70,28,1,1,WHITE,WHITE);
            if(flag_dev.langage==1)
                LCD_Show_3030_String(130,210,"SAVE",BLACK);
            else
                ShowTwoChineseChar(135,213,10,11,24,BLACK);
        }
    else if(flag_dev.action_flag==DELAY&&flag_dev.save_flag==SAVE)
        {
            gui_draw_arcrectangle(125,212,70,28,1,1,GRAY,GRAY);
            if(flag_dev.langage==1)
                LCD_Show_3030_String(130,210,"SAVE",BLACK);
            else
                ShowTwoChineseChar(135,213,10,11,24,BLACK);
            flag_dev.save_flag=0;
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
            LCD_ShowNum(220,48,chan_data.data1,3,30,BLACK,WHITE);
            LCD_Show_3030_String(265,48,"s",BLACK);
            LCD_ShowNum(220,90,chan_data.data2,3,30,BLACK,WHITE);
            LCD_Show_3030_String(265,90,"s",BLACK);
            LCD_ShowNum(220,131,chan_data.data3,3,30,BLACK,WHITE);
            LCD_Show_3030_String(265,131,"s",BLACK);
            LCD_ShowNum(220,173,chan_data.data4,3,30,BLACK,WHITE);
            LCD_Show_3030_String(265,173,"s",BLACK);
            delay_ms(100);
            gui_draw_arcrectangle(125,212,70,28,1,1,WHITE,WHITE);
            if(flag_dev.langage==1)
                LCD_Show_3030_String(130,210,"SAVE",BLACK);
            else
                ShowTwoChineseChar(135,213,10,11,24,BLACK);
        }
		else if(flag_dev.action_flag==SWITCH&&flag_dev.save_flag==SAVE){
		        flag_dev.save_flag=0;
			            gui_draw_arcrectangle(125,212,70,28,1,1,GRAY,GRAY);
            if(flag_dev.langage==1)
                LCD_Show_3030_String(130,210,"SAVE",BLACK);
            else
                ShowTwoChineseChar(135,213,10,11,24,BLACK);					
							  ReadAndSave(ISSWITCH,1);			  
						delay_ms(100);
					            gui_draw_arcrectangle(125,212,70,28,1,1,WHITE,WHITE);
            if(flag_dev.langage==1)
                LCD_Show_3030_String(130,210,"SAVE",BLACK);
            else
                ShowTwoChineseChar(135,213,10,11,24,BLACK);	
		
		}
    else if(flag_dev.action_flag==TIMER&&flag_dev.save_flag==SAVE)
        {
            gui_draw_arcrectangle(125,212,70,28,1,1,GRAY,GRAY);
            if(flag_dev.langage==1)
                LCD_Show_3030_String(130,210,"SAVE",BLACK);
            else
                ShowTwoChineseChar(135,213,10,11,24,BLACK);
            flag_dev.save_flag=0;
            if(chan_dev.mode==ONCE)
                {
                    LCD_ShowNum(180,144,chan_dev.date_year,4,24,BLACK,WHITE);
                    LCD_ShowNum(240,144,chan_dev.date_month,2,24,BLACK,WHITE);
                    LCD_ShowNum(276,144,chan_dev.date_day,2,24,BLACK,WHITE);
                }
            LCD_ShowNum(180,176,chan_dev.time_hour,2,24,BLACK,WHITE);
            LCD_ShowNum(216,176,chan_dev.time_min,2,24,BLACK,WHITE);
            LCD_ShowNum(252,176,chan_dev.time_sec,2,24,BLACK,WHITE);

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
            gui_draw_arcrectangle(125,212,70,28,1,1,WHITE,WHITE);
            if(flag_dev.langage==1)
                LCD_Show_3030_String(130,210,"SAVE",BLACK);
            else
                ShowTwoChineseChar(135,213,10,11,24,BLACK);
        }
    else if(flag_dev.action_flag==IP&&flag_dev.save_flag==SAVE)
        {
					  
            flag_dev.save_flag=0;
            ReadAndSave(ISIP,1);
            LCD_ShowNum(185,125,ip_data.ip,3,30,BLACK,WHITE);
        }
    else if(flag_dev.action_flag==PWD&&flag_dev.save_flag==SAVE)
        {
            flag_dev.save_flag=0;

        }
    else if(flag_dev.action_flag==AUZ&&flag_dev.save_flag==SAVE)
        {
					if(flag_dev.IsShowAUZNumset==1){
            gui_draw_arcrectangle(125,212,70,28,1,1,GRAY,GRAY);
            if(flag_dev.langage==1)
                LCD_Show_3030_String(130,210,"SAVE",BLACK);
            else
                ShowTwoChineseChar(135,213,10,11,24,BLACK);
            AuzCnt.CurrentCnt=0;
            AuzCnt.SurplusCnt=AuzCntData.SetCnt;
            AuzCnt.SetCnt=AuzCntData.SetCnt;

            if(AuzCnt.SetCnt<101)
                {

                    LCD_ShowNum(242,92,AuzCnt.CurrentCnt,3,24,BLACK,WHITE);
                    LCD_ShowNum(242,133,AuzCnt.SurplusCnt,3,24,BLACK,WHITE);
                    LCD_ShowNum(242,175,AuzCnt.SetCnt,3,24,BLACK,WHITE);
                }
            else
                {
                    AuzCnt.SurplusCnt=AuzCntData.SetCnt-1;
                    LCD_Show_2424_String(222,52,"******",BLACK);
                    LCD_Show_2424_String(244,94,"***",BLACK);
                    LCD_Show_2424_String(244,135,"***",BLACK);
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
            ReadAndSave(ISAUZ,1);
            flag_dev.save_flag=0;
								delay_ms(100);
            gui_draw_arcrectangle(125,212,70,28,1,1,WHITE,WHITE);
            if(flag_dev.langage==1)
                LCD_Show_3030_String(130,210,"SAVE",BLACK);
            else
                ShowTwoChineseChar(135,213,10,11,24,BLACK);
					}
        }
    /*锁屏状态的锁头操作*/
    else if(flag_dev.action_flag==HOME&&flag_dev.save_flag==SAVE)
        {
            flag_dev.save_flag=0;
            if(flag_dev.lock_sta==L_CLOSE)
                {
                    flag_dev.save_flag=0;
                    flag_dev.action_flag=NUll;
                    LCD_Fill(93,42,319,208,BLACK);
                    flag_dev.action_flag=KEY_BOARD;
                    flag_dev.KEY_board_sta=1;
                    key_board_activity();
                }
        }

}



