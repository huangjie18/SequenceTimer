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
extern int gpio_pin[8];

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


//切换时界面刷新
void page_flash()
{
    if(flag_dev.activity_flag==HOME)
        {
            flag_dev.activity_flag=NUll;
            LCD_Fill(93,42,319,208,BLACK);
            LCD_Fill(93,0,319,40,RED);
            gui_draw_arcrectangle(2,43, 86,40,1,1, RED,RED);
            gui_draw_arcrectangle(2,84, 86,40,1,1, BLUE,BLUE);
            gui_draw_arcrectangle(2,125,86,40,1,1,BLUE,BLUE);
            gui_draw_arcrectangle(2,166,86,40,1,1,BLUE,BLUE);
            LCD_Show_picture(25,47,WHITE,0);
            LCD_Show_3030_String(10,89,"DELAY",WHITE);
            LCD_Show_3030_String(1, 126,"SWITCH",WHITE);
            LCD_Show_3030_String(15,168,"DATE",WHITE);

            main_setting_page_activity();
            LCD_Fill(22,212,52,239,BLUE);
            LCD_Show_3030_String(22,212,"1/3",WHITE);
            flag_dev.page_num=1;
            flag_dev.anchor=0;//清除切换界面前锚点
        }
    else if(flag_dev.activity_flag==DELAY)
        {

            flag_dev.activity_flag=NUll;
            LCD_Fill(93,0,319,40,RED);
            LCD_Fill(93,42,319,208,BLACK);
            gui_draw_arcrectangle(2,43, 86,40,1,1, BLUE,BLUE);
            gui_draw_arcrectangle(2,84, 86,40,1,1, RED,RED);
            gui_draw_arcrectangle(2,125,86,40,1,1,BLUE,BLUE);
            gui_draw_arcrectangle(2,166,86,40,1,1,BLUE,BLUE);
            LCD_Show_picture(25,47,WHITE,0);
            LCD_Show_3030_String(10,89,"DELAY",WHITE);
            LCD_Show_3030_String(1, 126,"SWITCH",WHITE);
            LCD_Show_3030_String(15,168,"DATE",WHITE);

            delay_setting_page_activity();
            flag_dev.screen_flag=DELAY;
            flag_dev.anchor=0;//清除切换界面前锚点

        }
    else if(flag_dev.activity_flag==SWITCH)
        {

            flag_dev.activity_flag=NUll;
            LCD_Fill(93,42,319,208,BLACK);
            LCD_Fill(93,0,319,40,RED);
            gui_draw_arcrectangle(2,43, 86,40,1,1, BLUE,BLUE);
            gui_draw_arcrectangle(2,84, 86,40,1,1, BLUE,BLUE);
            gui_draw_arcrectangle(2,125,86,40,1,1,RED,RED);
            gui_draw_arcrectangle(2,166,86,40,1,1,BLUE,BLUE);
            LCD_Show_picture(25,47,WHITE,0);
            LCD_Show_3030_String(10,89,"DELAY",WHITE);
            LCD_Show_3030_String(1, 126,"SWITCH",WHITE);
            LCD_Show_3030_String(15,168,"DATE",WHITE);
            switch_setting_page_activity();
            flag_dev.screen_flag=SWITCH;
            flag_dev.anchor=0;//清除切换界面前锚点

        }
    else if(flag_dev.activity_flag==DATE)
        {
            flag_dev.activity_flag=NUll;
            LCD_Fill(93,42,319,208,BLACK);
            LCD_Fill(93,0,319,40,RED);
            gui_draw_arcrectangle(2,43, 86,40,1,1, BLUE,BLUE);
            gui_draw_arcrectangle(2,84, 86,40,1,1, BLUE,BLUE);
            gui_draw_arcrectangle(2,125,86,40,1,1,BLUE,BLUE);
            gui_draw_arcrectangle(2,166,86,40,1,1,RED,RED);
            LCD_Show_picture(25,47,WHITE,0);
            LCD_Show_3030_String(10,89,"DELAY",WHITE);
            LCD_Show_3030_String(1, 126,"SWITCH",WHITE);
            LCD_Show_3030_String(15,168,"DATE",WHITE);
            date_setting_page_activity();
            flag_dev.anchor=0;//清除切换界面前锚点

        }
    else if(flag_dev.activity_flag==TIMER)
        {
            flag_dev.activity_flag=NUll;
            LCD_Fill(93,42,319,208,BLACK);
            LCD_Fill(93,0,319,40,RED);
            gui_draw_arcrectangle(2,43, 86,40,1,1, RED,RED);
            gui_draw_arcrectangle(2,84, 86,40,1,1, BLUE,BLUE);
            gui_draw_arcrectangle(2,125,86,40,1,1,BLUE,BLUE);
            gui_draw_arcrectangle(2,166,86,40,1,1,BLUE,BLUE);
            LCD_Show_3030_String(10,50,"TIMER",WHITE);
            LCD_Show_3030_String(10, 89,"RESET",WHITE);
            LCD_Show_3030_String(30,131,"IP",WHITE);
            LCD_Show_3030_String(10,170,"UV&OV",WHITE);
            timer_page_activity();
            flag_dev.anchor=0;//清除切换界面前锚点

        }
    else if(flag_dev.activity_flag==RESET)
        {
            flag_dev.activity_flag=NUll;
            LCD_Fill(93,42,319,208,BLACK);
            LCD_Fill(93,0,319,40,RED);
            gui_draw_arcrectangle(2,43, 86,40,1,1, BLUE,BLUE);
            gui_draw_arcrectangle(2,84, 86,40,1,1, RED,RED);
            gui_draw_arcrectangle(2,125,86,40,1,1,BLUE,BLUE);
            gui_draw_arcrectangle(2,166,86,40,1,1,BLUE,BLUE);
            LCD_Show_3030_String(10,50,"TIMER",WHITE);
            LCD_Show_3030_String(10, 89,"RESET",WHITE);
            LCD_Show_3030_String(30,131,"IP",WHITE);
            LCD_Show_3030_String(10,170,"UV&OV",WHITE);
            reset_page_activity();
            flag_dev.anchor=0;//清除切换界面前锚点

        }
    else if(flag_dev.activity_flag==IP)
        {
            flag_dev.activity_flag=NUll;
            LCD_Fill(93,42,319,208,BLACK);
            LCD_Fill(93,0,319,40,RED);
            gui_draw_arcrectangle(2,43, 86,40,1,1, BLUE,BLUE);
            gui_draw_arcrectangle(2,84, 86,40,1,1, BLUE,BLUE);
            gui_draw_arcrectangle(2,125,86,40,1,1,RED,RED);
            gui_draw_arcrectangle(2,166,86,40,1,1,BLUE,BLUE);
            LCD_Show_3030_String(10,50,"TIMER",WHITE);
            LCD_Show_3030_String(10, 89,"RESET",WHITE);
            LCD_Show_3030_String(30,131,"IP",WHITE);
            LCD_Show_3030_String(10,170,"UV&OV",WHITE);
            ip_setting_page_activity();
            flag_dev.anchor=0;//清除切换界面前锚点

        }
    else if(flag_dev.activity_flag==UV_OV)
        {
            flag_dev.activity_flag=NUll;
            LCD_Fill(93,42,319,208,BLACK);
            LCD_Fill(93,0,319,40,RED);
            gui_draw_arcrectangle(2,43, 86,40,1,1, BLUE,BLUE);
            gui_draw_arcrectangle(2,84, 86,40,1,1, BLUE,BLUE);
            gui_draw_arcrectangle(2,125,86,40,1,1,BLUE,BLUE);
            gui_draw_arcrectangle(2,166,86,40,1,1,RED,RED);
            LCD_Show_3030_String(10,50,"TIMER",WHITE);
            LCD_Show_3030_String(10, 89,"RESET",WHITE);
            LCD_Show_3030_String(30,131,"IP",WHITE);
            LCD_Show_3030_String(10,170,"UV&OV",WHITE);
            uv_ov_page_activity();
            flag_dev.anchor=0;//清除切换界面前锚点

        }
    else if(flag_dev.activity_flag==PWD)
        {
            flag_dev.activity_flag=NUll;
            LCD_Fill(93,42,319,208,BLACK);
            LCD_Fill(93,0,319,40,RED);
            gui_draw_arcrectangle(2,43, 86,40,1,1, RED,RED);
            gui_draw_arcrectangle(2,84, 86,40,1,1, BLUE,BLUE);
            gui_draw_arcrectangle(2,125,86,40,1,1,BLACK,BLACK);
            gui_draw_arcrectangle(2,166,86,40,1,1,BLACK,BLACK);


            LCD_Show_3030_String(25,50,"PWD",WHITE);
            LCD_Show_3030_String(25,89,"AUZ",WHITE);
            pwd_page_activity();
            flag_dev.anchor=0;//清除切换界面前锚点

        }
    else if(flag_dev.activity_flag==AUZ)
        {
            flag_dev.activity_flag=NUll;
            LCD_Fill(93,42,319,208,BLACK);
            LCD_Fill(93,0,319,40,RED);
            gui_draw_arcrectangle(2,43, 86,40,1,1, BLUE,BLUE);
            gui_draw_arcrectangle(2,84, 86,40,1,1, RED,RED);
            gui_draw_arcrectangle(2,125,86,40,1,1,BLACK,BLACK);
            gui_draw_arcrectangle(2,166,86,40,1,1,BLACK,BLACK);

            LCD_Show_3030_String(25,50,"PWD",WHITE);
            LCD_Show_3030_String(25,89,"AUZ",WHITE);
            auz_page_activity();
            flag_dev.anchor=0;//清除切换界面前锚点

        }



}


