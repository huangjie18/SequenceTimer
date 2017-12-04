#include "data.h"
#include "rtc.h"

_ip_data ip_data= {1};

_uv_ov_data uv_ov_data=
{
    10,
    75,
    ON,
    165,
    OFF,
};

_date_time_data date_time_data;

_chan_open_data  chan_open_data=
{
    1,
    2,
    3,
    4,
    5,
    6,
    7,
    8,
};
_chan_close_data  chan_close_data=
{
    8,
    7,
    6,
    5,
    4,
    3,
    2,
    1,
};

_chan_data chan_data;

//»Ö¸´Ä¬ÈÏÊı¾İ
void Reset_deflaut()
{
    ip_data.ip=1;

    uv_ov_data.rdv=10;
    uv_ov_data.uv=75;
    uv_ov_data.uv_state=OFF;
    uv_ov_data.ov=165;
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
    chan_close_data.chan2=6;
    chan_close_data.chan3=6;
    chan_close_data.chan4=5;
    chan_close_data.chan5=4;
    chan_close_data.chan6=3;
    chan_close_data.chan7=2;
    chan_close_data.chan8=1;

}

pwd_data user_pwd= {1,2,3,4,5,6};
pwd_data settings_pwd={1,2,3,4,5,6};

_timer_dev timer_dev_1={0,1,2017,10,1,12,0,20};
_timer_dev timer_dev_2={0,1,2017,10,1,12,0,15};
_timer_dev timer_dev_3={0,1,2017,10,1,12,0,10};
_timer_dev chan_dev;

