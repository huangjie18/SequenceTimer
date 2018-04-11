#include "data.h"
#include "rtc.h"
#include "24cxx.h"
#include "flag.h"
#include "key.h"
#include "main_setting_page.h"
#include "rs232.h"
#include "lcd.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
地址：0~250
0~14  触摸屏参数
15    存储IP地址0~255
16    回差值
17    欠压保护阈值
18    欠压保护开关
19~20 过压保护阈值（半字储存）
21    过压保护开关
22~29 延时开时序0~255s 22为CH1
30~37 延时关时序0~255s 30为CH1
38~43 用户密码
220   记录授权天数
221   标记是否注册
222~231   timer1~10 week
232 CURREBT
233 SURPLUS
234 SET CNT
235 Language
236~243 8个通道的使能开关

      Timer1                      Timer2                       Timer3                   Timer4                   Timer5
44    定时状态               61    定时状态            78       定时状态          101       定时状态        118       定时状态
45    定时模式               62    定时模式            79       定时模式          102       定时模式        119       定时模式
46~47 年                     63~64 年                  80~81   年                103~104   年              120~121   年
48    月                     65    月                  82      月                105      月               122      月
49    日                     66    日                  83      日                106      日               123      日
50    时                     67    时                  84      时                107      时               124      时
51    分                     68    分                  85      分                108      分               125      分
52    秒                     69    秒                  86      秒                109      秒               126      秒
53~60 CH1~CH2                70~77 CH1~CH2             87~94    CH1~CH2         110~117    CH1~CH2         127~134    CH1~CH2


       Timer6                      Timer7                    Timer8                    Timer9                    Timer10
135       定时状态           152       定时状态         169       定时状态        186       定时状态        203       定时状态
136       定时模式           153       定时模式         170       定时模式        187       定时模式        204       定时模式
137~138   年                 154~155   年              171~172   年              188~189   年              205~206   年
139      月                  156      月               173      月               190      月               207       月
140     日                   157      日               174      日               191      日               208       日
141      时                  158      时               175      时               192      时               209       时
142      分                  159      分               176      分               193      分               210       分
143      秒                  160      秒               177      秒               194      秒               211       秒
144~151    CH1~CH2           161~168    CH1~CH2        178~185    CH1~CH2        195~202    CH1~CH2        212~219    CH1~CH2



*/
AUZCNT AuzCnt= {0,50,50};
AUZCNT AuzCntData;
_ip_data ip_data= {1};
_uv_ov_data uv_ov_data= {10,85,OFF,265,OFF,};
_date_time_data date_time_data;
_chan_open_data  chan_open_data= {1,2,3,4,5,6,7,8,};
_chan_close_data  chan_close_data= {8,7,6,5,4,3,2,1,};
_chan_data chan_data;
pwd_data user_pwd= {1,2,3,4,5,6};
pwd_data settings_pwd= {1,2,3,4,5,6};
CHANEN ChanenStructure= {1,1,1,1,1,1,1,1};
_timer_dev timer_dev_1= {0,1,2017,10,1,12,0,1,0,0,0,0,0,0,0,0,0,1};
_timer_dev timer_dev_2= {0,1,2017,10,1,12,0,2,0,0,0,0,0,0,0,0,0,2};
_timer_dev timer_dev_3= {0,1,2017,10,1,12,0,3,0,0,0,0,0,0,0,0,0,3};
_timer_dev timer_dev_4= {0,1,2017,10,1,12,0,4,0,0,0,0,0,0,0,0,0,4};
_timer_dev timer_dev_5= {0,1,2017,10,1,12,0,5,0,0,0,0,0,0,0,0,0,5};
_timer_dev timer_dev_6= {0,1,2017,10,1,12,0,6,0,0,0,0,0,0,0,0,0,6};
_timer_dev timer_dev_7= {0,1,2017,10,1,12,0,7,0,0,0,0,0,0,0,0,0,7};
_timer_dev timer_dev_8= {0,1,2017,10,1,12,0,8,0,0,0,0,0,0,0,0,0,8};
_timer_dev timer_dev_9= {0,1,2017,10,1,12,0,9,0,0,0,0,0,0,0,0,0,9};
_timer_dev timer_dev_10= {0,1,2017,10,1,12,0,10,0,0,0,0,0,0,0,0,10};
/*修改TIMER参数的中间变量*/
_timer_dev chan_dev;
/*TIMERX常量*/
enum TimerIndex TIMERINDEX;
/*先定义函数，后面实现，放在前面后面的函数调用*/
void DefaultElement(void);
/*恢复出厂数据*/
void Reset_deflaut()
{
    ip_data.ip=1;
    uv_ov_data.rdv=10;
    uv_ov_data.uv=85;
    uv_ov_data.uv_state=OFF;
    uv_ov_data.ov=265;
    uv_ov_data.ov_state=OFF;

    chan_open_data.chan1=1;
    chan_open_data.chan2=2;
    chan_open_data.chan3=3;
    chan_open_data.chan4=4;
    chan_open_data.chan5=5;
    chan_open_data.chan6=6;
    chan_open_data.chan7=7;
    chan_open_data.chan8=8;

    chan_close_data.chan1=8;
    chan_close_data.chan2=7;
    chan_close_data.chan3=6;
    chan_close_data.chan4=5;
    chan_close_data.chan5=4;
    chan_close_data.chan6=3;
    chan_close_data.chan7=2;
    chan_close_data.chan8=1;

    EnCH1=1;
    EnCH2=1;
    EnCH3=1;
    EnCH4=1;
    EnCH5=1;
    EnCH6=1;
    EnCH7=1;
    EnCH8=1;
    /*Timer1*/
    timer_dev_1.timer_state=0;
    timer_dev_1.mode=0;
    timer_dev_1.date_year=2017;
    timer_dev_1.date_month=10;
    timer_dev_1.date_day=1;
    timer_dev_1.time_hour=12;
    timer_dev_1.time_min=0;
    timer_dev_1.time_sec=1;
    timer_dev_1.chan1=0;
    timer_dev_1.chan2=0;
    timer_dev_1.chan3=0;
    timer_dev_1.chan4=0;
    timer_dev_1.chan5=0;
    timer_dev_1.chan6=0;
    timer_dev_1.chan7=0;
    timer_dev_1.chan8=0;

    /*Timer2*/
    timer_dev_2.timer_state=0;
    timer_dev_2.mode=0;
    timer_dev_2.date_year=2017;
    timer_dev_2.date_month=10;
    timer_dev_2.date_day=1;
    timer_dev_2.time_hour=12;
    timer_dev_2.time_min=0;
    timer_dev_2.time_sec=2;
    timer_dev_2.chan1=0;
    timer_dev_2.chan2=0;
    timer_dev_2.chan3=0;
    timer_dev_2.chan4=0;
    timer_dev_2.chan5=0;
    timer_dev_2.chan6=0;
    timer_dev_2.chan7=0;
    timer_dev_2.chan8=0;

    /*Timer3*/
    timer_dev_3.timer_state=0;
    timer_dev_3.mode=0;
    timer_dev_3.date_year=2017;
    timer_dev_3.date_month=10;
    timer_dev_3.date_day=1;
    timer_dev_3.time_hour=12;
    timer_dev_3.time_min=0;
    timer_dev_3.time_sec=3;
    timer_dev_3.chan1=0;
    timer_dev_3.chan2=0;
    timer_dev_3.chan3=0;
    timer_dev_3.chan4=0;
    timer_dev_3.chan5=0;
    timer_dev_3.chan6=0;
    timer_dev_3.chan7=0;
    timer_dev_3.chan8=0;

    /*Timer4*/
    timer_dev_4.timer_state=0;
    timer_dev_4.mode=0;
    timer_dev_4.date_year=2017;
    timer_dev_4.date_month=10;
    timer_dev_4.date_day=1;
    timer_dev_4.time_hour=12;
    timer_dev_4.time_min=0;
    timer_dev_4.time_sec=4;
    timer_dev_4.chan1=0;
    timer_dev_4.chan2=0;
    timer_dev_4.chan3=0;
    timer_dev_4.chan4=0;
    timer_dev_4.chan5=0;
    timer_dev_4.chan6=0;
    timer_dev_4.chan7=0;
    timer_dev_4.chan8=0;

    /*Timer5*/
    timer_dev_5.timer_state=0;
    timer_dev_5.mode=0;
    timer_dev_5.date_year=2017;
    timer_dev_5.date_month=10;
    timer_dev_5.date_day=1;
    timer_dev_5.time_hour=12;
    timer_dev_5.time_min=0;
    timer_dev_5.time_sec=5;
    timer_dev_5.chan1=0;
    timer_dev_5.chan2=0;
    timer_dev_5.chan3=0;
    timer_dev_5.chan4=0;
    timer_dev_5.chan5=0;
    timer_dev_5.chan6=0;
    timer_dev_5.chan7=0;
    timer_dev_5.chan8=0;

    /*Timer6*/
    timer_dev_6.timer_state=0;
    timer_dev_6.mode=0;
    timer_dev_6.date_year=2017;
    timer_dev_6.date_month=10;
    timer_dev_6.date_day=1;
    timer_dev_6.time_hour=12;
    timer_dev_6.time_min=0;
    timer_dev_6.time_sec=6;
    timer_dev_6.chan1=0;
    timer_dev_6.chan2=0;
    timer_dev_6.chan3=0;
    timer_dev_6.chan4=0;
    timer_dev_6.chan5=0;
    timer_dev_6.chan6=0;
    timer_dev_6.chan7=0;
    timer_dev_6.chan8=0;

    /*Timer7*/
    timer_dev_7.timer_state=0;
    timer_dev_7.mode=0;
    timer_dev_7.date_year=2017;
    timer_dev_7.date_month=10;
    timer_dev_7.date_day=1;
    timer_dev_7.time_hour=12;
    timer_dev_7.time_min=0;
    timer_dev_7.time_sec=7;
    timer_dev_7.chan1=0;
    timer_dev_7.chan2=0;
    timer_dev_7.chan3=0;
    timer_dev_7.chan4=0;
    timer_dev_7.chan5=0;
    timer_dev_7.chan6=0;
    timer_dev_7.chan7=0;
    timer_dev_7.chan8=0;

    /*Timer8*/
    timer_dev_8.timer_state=0;
    timer_dev_8.mode=0;
    timer_dev_8.date_year=2017;
    timer_dev_8.date_month=10;
    timer_dev_8.date_day=1;
    timer_dev_8.time_hour=12;
    timer_dev_8.time_min=0;
    timer_dev_8.time_sec=8;
    timer_dev_8.chan1=0;
    timer_dev_8.chan2=0;
    timer_dev_8.chan3=0;
    timer_dev_8.chan4=0;
    timer_dev_8.chan5=0;
    timer_dev_8.chan6=0;
    timer_dev_8.chan7=0;
    timer_dev_8.chan8=0;

    /*Timer9*/
    timer_dev_9.timer_state=0;
    timer_dev_9.mode=0;
    timer_dev_9.date_year=2017;
    timer_dev_9.date_month=10;
    timer_dev_9.date_day=1;
    timer_dev_9.time_hour=12;
    timer_dev_9.time_min=0;
    timer_dev_9.time_sec=9;
    timer_dev_9.chan1=0;
    timer_dev_9.chan2=0;
    timer_dev_9.chan3=0;
    timer_dev_9.chan4=0;
    timer_dev_9.chan5=0;
    timer_dev_9.chan6=0;
    timer_dev_9.chan7=0;
    timer_dev_9.chan8=0;

    /*Timer10*/
    timer_dev_10.timer_state=0;
    timer_dev_10.mode=0;
    timer_dev_10.date_year=2017;
    timer_dev_10.date_month=10;
    timer_dev_10.date_day=1;
    timer_dev_10.time_hour=12;
    timer_dev_10.time_min=0;
    timer_dev_10.time_sec=10;
    timer_dev_10.chan1=0;
    timer_dev_10.chan2=0;
    timer_dev_10.chan3=0;
    timer_dev_10.chan4=0;
    timer_dev_10.chan5=0;
    timer_dev_10.chan6=0;
    timer_dev_10.chan7=0;
    timer_dev_10.chan8=0;

    /*Timerweek*/
    AT24CXX_WriteOneByte(222,0);
    AT24CXX_WriteOneByte(223,0);
    AT24CXX_WriteOneByte(224,0);
    AT24CXX_WriteOneByte(225,0);
    AT24CXX_WriteOneByte(226,0);
    AT24CXX_WriteOneByte(227,0);
    AT24CXX_WriteOneByte(228,0);
    AT24CXX_WriteOneByte(229,0);
    AT24CXX_WriteOneByte(230,0);
    AT24CXX_WriteOneByte(231,0);
    DefaultElement();
}