//home按键左右的两个箭头用于加减法

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
    if(flag_dev.action_flag==IP&&flag_dev.screen_key==RIGHT)
        {
            delay_ms(70);
            ip_data.ip=ip_data.ip+1;
            LCD_ShowNum(185,125,ip_data.ip,3,30,WHITE,RED);
            flag_dev.screen_key=0;
            if(ip_data.ip>127)
                {
                    ip_data.ip=0;
                }
            flag_dev.screen_key=0;


        }
    else if(flag_dev.action_flag==IP&&flag_dev.screen_key==LEFT)
        {
            delay_ms(70);
            ip_data.ip=ip_data.ip-1;

            LCD_ShowNum(185,125,ip_data.ip,3,30,WHITE,RED);
            if(ip_data.ip==0)
                {
                    ip_data.ip=127;
                }

            flag_dev.screen_key=0;

        }
//-----------------------protection----------------------------------


    if(flag_dev.action_flag==UV_OV&&flag_dev.anchor==1&&flag_dev.screen_key==RIGHT)
        {
            delay_ms(70);
            uv_ov_data.rdv=uv_ov_data.rdv+1;
            LCD_ShowNum(235,68,uv_ov_data.rdv,2,30,WHITE,RED);
            flag_dev.screen_key=0;

        }
    else if(flag_dev.action_flag==UV_OV&&flag_dev.anchor==1&&flag_dev.screen_key==LEFT)
        {
            delay_ms(70);
            uv_ov_data.rdv=uv_ov_data.rdv-1;
            LCD_ShowNum(235,68,uv_ov_data.rdv,2,30,WHITE,RED);
            flag_dev.screen_key=0;
        }
    else if(flag_dev.action_flag==UV_OV&&flag_dev.anchor==2&&flag_dev.screen_key==RIGHT)
        {
            delay_ms(70);
            uv_ov_data.uv=uv_ov_data.uv+1;
            if(uv_ov_data.uv>300)
                {
                    uv_ov_data.uv=200;
                }
            LCD_ShowNum(160,108,uv_ov_data.uv,3,30,WHITE,RED);
            flag_dev.screen_key=0;


        }
    else if(flag_dev.action_flag==UV_OV&&flag_dev.anchor==2&&flag_dev.screen_key==LEFT)
        {
            delay_ms(70);
            uv_ov_data.uv=uv_ov_data.uv-1;
            if(uv_ov_data.uv<200)
                {
                    uv_ov_data.uv=200;
                }
            LCD_ShowNum(160,108,uv_ov_data.uv,3,30,WHITE,RED);
            flag_dev.screen_key=0;
        }
    else if(flag_dev.action_flag==UV_OV&&flag_dev.anchor==3&&flag_dev.screen_key==RIGHT)
        {
            delay_ms(70);
            uv_ov_data.ov=uv_ov_data.ov+1;
            LCD_ShowNum(160,148,uv_ov_data.ov,3,30,WHITE,RED);
            flag_dev.screen_key=0;
            if(uv_ov_data.ov>300)
                {
                    uv_ov_data.ov=100;
                }

        }
    else if(flag_dev.action_flag==UV_OV&&flag_dev.anchor==3&&flag_dev.screen_key==LEFT)
        {
            delay_ms(70);
            uv_ov_data.ov=uv_ov_data.ov-1;
            LCD_ShowNum(160,148,uv_ov_data.ov,3,30,WHITE,RED);
            flag_dev.screen_key=0;
            if(uv_ov_data.ov<100)
                {
                    uv_ov_data.ov=100;
                }
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
            LCD_ShowNum(135,90,date_time_data.date_year,4,30,WHITE,RED);
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
            LCD_ShowNum(135,90,date_time_data.date_year,4,30,WHITE,RED);
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
            LCD_ShowNum(211,90,date_time_data.date_month,2,30,WHITE,RED);
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
            LCD_ShowNum(211,90,date_time_data.date_month,2,30,WHITE,RED);
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
            LCD_ShowNum(255,90,date_time_data.date_day,2,30,WHITE,RED);
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
            LCD_ShowNum(255,90,date_time_data.date_day,2,30,WHITE,RED);
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
            LCD_ShowNum(175,170,date_time_data.time_hour,2,30,WHITE,RED);
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
            LCD_ShowNum(175,170,date_time_data.time_hour,2,30,WHITE,RED);
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
            LCD_ShowNum(215,170,date_time_data.time_min,2,30,WHITE,RED);
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
            LCD_ShowNum(215,170,date_time_data.time_min,2,30,WHITE,RED);
            flag_dev.screen_key=0;
        }

