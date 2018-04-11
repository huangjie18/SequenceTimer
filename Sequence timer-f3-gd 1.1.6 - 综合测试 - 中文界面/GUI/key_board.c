#include "key_board.h"
#include "lcd.h"
#include "gui.h"
#include  "touch.h"
#include "flag.h"
#include "delay.h"
#include "pwd_page.h"
#include <string.h>
#include "data.h"
#include "main_setting_page.h"
#include "24cxx.h"
extern _m_tp_dev tp_dev;//触屏结构体
extern _flag_dev flag_dev;
extern pwd_data user_pwd;
u8  a;
extern u8 Lastaction;
extern u8 SubAnchor;
void key_board_activity()
{

    LCD_Fill(94,42,316,110,WHITE);

    gui_draw_arcrectangle(94, 114, 55,30,1,1, GRAY,GRAY);
    gui_draw_arcrectangle(150,114, 55,30,1,1, GRAY,GRAY);
    gui_draw_arcrectangle(206,114, 55,30,1,1, GRAY,GRAY);
    gui_draw_arcrectangle(262,114, 55,30,1,1, GRAY,GRAY);

    gui_draw_arcrectangle(94, 146, 55,30,1,1, GRAY,GRAY);
    gui_draw_arcrectangle(150,146, 55,30,1,1, GRAY,GRAY);
    gui_draw_arcrectangle(206,146, 55,30,1,1, GRAY,GRAY);
    gui_draw_arcrectangle(262,146, 55,30,1,1, GRAY,GRAY);

    gui_draw_arcrectangle(94, 178, 55,30,1,1,GRAY,GRAY);
    gui_draw_arcrectangle(150,178, 55,30,1,1,GRAY,GRAY);
    gui_draw_arcrectangle(206,178, 55,30,1,1,GRAY,GRAY);
    gui_draw_arcrectangle(262,178, 55,30,1,1,GRAY,GRAY);

    LCD_Draw_arrow_key(294,90,314,110,RIGHT,BLACK);

    LCD_Show_3030_String(114,114,"1",BLACK);
    LCD_Show_3030_String(170,114,"2",BLACK);
    LCD_Show_3030_String(226,114,"3",BLACK);
    LCD_Show_3030_String(282,114,"0",BLACK);

    LCD_Show_3030_String(114,146,"4",BLACK);
    LCD_Show_3030_String(170,146,"5",BLACK);
    LCD_Show_3030_String(226,146,"6",BLACK);
    LCD_Show_2424_String(272,148,"DEL",BLACK);

    LCD_Show_3030_String(114,178,"7",BLACK);
    LCD_Show_3030_String(170,178,"8",BLACK);
    LCD_Show_3030_String(226,178,"9",BLACK);
    LCD_Show_2424_String(277,180,"OK",BLACK);


}