/*保存数据、读取数据*/
enum INDEX DATAINDEX;
void ReadAndSave(u8 Index,u8 mode)
{
    switch(Index)
        {
        case ISDELAY:

            /*开延时数据*/
            AT24CXX_Write(22,&chan_open_data.chan1,1);
            AT24CXX_Write(23,&chan_open_data.chan2,1);
            AT24CXX_Write(24,&chan_open_data.chan3,1);
            AT24CXX_Write(25,&chan_open_data.chan4,1);
            AT24CXX_Write(26,&chan_open_data.chan5,1);
            AT24CXX_Write(27,&chan_open_data.chan6,1);
            AT24CXX_Write(28,&chan_open_data.chan7,1);
            AT24CXX_Write(29,&chan_open_data.chan8,1);

            /*关延时数据*/
            AT24CXX_Write(30,&chan_close_data.chan1,1);
            AT24CXX_Write(31,&chan_close_data.chan2,1);
            AT24CXX_Write(32,&chan_close_data.chan3,1);
            AT24CXX_Write(33,&chan_close_data.chan4,1);
            AT24CXX_Write(34,&chan_close_data.chan5,1);
            AT24CXX_Write(35,&chan_close_data.chan6,1);
            AT24CXX_Write(36,&chan_close_data.chan7,1);
            AT24CXX_Write(37,&chan_close_data.chan8,1);
            break;
        case ISSWITCH:
            AT24CXX_Write(236,&EnCH1,1);
            AT24CXX_Write(237,&EnCH2,1);
            AT24CXX_Write(238,&EnCH3,1);
            AT24CXX_Write(239,&EnCH4,1);

            AT24CXX_Write(240,&EnCH5,1);
            AT24CXX_Write(241,&EnCH6,1);
            AT24CXX_Write(242,&EnCH7,1);
            AT24CXX_Write(243,&EnCH8,1);
            break;

        case ISIP:
            AT24CXX_Write(15,&ip_data.ip,1);
            break;
        case ISUV_OV:
            AT24CXX_Write(16,&uv_ov_data.rdv,1);
            AT24CXX_Write(17,&uv_ov_data.uv,1);
            AT24CXX_Write(18,&uv_ov_data.uv_state,1);
            AT24CXX_WriteLenByte(19,(u32*)&uv_ov_data.ov,2);
            AT24CXX_Write(21,&uv_ov_data.ov_state,1);
            break;
        case ISTIMER:
            /*Timer1*/
            AT24CXX_Write(44,&timer_dev_1.timer_state,1);
            AT24CXX_Write(45,&timer_dev_1.mode,1);
            /*年月日时分秒*/
            AT24CXX_WriteLenByte(46,(u32*)&timer_dev_1.date_year,2);
            AT24CXX_Write(48,&timer_dev_1.date_month,1);
            AT24CXX_Write(49,&timer_dev_1.date_day,1);
            AT24CXX_Write(50,&timer_dev_1.time_hour,1);
            AT24CXX_Write(51,&timer_dev_1.time_min,1);
            AT24CXX_Write(52,&timer_dev_1.time_sec,1);
            /*CH1~CH8*/
            AT24CXX_Write(53,&timer_dev_1.chan1,1);
            AT24CXX_Write(54,&timer_dev_1.chan2,1);
            AT24CXX_Write(55,&timer_dev_1.chan3,1);
            AT24CXX_Write(56,&timer_dev_1.chan4,1);
            AT24CXX_Write(57,&timer_dev_1.chan5,1);
            AT24CXX_Write(58,&timer_dev_1.chan6,1);
            AT24CXX_Write(59,&timer_dev_1.chan7,1);
            AT24CXX_Write(60,&timer_dev_1.chan8,1);

            /*Timer2*/
            AT24CXX_Write(61,&timer_dev_2.timer_state,1);
            AT24CXX_Write(62,&timer_dev_2.mode,1);
            /*年月日时分秒*/
            AT24CXX_WriteLenByte(63,(u32*)&timer_dev_2.date_year,2);
            AT24CXX_Write(65,&timer_dev_2.date_month,1);
            AT24CXX_Write(66,&timer_dev_2.date_day,1);
            AT24CXX_Write(67,&timer_dev_2.time_hour,1);
            AT24CXX_Write(68,&timer_dev_2.time_min,1);
            AT24CXX_Write(69,&timer_dev_2.time_sec,1);
            /*CH1~CH8*/
            AT24CXX_Write(70,&timer_dev_2.chan1,1);
            AT24CXX_Write(71,&timer_dev_2.chan2,1);
            AT24CXX_Write(72,&timer_dev_2.chan3,1);
            AT24CXX_Write(73,&timer_dev_2.chan4,1);
            AT24CXX_Write(74,&timer_dev_2.chan5,1);
            AT24CXX_Write(75,&timer_dev_2.chan6,1);
            AT24CXX_Write(76,&timer_dev_2.chan7,1);
            AT24CXX_Write(77,&timer_dev_2.chan8,1);

            /*Timer3*/
            AT24CXX_Write(78,&timer_dev_3.timer_state,1);
            AT24CXX_Write(79,&timer_dev_3.mode,1);
            /*年月日时分秒*/
            AT24CXX_WriteLenByte(80,(u32*)&timer_dev_3.date_year,2);
            AT24CXX_Write(82,&timer_dev_3.date_month,1);
            AT24CXX_Write(83,&timer_dev_3.date_day,1);
            AT24CXX_Write(84,&timer_dev_3.time_hour,1);
            AT24CXX_Write(85,&timer_dev_3.time_min,1);
            AT24CXX_Write(86,&timer_dev_3.time_sec,1);
            /*CH1~CH8*/
            AT24CXX_Write(87,&timer_dev_3.chan1,1);
            AT24CXX_Write(88,&timer_dev_3.chan2,1);
            AT24CXX_Write(89,&timer_dev_3.chan3,1);
            AT24CXX_Write(90,&timer_dev_3.chan4,1);
            AT24CXX_Write(91,&timer_dev_3.chan5,1);
            AT24CXX_Write(92,&timer_dev_3.chan6,1);
            AT24CXX_Write(93,&timer_dev_3.chan7,1);
            AT24CXX_Write(94,&timer_dev_3.chan8,1);

            /*Timer4*/
            AT24CXX_Write(101,&timer_dev_4.timer_state,1);
            AT24CXX_Write(102,&timer_dev_4.mode,1);
            /*年月日时分秒*/
            AT24CXX_WriteLenByte(103,(u32*)&timer_dev_4.date_year,2);
            AT24CXX_Write(105,&timer_dev_4.date_month,1);
            AT24CXX_Write(106,&timer_dev_4.date_day,1);
            AT24CXX_Write(107,&timer_dev_4.time_hour,1);
            AT24CXX_Write(108,&timer_dev_4.time_min,1);
            AT24CXX_Write(109,&timer_dev_4.time_sec,1);
            /*CH1~CH8*/
            AT24CXX_Write(110,&timer_dev_4.chan1,1);
            AT24CXX_Write(111,&timer_dev_4.chan2,1);
            AT24CXX_Write(112,&timer_dev_4.chan3,1);
            AT24CXX_Write(113,&timer_dev_4.chan4,1);
            AT24CXX_Write(114,&timer_dev_4.chan5,1);
            AT24CXX_Write(115,&timer_dev_4.chan6,1);
            AT24CXX_Write(116,&timer_dev_4.chan7,1);
            AT24CXX_Write(117,&timer_dev_4.chan8,1);

            /*Timer5*/
            AT24CXX_Write(118,&timer_dev_5.timer_state,1);
            AT24CXX_Write(119,&timer_dev_5.mode,1);
            /*年月日时分秒*/
            AT24CXX_WriteLenByte(120,(u32*)&timer_dev_5.date_year,2);
            AT24CXX_Write(122,&timer_dev_5.date_month,1);
            AT24CXX_Write(123,&timer_dev_5.date_day,1);
            AT24CXX_Write(124,&timer_dev_5.time_hour,1);
            AT24CXX_Write(125,&timer_dev_5.time_min,1);
            AT24CXX_Write(126,&timer_dev_5.time_sec,1);
            /*CH1~CH8*/
            AT24CXX_Write(127,&timer_dev_5.chan1,1);
            AT24CXX_Write(128,&timer_dev_5.chan2,1);
            AT24CXX_Write(129,&timer_dev_5.chan3,1);
            AT24CXX_Write(130,&timer_dev_5.chan4,1);
            AT24CXX_Write(131,&timer_dev_5.chan5,1);
            AT24CXX_Write(132,&timer_dev_5.chan6,1);
            AT24CXX_Write(133,&timer_dev_5.chan7,1);
            AT24CXX_Write(134,&timer_dev_5.chan8,1);

            /*Timer6*/
            AT24CXX_Write(135,&timer_dev_6.timer_state,1);
            AT24CXX_Write(136,&timer_dev_6.mode,1);
            /*年月日时分秒*/
            AT24CXX_WriteLenByte(137,(u32*)&timer_dev_6.date_year,2);
            AT24CXX_Write(139,&timer_dev_6.date_month,1);
            AT24CXX_Write(140,&timer_dev_6.date_day,1);
            AT24CXX_Write(141,&timer_dev_6.time_hour,1);
            AT24CXX_Write(142,&timer_dev_6.time_min,1);
            AT24CXX_Write(143,&timer_dev_6.time_sec,1);
            /*CH1~CH8*/
            AT24CXX_Write(144,&timer_dev_6.chan1,1);
            AT24CXX_Write(145,&timer_dev_6.chan2,1);
            AT24CXX_Write(146,&timer_dev_6.chan3,1);
            AT24CXX_Write(147,&timer_dev_6.chan4,1);
            AT24CXX_Write(148,&timer_dev_6.chan5,1);
            AT24CXX_Write(149,&timer_dev_6.chan6,1);
            AT24CXX_Write(150,&timer_dev_6.chan7,1);
            AT24CXX_Write(151,&timer_dev_6.chan8,1);

            /*Timer7*/
            AT24CXX_Write(152,&timer_dev_7.timer_state,1);
            AT24CXX_Write(153,&timer_dev_7.mode,1);
            /*年月日时分秒*/
            AT24CXX_WriteLenByte(154,(u32*)&timer_dev_7.date_year,2);
            AT24CXX_Write(156,&timer_dev_7.date_month,1);
            AT24CXX_Write(157,&timer_dev_7.date_day,1);
            AT24CXX_Write(158,&timer_dev_7.time_hour,1);
            AT24CXX_Write(159,&timer_dev_7.time_min,1);
            AT24CXX_Write(160,&timer_dev_7.time_sec,1);
            /*CH1~CH8*/
            AT24CXX_Write(161,&timer_dev_7.chan1,1);
            AT24CXX_Write(162,&timer_dev_7.chan2,1);
            AT24CXX_Write(163,&timer_dev_7.chan3,1);
            AT24CXX_Write(164,&timer_dev_7.chan4,1);
            AT24CXX_Write(165,&timer_dev_7.chan5,1);
            AT24CXX_Write(166,&timer_dev_7.chan6,1);
            AT24CXX_Write(167,&timer_dev_7.chan7,1);
            AT24CXX_Write(168,&timer_dev_7.chan8,1);

            /*Timer8*/
            AT24CXX_Write(169,&timer_dev_8.timer_state,1);
            AT24CXX_Write(170,&timer_dev_8.mode,1);
            /*年月日时分秒*/
            AT24CXX_WriteLenByte(171,(u32*)&timer_dev_8.date_year,2);
            AT24CXX_Write(173,&timer_dev_8.date_month,1);
            AT24CXX_Write(174,&timer_dev_8.date_day,1);
            AT24CXX_Write(175,&timer_dev_8.time_hour,1);
            AT24CXX_Write(176,&timer_dev_8.time_min,1);
            AT24CXX_Write(177,&timer_dev_8.time_sec,1);
            /*CH1~CH8*/
            AT24CXX_Write(178,&timer_dev_8.chan1,1);
            AT24CXX_Write(179,&timer_dev_8.chan2,1);
            AT24CXX_Write(180,&timer_dev_8.chan3,1);
            AT24CXX_Write(181,&timer_dev_8.chan4,1);
            AT24CXX_Write(182,&timer_dev_8.chan5,1);
            AT24CXX_Write(183,&timer_dev_8.chan6,1);
            AT24CXX_Write(184,&timer_dev_8.chan7,1);
            AT24CXX_Write(185,&timer_dev_8.chan8,1);

            /*Timer9*/
            AT24CXX_Write(186,&timer_dev_9.timer_state,1);
            AT24CXX_Write(187,&timer_dev_9.mode,1);
            /*年月日时分秒*/
            AT24CXX_WriteLenByte(188,(u32*)&timer_dev_9.date_year,2);
            AT24CXX_Write(190,&timer_dev_9.date_month,1);
            AT24CXX_Write(191,&timer_dev_9.date_day,1);
            AT24CXX_Write(192,&timer_dev_9.time_hour,1);
            AT24CXX_Write(193,&timer_dev_9.time_min,1);
            AT24CXX_Write(194,&timer_dev_9.time_sec,1);
            /*CH1~CH8*/
            AT24CXX_Write(195,&timer_dev_9.chan1,1);
            AT24CXX_Write(196,&timer_dev_9.chan2,1);
            AT24CXX_Write(197,&timer_dev_9.chan3,1);
            AT24CXX_Write(198,&timer_dev_9.chan4,1);
            AT24CXX_Write(199,&timer_dev_9.chan5,1);
            AT24CXX_Write(200,&timer_dev_9.chan6,1);
            AT24CXX_Write(201,&timer_dev_9.chan7,1);
            AT24CXX_Write(202,&timer_dev_9.chan8,1);

            /*Timer10*/
            AT24CXX_Write(203,&timer_dev_10.timer_state,1);
            AT24CXX_Write(204,&timer_dev_10.mode,1);
            /*年月日时分秒*/
            AT24CXX_WriteLenByte(205,(u32*)&timer_dev_10.date_year,2);
            AT24CXX_Write(207,&timer_dev_10.date_month,1);
            AT24CXX_Write(208,&timer_dev_10.date_day,1);
            AT24CXX_Write(209,&timer_dev_10.time_hour,1);
            AT24CXX_Write(210,&timer_dev_10.time_min,1);
            AT24CXX_Write(211,&timer_dev_10.time_sec,1);
            /*CH1~CH8*/
            AT24CXX_Write(212,&timer_dev_10.chan1,1);
            AT24CXX_Write(213,&timer_dev_10.chan2,1);
            AT24CXX_Write(214,&timer_dev_10.chan3,1);
            AT24CXX_Write(215,&timer_dev_10.chan4,1);
            AT24CXX_Write(216,&timer_dev_10.chan5,1);
            AT24CXX_Write(217,&timer_dev_10.chan6,1);
            AT24CXX_Write(218,&timer_dev_10.chan7,1);
            AT24CXX_Write(219,&timer_dev_10.chan8,1);

            /*Timerweek*/
            AT24CXX_Write(222,&timer_dev_1.week,1);
            AT24CXX_Write(223,&timer_dev_2.week,1);
            AT24CXX_Write(224,&timer_dev_3.week,1);
            AT24CXX_Write(225,&timer_dev_4.week,1);
            AT24CXX_Write(226,&timer_dev_5.week,1);
            AT24CXX_Write(227,&timer_dev_6.week,1);
            AT24CXX_Write(228,&timer_dev_7.week,1);
            AT24CXX_Write(229,&timer_dev_8.week,1);
            AT24CXX_Write(230,&timer_dev_9.week,1);
            AT24CXX_Write(231,&timer_dev_10.week,1);

            break;
        case ISPWD:

            AT24CXX_Write(38,&user_pwd.p_one,1);
            AT24CXX_Write(39,&user_pwd.p_two,1);
            AT24CXX_Write(40,&user_pwd.p_three,1);
            AT24CXX_Write(41,&user_pwd.p_four,1);
            AT24CXX_Write(42,&user_pwd.p_five,1);
            AT24CXX_Write(43,&user_pwd.p_six,1);
            break;
        case ISAUZ:

            AT24CXX_Write(232,&AuzCnt.CurrentCnt,1);
            AT24CXX_Write(233,&AuzCnt.SurplusCnt,1);
            AT24CXX_Write(234,&AuzCnt.SetCnt,1);

            break;
        case ISWRITEALL:
            if(AT24CXX_ReadOneByte(100)!=1)
                {
                    /*刷写默认数据*/
                    DefaultElement();
                    /*刷写默认语言*/
                    AT24CXX_WriteOneByte(235,0);
                    /*刷写授权认证默认数据*/
                    AT24CXX_WriteOneByte(232,0);
                    AT24CXX_WriteOneByte(233,50);
                    AT24CXX_WriteOneByte(234,50);
                    /*标记没有注册授权和使用次数为0*/
                    AT24CXX_WriteOneByte(221,0);
                    AT24CXX_WriteOneByte(220,0);
                    /*标记刷写默认数据*/
                    AT24CXX_WriteOneByte(100,1);
                }
            break;
        case ISMAIN:
            /*上电读取24CXX数据*/


            /*----------------PWD密码-----------------*/
            AT24CXX_Read(38,&user_pwd.p_one,1);
            AT24CXX_Read(39,&user_pwd.p_two,1);
            AT24CXX_Read(40,&user_pwd.p_three,1);
            AT24CXX_Read(41,&user_pwd.p_four,1);
            AT24CXX_Read(42,&user_pwd.p_five,1);
            AT24CXX_Read(43,&user_pwd.p_six,1);

            /*------------------IP---------------*/
            AT24CXX_Read(15,&ip_data.ip,1);
            /*------------Switch-------------------*/

            AT24CXX_Read(236,EnCH1Addr,1);
            AT24CXX_Read(237,EnCH2Addr,1);
            AT24CXX_Read(238,EnCH3Addr,1);
            AT24CXX_Read(239,EnCH4Addr,1);
            AT24CXX_Read(240,EnCH5Addr,1);
            AT24CXX_Read(241,EnCH6Addr,1);
            AT24CXX_Read(242,EnCH7Addr,1);
            AT24CXX_Read(243,EnCH8Addr,1);

            /*--------------Timer----------------*/
            /*Timer1*/
            AT24CXX_Read(44,&timer_dev_1.timer_state,1);
            AT24CXX_Read(45,&timer_dev_1.mode,1);
            /*年月日时分秒*/
            AT24CXX_ReadLenByte(46,(u32*)&timer_dev_1.date_year,2);
            AT24CXX_Read(48,&timer_dev_1.date_month,1);
            AT24CXX_Read(49,&timer_dev_1.date_day,1);
            AT24CXX_Read(50,&timer_dev_1.time_hour,1);
            AT24CXX_Read(51,&timer_dev_1.time_min,1);
            AT24CXX_Read(52,&timer_dev_1.time_sec,1);
            /*CH1~CH8*/
            AT24CXX_Read(53,&timer_dev_1.chan1,1);
            AT24CXX_Read(54,&timer_dev_1.chan2,1);
            AT24CXX_Read(55,&timer_dev_1.chan3,1);
            AT24CXX_Read(56,&timer_dev_1.chan4,1);
            AT24CXX_Read(57,&timer_dev_1.chan5,1);
            AT24CXX_Read(58,&timer_dev_1.chan6,1);
            AT24CXX_Read(59,&timer_dev_1.chan7,1);
            AT24CXX_Read(60,&timer_dev_1.chan8,1);

            /*Timer2*/
            AT24CXX_Read(61,&timer_dev_2.timer_state,1);
            AT24CXX_Read(62,&timer_dev_2.mode,1);
            /*年月日时分秒*/
            AT24CXX_ReadLenByte(63,(u32*)&timer_dev_2.date_year,2);
            AT24CXX_Read(65,&timer_dev_2.date_month,1);
            AT24CXX_Read(66,&timer_dev_2.date_day,1);
            AT24CXX_Read(67,&timer_dev_2.time_hour,1);
            AT24CXX_Read(68,&timer_dev_2.time_min,1);
            AT24CXX_Read(69,&timer_dev_2.time_sec,1);
            /*CH1~CH8*/
            AT24CXX_Read(70,&timer_dev_2.chan1,1);
            AT24CXX_Read(71,&timer_dev_2.chan2,1);
            AT24CXX_Read(72,&timer_dev_2.chan3,1);
            AT24CXX_Read(73,&timer_dev_2.chan4,1);
            AT24CXX_Read(74,&timer_dev_2.chan5,1);
            AT24CXX_Read(75,&timer_dev_2.chan6,1);
            AT24CXX_Read(76,&timer_dev_2.chan7,1);
            AT24CXX_Read(77,&timer_dev_2.chan8,1);

            /*Timer3*/
            AT24CXX_Read(78,&timer_dev_3.timer_state,1);
            AT24CXX_Read(79,&timer_dev_3.mode,1);
            /*年月日时分秒*/
            AT24CXX_ReadLenByte(80,(u32*)&timer_dev_3.date_year,2);
            AT24CXX_Read(82,&timer_dev_3.date_month,1);
            AT24CXX_Read(83,&timer_dev_3.date_day,1);
            AT24CXX_Read(84,&timer_dev_3.time_hour,1);
            AT24CXX_Read(85,&timer_dev_3.time_min,1);
            AT24CXX_Read(86,&timer_dev_3.time_sec,1);
            /*CH1~CH8*/
            AT24CXX_Read(87,&timer_dev_3.chan1,1);
            AT24CXX_Read(88,&timer_dev_3.chan2,1);
            AT24CXX_Read(89,&timer_dev_3.chan3,1);
            AT24CXX_Read(90,&timer_dev_3.chan4,1);
            AT24CXX_Read(91,&timer_dev_3.chan5,1);
            AT24CXX_Read(92,&timer_dev_3.chan6,1);
            AT24CXX_Read(93,&timer_dev_3.chan7,1);
            AT24CXX_Read(94,&timer_dev_3.chan8,1);

            /*Timer4*/
            AT24CXX_Read(101,&timer_dev_4.timer_state,1);
            AT24CXX_Read(102,&timer_dev_4.mode,1);
            /*年月日时分秒*/
            AT24CXX_ReadLenByte(103,(u32*)&timer_dev_4.date_year,2);
            AT24CXX_Read(105,&timer_dev_4.date_month,1);
            AT24CXX_Read(106,&timer_dev_4.date_day,1);
            AT24CXX_Read(107,&timer_dev_4.time_hour,1);
            AT24CXX_Read(108,&timer_dev_4.time_min,1);
            AT24CXX_Read(109,&timer_dev_4.time_sec,1);
            /*CH1~CH8*/
            AT24CXX_Read(110,&timer_dev_4.chan1,1);
            AT24CXX_Read(111,&timer_dev_4.chan2,1);
            AT24CXX_Read(112,&timer_dev_4.chan3,1);
            AT24CXX_Read(113,&timer_dev_4.chan4,1);
            AT24CXX_Read(114,&timer_dev_4.chan5,1);
            AT24CXX_Read(115,&timer_dev_4.chan6,1);
            AT24CXX_Read(116,&timer_dev_4.chan7,1);
            AT24CXX_Read(117,&timer_dev_4.chan8,1);

            /*Timer5*/
            AT24CXX_Read(118,&timer_dev_5.timer_state,1);
            AT24CXX_Read(119,&timer_dev_5.mode,1);
            /*年月日时分秒*/
            AT24CXX_ReadLenByte(120,(u32*)&timer_dev_5.date_year,2);
            AT24CXX_Read(122,&timer_dev_5.date_month,1);
            AT24CXX_Read(123,&timer_dev_5.date_day,1);
            AT24CXX_Read(124,&timer_dev_5.time_hour,1);
            AT24CXX_Read(125,&timer_dev_5.time_min,1);
            AT24CXX_Read(126,&timer_dev_5.time_sec,1);
            /*CH1~CH8*/
            AT24CXX_Read(127,&timer_dev_5.chan1,1);
            AT24CXX_Read(128,&timer_dev_5.chan2,1);
            AT24CXX_Read(129,&timer_dev_5.chan3,1);
            AT24CXX_Read(130,&timer_dev_5.chan4,1);
            AT24CXX_Read(131,&timer_dev_5.chan5,1);
            AT24CXX_Read(132,&timer_dev_5.chan6,1);
            AT24CXX_Read(133,&timer_dev_5.chan7,1);
            AT24CXX_Read(134,&timer_dev_5.chan8,1);

            /*Timer6*/
            AT24CXX_Read(135,&timer_dev_6.timer_state,1);
            AT24CXX_Read(136,&timer_dev_6.mode,1);
            /*年月日时分秒*/
            AT24CXX_ReadLenByte(137,(u32*)&timer_dev_6.date_year,2);
            AT24CXX_Read(139,&timer_dev_6.date_month,1);
            AT24CXX_Read(140,&timer_dev_6.date_day,1);
            AT24CXX_Read(141,&timer_dev_6.time_hour,1);
            AT24CXX_Read(142,&timer_dev_6.time_min,1);
            AT24CXX_Read(143,&timer_dev_6.time_sec,1);
            /*CH1~CH8*/
            AT24CXX_Read(144,&timer_dev_6.chan1,1);
            AT24CXX_Read(145,&timer_dev_6.chan2,1);
            AT24CXX_Read(146,&timer_dev_6.chan3,1);
            AT24CXX_Read(147,&timer_dev_6.chan4,1);
            AT24CXX_Read(148,&timer_dev_6.chan5,1);
            AT24CXX_Read(149,&timer_dev_6.chan6,1);
            AT24CXX_Read(150,&timer_dev_6.chan7,1);
            AT24CXX_Read(151,&timer_dev_6.chan8,1);

            /*Timer7*/
            AT24CXX_Read(152,&timer_dev_7.timer_state,1);
            AT24CXX_Read(153,&timer_dev_7.mode,1);
            /*年月日时分秒*/
            AT24CXX_ReadLenByte(154,(u32*)&timer_dev_7.date_year,2);
            AT24CXX_Read(156,&timer_dev_7.date_month,1);
            AT24CXX_Read(157,&timer_dev_7.date_day,1);
            AT24CXX_Read(158,&timer_dev_7.time_hour,1);
            AT24CXX_Read(159,&timer_dev_7.time_min,1);
            AT24CXX_Read(160,&timer_dev_7.time_sec,1);
            /*CH1~CH8*/
            AT24CXX_Read(161,&timer_dev_7.chan1,1);
            AT24CXX_Read(162,&timer_dev_7.chan2,1);
            AT24CXX_Read(163,&timer_dev_7.chan3,1);
            AT24CXX_Read(164,&timer_dev_7.chan4,1);
            AT24CXX_Read(165,&timer_dev_7.chan5,1);
            AT24CXX_Read(166,&timer_dev_7.chan6,1);
            AT24CXX_Read(167,&timer_dev_7.chan7,1);
            AT24CXX_Read(168,&timer_dev_7.chan8,1);

            /*Timer8*/
            AT24CXX_Read(169,&timer_dev_8.timer_state,1);
            AT24CXX_Read(170,&timer_dev_8.mode,1);
            /*年月日时分秒*/
            AT24CXX_ReadLenByte(171,(u32*)&timer_dev_8.date_year,2);
            AT24CXX_Read(173,&timer_dev_8.date_month,1);
            AT24CXX_Read(174,&timer_dev_8.date_day,1);
            AT24CXX_Read(175,&timer_dev_8.time_hour,1);
            AT24CXX_Read(176,&timer_dev_8.time_min,1);
            AT24CXX_Read(177,&timer_dev_8.time_sec,1);
            /*CH1~CH8*/
            AT24CXX_Read(178,&timer_dev_8.chan1,1);
            AT24CXX_Read(179,&timer_dev_8.chan2,1);
            AT24CXX_Read(180,&timer_dev_8.chan3,1);
            AT24CXX_Read(181,&timer_dev_8.chan4,1);
            AT24CXX_Read(182,&timer_dev_8.chan5,1);
            AT24CXX_Read(183,&timer_dev_8.chan6,1);
            AT24CXX_Read(184,&timer_dev_8.chan7,1);
            AT24CXX_Read(185,&timer_dev_8.chan8,1);

            /*Timer9*/
            AT24CXX_Read(186,&timer_dev_9.timer_state,1);
            AT24CXX_Read(187,&timer_dev_9.mode,1);
            /*年月日时分秒*/
            AT24CXX_ReadLenByte(188,(u32*)&timer_dev_9.date_year,2);
            AT24CXX_Read(190,&timer_dev_9.date_month,1);
            AT24CXX_Read(191,&timer_dev_9.date_day,1);
            AT24CXX_Read(192,&timer_dev_9.time_hour,1);
            AT24CXX_Read(193,&timer_dev_9.time_min,1);
            AT24CXX_Read(194,&timer_dev_9.time_sec,1);
            /*CH1~CH8*/
            AT24CXX_Read(195,&timer_dev_9.chan1,1);
            AT24CXX_Read(196,&timer_dev_9.chan2,1);
            AT24CXX_Read(197,&timer_dev_9.chan3,1);
            AT24CXX_Read(198,&timer_dev_9.chan4,1);
            AT24CXX_Read(199,&timer_dev_9.chan5,1);
            AT24CXX_Read(200,&timer_dev_9.chan6,1);
            AT24CXX_Read(201,&timer_dev_9.chan7,1);
            AT24CXX_Read(202,&timer_dev_9.chan8,1);

            /*Timer10*/
            AT24CXX_Read(203,&timer_dev_10.timer_state,1);
            AT24CXX_Read(204,&timer_dev_10.mode,1);
            /*年月日时分秒*/
            AT24CXX_ReadLenByte(205,(u32*)&timer_dev_10.date_year,2);
            AT24CXX_Read(207,&timer_dev_10.date_month,1);
            AT24CXX_Read(208,&timer_dev_10.date_day,1);
            AT24CXX_Read(209,&timer_dev_10.time_hour,1);
            AT24CXX_Read(210,&timer_dev_10.time_min,1);
            AT24CXX_Read(211,&timer_dev_10.time_sec,1);
            /*CH1~CH8*/
            AT24CXX_Read(212,&timer_dev_10.chan1,1);
            AT24CXX_Read(213,&timer_dev_10.chan2,1);
            AT24CXX_Read(214,&timer_dev_10.chan3,1);
            AT24CXX_Read(215,&timer_dev_10.chan4,1);
            AT24CXX_Read(216,&timer_dev_10.chan5,1);
            AT24CXX_Read(217,&timer_dev_10.chan6,1);
            AT24CXX_Read(218,&timer_dev_10.chan7,1);
            AT24CXX_Read(219,&timer_dev_10.chan8,1);

            /*Timerweek*/
            AT24CXX_Read(222,&timer_dev_1.week,1);
            AT24CXX_Read(223,&timer_dev_2.week,1);
            AT24CXX_Read(224,&timer_dev_3.week,1);
            AT24CXX_Read(225,&timer_dev_4.week,1);
            AT24CXX_Read(226,&timer_dev_5.week,1);
            AT24CXX_Read(227,&timer_dev_6.week,1);
            AT24CXX_Read(228,&timer_dev_7.week,1);
            AT24CXX_Read(229,&timer_dev_8.week,1);
            AT24CXX_Read(230,&timer_dev_9.week,1);
            AT24CXX_Read(231,&timer_dev_10.week,1);

            /*---------------OV_UV-------------------*/
            AT24CXX_Read(16,&uv_ov_data.rdv,1);
            AT24CXX_Read(17,&uv_ov_data.uv,1);
            AT24CXX_Read(18,&uv_ov_data.uv_state,1);
            AT24CXX_ReadLenByte(19,(u32*)&uv_ov_data.ov,2);
            AT24CXX_Read(21,&uv_ov_data.ov_state,1);

            /*-------------DELAY---------------------*/
            /*开延时数据*/
            AT24CXX_Read(22,&chan_open_data.chan1,1);
            AT24CXX_Read(23,&chan_open_data.chan2,1);
            AT24CXX_Read(24,&chan_open_data.chan3,1);
            AT24CXX_Read(25,&chan_open_data.chan4,1);
            AT24CXX_Read(26,&chan_open_data.chan5,1);
            AT24CXX_Read(27,&chan_open_data.chan6,1);
            AT24CXX_Read(28,&chan_open_data.chan7,1);
            AT24CXX_Read(29,&chan_open_data.chan8,1);
            /*关延时数据*/
            AT24CXX_Read(30,&chan_close_data.chan1,1);
            AT24CXX_Read(31,&chan_close_data.chan2,1);
            AT24CXX_Read(32,&chan_close_data.chan3,1);
            AT24CXX_Read(33,&chan_close_data.chan4,1);
            AT24CXX_Read(34,&chan_close_data.chan5,1);
            AT24CXX_Read(35,&chan_close_data.chan6,1);
            AT24CXX_Read(36,&chan_close_data.chan7,1);
            AT24CXX_Read(37,&chan_close_data.chan8,1);

            /*------------------AUZ-----------------*/

            AT24CXX_Read(232,&AuzCnt.CurrentCnt,1);
            AT24CXX_Read(233,&AuzCnt.SurplusCnt,1);
            AT24CXX_Read(234,&AuzCnt.SetCnt,1);
            if(AuzCnt.SetCnt<101)
                {

                    AuzCnt.CurrentCnt+=1;
                    AuzCnt.SurplusCnt-=1;
                    if(AuzCnt.SurplusCnt!=0)
                        {
                            AT24CXX_WriteOneByte(233,AuzCnt.SurplusCnt);
                        }
                    if(AuzCnt.CurrentCnt!=AuzCnt.SetCnt)
                        {
                            AT24CXX_WriteOneByte(232,AuzCnt.CurrentCnt);
                        }
                }
            else
                {
                    AT24CXX_WriteOneByte(221,1);
                }
            AT24CXX_Read(221,&flag_dev.ISAUZ,1);
            /*默认中文*/
            AT24CXX_Read(235,&flag_dev.langage,1);
            break;
        }
}