//------------------------------------------CHAN DELAY----------------------------------------
    if(flag_dev.action_flag==DELAY&&flag_dev.anchor==1&&flag_dev.screen_key==RIGHT)
        {
            flag_dev.screen_key=0;

            chan_data.data1=chan_data.data1+1;
            if(chan_data.data1>999)
                {
                    chan_data.data1=0;
                }
            LCD_ShowNum(220,48,chan_data.data1,3,30,WHITE,RED);
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
            LCD_ShowNum(220,48,chan_data.data1,3,30,WHITE,RED);
            LCD_Show_3030_String(265,48,"s",BLACK);
            delay_ms(70);


        }
    else if(flag_dev.action_flag==DELAY&&flag_dev.anchor==2&&flag_dev.screen_key==RIGHT)
        {
            flag_dev.screen_key=0;
            chan_data.data2=chan_data.data2+1;
            if(chan_data.data2>999)
                {
                    chan_data.data2=0;
                }
            LCD_ShowNum(220,88,chan_data.data2,3,30,WHITE,RED);
            LCD_Show_3030_String(265,88,"s",BLACK);

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
            LCD_ShowNum(220,88,chan_data.data2,3,30,WHITE,RED);
            LCD_Show_3030_String(265,88,"s",BLACK);
            delay_ms(70);
        }
    else if(flag_dev.action_flag==DELAY&&flag_dev.anchor==3&&flag_dev.screen_key==RIGHT)
        {

            flag_dev.screen_key=0;
            chan_data.data3=chan_data.data3+1;
            if(chan_data.data3>999)
                {
                    chan_data.data3=0;
                }
            LCD_ShowNum(220,128,chan_data.data3,3,30,WHITE,RED);
            LCD_Show_3030_String(265,128,"s",BLACK);
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
            LCD_ShowNum(220,128,chan_data.data3,3,30,WHITE,RED);
            LCD_Show_3030_String(265,128,"s",BLACK);
            delay_ms(70);


        }
    else if(flag_dev.action_flag==DELAY&&flag_dev.anchor==4&&flag_dev.screen_key==RIGHT)
        {


            flag_dev.screen_key=0;

            chan_data.data4=chan_data.data4+1;
            if(chan_data.data4>999)
                {
                    chan_data.data4=0;
                }
            LCD_ShowNum(220,168,chan_data.data4,3,30,WHITE,RED);
            LCD_Show_3030_String(265,168,"s",BLACK);
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
            LCD_ShowNum(220,168,chan_data.data4,3,30,WHITE,RED);
            LCD_Show_3030_String(265,168,"s",BLACK);


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
            LCD_ShowNum(180,144,chan_dev.date_year,4,24,WHITE,RED);

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
            LCD_ShowNum(180,144,chan_dev.date_year,4,24,WHITE,RED);
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
            LCD_ShowNum(240,144,chan_dev.date_month,2,24,WHITE,RED);
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
            LCD_ShowNum(240,144,chan_dev.date_month,2,24,WHITE,RED);
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
            LCD_ShowNum(276,144,chan_dev.date_day,2,24,WHITE,RED);
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
            LCD_ShowNum(276,144,chan_dev.date_day,2,24,WHITE,RED);
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
            LCD_ShowNum(180,176,chan_dev.time_hour,2,24,WHITE,RED);

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
            LCD_ShowNum(180,176,chan_dev.time_hour,2,24,WHITE,RED);
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

            LCD_ShowNum(216,176,chan_dev.time_min,2,24,WHITE,RED);
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

            LCD_ShowNum(216,176,chan_dev.time_min,2,24,WHITE,RED);

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

            LCD_ShowNum(252,176,chan_dev.time_sec,2,24,WHITE,RED);


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
            LCD_ShowNum(252,176,chan_dev.time_sec,2,24,WHITE,RED);


            delay_ms(100);
        }





}

