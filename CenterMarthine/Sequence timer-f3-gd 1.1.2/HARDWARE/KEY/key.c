#include "key.h"
#include "sys.h"
#include "delay.h"
#include "flag.h"
#include "gui.h"
#include "lcd.h"


_relay_key_dev relay_key_dev= {XNULL}; //�����ṹ��

_encoder_dev encoder_dev;//������״̬�ṹ��

u8 back_flag,front_flag;
u8 LAST_A_LEVEL=1;//������һ�α�����״̬A�ŵ�ƽֵ
u8 LAST_KEY_LEVEL=1;//������һ�α�����������ƽ״̬
u8 LAST_REKEY_LEVEL=1;

void key_init()
{

    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);

    GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_12|GPIO_Pin_13;//����������Դ����
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //���ó���������
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    GPIO_SetBits(GPIOB,GPIO_Pin_0|GPIO_Pin_1);

}

//�жϱ�������ת״̬
void encoder()
{

    encoder_dev.EN_STATE=XNULL;
    //while(1){if(!(ENCODER_A==LAST_A_LEVEL)) break;}
    if(!(ENCODER_A==LAST_A_LEVEL))////���������߱�������ť������ƽת��
        {
            delay_us(200);//����
            if(!(ENCODER_A==LAST_A_LEVEL))//������A���ŷ�����ƽת��
                {
                    if(LAST_A_LEVEL==1)//�½���     //����һ����������ж�����ת
                        {
                            if(ENCODER_B==1)front_flag=1;
                            else back_flag=1;
                        }
                    else  //������
                        {
                            if(front_flag==1)//����־1
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

//�жϱ���������״̬
void encoder_key()
{
    encoder_dev.EN_KEY=EN_KEY_UP;//�������������״̬

    if(!(ENCODER_KEY==LAST_KEY_LEVEL)) //������������ƽ����װ��
        {
            if(ENCODER_KEY==0)
                encoder_dev.EN_KEY=EN_KEY_DOWN;
        }
    LAST_KEY_LEVEL=ENCODER_KEY;

}



