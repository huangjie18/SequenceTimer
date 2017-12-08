#include "pwd_page.h"
#include "gui.h"
#include "lcd.h"
#include "touch.h"
#include "flag.h"

extern _flag_dev flag_dev;
extern _m_tp_dev tp_dev;

void pwd_page_activity()
{

    gui_draw_arcrectangle(95,45,225,30,1,1, BLUE,BLUE);
    gui_draw_arcrectangle(95,109,225,30,1,1,WHITE,WHITE);
    gui_draw_arcrectangle(95,173,225,30,1,1,WHITE,WHITE);

    gui_draw_arcrectangle(160,48,158,24,1,1,WHITE,WHITE);
    LCD_DrawLtrigo(160,48,185,73,LEFT,BLUE);
    LCD_DrawLtrigo(292,48,317,73,RIGHT,BLUE);


    LCD_Show_3030_String(150,5,"PASSWORD",WHITE);
    LCD_Show_2424_String(95, 48,"TYPE",WHITE);
    LCD_Show_2424_String(100,80,"NEW PASSWORD:",WHITE);

    LCD_Show_2424_String(100,144,"RE-ENTER:",WHITE);

	  LCD_Show_2424_String(95,114,"******",BLACK);
		LCD_Show_2424_String(95,178,"******",BLACK);
	
	
	if(flag_dev.pwdtype==USER){
	  LCD_Show_2424_String(215, 48,"USER",BLACK);
	}else{
	
	  LCD_Show_2424_String(190, 48,"SETTINGS",BLACK);
	}
  
	   
   gui_draw_arcrectangle(120,210,80,30,1,1,BLUE,BLUE);

}

/*页面上的动作函数*/
void pwd_page_action()
{
	
	if(flag_dev.action_flag==PWD&&(tp_dev.x[0]>160)&&(tp_dev.x[0]<185)&&(tp_dev.y[0]>48)&&(tp_dev.y[0]<73)){
	  
	  if(flag_dev.pwdtype==SETTINGS){
		gui_draw_arcrectangle(190,48,100,24,1,1,WHITE,WHITE);
		LCD_Show_2424_String(215, 48,"USER",BLACK);
		}
		
		 flag_dev.pwdtype=USER;		
	}else if(flag_dev.action_flag==PWD&&(tp_dev.x[0]>292)&&(tp_dev.x[0]<317)&&(tp_dev.y[0]>48)&&(tp_dev.y[0]<73)){
	
	if(flag_dev.pwdtype==USER){
	 gui_draw_arcrectangle(190,48,100,24,1,1,WHITE,WHITE);
	 LCD_Show_2424_String(190, 48,"SETTINGS",BLACK);
	}
 	 flag_dev.pwdtype=SETTINGS;
	}
  else if(flag_dev.action_flag==PWD&&(tp_dev.x[0]>95)&&(tp_dev.x[0]<319)&&(tp_dev.y[0]>109)&&(tp_dev.y[0]<139)){
	
		
	flag_dev.action_flag=KEY_BOARD;	
	flag_dev.KEY_board_sta=1;	
  LCD_Fill(93,42,319,208,BLACK);
	key_board_activity();
	flag_dev.pwd_anchor=1;
		

	}else if(flag_dev.action_flag==PWD&&(tp_dev.x[0]>95)&&(tp_dev.x[0]<319)&&(tp_dev.y[0]>173)&&(tp_dev.y[0]<200)){
	
	flag_dev.action_flag=KEY_BOARD;
	flag_dev.KEY_board_sta=1;
	LCD_Fill(93,42,319,208,BLACK);
  key_board_activity();
	flag_dev.pwd_anchor=2;
	}

}
