#include "timer_page.h"
#include "gui.h"
#include "lcd.h"
#include "data.h"
#include "flag.h"
#include "touch.h"
#include "delay.h"

extern _m_tp_dev tp_dev;//触屏结构体
extern _flag_dev flag_dev;
char chan_sta[8]= {0,0,0,0,0,0,0,0};
void timer_page_activity()
{


    gui_draw_arcrectangle(95,45,225,30,1,1,BLUE,BLUE);
    gui_draw_arcrectangle(95,77,225,30, 1,1,BLUE,BLUE);
    gui_draw_arcrectangle(95,109,225,30,1,1,BLUE,BLUE);
    gui_draw_arcrectangle(95,141,225,30,1,1,BLUE,BLUE);
    gui_draw_arcrectangle(95,173,225,30,1,1,BLUE,BLUE);

    gui_draw_arcrectangle(160,80,158,24,1,1,WHITE,WHITE);
    gui_draw_arcrectangle(160,48,158,24, 1,1,WHITE,WHITE);
    gui_draw_arcrectangle(160,112,158,24,1,1,WHITE,WHITE);
    gui_draw_arcrectangle(160,144,158,24,1,1,WHITE,WHITE);
    gui_draw_arcrectangle(160,176,158,24,1,1,WHITE,WHITE);

    LCD_DrawLtrigo(95,0,125,40,LEFT,WHITE);
    LCD_DrawLtrigo(290,0,319,40,RIGHT,WHITE);

//    LCD_DrawLtrigo(160,48,185,73,LEFT,BLUE);
//    LCD_DrawLtrigo(292,48,317,73,RIGHT,BLUE);
    LCD_DrawLtrigo(160,48,185,73,LEFT,BLUE);
    LCD_DrawLtrigo(292,48,317,73,RIGHT,BLUE);
    LCD_DrawLtrigo(160,112,185,137,LEFT,BLUE);
    LCD_DrawLtrigo(292,112,317,137,RIGHT,BLUE);

    LCD_Show_3030_String(170,5,"TIMER1",WHITE);
    LCD_Show_2424_String(95, 48,"STATE",WHITE);
    LCD_Show_2424_String(95,80,"CHAN",WHITE);
    LCD_Show_2424_String(95,112,"MODE",WHITE);
    LCD_Show_2424_String(95,144,"DATE",WHITE);
    LCD_Show_2424_String(95,176,"TIME",WHITE);

//    LCD_Show_2424_String(190, 48,"PROHIBIT",BLACK);
//	LCD_Show_2424_String(185, 80, "CHAN OPEN",BLACK);
//  LCD_Show_2424_String(180, 80,"CHAN CLOSE",BLACK);

   

//    LCD_Show_2424_String(220,112,"LOOP",BLACK);

            LCD_Show_2424_String(180,144,"    -  -  ",BLACK);
            LCD_Show_2424_String(180,176,"  :  :  ",BLACK);

            chan_dev=timer_dev_1;//数据赋值给页面变量
		        chan_sta[0]=chan_dev.chan1;
            chan_sta[1]=chan_dev.chan2;
            chan_sta[2]=chan_dev.chan3;
            chan_sta[3]=chan_dev.chan4;
            chan_sta[4]=chan_dev.chan5;
            chan_sta[5]=chan_dev.chan6;
            chan_sta[6]=chan_dev.chan7;
            chan_sta[7]=chan_dev.chan8;		
            timer_data_flash();

    gui_draw_arcrectangle(120,210,80,30,1,1,BLUE,BLUE);
    gui_draw_arcrectangle(125,212,70,28,1,1,WHITE,WHITE);
    LCD_Show_3030_String(130,210,"SAVE",BLUE);
    flag_dev.activity_num=1;//标记为第一个页面
}




