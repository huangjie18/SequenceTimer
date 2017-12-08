#include "key.h"
#include "sys.h"
#include "delay.h"
#include "flag.h"
#include "gui.h"
#include "lcd.h"


_relay_key_dev relay_key_dev= {XNULL}; //按键结构体

_encoder_dev encoder_dev;//编码器状态结构体

u8 back_flag,front_flag;
u8 LAST_A_LEVEL=1;//保存上一次编码器状态A脚电平值
u8 LAST_KEY_LEVEL=1;//保存上一次编码器按键电平状态
u8 LAST_REKEY_LEVEL=1;

void key_init()
{

    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);

    GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_12|GPIO_Pin_13;//编码器，电源开关
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //设置成上拉输入
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    GPIO_SetBits(GPIOB,GPIO_Pin_0|GPIO_Pin_1);

}

//判断编码器旋转状态
void encoder()
{

    encoder_dev.EN_STATE=XNULL;
    //while(1){if(!(ENCODER_A==LAST_A_LEVEL)) break;}
    if(!(ENCODER_A==LAST_A_LEVEL))////编码器或者编码器按钮发生电平转变
        {
            delay_us(200);//消抖
            if(!(ENCODER_A==LAST_A_LEVEL))//编码器A引脚发生电平转变
                {
                    if(LAST_A_LEVEL==1)//下降沿     //牺牲一个半个周期判断正反转
                        {
                            if(ENCODER_B==1)front_flag=1;
                            else back_flag=1;
                        }
                    else  //上升沿
                        {
                            if(front_flag==1)//向后标志1
                                {
                                    if(ENCODER_B==0)
                                        {
                                            encoder_dev.EN_STATE=TURN_L;
                                            front_flag=0;
                                        }
                                }
                            else if(back_flag==1)
                                {
                                    if(ENCODER_B)
                                        {
                                            encoder_dev.EN_STATE=TURN_R;
                                            back_flag=0;
                                        }
                                }
                            back_flag=0;
                            front_flag=0;
                        }
                    LAST_A_LEVEL=ENCODER_A;
                }
        }
}

//判断编码器按键状态
void encoder_key()
{
    encoder_dev.EN_KEY=EN_KEY_UP;//清除编码器按键状态

    if(!(ENCODER_KEY==LAST_KEY_LEVEL)) //编码器按键电平发生装换
        {
            if(ENCODER_KEY==0)
                encoder_dev.EN_KEY=EN_KEY_DOWN;
        }
    LAST_KEY_LEVEL=ENCODER_KEY;

}



