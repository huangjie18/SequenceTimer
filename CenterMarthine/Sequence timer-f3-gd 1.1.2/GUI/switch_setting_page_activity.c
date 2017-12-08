#include "switch_setting_page_activity.h"
#include "lcd.h"
#include "gui.h"
#include "flag.h"
#include "touch.h"
#include "delay.h"

extern _m_tp_dev tp_dev;//´¥ÆÁ½á¹¹Ìå
extern _flag_dev flag_dev;

void switch_setting_page_activity()
{

    gui_draw_arcrectangle(95,45,225,35,1,1,BLUE,BLUE);
    gui_draw_arcrectangle(95,85,225,35, 1,1,BLUE,BLUE);
    gui_draw_arcrectangle(95,125,225,35,1,1,BLUE,BLUE);
    gui_draw_arcrectangle(95,165,225,35,1,1,BLUE,BLUE);

    gui_draw_arcrectangle(172,48, 145,30,1,1,WHITE,WHITE);
    gui_draw_arcrectangle(172,88, 145,30,1,1,WHITE,WHITE);
    gui_draw_arcrectangle(172,128,145,30,1,1,WHITE,WHITE);
    gui_draw_arcrectangle(172,168,145,30,1,1,WHITE,WHITE);

    LCD_DrawLtrigo(172, 48,202,78,LEFT,BLUE);
    LCD_DrawLtrigo(287, 48,317,78,RIGHT,BLUE);

    LCD_DrawLtrigo(172, 88,202,118,LEFT,BLUE);
    LCD_DrawLtrigo(287, 88,317,118,RIGHT,BLUE);

    LCD_DrawLtrigo(172, 128,202,158,LEFT,BLUE);
    LCD_DrawLtrigo(287, 128,317,158,RIGHT,BLUE);

    LCD_DrawLtrigo(172, 168,202,198,LEFT,BLUE);
    LCD_DrawLtrigo(287, 168,317,198,RIGHT,BLUE);

    LCD_DrawLtrigo(95,0,125,40,LEFT,WHITE);
    LCD_DrawLtrigo(290,0,319,40,RIGHT,WHITE);

    LCD_Show_3030_String(130,5,"CHAN SWITCH",WHITE);

    LCD_Show_2424_String(100,50,"CHAN1",WHITE);
    LCD_Show_2424_String(100,90,"CHAN2",WHITE);
    LCD_Show_2424_String(100,130,"CHAN3",WHITE);
    LCD_Show_2424_String(100,170,"CHAN4",WHITE);


//    LCD_Show_2424_String(100,50,"Chan5",WHITE);
//    LCD_Show_2424_String(100,90,"Chan6",WHITE);
//    LCD_Show_2424_String(100,130,"Chan7",WHITE);
//    LCD_Show_2424_String(100,170,"Chan8",WHITE);

//	   LCD_Show_3030_String(230,50,"ON",BLACK);
//		 LCD_Show_3030_String(230,90,"ON",BLACK);
//		 LCD_Show_3030_String(230,130,"ON",BLACK);
//		 LCD_Show_3030_String(230,170,"ON",BLACK);

//    LCD_Show_3030_String(230,50,"OFF",BLACK);
//    LCD_Show_3030_String(230,90,"OFF",BLACK);
//    LCD_Show_3030_String(230,130,"OFF",BLACK);
//    LCD_Show_3030_String(230,170,"OFF",BLACK);

    gui_draw_arcrectangle(120,210,80,30,1,1,BLUE,BLUE);

    if(GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_0))
        {

            LCD_Show_3030_String(230,50,"ON",BLACK);

        }
    else
        {
            LCD_Show_3030_String(230,50,"0FF",BLACK);

        }
    if(GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_1))
        {
            LCD_Show_3030_String(230,90,"ON",BLACK);


        }
    else
        {
            LCD_Show_3030_String(230,90,"OFF",BLACK);

        }
    if(GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_2))
        {

            LCD_Show_3030_String(230,130,"ON",BLACK);

        }
    else
        {
            LCD_Show_3030_String(230,130,"OFF",BLACK);

        }

    if(GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_3))
        {
            LCD_Show_3030_String(230,170,"ON",BLACK);


        }
    else
        {

            LCD_Show_3030_String(230,170,"OFF",BLACK);
        }

    flag_dev.activity_num=1;

}

