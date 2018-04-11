#include "delay_setting_page.h"
#include "gui.h"
#include "lcd.h"
#include  "touch.h"
#include "flag.h"
#include "delay.h"
#include "data.h"


extern _m_tp_dev tp_dev;//触屏结构体
extern _flag_dev flag_dev;
extern _chan_data chan_data;

void delay_setting_page_activity()
{

    gui_draw_arcrectangle(94,43,226,40,4,1,BLUE,BLUE);
    gui_draw_arcrectangle(94,85,226,40,4,1,BLUE,BLUE);
    gui_draw_arcrectangle(94,127,226,40,4,1,BLUE,BLUE);
    gui_draw_arcrectangle(94,169,226,38,4,1,BLUE,BLUE);

    gui_draw_arcrectangle(172,48, 145,30,4,1,WHITE,WHITE);
    gui_draw_arcrectangle(172,90, 145,30,4,1,WHITE,WHITE);
    gui_draw_arcrectangle(172,131,145,30,4,1,WHITE,WHITE);
    gui_draw_arcrectangle(172,173,145,30,4,1,WHITE,WHITE);

    LCD_DrawLtrigo(95,0,125,40,LEFT,WHITE);
    LCD_DrawLtrigo(290,0,319,40,RIGHT,WHITE);
   if(flag_dev.langage==1){
    LCD_Show_3030_String(125,5,"CHAN OPEN1/2",WHITE);
    //LCD_Show_3030_String(140,5,"CHAN CLOSE",WHITE);
	 }else{
    ShowTwoChineseChar(145,11,2,3,24,WHITE);
    ShowTwoChineseChar(193,11,4,5,24,WHITE);
    LCD_Show_2424_String(241,14,"1/2",WHITE);
	 }
   if(flag_dev.langage==1){
    LCD_Show_2424_String(100,50,"CHAN1",WHITE);
    LCD_Show_2424_String(100,92,"CHAN2",WHITE);
    LCD_Show_2424_String(100,133,"CHAN3",WHITE);
    LCD_Show_2424_String(100,175,"CHAN4",WHITE);
   }else{
    ShowTwoChineseChar(100,50,0,1,24,WHITE);
    LCD_Show_2424_String(148,50,"1",WHITE);
    ShowTwoChineseChar(100,92,0,1,24,WHITE);
    LCD_Show_2424_String(148,92,"2",WHITE);
    ShowTwoChineseChar(100,133,0,1,24,WHITE);
    LCD_Show_2424_String(148,133,"3",WHITE);
    ShowTwoChineseChar(100,175,0,1,24,WHITE);
    LCD_Show_2424_String(148,175,"4",WHITE);
	 }
    flag_dev.activity_num=1;

    LCD_ShowNum(220,48,chan_open_data.chan1,3,30,BLACK,WHITE);
    LCD_Show_3030_String(265,48,"s",BLACK);
    LCD_ShowNum(220,90,chan_open_data.chan2,3,30,BLACK,WHITE);
    LCD_Show_3030_String(265,90,"s",BLACK);
    LCD_ShowNum(220,131,chan_open_data.chan3,3,30,BLACK,WHITE);
    LCD_Show_3030_String(265,131,"s",BLACK);
    LCD_ShowNum(220,173,chan_open_data.chan4,3,30,BLACK,WHITE);
    LCD_Show_3030_String(265,173,"s",BLACK);


    chan_data.data1=chan_open_data.chan1;
    chan_data.data2=chan_open_data.chan2;
    chan_data.data3=chan_open_data.chan3;
    chan_data.data4=chan_open_data.chan4;


    gui_draw_arcrectangle(120,210,80,30,1,1,BLUE,BLUE);
    gui_draw_arcrectangle(125,212,70,28,1,1,WHITE,WHITE);
		if(flag_dev.langage==0)
		  ShowTwoChineseChar(135,213,10,11,24,BLACK);
		else
    LCD_Show_3030_String(130,210,"SAVE",BLACK);
  

}

