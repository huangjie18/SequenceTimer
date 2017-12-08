#ifndef __GUI_H
#define __GUI_H

#include "sys.h"

__packed typedef struct
{
    void(*draw_point)(u16,u16,u16);			//画点函数
    void(*fill)(u16,u16,u16,u16,u16);		//单色填充函数
    void(*colorfill)(u16,u16,u16,u16,u16*);	//彩色填充函数
    u16 lcdwidth;							//LCD的宽度
    u16 lcdheight;							//LCD的高度
} _gui_phy;




void gui_init(void);
void gui_draw_bigpoint(u16 x0,u16 y0,u16 color);						//画大点
void gui_draw_line(u16 x0,u16 y0,u16 x1,u16 y1,u16 color);				//画任意线
void gui_draw_bline(u16 x1, u16 y1, u16 x2, u16 y2,u8 size,u16 color);	//画一条粗线
void gui_draw_bline1(u16 x0,u16 y0,u16 x1,u16 y1,u8 size,u16 color);	//画一条粗线,方法1
void gui_draw_rectangle(u16 x0,u16 y0,u16 width,u16 height,u16 color);	//画矩形
void gui_draw_arcrectangle(u16 x,u16 y,u16 width,u16 height,u8 r,u8 mode,u16 upcolor,u16 downcolor);//画圆角矩形
void gui_draw_vline(u16 x0,u16 y0,u16 len,u16 color);								//画垂直线
void gui_draw_hline(u16 x0,u16 y0,u16 len,u16 color);								//画水平线
void gui_fill_colorblock(u16 x0,u16 y0,u16 width,u16 height,u16* ctbl,u8 mode);		//填充颜色块
void gui_fill_rectangle(u16 x0,u16 y0,u16 width,u16 height,u16 color);				//填充区域
void gui_fill_circle(u16 x0,u16 y0,u16 r,u16 color);
void gui_draw_arc(u16 sx,u16 sy,u16 ex,u16 ey,u16 rx,u16 ry,u16 r,u16 color,u8 mode);
void LCD_draw_arcrectangle(u16 x,u16 y,u16 width,u16 height,u8 r,u16 FILL_color,u16 LINEcolor);//画带边框的圆角矩形
void LCD_draw_rectangle(u16 x0,u16 y0,u16 x1,u16 y1,u8 size,u16 color);//画粗边框的矩形
void b_gui_draw_arcrectangle(u16 x,u16 y,u16 width,u16 height,u8 r,u8 mode,u16 FILL_color,u16 LINEcolor);//画粗边框


#endif

