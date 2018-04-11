#ifndef __DATA_H
#define __DATA_H
#include "sys.h"
/*C�����﷨������һ��Ҫ�����õ�ǰ��*/

/*��������*/
#define ON  1
#define OFF 0
#define PROHIBIT  0
#define CHAN_OPEN 1
#define CHAN_CLOSE 2
#define LOOP 1
#define ONCE 0
/*��ʱ����*/
typedef struct                   
{   
    u8 timer_state;//��ʱ�أ���������   
    u8 mode;//loop once
    u16 date_year;
    u8 date_month;
    u8 date_day;
    u8 time_hour;
    u8 time_min;
    u8 time_sec;
	  u8 chan1;
	  u8 chan2;
	  u8 chan3;
	  u8 chan4;
	  u8 chan5;
	  u8 chan6;
	  u8 chan7;
 	  u8 chan8;
    u32 SecCount;
	  u8 TimerName;
	  u8 week;//��λ����λ->SUN..SAT

} _timer_dev;
/*ʱ����IP��ַ����*/
typedef struct{
  
  u8 ip;
	
}_ip_data ;
/*��ѹǷѹ��������*/
typedef struct{
 u8 rdv;
 u8 uv;
 u8 uv_state;
 u16 ov;
 u8 ov_state;		
}_uv_ov_data;
/*����ʱ����*/
typedef struct{  
	u8 chan1;
	u8 chan2;
	u8 chan3;
	u8 chan4;
	u8 chan5;
	u8 chan6;
	u8 chan7;
	u8 chan8;
}_chan_open_data;
/*�޸Ŀ�����ʱ���м����*/
typedef struct{
	u16 data1;
	u16 data2;
	u16 data3;
	u16 data4;
}_chan_data;
/*����ʱ����*/
typedef struct{
  
	u8 chan1;
	u8 chan2;
	u8 chan3;
	u8 chan4;
	u8 chan5;
	u8 chan6;
	u8 chan7;
	u8 chan8;
	
}_chan_close_data;
/*ͨ����������*/
typedef struct{
  
	u8 chan1;
	u8 chan2;
	u8 chan3;
	u8 chan4;
	u8 chan5;
	u8 chan6;
	u8 chan7;
	u8 chan8;
	
}_chan_switch_data;
/*ʱ����������*/
typedef struct{
	u16 date_year; 
	u8 date_month;
	u8 date_day;
	u8 time_hour;
	u8 time_min;

}_date_time_data;
/*��������*/
typedef struct{
u8 p_one;
u8 p_two;
u8 p_three;	
u8 p_four;	
u8 p_five;	
u8 p_six;
}pwd_data;
/*ͨ��ʹ�ܽṹ��*/
typedef struct{
u8 CHAN1;
u8 CHAN2;
u8 CHAN3;
u8 CHAN4;
u8 CHAN5;
u8 CHAN6;
u8 CHAN7;
u8 CHAN8;
}CHANEN;
extern CHANEN ChanenStructure;
typedef struct{
u8 CurrentCnt;
u8 SurplusCnt;
u8 SetCnt;	
}AUZCNT;
extern AUZCNT AuzCnt;
extern AUZCNT AuzCntData;
/*����ö������*/
enum INDEX{ISMAIN=1,ISDELAY,ISIP,ISUV_OV,ISTIMER,ISPWD,ISAUZ,ISWRITEALL,ISSWITCH};
enum TimerIndex{ISTIMER1=1,ISTIMER2,ISTIMER3,ISTIMER4,ISTIMER5,ISTIMER6,ISTIMER7,ISTIMER8,ISTIMER9,ISTIMER10};
extern _chan_open_data   chan_open_data;
extern _chan_close_data  chan_close_data;
extern _ip_data ip_data;
extern _timer_dev timer_dev_1;
extern _timer_dev timer_dev_2;
extern _timer_dev timer_dev_3;
extern _timer_dev timer_dev_4;
extern _timer_dev timer_dev_5;
extern _timer_dev timer_dev_6;
extern _timer_dev timer_dev_7;
extern _timer_dev timer_dev_8;
extern _timer_dev timer_dev_6;
extern _timer_dev timer_dev_9;
extern _timer_dev timer_dev_10;
extern _timer_dev chan_dev;	
extern enum INDEX DATAINDEX;
extern enum TimerIndex TIMERINDEX;
extern u8 ISREDLAYFLAGCHANGE;
void EnableDisableChannel(u8 *buf);
void Reset_deflaut(void);
void ReadAndSave(u8 Index,u8 mode);
void InitDefaultElement(void);
void DefaultElement(void);

/*ͨ�ź���*/
void ArithmaticOfCommunication(void);
void WRProtectionparameter(u8*buf);
void ChannelAction(u8 *buf);
void RWChannelParameter(u8* buf);
void WRDateParameter(u8* buf);
void WRIPAddress(u8*buf);
void ReadChannelState(u8 *buf);
void Resetparameter(u8 *buf);
void RValtage(u8 *buf);
void EnableDisableChannel(u8 *buf);
void WRTimerParameter(u8 *buf);
#endif


