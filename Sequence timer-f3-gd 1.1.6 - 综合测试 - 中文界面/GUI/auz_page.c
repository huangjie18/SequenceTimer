#include "auz_page.h"
#include "gui.h"
#include "lcd.h"
#include "touch.h"
#include "flag.h"
#include "key_board.h"
#include "24cxx.h"
#include "delay.h"
extern _flag_dev flag_dev;
extern _m_tp_dev tp_dev;


void auz_page_activity()
{
    if(flag_dev.langage==1)
        {
            LCD_Show_3030_String(115,5,"AUTHORIZATION",WHITE);
        }
    else
        {
            ShowTwoChineseChar(160,11,55,56,24,WHITE);
            ShowTwoChineseChar(208,11,57,58,24,WHITE);
        }
				
    gui_draw_arcrectangle(94,43,226,40,4,1,BLUE,BLUE);
		if(flag_dev.IsShowAUZNumset==1){		
    gui_draw_arcrectangle(94,85,226,40,4,1,BLUE,BLUE);
    gui_draw_arcrectangle(94,127,226,40,4,1,BLUE,BLUE);
    gui_draw_arcrectangle(94,169,226,38,4,1,BLUE,BLUE);
		}else{
		gui_draw_arcrectangle(94,85,226,40,4,1,GRAY,GRAY);
    gui_draw_arcrectangle(94,127,226,40,4,1,GRAY,GRAY);
    gui_draw_arcrectangle(94,169,226,38,4,1,GRAY,GRAY);	
		}	
			
    gui_draw_arcrectangle(202,48, 117-2,30,4,1,WHITE,WHITE);
    gui_draw_arcrectangle(202,90, 117-2,30,4,1,WHITE,WHITE);
    gui_draw_arcrectangle(202,131,117-2,30,4,1,WHITE,WHITE);
    gui_draw_arcrectangle(202,173,117-2,30,4,1,WHITE,WHITE);
				
    if(flag_dev.langage==1)
        {
            LCD_Show_2424_String(100,48+2,"PASSCODE",WHITE);
            LCD_Show_2424_String(100,88+4,"CURRENT",WHITE);
            LCD_Show_2424_String(100,128+5,"SURPLUS",WHITE);
            LCD_Show_2424_String(100,168+7,"SET CNT",WHITE);
        }
    else
        {
            ShowTwoChineseChar(124,48+2,41,42,24,WHITE);
            ShowTwoChineseChar(100,88+4,59,60,24,WHITE);
            ShowTwoChineseChar(148,88+4,61,62,24,WHITE);
            ShowTwoChineseChar(100,128+5,63,64,24,WHITE);
            ShowTwoChineseChar(148,128+5,61,62,24,WHITE);
            ShowTwoChineseChar(100,168+7,23,24,24,WHITE);
            ShowTwoChineseChar(148,168+7,61,62,24,WHITE);
        }
				
    LCD_Show_2424_String(222,52,"******",BLACK);
    if(AuzCnt.SetCnt<101)
        {
            if(flag_dev.langage==1){
            LCD_ShowNum(242,92,AuzCnt.CurrentCnt,3,24,BLACK,WHITE);
            LCD_ShowNum(242,133,AuzCnt.SurplusCnt,3,24,BLACK,WHITE);
            LCD_ShowNum(242,175,AuzCnt.SetCnt,3,24,BLACK,WHITE);
						}else{
						LCD_ShowNum(242,92,AuzCnt.CurrentCnt,3,24,GRAY,WHITE);
            LCD_ShowNum(242,133,AuzCnt.SurplusCnt,3,24,GRAY,WHITE);
            LCD_ShowNum(242,175,AuzCnt.SetCnt,3,24,GRAY,WHITE);
						}
					
        }
    else
        {
           if(flag_dev.IsShowAUZNumset==1){
            LCD_Show_2424_String(244,94,"***",BLACK);
            LCD_Show_2424_String(244,135,"***",BLACK);
					 }else{
					 LCD_Show_2424_String(244,94,"***",GRAY);
            LCD_Show_2424_String(244,135,"***",GRAY);
					 }
            if(flag_dev.langage==1)
                {
									  if(flag_dev.IsShowAUZNumset==1)
                    LCD_Show_2424_String(204,175,"PERMANENT",BLACK);
									  else
										LCD_Show_2424_String(204,175,"PERMANENT",GRAY);	
                }
            else
                {									
									  if(flag_dev.IsShowAUZNumset==1){
                    ShowTwoChineseChar(210,175,71,72,24,BLACK);
                    ShowTwoChineseChar(258,175,73,45,24,BLACK);
										}else{
											
										ShowTwoChineseChar(210,175,71,72,24,GRAY);
                    ShowTwoChineseChar(258,175,73,45,24,GRAY);
										}
									
                }
        }
    gui_draw_arcrectangle(120,210,80,30,1,1,BLUE,BLUE);
		if(flag_dev.IsShowAUZNumset==1)		
    gui_draw_arcrectangle(125,212,70,28,1,1,WHITE,WHITE);
		else		
		gui_draw_arcrectangle(125,212,70,28,1,1,GRAY,GRAY);	
    if(flag_dev.langage==0){
			 if(flag_dev.IsShowAUZNumset==1)
        ShowTwoChineseChar(135,213,10,11,24,BLACK);
			 else
				ShowTwoChineseChar(135,213,10,11,24,WHITE); 
    }else{
			 if(flag_dev.IsShowAUZNumset==1)
        LCD_Show_3030_String(130,210,"SAVE",BLACK);
			 else
				 LCD_Show_3030_String(130,210,"SAVE",WHITE);
		}
    AuzCntData=AuzCnt;
}

