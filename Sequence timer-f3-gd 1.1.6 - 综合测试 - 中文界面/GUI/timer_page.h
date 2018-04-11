#ifndef __TIMER_PAGE_H
#define __TIMER_PAGE_H
#include "data.h"
#include "sys.h"
void timer_page_activity(void);
void timer_page_action(void);
void timer_data_flash(void);
void TimerAction(u32 second);
void Alarm_Action(_timer_dev* timer_dev);
u32 Sec_counter(u16 syear,u8 smon,u8 sday,u8 hour,u8 min,u8 sec);
void ISWEEKALARM(_timer_dev *timer_dev,u8 week);
#endif


