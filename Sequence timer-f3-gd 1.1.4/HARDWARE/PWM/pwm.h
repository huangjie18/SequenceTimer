#ifndef __PWM_H
#define __PWM_H
#include "sys.h"
void Pwm_Init(void);
void Pwm_Output_Init(void);
void Pwm_Input_Init(void);
void TIM5_Init(void);
void Delay_One_Sec(void);
void Set_Frequence(u16 arr);
#endif

