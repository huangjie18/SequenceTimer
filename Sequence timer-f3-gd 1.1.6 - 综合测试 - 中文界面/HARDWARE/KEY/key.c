#include "key.h"
#include "sys.h"
#include "delay.h"
#include "flag.h"
#include "gui.h"
#include "lcd.h"

extern  _flag_dev flag_dev;
extern u16 TIM3CH1_CAPTURE_VAL;//���벶��ֵ

#define ROTATE_A  PBin(10)
#define ROTATE_B PBin(11)

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

    GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;//����������Դ����
	  //GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_12|GPIO_Pin_13;//����������Դ����
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //���ó���������
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    // GPIO_SetBits(GPIOB,GPIO_Pin_0|GPIO_Pin_1);

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
                                            if(flag_dev.TOSUBPAGE==0)
                                                {
                                                    encoder_dev.EN_STATE=TURN_R;
                                                }
                                            else
                                                {
                                                    encoder_dev.EN_STATE=SUBRIGHT;
                                                }
                                            front_flag=0;
                                        }
                                }
                            else if(back_flag==1)
                                {
                                    if(ENCODER_B)
                                        {
                                            if(flag_dev.TOSUBPAGE==0)
                                                {
                                                    encoder_dev.EN_STATE=TURN_L;
                                                }
                                            else
                                                {
                                                    encoder_dev.EN_STATE=SUBLEFT;
                                                }
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
            delay_ms(20);//����
            if(!(ENCODER_KEY==LAST_KEY_LEVEL)) //������������ƽ����װ��
                {
                    if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_12)==0)
                        encoder_dev.EN_KEY=EN_KEY_DOWN;

                }
            LAST_KEY_LEVEL=ENCODER_KEY;
        }


}


void relay_key()
{

    if(flag_dev.lock_sta==L_OPEN)
        {
            static u8 lastkeysta;
            static u8 key_up=1;//�������ɿ���־
            if(key_up&&RELAY_KEY==0)
                {
                    delay_ms(100);
                    key_up=0;
                    if(RELAY_KEY==0)
                        {


                            if(	flag_dev.link)
                                {

                                }
                            else
                                {
                                    if(relay_key_dev.relay_key_state==RE_KEY_UP||relay_key_dev.relay_key_state==XNULL)
                                        {
                                            relay_key_dev.relay_key_state=RE_KEY_DOWN;
                                        }
                                    else
                                        {
                                            relay_key_dev.relay_key_state=RE_KEY_UP;
                                        }
                                }

                        }
                }
            else if(RELAY_KEY==1)key_up=1;
            if(lastkeysta!=relay_key_dev.relay_key_state)
                {
                    if(relay_key_dev.relay_key_state==RE_KEY_DOWN)
                        {
                          if(flag_dev.action_flag==HOME){
                           gui_draw_arcrectangle(94,0,151,40,1,1,RED,RED);
													if(flag_dev.langage==1){
                            LCD_Show_3030_String(100,5,"CHAN OPEN",WHITE);
													}else{
													ShowTwoChineseChar(124,11,2,3,24,WHITE);
													 ShowChineseChar(172,11,5,24,WHITE);
													}
												}
                        }
                    if(relay_key_dev.relay_key_state==RE_KEY_UP)
                        {
													if(flag_dev.action_flag==HOME){
                           gui_draw_arcrectangle(94,0,151,40,1,1,RED,RED);
													if(flag_dev.langage==1){
                           LCD_Show_3030_String(100,5,"CHAN CLOSE",WHITE);
													}else{																									
											    	ShowTwoChineseChar(124,11,2,3,24,WHITE);
													 ShowChineseChar(172,11,6,24,WHITE);
													}
												}
                        }
                    lastkeysta=relay_key_dev.relay_key_state;
                }
        }
}


