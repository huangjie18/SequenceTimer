#include "timer_page.h"
#include "gui.h"
#include "lcd.h"
#include "data.h"
#include "flag.h"
#include "touch.h"
#include "delay.h"
#include "rtc.h"

extern _m_tp_dev tp_dev;//触屏结构体
extern _flag_dev flag_dev;
extern int gpio_pin[8];
void timer_page_activity()
{


    gui_draw_arcrectangle(95,45,225,30,1,1,BLUE,BLUE);
    gui_draw_arcrectangle(95,77,225,30, 1,1,BLUE,BLUE);
    gui_draw_arcrectangle(95,109,225,30,1,1,BLUE,BLUE);
    gui_draw_arcrectangle(95,141,225,30,1,1,BLUE,BLUE);
    gui_draw_arcrectangle(95,173,225,32,1,1,BLUE,BLUE);

    gui_draw_arcrectangle(160,80,158,24,1,1,WHITE,WHITE);
    gui_draw_arcrectangle(160,48,158,24, 1,1,WHITE,WHITE);
    gui_draw_arcrectangle(160,112,158,24,1,1,WHITE,WHITE);
    gui_draw_arcrectangle(160,144,158,24,1,1,WHITE,WHITE);
    gui_draw_arcrectangle(160,176,158,24,1,1,WHITE,WHITE);
   
    LCD_DrawLtrigo(95,0,125,40,LEFT,WHITE);
    LCD_DrawLtrigo(290,0,319,40,RIGHT,WHITE);
    LCD_DrawLtrigo(160,48,185,73,LEFT,BLUE);
    LCD_DrawLtrigo(292,48,317,73,RIGHT,BLUE);
    LCD_DrawLtrigo(160,112,185,137,LEFT,BLUE);
    LCD_DrawLtrigo(292,112,317,137,RIGHT,BLUE);
    if(flag_dev.langage==1){
    LCD_Show_3030_String(170,5,"TIMER1",WHITE);
    LCD_Show_2424_String(95, 48,"STATE",WHITE);
    LCD_Show_2424_String(95,80,"CHAN",WHITE);
    LCD_Show_2424_String(95,112,"MODE",WHITE);
    LCD_Show_2424_String(95,144,"DATE",WHITE);
    LCD_Show_2424_String(95,176,"TIME",WHITE);
    }else{
    ShowTwoChineseChar(185,11,12,13,24,WHITE);
    LCD_Show_2424_String(233,14,"1",WHITE);
    ShowTwoChineseChar(102,48,47,48,24,WHITE);
    ShowTwoChineseChar(102,80,0,1,24,WHITE);
    ShowTwoChineseChar(102,112,49,50,24,WHITE);
    ShowTwoChineseChar(102,144,8,9,24,WHITE);
    ShowTwoChineseChar(102,176,3,16,24,WHITE);
    }
//  LCD_Show_2424_String(190, 48,"PROHIBIT",BLACK);
//	LCD_Show_2424_String(185, 80, "CHAN OPEN",BLACK);
//  LCD_Show_2424_String(180, 80,"CHAN CLOSE",BLACK);
//  LCD_Show_2424_String(220,112,"LOOP",BLACK);
    LCD_Show_2424_String(180,144,"    -  -  ",BLACK);
    LCD_Show_2424_String(180,176,"  :  :  ",BLACK);

    chan_dev=timer_dev_1;//数据赋值给页面变量
    timer_data_flash();

    gui_draw_arcrectangle(120,210,80,30,1,1,BLUE,BLUE);
    gui_draw_arcrectangle(125,212,70,28,1,1,WHITE,WHITE);
		 if(flag_dev.langage==1)
     LCD_Show_3030_String(130,210,"SAVE",BLACK);
		 else
    ShowTwoChineseChar(135,213,10,11,24,BLACK);
    flag_dev.activity_num=1;//标记为第一个页面
}
/*TIMER页面触屏操作*/
void timer_page_action()
{
    if(flag_dev.action_flag==TIMER&&(tp_dev.x[0]>95)&&(tp_dev.x[0]<125)&&(tp_dev.y[0]>0)&&(tp_dev.y[0]<40))
        {
            switch(flag_dev.activity_num)
                {
                case ISTIMER1:
                    LCD_Fill(170,0,280,35,RED);
								    if(flag_dev.langage==1)
                    	LCD_Show_3030_String(170,5,"TIMER10",WHITE);
								    else{ 
                    ShowTwoChineseChar(185,11,12,13,24,WHITE);
                    LCD_Show_2424_String(233,12,"10",WHITE);
										}
                    flag_dev.activity_num=10;
                    chan_dev=timer_dev_10;
                    break;
                case ISTIMER10:
                    LCD_Fill(170,0,280,35,RED);
								    if(flag_dev.langage==1)
                    	LCD_Show_3030_String(170,5,"TIMER9",WHITE);
								    else {
                    ShowTwoChineseChar(185,11,12,13,24,WHITE);
                    LCD_Show_2424_String(233,12,"9",WHITE);
										}
                    flag_dev.activity_num=9;
                    chan_dev=timer_dev_9;
                    break;
                case ISTIMER9:
                    LCD_Fill(170,0,280,35,RED);
								    if(flag_dev.langage==1)
                    	LCD_Show_3030_String(170,5,"TIMER8",WHITE);
								    else{ 
                    ShowTwoChineseChar(185,11,12,13,24,WHITE);
                    LCD_Show_2424_String(233,12,"8",WHITE);
										}
                    flag_dev.activity_num=8;
                    chan_dev=timer_dev_8;
                    break;
                case ISTIMER8:
                    LCD_Fill(170,0,280,35,RED);
								    if(flag_dev.langage==1)
                    	LCD_Show_3030_String(170,5,"TIMER7",WHITE);
								    else {
                    ShowTwoChineseChar(185,11,12,13,24,WHITE);
                    LCD_Show_2424_String(233,12,"7",WHITE);
										}
                    flag_dev.activity_num=7;
                    chan_dev=timer_dev_7;
                    break;
                case ISTIMER7:
                    LCD_Fill(170,0,280,35,RED);
								    if(flag_dev.langage==1)
                    	LCD_Show_3030_String(170,5,"TIMER6",WHITE);
								    else {
                    ShowTwoChineseChar(185,11,12,13,24,WHITE);
                    LCD_Show_2424_String(233,12,"6",WHITE);
										}
                    flag_dev.activity_num=6;
                    chan_dev=timer_dev_6;
                    break;
                case ISTIMER6:
                    LCD_Fill(170,0,280,35,RED);
								    if(flag_dev.langage==1)
                    	LCD_Show_3030_String(170,5,"TIMER5",WHITE);
								    else {
                    ShowTwoChineseChar(185,11,12,13,24,WHITE);
                    LCD_Show_2424_String(233,12,"5",WHITE);
										}
                    flag_dev.activity_num=5;
                    chan_dev=timer_dev_5;
                    break;
                case ISTIMER5:
                    LCD_Fill(170,0,280,35,RED);
								    if(flag_dev.langage==1)
                    	LCD_Show_3030_String(170,5,"TIMER4",WHITE);
								    else {
                    ShowTwoChineseChar(185,11,12,13,24,WHITE);
                    LCD_Show_2424_String(233,12,"4",WHITE);
										}
                    flag_dev.activity_num=4;
                    chan_dev=timer_dev_4;
                    break;
                case ISTIMER4:
                    LCD_Fill(170,0,280,35,RED);
								    if(flag_dev.langage==1)
                    	LCD_Show_3030_String(170,5,"TIMER3",WHITE);
								    else {
                    ShowTwoChineseChar(185,11,12,13,24,WHITE);
                    LCD_Show_2424_String(233,12,"3",WHITE);
										}
                    flag_dev.activity_num=3;
                    chan_dev=timer_dev_3;
                    break;
                case ISTIMER3:
                    LCD_Fill(170,0,280,35,RED);
								    if(flag_dev.langage==1)
                    	LCD_Show_3030_String(170,5,"TIMER2",WHITE);
								    else {
                    ShowTwoChineseChar(185,11,12,13,24,WHITE);
                    LCD_Show_2424_String(233,12,"2",WHITE);
										}
                    flag_dev.activity_num=2;
                    chan_dev=timer_dev_2;
                    break;
                case ISTIMER2:
                    LCD_Fill(170,0,280,35,RED);
								    if(flag_dev.langage==1)
                    	LCD_Show_3030_String(170,5,"TIMER1",WHITE);
								    else {
                    ShowTwoChineseChar(185,11,12,13,24,WHITE);
                    LCD_Show_2424_String(233,12,"1",WHITE);
										}
                    flag_dev.activity_num=1;
                    chan_dev=timer_dev_1;
                    break;
                }
            timer_data_flash();
            delay_ms(300);
        }
    else if(flag_dev.action_flag==TIMER&&(tp_dev.x[0]>290)&&(tp_dev.x[0]<319)&&(tp_dev.y[0]>0)&&(tp_dev.y[0]<40))
        {
            switch(flag_dev.activity_num)
                {
                case ISTIMER10:
                    LCD_Fill(170,0,280,35,RED);
								    if(flag_dev.langage==1)
                    	LCD_Show_3030_String(170,5,"TIMER1",WHITE);
								    else {
                    ShowTwoChineseChar(185,11,12,13,24,WHITE);
                    LCD_Show_2424_String(233,12,"1",WHITE);
										}
                    flag_dev.activity_num=1;
                    chan_dev=timer_dev_1;
                    break;
                case ISTIMER1:
                    LCD_Fill(170,0,280,35,RED);
								    if(flag_dev.langage==1)
                    	LCD_Show_3030_String(170,5,"TIMER2",WHITE);
								    else {
                    ShowTwoChineseChar(185,11,12,13,24,WHITE);
                    LCD_Show_2424_String(233,12,"2",WHITE);
										}
                    flag_dev.activity_num=2;
                    chan_dev=timer_dev_2;
                    break;
                case ISTIMER2:
                    LCD_Fill(170,0,280,35,RED);
								    if(flag_dev.langage==1)
                    	LCD_Show_3030_String(170,5,"TIMER3",WHITE);
								    else {
                    ShowTwoChineseChar(185,11,12,13,24,WHITE);
                    LCD_Show_2424_String(233,12,"3",WHITE);
										}
                    flag_dev.activity_num=3;
                    chan_dev=timer_dev_3;
                    break;
                case ISTIMER3:
                    LCD_Fill(170,0,280,35,RED);
								    if(flag_dev.langage==1)
                    	LCD_Show_3030_String(170,5,"TIMER4",WHITE);
								    else {
                    ShowTwoChineseChar(185,11,12,13,24,WHITE);
                    LCD_Show_2424_String(233,12,"4",WHITE);
										}
                    flag_dev.activity_num=4;
                    chan_dev=timer_dev_4;
                    break;
                case ISTIMER4:
                    LCD_Fill(170,0,280,35,RED);
								    if(flag_dev.langage==1)
                    	LCD_Show_3030_String(170,5,"TIMER5",WHITE);
								    else {
                    ShowTwoChineseChar(185,11,12,13,24,WHITE);
                    LCD_Show_2424_String(233,12,"5",WHITE);
										}
                    flag_dev.activity_num=5;
                    chan_dev=timer_dev_5;
                    break;
                case ISTIMER5:
                    LCD_Fill(170,0,280,35,RED);
								    if(flag_dev.langage==1)
                    	LCD_Show_3030_String(170,5,"TIMER6",WHITE);
								    else {
                    ShowTwoChineseChar(185,11,12,13,24,WHITE);
                    LCD_Show_2424_String(233,12,"6",WHITE);
										}
                    flag_dev.activity_num=6;
                    chan_dev=timer_dev_6;
                    break;
                case ISTIMER6:
                    LCD_Fill(170,0,280,35,RED);
								    if(flag_dev.langage==1)
                    	LCD_Show_3030_String(170,5,"TIMER7",WHITE);
								    else {
                    ShowTwoChineseChar(185,11,12,13,24,WHITE);
                    LCD_Show_2424_String(233,12,"7",WHITE);
										}
                    flag_dev.activity_num=7;
                    chan_dev=timer_dev_7;
                    break;
                case ISTIMER7:
                    LCD_Fill(170,0,280,35,RED);
								    if(flag_dev.langage==1)
                    	LCD_Show_3030_String(170,5,"TIMER8",WHITE);
								    else {
                    ShowTwoChineseChar(185,11,12,13,24,WHITE);
                    LCD_Show_2424_String(233,12,"8",WHITE);
										}
                    flag_dev.activity_num=8;
                    chan_dev=timer_dev_8;
                    break;
                case ISTIMER8:
                    LCD_Fill(170,0,280,35,RED);
								    if(flag_dev.langage==1)
                    	LCD_Show_3030_String(170,5,"TIMER9",WHITE);
								    else {
                    ShowTwoChineseChar(185,11,12,13,24,WHITE);
                    LCD_Show_2424_String(233,12,"9",WHITE);
										}
                    flag_dev.activity_num=9;
                    chan_dev=timer_dev_9;
                    break;
                case ISTIMER9:
                    LCD_Fill(170,0,280,35,RED);
								    if(flag_dev.langage==1)
                    	LCD_Show_3030_String(170,5,"TIMER10",WHITE);
								    else {
                    ShowTwoChineseChar(185,11,12,13,24,WHITE);
                    LCD_Show_2424_String(233,12,"10",WHITE);
										}
                    flag_dev.activity_num=10;
                    chan_dev=timer_dev_10;
                    break;
                }

            timer_data_flash();
            delay_ms(300);
        }
    else if(flag_dev.action_flag==TIMER&&(tp_dev.x[0]>165)&&(tp_dev.x[0]<177)&&(tp_dev.y[0]>80)&&(tp_dev.y[0]<105))
        {
            if(chan_dev.chan1!=1)
                {
                    LCD_Show_2424_String(165,80,"1",RED);
                    chan_dev.chan1=1;
                }
            else
                {
                    LCD_Show_2424_String(165,80,"1",BLACK);
                    chan_dev.chan1=0;
                }
            delay_ms(200);
        }
    else if(flag_dev.action_flag==TIMER&&(tp_dev.x[0]>185)&&(tp_dev.x[0]<197)&&(tp_dev.y[0]>80)&&(tp_dev.y[0]<105))
        {

            if(chan_dev.chan2!=1)
                {
                    LCD_Show_2424_String(185,80,"2",RED);
                    chan_dev.chan2=1;
                }
            else
                {
                    LCD_Show_2424_String(185,80,"2",BLACK);

                    chan_dev.chan2=0;
                }
            delay_ms(200);
        }
    else if(flag_dev.action_flag==TIMER&&(tp_dev.x[0]>205)&&(tp_dev.x[0]<217)&&(tp_dev.y[0]>80)&&(tp_dev.y[0]<105))
        {


            if(chan_dev.chan3!=1)
                {
                    LCD_Show_2424_String(205,80,"3",RED);

                    chan_dev.chan3=1;
                }
            else
                {
                    LCD_Show_2424_String(205,80,"3",BLACK);

                    chan_dev.chan3=0;
                }
            delay_ms(200);

        }
    else if(flag_dev.action_flag==TIMER&&(tp_dev.x[0]>225)&&(tp_dev.x[0]<237)&&(tp_dev.y[0]>80)&&(tp_dev.y[0]<105))
        {


            if(chan_dev.chan4!=1)
                {
                    LCD_Show_2424_String(225,80,"4",RED);

                    chan_dev.chan4=1;
                }
            else
                {
                    LCD_Show_2424_String(225,80,"4",BLACK);

                    chan_dev.chan4=0;
                }


            delay_ms(200);

        }
    else if(flag_dev.action_flag==TIMER&&(tp_dev.x[0]>245)&&(tp_dev.x[0]<257)&&(tp_dev.y[0]>80)&&(tp_dev.y[0]<105))
        {
            if(chan_dev.chan5!=1)
                {
                    LCD_Show_2424_String(245,80,"5",RED);
                    chan_dev.chan5=1;
                }
            else
                {
                    LCD_Show_2424_String(245,80,"5",BLACK);
                    chan_dev.chan5=0;
                }
            delay_ms(200);
        }
    else if(flag_dev.action_flag==TIMER&&(tp_dev.x[0]>265)&&(tp_dev.x[0]<277)&&(tp_dev.y[0]>80)&&(tp_dev.y[0]<105))
        {
            if(chan_dev.chan6!=1)
                {
                    LCD_Show_2424_String(265,80,"6",RED);
                    chan_dev.chan6=1;
                }
            else
                {
                    LCD_Show_2424_String(265,80,"6",BLACK);
                    chan_dev.chan6=0;
                }


            delay_ms(200);
        }
    else if(flag_dev.action_flag==TIMER&&(tp_dev.x[0]>285)&&(tp_dev.x[0]<297)&&(tp_dev.y[0]>80)&&(tp_dev.y[0]<105))
        {
            if(chan_dev.chan7!=1)
                {
                    LCD_Show_2424_String(285,80,"7",RED);
                    chan_dev.chan7=1;
                }
            else
                {
                    LCD_Show_2424_String(285,80,"7",BLACK);
                    chan_dev.chan7=0;
                }

            delay_ms(200);
        }
    else if(flag_dev.action_flag==TIMER&&(tp_dev.x[0]>305)&&(tp_dev.x[0]<317)&&(tp_dev.y[0]>80)&&(tp_dev.y[0]<105))
        {
            if(chan_dev.chan8!=1)
                {
                    LCD_Show_2424_String(305,80,"8",RED);
                    chan_dev.chan8=1;
                }
            else
                {
                    LCD_Show_2424_String(305,80,"8",BLACK);
                    chan_dev.chan8=0;
                }
            delay_ms(200);
        }
    else if(flag_dev.action_flag==TIMER&&(tp_dev.x[0]>160)&&(tp_dev.x[0]<317)&&(tp_dev.y[0]>48)&&(tp_dev.y[0]<73))
        {

            if(chan_dev.timer_state==PROHIBIT)
                {
                    LCD_Fill(180,48,300,71,WHITE);
									  if(flag_dev.langage==1){
                    	LCD_Show_2424_String(218, 48, "OPEN",BLACK);
									}else{ 
                    ShowTwoChineseChar(206,48,0,1,24,BLACK);
                    ShowChineseChar(254,48,5,24,BLACK);
										}
                    chan_dev.timer_state=CHAN_OPEN;
                }
            else if(  chan_dev.timer_state==CHAN_OPEN)
                {
                    LCD_Fill(180,48,300,71,WHITE);
									  if(flag_dev.langage==1){
                    	LCD_Show_2424_String(212, 48,"CLOSE",BLACK);
									  }else {
                    ShowTwoChineseChar(206,48,0,1,24,BLACK);
                    ShowChineseChar(254,48,6,24,BLACK);
										}
                    chan_dev.timer_state=CHAN_CLOSE;
                }
            else if(chan_dev.timer_state==CHAN_CLOSE)
                {
                    LCD_Fill(180,48,300,71,WHITE);
									  if(flag_dev.langage==1)
                    LCD_Show_2424_String(225, 48,"OFF",BLACK);
									  else 
										ShowChineseChar(230,48,6,24,BLACK);
                    chan_dev.timer_state=PROHIBIT;
                }
            delay_ms(300);
        }
    else if(flag_dev.action_flag==TIMER&&(tp_dev.x[0]>160)&&(tp_dev.x[0]<317)&&(tp_dev.y[0]>109)&&(tp_dev.y[0]<139))
        {
            if(chan_dev.mode==LOOP)
                {
                    LCD_Fill(180,112,300,135,WHITE);
									  if(flag_dev.langage==1){
                    	LCD_Show_2424_String(220,112,"ONCE",BLACK);
									  }else {
                    ShowTwoChineseChar(217,112,54,44,24,BLACK);
										}
                    chan_dev.mode=ONCE;

                    gui_draw_arcrectangle(95,141,225,30,1,1,BLUE,BLUE);
                    gui_draw_arcrectangle(160,144,158,24,1,1,WHITE,WHITE);
										if(flag_dev.langage==1)
                    	LCD_Show_2424_String(95,144,"DATE",WHITE);
										else 
                    ShowTwoChineseChar(102,144,8,9,24,WHITE);
                    LCD_Show_2424_String(180,144,"    -  -  ",BLACK);
                    LCD_ShowNum(180,144,chan_dev.date_year,4,24,BLACK,WHITE);
                    LCD_ShowNum(240,144,chan_dev.date_month,2,24,BLACK,WHITE);
                    LCD_ShowNum(276,144,chan_dev.date_day,2,24,BLACK,WHITE);

                    LCD_ShowNum(180,176,chan_dev.time_hour,2,24,BLACK,WHITE);
                    LCD_ShowNum(216,176,chan_dev.time_min,2,24,BLACK,WHITE);
                    LCD_ShowNum(252,176,chan_dev.time_sec,2,24,BLACK,WHITE);

                }
            else if(chan_dev.mode==ONCE)
                {
                    LCD_Fill(180,112,300,135,WHITE);
									  if(flag_dev.langage==1)
                    	LCD_Show_2424_String(220,112,"LOOP",BLACK);
									  else 
                    ShowTwoChineseChar(217,112,52,53,24,BLACK);
                    chan_dev.mode=LOOP;

                    gui_draw_arcrectangle(95,141,225,30,1,1,BLUE,BLUE);
                    gui_draw_arcrectangle(160,144,158,24,1,1,WHITE,WHITE);
                    LCD_DrawLtrigo(160,144,185,169,LEFT,BLUE);
                    LCD_DrawLtrigo(292,144,317,169,RIGHT,BLUE);
										if(flag_dev.langage==1)
                    	LCD_Show_2424_String(95,144,"WEEK",WHITE);
										else 
                    ShowTwoChineseChar(102,144,51,9,24,WHITE);

                    if(chan_dev.week&0x01)
                        {
													 if(flag_dev.langage==1){
                           	 LCD_Show_2424_String(200,144,"  SUN  ",RED);
												 }else {
                            ShowTwoChineseChar(206,144,51,9,24,RED);
                            ShowChineseChar(254,144,8,24,RED);
													 }

                        }
                    else
                        {
													if(flag_dev.langage==1){
                          	  LCD_Show_2424_String(200,144,"  SUN  ",BLACK);
													}else {
                            ShowTwoChineseChar(206,144,51,9,24,BLACK);
                            ShowChineseChar(254,144,8,24,BLACK);
													}
                        }
                    flag_dev.WeekAnchor=0x01;
                    LCD_ShowNum(180,176,chan_dev.time_hour,2,24,BLACK,WHITE);
                    LCD_ShowNum(216,176,chan_dev.time_min,2,24,BLACK,WHITE);
                    LCD_ShowNum(252,176,chan_dev.time_sec,2,24,BLACK,WHITE);
                    flag_dev.anchor=0;

                }

            delay_ms(100);
        }
    else if(flag_dev.action_flag==TIMER&&(tp_dev.x[0]>160)&&(tp_dev.x[0]<185)&&(tp_dev.y[0]>144)&&(tp_dev.y[0]<169)&&chan_dev.mode==LOOP)
        {
            switch(flag_dev.WeekAnchor)
                {

                case 0x00:
                    gui_draw_arcrectangle(160,144,158,24,1,1,WHITE,WHITE);
                    LCD_DrawLtrigo(160,144,185,169,LEFT,BLUE);
                    LCD_DrawLtrigo(292,144,317,169,RIGHT,BLUE);
								   if(flag_dev.langage==1)
                   	  LCD_Show_2424_String(95,144,"WEEK",WHITE);
								   else 
                    ShowTwoChineseChar(102,144,51,9,24,WHITE);
                    if(chan_dev.week&0x01)
                        {
													if(flag_dev.langage==1){
                          	  LCD_Show_2424_String(200,144,"  SUN  ",RED);
												}else {
                            ShowTwoChineseChar(206,144,51,9,24,RED);
                            ShowChineseChar(254,144,8,24,RED);
													}
                        }
                    else
                        {
													if(flag_dev.langage==1){
                          	  LCD_Show_2424_String(200,144,"  SUN  ",BLACK);
												}else {
                            ShowTwoChineseChar(206,144,51,9,24,BLACK);
                            ShowChineseChar(254,144,8,24,BLACK);
												}
                        }
                    flag_dev.WeekAnchor=0x01;
                    break;
                case 0x02:
                    gui_draw_arcrectangle(160,144,158,24,1,1,WHITE,WHITE);
                    LCD_DrawLtrigo(160,144,185,169,LEFT,BLUE);
                    LCD_DrawLtrigo(292,144,317,169,RIGHT,BLUE);
								    if(flag_dev.langage==1)
                    	LCD_Show_2424_String(95,144,"WEEK",WHITE);
								    else 
                    ShowTwoChineseChar(102,144,51,9,24,WHITE);
                    if(chan_dev.week&0x01)
                        {
													if(flag_dev.langage==1){
                          	  LCD_Show_2424_String(200,144,"  SUN  ",RED);
												}else {
                            ShowTwoChineseChar(206,144,51,9,24,RED);
                            ShowChineseChar(254,144,8,24,RED);
													}
                        }
                    else
                        {
													if(flag_dev.langage==1){
                          	  LCD_Show_2424_String(200,144,"  SUN  ",BLACK);
													}else {
                            ShowTwoChineseChar(206,144,51,9,24,BLACK);
                            ShowChineseChar(254,144,8,24,BLACK);
													}
                        }
                    flag_dev.WeekAnchor=0x01;
                    break;
                case 0x03:
                    gui_draw_arcrectangle(160,144,158,24,1,1,WHITE,WHITE);
                    LCD_DrawLtrigo(160,144,185,169,LEFT,BLUE);
                    LCD_DrawLtrigo(292,144,317,169,RIGHT,BLUE);
								    if(flag_dev.langage==1)
                    	LCD_Show_2424_String(95,144,"WEEK",WHITE);
								    else 
                    ShowTwoChineseChar(102,144,51,9,24,WHITE);
                    if(chan_dev.week&0x02)
                        {
													if(flag_dev.langage==1){
                          	  LCD_Show_2424_String(200,144,"  MON  ",RED);
													}else {
                            ShowTwoChineseChar(206,144,51,9,24,RED);
                            ShowChineseChar(254,144,65,24,RED);
													}
                        }
                    else
                        {
													if(flag_dev.langage==1){
                          	  LCD_Show_2424_String(200,144,"  MON  ",BLACK);
												}else{ 
                            ShowTwoChineseChar(206,144,51,9,24,BLACK);
                            ShowChineseChar(254,144,65,24,BLACK);
												}
                        }
                    flag_dev.WeekAnchor=0x02;
                    break;
                case 0x04:
                    gui_draw_arcrectangle(160,144,158,24,1,1,WHITE,WHITE);
                    LCD_DrawLtrigo(160,144,185,169,LEFT,BLUE);
                    LCD_DrawLtrigo(292,144,317,169,RIGHT,BLUE);
								    if(flag_dev.langage==1)
                    	LCD_Show_2424_String(95,144,"WEEK",WHITE);
								    else 
                    ShowTwoChineseChar(102,144,51,9,24,WHITE);
                    if(chan_dev.week&0x04)
                        {
													 if(flag_dev.langage==1){
                           	 LCD_Show_2424_String(200,144,"  TUE  ",RED);
													 }else {
                            ShowTwoChineseChar(206,144,51,9,24,RED);
                            ShowChineseChar(254,144,66,24,RED);
													 }
													
                        }
                    else
                        {
													  if(flag_dev.langage==1){
                            	LCD_Show_2424_String(200,144,"  TUE  ",BLACK);
													  }else {
                            ShowTwoChineseChar(206,144,51,9,24,BLACK);
                            ShowChineseChar(254,144,66,24,BLACK);
														}
                        }
                    flag_dev.WeekAnchor=0x03;
                    break;
                case 0x05:
                    gui_draw_arcrectangle(160,144,158,24,1,1,WHITE,WHITE);
                    LCD_DrawLtrigo(160,144,185,169,LEFT,BLUE);
                    LCD_DrawLtrigo(292,144,317,169,RIGHT,BLUE);
								    if(flag_dev.langage==1) 
                    	LCD_Show_2424_String(95,144,"WEEK",WHITE);
								    else 
                    ShowTwoChineseChar(102,144,51,9,24,WHITE);
                    if(chan_dev.week&0x08)
                        {
                            if(flag_dev.langage==1) 
                            	LCD_Show_2424_String(200,144,"  WED  ",RED);
													  else {
                            ShowTwoChineseChar(206,144,51,9,24,RED);
                            ShowChineseChar(254,144,67,24,RED);
														}

                        }
                    else
                        {
                           if(flag_dev.langage==1){
                           	 LCD_Show_2424_String(200,144,"  WED  ",BLACK);
													 }else {
                            ShowTwoChineseChar(206,144,51,9,24,BLACK);
                            ShowChineseChar(254,144,67,24,BLACK);
													 }

                        }
                    flag_dev.WeekAnchor=0x04;
                    break;
                case 0x06:
                    gui_draw_arcrectangle(160,144,158,24,1,1,WHITE,WHITE);
                    LCD_DrawLtrigo(160,144,185,169,LEFT,BLUE);
                    LCD_DrawLtrigo(292,144,317,169,RIGHT,BLUE);
								    if(flag_dev.langage==1)
                    	LCD_Show_2424_String(95,144,"WEEK",WHITE);
								    else 
                    ShowTwoChineseChar(102,144,51,9,24,WHITE);
                    if(chan_dev.week&0x10)
                        {
													  if(flag_dev.langage==1){
                            	LCD_Show_2424_String(200,144,"  THU  ",RED);
													  }else {
                            ShowTwoChineseChar(206,144,51,9,24,RED);
                            ShowChineseChar(254,144,68,24,RED);
														}
                        }
                    else
                        {
													  if(flag_dev.langage==1){
                            	LCD_Show_2424_String(200,144,"  THU  ",BLACK);
													  }else {
                            ShowTwoChineseChar(206,144,51,9,24,BLACK);
                            ShowChineseChar(254,144,68,24,BLACK);
														}
                        }
                    flag_dev.WeekAnchor=0x05;
                    break;
                case 0x07:
                    gui_draw_arcrectangle(160,144,158,24,1,1,WHITE,WHITE);
                    LCD_DrawLtrigo(160,144,185,169,LEFT,BLUE);
                    LCD_DrawLtrigo(292,144,317,169,RIGHT,BLUE);
								    if(flag_dev.langage==1)
                    	LCD_Show_2424_String(95,144,"WEEK",WHITE);
								    else 
                    ShowTwoChineseChar(102,144,51,9,24,WHITE);
                    if(chan_dev.week&0x20)
                        {
													 if(flag_dev.langage==1){
                           	 LCD_Show_2424_String(200,144,"  FRI  ",RED);
												 }else{ 
                            ShowTwoChineseChar(206,144,51,9,24,RED);
                            ShowChineseChar(254,144,69,24,RED);
												 }
                        }
                    else
                        {
													  if(flag_dev.langage==1){
                            	LCD_Show_2424_String(200,144,"  FRI  ",BLACK);
													  }else{
                            ShowTwoChineseChar(206,144,51,9,24,BLACK);
                            ShowChineseChar(254,144,69,24,BLACK);
														}
                        }
                    flag_dev.WeekAnchor=0x06;
                    break;
                case 0x01:
                    gui_draw_arcrectangle(160,144,158,24,1,1,WHITE,WHITE);
                    LCD_DrawLtrigo(160,144,185,169,LEFT,BLUE);
                    LCD_DrawLtrigo(292,144,317,169,RIGHT,BLUE);
								    if(flag_dev.langage==1)
                    	LCD_Show_2424_String(95,144,"WEEK",WHITE);
								    else 
                    ShowTwoChineseChar(102,144,51,9,24,WHITE);
                    if(chan_dev.week&0x40)
                        {
													  if(flag_dev.langage==1){
                            	LCD_Show_2424_String(200,144,"  SAT  ",RED);
													  }else {
                            ShowTwoChineseChar(206,144,51,9,24,RED);
                            ShowChineseChar(254,144,70,24,RED);
														}
                        }
                    else
                        {
													  if(flag_dev.langage==1){
                            	LCD_Show_2424_String(200,144,"  SAT  ",BLACK);
													  }else {
                            ShowTwoChineseChar(206,144,51,9,24,BLACK);
                            ShowChineseChar(254,144,70,24,BLACK);
														}
                        }
                    flag_dev.WeekAnchor=0x07;
                    break;
                }

            delay_ms(200);
        }
    else if(flag_dev.action_flag==TIMER&&(tp_dev.x[0]>292)&&(tp_dev.x[0]<317)&&(tp_dev.y[0]>144)&&(tp_dev.y[0]<169)&&chan_dev.mode==LOOP)
        {

            switch(flag_dev.WeekAnchor)
                {

                case 0x00:
                    gui_draw_arcrectangle(160,144,158,24,1,1,WHITE,WHITE);
                    LCD_DrawLtrigo(160,144,185,169,LEFT,BLUE);
                    LCD_DrawLtrigo(292,144,317,169,RIGHT,BLUE);
								  if(flag_dev.langage==1)
                  	   LCD_Show_2424_String(95,144,"WEEK",WHITE);
								  else 
                    ShowTwoChineseChar(102,144,51,9,24,WHITE);
                    if(chan_dev.week&0x02)
                        {
													if(flag_dev.langage==1){
                          	  LCD_Show_2424_String(200,144,"  MON  ",RED);
													}else {
                            ShowTwoChineseChar(206,144,51,9,24,RED);
                            ShowChineseChar(254,144,65,24,RED);
													}
                        }
                    else
                        {
													 if(flag_dev.langage==1){
                           	 LCD_Show_2424_String(200,144,"  MON  ",BLACK);
													 }else{
                            ShowTwoChineseChar(206,144,51,9,24,BLACK);
                            ShowChineseChar(254,144,65,24,BLACK);
													 }
                        }
                    flag_dev.WeekAnchor=0x02;
                    break;
                case 0x01:
                    gui_draw_arcrectangle(160,144,158,24,1,1,WHITE,WHITE);
                    LCD_DrawLtrigo(160,144,185,169,LEFT,BLUE);
                    LCD_DrawLtrigo(292,144,317,169,RIGHT,BLUE);
								    if(flag_dev.langage==1)
                    	LCD_Show_2424_String(95,144,"WEEK",WHITE);
								    else 
                    ShowTwoChineseChar(102,144,51,9,24,WHITE);
										
                    if(chan_dev.week&0x02)
                        {
													  if(flag_dev.langage==1){
                            	LCD_Show_2424_String(200,144,"  MON  ",RED);
													  }else {
                            ShowTwoChineseChar(206,144,51,9,24,RED);
                            ShowChineseChar(254,144,65,24,RED);
														}
                        }
                    else
                        {
													  if(flag_dev.langage==1){
                            	LCD_Show_2424_String(200,144,"  MON  ",BLACK);
													  }else {
                            ShowTwoChineseChar(206,144,51,9,24,BLACK);
                            ShowChineseChar(254,144,65,24,BLACK);
														}
                        }
                    flag_dev.WeekAnchor=0x02;
                    break;
                case 0x02:
                    gui_draw_arcrectangle(160,144,158,24,1,1,WHITE,WHITE);
                    LCD_DrawLtrigo(160,144,185,169,LEFT,BLUE);
                    LCD_DrawLtrigo(292,144,317,169,RIGHT,BLUE);
								    if(flag_dev.langage==1)
                    	LCD_Show_2424_String(95,144,"WEEK",WHITE);
								    else 
                    ShowTwoChineseChar(102,144,51,9,24,WHITE);
                    if(chan_dev.week&0x04)
                        {
													  if(flag_dev.langage==1){
                            	LCD_Show_2424_String(200,144,"  TUE  ",RED);
													  }else {
                            ShowTwoChineseChar(206,144,51,9,24,RED);
                            ShowChineseChar(254,144,66,24,RED);
														}
                        }
                    else
                        {
													  if(flag_dev.langage==1){
                            	LCD_Show_2424_String(200,144,"  TUE  ",BLACK);
													  }else{
                            ShowTwoChineseChar(206,144,51,9,24,BLACK);
                            ShowChineseChar(254,144,66,24,BLACK);
														}
                        }
                    flag_dev.WeekAnchor=0x03;
                    break;
                case 0x03:
                    gui_draw_arcrectangle(160,144,158,24,1,1,WHITE,WHITE);
                    LCD_DrawLtrigo(160,144,185,169,LEFT,BLUE);
                    LCD_DrawLtrigo(292,144,317,169,RIGHT,BLUE);
								   if(flag_dev.langage==1)
                   	 LCD_Show_2424_String(95,144,"WEEK",WHITE);
								   else 
                    ShowTwoChineseChar(102,144,51,9,24,WHITE);
                    if(chan_dev.week&0x08)
                        {
													  if(flag_dev.langage==1){
                            	LCD_Show_2424_String(200,144,"  WED  ",RED);
													  }else {
                            ShowTwoChineseChar(206,144,51,9,24,RED);
                            ShowChineseChar(254,144,67,24,RED);
														}
                        }
                    else
                        {
													  if(flag_dev.langage==1){
                            	LCD_Show_2424_String(200,144,"  WED  ",BLACK);
													  }else {
                            ShowTwoChineseChar(206,144,51,9,24,BLACK);
                            ShowChineseChar(254,144,67,24,BLACK);
														}
                        }
                    flag_dev.WeekAnchor=0x04;
                    break;
                case 0x04:
                    gui_draw_arcrectangle(160,144,158,24,1,1,WHITE,WHITE);
                    LCD_DrawLtrigo(160,144,185,169,LEFT,BLUE);
                    LCD_DrawLtrigo(292,144,317,169,RIGHT,BLUE);
								    if(flag_dev.langage==1)
                    	LCD_Show_2424_String(95,144,"WEEK",WHITE);
								    else 
                    ShowTwoChineseChar(102,144,51,9,24,WHITE);
                    if(chan_dev.week&0x10)
                        {
													  if(flag_dev.langage==1){
                            	LCD_Show_2424_String(200,144,"  THU  ",RED);
													  }else {
                            ShowTwoChineseChar(206,144,51,9,24,RED);
                            ShowChineseChar(254,144,68,24,RED);
														}
                        }
                    else
                        {
													  if(flag_dev.langage==1){
                            	LCD_Show_2424_String(200,144,"  THU  ",BLACK);
													  }else{
                            ShowTwoChineseChar(206,144,51,9,24,BLACK);
                            ShowChineseChar(254,144,68,24,BLACK);
														}
                        }
                    flag_dev.WeekAnchor=0x05;
                    break;
                case 0x05:
                    gui_draw_arcrectangle(160,144,158,24,1,1,WHITE,WHITE);
                    LCD_DrawLtrigo(160,144,185,169,LEFT,BLUE);
                    LCD_DrawLtrigo(292,144,317,169,RIGHT,BLUE);
								    if(flag_dev.langage==1)
                    	LCD_Show_2424_String(95,144,"WEEK",WHITE);
								    else 
                    ShowTwoChineseChar(102,144,51,9,24,WHITE);
                    if(chan_dev.week&0x20)
                        {
													  if(flag_dev.langage==1){
                            	LCD_Show_2424_String(200,144,"  FRI  ",RED);
													  }else {
                            ShowTwoChineseChar(206,144,51,9,24,RED);
                            ShowChineseChar(254,144,69,24,RED);
														}
                        }
                    else
                        {
													  if(flag_dev.langage==1){
                            	LCD_Show_2424_String(200,144,"  FRI  ",BLACK);
													  }else{
                            ShowTwoChineseChar(206,144,51,9,24,BLACK);
                            ShowChineseChar(254,144,69,24,BLACK);
														}
                        }
                    flag_dev.WeekAnchor=0x06;
                    break;
                case 0x06:
                    gui_draw_arcrectangle(160,144,158,24,1,1,WHITE,WHITE);
                    LCD_DrawLtrigo(160,144,185,169,LEFT,BLUE);
                    LCD_DrawLtrigo(292,144,317,169,RIGHT,BLUE);
								    if(flag_dev.langage==1)
                    	LCD_Show_2424_String(95,144,"WEEK",WHITE);
								    else 
                    ShowTwoChineseChar(102,144,51,9,24,WHITE);
                    if(chan_dev.week&0x40)
                        {
													  if(flag_dev.langage==1){
                            	LCD_Show_2424_String(200,144,"  SAT  ",RED);
													  }else {
                            ShowTwoChineseChar(206,144,51,9,24,RED);
                            ShowChineseChar(254,144,70,24,RED);
														}
                        }
                    else
                        {
													  if(flag_dev.langage==1){
                            	LCD_Show_2424_String(200,144,"  SAT  ",BLACK);
													  }else {
                            ShowTwoChineseChar(206,144,51,9,24,BLACK);
                            ShowChineseChar(254,144,70,24,BLACK);
														}
                        }
                    flag_dev.WeekAnchor=0x07;
                    break;
                case 0x07:
                    gui_draw_arcrectangle(160,144,158,24,1,1,WHITE,WHITE);
                    LCD_DrawLtrigo(160,144,185,169,LEFT,BLUE);
                    LCD_DrawLtrigo(292,144,317,169,RIGHT,BLUE);
								    if(flag_dev.langage==1)
                    	LCD_Show_2424_String(95,144,"WEEK",WHITE);
								    else 
                    ShowTwoChineseChar(102,144,51,9,24,WHITE);
                    if(chan_dev.week&0x01)
                        {
													  if(flag_dev.langage==1){
                            	LCD_Show_2424_String(200,144,"  SUN  ",RED);
													  }else {
                            ShowTwoChineseChar(206,144,51,9,24,RED);
                            ShowChineseChar(254,144,8,24,RED);
														}
                        }
                    else
                        {
													  if(flag_dev.langage==1){
                            	LCD_Show_2424_String(200,144,"  SUN  ",BLACK);
													  }else {
                            ShowTwoChineseChar(206,144,51,9,24,BLACK);
                            ShowChineseChar(254,144,8,24,BLACK);
														}
                        }
                    flag_dev.WeekAnchor=0x01;
                    break;
                }

            delay_ms(200);

        }
    else if(flag_dev.action_flag==TIMER&&(tp_dev.x[0]>220)&&(tp_dev.x[0]<260)&&(tp_dev.y[0]>144)&&(tp_dev.y[0]<168)&&chan_dev.mode==LOOP)
        {
            switch(flag_dev.WeekAnchor)
                {
                case 0x01:
                    if(chan_dev.week&0x01)
                        {
                            chan_dev.week&=0x7E;
													  if(flag_dev.langage==1){
                            	LCD_Show_2424_String(200,144,"  SUN  ",BLACK);
													  }else{
                            ShowTwoChineseChar(206,144,51,9,24,BLACK);
                            ShowChineseChar(254,144,8,24,BLACK);
														}
                        }
                    else
                        {
                            chan_dev.week|=0x01;
													  if(flag_dev.langage==1){
                            	LCD_Show_2424_String(200,144,"  SUN  ",RED);
													  }else {
                            ShowTwoChineseChar(206,144,51,9,24,RED);
                            ShowChineseChar(254,144,8,24,RED);
														}
                        }
                    break;
                case 0x02:
                    if(chan_dev.week&0x02)
                        {
													if(flag_dev.langage==1){
                          	  LCD_Show_2424_String(200,144,"  MON  ",BLACK);
													}else {
                            ShowTwoChineseChar(206,144,51,9,24,BLACK);
                            ShowChineseChar(254,144,65,24,BLACK);
													}
                            chan_dev.week&=0x7D;
                        }
                    else
                        {
													if(flag_dev.langage==1){
                          	  LCD_Show_2424_String(200,144,"  MON  ",RED);
													}else {
                            ShowTwoChineseChar(206,144,51,9,24,RED);
                            ShowChineseChar(254,144,65,24,RED);
													}
                            chan_dev.week|=0x02;
                        }
                    break;
                case 0x03:
                    if(chan_dev.week&0x04)
                        {
													 if(flag_dev.langage==1){
                           	 LCD_Show_2424_String(200,144,"  TUE  ",BLACK);
													 }else{
                            ShowTwoChineseChar(206,144,51,9,24,BLACK);
                            ShowChineseChar(254,144,66,24,BLACK);
													 }
                            chan_dev.week&=0x7B;
                        }
                    else
                        {
													  if(flag_dev.langage==1){
                            	LCD_Show_2424_String(200,144,"  TUE  ",RED);
													  }else{
                            ShowTwoChineseChar(206,144,51,9,24,RED);
                            ShowChineseChar(254,144,66,24,RED);
														}
                            chan_dev.week|=0x04;
                        }
                    break;
                case 0x04:
                    if(chan_dev.week&0x08)
                        {
                            chan_dev.week&=0x77;
													  if(flag_dev.langage==1){
                            	LCD_Show_2424_String(200,144,"  WED  ",BLACK);
													  }else{ 
                            ShowTwoChineseChar(206,144,51,9,24,BLACK);
                            ShowChineseChar(254,144,67,24,BLACK);
														}
                        }
                    else
                        {
													 if(flag_dev.langage==1){
                           	 LCD_Show_2424_String(200,144,"  WED  ",RED);
													 }else{
                            ShowTwoChineseChar(206,144,51,9,24,RED);
                            ShowChineseChar(254,144,67,24,RED);
													 }
                            chan_dev.week|=0x08;
                        }
                    break;
                case 0x05:
                    if(chan_dev.week&0x10)
                        {
													 if(flag_dev.langage==1){
                           	 LCD_Show_2424_String(200,144,"  THU  ",BLACK);
													 }else {
													   ShowTwoChineseChar(206,144,51,9,24,BLACK);
							               ShowChineseChar(254,144,68,24,BLACK);
													 }
                            chan_dev.week&=0x6F;
                        }
                    else
                        {
													 if(flag_dev.langage==1){
                           	LCD_Show_2424_String(200,144,"  THU  ",RED);
													 }else {
													  ShowTwoChineseChar(206,144,51,9,24,RED);
							              ShowChineseChar(254,144,68,24,RED);
													 }
                            chan_dev.week|=0x10;
                        }
                    break;
                case 0x06:
                    if(chan_dev.week&0x20)
                        {
													  if(flag_dev.langage==1){
                            	LCD_Show_2424_String(200,144,"  FRI  ",BLACK);
													  }else{
													  ShowTwoChineseChar(206,144,51,9,24,BLACK);
							              ShowChineseChar(254,144,69,24,BLACK);
														}
                            chan_dev.week&=0x5F;
                        }
                    else
                        {
													  if(flag_dev.langage==1){
                            	LCD_Show_2424_String(200,144,"  FRI  ",RED);
													  }else{
													  ShowTwoChineseChar(206,144,51,9,24,RED);
							              ShowChineseChar(254,144,69,24,RED);
														}
                            chan_dev.week|=0x20;
                        }
                    break;
                case 0x07:
                    if(chan_dev.week&0x40)
                        {
													  if(flag_dev.langage==1){
                            	LCD_Show_2424_String(200,144,"  SAT  ",BLACK);
													  }else{
													  ShowTwoChineseChar(206,144,51,9,24,BLACK);
							              ShowChineseChar(254,144,70,24,BLACK);
														}
                            chan_dev.week&=0x3F;
                        }
                    else
                        {
													  if(flag_dev.langage==1){
                            	LCD_Show_2424_String(200,144,"  SAT  ",RED);
													  }else{
													  ShowTwoChineseChar(206,144,51,9,24,RED);
							              ShowChineseChar(254,144,70,24,RED);
														}
                            chan_dev.week|=0x40;
                        }
                    break;
                }
            delay_ms(200);
        }
    else if(flag_dev.action_flag==TIMER&&(tp_dev.x[0]>180)&&(tp_dev.x[0]<228)&&(tp_dev.y[0]>144)&&(tp_dev.y[0]<168))
        {
            if(chan_dev.mode==ONCE)
                {
                    LCD_ShowNum(180,144,chan_dev.date_year,4,24,RED,WHITE);
                    LCD_ShowNum(240,144,chan_dev.date_month,2,24,BLACK,WHITE);
                    LCD_ShowNum(276,144,chan_dev.date_day,2,24,BLACK,WHITE);
                    flag_dev.anchor=1;
                }

            LCD_ShowNum(180,176,chan_dev.time_hour,2,24,BLACK,WHITE);
            LCD_ShowNum(216,176,chan_dev.time_min,2,24,BLACK,WHITE);
            LCD_ShowNum(252,176,chan_dev.time_sec,2,24,BLACK,WHITE);

        }
    else if(flag_dev.action_flag==TIMER&&(tp_dev.x[0]>240)&&(tp_dev.x[0]<264)&&(tp_dev.y[0]>144)&&(tp_dev.y[0]<168))
        {

            if(chan_dev.mode==ONCE)
                {
                    LCD_ShowNum(180,144,chan_dev.date_year,4,24,BLACK,WHITE);
                    LCD_ShowNum(240,144,chan_dev.date_month,2,24,RED,WHITE);
                    LCD_ShowNum(276,144,chan_dev.date_day,2,24,BLACK,WHITE);
                    flag_dev.anchor=2;

                }


            LCD_ShowNum(180,176,chan_dev.time_hour,2,24,BLACK,WHITE);
            LCD_ShowNum(216,176,chan_dev.time_min,2,24,BLACK,WHITE);
            LCD_ShowNum(252,176,chan_dev.time_sec,2,24,BLACK,WHITE);


        }
    else if(flag_dev.action_flag==TIMER&&(tp_dev.x[0]>276)&&(tp_dev.x[0]<300)&&(tp_dev.y[0]>144)&&(tp_dev.y[0]<168))
        {

            if(chan_dev.mode==ONCE)
                {
                    LCD_ShowNum(180,144,chan_dev.date_year,4,24,BLACK,WHITE);
                    LCD_ShowNum(240,144,chan_dev.date_month,2,24,BLACK,WHITE);
                    LCD_ShowNum(276,144,chan_dev.date_day,2,24,RED,WHITE);
                    flag_dev.anchor=3;

                }

            LCD_ShowNum(180,176,chan_dev.time_hour,2,24,BLACK,WHITE);
            LCD_ShowNum(216,176,chan_dev.time_min,2,24,BLACK,WHITE);
            LCD_ShowNum(252,176,chan_dev.time_sec,2,24,BLACK,WHITE);

        }
    else if(flag_dev.action_flag==TIMER&&(tp_dev.x[0]>180)&&(tp_dev.x[0]<204)&&(tp_dev.y[0]>176)&&(tp_dev.y[0]<200))
        {
            if(chan_dev.mode==ONCE)
                {
                    LCD_ShowNum(180,144,chan_dev.date_year,4,24,BLACK,WHITE);
                    LCD_ShowNum(240,144,chan_dev.date_month,2,24,BLACK,WHITE);
                    LCD_ShowNum(276,144,chan_dev.date_day,2,24,BLACK,WHITE);
                }
            LCD_ShowNum(180,176,chan_dev.time_hour,2,24,RED,WHITE);
            LCD_ShowNum(216,176,chan_dev.time_min,2,24,BLACK,WHITE);
            LCD_ShowNum(252,176,chan_dev.time_sec,2,24,BLACK,WHITE);
            flag_dev.anchor=4;
        }
    else if(flag_dev.action_flag==TIMER&&(tp_dev.x[0]>216)&&(tp_dev.x[0]<240)&&(tp_dev.y[0]>176)&&(tp_dev.y[0]<200))
        {
            if(chan_dev.mode==ONCE)
                {
                    LCD_ShowNum(180,144,chan_dev.date_year,4,24,BLACK,WHITE);
                    LCD_ShowNum(240,144,chan_dev.date_month,2,24,BLACK,WHITE);
                    LCD_ShowNum(276,144,chan_dev.date_day,2,24,BLACK,WHITE);
                }
            LCD_ShowNum(180,176,chan_dev.time_hour,2,24,BLACK,WHITE);
            LCD_ShowNum(216,176,chan_dev.time_min,2,24,RED,WHITE);
            LCD_ShowNum(252,176,chan_dev.time_sec,2,24,BLACK,WHITE);
            flag_dev.anchor=5;
        }
    else if(flag_dev.action_flag==TIMER&&(tp_dev.x[0]>252)&&(tp_dev.x[0]<276)&&(tp_dev.y[0]>176)&&(tp_dev.y[0]<200))
        {

            if(chan_dev.mode==ONCE)
                {
                    LCD_ShowNum(180,144,chan_dev.date_year,4,24,BLACK,WHITE);
                    LCD_ShowNum(240,144,chan_dev.date_month,2,24,BLACK,WHITE);
                    LCD_ShowNum(276,144,chan_dev.date_day,2,24,BLACK,WHITE);
                }
            LCD_ShowNum(180,176,chan_dev.time_hour,2,24,BLACK,WHITE);
            LCD_ShowNum(216,176,chan_dev.time_min,2,24,BLACK,WHITE);
            LCD_ShowNum(252,176,chan_dev.time_sec,2,24,RED,WHITE);
            flag_dev.anchor=6;
        }
}
/*TIMER页面数据刷新*/
void timer_data_flash()
{

    if(chan_dev.timer_state==PROHIBIT)
        {
            LCD_Fill(180,48,300,71,WHITE);
					  if(flag_dev.langage==1)
            LCD_Show_2424_String(225, 48,"OFF",BLACK);
else
	ShowChineseChar(230,48,6,24,BLACK);

        }
    else if(chan_dev.timer_state==CHAN_OPEN)
        {
            LCD_Fill(180,48,300,71,WHITE);
					  if(flag_dev.langage==1){
            	LCD_Show_2424_String(218, 48, "OPEN",BLACK);
					  }else {
            ShowTwoChineseChar(206,48,0,1,24,BLACK);
            ShowChineseChar(254,48,5,24,BLACK);
						}

        }
    else if(chan_dev.timer_state==CHAN_CLOSE)
        {
            LCD_Fill(180,48,300,71,WHITE);
					  if(flag_dev.langage==1){
            	LCD_Show_2424_String(212, 48,"CLOSE",BLACK);
					  }else {
            ShowTwoChineseChar(206,48,0,1,24,BLACK);
            ShowChineseChar(254,48,6,24,BLACK);
						}

        }

    if(chan_dev.chan1)
        {
            LCD_Show_2424_String(165,80,"1",RED);
        }
    else
        {
            LCD_Show_2424_String(165,80,"1",BLACK);
        }

    if(chan_dev.chan2)
        {
            LCD_Show_2424_String(185,80,"2",RED);

        }
    else
        {
            LCD_Show_2424_String(185,80,"2",BLACK);

        }


    if(chan_dev.chan3)
        {
            LCD_Show_2424_String(205,80,"3",RED);

        }
    else
        {
            LCD_Show_2424_String(205,80,"3",BLACK);

        }
    if(chan_dev.chan4)
        {
            LCD_Show_2424_String(225,80,"4",RED);

        }
    else
        {
            LCD_Show_2424_String(225,80,"4",BLACK);

        }

    if(chan_dev.chan5)
        {
            LCD_Show_2424_String(245,80,"5",RED);

        }
    else
        {
            LCD_Show_2424_String(245,80,"5",BLACK);

        }
    if(chan_dev.chan6)
        {
            LCD_Show_2424_String(265,80,"6",RED);

        }
    else
        {
            LCD_Show_2424_String(265,80,"6",BLACK);

        }

    if(chan_dev.chan7)
        {
            LCD_Show_2424_String(285,80,"7",RED);
        }
    else
        {
            LCD_Show_2424_String(285,80,"7",BLACK);

        }
    if(chan_dev.chan8)
        {
            LCD_Show_2424_String(305,80,"8",RED);

        }
    else
        {
            LCD_Show_2424_String(305,80,"8",BLACK);
        }
    if(chan_dev.mode==ONCE)
        {
            LCD_Fill(180,112,280,135,WHITE);
					  if(flag_dev.langage==1){
            	LCD_Show_2424_String(220,112,"ONCE",BLACK);
					  }else{
            ShowTwoChineseChar(217,112,54,44,24,BLACK);
						}
            gui_draw_arcrectangle(95,141,225,30,1,1,BLUE,BLUE);
            gui_draw_arcrectangle(160,144,158,24,1,1,WHITE,WHITE);
            if(flag_dev.langage==1){
            	LCD_Show_2424_String(95,144,"DATE",WHITE);
						}else{
            ShowTwoChineseChar(102,144,8,9,24,WHITE);
            }  
            LCD_Show_2424_String(180,144,"    -  -  ",BLACK);
            LCD_ShowNum(180,144,chan_dev.date_year,4,24,BLACK,WHITE);
            LCD_ShowNum(240,144,chan_dev.date_month,2,24,BLACK,WHITE);
            LCD_ShowNum(276,144,chan_dev.date_day,2,24,BLACK,WHITE);

            LCD_ShowNum(180,176,chan_dev.time_hour,2,24,BLACK,WHITE);
            LCD_ShowNum(216,176,chan_dev.time_min,2,24,BLACK,WHITE);
            LCD_ShowNum(252,176,chan_dev.time_sec,2,24,BLACK,WHITE);

        }
    else  if(chan_dev.mode==LOOP)
        {
            LCD_Fill(180,112,280,135,WHITE);
					  if(flag_dev.langage==1){
            	LCD_Show_2424_String(220,112,"LOOP",BLACK);
					  }else {
            ShowTwoChineseChar(217,112,52,53,24,BLACK);
						}
            gui_draw_arcrectangle(95,141,225,30,1,1,BLUE,BLUE);
            gui_draw_arcrectangle(160,144,158,24,1,1,WHITE,WHITE);
            LCD_DrawLtrigo(160,144,185,169,LEFT,BLUE);
            LCD_DrawLtrigo(292,144,317,169,RIGHT,BLUE);
						if(flag_dev.langage==1)
            	LCD_Show_2424_String(95,144,"WEEK",WHITE);
						else 
            ShowTwoChineseChar(102,144,51,9,24,WHITE);
            if(chan_dev.week&0x01)
                {
									if(flag_dev.langage==1){
                  	  LCD_Show_2424_String(200,144,"  SUN  ",RED);
									}else {
                    ShowTwoChineseChar(206,144,51,9,24,RED);
                    ShowChineseChar(254,144,8,24,RED);
									}
                }
            else
                {
									 if(flag_dev.langage==1){
                   	 LCD_Show_2424_String(200,144,"  SUN  ",BLACK);
									 }else{
                    ShowTwoChineseChar(206,144,51,9,24,BLACK);
                    ShowChineseChar(254,144,8,24,BLACK);
									 }
                }
            flag_dev.WeekAnchor=0x01;
            LCD_ShowNum(180,176,chan_dev.time_hour,2,24,BLACK,WHITE);
            LCD_ShowNum(216,176,chan_dev.time_min,2,24,BLACK,WHITE);
            LCD_ShowNum(252,176,chan_dev.time_sec,2,24,BLACK,WHITE);
        }

}
/*TIMER产生操作*/
void TimerAction(u32 second)
{
    u8 week;
    u32 LastSecond;


    /*获取TIMER秒数*/
    if(timer_dev_1.mode==ONCE)
        timer_dev_1.SecCount=Sec_counter(timer_dev_1.date_year,timer_dev_1.date_month,timer_dev_1.date_day,timer_dev_1.time_hour,timer_dev_1.time_min,timer_dev_1.time_sec);
    else
        timer_dev_1.SecCount=0;
    if(timer_dev_2.mode==ONCE)
        timer_dev_2.SecCount=Sec_counter(timer_dev_2.date_year,timer_dev_2.date_month,timer_dev_2.date_day,timer_dev_2.time_hour,timer_dev_2.time_min,timer_dev_2.time_sec);
    else
        timer_dev_2.SecCount=0;
    if(timer_dev_3.mode==ONCE)
        timer_dev_3.SecCount=Sec_counter(timer_dev_3.date_year,timer_dev_3.date_month,timer_dev_3.date_day,timer_dev_3.time_hour,timer_dev_3.time_min,timer_dev_3.time_sec);
    else
        timer_dev_3.SecCount=0;
    if(timer_dev_4.mode==ONCE)
        timer_dev_4.SecCount=Sec_counter(timer_dev_4.date_year,timer_dev_4.date_month,timer_dev_4.date_day,timer_dev_4.time_hour,timer_dev_4.time_min,timer_dev_4.time_sec);
    else
        timer_dev_4.SecCount=0;
    if(timer_dev_5.mode==ONCE)
        timer_dev_5.SecCount=Sec_counter(timer_dev_5.date_year,timer_dev_5.date_month,timer_dev_5.date_day,timer_dev_5.time_hour,timer_dev_5.time_min,timer_dev_5.time_sec);
    else
        timer_dev_5.SecCount=0;
    if(timer_dev_6.mode==ONCE)
        timer_dev_6.SecCount=Sec_counter(timer_dev_6.date_year,timer_dev_6.date_month,timer_dev_6.date_day,timer_dev_6.time_hour,timer_dev_6.time_min,timer_dev_6.time_sec);
    else
        timer_dev_6.SecCount=0;
    if(timer_dev_7.mode==ONCE)
        timer_dev_7.SecCount=Sec_counter(timer_dev_7.date_year,timer_dev_7.date_month,timer_dev_7.date_day,timer_dev_7.time_hour,timer_dev_7.time_min,timer_dev_7.time_sec);
    else
        timer_dev_7.SecCount=0;
    if(timer_dev_8.mode==ONCE)
        timer_dev_8.SecCount=Sec_counter(timer_dev_8.date_year,timer_dev_8.date_month,timer_dev_8.date_day,timer_dev_8.time_hour,timer_dev_8.time_min,timer_dev_8.time_sec);
    else
        timer_dev_8.SecCount=0;
    if(timer_dev_9.mode==ONCE)
        timer_dev_9.SecCount=Sec_counter(timer_dev_9.date_year,timer_dev_9.date_month,timer_dev_9.date_day,timer_dev_9.time_hour,timer_dev_9.time_min,timer_dev_9.time_sec);
    else
        timer_dev_9.SecCount=0;
    if(timer_dev_10.mode==ONCE)
        timer_dev_10.SecCount=Sec_counter(timer_dev_10.date_year,timer_dev_10.date_month,timer_dev_10.date_day,timer_dev_10.time_hour,timer_dev_10.time_min,timer_dev_10.time_sec);
    else
        timer_dev_10.SecCount=0;


    week=RTC_Get_Week(calendar.w_year,calendar.w_month,calendar.w_date);
    //LCD_ShowNum(100,100,week,2,30,RED,WHITE);


    ISWEEKALARM(&timer_dev_1, week);
    ISWEEKALARM(&timer_dev_2, week);
    ISWEEKALARM(&timer_dev_3, week);
    ISWEEKALARM(&timer_dev_4, week);
    ISWEEKALARM(&timer_dev_5, week);
    ISWEEKALARM(&timer_dev_6, week);
    ISWEEKALARM(&timer_dev_7, week);
    ISWEEKALARM(&timer_dev_8, week);
    ISWEEKALARM(&timer_dev_9, week);
    ISWEEKALARM(&timer_dev_10, week);

    if(LastSecond!=second)
        {
            if(second==timer_dev_1.SecCount)
                {

                    Alarm_Action(&timer_dev_1);
                }
            else if(second==timer_dev_2.SecCount)
                {
                    Alarm_Action(&timer_dev_2);
                }
            else if(second==timer_dev_3.SecCount)
                {
                    Alarm_Action(&timer_dev_3);
                }
            else if(second==timer_dev_4.SecCount)
                {
                    Alarm_Action(&timer_dev_4);
                }
            else if(second==timer_dev_5.SecCount)
                {
                    Alarm_Action(&timer_dev_5);
                }
            else if(second==timer_dev_6.SecCount)
                {
                    Alarm_Action(&timer_dev_6);
                }
            else if(second==timer_dev_7.SecCount)
                {
                    Alarm_Action(&timer_dev_7);
                }
            else if(second==timer_dev_8.SecCount)
                {
                    Alarm_Action(&timer_dev_8);
                }
            else if(second==timer_dev_9.SecCount)
                {
                    Alarm_Action(&timer_dev_9);
                }
            else if(second==timer_dev_10.SecCount)
                {
                    Alarm_Action(&timer_dev_10);
                }

        }
    LastSecond=second;
}

