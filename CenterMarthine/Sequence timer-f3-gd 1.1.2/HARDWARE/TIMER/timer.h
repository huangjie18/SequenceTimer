#ifndef __TIMER_H
#define __TIMER_H
#include "sys.h"
void TIM4_Int_Init(u16 arr,u16 psc);

#define Pin(n)  GPIO_ReadOutputDataBit(GPIOC,n)


#endif
