#include "ip_setting_page.h"
#include "lcd.h"
#include "gui.h"
#include "data.h"
#include "flag.h"
#include "touch.h"

extern _ip_data ip_data;
extern _m_tp_dev tp_dev;//�����ṹ��
extern _flag_dev flag_dev;




void ip_setting_page_activity()
{

    gui_draw_arcrectangle(94,80,226,75,4,1,BLUE,WHITE);
	  if(flag_dev.langage==1){
    LCD_Show_3030_String(190,5,"IP",WHITE);
    LCD_Show_3030_String(140,85,"IP ADDRESS",WHITE);
	  }else{
	  ShowTwoChineseChar(188,11,26,27,24,WHITE);
	  ShowTwoChineseChar(160,85,23,25,24,WHITE);
	  ShowTwoChineseChar(208,85,26,27,24,WHITE);
		}
    LCD_ShowNum(185,125,ip_data.ip,3,30,BLACK,WHITE);
    gui_draw_arcrectangle(120,210,80,30,1,1,BLUE,BLUE);
	  //gui_draw_arcrectangle(125,212,70,28,1,1,WHITE,WHITE);
	  //LCD_Show_3030_String(130,210,"SAVE",BLUE);
}

void ip_setting_page_action()
{

 if(flag_dev.action_flag==IP&&(tp_dev.x[0]>95)&&(tp_dev.x[0]<319)&&(tp_dev.y[0]>80)&&(tp_dev.y[0]<155)){

     LCD_ShowNum(185,125,ip_data.ip,3,30,RED,WHITE);
	   flag_dev.anchor=1;
 }



}

