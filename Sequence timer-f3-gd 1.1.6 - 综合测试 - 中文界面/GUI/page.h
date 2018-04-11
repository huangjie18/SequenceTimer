#ifndef __PAGE_H
#define __PAGE_H
#include "sys.h"

void main_page(void);//主页面
void channel_set_page(void);

//通道设置页面
void channel_delay_main_page(void);//通道延时主页
void channel_delay_set_page(u8 pagenunber);//通道延时设置页面
void channel_switch_set_page(u8 pagenumber);//通道开关设置页面

//系统设置页面
void system_page(u8 pagenumber);//系统设置主页面
void restore_factory_settings_page(void);//恢复出厂设置页面
void ip_address_set_page(void);//本机地址设置页面
void uv_ov_protection_set_page(void);//过压欠压保护页面

void date_timeswitch_set_main_page(void);//时间和定时设置页面
void date_time_set_page(void);//时间设置页面
void time_switch_set_page(u8 switchnum);//定时设置页面
void chan_time_switch_set_page(u8 mode);//通道定时开关设置页面

void delay_set_page(u8 chan_x);
#endif