void auz_page_action()
{
        if(flag_dev.action_flag==PWD||flag_dev.action_flag==HOME||flag_dev.action_flag==UV_OV)
        flag_dev.IsShowAUZNumset=1;//取消显示更改使用次数
    if(flag_dev.action_flag==AUZ&&(tp_dev.x[0]>95)&&(tp_dev.x[0]<319)&&(tp_dev.y[0]>43)&&(tp_dev.y[0]<83))
        {
            flag_dev.action_flag=KEY_BOARD;
            flag_dev.KEY_board_sta=1;
            LCD_Fill(93,42,319,208,BLACK);
            key_board_activity();
            flag_dev.pwd_anchor=3;//设置为注册授权情况
        }
    else if(flag_dev.action_flag==AUZ&&(tp_dev.x[0]>95)&&(tp_dev.x[0]<319)&&(tp_dev.y[0]>85)&&(tp_dev.y[0]<125))
        {

        }
    else if(flag_dev.action_flag==AUZ&&(tp_dev.x[0]>95)&&(tp_dev.x[0]<319)&&(tp_dev.y[0]>127)&&(tp_dev.y[0]<167))
        {

        }
    else if(flag_dev.action_flag==AUZ&&(tp_dev.x[0]>95)&&(tp_dev.x[0]<319)&&(tp_dev.y[0]>169)&&(tp_dev.y[0]<207))
        {
					if(flag_dev.IsShowAUZNumset==1){
            if(AuzCnt.SetCnt<101)
                {
                    LCD_ShowNum(242,92,AuzCnt.CurrentCnt,3,24,BLACK,WHITE);
                    LCD_ShowNum(242,133,AuzCnt.SurplusCnt,3,24,BLACK,WHITE);
                    LCD_ShowNum(242,175,AuzCnt.SetCnt,3,24,RED,WHITE);
                }
            else
                {
                    LCD_Show_2424_String(244,94,"***",BLACK);
                    LCD_Show_2424_String(244,135,"***",BLACK);
                    if(flag_dev.langage==1)
                        {
                            LCD_Show_2424_String(204,175,"PERMANENT",RED);
                        }
                    else
                        {
                            ShowTwoChineseChar(210,175,71,72,24,RED);
                            ShowTwoChineseChar(258,175,73,45,24,RED);
                        }
                }
            flag_dev.anchor=1;
							}
								
        }



}
void IsShowAUZPage()
{
    static u8 cnt;
    static u8 cntx;
    
    if(flag_dev.ISMENU==1)
        {
            cnt++;
            if(cnt>100)
                {
                    flag_dev.ISSHOWAUZ=1;
                    cnt=0;
                 
                    if(flag_dev.action_flag==PWD){
											  gui_draw_arcrectangle(0,84, 90,40,3,1, BLUE,BLUE);
											 if(flag_dev.langage==1)
                        LCD_Show_3030_String(25,89,"AUZ",WHITE);
                       else
                        ShowTwoChineseChar(15,89,30,31,30,WHITE);
										}
                }
        }
				
    if(flag_dev.ISMENU==0)
        {
            if(cntx>10)
                {
                    cnt=0;
                    cntx=0;
                }
            cntx++;
        }
				
    flag_dev.ISMENU=0;
}
/*过了授权日期自动弹出窗口*/
void AuthorizationWIndow()
{

    gui_draw_arcrectangle(50,109-30,222,30,1,1,WHITE,WHITE);
    LCD_Show_2424_String(50,80-30,"AUZ CODE:",WHITE);

    gui_draw_arcrectangle(94-40-4, 114, 55,30,1,1, GRAY,GRAY);
    gui_draw_arcrectangle(150-40-4,114, 55,30,1,1, GRAY,GRAY);
    gui_draw_arcrectangle(206-40-4,114, 55,30,1,1, GRAY,GRAY);
    gui_draw_arcrectangle(262-40-4,114, 55,30,1,1, GRAY,GRAY);

    gui_draw_arcrectangle(94-40-4, 146, 55,30,1,1, GRAY,GRAY);
    gui_draw_arcrectangle(150-40-4,146, 55,30,1,1, GRAY,GRAY);
    gui_draw_arcrectangle(206-40-4,146, 55,30,1,1, GRAY,GRAY);
    gui_draw_arcrectangle(262-40-4,146, 55,30,1,1, GRAY,GRAY);

    gui_draw_arcrectangle(94-40-4, 178, 55,30,1,1,GRAY,GRAY);
    gui_draw_arcrectangle(150-40-4,178, 55,30,1,1,GRAY,GRAY);
    gui_draw_arcrectangle(206-40-4,178, 55,30,1,1,GRAY,GRAY);
    gui_draw_arcrectangle(262-40-4,178, 55,30,1,1,GRAY,GRAY);


    LCD_Show_3030_String(114-40-4,114,"1",BLACK);
    LCD_Show_3030_String(170-40-4,114,"2",BLACK);
    LCD_Show_3030_String(226-40-4,114,"3",BLACK);
    LCD_Show_3030_String(282-40-4,114,"0",BLACK);

    LCD_Show_3030_String(114-40-4,146,"4",BLACK);
    LCD_Show_3030_String(170-40-4,146,"5",BLACK);
    LCD_Show_3030_String(226-40-4,146,"6",BLACK);
    LCD_Show_2424_String(272-40-4,148,"DEL",BLACK);

    LCD_Show_3030_String(114-40-4,178,"7",BLACK);
    LCD_Show_3030_String(170-40-4,178,"8",BLACK);
    LCD_Show_3030_String(226-40-4,178,"9",BLACK);
    LCD_Show_2424_String(277-40-4,180,"OK",BLACK);


}
/*键盘动作*/
void AuthorizationgAction()
{
    if(flag_dev.action_flag==KEY_BOARD)
        {

            if((tp_dev.x[0]>94-40-4)&&(tp_dev.x[0]<149-40-4)&&(tp_dev.y[0]>114)&&(tp_dev.y[0]<144))
                {

                    flag_dev.key_board_num=1;
                    flag_dev.key_board_state=1;
                }
            else if((tp_dev.x[0]>150-40-4)&&(tp_dev.x[0]<205-40-4)&&(tp_dev.y[0]>114)&&(tp_dev.y[0]<144))
                {


                    flag_dev.key_board_num=2;
                    flag_dev.key_board_state=1;
                }
            else if((tp_dev.x[0]>206-40-4)&&(tp_dev.x[0]<261-40-4)&&(tp_dev.y[0]>114)&&(tp_dev.y[0]<144))
                {

                    flag_dev.key_board_state=1;
                    flag_dev.key_board_num=3;
                }
            else if((tp_dev.x[0]>262-40-4)&&(tp_dev.x[0]<317-40-4)&&(tp_dev.y[0]>114)&&(tp_dev.y[0]<144))
                {

                    flag_dev.key_board_state=1;
                    flag_dev.key_board_num=0;
                }
            else if((tp_dev.x[0]>94-40-4)&&(tp_dev.x[0]<149-40-4)&&(tp_dev.y[0]>146)&&(tp_dev.y[0]<176))
                {

                    flag_dev.key_board_state=1;
                    flag_dev.key_board_num=4;
                }
            else if((tp_dev.x[0]>150-40-4)&&(tp_dev.x[0]<205-40-4)&&(tp_dev.y[0]>146)&&(tp_dev.y[0]<176))
                {

                    flag_dev.key_board_state=1;
                    flag_dev.key_board_num=5;
                }
            else if((tp_dev.x[0]>206-40-4)&&(tp_dev.x[0]<261-40-4)&&(tp_dev.y[0]>146)&&(tp_dev.y[0]<176))
                {
                    flag_dev.key_board_state=1;

                    flag_dev.key_board_num=6;
                }
            else if((tp_dev.x[0]>262-40-4)&&(tp_dev.x[0]<317-40-4)&&(tp_dev.y[0]>146)&&(tp_dev.y[0]<176))
                {

                    flag_dev.key_board_state=1;
                    flag_dev.key_board_num=DEL;
                }
            else if((tp_dev.x[0]>94-40-4)&&(tp_dev.x[0]<149-40-4)&&(tp_dev.y[0]>178)&&(tp_dev.y[0]<208))
                {

                    flag_dev.key_board_state=1;
                    flag_dev.key_board_num=7;
                }
            else if((tp_dev.x[0]>150-40-4)&&(tp_dev.x[0]<205-40-4)&&(tp_dev.y[0]>178)&&(tp_dev.y[0]<208))
                {

                    flag_dev.key_board_state=1;
                    flag_dev.key_board_num=8;
                }
            else if((tp_dev.x[0]>206-40-4)&&(tp_dev.x[0]<261-40-4)&&(tp_dev.y[0]>178)&&(tp_dev.y[0]<208))
                {

                    flag_dev.key_board_state=1;
                    flag_dev.key_board_num=9;
                }
            else if((tp_dev.x[0]>262-40-4)&&(tp_dev.x[0]<317-40-4)&&(tp_dev.y[0]>178)&&(tp_dev.y[0]<208))
                {
                    flag_dev.key_board_state=1;
                    flag_dev.key_board_num=OK;
                }
        }
}
void Authorization()
{

    /*免费使用50次数,超过弹出窗口,已注册则可以永久使用*/

    if((AuzCnt.CurrentCnt==AuzCnt.SetCnt)&&flag_dev.ISAUZ!=1)
        {
            flag_dev.action_flag=KEY_BOARD;
            flag_dev.KEY_board_sta=1;
            flag_dev.pwd_anchor=4;
            AuthorizationWIndow();
            while(flag_dev.ISAUZ!=1)
                {
                    tp_dev.scan(0);
                    if(tp_dev.sta&TP_PRES_DOWN)
                        {
                            delay_ms(10);//消抖
                            if(tp_dev.sta&TP_PRES_DOWN)
                                {
                                    AuthorizationgAction();
                                }
                        }
                    key_board_event();

                }
        }

}