/*写出厂数据*/
void DefaultElement()
{

    /*开延时数据*/
    AT24CXX_Write(22,&chan_open_data.chan1,1);
    AT24CXX_Write(23,&chan_open_data.chan2,1);
    AT24CXX_Write(24,&chan_open_data.chan3,1);
    AT24CXX_Write(25,&chan_open_data.chan4,1);
    AT24CXX_Write(26,&chan_open_data.chan5,1);
    AT24CXX_Write(27,&chan_open_data.chan6,1);
    AT24CXX_Write(28,&chan_open_data.chan7,1);
    AT24CXX_Write(29,&chan_open_data.chan8,1);

    /*关延时数据*/
    AT24CXX_Write(30,&chan_close_data.chan1,1);
    AT24CXX_Write(31,&chan_close_data.chan2,1);
    AT24CXX_Write(32,&chan_close_data.chan3,1);
    AT24CXX_Write(33,&chan_close_data.chan4,1);
    AT24CXX_Write(34,&chan_close_data.chan5,1);
    AT24CXX_Write(35,&chan_close_data.chan6,1);
    AT24CXX_Write(36,&chan_close_data.chan7,1);
    AT24CXX_Write(37,&chan_close_data.chan8,1);

    /*IP数据*/
    AT24CXX_Write(15,&ip_data.ip,1);
    /*UV_OV数据*/
    AT24CXX_Write(16,&uv_ov_data.rdv,1);
    AT24CXX_Write(17,&uv_ov_data.uv,1);
    AT24CXX_Write(18,&uv_ov_data.uv_state,1);
    AT24CXX_WriteLenByte(19,(u32*)&uv_ov_data.ov,2);
    AT24CXX_Write(21,&uv_ov_data.ov_state,1);

    /*SWITCH数据*/
    AT24CXX_Write(236,&EnCH1,1);
    AT24CXX_Write(237,&EnCH2,1);
    AT24CXX_Write(238,&EnCH3,1);
    AT24CXX_Write(239,&EnCH4,1);

    AT24CXX_Write(240,&EnCH5,1);
    AT24CXX_Write(241,&EnCH6,1);
    AT24CXX_Write(242,&EnCH7,1);
    AT24CXX_Write(243,&EnCH8,1);

    /*Timer1*/
    AT24CXX_Write(44,&timer_dev_1.timer_state,1);
    AT24CXX_Write(45,&timer_dev_1.mode,1);
    /*年月日时分秒*/
    AT24CXX_WriteLenByte(46,(u32*)&timer_dev_1.date_year,2);
    AT24CXX_Write(48,&timer_dev_1.date_month,1);
    AT24CXX_Write(49,&timer_dev_1.date_day,1);
    AT24CXX_Write(50,&timer_dev_1.time_hour,1);
    AT24CXX_Write(51,&timer_dev_1.time_min,1);
    AT24CXX_Write(52,&timer_dev_1.time_sec,1);
    /*CH1~CH8*/
    AT24CXX_Write(53,&timer_dev_1.chan1,1);
    AT24CXX_Write(54,&timer_dev_1.chan2,1);
    AT24CXX_Write(55,&timer_dev_1.chan3,1);
    AT24CXX_Write(56,&timer_dev_1.chan4,1);
    AT24CXX_Write(57,&timer_dev_1.chan5,1);
    AT24CXX_Write(58,&timer_dev_1.chan6,1);
    AT24CXX_Write(59,&timer_dev_1.chan7,1);
    AT24CXX_Write(60,&timer_dev_1.chan8,1);

    /*Timer2*/
    AT24CXX_Write(61,&timer_dev_2.timer_state,1);
    AT24CXX_Write(62,&timer_dev_2.mode,1);
    /*年月日时分秒*/
    AT24CXX_WriteLenByte(63,(u32*)&timer_dev_2.date_year,2);
    AT24CXX_Write(65,&timer_dev_2.date_month,1);
    AT24CXX_Write(66,&timer_dev_2.date_day,1);
    AT24CXX_Write(67,&timer_dev_2.time_hour,1);
    AT24CXX_Write(68,&timer_dev_2.time_min,1);
    AT24CXX_Write(69,&timer_dev_2.time_sec,1);
    /*CH1~CH8*/
    AT24CXX_Write(70,&timer_dev_2.chan1,1);
    AT24CXX_Write(71,&timer_dev_2.chan2,1);
    AT24CXX_Write(72,&timer_dev_2.chan3,1);
    AT24CXX_Write(73,&timer_dev_2.chan4,1);
    AT24CXX_Write(74,&timer_dev_2.chan5,1);
    AT24CXX_Write(75,&timer_dev_2.chan6,1);
    AT24CXX_Write(76,&timer_dev_2.chan7,1);
    AT24CXX_Write(77,&timer_dev_2.chan8,1);

    /*Timer3*/
    AT24CXX_Write(78,&timer_dev_3.timer_state,1);
    AT24CXX_Write(79,&timer_dev_3.mode,1);
    /*年月日时分秒*/
    AT24CXX_WriteLenByte(80,(u32*)&timer_dev_3.date_year,2);
    AT24CXX_Write(82,&timer_dev_3.date_month,1);
    AT24CXX_Write(83,&timer_dev_3.date_day,1);
    AT24CXX_Write(84,&timer_dev_3.time_hour,1);
    AT24CXX_Write(85,&timer_dev_3.time_min,1);
    AT24CXX_Write(86,&timer_dev_3.time_sec,1);
    /*CH1~CH8*/
    AT24CXX_Write(87,&timer_dev_3.chan1,1);
    AT24CXX_Write(88,&timer_dev_3.chan2,1);
    AT24CXX_Write(89,&timer_dev_3.chan3,1);
    AT24CXX_Write(90,&timer_dev_3.chan4,1);
    AT24CXX_Write(91,&timer_dev_3.chan5,1);
    AT24CXX_Write(92,&timer_dev_3.chan6,1);
    AT24CXX_Write(93,&timer_dev_3.chan7,1);
    AT24CXX_Write(94,&timer_dev_3.chan8,1);

    /*Timer4*/
    AT24CXX_Write(101,&timer_dev_4.timer_state,1);
    AT24CXX_Write(102,&timer_dev_4.mode,1);
    /*年月日时分秒*/
    AT24CXX_WriteLenByte(103,(u32*)&timer_dev_4.date_year,2);
    AT24CXX_Write(105,&timer_dev_4.date_month,1);
    AT24CXX_Write(106,&timer_dev_4.date_day,1);
    AT24CXX_Write(107,&timer_dev_4.time_hour,1);
    AT24CXX_Write(108,&timer_dev_4.time_min,1);
    AT24CXX_Write(109,&timer_dev_4.time_sec,1);
    /*CH1~CH8*/
    AT24CXX_Write(110,&timer_dev_4.chan1,1);
    AT24CXX_Write(111,&timer_dev_4.chan2,1);
    AT24CXX_Write(112,&timer_dev_4.chan3,1);
    AT24CXX_Write(113,&timer_dev_4.chan4,1);
    AT24CXX_Write(114,&timer_dev_4.chan5,1);
    AT24CXX_Write(115,&timer_dev_4.chan6,1);
    AT24CXX_Write(116,&timer_dev_4.chan7,1);
    AT24CXX_Write(117,&timer_dev_4.chan8,1);

    /*Timer5*/
    AT24CXX_Write(118,&timer_dev_5.timer_state,1);
    AT24CXX_Write(119,&timer_dev_5.mode,1);
    /*年月日时分秒*/
    AT24CXX_WriteLenByte(120,(u32*)&timer_dev_5.date_year,2);
    AT24CXX_Write(122,&timer_dev_5.date_month,1);
    AT24CXX_Write(123,&timer_dev_5.date_day,1);
    AT24CXX_Write(124,&timer_dev_5.time_hour,1);
    AT24CXX_Write(125,&timer_dev_5.time_min,1);
    AT24CXX_Write(126,&timer_dev_5.time_sec,1);
    /*CH1~CH8*/
    AT24CXX_Write(127,&timer_dev_5.chan1,1);
    AT24CXX_Write(128,&timer_dev_5.chan2,1);
    AT24CXX_Write(129,&timer_dev_5.chan3,1);
    AT24CXX_Write(130,&timer_dev_5.chan4,1);
    AT24CXX_Write(131,&timer_dev_5.chan5,1);
    AT24CXX_Write(132,&timer_dev_5.chan6,1);
    AT24CXX_Write(133,&timer_dev_5.chan7,1);
    AT24CXX_Write(134,&timer_dev_5.chan8,1);

    /*Timer6*/
    AT24CXX_Write(135,&timer_dev_6.timer_state,1);
    AT24CXX_Write(136,&timer_dev_6.mode,1);
    /*年月日时分秒*/
    AT24CXX_WriteLenByte(137,(u32*)&timer_dev_6.date_year,2);
    AT24CXX_Write(139,&timer_dev_6.date_month,1);
    AT24CXX_Write(140,&timer_dev_6.date_day,1);
    AT24CXX_Write(141,&timer_dev_6.time_hour,1);
    AT24CXX_Write(142,&timer_dev_6.time_min,1);
    AT24CXX_Write(143,&timer_dev_6.time_sec,1);
    /*CH1~CH8*/
    AT24CXX_Write(144,&timer_dev_6.chan1,1);
    AT24CXX_Write(145,&timer_dev_6.chan2,1);
    AT24CXX_Write(146,&timer_dev_6.chan3,1);
    AT24CXX_Write(147,&timer_dev_6.chan4,1);
    AT24CXX_Write(148,&timer_dev_6.chan5,1);
    AT24CXX_Write(149,&timer_dev_6.chan6,1);
    AT24CXX_Write(150,&timer_dev_6.chan7,1);
    AT24CXX_Write(151,&timer_dev_6.chan8,1);

    /*Timer7*/
    AT24CXX_Write(152,&timer_dev_7.timer_state,1);
    AT24CXX_Write(153,&timer_dev_7.mode,1);
    /*年月日时分秒*/
    AT24CXX_WriteLenByte(154,(u32*)&timer_dev_7.date_year,2);
    AT24CXX_Write(156,&timer_dev_7.date_month,1);
    AT24CXX_Write(157,&timer_dev_7.date_day,1);
    AT24CXX_Write(158,&timer_dev_7.time_hour,1);
    AT24CXX_Write(159,&timer_dev_7.time_min,1);
    AT24CXX_Write(160,&timer_dev_7.time_sec,1);
    /*CH1~CH8*/
    AT24CXX_Write(161,&timer_dev_7.chan1,1);
    AT24CXX_Write(162,&timer_dev_7.chan2,1);
    AT24CXX_Write(163,&timer_dev_7.chan3,1);
    AT24CXX_Write(164,&timer_dev_7.chan4,1);
    AT24CXX_Write(165,&timer_dev_7.chan5,1);
    AT24CXX_Write(166,&timer_dev_7.chan6,1);
    AT24CXX_Write(167,&timer_dev_7.chan7,1);
    AT24CXX_Write(168,&timer_dev_7.chan8,1);

    /*Timer8*/
    AT24CXX_Write(169,&timer_dev_8.timer_state,1);
    AT24CXX_Write(170,&timer_dev_8.mode,1);
    /*年月日时分秒*/
    AT24CXX_WriteLenByte(171,(u32*)&timer_dev_8.date_year,2);
    AT24CXX_Write(173,&timer_dev_8.date_month,1);
    AT24CXX_Write(174,&timer_dev_8.date_day,1);
    AT24CXX_Write(175,&timer_dev_8.time_hour,1);
    AT24CXX_Write(176,&timer_dev_8.time_min,1);
    AT24CXX_Write(177,&timer_dev_8.time_sec,1);
    /*CH1~CH8*/
    AT24CXX_Write(178,&timer_dev_8.chan1,1);
    AT24CXX_Write(179,&timer_dev_8.chan2,1);
    AT24CXX_Write(180,&timer_dev_8.chan3,1);
    AT24CXX_Write(181,&timer_dev_8.chan4,1);
    AT24CXX_Write(182,&timer_dev_8.chan5,1);
    AT24CXX_Write(183,&timer_dev_8.chan6,1);
    AT24CXX_Write(184,&timer_dev_8.chan7,1);
    AT24CXX_Write(185,&timer_dev_8.chan8,1);

    /*Timer9*/
    AT24CXX_Write(186,&timer_dev_9.timer_state,1);
    AT24CXX_Write(187,&timer_dev_9.mode,1);
    /*年月日时分秒*/
    AT24CXX_WriteLenByte(188,(u32*)&timer_dev_9.date_year,2);
    AT24CXX_Write(190,&timer_dev_9.date_month,1);
    AT24CXX_Write(191,&timer_dev_9.date_day,1);
    AT24CXX_Write(192,&timer_dev_9.time_hour,1);
    AT24CXX_Write(193,&timer_dev_9.time_min,1);
    AT24CXX_Write(194,&timer_dev_9.time_sec,1);
    /*CH1~CH8*/
    AT24CXX_Write(195,&timer_dev_9.chan1,1);
    AT24CXX_Write(196,&timer_dev_9.chan2,1);
    AT24CXX_Write(197,&timer_dev_9.chan3,1);
    AT24CXX_Write(198,&timer_dev_9.chan4,1);
    AT24CXX_Write(199,&timer_dev_9.chan5,1);
    AT24CXX_Write(200,&timer_dev_9.chan6,1);
    AT24CXX_Write(201,&timer_dev_9.chan7,1);
    AT24CXX_Write(202,&timer_dev_9.chan8,1);

    /*Timer10*/
    AT24CXX_Write(203,&timer_dev_10.timer_state,1);
    AT24CXX_Write(204,&timer_dev_10.mode,1);
    /*年月日时分秒*/
    AT24CXX_WriteLenByte(205,(u32*)&timer_dev_10.date_year,2);
    AT24CXX_Write(207,&timer_dev_10.date_month,1);
    AT24CXX_Write(208,&timer_dev_10.date_day,1);
    AT24CXX_Write(209,&timer_dev_10.time_hour,1);
    AT24CXX_Write(210,&timer_dev_10.time_min,1);
    AT24CXX_Write(211,&timer_dev_10.time_sec,1);
    /*CH1~CH8*/
    AT24CXX_Write(212,&timer_dev_10.chan1,1);
    AT24CXX_Write(213,&timer_dev_10.chan2,1);
    AT24CXX_Write(214,&timer_dev_10.chan3,1);
    AT24CXX_Write(215,&timer_dev_10.chan4,1);
    AT24CXX_Write(216,&timer_dev_10.chan5,1);
    AT24CXX_Write(217,&timer_dev_10.chan6,1);
    AT24CXX_Write(218,&timer_dev_10.chan7,1);
    AT24CXX_Write(219,&timer_dev_10.chan8,1);


    AT24CXX_Write(38,&user_pwd.p_one,1);
    AT24CXX_Write(39,&user_pwd.p_two,1);
    AT24CXX_Write(40,&user_pwd.p_three,1);
    AT24CXX_Write(41,&user_pwd.p_four,1);
    AT24CXX_Write(42,&user_pwd.p_five,1);
    AT24CXX_Write(43,&user_pwd.p_six,1);
}
/*上位机通信、中控通信*/
extern u8 temp[8];
extern u8 RS232_RX_BUF[8];
void ArithmaticOfCommunication()
{
	u8 j;
	 		  for(j=0;j<8;j++){			
		LCD_ShowNum(0,0+j*30,temp[j],3,24,WHITE,BLACK);	
			}
				Receiveshangweijidata();
				    /*读写IP地址*/
    WRIPAddress(RS232_RX_BUF);
    /*读取设备地址判断是否本机*/
    if(RS232_RX_BUF[0]==ip_data.ip)
        {
        /*读设备通道状态*/
     ReadChannelState(RS232_RX_BUF);
     /*读取设备电压*/
     RValtage(RS232_RX_BUF);
     /*读写IP地址*/
      WRIPAddress(RS232_RX_BUF);
            /*根据功能码进入不同的函数*/
            switch(RS232_RX_BUF[1])
                {
                case 0x16:
                    ChannelAction(RS232_RX_BUF); /*操作通道函数*/
                    break;
                case 0x13:
                    WRDateParameter(RS232_RX_BUF);/*同步上位机时钟*/
                    break;
                case 0x77:
                    Resetparameter(RS232_RX_BUF);/*恢复出厂设置*/
                    break;
                case 0x10:
                    RWChannelParameter(RS232_RX_BUF);/*写通道延时参数*/
                    WRProtectionparameter(RS232_RX_BUF);/*写过压欠压参数*/
                    break;
                case 0x02:
                    RWChannelParameter(RS232_RX_BUF);/*读取通道延时参数*/
                    WRProtectionparameter(RS232_RX_BUF);/*读过压欠压参数*/
                    break;
                case 0x05:
                    WRTimerParameter(RS232_RX_BUF);
                    break;
                case 0x06:
                    WRTimerParameter(RS232_RX_BUF);
                    break;
                case 0x11:
                    WRTimerParameter(RS232_RX_BUF);
                    break;
                case 0x12:
                    WRTimerParameter(RS232_RX_BUF);
                    break;
                }


            ClearBuf();
        }


}
/*读取电压函数*/
void RValtage(u8 *buf)
{
    u8 RVbuf[8];
    if(buf[0]==ip_data.ip&&buf[1]==0x02&&buf[2]==0x20&&buf[3]==0x12)
        {

            RVbuf[0]=ip_data.ip;
            RVbuf[1]=0x02;
            RVbuf[2]=0x20;
            RVbuf[3]=0x12;
            RVbuf[4]=0x00;
            RVbuf[5]=((flag_dev.lastVAL)&0xFF00)>>8;
            RVbuf[6]=(flag_dev.lastVAL)&0x00FF;					
            RVbuf[7]=0xAA;
            RS232_Send_Data(RVbuf,8);

        }
}
/*操作通道函数*/
u8 ISREDLAYFLAGCHANGE;//按键状态更新
extern u8 ISALARM;
void ChannelAction(u8 *buf)
{
    if(buf[1]==0x16&&buf[2]==0x00&&buf[3]==0x00)
        {
            if(buf[5]==0x01)
                {
                    switch(buf[6])
                        {
                        case 0x01:
                            if(EnCH1)
                                {
																	 if(ISALARM==0)
                                    SetCH1
																	
                                }
                            break;
                        case 0x02:
                            if(EnCH2)
                                {
																	 if(ISALARM==0)
                                   SetCH2
                                }
                            break;
                        case 0x03:
                            if(EnCH3)
                                {
																	 if(ISALARM==0)
                                   SetCH3
                                }
                            break;
                        case 0x04:
                            if(EnCH4)
                                {
																	 if(ISALARM==0)
                                   SetCH4
                                }
                            break;
                        case 0x05:
                            if(EnCH5)
                                {
																	  if(ISALARM==0)
                                  SetCH5
                                }
                            break;
                        case 0x06:
                            if(EnCH6)
                                {
																		if(ISALARM==0)														
                                   SetCH6
                                }
                            break;
                        case 0x07:
                            if(EnCH7)
                                {
																	  if(ISALARM==0)
                                   SetCH7
                                }
                            break;
                        case 0x08:
                            if(EnCH8)
                                {
																	  if(ISALARM==0)
                                   SetCH8
                                }
                            break;
                        case 0x11:
                            /*延时开*/
												    if(ISALARM==0){
                            relay_key_dev.relay_key_state=RE_KEY_DOWN;
                            ISREDLAYFLAGCHANGE=1;
														}
                            break;
                        case 0x12:
                            /*全部开*/
                            if(EnCH1)
                                {
																	  if(ISALARM==0)
                                    SetCH1
                                }
                            if(EnCH2)
                                {
																	 if(ISALARM==0)
                                   SetCH2
                                }
                            if(EnCH3)
                                {
																	 if(ISALARM==0)
                                   SetCH3
                                }
                            if(EnCH4)
                                {
																	 if(ISALARM==0)
                                   SetCH4
                                }
                            if(EnCH5)
                                {
																	 if(ISALARM==0)
                                    SetCH5
                                }
                            if(EnCH6)
                                {
																	  if(ISALARM==0)
                                   SetCH6
                                }
                            if(EnCH7)
                                {																
																	 if(ISALARM==0)
                                   SetCH7
                                }
                            if(EnCH8)
                                {
																	 if(ISALARM==0)
                                    SetCH8
                                }
                            break;
                        }
                }
            else if(buf[5]==0x00)
                {

                    switch(buf[6])
                        {
                        case 0x01:
                            ResetCH1
                            break;
                        case 0x02:
                            ResetCH2
                            break;
                        case 0x03:
                            ResetCH3
                            break;
                        case 0x04:
                            ResetCH4
                            break;
                        case 0x05:
                            ResetCH5
                            break;
                        case 0x06:
                            ResetCH6
                            break;
                        case 0x07:
                            ResetCH7
                            break;
                        case 0x08:
                            ResetCH8
                            break;
                        case 0x00:
                            /*延时关*/
                            relay_key_dev.relay_key_state=RE_KEY_UP;
                            ISREDLAYFLAGCHANGE=1;
                            break;
                        case 0x10:
                            /*全部关*/
                            ResetCH1
												    ResetCH2
												    ResetCH3
												    ResetCH4
												    ResetCH5
												    ResetCH6
												    ResetCH7
												    ResetCH8
                            break;
                        }
                }
            /*刷新界面*/
            Channel_State_Show_();
        }
}
void EnableDisableChannel(u8 *buf)
{
    u8 sendbuf[8];
    if(buf[1]==0x02)
        {
            if(EnCH8)
                {
                    sendbuf[4]|=0x10;
                }
            if(EnCH7)
                {
                    sendbuf[4]|=0x01;
                }
            if(EnCH6)
                {
                    sendbuf[5]|=0x10;
                }
            if(EnCH5)
                {
                    sendbuf[5]|=0x01;
                }
            if(EnCH4)
                {
                    sendbuf[6]|=0x10;
                }
            if(EnCH3)
                {
                    sendbuf[6]|=0x01;
                }
            if(EnCH2)
                {
                    sendbuf[7]|=0x10;
                }
            if(EnCH1)
                {
                    sendbuf[7]|=0x01;
                }

            sendbuf[0]=ip_data.ip;
            sendbuf[1]=0x02;
            sendbuf[2]=0x40;
            sendbuf[3]=0x30;
            RS232_Send_Data(sendbuf,8);

        }
    if(buf[1]==0x10)
        {
            if(buf[4]&0x10)
                {
                    EnCH8=1;
                    sendbuf[4]|=0x10;
                }
            else
                {
                    EnCH8=0;
                }
            if(buf[4]&0x01)
                {
                    EnCH7=1;
                }
            else
                {
                    EnCH7=0;
                }
            if(buf[5]&0x10)
                {
                   EnCH6=1;
                }
            else
                {
                    EnCH6=0;
                }
            if(buf[5]&0x01)
                {
                    EnCH5=1;
                }
            else
                {
                    EnCH5=0;
                }
            if(buf[6]&0x10)
                {
                    EnCH4=1;
                }
            else
                {
                    EnCH4=0;
                }
            if(buf[6]&0x01)
                {
                    EnCH3=1;
                }
            else
                {
                    EnCH3=0;
                }
            if(buf[7]&0x10)
                {
                    EnCH2=1;
                }
            else
                {
                    EnCH2=0;
                }
            if(buf[7]&0x01)
                {
                    EnCH1=1;
                }
            else
                {
                    EnCH1=0;
                }
            sendbuf[4]=0x00;
            sendbuf[5]=0x00;
            sendbuf[6]=0x00;
            sendbuf[7]=0x00;
            if(EnCH8)
                {
                    sendbuf[4]|=0x10;
                }
            if(EnCH7)
                {
                    sendbuf[4]|=0x01;
                }
            if(EnCH6)
                {
                    sendbuf[5]|=0x10;
                }
            if(EnCH5)
                {
                    sendbuf[5]|=0x01;
                }
            if(EnCH4)
                {
                    sendbuf[6]|=0x10;
                }
            if(EnCH3)
                {
                    sendbuf[6]|=0x01;
                }
            if(EnCH2)
                {
                    sendbuf[7]|=0x10;
                }
            if(EnCH1)
                {
                    sendbuf[7]|=0x01;
                }

            sendbuf[0]=ip_data.ip;
            sendbuf[1]=0x02;
            sendbuf[2]=0x40;
            sendbuf[3]=0x30;
            RS232_Send_Data(sendbuf,8);
					  ReadAndSave(ISSWITCH,1);			  

        }

}
void RWChannelParameter(u8* buf)
{
    u8 sendbuf[8];
    u32 sec;
    /*读通道延时参数*/
    if(buf[1]==0x02&&buf[2]==0x40)
        {
				//	delay_ms(25);
            switch(buf[3])
                {
                case 0x10:
                    sendbuf[3]=0x10;
                    sec=chan_open_data.chan1;
                    sec*=1000;
                    break;
                case 0x12:
                    sendbuf[3]=0x12;
                    sec=chan_open_data.chan2;
                    sec*=1000;
                    break;
                case 0x14:
                    sendbuf[3]=0x14;
                    sec=chan_open_data.chan3;
                    sec*=1000;
                    break;
                case 0x16:
                    sendbuf[3]=0x16;
                    sec=chan_open_data.chan4;
                    sec*=1000;
                    break;
                case 0x18:
                    sendbuf[3]=0x18;
                    sec=chan_open_data.chan5;
                    sec*=1000;
                    break;
                case 0x1A:
                    sendbuf[3]=0x1A;
                    sec=chan_open_data.chan6;
                    sec*=1000;
                    break;
                case 0x1C:
                    sendbuf[3]=0x1C;
                    sec=chan_open_data.chan7;
                    sec*=1000;
                    break;
                case 0x1E:
                    sendbuf[3]=0x1E;
                    sec=chan_open_data.chan8;
                    sec*=1000;
                    break;
                case 0x20:
                    sendbuf[3]=0x20;
                    sec=chan_close_data.chan1;
                    sec*=1000;
                    break;
                case 0x22:
                    sendbuf[3]=0x22;
                    sec=chan_close_data.chan2;
                    sec*=1000;
                    break;
                case 0x24:
                    sendbuf[3]=0x24;
                    sec=chan_close_data.chan3;
                    sec*=1000;
                    break;
                case 0x26:
                    sendbuf[3]=0x26;
                    sec=chan_close_data.chan4;
                    sec*=1000;
                    break;
                case 0x28:
                    sendbuf[3]=0x28;
                    sec=chan_close_data.chan5;
                    sec*=1000;
                    break;
                case 0x2A:
                    sendbuf[3]=0x2A;
                    sec=chan_close_data.chan6;
                    sec*=1000;
                    break;
                case 0x2C:
                    sendbuf[3]=0x2C;
                    sec=chan_close_data.chan7;
                    sec*=1000;
                    break;
                case 0x2E:
                    sendbuf[3]=0x2E;
                    sec=chan_close_data.chan8;
                    sec*=1000;
                    break;
                case 0x30:
                    EnableDisableChannel(buf);
                    break;
                }

            sendbuf[0]=ip_data.ip;
            sendbuf[1]=0x02;
            sendbuf[2]=0x40;
            sendbuf[4]=(sec&0xFF000000)>>24;
            sendbuf[5]=(sec&0x00FF0000)>16;
            sendbuf[6]=(sec&0x0000FF00)>>8;
            sendbuf[7]=sec&0x000000FF;
            RS232_Send_Data(sendbuf,8);
        }
    if(buf[1]==0x10&&buf[2]==0x40)
        {


            sec=(buf[4]<<24)+(buf[5]<<16)+(buf[6]<<8)+buf[7];

            switch(buf[3])
                {
                case 0x10:
                    sendbuf[3]=0x10;
                    chan_open_data.chan1=sec/1000;

                    break;
                case 0x12:
                    sendbuf[3]=0x12;
                    chan_open_data.chan2=sec/1000;
                    break;
                case 0x14:
                    sendbuf[3]=0x14;
                    chan_open_data.chan3=sec/1000;
                    break;
                case 0x16:
                    sendbuf[3]=0x16;
                    chan_open_data.chan4=sec/1000;
                    break;
                case 0x18:
                    sendbuf[3]=0x18;
                    chan_open_data.chan5=sec/1000;
                    break;
                case 0x1A:
                    sendbuf[3]=0x1A;
                    chan_open_data.chan6=sec/1000;
                    break;
                case 0x1C:
                    sendbuf[3]=0x1C;
                    chan_open_data.chan7=sec/1000;
                    break;
                case 0x1E:
                    sendbuf[3]=0x1E;
                    chan_open_data.chan8=sec/1000;
                    break;
                case 0x20:
                    sendbuf[3]=0x20;
                    chan_close_data.chan1=sec/1000;
                    break;
                case 0x22:
                    sendbuf[3]=0x22;
                    chan_close_data.chan2=sec/1000;
                    break;
                case 0x24:
                    sendbuf[3]=0x24;
                    sec=chan_close_data.chan3=sec/1000;
                    break;
                case 0x26:
                    sendbuf[3]=0x26;
                    chan_close_data.chan4=sec/1000;
                    break;
                case 0x28:
                    sendbuf[3]=0x28;
                    chan_close_data.chan5=sec/1000;
                    break;
                case 0x2A:
                    sendbuf[3]=0x2A;
                    chan_close_data.chan6=sec/1000;
                    break;
                case 0x2C:
                    sendbuf[3]=0x2C;
                    chan_close_data.chan7=sec/1000;
                    break;
                case 0x2E:
                    sendbuf[3]=0x2E;
                    chan_close_data.chan8=sec/1000;
                    break;
                case 0x30:
                    EnableDisableChannel(buf);
                    break;
                }
        }
}