/*Timers处理闹钟定时函数*/
void Alarm_Action(_timer_dev* timer_dev)
{
    char Alarm_Chan[8];
    Alarm_Chan[0]=timer_dev->chan1;
    Alarm_Chan[1]=timer_dev->chan2;
    Alarm_Chan[2]=timer_dev->chan3;
    Alarm_Chan[3]=timer_dev->chan4;
    Alarm_Chan[4]=timer_dev->chan5;
    Alarm_Chan[5]=timer_dev->chan6;
    Alarm_Chan[6]=timer_dev->chan7;
    Alarm_Chan[7]=timer_dev->chan8;
  
            if((timer_dev->timer_state)!=PROHIBIT)
                {
                    if(Alarm_Chan[0]==1)
                        {
                            if(timer_dev->timer_state==CHAN_OPEN)
                               SetCH1
                            else if(timer_dev->timer_state==CHAN_CLOSE)
                               ResetCH1
                        }
												  if(Alarm_Chan[1]==1)
                        {
                            if(timer_dev->timer_state==CHAN_OPEN)
                               SetCH2
                            else if(timer_dev->timer_state==CHAN_CLOSE)
                               ResetCH2
                        }
												  if(Alarm_Chan[2]==1)
                        {
                            if(timer_dev->timer_state==CHAN_OPEN)
                               SetCH3
                            else if(timer_dev->timer_state==CHAN_CLOSE)
                               ResetCH3
                        }
												  if(Alarm_Chan[3]==1)
                        {
                            if(timer_dev->timer_state==CHAN_OPEN)
                               SetCH4
                            else if(timer_dev->timer_state==CHAN_CLOSE)
                               ResetCH4
                        }
														  if(Alarm_Chan[4]==1)
                        {
                            if(timer_dev->timer_state==CHAN_OPEN)
                               SetCH5
                            else if(timer_dev->timer_state==CHAN_CLOSE)
                               ResetCH5
                        }
														  if(Alarm_Chan[5]==1)
                        {
                            if(timer_dev->timer_state==CHAN_OPEN)
                               SetCH6
                            else if(timer_dev->timer_state==CHAN_CLOSE)
                               ResetCH6
                        }
														  if(Alarm_Chan[6]==1)
                        {
                            if(timer_dev->timer_state==CHAN_OPEN)
                               SetCH7
                            else if(timer_dev->timer_state==CHAN_CLOSE)
                               ResetCH7
                        }
														  if(Alarm_Chan[7]==1)
                        {
                            if(timer_dev->timer_state==CHAN_OPEN)
                               SetCH8
                            else if(timer_dev->timer_state==CHAN_CLOSE)
                               ResetCH8
                        }
                }
         
    Channel_State_Show_();
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
/*闹钟是否循环模式*/
void ISWEEKALARM(_timer_dev *timer_dev,u8 week)
{

    if(timer_dev->mode==LOOP)
        {
            switch(week)
                {
                case 0x01:
                    if(timer_dev->week&0x02)
                        timer_dev->SecCount=Sec_counter(calendar.w_year,calendar.w_month,calendar.w_date,timer_dev->time_hour,timer_dev->time_min,timer_dev->time_sec);
                    else
                        timer_dev->SecCount=0;
                    break;
                case 0x02:
                    if(timer_dev->week&0x04)
                        timer_dev->SecCount=Sec_counter(calendar.w_year,calendar.w_month,calendar.w_date,timer_dev->time_hour,timer_dev->time_min,timer_dev->time_sec);
                    else
                        timer_dev->SecCount=0;
                    break;
                case 0x03:
                    if(timer_dev->week&0x08)
                        timer_dev->SecCount=Sec_counter(calendar.w_year,calendar.w_month,calendar.w_date,timer_dev->time_hour,timer_dev->time_min,timer_dev->time_sec);
                    else
                        timer_dev->SecCount=0;
                    break;
                case 0x04:
                    if(timer_dev->week&0x10)
                        timer_dev->SecCount=Sec_counter(calendar.w_year,calendar.w_month,calendar.w_date,timer_dev->time_hour,timer_dev->time_min,timer_dev->time_sec);
                    else
                        timer_dev->SecCount=0;
                    break;
                case 0x05:
                    if(timer_dev->week&0x20)
                        timer_dev->SecCount=Sec_counter(calendar.w_year,calendar.w_month,calendar.w_date,timer_dev->time_hour,timer_dev->time_min,timer_dev->time_sec);
                    else
                        timer_dev->SecCount=0;
                    break;
                case 0x06:
                    if(timer_dev->week&0x40)
                        timer_dev->SecCount=Sec_counter(calendar.w_year,calendar.w_month,calendar.w_date,timer_dev->time_hour,timer_dev->time_min,timer_dev->time_sec);
                    else
                        timer_dev->SecCount=0;
                    break;
                case 0x00:
                    if(timer_dev->week&0x01)
                        timer_dev->SecCount=Sec_counter(calendar.w_year,calendar.w_month,calendar.w_date,timer_dev->time_hour,timer_dev->time_min,timer_dev_1.time_sec);
                    else
                        timer_dev->SecCount=0;
                    break;
                }
        }

}