void switch_setting_page_action()
{



    if(flag_dev.action_flag==SWITCH&&(tp_dev.x[0]>92)&&(tp_dev.x[0]<132)&&(tp_dev.y[0]>0)&&(tp_dev.y[0]<40))
        {
            delay_ms(200);
            if(flag_dev.activity_num==1)
                {


                    gui_draw_arcrectangle(95,45,225,35,1,1,BLUE,BLUE);
                    gui_draw_arcrectangle(95,85,225,35, 1,1,BLUE,BLUE);
                    gui_draw_arcrectangle(95,125,225,35,1,1,BLUE,BLUE);
                    gui_draw_arcrectangle(95,165,225,35,1,1,BLUE,BLUE);

                    gui_draw_arcrectangle(172,48, 145,30,1,1,WHITE,WHITE);
                    gui_draw_arcrectangle(172,88, 145,30,1,1,WHITE,WHITE);
                    gui_draw_arcrectangle(172,128,145,30,1,1,WHITE,WHITE);
                    gui_draw_arcrectangle(172,168,145,30,1,1,WHITE,WHITE);

                    LCD_DrawLtrigo(172, 48,202,78,LEFT,BLUE);
                    LCD_DrawLtrigo(287, 48,317,78,RIGHT,BLUE);

                    LCD_DrawLtrigo(172, 88,202,118,LEFT,BLUE);
                    LCD_DrawLtrigo(287, 88,317,118,RIGHT,BLUE);

                    LCD_DrawLtrigo(172, 128,202,158,LEFT,BLUE);
                    LCD_DrawLtrigo(287, 128,317,158,RIGHT,BLUE);

                    LCD_DrawLtrigo(172, 168,202,198,LEFT,BLUE);
                    LCD_DrawLtrigo(287, 168,317,198,RIGHT,BLUE);

                    LCD_DrawLtrigo(95,0,125,40,LEFT,WHITE);
                    LCD_DrawLtrigo(290,0,319,40,RIGHT,WHITE);

                    LCD_Show_2424_String(100,50,"CHAN5",WHITE);
                    LCD_Show_2424_String(100,90,"CHAN6",WHITE);
                    LCD_Show_2424_String(100,130,"CHAN7",WHITE);
                    LCD_Show_2424_String(100,170,"CHAN8",WHITE);

                    if(GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_4))
                        {
                            LCD_Show_3030_String(230,50,"ON",BLACK);


                        }
                    else
                        {

                            LCD_Show_3030_String(230,50,"OFF",BLACK);
                        }

                    if(GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_5))
                        {
                            LCD_Show_3030_String(230,90,"ON",BLACK);


                        }
                    else
                        {

                            LCD_Show_3030_String(230,90,"OFF",BLACK);
                        }

                    if(GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_6))
                        {


                            LCD_Show_3030_String(230,130,"ON",BLACK);
                        }
                    else
                        {
                            LCD_Show_3030_String(230,130,"OFF",BLACK);

                        }

                    if(GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_7))
                        {


                            LCD_Show_3030_String(230,170,"ON",BLACK);
                        }
                    else
                        {
                            LCD_Show_3030_String(230,170,"OFF",BLACK);

                        }


                    flag_dev.activity_num=2;

                }
            else if(flag_dev.activity_num==2)
                {


                    gui_draw_arcrectangle(95,45,225,35,1,1,BLUE,BLUE);
                    gui_draw_arcrectangle(95,85,225,35, 1,1,BLUE,BLUE);
                    gui_draw_arcrectangle(95,125,225,35,1,1,BLUE,BLUE);
                    gui_draw_arcrectangle(95,165,225,35,1,1,BLUE,BLUE);

                    gui_draw_arcrectangle(172,48, 145,30,1,1,WHITE,WHITE);
                    gui_draw_arcrectangle(172,88, 145,30,1,1,WHITE,WHITE);
                    gui_draw_arcrectangle(172,128,145,30,1,1,WHITE,WHITE);
                    gui_draw_arcrectangle(172,168,145,30,1,1,WHITE,WHITE);

                    LCD_Show_2424_String(100,50,"CHAN1",WHITE);
                    LCD_Show_2424_String(100,90,"CHAN2",WHITE);
                    LCD_Show_2424_String(100,130,"CHAN3",WHITE);
                    LCD_Show_2424_String(100,170,"CHAN4",WHITE);

                    LCD_DrawLtrigo(172, 48,202,78,LEFT,BLUE);
                    LCD_DrawLtrigo(287, 48,317,78,RIGHT,BLUE);

                    LCD_DrawLtrigo(172, 88,202,118,LEFT,BLUE);
                    LCD_DrawLtrigo(287, 88,317,118,RIGHT,BLUE);

                    LCD_DrawLtrigo(172, 128,202,158,LEFT,BLUE);
                    LCD_DrawLtrigo(287, 128,317,158,RIGHT,BLUE);

                    LCD_DrawLtrigo(172, 168,202,198,LEFT,BLUE);
                    LCD_DrawLtrigo(287, 168,317,198,RIGHT,BLUE);

                    LCD_DrawLtrigo(95,0,125,40,LEFT,WHITE);
                    LCD_DrawLtrigo(290,0,319,40,RIGHT,WHITE);



                    if(GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_0))
                        {

                            LCD_Show_3030_String(230,50,"ON",BLACK);

                        }
                    else
                        {
                            LCD_Show_3030_String(230,50,"0FF",BLACK);

                        }
                    if(GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_1))
                        {
                            LCD_Show_3030_String(230,90,"ON",BLACK);


                        }
                    else
                        {
                            LCD_Show_3030_String(230,90,"OFF",BLACK);

                        }
                    if(GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_2))
                        {

                            LCD_Show_3030_String(230,130,"ON",BLACK);

                        }
                    else
                        {
                            LCD_Show_3030_String(230,130,"OFF",BLACK);

                        }

                    if(GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_3))
                        {
                            LCD_Show_3030_String(230,170,"ON",BLACK);


                        }
                    else
                        {

                            LCD_Show_3030_String(230,170,"OFF",BLACK);
                        }

                flag_dev.activity_num=1;
                }
          

        }
    else if(flag_dev.action_flag==SWITCH&&(tp_dev.x[0]>279)&&(tp_dev.x[0]<319)&&(tp_dev.y[0]>0)&&(tp_dev.y[0]<40))
        {

            delay_ms(200);
            if(flag_dev.activity_num==1)
                {



                    gui_draw_arcrectangle(95,45,225,35,1,1,BLUE,BLUE);
                    gui_draw_arcrectangle(95,85,225,35, 1,1,BLUE,BLUE);
                    gui_draw_arcrectangle(95,125,225,35,1,1,BLUE,BLUE);
                    gui_draw_arcrectangle(95,165,225,35,1,1,BLUE,BLUE);

                    gui_draw_arcrectangle(172,48, 145,30,1,1,WHITE,WHITE);
                    gui_draw_arcrectangle(172,88, 145,30,1,1,WHITE,WHITE);
                    gui_draw_arcrectangle(172,128,145,30,1,1,WHITE,WHITE);
                    gui_draw_arcrectangle(172,168,145,30,1,1,WHITE,WHITE);

                    LCD_DrawLtrigo(172, 48,202,78,LEFT,BLUE);
                    LCD_DrawLtrigo(287, 48,317,78,RIGHT,BLUE);

                    LCD_DrawLtrigo(172, 88,202,118,LEFT,BLUE);
                    LCD_DrawLtrigo(287, 88,317,118,RIGHT,BLUE);

                    LCD_DrawLtrigo(172, 128,202,158,LEFT,BLUE);
                    LCD_DrawLtrigo(287, 128,317,158,RIGHT,BLUE);

                    LCD_DrawLtrigo(172, 168,202,198,LEFT,BLUE);
                    LCD_DrawLtrigo(287, 168,317,198,RIGHT,BLUE);

                    LCD_DrawLtrigo(95,0,125,40,LEFT,WHITE);
                    LCD_DrawLtrigo(290,0,319,40,RIGHT,WHITE);

                    LCD_Show_2424_String(100,50,"CHAN5",WHITE);
                    LCD_Show_2424_String(100,90,"CHAN6",WHITE);
                    LCD_Show_2424_String(100,130,"CHAN7",WHITE);
                    LCD_Show_2424_String(100,170,"CHAN8",WHITE);

                    if(GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_4))
                        {
                            LCD_Show_3030_String(230,50,"ON",BLACK);


                        }
                    else
                        {

                            LCD_Show_3030_String(230,50,"OFF",BLACK);
                        }

                    if(GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_5))
                        {
                            LCD_Show_3030_String(230,90,"ON",BLACK);


                        }
                    else
                        {

                            LCD_Show_3030_String(230,90,"OFF",BLACK);
                        }

                    if(GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_6))
                        {


                            LCD_Show_3030_String(230,130,"ON",BLACK);
                        }
                    else
                        {
                            LCD_Show_3030_String(230,130,"OFF",BLACK);

                        }

                    if(GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_7))
                        {


                            LCD_Show_3030_String(230,170,"ON",BLACK);
                        }
                    else
                        {
                            LCD_Show_3030_String(230,170,"OFF",BLACK);

                        }


                    flag_dev.activity_num=2;

                }
           else if(flag_dev.activity_num==2)
                {


                    gui_draw_arcrectangle(95,45,225,35,1,1,BLUE,BLUE);
                    gui_draw_arcrectangle(95,85,225,35, 1,1,BLUE,BLUE);
                    gui_draw_arcrectangle(95,125,225,35,1,1,BLUE,BLUE);
                    gui_draw_arcrectangle(95,165,225,35,1,1,BLUE,BLUE);

                    gui_draw_arcrectangle(172,48, 145,30,1,1,WHITE,WHITE);
                    gui_draw_arcrectangle(172,88, 145,30,1,1,WHITE,WHITE);
                    gui_draw_arcrectangle(172,128,145,30,1,1,WHITE,WHITE);
                    gui_draw_arcrectangle(172,168,145,30,1,1,WHITE,WHITE);

                    LCD_DrawLtrigo(172, 48,202,78,LEFT,BLUE);
                    LCD_DrawLtrigo(287, 48,317,78,RIGHT,BLUE);

                    LCD_DrawLtrigo(172, 88,202,118,LEFT,BLUE);
                    LCD_DrawLtrigo(287, 88,317,118,RIGHT,BLUE);

                    LCD_DrawLtrigo(172, 128,202,158,LEFT,BLUE);
                    LCD_DrawLtrigo(287, 128,317,158,RIGHT,BLUE);

                    LCD_DrawLtrigo(172, 168,202,198,LEFT,BLUE);
                    LCD_DrawLtrigo(287, 168,317,198,RIGHT,BLUE);

                    LCD_DrawLtrigo(95,0,125,40,LEFT,WHITE);
                    LCD_DrawLtrigo(290,0,319,40,RIGHT,WHITE);

                    LCD_Show_2424_String(100,50,"CHAN1",WHITE);
                    LCD_Show_2424_String(100,90,"CHAN2",WHITE);
                    LCD_Show_2424_String(100,130,"CHAN3",WHITE);
                    LCD_Show_2424_String(100,170,"CHAN4",WHITE);



                    if(GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_0))
                        {

                            LCD_Show_3030_String(230,50,"ON",BLACK);

                        }
                    else
                        {
                            LCD_Show_3030_String(230,50,"0FF",BLACK);

                        }
                    if(GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_1))
                        {
                            LCD_Show_3030_String(230,90,"ON",BLACK);


                        }
                    else
                        {
                            LCD_Show_3030_String(230,90,"OFF",BLACK);

                        }
                    if(GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_2))
                        {

                            LCD_Show_3030_String(230,130,"ON",BLACK);

                        }
                    else
                        {
                            LCD_Show_3030_String(230,130,"OFF",BLACK);

                        }

                    if(GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_3))
                        {
                            LCD_Show_3030_String(230,170,"ON",BLACK);


                        }
                    else
                        {

                            LCD_Show_3030_String(230,170,"OFF",BLACK);
                        }

                    flag_dev.activity_num=1;
                }

            


        }


    if(flag_dev.action_flag==SWITCH&&(tp_dev.x[0]>172)&&(tp_dev.x[0]<202)&&(tp_dev.y[0]>48)&&(tp_dev.y[0]<78))
        {

            if(flag_dev.activity_num==1)
                {

                    if(GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_0))
                        {

                            gui_draw_arcrectangle(222,48, 60,30,1,1,WHITE,WHITE);
                            LCD_Show_3030_String(230,50,"OFF",BLACK);
                            GPIO_ResetBits(GPIOC,GPIO_Pin_0);
                        }

                }
            else if(flag_dev.activity_num==2)
                {

                    if(GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_4))
                        {
                            gui_draw_arcrectangle(222,48, 60,30,1,1,WHITE,WHITE);
                            LCD_Show_3030_String(230,50,"OFF",BLACK);
                            GPIO_ResetBits(GPIOC,GPIO_Pin_4);
                        }

                }

        }
    else if(flag_dev.action_flag==SWITCH&&(tp_dev.x[0]>287)&&(tp_dev.x[0]<317)&&(tp_dev.y[0]>48)&&(tp_dev.y[0]<78))
        {


            if(flag_dev.activity_num==1)
                {

                    if(GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_0)!=1)
                        {

                            gui_draw_arcrectangle(222,48, 60,30,1,1,WHITE,WHITE);
                            LCD_Show_3030_String(230,50,"ON",BLACK);
                            GPIO_SetBits(GPIOC,GPIO_Pin_0);
                        }

                }
            else if(flag_dev.activity_num==2)
                {

                    if(GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_4)!=1)
                        {
                            gui_draw_arcrectangle(222,48, 60,30,1,1,WHITE,WHITE);
                            LCD_Show_3030_String(230,50,"ON",BLACK);
                            GPIO_SetBits(GPIOC,GPIO_Pin_4);
                        }

                }


        }
    else if(flag_dev.action_flag==SWITCH&&(tp_dev.x[0]>172)&&(tp_dev.x[0]<202)&&(tp_dev.y[0]>88)&&(tp_dev.y[0]<118))
        {

            if(flag_dev.activity_num==1)
                {

                    if(GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_1))
                        {

                            gui_draw_arcrectangle(222,88, 60,30,1,1,WHITE,WHITE);
                            LCD_Show_3030_String(230,90,"OFF",BLACK);
                            GPIO_ResetBits(GPIOC,GPIO_Pin_1);
                        }

                }
            else if(flag_dev.activity_num==2)
                {

                    if(GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_5))
                        {
                            gui_draw_arcrectangle(222,88, 60,30,1,1,WHITE,WHITE);
                            LCD_Show_3030_String(230,90,"OFF",BLACK);
                            GPIO_ResetBits(GPIOC,GPIO_Pin_5);
                        }

                }


        }
    else if(flag_dev.action_flag==SWITCH&&(tp_dev.x[0]>287)&&(tp_dev.x[0]<317)&&(tp_dev.y[0]>88)&&(tp_dev.y[0]<118))
        {

            if(flag_dev.activity_num==1)
                {

                    if(GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_1)!=1)
                        {

                            gui_draw_arcrectangle(222,88, 60,30,1,1,WHITE,WHITE);
                            LCD_Show_3030_String(230,90,"ON",BLACK);
                            GPIO_SetBits(GPIOC,GPIO_Pin_1);

                        }
                }
            else if(flag_dev.activity_num==2)
                {

                    if(GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_5)!=1)
                        {
                            gui_draw_arcrectangle(222,88, 60,30,1,1,WHITE,WHITE);
                            LCD_Show_3030_String(230,90,"ON",BLACK);
                            GPIO_SetBits(GPIOC,GPIO_Pin_5);
                        }

                }



        }
    else if(flag_dev.action_flag==SWITCH&&(tp_dev.x[0]>172)&&(tp_dev.x[0]<202)&&(tp_dev.y[0]>128)&&(tp_dev.y[0]<158))
        {

            if(flag_dev.activity_num==1)
                {

                    if(GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_2))
                        {

                            gui_draw_arcrectangle(222,128, 60,30,1,1,WHITE,WHITE);
                            LCD_Show_3030_String(230,130,"OFF",BLACK);
                            GPIO_ResetBits(GPIOC,GPIO_Pin_2);

                        }
                }
            else if(flag_dev.activity_num==2)
                {

                    if(GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_6))
                        {
                            gui_draw_arcrectangle(222,128, 60,30,1,1,WHITE,WHITE);
                            LCD_Show_3030_String(230,130,"OFF",BLACK);
                            GPIO_ResetBits(GPIOC,GPIO_Pin_6);
                        }

                }




        }
    else if(flag_dev.action_flag==SWITCH&&(tp_dev.x[0]>287)&&(tp_dev.x[0]<317)&&(tp_dev.y[0]>128)&&(tp_dev.y[0]<158))
        {

            if(flag_dev.activity_num==1)
                {

                    if(GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_2)!=1)
                        {

                            gui_draw_arcrectangle(222,128, 60,30,1,1,WHITE,WHITE);
                            LCD_Show_3030_String(230,130,"ON",BLACK);
                            GPIO_SetBits(GPIOC,GPIO_Pin_2);

                        }
                }
            else if(flag_dev.activity_num==2)
                {

                    if(GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_6)!=1)
                        {
                            gui_draw_arcrectangle(222,128, 60,30,1,1,WHITE,WHITE);
                            LCD_Show_3030_String(230,130,"ON",BLACK);
                            GPIO_SetBits(GPIOC,GPIO_Pin_6);
                        }

                }






        }
    else if(flag_dev.action_flag==SWITCH&&(tp_dev.x[0]>172)&&(tp_dev.x[0]<202)&&(tp_dev.y[0]>168)&&(tp_dev.y[0]<208))
        {

            if(flag_dev.activity_num==1)
                {

                    if(GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_3))
                        {

                            gui_draw_arcrectangle(222,168, 60,30,1,1,WHITE,WHITE);
                            LCD_Show_3030_String(230,170,"OFF",BLACK);
                            GPIO_ResetBits(GPIOC,GPIO_Pin_3);

                        }
                }
            else if(flag_dev.activity_num==2)
                {

                    if(GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_7))
                        {
                            gui_draw_arcrectangle(222,168, 60,30,1,1,WHITE,WHITE);
                            LCD_Show_3030_String(230,170,"OFF",BLACK);
                            GPIO_ResetBits(GPIOC,GPIO_Pin_7);
                        }

                }




        }
    else if(flag_dev.action_flag==SWITCH&&(tp_dev.x[0]>287)&&(tp_dev.x[0]<317)&&(tp_dev.y[0]>168)&&(tp_dev.y[0]<208))
        {

            if(flag_dev.activity_num==1)
                {

                    if(GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_3)!=1)
                        {

                            gui_draw_arcrectangle(222,168, 60,30,1,1,WHITE,WHITE);
                            LCD_Show_3030_String(230,170,"ON",BLACK);
                            GPIO_SetBits(GPIOC,GPIO_Pin_3);

                        }
                }
            else if(flag_dev.activity_num==2)
                {

                    if(GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_7)!=1)
                        {
                            gui_draw_arcrectangle(222,168, 60,30,1,1,WHITE,WHITE);
                            LCD_Show_3030_String(230,170,"ON",BLACK);
                            GPIO_SetBits(GPIOC,GPIO_Pin_7);
                        }

                }





        }





}




