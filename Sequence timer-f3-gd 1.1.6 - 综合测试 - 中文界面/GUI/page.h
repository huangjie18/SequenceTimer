#ifndef __PAGE_H
#define __PAGE_H
#include "sys.h"

void main_page(void);//��ҳ��
void channel_set_page(void);

//ͨ������ҳ��
void channel_delay_main_page(void);//ͨ����ʱ��ҳ
void channel_delay_set_page(u8 pagenunber);//ͨ����ʱ����ҳ��
void channel_switch_set_page(u8 pagenumber);//ͨ����������ҳ��

//ϵͳ����ҳ��
void system_page(u8 pagenumber);//ϵͳ������ҳ��
void restore_factory_settings_page(void);//�ָ���������ҳ��
void ip_address_set_page(void);//������ַ����ҳ��
void uv_ov_protection_set_page(void);//��ѹǷѹ����ҳ��

void date_timeswitch_set_main_page(void);//ʱ��Ͷ�ʱ����ҳ��
void date_time_set_page(void);//ʱ������ҳ��
void time_switch_set_page(u8 switchnum);//��ʱ����ҳ��
void chan_time_switch_set_page(u8 mode);//ͨ����ʱ��������ҳ��

void delay_set_page(u8 chan_x);
#endif

