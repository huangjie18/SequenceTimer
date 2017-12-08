#include "reset_page.h"
#include "lcd.h"
#include "gui.h"
#include "flag.h"
#include "touch.h"
#include "data.h"
#include "data.h"


extern _date_time_data date_time_data;
extern _flag_dev flag_dev;



void reset_page_activity()
{

    gui_draw_arcrectangle(95,80,225,75,1,1,BLUE,WHITE);
    gui_draw_arcrectangle(98,125,50,30,1,1,BLUE,BLUE);
    gui_draw_arcrectangle(268,125,50,30,1,1,BLUE,BLUE);

    LCD_Show_3030_String(170,5,"RESET",WHITE);


    LCD_Show_2424_String(110,85,"Restore Default ?",WHITE);
    LCD_Show_3030_String(100,125,"Yes",WHITE);
    LCD_Show_3030_String(280,125,"No",WHITE);
    	gui_draw_arcrectangle(120,210,80,30,1,1,BLUE,BLUE);
}


void reset_page_action()
{

					if(flag_dev.action_flag==RESET&&(tp_dev.x[0]>98)&&(tp_dev.x[0]<148)&&(tp_dev.y[0]>125)&&(tp_dev.y[0]<155)){
				
						
						
						                Reset_deflaut();
				
				                    flag_dev.activity_flag=HOME;
                            flag_dev.action_flag=HOME;
                            flag_dev.screen_flag=HOME;//不支持长按
													  flag_dev.anchor=0;
													  
				}else if(flag_dev.action_flag==RESET&&(tp_dev.x[0]>268)&&(tp_dev.x[0]<318)&&(tp_dev.y[0]>125)&&(tp_dev.y[0]<155)){
				
				                    flag_dev.activity_flag=HOME;
                            flag_dev.action_flag=HOME;
                            flag_dev.screen_flag=HOME;//不支持长按
													  flag_dev.anchor=0;
													  
				}



}



