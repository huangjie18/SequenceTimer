#include "date_setting_page.h"
#include "lcd.h"
#include "gui.h"
#include "rtc.h"
#include "flag.h"
#include "touch.h"
#include "data.h"


extern _date_time_data date_time_data;
extern _flag_dev flag_dev;

void date_setting_page_activity()
{

    gui_draw_arcrectangle(95,45,225,75,4,1,BLUE,WHITE);

//	   gui_draw_arcrectangle(95,85,225,35,4,1,BLUE,WHITE);

    gui_draw_arcrectangle(95,125,225,75,4,1,BLUE,WHITE);
//	   gui_draw_arcrectangle(95,165,225,35,4,1,BLUE,WHITE);

    LCD_Show_3030_String(140,5,"DATE&TIME",WHITE);

    LCD_Show_3030_String(180,50,"DATE",WHITE);


    LCD_Show_3030_String(140,90,"    -  -  ",BLACK);

    LCD_Show_3030_String(180,130,"TIME",WHITE);
    LCD_Show_3030_String(175,170,"  :  ",BLACK);

    LCD_ShowNum(135,90,calendar.w_year,4,30,BLACK,WHITE);
    LCD_ShowNum(211,90,calendar.w_month,2,30,BLACK,WHITE);
    LCD_ShowNum(255,90,calendar.w_date,2,30,BLACK,WHITE);

    LCD_ShowNum(175,170,calendar.hour,2,30,BLACK,WHITE);
    LCD_ShowNum(215,170,calendar.min,2,30,BLACK,WHITE);

    date_time_data.date_year=calendar.w_year;
    date_time_data.date_month=calendar.w_month;
    date_time_data.date_day=calendar.w_date;
    date_time_data.time_hour=calendar.hour;
    date_time_data.time_min=calendar.min;
     gui_draw_arcrectangle(120,210,80,30,1,1,BLUE,BLUE);
		gui_draw_arcrectangle(125,212,70,28,1,1,WHITE,WHITE);
		LCD_Show_3030_String(130,210,"SAVE",BLUE);
}
void date_setting_page_action()
{




    if(flag_dev.action_flag==DATE&&(tp_dev.x[0]>135)&&(tp_dev.x[0]<195)&&(tp_dev.y[0]>90)&&(tp_dev.y[0]<120))
        {

            LCD_ShowNum(135,90,date_time_data.date_year,4,30,WHITE,RED);
            LCD_ShowNum(211,90,date_time_data.date_month,2,30,BLACK,WHITE);
            LCD_ShowNum(255,90,date_time_data.date_day,2,30,BLACK,WHITE);
            LCD_ShowNum(175,170,date_time_data.time_hour,2,30,BLACK,WHITE);
            LCD_ShowNum(215,170,date_time_data.time_min,2,30,BLACK,WHITE);

            flag_dev.anchor=1;


        }
    else if(flag_dev.action_flag==DATE&&(tp_dev.x[0]>211)&&(tp_dev.x[0]<241)&&(tp_dev.y[0]>90)&&(tp_dev.y[0]<120))
        {

            flag_dev.anchor=2;

            LCD_ShowNum(135,90,date_time_data.date_year,4,30,BLACK,WHITE);
            LCD_ShowNum(211,90,date_time_data.date_month,2,30,WHITE,RED);
            LCD_ShowNum(255,90,date_time_data.date_day,2,30,BLACK,WHITE);
            LCD_ShowNum(175,170,date_time_data.time_hour,2,30,BLACK,WHITE);
            LCD_ShowNum(215,170,date_time_data.time_min,2,30,BLACK,WHITE);



        }
    else if(flag_dev.action_flag==DATE&&(tp_dev.x[0]>255)&&(tp_dev.x[0]<285)&&(tp_dev.y[0]>90)&&(tp_dev.y[0]<120))
        {

            LCD_ShowNum(135,90,date_time_data.date_year,4,30,BLACK,WHITE);
            LCD_ShowNum(211,90,date_time_data.date_month,2,30,BLACK,WHITE);
            LCD_ShowNum(255,90,date_time_data.date_day,2,30,WHITE,RED);
            LCD_ShowNum(175,170,date_time_data.time_hour,2,30,BLACK,WHITE);
            LCD_ShowNum(215,170,date_time_data.time_min,2,30,BLACK,WHITE);

            flag_dev.anchor=3;
        }
    else if(flag_dev.action_flag==DATE&&(tp_dev.x[0]>175)&&(tp_dev.x[0]<205)&&(tp_dev.y[0]>170)&&(tp_dev.y[0]<200))
        {

            LCD_ShowNum(135,90,date_time_data.date_year,4,30,BLACK,WHITE);
            LCD_ShowNum(211,90,date_time_data.date_month,2,30,BLACK,WHITE);
            LCD_ShowNum(255,90,date_time_data.date_day,2,30,BLACK,WHITE);
            LCD_ShowNum(175,170,date_time_data.time_hour,2,30,WHITE,RED);
            LCD_ShowNum(215,170,date_time_data.time_min,2,30,BLACK,WHITE);

            flag_dev.anchor=4;
        }
    else if(flag_dev.action_flag==DATE&&(tp_dev.x[0]>215)&&(tp_dev.x[0]<245)&&(tp_dev.y[0]>170)&&(tp_dev.y[0]<200))
        {

            LCD_ShowNum(135,90,date_time_data.date_year,4,30,BLACK,WHITE);
            LCD_ShowNum(211,90,date_time_data.date_month,2,30,BLACK,WHITE);
            LCD_ShowNum(255,90,date_time_data.date_day,2,30,BLACK,WHITE);
            LCD_ShowNum(175,170,date_time_data.time_hour,2,30,BLACK,WHITE);
            LCD_ShowNum(215,170,date_time_data.time_min,2,30,WHITE,RED);
					 flag_dev.anchor=5;
        }




}





