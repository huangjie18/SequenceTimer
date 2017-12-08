#ifndef __DATA_H
#define __DATA_H
#include "sys.h"



#define ON  1
#define OFF 0
#define PROHIBIT  0
#define CHAN_OPEN 1
#define CHAN_CLOSE 2
#define LOOP 0
#define ONCE 1

typedef struct                                                    //声明一定要在引用的前面
{

	
    u8 timer_state;//定时关，开，禁用   
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

} _timer_dev;

typedef struct{
  
  u16 ip;
	
}_ip_data ;

typedef struct{

 u16 rdv;
 u16 uv;
 u8 uv_state;
 u16 ov;
 u8 ov_state;	
	
}_uv_ov_data;

typedef struct{
  
	u16 chan1;
	u16 chan2;
	u16 chan3;
	u16 chan4;
	u16 chan5;
	u16 chan6;
	u16 chan7;
	u16 chan8;
	
}_chan_open_data;//开延时时间
typedef struct{
  
	u16 data1;
	u16 data2;
	u16 data3;
	u16 data4;

}_chan_data;//修改开关延时的中间变量
typedef struct{
  
	u16 chan1;
	u16 chan2;
	u16 chan3;
	u16 chan4;
	u16 chan5;
	u16 chan6;
	u16 chan7;
	u16 chan8;
	
}_chan_close_data;//关延时时间

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

typedef struct{

	
	u16 date_year; 
	u8 date_month;
	u8 date_day;
	u8 time_hour;
	u8 time_min;

}_date_time_data;

typedef struct{
u8 p_one;
u8 p_two;
u8 p_three;	
u8 p_four;	
u8 p_five;	
u8 p_six;
}pwd_data;

extern _timer_dev timer_dev_1;
extern _timer_dev timer_dev_2;
extern _timer_dev timer_dev_3;//可#include头文件引用这些结构体
extern _timer_dev chan_dev;	

void Reset_deflaut(void);




#endif


