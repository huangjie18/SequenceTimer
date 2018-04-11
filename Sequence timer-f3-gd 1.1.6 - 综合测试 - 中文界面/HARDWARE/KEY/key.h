#ifndef __KEY_H
#define __KEY_H
#include "sys.h"


	
//编码器状态结构体	
typedef struct{
 u8 EN_STATE;
 u8 EN_KEY	;
}_encoder_dev;

typedef struct{
	
u8 relay_key_state;
	
}_relay_key_dev;

extern _relay_key_dev relay_key_dev;


//编码器和按键状态
#define TURN_R 1
#define TURN_L 2
#define EN_KEY_UP 3
#define EN_KEY_DOWN 6
#define RE_KEY_UP 4
#define RE_KEY_DOWN 5
#define XNULL 0
/*进入子页面的编码器方向标志位更新*/
#define SUBLEFT 7
#define SUBRIGHT 8

//电平状态
#define  H 1
#define  L 0

	//读取电平状态
#define ENCODER_B      PBin(15)
#define ENCODER_A      PBin(14)
#define ENCODER_KEY    PBin(12)
#define RELAY_KEY      PBin(13)

//#define ENCODER_B      PBin(10)
//#define ENCODER_A      PBin(11)
//#define ENCODER_KEY    PBin(12)
//#define RELAY_KEY      PBin(13)


void key_init(void);//按键初始化函数
void encoder(void);//编码器旋转状态
void encoder_key(void);//编码器按键状态
void relay_key(void);//继电器开关按键
#endif











