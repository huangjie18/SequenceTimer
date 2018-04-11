#ifndef __FLAG_H
#define __FLAG_H 
#include "sys.h"
typedef struct{

	u8 activity_flag;//activity�����־λ
	u8 action_flag;//��ǰactivity�ɼ����ʱ�䣬�������¼�
	u8 page_num; //�˵�����ҳ��
	u8 screen_flag;//��Ļ�Ƿ�֧�ֳ�����־λ
  u8 screen_key;//��Ļ�Ӽ�����־λ
	u8 anchor;//activity��ê���־λ
	u8 activity_num;//activity��ҳ��
  u8 save_flag;//�������ݱ�־λ	
	u8 KEY_board_sta;//�Ƿ�ʹ������̱�־λ
	u8 key_board_num;//�����
	u8 key_board_state;//�Ƿ��±�־λ
	u8 pwdtype;//��������
	u8 lock_sta;//��ͷ״̬
	u8 pwd_anchor;//��ǵڼ�������
	u8 encodermode;//0Ϊ����ˢ��ҳ�棬1���ڼӼ�����
	u8 lastVAL; //��һ�ε�ѹֵ
	u8 OPEN_PAGE_STR;//����������ɱ�־λ
	u8 RTC_ALARM;//RTC�����ж���ɱ�־λ
	u8 RTC_Alarm_Dex;//���ӱ��
	u8 S_CHAN;//0����״̬ 1��ȫ���� 2��ȫ���ر�
  u8 FREEDATE;//���ʹ������
	u8 ISAUZ;//�Ƿ���ע����Ȩ
	u8 TOSUBPAGE;//�������������Ӧ����ҳ���־λ
	u8 WeekAnchor;//���ڵ��α�
	u8 FREQUENCE;//PWM��Ƶ��
	u8 link;//���ÿ���
	u8 ONESECDELAY;//���Եȴ�һ����ʱ
	u8 ISSHOWAUZ;//�Ƿ���ʾAUZ
	u8 ISMENU;//MENU����
	u8 langage;//����
	u8 PWDsta;//1��ʾ�Ѿ����������
	u8 IsShowAUZNumset;//�Ƿ���ʾ����ʹ�ô���
}_flag_dev;

typedef struct{

u32 Sec_MAX;
u32 Sec_MID;
u32 Sec_MIN;
u8 MAX_Alarm_Dex;
u8 MID_Alarm_Dex;
u8 MIN_Alarm_Dex;	
	
}_Alarm_Sequence_Dev;
extern _flag_dev flag_dev;
extern  _Alarm_Sequence_Dev Alarm_Sequence;
#define NUll    0
#define DELAY   1
#define SWITCH  2
#define DATE    3
#define UV_OV   4
#define TIMER   5
#define RESET   6
#define IP      7
#define PWD     8
#define AUZ     9  
#define HOME    10
#define HOME_X    11
#define KEY_BOARD  12
#define TRIGO      13
#define OPEN_N 14


#define SAVE 1
#define DEL 10
#define OK  11
#define NUM_NULL 12

#define USER 0
#define SETTINGS 1

#define L_CLOSE 1
#define L_OPEN 2
#endif 