/*恢复出厂函数*/
void Resetparameter(u8 *buf)
{
    u8 sendbuf[8];
    if(buf[1]==0x77&&buf[2]==0x66&&buf[3]==0x86)
        {
            Reset_deflaut();/*恢复出厂设置函数*/
            sendbuf[0]=ip_data.ip;
            sendbuf[1]=0x77;
            sendbuf[2]=0x66;
            sendbuf[3]=0x86;
            sendbuf[4]=0xAA;
            sendbuf[5]=0xAA;
            sendbuf[6]=0xAA;
            sendbuf[7]=0xAA;
            RS232_Send_Data(sendbuf,8);

        }
}
/*读写保护电压电压函数：1 写，0 读*/
void WRProtectionparameter(u8*buf)
{
    /*发送数据缓冲*/
    u8 sendbuf[8];

    /*数据帧1*/
    if(buf[1]==0x10&&buf[2]==0x23&&buf[3]==0x6C)
        {
            uv_ov_data.ov=(buf[4]<<8)+buf[5];
            uv_ov_data.uv=buf[6];
            ReadAndSave(ISUV_OV,1);

        }
    /*数据帧2*/
    else if(buf[1]==0x10&&buf[2]==0x23&&buf[3]==0x6D)
        {
            uv_ov_data.rdv=buf[4];
            uv_ov_data.ov_state=buf[5];
            uv_ov_data.uv_state=buf[6];
            ReadAndSave(ISUV_OV,1);

        }
    else if(buf[1]==0x02&&buf[2]==0x23&&buf[3]==0x6C)
        {

            /*返回数据帧1*/
            sendbuf[0]=ip_data.ip;
            sendbuf[1]=0x02;
            sendbuf[2]=0x23;
            sendbuf[3]=0x6C;
            sendbuf[4]=(uv_ov_data.ov)>>8;
            sendbuf[5]=(uv_ov_data.ov)&0x00FF;
            sendbuf[6]=uv_ov_data.uv;
            sendbuf[7]=0xAA;
            RS232_Send_Data(sendbuf,8);
            /*返回数据帧2*/
            sendbuf[0]=ip_data.ip;
            sendbuf[1]=0x02;
            sendbuf[2]=0x23;
            sendbuf[3]=0x6D;
            sendbuf[4]=uv_ov_data.rdv;
            sendbuf[5]=uv_ov_data.ov_state;
            sendbuf[6]=uv_ov_data.uv_state;
            sendbuf[7]=0xAA;
            RS232_Send_Data(sendbuf,8);
        }
}
/*读写设备IP地址函数：1 写 0 读*/
void WRIPAddress(u8*buf)
{
    u8 sendbuf[8];
    if(buf[1]==0x10&&buf[2]==0x20&&buf[3]==0x17)
        {
            ip_data.ip=buf[7];
            ReadAndSave(ISIP,1);
            sendbuf[0]=ip_data.ip;
            sendbuf[1]=0x10;
            sendbuf[2]=0x20;
            sendbuf[3]=0x17;
            sendbuf[4]=0xAA;
            sendbuf[5]=0x00;
            sendbuf[6]=0x00;
            sendbuf[7]=0xAA;					  
            RS232_Send_Data(sendbuf,8);

        }
    if(buf[0]==0&&buf[1]==0x02&&buf[2]==0x20&&buf[3]==0x17)
        {
            sendbuf[0]=0x00;
            sendbuf[1]=0x02;
            sendbuf[2]=0x20;
            sendbuf[3]=0x17;
            sendbuf[4]=0xAA;
            sendbuf[5]=0x00;
            sendbuf[6]=0x00;
            sendbuf[7]=ip_data.ip;	
            RS232_Send_Data(sendbuf,8);
					//  LCD_ShowNum(100,0,i++,4,24,WHITE,BLACK);
            ClearBuf();
        }		
  		
}