void key_board_action()
{

    //结构体保存当前数据

    if(flag_dev.action_flag==KEY_BOARD)
        {

            if((tp_dev.x[0]>94)&&(tp_dev.x[0]<149)&&(tp_dev.y[0]>114)&&(tp_dev.y[0]<144))
                {

                    flag_dev.key_board_num=1;
                    flag_dev.key_board_state=1;
                }
            else if((tp_dev.x[0]>150)&&(tp_dev.x[0]<205)&&(tp_dev.y[0]>114)&&(tp_dev.y[0]<144))
                {


                    flag_dev.key_board_num=2;
                    flag_dev.key_board_state=1;
                }
            else if((tp_dev.x[0]>206)&&(tp_dev.x[0]<261)&&(tp_dev.y[0]>114)&&(tp_dev.y[0]<144))
                {

                    flag_dev.key_board_state=1;
                    flag_dev.key_board_num=3;
                }
            else if((tp_dev.x[0]>262)&&(tp_dev.x[0]<317)&&(tp_dev.y[0]>114)&&(tp_dev.y[0]<144))
                {

                    flag_dev.key_board_state=1;
                    flag_dev.key_board_num=0;
                }
            else if((tp_dev.x[0]>94)&&(tp_dev.x[0]<149)&&(tp_dev.y[0]>146)&&(tp_dev.y[0]<176))
                {

                    flag_dev.key_board_state=1;
                    flag_dev.key_board_num=4;
                }
            else if((tp_dev.x[0]>150)&&(tp_dev.x[0]<205)&&(tp_dev.y[0]>146)&&(tp_dev.y[0]<176))
                {

                    flag_dev.key_board_state=1;
                    flag_dev.key_board_num=5;
                }
            else if((tp_dev.x[0]>206)&&(tp_dev.x[0]<261)&&(tp_dev.y[0]>146)&&(tp_dev.y[0]<176))
                {
                    flag_dev.key_board_state=1;

                    flag_dev.key_board_num=6;
                }
            else if((tp_dev.x[0]>262)&&(tp_dev.x[0]<317)&&(tp_dev.y[0]>146)&&(tp_dev.y[0]<176))
                {

                    flag_dev.key_board_state=1;
                    flag_dev.key_board_num=DEL;
                }
            else if((tp_dev.x[0]>94)&&(tp_dev.x[0]<149)&&(tp_dev.y[0]>178)&&(tp_dev.y[0]<208))
                {

                    flag_dev.key_board_state=1;
                    flag_dev.key_board_num=7;
                }
            else if((tp_dev.x[0]>150)&&(tp_dev.x[0]<205)&&(tp_dev.y[0]>178)&&(tp_dev.y[0]<208))
                {

                    flag_dev.key_board_state=1;
                    flag_dev.key_board_num=8;
                }
            else if((tp_dev.x[0]>206)&&(tp_dev.x[0]<261)&&(tp_dev.y[0]>178)&&(tp_dev.y[0]<208))
                {

                    flag_dev.key_board_state=1;
                    flag_dev.key_board_num=9;
                }
            else if((tp_dev.x[0]>262)&&(tp_dev.x[0]<317)&&(tp_dev.y[0]>178)&&(tp_dev.y[0]<208))
                {
                    flag_dev.key_board_state=1;
                    flag_dev.key_board_num=OK;
                }

            else if((tp_dev.x[0]>294)&&(tp_dev.x[0]<314)&&(tp_dev.y[0]>90)&&(tp_dev.y[0]<110))
                {

                    if(flag_dev.lock_sta==L_CLOSE)
                        {

                            LCD_Fill(93,42,319,208,BLACK);
                            flag_dev.save_flag=0;
                            main_setting_page_activity();
                            flag_dev.action_flag=HOME;
                            delay_ms(300);
                            a=0;

                        }
                    else if(flag_dev.lock_sta==L_OPEN)
                        {

                            if(flag_dev.pwd_anchor==1||flag_dev.pwd_anchor==2||flag_dev.pwd_anchor==5)
                                {
                                    LCD_Fill(93,42,319,208,BLACK);
                                    flag_dev.save_flag=0;
																	   gui_draw_arcrectangle(94,0,226,40,3,1, RED,RED);
                                    pwd_page_activity();
																 
                                    flag_dev.action_flag=PWD;
                                    delay_ms(300);
                                    a=0;
                                }
                            else if(flag_dev.pwd_anchor==3)
                                {
                                    LCD_Fill(93,42,319,208,BLACK);
                                    flag_dev.save_flag=0;
                                    auz_page_activity();
                                    flag_dev.action_flag=AUZ;
                                    delay_ms(300);
                                    a=0;
                                }
                            else if(flag_dev.pwd_anchor==4)
                                {																	
                                    LCD_Clear(BLUE);
                                    gui_draw_arcrectangle(50,109,226,30,1,1,WHITE,WHITE);
                                    LCD_Show_2424_String(50,80,"AUZ CODE:",WHITE);
                                    flag_dev.action_flag=AUZ;
                                    a=0;

                                }
                        }

                }

        }
}
static int pwd[6]= {0,0,0,0,0,0};
static int pwd_A[6]= {0,0,0,0,0,0};
static int pwd_B[6]= {0,0,0,0,0,0};
static int pwd_[6]= {1,2,3,4,5,6};
/*注册授权码*/
static int pwd_C[6]= {1,5,0,0,5,1};
void key_board_event()
{
    if(flag_dev.action_flag!=KEY_BOARD)
        {
            a=0 ;
            flag_dev.KEY_board_sta=0;
            flag_dev.pwd_anchor=0;

        }
    if(flag_dev.KEY_board_sta==1)
        {
            if(flag_dev.key_board_num<10&&flag_dev.key_board_state==1&&a<6)
                {
                    pwd[a]=flag_dev.key_board_num;
                    if(flag_dev.lock_sta==L_OPEN)
                        {
                            if(flag_dev.pwd_anchor!=4)
                                {
                                    LCD_ShowNum(95+15*a,45,flag_dev.key_board_num,1,30,BLACK,WHITE);
                                }
                            else
                                {
                                    LCD_ShowNum(50+15*a,79,flag_dev.key_board_num,1,30,BLACK,WHITE);
                                }
                        }
                    else
                        {
                            LCD_ShowNum(95+15*a,45,flag_dev.key_board_num,1,30,BLACK,WHITE);
                            delay_ms(200);
                            LCD_ShowNum(95+15*a,45,flag_dev.key_board_num,1,30,WHITE,WHITE);
                            LCD_Show_3030_String(95+15*a,45,"*",BLACK);
                        }
                    a++;
                    delay_ms(300);
                    flag_dev.key_board_num=NUM_NULL;
                    flag_dev.key_board_state=0;
                    if(flag_dev.pwd_anchor==1)
                        {

                            pwd_A[a-1]=pwd[a-1];


                        }
                    else if(flag_dev.pwd_anchor==2)
                        {
                            pwd_B[a-1]=pwd[a-1];

                        }
                }
            else if(flag_dev.key_board_num==OK&&flag_dev.key_board_state==1)
                {

                    if(flag_dev.lock_sta==L_CLOSE)
                        {
                            /*判断否输入6个数字*/
                            if(a==6)
                                {
                                    pwd_[0]=user_pwd.p_one;
                                    pwd_[1]=user_pwd.p_two;
                                    pwd_[2]=user_pwd.p_three;
                                    pwd_[3]=user_pwd.p_four;
                                    pwd_[4]=user_pwd.p_five;
                                    pwd_[5]=user_pwd.p_six;
                                    if (!memcmp(pwd,pwd_,sizeof(int)*6))//比较两个数组的大小
                                        {
                                            flag_dev.lock_sta=L_OPEN;

                                            LCD_Fill(93,42,319,208,BLACK);
                                            flag_dev.save_flag=0;
                                            main_setting_page_activity();
                                            flag_dev.action_flag=HOME;

                                            delay_ms(300);
                                            a=0;

                                        }
                                    else
                                        {
                                            LCD_Show_2424_String(95,75,"PASSWORD ERROR!",RED);
                                            delay_ms(3000);

                                            LCD_Fill(93,42,319,208,BLACK);
                                            flag_dev.save_flag=0;
                                            main_setting_page_activity();
                                            flag_dev.action_flag=HOME;
                                            delay_ms(300);
                                            a=0;

                                        }
                                }
                            else
                                {
                                    LCD_Show_2424_String(95,75,"FORMAT ERROR!",RED);
                                    delay_ms(3000);
                                    LCD_Fill(95,75,250,95,WHITE);
                                }
                        }
                    else if(flag_dev.lock_sta==L_OPEN)
                        {
                            if(a==6)
                                {

                                    if(flag_dev.pwd_anchor==1)
                                        {

                                            LCD_Fill(93,42,319,208,BLACK);
                                            flag_dev.save_flag=0;
																					
                                            pwd_page_activity();
                                            flag_dev.action_flag=PWD;
                                            delay_ms(300);
                                            Lastaction=PWD;
                                            SubAnchor=0x00;
                                            a=0;
                                        }
                                    if(flag_dev.pwd_anchor==2)
                                        {
                                            if (!memcmp(pwd_A,pwd_B,sizeof(int)*6))//比较两个数组的大小
                                                {


                                                    user_pwd.p_one=pwd[0];
                                                    user_pwd.p_two=pwd[1];
                                                    user_pwd.p_three=pwd[2];
                                                    user_pwd.p_four=pwd[3];
                                                    user_pwd.p_five=pwd[4];
                                                    user_pwd.p_six=pwd[5];

                                                    LCD_Show_2424_String(95,75,"SUCCESS!",RED);
                                                    delay_ms(3000);
                                                    LCD_Fill(95,75,270,95,WHITE);
                                                    ReadAndSave(ISPWD,1);
                                                }
                                            else
                                                {
                                                    LCD_Show_2424_String(95,75,"INPUT NOTMATCH!",RED);
                                                    delay_ms(3000);
                                                    LCD_Fill(95,75,270,95,WHITE);
                                                }

                                            LCD_Fill(93,42,319,208,BLACK);
                                            flag_dev.save_flag=0;
																					  gui_draw_arcrectangle(94,0,226,40,3,1, RED,RED);
                                            pwd_page_activity();
                                            flag_dev.action_flag=PWD;
                                            Lastaction=PWD;
                                            SubAnchor=0x00;
                                            delay_ms(300);
                                            a=0;
                                        }
                                    else if(flag_dev.pwd_anchor==3)
                                        {
                                            /*判断注册码是否匹配*/
                                            if(!memcmp(pwd_C,pwd,sizeof(int)*6))
                                                {

                                                    pwd_C[0] =pwd[0];
                                                    pwd_C[1] =pwd[1];
                                                    pwd_C[2] =pwd[2];
                                                    pwd_C[3] =pwd[3];
                                                    pwd_C[4] =pwd[4];
                                                    pwd_C[5] =pwd[5];

                                                    /*取消标记已注册授权*/
                                                    AT24CXX_WriteOneByte(221,0);

                                                    LCD_Show_2424_String(95,75,"SUCCESS!",RED);
                                                    delay_ms(3000);
                                                    LCD_Fill(95,75,270,95,WHITE);
																									  flag_dev.IsShowAUZNumset=1;
                                                }
                                            else
                                                {


                                                    LCD_Show_2424_String(95,75,"ERROR!",RED);
                                                    delay_ms(3000);
                                                    LCD_Fill(95,75,270,95,WHITE);
                                                }
                                            /*返回AUZ界面*/
                                            LCD_Fill(93,42,319,208,BLACK);
                                            flag_dev.save_flag=0;
                                            auz_page_activity();
                                            flag_dev.action_flag=AUZ;
                                            Lastaction=AUZ;
                                            SubAnchor=0x00;
                                            delay_ms(300);

                                        }
                                    else if(flag_dev.pwd_anchor==4)
                                        {
                                            /*判断密码是否匹配*/
                                            if(!memcmp(pwd_C,pwd,sizeof(int)*6))
                                                {

                                                    pwd_C[0] =pwd[0];
                                                    pwd_C[1] =pwd[1];
                                                    pwd_C[2] =pwd[2];
                                                    pwd_C[3] =pwd[3];
                                                    pwd_C[4] =pwd[4];
                                                    pwd_C[5] =pwd[5];

                                                    /*标记已经注册过*/
                                                    flag_dev.ISAUZ=1;
                                                    AT24CXX_WriteOneByte(221,1);
                                                    LCD_Clear(BLACK);
                                                }
                                            else
                                                {
                                                    gui_draw_arcrectangle(50,79,222,30,1,1,WHITE,WHITE);
                                                    LCD_Show_2424_String(50,81,"ERROR!",RED);
                                                    delay_ms(3000);
                                                    gui_draw_arcrectangle(50,79,222,30,1,1,WHITE,WHITE);


                                                }
                                            /*清除按下数字个数*/
                                            a=0;

                                        }
                                    else if(flag_dev.pwd_anchor==5)
                                        {
                                            pwd_[0]=user_pwd.p_one;
                                            pwd_[1]=user_pwd.p_two;
                                            pwd_[2]=user_pwd.p_three;
                                            pwd_[3]=user_pwd.p_four;
                                            pwd_[4]=user_pwd.p_five;
                                            pwd_[5]=user_pwd.p_six;
                                            if (!memcmp(pwd,pwd_,sizeof(int)*6))//比较两个数组的大小
                                                {

                                                    flag_dev.PWDsta=1;
                                                    LCD_Show_2424_String(95,75,"SUCCESS!",RED);
                                                    delay_ms(3000);
                                             LCD_Fill(93,42,319,208,BLACK);
                                            flag_dev.save_flag=0;
																					  gui_draw_arcrectangle(94,0,226,40,3,1, RED,RED);
                                            pwd_page_activity();
                                            flag_dev.action_flag=PWD;
                                            Lastaction=PWD;
                                            SubAnchor=0x00;
                                
                                                    a=0;

                                                }
                                            else
                                                {
                                                    LCD_Show_2424_String(95,75,"PASSWORD ERROR!",RED);
                                                    delay_ms(3000);

                                 
                                             LCD_Fill(93,42,319,208,BLACK);
                                            flag_dev.save_flag=0;
																					  gui_draw_arcrectangle(94,0,226,40,3,1, RED,RED);
                                            pwd_page_activity();
                                            flag_dev.action_flag=PWD;
                                            Lastaction=PWD;
                                            SubAnchor=0x00;
                                            delay_ms(300);
                                                    a=0;
                                           

                                                }
                                        }
                                }
                            else
                                {
                                    if(flag_dev.pwd_anchor!=4)
                                        {
                                            LCD_Show_2424_String(95,75,"FORMAT ERROR!",RED);
                                            delay_ms(3000);
                                            LCD_Fill(95,75,250,95,WHITE);
                                        }
                                }
                        }
                    delay_ms(300);
                    flag_dev.key_board_num=NUM_NULL;
                    flag_dev.key_board_state=0;

                }
            else if(flag_dev.key_board_num==DEL&&flag_dev.key_board_state==1)
                {

                    pwd[a]=0;
                    if(a!=0)
                        {
                            a--;
                        }
                    if(flag_dev.pwd_anchor!=4)
                        {

                            LCD_ShowNum(95+15*a,45,8,1,30,WHITE,WHITE);

                        }
                    else
                        {
                            LCD_ShowNum(50+15*a,79,8,1,30,WHITE,WHITE);

                        }
                    delay_ms(150);
                    flag_dev.key_board_num=NUM_NULL;
                    flag_dev.key_board_state=0;

                }

        }
}