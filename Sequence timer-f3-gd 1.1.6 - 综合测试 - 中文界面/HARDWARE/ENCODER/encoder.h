#ifndef __KEY_H
#define __KEY_H
#include "sys.h"

#define ENCODER_A PBout(10)
#define ENCODER_B PBout(11)
#define ENCODER_KEY PBout(12)
#define KEY PBout(13)


#define TURN_R 1;
#define TURN_L 2;
#define EN_KEY 3;
#define RE_KEY 4;

void key_init();//按键初始化函数
u8 encoder_dir(void);//编码器
u8 relay_key(void);//继电器开关按键

#endif