/*读设备通道状态函数*/
void ReadChannelState(u8 *buf)
{
    u8 sendbuf[8];
    sendbuf[0]=ip_data.ip;
    sendbuf[1]=0x02;
    sendbuf[2]=0x20;
    sendbuf[3]=0x16;
    sendbuf[4]=0x00;
    sendbuf[5]=0x00;
    sendbuf[6]=0x00;
    sendbuf[7]=0x00;
    
    if(buf[1]==0x02&&buf[2]==0x20&&buf[3]==0x16)
        {
            if(ReadCH8)
                {
                    sendbuf[4]|=0x10;
                }
            if(ReadCH7)
                {
                    sendbuf[4]|=0x01;
                }
            if(ReadCH6)
                {
                    sendbuf[5]|=0x10;
                }
            if(ReadCH5)
                {
                    sendbuf[5]|=0x01;
                }
            if(ReadCH4)
                {
                    sendbuf[6]|=0x10;
                }
            if(ReadCH3)
                {

                    sendbuf[6]|=0x01;
                }
            if(ReadCH2)
                {
                    sendbuf[7]|=0x10;
                }
            if(ReadCH1)
                {
                    sendbuf[7]|=0x01;
                }
					
            /*发送val的值，每一位代表一个通道的状态*/
            RS232_Send_Data(sendbuf,8);

        }


}
/*读写时钟函数：1 写 0 读*/
void WRDateParameter(u8* buf)
{
    u8 sec;
    _date_time_data DateStructure;

    if(buf[1]==0x13)
        {
            DateStructure.date_year=2000+((buf[2]&0xF0)>>4)*10+(buf[2]&0x0F);
            DateStructure.date_month=((buf[3]&0xF0)>>4)*10+(buf[3]&0x0F);
            DateStructure.date_day=((buf[4]&0xF0)>>4)*10+(buf[4]&0x0F);
            DateStructure.time_hour=((buf[5]&0xF0)>>4)*10+(buf[5]&0x0F);
            DateStructure.time_min=((buf[6]&0xF0)>>4)*10+(buf[6]&0x0F);
            sec=((buf[7]&0xF0)>>4)*10+(buf[7]&0x0F);
            RTC_Set(DateStructure.date_year,DateStructure.date_month,
                    DateStructure.date_day,DateStructure.time_hour,DateStructure.time_min,sec);


        }

}
/*读写定时数据函数*/
u8 CHANWeek(_timer_dev* timer_dev)
{
    u8 temp,week;
    week=timer_dev->week;
    temp=(week>>1)+((week&0x01)<<6);
    return temp;
}
void CHANSTATEOFTIMER(_timer_dev* timer_dev,u8* data)
{

    u8 chan;
    chan=timer_dev->chan1;
    if(chan)
        {
            *data|=0x01;
        }

    chan=timer_dev->chan2;
    if(chan)
        {
            *data|=0x02;
        }
    chan=timer_dev->chan3;
    if(chan)
        {
            *data|=0x04;
        }
    chan=timer_dev->chan4;
    if(chan)
        {
            *data|=0x08;
        }
    chan=timer_dev->chan5;
    if(chan)
        {
            *data|=0x10;
        }
    chan=timer_dev->chan6;
    if(chan)
        {
            *data|=0x20;
        }
    chan=timer_dev->chan7;
    if(chan)
        {
            *data|=0x40;
        }
    chan=timer_dev->chan8;
    if(chan)
        {
            *data|=0x80;
        }

}
void WRTimerParameter(u8 *buf)
{
    u8 sendbuf[8],data=0;
    /*读定时状态，通道状态，模式，年份*/
    if(buf[1]==0x05&&buf[3]==0x00&&buf[4]==0x00)
        {
            switch(buf[2])
                {
                case 0x00:
                    sendbuf[0]=ip_data.ip;
                    sendbuf[1]=0x05;
                    sendbuf[2]=0x00;
                    sendbuf[3]=timer_dev_1.timer_state;//02 关机 01 开机 00 禁用
                    sendbuf[4]=timer_dev_1.mode;//00 单次 01循环
                    CHANSTATEOFTIMER(&timer_dev_1,&data);
                    sendbuf[5]=data;
                    sendbuf[6]=CHANWeek(&timer_dev_1);
                    sendbuf[7]=timer_dev_1.date_year%1000;
                    RS232_Send_Data(sendbuf,8);
                    break;
                case 0x01:
                    sendbuf[0]=ip_data.ip;
                    sendbuf[1]=0x05;
                    sendbuf[2]=0x01;
                    sendbuf[3]=timer_dev_2.timer_state;//02 关机 01 开机 00 禁用
                    sendbuf[4]=timer_dev_2.mode;//00 单次 01循环
                    CHANSTATEOFTIMER(&timer_dev_2,&data);
                    sendbuf[5]=data;
                    sendbuf[6]=CHANWeek(&timer_dev_2);
                    sendbuf[7]=timer_dev_2.date_year%1000;
                    RS232_Send_Data(sendbuf,8);
                    break;
                case 0x02:
                    sendbuf[0]=ip_data.ip;
                    sendbuf[1]=0x05;
                    sendbuf[2]=0x02;
                    sendbuf[3]=timer_dev_3.timer_state;//02 关机 01 开机 00 禁用
                    sendbuf[4]=timer_dev_3.mode;//00 单次 01循环
                    CHANSTATEOFTIMER(&timer_dev_3,&data);
                    sendbuf[5]=data;
                    sendbuf[6]=CHANWeek(&timer_dev_3);

                    sendbuf[7]=timer_dev_3.date_year%1000;
                    RS232_Send_Data(sendbuf,8);
                    break;
                case 0x03:
                    sendbuf[0]=ip_data.ip;
                    sendbuf[1]=0x05;
                    sendbuf[2]=0x03;
                    sendbuf[3]=timer_dev_4.timer_state;//02 关机 01 开机 00 禁用
                    sendbuf[4]=timer_dev_4.mode;//00 单次 01循环
                    CHANSTATEOFTIMER(&timer_dev_4,&data);
                    sendbuf[5]=data;
                    sendbuf[6]=CHANWeek(&timer_dev_4);
                    sendbuf[7]=timer_dev_4.date_year%1000;
                    RS232_Send_Data(sendbuf,8);
                    break;
                case 0x04:
                    sendbuf[0]=ip_data.ip;
                    sendbuf[1]=0x05;
                    sendbuf[2]=0x04;
                    sendbuf[3]=timer_dev_5.timer_state;//02 关机 01 开机 00 禁用
                    sendbuf[4]=timer_dev_5.mode;//00 单次 01循环
                    CHANSTATEOFTIMER(&timer_dev_5,&data);
                    sendbuf[5]=data;
                    sendbuf[6]=CHANWeek(&timer_dev_5);
                    sendbuf[7]=timer_dev_5.date_year%1000;
                    RS232_Send_Data(sendbuf,8);
                    break;
                case 0x05:
                    sendbuf[0]=ip_data.ip;
                    sendbuf[1]=0x05;
                    sendbuf[2]=0x05;
                    sendbuf[3]=timer_dev_6.timer_state;//02 关机 01 开机 00 禁用
                    sendbuf[4]=timer_dev_6.mode;//00 单次 01循环
                    CHANSTATEOFTIMER(&timer_dev_6,&data);
                    sendbuf[5]=data;
                    sendbuf[6]=CHANWeek(&timer_dev_6);
                    sendbuf[7]=timer_dev_6.date_year%1000;
                    RS232_Send_Data(sendbuf,8);
                    break;
                case 0x06:
                    sendbuf[0]=ip_data.ip;
                    sendbuf[1]=0x05;
                    sendbuf[2]=0x06;
                    sendbuf[3]=timer_dev_7.timer_state;//02 关机 01 开机 00 禁用
                    sendbuf[4]=timer_dev_7.mode;//00 单次 01循环
                    CHANSTATEOFTIMER(&timer_dev_7,&data);
                    sendbuf[5]=data;
                    sendbuf[6]=CHANWeek(&timer_dev_7);
                    sendbuf[7]=timer_dev_7.date_year%1000;
                    RS232_Send_Data(sendbuf,8);
                    break;
                case 0x07:
                    sendbuf[0]=ip_data.ip;
                    sendbuf[1]=0x05;
                    sendbuf[2]=0x07;
                    sendbuf[3]=timer_dev_8.timer_state;//02 关机 01 开机 00 禁用
                    sendbuf[4]=timer_dev_8.mode;//00 单次 01循环
                    CHANSTATEOFTIMER(&timer_dev_8,&data);
                    sendbuf[5]=data;
                    sendbuf[6]=CHANWeek(&timer_dev_8);
                    sendbuf[7]=timer_dev_8.date_year%1000;
                    RS232_Send_Data(sendbuf,8);
                    break;
                case 0x08:
                    sendbuf[0]=ip_data.ip;
                    sendbuf[1]=0x05;
                    sendbuf[2]=0x08;
                    sendbuf[3]=timer_dev_9.timer_state;//02 关机 01 开机 00 禁用
                    sendbuf[4]=timer_dev_9.mode;//00 单次 01循环
                    CHANSTATEOFTIMER(&timer_dev_9,&data);
                    sendbuf[5]=data;
                    sendbuf[6]=CHANWeek(&timer_dev_9);
                    sendbuf[7]=timer_dev_9.date_year%1000;
                    RS232_Send_Data(sendbuf,8);
                    break;
                case 0x09:
                    sendbuf[0]=ip_data.ip;
                    sendbuf[1]=0x05;
                    sendbuf[2]=0x09;
                    sendbuf[3]=timer_dev_10.timer_state;//02 关机 01 开机 00 禁用
                    sendbuf[4]=timer_dev_10.mode;//00 单次 01循环
                    CHANSTATEOFTIMER(&timer_dev_10,&data);
                    sendbuf[5]=data;
                    sendbuf[6]=CHANWeek(&timer_dev_10);
                    sendbuf[7]=timer_dev_10.date_year%1000;
                    RS232_Send_Data(sendbuf,8);
                    break;
                }


        }
    if(buf[1]==0x06&&buf[3]==0x00&&buf[4]==0x00)
        {
            switch(buf[2])
                {
                case 0x00:
                    sendbuf[0]=ip_data.ip;
                    sendbuf[1]=0x06;
                    sendbuf[2]=0x00;
                    sendbuf[3]=timer_dev_1.date_month;
                    sendbuf[4]=timer_dev_1.date_day;
                    sendbuf[5]=timer_dev_1.time_hour;
                    sendbuf[6]=timer_dev_1.time_min;
                    sendbuf[7]=timer_dev_1.time_sec;
                    RS232_Send_Data(sendbuf,8);
                    break;
                case 0x01:
                    sendbuf[0]=ip_data.ip;
                    sendbuf[1]=0x06;
                    sendbuf[2]=0x01;
                    sendbuf[3]=timer_dev_2.date_month;
                    sendbuf[4]=timer_dev_2.date_day;
                    sendbuf[5]=timer_dev_2.time_hour;
                    sendbuf[6]=timer_dev_2.time_min;
                    sendbuf[7]=timer_dev_2.time_sec;
                    RS232_Send_Data(sendbuf,8);
                    break;
                case 0x02:
                    sendbuf[0]=ip_data.ip;
                    sendbuf[1]=0x06;
                    sendbuf[2]=0x02;
                    sendbuf[3]=timer_dev_3.date_month;
                    sendbuf[4]=timer_dev_3.date_day;
                    sendbuf[5]=timer_dev_3.time_hour;
                    sendbuf[6]=timer_dev_3.time_min;
                    sendbuf[7]=timer_dev_3.time_sec;
                    RS232_Send_Data(sendbuf,8);
                    break;
                case 0x03:
                    sendbuf[0]=ip_data.ip;
                    sendbuf[1]=0x06;
                    sendbuf[2]=0x03;
                    sendbuf[3]=timer_dev_4.date_month;
                    sendbuf[4]=timer_dev_4.date_day;
                    sendbuf[5]=timer_dev_4.time_hour;
                    sendbuf[6]=timer_dev_4.time_min;
                    sendbuf[7]=timer_dev_4.time_sec;
                    RS232_Send_Data(sendbuf,8);
                    break;
                case 0x04:
                    sendbuf[0]=ip_data.ip;
                    sendbuf[1]=0x06;
                    sendbuf[2]=0x04;
                    sendbuf[3]=timer_dev_5.date_month;
                    sendbuf[4]=timer_dev_5.date_day;
                    sendbuf[5]=timer_dev_5.time_hour;
                    sendbuf[6]=timer_dev_5.time_min;
                    sendbuf[7]=timer_dev_5.time_sec;
                    RS232_Send_Data(sendbuf,8);
                    break;
                case 0x05:
                    sendbuf[0]=ip_data.ip;
                    sendbuf[1]=0x06;
                    sendbuf[2]=0x05;
                    sendbuf[3]=timer_dev_6.date_month;
                    sendbuf[4]=timer_dev_6.date_day;
                    sendbuf[5]=timer_dev_6.time_hour;
                    sendbuf[6]=timer_dev_6.time_min;
                    sendbuf[7]=timer_dev_6.time_sec;
                    RS232_Send_Data(sendbuf,8);
                    break;
                case 0x06:
                    sendbuf[0]=ip_data.ip;
                    sendbuf[1]=0x06;
                    sendbuf[2]=0x06;
                    sendbuf[3]=timer_dev_7.date_month;
                    sendbuf[4]=timer_dev_7.date_day;
                    sendbuf[5]=timer_dev_7.time_hour;
                    sendbuf[6]=timer_dev_7.time_min;
                    sendbuf[7]=timer_dev_7.time_sec;
                    RS232_Send_Data(sendbuf,8);
                    break;
                case 0x07:
                    sendbuf[0]=ip_data.ip;
                    sendbuf[1]=0x06;
                    sendbuf[2]=0x07;
                    sendbuf[3]=timer_dev_8.date_month;
                    sendbuf[4]=timer_dev_8.date_day;
                    sendbuf[5]=timer_dev_8.time_hour;
                    sendbuf[6]=timer_dev_8.time_min;
                    sendbuf[7]=timer_dev_8.time_sec;
                    RS232_Send_Data(sendbuf,8);
                    break;
                case 0x08:
                    sendbuf[0]=ip_data.ip;
                    sendbuf[1]=0x06;
                    sendbuf[2]=0x08;
                    sendbuf[3]=timer_dev_9.date_month;
                    sendbuf[4]=timer_dev_9.date_day;
                    sendbuf[5]=timer_dev_9.time_hour;
                    sendbuf[6]=timer_dev_9.time_min;
                    sendbuf[7]=timer_dev_9.time_sec;
                    RS232_Send_Data(sendbuf,8);
                    break;
                case 0x09:
                    sendbuf[0]=ip_data.ip;
                    sendbuf[1]=0x06;
                    sendbuf[2]=0x09;
                    sendbuf[3]=timer_dev_10.date_month;
                    sendbuf[4]=timer_dev_10.date_day;
                    sendbuf[5]=timer_dev_10.time_hour;
                    sendbuf[6]=timer_dev_10.time_min;
                    sendbuf[7]=timer_dev_10.time_sec;
                    RS232_Send_Data(sendbuf,8);
                    break;
                }


        }
    /*写月日时分秒*/
    if(buf[1]==0x11)
        {
            switch(buf[2])
                {
                case 0x00:
                    timer_dev_1.timer_state=buf[3];
                    timer_dev_1.mode=buf[4];
                    timer_dev_1.chan1=buf[5]&0x01;
                    timer_dev_1.chan2=(buf[5]>>1)&0x01;
                    timer_dev_1.chan3=(buf[5]>>2)&0x01;
                    timer_dev_1.chan4=(buf[5]>>3)&0x01;
                    timer_dev_1.chan5=(buf[5]>>4)&0x01;
                    timer_dev_1.chan6=(buf[5]>>5)&0x01;
                    timer_dev_1.chan7=(buf[5]>>6)&0x01;
                    timer_dev_1.chan8=(buf[5]>>7)&0x01;
                    timer_dev_1.week=((buf[6]&0x3F)<<1)+((buf[6]&0x40)>>6);
                    timer_dev_1.date_year=calendar.w_year-(calendar.w_year%1000)+buf[7];
                    break;
                case 0x01:
                    timer_dev_2.timer_state=buf[3];
                    timer_dev_2.mode=buf[4];
                    timer_dev_2.chan1=buf[5]&0x01;
                    timer_dev_2.chan2=(buf[5]>>1)&0x01;
                    timer_dev_2.chan3=(buf[5]>>2)&0x01;
                    timer_dev_2.chan4=(buf[5]>>3)&0x01;
                    timer_dev_2.chan5=(buf[5]>>4)&0x01;
                    timer_dev_2.chan6=(buf[5]>>5)&0x01;
                    timer_dev_2.chan7=(buf[5]>>6)&0x01;
                    timer_dev_2.chan8=(buf[5]>>7)&0x01;
                    timer_dev_2.week=((buf[6]&0x3F)<<1)+((buf[6]&0x40)>>6);
                    timer_dev_2.date_year=calendar.w_year-(calendar.w_year%1000)+buf[7];
                    break;
                case 0x02:
                    timer_dev_3.timer_state=buf[3];
                    timer_dev_3.mode=buf[4];
                    timer_dev_3.chan1=buf[5]&0x01;
                    timer_dev_3.chan2=(buf[5]>>1)&0x01;
                    timer_dev_3.chan3=(buf[5]>>2)&0x01;
                    timer_dev_3.chan4=(buf[5]>>3)&0x01;
                    timer_dev_3.chan5=(buf[5]>>4)&0x01;
                    timer_dev_3.chan6=(buf[5]>>5)&0x01;
                    timer_dev_3.chan7=(buf[5]>>6)&0x01;
                    timer_dev_3.chan8=(buf[5]>>7)&0x01;
                    timer_dev_3.week=((buf[6]&0x3F)<<1)+((buf[6]&0x40)>>6);
                    timer_dev_3.date_year=calendar.w_year-(calendar.w_year%1000)+buf[7];

                    break;
                case 0x03:
                    timer_dev_4.timer_state=buf[3];
                    timer_dev_4.mode=buf[4];
                    timer_dev_4.chan1=buf[5]&0x01;
                    timer_dev_4.chan2=(buf[5]>>1)&0x01;
                    timer_dev_4.chan3=(buf[5]>>2)&0x01;
                    timer_dev_4.chan4=(buf[5]>>3)&0x01;
                    timer_dev_4.chan5=(buf[5]>>4)&0x01;
                    timer_dev_4.chan6=(buf[5]>>5)&0x01;
                    timer_dev_4.chan7=(buf[5]>>6)&0x01;
                    timer_dev_4.chan8=(buf[5]>>7)&0x01;
                    timer_dev_4.week=((buf[6]&0x3F)<<1)+((buf[6]&0x40)>>6);
                    timer_dev_4.date_year=calendar.w_year-(calendar.w_year%1000)+buf[7];
                    break;

                case 0x04:
                    timer_dev_5.timer_state=buf[3];
                    timer_dev_5.mode=buf[4];
                    timer_dev_5.chan1=buf[5]&0x01;
                    timer_dev_5.chan2=(buf[5]>>1)&0x01;
                    timer_dev_5.chan3=(buf[5]>>2)&0x01;
                    timer_dev_5.chan4=(buf[5]>>3)&0x01;
                    timer_dev_5.chan5=(buf[5]>>4)&0x01;
                    timer_dev_5.chan6=(buf[5]>>5)&0x01;
                    timer_dev_5.chan7=(buf[5]>>6)&0x01;
                    timer_dev_5.chan8=(buf[5]>>7)&0x01;
                    timer_dev_5.week=((buf[6]&0x3F)<<1)+((buf[6]&0x40)>>6);
                    timer_dev_5.date_year=calendar.w_year-(calendar.w_year%1000)+buf[7];

                    break;
                case 0x05:
                    timer_dev_6.timer_state=buf[3];
                    timer_dev_6.mode=buf[4];
                    timer_dev_6.chan1=buf[5]&0x01;
                    timer_dev_6.chan2=(buf[5]>>1)&0x01;
                    timer_dev_6.chan3=(buf[5]>>2)&0x01;
                    timer_dev_6.chan4=(buf[5]>>3)&0x01;
                    timer_dev_6.chan5=(buf[5]>>4)&0x01;
                    timer_dev_6.chan6=(buf[5]>>5)&0x01;
                    timer_dev_6.chan7=(buf[5]>>6)&0x01;
                    timer_dev_6.chan8=(buf[5]>>7)&0x01;
                    timer_dev_6.week=((buf[6]&0x3F)<<1)+((buf[6]&0x40)>>6);
                    timer_dev_6.date_year=calendar.w_year-(calendar.w_year%1000)+buf[7];

                    break;
                case 0x06:
                    timer_dev_7.timer_state=buf[3];
                    timer_dev_7.mode=buf[4];
                    timer_dev_7.chan1=buf[5]&0x01;
                    timer_dev_7.chan2=(buf[5]>>1)&0x01;
                    timer_dev_7.chan3=(buf[5]>>2)&0x01;
                    timer_dev_7.chan4=(buf[5]>>3)&0x01;
                    timer_dev_7.chan5=(buf[5]>>4)&0x01;
                    timer_dev_7.chan6=(buf[5]>>5)&0x01;
                    timer_dev_7.chan7=(buf[5]>>6)&0x01;
                    timer_dev_7.chan8=(buf[5]>>7)&0x01;
                    timer_dev_7.week=((buf[6]&0x3F)<<1)+((buf[6]&0x40)>>6);
                    timer_dev_7.date_year=calendar.w_year-(calendar.w_year%1000)+buf[7];

                    break;
                case 0x07:
                    timer_dev_8.timer_state=buf[3];
                    timer_dev_8.mode=buf[4];
                    timer_dev_8.chan1=buf[5]&0x01;
                    timer_dev_8.chan2=(buf[5]>>1)&0x01;
                    timer_dev_8.chan3=(buf[5]>>2)&0x01;
                    timer_dev_8.chan4=(buf[5]>>3)&0x01;
                    timer_dev_8.chan5=(buf[5]>>4)&0x01;
                    timer_dev_8.chan6=(buf[5]>>5)&0x01;
                    timer_dev_8.chan7=(buf[5]>>6)&0x01;
                    timer_dev_8.chan8=(buf[5]>>7)&0x01;
                    timer_dev_8.week=((buf[6]&0x3F)<<1)+((buf[6]&0x40)>>6);
                    timer_dev_8.date_year=calendar.w_year-(calendar.w_year%1000)+buf[7];
                    break;
                case 0x08:
                    timer_dev_9.timer_state=buf[3];
                    timer_dev_9.mode=buf[4];
                    timer_dev_9.chan1=buf[5]&0x01;
                    timer_dev_9.chan2=(buf[5]>>1)&0x01;
                    timer_dev_9.chan3=(buf[5]>>2)&0x01;
                    timer_dev_9.chan4=(buf[5]>>3)&0x01;
                    timer_dev_9.chan5=(buf[5]>>4)&0x01;
                    timer_dev_9.chan6=(buf[5]>>5)&0x01;
                    timer_dev_9.chan7=(buf[5]>>6)&0x01;
                    timer_dev_9.chan8=(buf[5]>>7)&0x01;
                    timer_dev_9.week=((buf[6]&0x3F)<<1)+((buf[6]&0x40)>>6);
                    timer_dev_9.date_year=calendar.w_year-(calendar.w_year%1000)+buf[7];
                    break;
                case 0x09:
                    timer_dev_10.timer_state=buf[3];
                    timer_dev_10.mode=buf[4];
                    timer_dev_10.chan1=buf[5]&0x01;
                    timer_dev_10.chan2=(buf[5]>>1)&0x01;
                    timer_dev_10.chan3=(buf[5]>>2)&0x01;
                    timer_dev_10.chan4=(buf[5]>>3)&0x01;
                    timer_dev_10.chan5=(buf[5]>>4)&0x01;
                    timer_dev_10.chan6=(buf[5]>>5)&0x01;
                    timer_dev_10.chan7=(buf[5]>>6)&0x01;
                    timer_dev_10.chan8=(buf[5]>>7)&0x01;
                    timer_dev_10.week=((buf[6]&0x3F)<<1)+((buf[6]&0x40)>>6);
                    timer_dev_10.date_year=calendar.w_year-(calendar.w_year%1000)+buf[7];
                    break;
                }
            ReadAndSave(ISTIMER,1);
        }
    if(buf[1]==0x12)
        {
            switch(buf[2])
                {
                case 0x00:
                    timer_dev_1.date_month=(buf[3]>>4)*10+buf[3]&0x0F;
                    timer_dev_1.date_day=buf[4];
                    timer_dev_1.time_hour=buf[5];
                    timer_dev_1.time_min=buf[6];
                    timer_dev_1.time_sec=buf[7];
                    break;
                case 0x01:
                    timer_dev_2.date_month=(buf[3]>>4)*10+buf[3]&0x0F;
                    timer_dev_2.date_day=buf[4];
                    timer_dev_2.time_hour=buf[5];
                    timer_dev_2.time_min=buf[6];
                    timer_dev_2.time_sec=buf[7];
                    break;
                case 0x02:
                    timer_dev_3.date_month=(buf[3]>>4)*10+buf[3]&0x0F;
                    timer_dev_3.date_day=buf[4];
                    timer_dev_3.time_hour=buf[5];
                    timer_dev_3.time_min=buf[6];
                    timer_dev_3.time_sec=buf[7];

                    break;
                case 0x03:
                    timer_dev_4.date_month=(buf[3]>>4)*10+buf[3]&0x0F;
                    timer_dev_4.date_day=buf[4];
                    timer_dev_4.time_hour=buf[5];
                    timer_dev_4.time_min=buf[6];
                    timer_dev_4.time_sec=buf[7];
                    break;

                case 0x04:
                    timer_dev_5.date_month=(buf[3]>>4)*10+buf[3]&0x0F;
                    timer_dev_5.date_day=buf[4];
                    timer_dev_5.time_hour=buf[5];
                    timer_dev_5.time_min=buf[6];
                    timer_dev_5.time_sec=buf[7];

                    break;
                case 0x05:
                    timer_dev_6.date_month=(buf[3]>>4)*10+buf[3]&0x0F;
                    timer_dev_6.date_day=buf[4];
                    timer_dev_6.time_hour=buf[5];
                    timer_dev_6.time_min=buf[6];
                    timer_dev_6.time_sec=buf[7];

                    break;
                case 0x06:
                    timer_dev_7.date_month=(buf[3]>>4)*10+buf[3]&0x0F;
                    timer_dev_7.date_day=buf[4];
                    timer_dev_7.time_hour=buf[5];
                    timer_dev_7.time_min=buf[6];
                    timer_dev_7.time_sec=buf[7];

                    break;
                case 0x07:
                    timer_dev_8.date_month=(buf[3]>>4)*10+buf[3]&0x0F;
                    timer_dev_8.date_day=buf[4];
                    timer_dev_8.time_hour=buf[5];
                    timer_dev_8.time_min=buf[6];
                    timer_dev_8.time_sec=buf[7];

                    break;
                case 0x08:
                    timer_dev_9.date_month=(buf[3]>>4)*10+buf[3]&0x0F;
                    timer_dev_9.date_day=buf[4];
                    timer_dev_9.time_hour=buf[5];
                    timer_dev_9.time_min=buf[6];
                    timer_dev_9.time_sec=buf[7];

                    break;
                case 0x09:
                    timer_dev_10.date_month=(buf[3]>>4)*10+buf[3]&0x0F;
                    timer_dev_10.date_day=buf[4];
                    timer_dev_10.time_hour=buf[5];
                    timer_dev_10.time_min=buf[6];
                    timer_dev_10.time_sec=buf[7];

                    break;
                }
            ReadAndSave(ISTIMER,1);
        }

}
