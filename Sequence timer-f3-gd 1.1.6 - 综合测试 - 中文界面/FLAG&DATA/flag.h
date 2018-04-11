#ifndef __FLAG_H
#define __FLAG_H 
#include "sys.h"
typedef struct{

	u8 activity_flag;//activity激活标志位
	u8 action_flag;//当前activity可激活触屏时间，编码器事件
	u8 page_num; //菜单栏的页数
	u8 screen_flag;//屏幕是否支持长按标志位
  u8 screen_key;//屏幕加减法标志位
	u8 anchor;//activity上锚点标志位
	u8 activity_num;//activity的页数
  u8 save_flag;//保存数据标志位	
	u8 KEY_board_sta;//是否使用软键盘标志位
	u8 key_board_num;//软键盘
	u8 key_board_state;//是否按下标志位
	u8 pwdtype;//密码类型
	u8 lock_sta;//锁头状态
	u8 pwd_anchor;//标记第几次输入
	u8 encodermode;//0为用于刷新页面，1用于加减数字
	u8 lastVAL; //上一次电压值
	u8 OPEN_PAGE_STR;//开机画面完成标志位
	u8 RTC_ALARM;//RTC闹钟中断完成标志位
	u8 RTC_Alarm_Dex;//闹钟编号
	u8 S_CHAN;//0：空状态 1：全部打开 2：全部关闭
  u8 FREEDATE;//免费使用天数
	u8 ISAUZ;//是否已注册授权
	u8 TOSUBPAGE;//从左侧栏进入相应的子页面标志位
	u8 WeekAnchor;//星期的游标
	u8 FREQUENCE;//PWM波频率
	u8 link;//禁用开关
	u8 ONESECDELAY;//可以等待一秒延时
	u8 ISSHOWAUZ;//是否显示AUZ
	u8 ISMENU;//MENU按下
	u8 langage;//语言
	u8 PWDsta;//1表示已经输入旧密码
	u8 IsShowAUZNumset;//是否显示设置使用次数
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

