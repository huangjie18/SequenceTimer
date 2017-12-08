#ifndef __ACTION_H
#define __ACTION_H
#include "sys.h"
void screen_action(void);
void page_flash(void);
void data_flash(void);
void add_sb(void);
void save_action(void);
void Alarm_Action(void);
u32 Sec_counter(u16 syear,u8 smon,u8 sday,u8 hour,u8 min,u8 sec);
#endif

