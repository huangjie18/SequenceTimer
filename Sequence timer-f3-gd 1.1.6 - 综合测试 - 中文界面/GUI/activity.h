#ifndef __ACTIVITY_H
#define __ACTIVITY_H
#include "sys.h"

typedef struct
{
    u8 anchor;//avtivity界面锚点（白色方框位置）
    u8 num_anchor;//所更改de数字锚点
} _anchor_dev;

typedef struct
{

    u8 	delay_time_anchor_flag;//进入相应chan延时设置数字锚点更新标志位
    u8  delay_time_flag;//通道延时执行递增函数标志位
    u8  delay_time_flag_f;	//通道延时执行递增函数完成标志位
    u8  delay_data_flag;//定时数据更新标志位


    u8  date_time_anchor_flag;	//进入时间或日期设置数字锚点更新标志位
    u8  date_time_flag;  //执行递增函数标志位
    u8  date_time_flag_f;	//执行递增函数完成标志位
    u8  date_data_flag;//时间或者日期数据更新标志位


} _flag_dev;

#define ENABLE   1
#define DISNABLE 0




#define ANCHOR_1 1
#define ANCHOR_2 2
#define ANCHOR_3 3
#define ANCHOR_4 4
#define ANCHOR_5 5
#define ANCHOR_6 6
#define ANCHOR_7 7
#define ANCHOR_8 8
#define ANCHOR_9 9
#define ANCHOR_10 10


void while_activity(void);

void main_page_activity(void);
void channel_set_page_activity(void);
void channel_delay_main_page_activity(void);
void channel_delay_set_page_activity(void);
void channel_switch_set_page_activity(void);
void system_page_activity_1(void);
void system_page_activity_2(void);
void uv_ov_protection_set_page_activity(void);
void ip_address_set_page_activity(void);
void restore_factory_settings_page_activity(void);
void date_timeswitch_set_main_page_activity(void);
void date_time_set_page_activity(void);
void time_switch_set_page_activity(u8 pagenumber);
void chan_time_switch_set_page_activity(void);


void main_page_activity_key(void);
void channel_set_page_activity_key(void);
void channel_delay_main_page_activity_key(void);
void channel_delay_set_page_activity_key(void);
void channel_switch_set_page_activity_key(void);
void system_page_activity_key_1(void);
void system_page_activity_key_2(void);
void uv_ov_protection_set_page_activity_key(void);
void ip_address_set_page_activity_key(void);
void restore_factory_settings_page_activity_key(void);
void date_timeswitch_set_main_page_activity_key(void);
void date_time_set_page_activity_key(void);
void time_switch_set_page_activity_key(u8 pagenumber);
void chan_time_switch_set_page_activity_key(void);

void encoder_algorithm(void);
void time_up_date(void);
void chan_state_up_data(void);
void ip_three_show(void);
void rd_op_up_show(u8 rd,u8 op,u8 up);
void chan_time_delay_show(u8 chan_x,u8 open_delay,u8 close_delay);
void chan_delay_four_show(void);
void data_time_up_date(void);
void date_timr_show(void);
void date_time_flash(void);
void calendar_to_date_time_dev(void);
void date_time_dev_to_date_time(void);

void rtp_test(void);


#endif