//保存数据操作
u32 Timer_[4];
void save_action()
{

    u32 i;
    u32 a,b,c;
	  
    u32 Current_Seccount;
    if(flag_dev.action_flag==DATE&&flag_dev.save_flag==SAVE)
        {

            flag_dev.save_flag=0;
            RTC_Set(date_time_data.date_year,date_time_data.date_month,date_time_data.date_day,date_time_data.time_hour,date_time_data.time_min,0);
            LCD_ShowNum(135,90,date_time_data.date_year,4,30,BLACK,WHITE);
            LCD_ShowNum(211,90,date_time_data.date_month,2,30,BLACK,WHITE);
            LCD_ShowNum(255,90,date_time_data.date_day,2,30,BLACK,WHITE);
            LCD_ShowNum(175,170,date_time_data.time_hour,2,30,BLACK,WHITE);
            LCD_ShowNum(215,170,date_time_data.time_min,2,30,BLACK,WHITE);

        }
    else if(flag_dev.action_flag==UV_OV&&flag_dev.save_flag==SAVE)
        {
            flag_dev.save_flag=0;

            //保存过压欠压数据

            LCD_ShowNum(235,68,uv_ov_data.rdv,2,30,BLACK,WHITE);
            LCD_Show_3030_String(270,68,"V",BLACK);
            LCD_ShowNum(160,108,uv_ov_data.uv,3,30,BLACK,WHITE);
            LCD_Show_3030_String(210,108,"V",BLACK);
            LCD_ShowNum(160,148,uv_ov_data.ov,3,30,BLACK,WHITE);
            LCD_Show_3030_String(210,148,"V",BLACK);
            flag_dev.anchor=2;

        }
    else if(flag_dev.action_flag==DELAY&&flag_dev.save_flag==SAVE)
        {
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

            LCD_ShowNum(220,48,chan_data.data1,3,30,BLACK,WHITE);
            LCD_Show_3030_String(265,48,"s",BLACK);
            LCD_ShowNum(220,88,chan_data.data2,3,30,BLACK,WHITE);
            LCD_Show_3030_String(265,88,"s",BLACK);
            LCD_ShowNum(220,128,chan_data.data3,3,30,BLACK,WHITE);
            LCD_Show_3030_String(265,128,"s",BLACK);
            LCD_ShowNum(220,168,chan_data.data4,3,30,BLACK,WHITE);
            LCD_Show_3030_String(265,168,"s",BLACK);


        }
    else if(flag_dev.action_flag==SWITCH&&flag_dev.save_flag==SAVE)
        {
            flag_dev.save_flag=0;


        }
    else if(flag_dev.action_flag==TIMER&&flag_dev.save_flag==SAVE)
        {
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

            if(flag_dev.activity_num==1)
                {
                    timer_dev_1=chan_dev;
                }
            else if(flag_dev.activity_num==2)
                {
                    timer_dev_2=chan_dev;
                }
            else if(flag_dev.activity_num==3)
                {
                    timer_dev_3=chan_dev;
                }

            timer_dev_1.SecCount=Sec_counter(timer_dev_1.date_year,timer_dev_1.date_month,timer_dev_1.date_day,timer_dev_1.time_hour,\
                                             timer_dev_1.time_min,timer_dev_1.time_sec);
            timer_dev_2.SecCount=Sec_counter(timer_dev_2.date_year,timer_dev_2.date_month,timer_dev_2.date_day,timer_dev_2.time_hour,\
                                             timer_dev_2.time_min,timer_dev_2.time_sec);
            timer_dev_3.SecCount=Sec_counter(timer_dev_3.date_year,timer_dev_3.date_month,timer_dev_3.date_day,timer_dev_3.time_hour,\
                                             timer_dev_3.time_min,timer_dev_3.time_sec);

            if(timer_dev_1.mode==LOOP)
                {
                    timer_dev_1.SecCount=Sec_counter(calendar.w_year,calendar.w_month,calendar.w_date,timer_dev_1.time_hour,\
                                                     timer_dev_1.time_min,timer_dev_1.time_sec);
                }
            if(timer_dev_2.mode==LOOP)
                {
                    timer_dev_2.SecCount=Sec_counter(calendar.w_year,calendar.w_month,calendar.w_date,timer_dev_2.time_hour,\
                                                     timer_dev_2.time_min,timer_dev_2.time_sec);
                }

            if(timer_dev_3.mode==LOOP)
                {
                    timer_dev_3.SecCount=Sec_counter(calendar.w_year,calendar.w_month,calendar.w_date,timer_dev_3.time_hour,\
                                                     timer_dev_3.time_min,timer_dev_3.time_sec);
                }

            a=timer_dev_1.SecCount;
            b=timer_dev_2.SecCount;
            c=timer_dev_3.SecCount;

            Current_Seccount=Sec_counter(calendar.w_year,calendar.w_month,calendar.w_date,calendar.hour,\
                                         calendar.min,calendar.sec);

            if(!(a==b)&&!(b==c)&&!(c==b)) //当三个数组不相等时候进入设置Alarm函数
                {
                    if(a<b)
                        {
                            if(b<c)
                                {
                                    //a<b<c

                                    Alarm_Sequence.Sec_MAX=timer_dev_3.SecCount;
                                    Alarm_Sequence.Sec_MID=timer_dev_2.SecCount;
                                    Alarm_Sequence.Sec_MIN=timer_dev_1.SecCount;
                                    Alarm_Sequence.MAX_Alarm_Dex=3;
                                    Alarm_Sequence.MID_Alarm_Dex=2;
                                    Alarm_Sequence.MIN_Alarm_Dex=1;



                                }
                            else//c<b
                                {
                                    if(a>c)
                                        {
                                            //c<a<b
                                            Alarm_Sequence.Sec_MAX=timer_dev_2.SecCount;
                                            Alarm_Sequence.Sec_MID=timer_dev_1.SecCount;
                                            Alarm_Sequence.Sec_MIN=timer_dev_3.SecCount;
                                            Alarm_Sequence.MAX_Alarm_Dex=2;
                                            Alarm_Sequence.MID_Alarm_Dex=1;
                                            Alarm_Sequence.MIN_Alarm_Dex=3;



                                        }
                                    else
                                        {
                                            //a<c<b

                                            Alarm_Sequence.Sec_MAX=timer_dev_2.SecCount;
                                            Alarm_Sequence.Sec_MID=timer_dev_3.SecCount;
                                            Alarm_Sequence.Sec_MIN=timer_dev_1.SecCount;
                                            Alarm_Sequence.MAX_Alarm_Dex=2;
                                            Alarm_Sequence.MID_Alarm_Dex=3;
                                            Alarm_Sequence.MIN_Alarm_Dex=1;

                                        }
                                }
                        }
                    else  //a>b
                        {
                            if(b>c)
                                {
                                    //a>b>c
                                    Alarm_Sequence.Sec_MAX=timer_dev_1.SecCount;
                                    Alarm_Sequence.Sec_MID=timer_dev_2.SecCount;
                                    Alarm_Sequence.Sec_MIN=timer_dev_3.SecCount;
                                    Alarm_Sequence.MAX_Alarm_Dex=1;
                                    Alarm_Sequence.MID_Alarm_Dex=2;
                                    Alarm_Sequence.MIN_Alarm_Dex=3;


                                }
                            else
                                {
                                    //c>b

                                    if(a>c) 	//a>c>b
                                        {
                                            Alarm_Sequence.Sec_MAX=timer_dev_1.SecCount;
                                            Alarm_Sequence.Sec_MID=timer_dev_3.SecCount;
                                            Alarm_Sequence.Sec_MIN=timer_dev_2.SecCount;
                                            Alarm_Sequence.MAX_Alarm_Dex=1;
                                            Alarm_Sequence.MID_Alarm_Dex=3;
                                            Alarm_Sequence.MIN_Alarm_Dex=2;



                                        }
                                    else
                                        {
                                            //c>a>b
                                            Alarm_Sequence.Sec_MAX=timer_dev_3.SecCount;
                                            Alarm_Sequence.Sec_MID=timer_dev_1.SecCount;
                                            Alarm_Sequence.Sec_MIN=timer_dev_2.SecCount;
                                            Alarm_Sequence.MAX_Alarm_Dex=3;
                                            Alarm_Sequence.MID_Alarm_Dex=1;
                                            Alarm_Sequence.MIN_Alarm_Dex=2;

                                        }

                                }

                        }


                    Timer_[0]=Alarm_Sequence.Sec_MIN;
                    Timer_[1]=Alarm_Sequence.Sec_MID;
                    Timer_[2]=Alarm_Sequence.Sec_MAX;

                    RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR | RCC_APB1Periph_BKP, ENABLE);	//使能PWR和BKP外设时钟
                    PWR_BackupAccessCmd(ENABLE);	//使能RTC和后备寄存器访问



                    if((Current_Seccount<Alarm_Sequence.Sec_MAX)&&(Current_Seccount>Alarm_Sequence.Sec_MID))
                        {

                            RTC_SetAlarm(Timer_[2]);	//设置RTC计数器的值
                            flag_dev.RTC_Alarm_Dex=Alarm_Sequence.MAX_Alarm_Dex;
                            
                        }
                    else if((Current_Seccount<Alarm_Sequence.Sec_MID)&&(Current_Seccount>Alarm_Sequence.Sec_MIN))
                        {

                            RTC_SetAlarm(Timer_[1]);	//设置RTC计数器的值
                            flag_dev.RTC_Alarm_Dex=Alarm_Sequence.MID_Alarm_Dex;
                           
                        }
                    else if(Current_Seccount<Alarm_Sequence.Sec_MIN)
                        {

                            flag_dev.RTC_Alarm_Dex=Alarm_Sequence.MIN_Alarm_Dex;
                            RTC_SetAlarm(Timer_[0]);	//设置RTC计数器的值
                           
                        }

                    RTC_WaitForLastTask();	//等待最近一次对RTC寄存器的写操作完成
                }
        }
    else if(flag_dev.action_flag==IP&&flag_dev.save_flag==SAVE)
        {
            flag_dev.save_flag=0;
            LCD_ShowNum(185,125,ip_data.ip,3,30,BLACK,WHITE);
        }
    else if(flag_dev.action_flag==PWD&&flag_dev.save_flag==SAVE)
        {
            flag_dev.save_flag=0;

        }
    //锁屏操作
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

