#include "auz_page.h"
#include "gui.h"
#include "lcd.h"
#include "touch.h"
#include "flag.h"
#include "key_board.h"
extern _flag_dev flag_dev;
extern _m_tp_dev tp_dev;


void auz_page_activity()
{

    gui_draw_arcrectangle(95,109,225,30,1,1,WHITE,WHITE);
	  LCD_Show_2424_String(95,114,"******",BLACK);
    LCD_Show_3030_String(115,5,"AUTHORIZATION",WHITE);
    LCD_Show_2424_String(100,80,"AUZ CODE:",WHITE);
    gui_draw_arcrectangle(120,210,80,30,1,1,BLUE,BLUE);
}

void auz_page_action()
{


	if(flag_dev.action_flag==AUZ&&(tp_dev.x[0]>95)&&(tp_dev.x[0]<319)&&(tp_dev.y[0]>109)&&(tp_dev.y[0]<139)){
	
		
	flag_dev.action_flag=KEY_BOARD;	
	flag_dev.KEY_board_sta=1;	
  LCD_Fill(93,42,319,208,BLACK);
	key_board_activity();
  flag_dev.pwd_anchor=3;//设置为注册授权情况
		

	}
	
	
	
	
	

}

