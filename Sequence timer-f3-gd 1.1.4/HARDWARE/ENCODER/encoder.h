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

void key_init();//������ʼ������
u8 encoder_dir(void);//������
u8 relay_key(void);//�̵������ذ���

#endif