/*
Timers
处理闹钟定时函数
*/

char Alarm_Chan[8]= {1,1,1,1,1,1,1,1};
void Alarm_Action()
{

    u8 i;
    _timer_dev timer_dev;//Timer结构体载体

    if(flag_dev.RTC_ALARM==1)
        {

            flag_dev.RTC_ALARM=0;

            if(flag_dev.RTC_Alarm_Dex==1)
                {
                 // LCD_Show_2424_String(20,100,"1",GREEN);
                    timer_dev=timer_dev_1;
                }
            else if(flag_dev.RTC_Alarm_Dex==2)
                {
               //    LCD_Show_2424_String(20,150,"2",GREEN);
                    timer_dev=timer_dev_2;

                }
            else if(flag_dev.RTC_Alarm_Dex==3)
                {
      //     LCD_Show_2424_String(20,200,"3",GREEN);
                    timer_dev=timer_dev_3;
                }

					 Alarm_Chan[0]=timer_dev.chan1;
				   Alarm_Chan[1]=timer_dev.chan2;
           Alarm_Chan[2]=timer_dev.chan3;
           Alarm_Chan[3]=timer_dev.chan4;
           Alarm_Chan[4]=timer_dev.chan5;
           Alarm_Chan[5]=timer_dev.chan6;
           Alarm_Chan[6]=timer_dev.chan7;
				   Alarm_Chan[7]=timer_dev.chan8;

            for(i=0; i<8; i++)
                {
                    if((Alarm_Chan[i]==1)&&(timer_dev.timer_state==CHAN_OPEN))
                        {
                            GPIO_SetBits(GPIOC,gpio_pin[i]);
                            delay_ms(10);
                        }
                    else if((Alarm_Chan[i]==0)&&(timer_dev.timer_state==CHAN_OPEN))
                        {
                            GPIO_ResetBits(GPIOC,gpio_pin[i]);

                        }

                }
             delay_ms(100);
            Channel_State_Show_();
        }





}

/*计算Timer对应的秒数*/

u32 Sec_counter(u16 syear,u8 smon,u8 sday,u8 hour,u8 min,u8 sec)
{
    u16 t;
    u32 seccount=0;
    if(syear<1970||syear>2099)return 1;
    for(t=1970; t<syear; t++)	//把所有年份的秒钟相加
        {
            if(Is_Leap_Year(t))seccount+=31622400;//闰年的秒钟数
            else seccount+=31536000;			  //平年的秒钟数
        }
    smon-=1;
    for(t=0; t<smon; t++)	 //把前面月份的秒钟数相加
        {
            seccount+=(u32)mon_table[t]*86400;//月份秒钟数相加
            if(Is_Leap_Year(syear)&&t==1)seccount+=86400;//闰年2月份增加一天的秒钟数
        }
    seccount+=(u32)(sday-1)*86400;//把前面日期的秒钟数相加
    seccount+=(u32)hour*3600;//小时秒钟数
    seccount+=(u32)min*60;	 //分钟秒钟数
    seccount+=sec;//最后的秒钟加上去

    return seccount;

}