void timer_page_action()
{


    if(flag_dev.action_flag==TIMER&&(tp_dev.x[0]>95)&&(tp_dev.x[0]<125)&&(tp_dev.y[0]>0)&&(tp_dev.y[0]<40))
        {
            if(flag_dev.activity_num==1)
                {

                    LCD_Fill(170,0,260,30,RED);
                    LCD_Show_3030_String(170,5,"TIMER3",WHITE);
                    flag_dev.activity_num=3;
                    chan_dev=timer_dev_3;
                   
                   
                }
            else if(flag_dev.activity_num==3)
                {

                    LCD_Fill(170,0,260,30,RED);
                    LCD_Show_3030_String(170,5,"TIMER2",WHITE);
                    flag_dev.activity_num=2;
                    chan_dev=timer_dev_2;

                   
                }
            else if( flag_dev.activity_num==2)
                {
                    LCD_Fill(170,0,260,30,RED);
                    LCD_Show_3030_String(170,5,"TIMER1",WHITE);
                    chan_dev=timer_dev_1;
                    flag_dev.activity_num=1;
                    
                }
            chan_sta[0]=chan_dev.chan1;
            chan_sta[1]=chan_dev.chan2;
            chan_sta[2]=chan_dev.chan3;
            chan_sta[3]=chan_dev.chan4;
            chan_sta[4]=chan_dev.chan5;
            chan_sta[5]=chan_dev.chan6;
            chan_sta[6]=chan_dev.chan7;
            chan_sta[7]=chan_dev.chan8;							
            timer_data_flash();
            delay_ms(300);
        }
    else if(flag_dev.action_flag==TIMER&&(tp_dev.x[0]>290)&&(tp_dev.x[0]<319)&&(tp_dev.y[0]>0)&&(tp_dev.y[0]<40))
        {

            if(flag_dev.activity_num==1)
                {
                    LCD_Fill(170,0,260,30,RED);
                    LCD_Show_3030_String(170,5,"TIMER2",WHITE);
                    chan_dev=timer_dev_2;
                    flag_dev.activity_num=2;
                  
                }
            else if(flag_dev.activity_num==2)
                {
                    LCD_Fill(170,0,260,30,RED);
                    LCD_Show_3030_String(170,5,"TIMER3",WHITE);
                    chan_dev=timer_dev_3;
                    flag_dev.activity_num=3;
                
                }
            else if( flag_dev.activity_num==3)
                {
                    LCD_Fill(170,0,260,30,RED);
                    LCD_Show_3030_String(170,5,"TIMER1",WHITE);
                    chan_dev=timer_dev_1;
                    flag_dev.activity_num=1;
                 
                }

            chan_sta[0]=chan_dev.chan1;
            chan_sta[1]=chan_dev.chan2;
            chan_sta[2]=chan_dev.chan3;
            chan_sta[3]=chan_dev.chan4;
            chan_sta[4]=chan_dev.chan5;
            chan_sta[5]=chan_dev.chan6;
            chan_sta[6]=chan_dev.chan7;
            chan_sta[7]=chan_dev.chan8;
						   timer_data_flash();
            delay_ms(300);
        }
    else if(flag_dev.action_flag==TIMER&&(tp_dev.x[0]>165)&&(tp_dev.x[0]<177)&&(tp_dev.y[0]>80)&&(tp_dev.y[0]<105))
        {
            if(!chan_sta[0])
                {
                    LCD_Show_2424_String(165,80,"1",RED);
                    chan_sta[0]=1;

                    chan_dev.chan1=1;
                }
            else
                {
                    LCD_Show_2424_String(165,80,"1",BLACK);
                    chan_sta[0]=0;
                    chan_dev.chan1=0;
                }
            delay_ms(200);
        }
    else if(flag_dev.action_flag==TIMER&&(tp_dev.x[0]>185)&&(tp_dev.x[0]<197)&&(tp_dev.y[0]>80)&&(tp_dev.y[0]<105))
        {

            if(!chan_sta[1])
                {
                    LCD_Show_2424_String(185,80,"2",RED);
                    chan_sta[1]=1;
                    chan_dev.chan2=1;
                }
            else
                {
                    LCD_Show_2424_String(185,80,"2",BLACK);
                    chan_sta[1]=0;
                    chan_dev.chan2=0;
                }
            delay_ms(200);
        }
    else if(flag_dev.action_flag==TIMER&&(tp_dev.x[0]>205)&&(tp_dev.x[0]<217)&&(tp_dev.y[0]>80)&&(tp_dev.y[0]<105))
        {


            if(!chan_sta[2])
                {
                    LCD_Show_2424_String(205,80,"3",RED);
                    chan_sta[2]=1;
                    chan_dev.chan3=1;
                }
            else
                {
                    LCD_Show_2424_String(205,80,"3",BLACK);
                    chan_sta[2]=0;
                    chan_dev.chan3=0;
                }
            delay_ms(200);

        }
    else if(flag_dev.action_flag==TIMER&&(tp_dev.x[0]>225)&&(tp_dev.x[0]<237)&&(tp_dev.y[0]>80)&&(tp_dev.y[0]<105))
        {


            if(!chan_sta[3])
                {
                    LCD_Show_2424_String(225,80,"4",RED);
                    chan_sta[3]=1;
                    chan_dev.chan4=1;
                }
            else
                {
                    LCD_Show_2424_String(225,80,"4",BLACK);
                    chan_sta[3]=0;
                    chan_dev.chan4=0;
                }


            delay_ms(200);

        }
    else if(flag_dev.action_flag==TIMER&&(tp_dev.x[0]>245)&&(tp_dev.x[0]<257)&&(tp_dev.y[0]>80)&&(tp_dev.y[0]<105))
        {



            if(!chan_sta[4])
                {
                    LCD_Show_2424_String(245,80,"5",RED);
                    chan_sta[4]=1;
                    chan_dev.chan5=1;
                }
            else
                {
                    LCD_Show_2424_String(245,80,"5",BLACK);
                    chan_sta[4]=0;
                    chan_dev.chan5=0;
                }
            delay_ms(200);



        }
    else if(flag_dev.action_flag==TIMER&&(tp_dev.x[0]>265)&&(tp_dev.x[0]<277)&&(tp_dev.y[0]>80)&&(tp_dev.y[0]<105))
        {


            if(!chan_sta[5])
                {
                    LCD_Show_2424_String(265,80,"6",RED);
                    chan_sta[5]=1;
                    chan_dev.chan6=1;
                }
            else
                {
                    LCD_Show_2424_String(265,80,"6",BLACK);
                    chan_sta[5]=0;
                    chan_dev.chan6=0;
                }


            delay_ms(200);




        }
    else if(flag_dev.action_flag==TIMER&&(tp_dev.x[0]>285)&&(tp_dev.x[0]<297)&&(tp_dev.y[0]>80)&&(tp_dev.y[0]<105))
        {

            if(!chan_sta[6])
                {
                    LCD_Show_2424_String(285,80,"7",RED);
                    chan_sta[6]=1;
                    chan_dev.chan7=1;
                }
            else
                {
                    LCD_Show_2424_String(285,80,"7",BLACK);
                    chan_sta[6]=0;
                    chan_dev.chan7=0;
                }

            delay_ms(200);


        }
    else if(flag_dev.action_flag==TIMER&&(tp_dev.x[0]>305)&&(tp_dev.x[0]<317)&&(tp_dev.y[0]>80)&&(tp_dev.y[0]<105))
        {


            if(!chan_sta[7])
                {
                    LCD_Show_2424_String(305,80,"8",RED);
                    chan_sta[7]=1;
                    chan_dev.chan8=1;
                }
            else
                {
                    LCD_Show_2424_String(305,80,"8",BLACK);
                    chan_sta[7]=0;
                    chan_dev.chan8=0;

                }
            delay_ms(200);
        }
    else if(flag_dev.action_flag==TIMER&&(tp_dev.x[0]>160)&&(tp_dev.x[0]<185)&&(tp_dev.y[0]>48)&&(tp_dev.y[0]<73))
        {

            if(chan_dev.timer_state==PROHIBIT)
                {
                    LCD_Fill(180,48,300,71,WHITE);
                    LCD_Show_2424_String(185, 48, "TIMER_ON",BLACK);
                    chan_dev.timer_state=CHAN_OPEN;



                }
            else if(  chan_dev.timer_state==CHAN_OPEN)
                {
                     LCD_Fill(180,48,300,71,WHITE);
                    LCD_Show_2424_String(190, 48,"PROHIBIT",BLACK);
                    chan_dev.timer_state=PROHIBIT;
                }
           


            delay_ms(100);
        }
    else if(flag_dev.action_flag==TIMER&&(tp_dev.x[0]>292)&&(tp_dev.x[0]<317)&&(tp_dev.y[0]>48)&&(tp_dev.y[0]<73))
        {

            if(chan_dev.timer_state==PROHIBIT)
                {
                    LCD_Fill(180,48,300,71,WHITE);
                    LCD_Show_2424_String(185, 48, "TIMER_ON",BLACK);
                    chan_dev.timer_state=CHAN_OPEN;
                }
            else if(  chan_dev.timer_state==CHAN_OPEN)
                {
                    LCD_Fill(180,48,300,71,WHITE);
                    LCD_Show_2424_String(190, 48,"PROHIBIT",BLACK);
                    chan_dev.timer_state=PROHIBIT;
                }

            delay_ms(100);
        }
    else if(flag_dev.action_flag==TIMER&&(tp_dev.x[0]>160)&&(tp_dev.x[0]<185)&&(tp_dev.y[0]>112)&&(tp_dev.y[0]<137))
        {
            if(chan_dev.mode==LOOP)
                {
                    LCD_Fill(180,112,300,135,WHITE);
                    LCD_Show_2424_String(220,112,"ONCE",BLACK);
                    chan_dev.mode=ONCE;

                    gui_draw_arcrectangle(95,141,225,30,1,1,BLUE,BLUE);
                    gui_draw_arcrectangle(160,144,158,24,1,1,WHITE,WHITE);
                    LCD_Show_2424_String(95,144,"DATE",WHITE);
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
                    LCD_Show_2424_String(220,112,"LOOP",BLACK);
                    chan_dev.mode=LOOP;

                    gui_draw_arcrectangle(95,141,225,30,1,1,GRAY,GRAY);
                    gui_draw_arcrectangle(160,144,158,24,1,1,WHITE,WHITE);

                    LCD_Show_2424_String(95,144,"DATE",WHITE);
                    LCD_Show_2424_String(180,144,"    -  -  ",WHITE);
                    LCD_ShowNum(180,144,chan_dev.date_year,4,24,GRAY,WHITE);
                    LCD_ShowNum(240,144,chan_dev.date_month,2,24,GRAY,WHITE);
                    LCD_ShowNum(276,144,chan_dev.date_day,2,24,GRAY,WHITE);

                    LCD_ShowNum(180,176,chan_dev.time_hour,2,24,BLACK,WHITE);
                    LCD_ShowNum(216,176,chan_dev.time_min,2,24,BLACK,WHITE);
                    LCD_ShowNum(252,176,chan_dev.time_sec,2,24,BLACK,WHITE);
                    flag_dev.anchor=0;
                }

            delay_ms(100);
        }
    else if(flag_dev.action_flag==TIMER&&(tp_dev.x[0]>292)&&(tp_dev.x[0]<317)&&(tp_dev.y[0]>112)&&(tp_dev.y[0]<137))
        {
            if(chan_dev.mode==LOOP)
                {
                    LCD_Fill(180,112,280,135,WHITE);
                    LCD_Show_2424_String(220,112,"ONCE",BLACK);
                    chan_dev.mode=ONCE;
                    gui_draw_arcrectangle(95,141,225,30,1,1,BLUE,BLUE);
                    gui_draw_arcrectangle(160,144,158,24,1,1,WHITE,WHITE);

                    LCD_Show_2424_String(95,144,"DATE",WHITE);
                    LCD_Show_2424_String(180,144,"    -  -  ",BLACK);
                    LCD_ShowNum(180,144,chan_dev.date_year,4,24,BLACK,WHITE);
                    LCD_ShowNum(240,144,chan_dev.date_month,2,24,BLACK,WHITE);
                    LCD_ShowNum(276,144,chan_dev.date_day,2,24,BLACK,WHITE);



                }
            else if(chan_dev.mode==ONCE)
                {
                    LCD_Fill(180,112,280,135,WHITE);
                    LCD_Show_2424_String(220,112,"LOOP",BLACK);
                    chan_dev.mode=LOOP;

                    gui_draw_arcrectangle(95,141,225,30,1,1,GRAY,GRAY);
                    gui_draw_arcrectangle(160,144,158,24,1,1,WHITE,WHITE);

                    LCD_Show_2424_String(95,144,"DATE",WHITE);
                    LCD_Show_2424_String(180,144,"    -  -  ",GRAY);
                    LCD_ShowNum(180,144,chan_dev.date_year,4,24,GRAY,WHITE);
                    LCD_ShowNum(240,144,chan_dev.date_month,2,24,GRAY,WHITE);
                    LCD_ShowNum(276,144,chan_dev.date_day,2,24,GRAY,WHITE);

                    LCD_ShowNum(180,176,chan_dev.time_hour,2,24,BLACK,WHITE);
                    LCD_ShowNum(216,176,chan_dev.time_min,2,24,BLACK,WHITE);
                    LCD_ShowNum(252,176,chan_dev.time_sec,2,24,BLACK,WHITE);
                    flag_dev.anchor=0;
                }

            delay_ms(100);
        }
    else if(flag_dev.action_flag==TIMER&&(tp_dev.x[0]>180)&&(tp_dev.x[0]<228)&&(tp_dev.y[0]>144)&&(tp_dev.y[0]<168))
        {
            if(chan_dev.mode==ONCE)
                {
                    LCD_ShowNum(180,144,chan_dev.date_year,4,24,WHITE,RED);
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
                    LCD_ShowNum(240,144,chan_dev.date_month,2,24,WHITE,RED);
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
                    LCD_ShowNum(276,144,chan_dev.date_day,2,24,WHITE,RED);
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
            LCD_ShowNum(180,176,chan_dev.time_hour,2,24,WHITE,RED);
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
            LCD_ShowNum(216,176,chan_dev.time_min,2,24,WHITE,RED);
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
            LCD_ShowNum(252,176,chan_dev.time_sec,2,24,WHITE,RED);
            flag_dev.anchor=6;
        }


}


void timer_data_flash()
{


    if(chan_dev.timer_state==CHAN_OPEN)
        {
            LCD_Fill(180,48,300,71,WHITE);
            LCD_Show_2424_String(185, 48, "TIMER_ON",BLACK);
     


        }
   
    else if(  chan_dev.timer_state==PROHIBIT)
        {
            LCD_Fill(180,48,300,71,WHITE);
            LCD_Show_2424_String(190, 48,"PROHIBIT",BLACK);

        }

    if(chan_sta[0])
        {
            LCD_Show_2424_String(165,80,"1",RED);   
        }
    else
        {
            LCD_Show_2424_String(165,80,"1",BLACK);
    
        }

    if(chan_sta[1])
        {
            LCD_Show_2424_String(185,80,"2",RED);
       
        }
    else
        {
            LCD_Show_2424_String(185,80,"2",BLACK);
    
        }


    if(chan_sta[2])
        {
            LCD_Show_2424_String(205,80,"3",RED);
    
        }
    else
        {
            LCD_Show_2424_String(205,80,"3",BLACK);

        }
    if(chan_sta[3])
        {
            LCD_Show_2424_String(225,80,"4",RED);

        }
    else
        {
            LCD_Show_2424_String(225,80,"4",BLACK);

        }

    if(chan_sta[4])
        {
            LCD_Show_2424_String(245,80,"5",RED);
   
        }
    else
        {
            LCD_Show_2424_String(245,80,"5",BLACK);
     
        }
    if(chan_sta[5])
        {
            LCD_Show_2424_String(265,80,"6",RED);
 
        }
    else
        {
            LCD_Show_2424_String(265,80,"6",BLACK);
  
        }


    if(chan_sta[6])
        {
            LCD_Show_2424_String(285,80,"7",RED);
 
        }
    else
        {
            LCD_Show_2424_String(285,80,"7",BLACK);
 
        }
    if(chan_sta[7])
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
            LCD_Show_2424_String(220,112,"ONCE",BLACK);
            gui_draw_arcrectangle(95,141,225,30,1,1,BLUE,BLUE);
            gui_draw_arcrectangle(160,144,158,24,1,1,WHITE,WHITE);

            LCD_Show_2424_String(95,144,"DATE",WHITE);
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
            LCD_Show_2424_String(220,112,"LOOP",BLACK);


            gui_draw_arcrectangle(95,141,225,30,1,1,GRAY,GRAY);
            gui_draw_arcrectangle(160,144,158,24,1,1,WHITE,WHITE);

            LCD_Show_2424_String(95,144,"DATE",WHITE);
            LCD_Show_2424_String(180,144,"    -  -  ",GRAY);
            LCD_ShowNum(180,144,chan_dev.date_year,4,24,GRAY,WHITE);
            LCD_ShowNum(240,144,chan_dev.date_month,2,24,GRAY,WHITE);
            LCD_ShowNum(276,144,chan_dev.date_day,2,24,GRAY,WHITE);

            LCD_ShowNum(180,176,chan_dev.time_hour,2,24,BLACK,WHITE);
            LCD_ShowNum(216,176,chan_dev.time_min,2,24,BLACK,WHITE);
            LCD_ShowNum(252,176,chan_dev.time_sec,2,24,BLACK,WHITE);
        }

}