void delay_setting_page_action()
{

    if(flag_dev.action_flag!=DELAY)
        {

            chan_data.data1=0;
            chan_data.data2=0;
            chan_data.data3=0;
            chan_data.data4=0;

        }//清除中间变量

    if(flag_dev.action_flag==DELAY&&(tp_dev.x[0]>92)&&(tp_dev.x[0]<132)&&(tp_dev.y[0]>0)&&(tp_dev.y[0]<40))
        {
            delay_ms(100);//防止切换过快
            if(flag_dev.activity_num==2)
                {
                    gui_draw_arcrectangle(115,0,190,40,1,1,RED,RED);
									  if(flag_dev.langage==1){
                    LCD_Show_3030_String(125,5,"CHAN OPEN1/2",WHITE);
										}else{
                    ShowTwoChineseChar(145,11,2,3,24,WHITE);
                    ShowTwoChineseChar(193,11,4,5,24,WHITE);
                    LCD_Show_2424_String(241,14,"1/2",WHITE);
										}
                    gui_draw_arcrectangle(94,43,226,40,4,1,BLUE,BLUE);
                    gui_draw_arcrectangle(94,85,226,40,4,1,BLUE,BLUE);
                    gui_draw_arcrectangle(94,127,226,40,4,1,BLUE,BLUE);
                    gui_draw_arcrectangle(94,169,226,38,4,1,BLUE,BLUE);

                    gui_draw_arcrectangle(172,48, 145,30,4,1,WHITE,WHITE);
                    gui_draw_arcrectangle(172,90, 145,30,4,1,WHITE,WHITE);
                    gui_draw_arcrectangle(172,131,145,30,4,1,WHITE,WHITE);
                    gui_draw_arcrectangle(172,173,145,30,4,1,WHITE,WHITE);
                   if(flag_dev.langage==1){
                    LCD_Show_2424_String(100,50,"CHAN1",WHITE);
                    LCD_Show_2424_String(100,92,"CHAN2",WHITE);
                    LCD_Show_2424_String(100,133,"CHAN3",WHITE);
                    LCD_Show_2424_String(100,175,"CHAN4",WHITE);
									 }else{
                    ShowTwoChineseChar(100,50,0,1,24,WHITE);
                    LCD_Show_2424_String(148,50,"1",WHITE);
                    ShowTwoChineseChar(100,92,0,1,24,WHITE);
                    LCD_Show_2424_String(148,92,"2",WHITE);
                    ShowTwoChineseChar(100,133,0,1,24,WHITE);
                    LCD_Show_2424_String(148,133,"3",WHITE);
                    ShowTwoChineseChar(100,175,0,1,24,WHITE);
                    LCD_Show_2424_String(148,175,"4",WHITE);
									 }
                    LCD_ShowNum(220,48,chan_open_data.chan1,3,30,BLACK,WHITE);
                    LCD_Show_3030_String(265,48,"s",BLACK);
                    LCD_ShowNum(220,90,chan_open_data.chan2,3,30,BLACK,WHITE);
                    LCD_Show_3030_String(265,90,"s",BLACK);
                    LCD_ShowNum(220,131,chan_open_data.chan3,3,30,BLACK,WHITE);
                    LCD_Show_3030_String(265,131,"s",BLACK);
                    LCD_ShowNum(220,173,chan_open_data.chan4,3,30,BLACK,WHITE);
                    LCD_Show_3030_String(265,173,"s",BLACK);

                    chan_data.data1=chan_open_data.chan1;
                    chan_data.data2=chan_open_data.chan2;
                    chan_data.data3=chan_open_data.chan3;
                    chan_data.data4=chan_open_data.chan4;

                    flag_dev.anchor=0;
                    flag_dev.activity_num=1;
                }
            else if(flag_dev.activity_num==1)
                {

                    gui_draw_arcrectangle(115,0,190,40,1,1,RED,RED);
									  if(flag_dev.langage==1){
                    LCD_Show_3030_String(115,5,"CHAN CLOSE2/2",WHITE);
										}else{
                    ShowTwoChineseChar(145,11,2,3,24,WHITE);
                    ShowTwoChineseChar(193,11,6,7,24,WHITE);
                    LCD_Show_2424_String(241,14,"2/2",WHITE);
										}
                    gui_draw_arcrectangle(94,43,226,40,4,1,BLUE,BLUE);
                    gui_draw_arcrectangle(94,85,226,40,4,1,BLUE,BLUE);
                    gui_draw_arcrectangle(94,127,226,40,4,1,BLUE,BLUE);
                    gui_draw_arcrectangle(94,169,226,38,4,1,BLUE,BLUE);

                    gui_draw_arcrectangle(172,48, 145,30,4,1,WHITE,WHITE);
                    gui_draw_arcrectangle(172,90, 145,30,4,1,WHITE,WHITE);
                    gui_draw_arcrectangle(172,131,145,30,4,1,WHITE,WHITE);
                    gui_draw_arcrectangle(172,173,145,30,4,1,WHITE,WHITE);

                    if(flag_dev.langage==1){
                    LCD_Show_2424_String(100,50,"CHAN5",WHITE);
                    LCD_Show_2424_String(100,92,"CHAN6",WHITE);
                    LCD_Show_2424_String(100,133,"CHAN7",WHITE);
                    LCD_Show_2424_String(100,175,"CHAN8",WHITE);
										}else{
										
                    ShowTwoChineseChar(100,50,0,1,24,WHITE);
                    LCD_Show_2424_String(148,50,"5",WHITE);
                    ShowTwoChineseChar(100,92,0,1,24,WHITE);
                    LCD_Show_2424_String(148,92,"6",WHITE);
                    ShowTwoChineseChar(100,133,0,1,24,WHITE);
                    LCD_Show_2424_String(148,133,"7",WHITE);
                    ShowTwoChineseChar(100,175,0,1,24,WHITE);
                    LCD_Show_2424_String(148,175,"8",WHITE);
										}
                    LCD_ShowNum(220,48,chan_close_data.chan5,3,30,BLACK,WHITE);
                    LCD_Show_3030_String(265,48,"s",BLACK);
                    LCD_ShowNum(220,90,chan_close_data.chan6,3,30,BLACK,WHITE);
                    LCD_Show_3030_String(265,90,"s",BLACK);
                    LCD_ShowNum(220,131,chan_close_data.chan7,3,30,BLACK,WHITE);
                    LCD_Show_3030_String(265,131,"s",BLACK);
                    LCD_ShowNum(220,173,chan_close_data.chan8,3,30,BLACK,WHITE);
                    LCD_Show_3030_String(265,173,"s",BLACK);

                    flag_dev.activity_num=4;

                    chan_data.data1=chan_close_data.chan5;
                    chan_data.data2=chan_close_data.chan6;
                    chan_data.data3=chan_close_data.chan7;
                    chan_data.data4=chan_close_data.chan8;
                    flag_dev.anchor=0;

                }
            else if(flag_dev.activity_num==4)
                {

                    gui_draw_arcrectangle(115,0,190,40,1,1,RED,RED);
									  if(flag_dev.langage==1){
                    LCD_Show_3030_String(115,5,"CHAN CLOSE1/2",WHITE);
									  }else{
                    ShowTwoChineseChar(145,11,2,3,24,WHITE);
                    ShowTwoChineseChar(193,11,6,7,24,WHITE);
                    LCD_Show_2424_String(241,14,"1/2",WHITE);
									  }
                    gui_draw_arcrectangle(94,43,226,40,4,1,BLUE,BLUE);
                    gui_draw_arcrectangle(94,85,226,40,4,1,BLUE,BLUE);
                    gui_draw_arcrectangle(94,127,226,40,4,1,BLUE,BLUE);
                    gui_draw_arcrectangle(94,169,226,38,4,1,BLUE,BLUE);

                    gui_draw_arcrectangle(172,48, 145,30,4,1,WHITE,WHITE);
                    gui_draw_arcrectangle(172,90, 145,30,4,1,WHITE,WHITE);
                    gui_draw_arcrectangle(172,131,145,30,4,1,WHITE,WHITE);
                    gui_draw_arcrectangle(172,173,145,30,4,1,WHITE,WHITE);

                    LCD_ShowNum(220,48,chan_close_data.chan1,3,30,BLACK,WHITE);
                    LCD_Show_3030_String(265,48,"s",BLACK);
                    LCD_ShowNum(220,90,chan_close_data.chan2,3,30,BLACK,WHITE);
                    LCD_Show_3030_String(265,90,"s",BLACK);
                    LCD_ShowNum(220,131,chan_close_data.chan3,3,30,BLACK,WHITE);
                    LCD_Show_3030_String(265,131,"s",BLACK);
                    LCD_ShowNum(220,173,chan_close_data.chan4,3,30,BLACK,WHITE);
                    LCD_Show_3030_String(265,173,"s",BLACK);

                    if(flag_dev.langage==1){
                    LCD_Show_2424_String(100,50,"CHAN1",WHITE);
                    LCD_Show_2424_String(100,92,"CHAN2",WHITE);
                    LCD_Show_2424_String(100,133,"CHAN3",WHITE);
                    LCD_Show_2424_String(100,175,"CHAN4",WHITE);
                    }else{
                    ShowTwoChineseChar(100,50,0,1,24,WHITE);
                    LCD_Show_2424_String(148,50,"1",WHITE);
                    ShowTwoChineseChar(100,92,0,1,24,WHITE);
                    LCD_Show_2424_String(148,92,"2",WHITE);
                    ShowTwoChineseChar(100,133,0,1,24,WHITE);
                    LCD_Show_2424_String(148,133,"3",WHITE);
                    ShowTwoChineseChar(100,175,0,1,24,WHITE);
                    LCD_Show_2424_String(148,175,"4",WHITE);
										}
                    flag_dev.activity_num=3;

                    chan_data.data1=chan_close_data.chan1;
                    chan_data.data2=chan_close_data.chan2;
                    chan_data.data3=chan_close_data.chan3;
                    chan_data.data4=chan_close_data.chan4;

                    flag_dev.anchor=0;

                }
            else if(flag_dev.activity_num==3)
                {
                    gui_draw_arcrectangle(115,0,190,40,1,1,RED,RED);
									  if(flag_dev.langage==1){
                     LCD_Show_3030_String(125,5,"CHAN OPEN2/2",WHITE);
										}else{
                    ShowTwoChineseChar(145,11,2,3,24,WHITE);
                    ShowTwoChineseChar(193,11,4,5,24,WHITE);
                    LCD_Show_2424_String(241,14,"2/2",WHITE);
										}
                    gui_draw_arcrectangle(94,43,226,40,4,1,BLUE,BLUE);
                    gui_draw_arcrectangle(94,85,226,40,4,1,BLUE,BLUE);
                    gui_draw_arcrectangle(94,127,226,40,4,1,BLUE,BLUE);
                    gui_draw_arcrectangle(94,169,226,38,4,1,BLUE,BLUE);

                    gui_draw_arcrectangle(172,48, 145,30,4,1,WHITE,WHITE);
                    gui_draw_arcrectangle(172,90, 145,30,4,1,WHITE,WHITE);
                    gui_draw_arcrectangle(172,131,145,30,4,1,WHITE,WHITE);
                    gui_draw_arcrectangle(172,173,145,30,4,1,WHITE,WHITE);

                    LCD_ShowNum(220,48,chan_open_data.chan5,3,30,BLACK,WHITE);
                    LCD_Show_3030_String(265,48,"s",BLACK);
                    LCD_ShowNum(220,90,chan_open_data.chan6,3,30,BLACK,WHITE);
                    LCD_Show_3030_String(265,90,"s",BLACK);
                    LCD_ShowNum(220,131,chan_open_data.chan7,3,30,BLACK,WHITE);
                    LCD_Show_3030_String(265,131,"s",BLACK);
                    LCD_ShowNum(220,173,chan_open_data.chan8,3,30,BLACK,WHITE);
                    LCD_Show_3030_String(265,173,"s",BLACK);
										
                    if(flag_dev.langage==1){
                    LCD_Show_2424_String(100,50,"CHAN5",WHITE);
                    LCD_Show_2424_String(100,92,"CHAN6",WHITE);
                    LCD_Show_2424_String(100,133,"CHAN7",WHITE);
                    LCD_Show_2424_String(100,175,"CHAN8",WHITE);
										}else{
                    ShowTwoChineseChar(100,50,0,1,24,WHITE);
                    LCD_Show_2424_String(148,50,"5",WHITE);
                    ShowTwoChineseChar(100,92,0,1,24,WHITE);
                    LCD_Show_2424_String(148,92,"6",WHITE);
                    ShowTwoChineseChar(100,133,0,1,24,WHITE);
                    LCD_Show_2424_String(148,133,"7",WHITE);
                    ShowTwoChineseChar(100,175,0,1,24,WHITE);
                    LCD_Show_2424_String(148,175,"8",WHITE);
										}
                    flag_dev.activity_num=2;

                    chan_data.data1=chan_open_data.chan5;
                    chan_data.data2=chan_open_data.chan6;
                    chan_data.data3=chan_open_data.chan7;
                    chan_data.data4=chan_open_data.chan8;

                    flag_dev.anchor=0;
                }

        }
    else if(flag_dev.action_flag==DELAY&&(tp_dev.x[0]>279)&&(tp_dev.x[0]<319)&&(tp_dev.y[0]>0)&&(tp_dev.y[0]<40))
        {
            delay_ms(100);//防止切换过快
            if(flag_dev.activity_num==1)
                {
                    gui_draw_arcrectangle(115,0,190,40,1,1,RED,RED);
									  if(flag_dev.langage==1)
                    LCD_Show_3030_String(125,5,"CHAN OPEN2/2",WHITE);
									  else{
                    ShowTwoChineseChar(145,11,2,3,24,WHITE);
                    ShowTwoChineseChar(193,11,4,5,24,WHITE);
                    LCD_Show_2424_String(241,14,"2/2",WHITE);
										}
                    gui_draw_arcrectangle(94,43,226,40,4,1,BLUE,BLUE);
                    gui_draw_arcrectangle(94,85,226,40,4,1,BLUE,BLUE);
                    gui_draw_arcrectangle(94,127,226,40,4,1,BLUE,BLUE);
                    gui_draw_arcrectangle(94,169,226,38,4,1,BLUE,BLUE);

                    gui_draw_arcrectangle(172,48, 145,30,4,1,WHITE,WHITE);
                    gui_draw_arcrectangle(172,90, 145,30,4,1,WHITE,WHITE);
                    gui_draw_arcrectangle(172,131,145,30,4,1,WHITE,WHITE);
                    gui_draw_arcrectangle(172,173,145,30,4,1,WHITE,WHITE);

                    LCD_ShowNum(220,48,chan_open_data.chan5,3,30,BLACK,WHITE);
                    LCD_Show_3030_String(265,48,"s",BLACK);
                    LCD_ShowNum(220,90,chan_open_data.chan6,3,30,BLACK,WHITE);
                    LCD_Show_3030_String(265,90,"s",BLACK);
                    LCD_ShowNum(220,131,chan_open_data.chan7,3,30,BLACK,WHITE);
                    LCD_Show_3030_String(265,131,"s",BLACK);
                    LCD_ShowNum(220,173,chan_open_data.chan8,3,30,BLACK,WHITE);
                    LCD_Show_3030_String(265,173,"s",BLACK);

                    if(flag_dev.langage==1){
                    LCD_Show_2424_String(100,50,"CHAN5",WHITE);
                    LCD_Show_2424_String(100,92,"CHAN6",WHITE);
                    LCD_Show_2424_String(100,133,"CHAN7",WHITE);
                    LCD_Show_2424_String(100,175,"CHAN8",WHITE);
										}else{
                    ShowTwoChineseChar(100,50,0,1,24,WHITE);
                    LCD_Show_2424_String(148,50,"5",WHITE);
                    ShowTwoChineseChar(100,92,0,1,24,WHITE);
                    LCD_Show_2424_String(148,92,"6",WHITE);
                    ShowTwoChineseChar(100,133,0,1,24,WHITE);
                    LCD_Show_2424_String(148,133,"7",WHITE);
                    ShowTwoChineseChar(100,175,0,1,24,WHITE);
                    LCD_Show_2424_String(148,175,"8",WHITE);
										}
                    chan_data.data1=chan_open_data.chan5;
                    chan_data.data2=chan_open_data.chan6;
                    chan_data.data3=chan_open_data.chan7;
                    chan_data.data4=chan_open_data.chan8;


                    flag_dev.activity_num=2;

                    flag_dev.anchor=0;

                }
            else if( flag_dev.activity_num==2)
                {

                    gui_draw_arcrectangle(115,0,190,40,1,1,RED,RED);
									  if(flag_dev.langage==1){
                    LCD_Show_3030_String(115,5,"CHAN CLOSE1/2",WHITE);
									  }else{
                    ShowTwoChineseChar(145,11,2,3,24,WHITE);
                    ShowTwoChineseChar(193,11,6,7,24,WHITE);
                    LCD_Show_2424_String(241,14,"1/2",WHITE);
									  }
                    gui_draw_arcrectangle(94,43,226,40,4,1,BLUE,BLUE);
                    gui_draw_arcrectangle(94,85,226,40,4,1,BLUE,BLUE);
                    gui_draw_arcrectangle(94,127,226,40,4,1,BLUE,BLUE);
                    gui_draw_arcrectangle(94,169,226,38,4,1,BLUE,BLUE);

                    gui_draw_arcrectangle(172,48, 145,30,4,1,WHITE,WHITE);
                    gui_draw_arcrectangle(172,90, 145,30,4,1,WHITE,WHITE);
                    gui_draw_arcrectangle(172,131,145,30,4,1,WHITE,WHITE);
                    gui_draw_arcrectangle(172,173,145,30,4,1,WHITE,WHITE);

                    LCD_ShowNum(220,48,chan_close_data.chan1,3,30,BLACK,WHITE);
                    LCD_Show_3030_String(265,48,"s",BLACK);
                    LCD_ShowNum(220,90,chan_close_data.chan2,3,30,BLACK,WHITE);
                    LCD_Show_3030_String(265,90,"s",BLACK);
                    LCD_ShowNum(220,131,chan_close_data.chan3,3,30,BLACK,WHITE);
                    LCD_Show_3030_String(265,131,"s",BLACK);
                    LCD_ShowNum(220,173,chan_close_data.chan4,3,30,BLACK,WHITE);
                    LCD_Show_3030_String(265,173,"s",BLACK);


                    if(flag_dev.langage==1){
                    LCD_Show_2424_String(100,50,"CHAN1",WHITE);
                    LCD_Show_2424_String(100,92,"CHAN2",WHITE);
                    LCD_Show_2424_String(100,133,"CHAN3",WHITE);
                    LCD_Show_2424_String(100,175,"CHAN4",WHITE);
                    }else{
                    ShowTwoChineseChar(100,50,0,1,24,WHITE);
                    LCD_Show_2424_String(148,50,"1",WHITE);
                    ShowTwoChineseChar(100,92,0,1,24,WHITE);
                    LCD_Show_2424_String(148,92,"2",WHITE);
                    ShowTwoChineseChar(100,133,0,1,24,WHITE);
                    LCD_Show_2424_String(148,133,"3",WHITE);
                    ShowTwoChineseChar(100,175,0,1,24,WHITE);
                    LCD_Show_2424_String(148,175,"4",WHITE);
                    }
                    flag_dev.activity_num=3;

                    chan_data.data1=chan_close_data.chan1;
                    chan_data.data2=chan_close_data.chan2;
                    chan_data.data3=chan_close_data.chan3;
                    chan_data.data4=chan_close_data.chan4;
                    flag_dev.anchor=0;

                }
            else if( flag_dev.activity_num==3)
                {

                    gui_draw_arcrectangle(115,0,190,40,1,1,RED,RED);
									 
									 if(flag_dev.langage==1){
                    LCD_Show_3030_String(115,5,"CHAN CLOSE2/2",WHITE);
									  }else{
                    ShowTwoChineseChar(145,11,2,3,24,WHITE);
                    ShowTwoChineseChar(193,11,6,7,24,WHITE);
                    LCD_Show_2424_String(241,14,"2/2",WHITE);
									  }
                    gui_draw_arcrectangle(94,43,226,40,4,1,BLUE,BLUE);
                    gui_draw_arcrectangle(94,85,226,40,4,1,BLUE,BLUE);
                    gui_draw_arcrectangle(94,127,226,40,4,1,BLUE,BLUE);
                    gui_draw_arcrectangle(94,169,226,38,4,1,BLUE,BLUE);

                    gui_draw_arcrectangle(172,48, 145,30,4,1,WHITE,WHITE);
                    gui_draw_arcrectangle(172,90, 145,30,4,1,WHITE,WHITE);
                    gui_draw_arcrectangle(172,131,145,30,4,1,WHITE,WHITE);
                    gui_draw_arcrectangle(172,173,145,30,4,1,WHITE,WHITE);


                    LCD_ShowNum(220,48,chan_close_data.chan5,3,30,BLACK,WHITE);
                    LCD_Show_3030_String(265,48,"s",BLACK);
                    LCD_ShowNum(220,90,chan_close_data.chan6,3,30,BLACK,WHITE);
                    LCD_Show_3030_String(265,90,"s",BLACK);
                    LCD_ShowNum(220,131,chan_close_data.chan7,3,30,BLACK,WHITE);
                    LCD_Show_3030_String(265,131,"s",BLACK);
                    LCD_ShowNum(220,173,chan_close_data.chan8,3,30,BLACK,WHITE);
                    LCD_Show_3030_String(265,173,"s",BLACK);

                    if(flag_dev.langage==1){
                    LCD_Show_2424_String(100,50,"CHAN5",WHITE);
                    LCD_Show_2424_String(100,92,"CHAN6",WHITE);
                    LCD_Show_2424_String(100,133,"CHAN7",WHITE);
                    LCD_Show_2424_String(100,175,"CHAN8",WHITE);
                    }else{
                    ShowTwoChineseChar(100,50,0,1,24,WHITE);
                    LCD_Show_2424_String(148,50,"5",WHITE);
                    ShowTwoChineseChar(100,92,0,1,24,WHITE);
                    LCD_Show_2424_String(148,92,"6",WHITE);
                    ShowTwoChineseChar(100,133,0,1,24,WHITE);
                    LCD_Show_2424_String(148,133,"7",WHITE);
                    ShowTwoChineseChar(100,175,0,1,24,WHITE);
                    LCD_Show_2424_String(148,175,"8",WHITE);
										}
                    flag_dev.activity_num=4;

                    chan_data.data1=chan_close_data.chan5;
                    chan_data.data2=chan_close_data.chan6;
                    chan_data.data3=chan_close_data.chan7;
                    chan_data.data4=chan_close_data.chan8;
                    flag_dev.anchor=0;

                }
            else if( flag_dev.activity_num==4)
                {
                    gui_draw_arcrectangle(115,0,190,40,1,1,RED,RED);
									  if(flag_dev.langage==1){
                    LCD_Show_3030_String(125,5,"CHAN OPEN1/2",WHITE);
										}else{
                    ShowTwoChineseChar(145,11,2,3,24,WHITE);
                    ShowTwoChineseChar(193,11,4,5,24,WHITE);
                    LCD_Show_2424_String(241,14,"1/2",WHITE);
										}
                    gui_draw_arcrectangle(94,43,226,40,4,1,BLUE,BLUE);
                    gui_draw_arcrectangle(94,85,226,40,4,1,BLUE,BLUE);
                    gui_draw_arcrectangle(94,127,226,40,4,1,BLUE,BLUE);
                    gui_draw_arcrectangle(94,169,226,38,4,1,BLUE,BLUE);


                    gui_draw_arcrectangle(172,48, 145,30,4,1,WHITE,WHITE);
                    gui_draw_arcrectangle(172,90, 145,30,4,1,WHITE,WHITE);
                    gui_draw_arcrectangle(172,131,145,30,4,1,WHITE,WHITE);
                    gui_draw_arcrectangle(172,173,145,30,4,1,WHITE,WHITE);


                    LCD_ShowNum(220,48,chan_open_data.chan1,3,30,BLACK,WHITE);
                    LCD_Show_3030_String(265,48,"s",BLACK);
                    LCD_ShowNum(220,90,chan_open_data.chan2,3,30,BLACK,WHITE);
                    LCD_Show_3030_String(265,90,"s",BLACK);
                    LCD_ShowNum(220,131,chan_open_data.chan3,3,30,BLACK,WHITE);
                    LCD_Show_3030_String(265,131,"s",BLACK);
                    LCD_ShowNum(220,173,chan_open_data.chan4,3,30,BLACK,WHITE);
                    LCD_Show_3030_String(265,173,"s",BLACK);
                    if(flag_dev.langage==1){
                    LCD_Show_2424_String(100,50,"CHAN1",WHITE);
                    LCD_Show_2424_String(100,92,"CHAN2",WHITE);
                    LCD_Show_2424_String(100,133,"CHAN3",WHITE);
                    LCD_Show_2424_String(100,175,"CHAN4",WHITE);
                    }else{
                    ShowTwoChineseChar(100,50,0,1,24,WHITE);
                    LCD_Show_2424_String(148,50,"1",WHITE);
                    ShowTwoChineseChar(100,92,0,1,24,WHITE);
                    LCD_Show_2424_String(148,92,"2",WHITE);
                    ShowTwoChineseChar(100,133,0,1,24,WHITE);
                    LCD_Show_2424_String(148,133,"3",WHITE);
                    ShowTwoChineseChar(100,175,0,1,24,WHITE);
                    LCD_Show_2424_String(148,175,"4",WHITE);
                    }
                    flag_dev.activity_num=1;

                    chan_data.data1=chan_open_data.chan1;
                    chan_data.data2=chan_open_data.chan2;
                    chan_data.data3=chan_open_data.chan3;
                    chan_data.data4=chan_open_data.chan4;
                    flag_dev.anchor=0;
                }

        }
    else if(flag_dev.action_flag==DELAY&&(tp_dev.x[0]>95)&&(tp_dev.x[0]<319)&&(tp_dev.y[0]>45)&&(tp_dev.y[0]<80))
        {

            LCD_ShowNum(220,48,chan_data.data1,3,30,RED,WHITE);
            LCD_Show_3030_String(265,48,"s",BLACK);
            LCD_ShowNum(220,90,chan_data.data2,3,30,BLACK,WHITE);
            LCD_Show_3030_String(265,90,"s",BLACK);
            LCD_ShowNum(220,131,chan_data.data3,3,30,BLACK,WHITE);
            LCD_Show_3030_String(265,131,"s",BLACK);
            LCD_ShowNum(220,173,chan_data.data4,3,30,BLACK,WHITE);
            LCD_Show_3030_String(265,173,"s",BLACK);

            flag_dev.anchor=1;

        }
    else if(flag_dev.action_flag==DELAY&&(tp_dev.x[0]>95)&&(tp_dev.x[0]<319)&&(tp_dev.y[0]>85)&&(tp_dev.y[0]<120))
        {


            LCD_ShowNum(220,48,chan_data.data1,3,30,BLACK,WHITE);
            LCD_Show_3030_String(265,48,"s",BLACK);
            LCD_ShowNum(220,90,chan_data.data2,3,30,RED,WHITE);
            LCD_Show_3030_String(265,90,"s",BLACK);
            LCD_ShowNum(220,131,chan_data.data3,3,30,BLACK,WHITE);
            LCD_Show_3030_String(265,131,"s",BLACK);
            LCD_ShowNum(220,173,chan_data.data4,3,30,BLACK,WHITE);
            LCD_Show_3030_String(265,173,"s",BLACK);
            flag_dev.anchor=2;
        }
    else if(flag_dev.action_flag==DELAY&&(tp_dev.x[0]>95)&&(tp_dev.x[0]<319)&&(tp_dev.y[0]>125)&&(tp_dev.y[0]<160))
        {

            LCD_ShowNum(220,48,chan_data.data1,3,30,BLACK,WHITE);
            LCD_Show_3030_String(265,48,"s",BLACK);
            LCD_ShowNum(220,90,chan_data.data2,3,30,BLACK,WHITE);
            LCD_Show_3030_String(265,90,"s",BLACK);
            LCD_ShowNum(220,131,chan_data.data3,3,30,RED,WHITE);
            LCD_Show_3030_String(265,131,"s",BLACK);
            LCD_ShowNum(220,173,chan_data.data4,3,30,BLACK,WHITE);
            flag_dev.anchor=3;
        }
    else if(flag_dev.action_flag==DELAY&&(tp_dev.x[0]>95)&&(tp_dev.x[0]<319)&&(tp_dev.y[0]>165)&&(tp_dev.y[0]<200))
        {

            LCD_ShowNum(220,48,chan_data.data1,3,30,BLACK,WHITE);
            LCD_Show_3030_String(265,48,"s",BLACK);
            LCD_ShowNum(220,90,chan_data.data2,3,30,BLACK,WHITE);
            LCD_Show_3030_String(265,90,"s",BLACK);
            LCD_ShowNum(220,131,chan_data.data3,3,30,BLACK,WHITE);
            LCD_Show_3030_String(265,131,"s",BLACK);
            LCD_ShowNum(220,173,chan_data.data4,3,30,RED,WHITE);
            flag_dev.anchor=4;
        }
}


