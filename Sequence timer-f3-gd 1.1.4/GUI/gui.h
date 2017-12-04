#ifndef __GUI_H
#define __GUI_H

#include "sys.h"

__packed typedef struct
{
    void(*draw_point)(u16,u16,u16);			//���㺯��
    void(*fill)(u16,u16,u16,u16,u16);		//��ɫ��亯��
    void(*colorfill)(u16,u16,u16,u16,u16*);	//��ɫ��亯��
    u16 lcdwidth;							//LCD�Ŀ��
    u16 lcdheight;							//LCD�ĸ߶�
} _gui_phy;




void gui_init(void);
void gui_draw_bigpoint(u16 x0,u16 y0,u16 color);						//�����
void gui_draw_line(u16 x0,u16 y0,u16 x1,u16 y1,u16 color);				//��������
void gui_draw_bline(u16 x1, u16 y1, u16 x2, u16 y2,u8 size,u16 color);	//��һ������
void gui_draw_bline1(u16 x0,u16 y0,u16 x1,u16 y1,u8 size,u16 color);	//��һ������,����1
void gui_draw_rectangle(u16 x0,u16 y0,u16 width,u16 height,u16 color);	//������
void gui_draw_arcrectangle(u16 x,u16 y,u16 width,u16 height,u8 r,u8 mode,u16 upcolor,u16 downcolor);//��Բ�Ǿ���
void gui_draw_vline(u16 x0,u16 y0,u16 len,u16 color);								//����ֱ��
void gui_draw_hline(u16 x0,u16 y0,u16 len,u16 color);								//��ˮƽ��
void gui_fill_colorblock(u16 x0,u16 y0,u16 width,u16 height,u16* ctbl,u8 mode);		//�����ɫ��
void gui_fill_rectangle(u16 x0,u16 y0,u16 width,u16 height,u16 color);				//�������
void gui_fill_circle(u16 x0,u16 y0,u16 r,u16 color);
void gui_draw_arc(u16 sx,u16 sy,u16 ex,u16 ey,u16 rx,u16 ry,u16 r,u16 color,u8 mode);
void LCD_draw_arcrectangle(u16 x,u16 y,u16 width,u16 height,u8 r,u16 FILL_color,u16 LINEcolor);//�����߿��Բ�Ǿ���
void LCD_draw_rectangle(u16 x0,u16 y0,u16 x1,u16 y1,u8 size,u16 color);//���ֱ߿�ľ���
void b_gui_draw_arcrectangle(u16 x,u16 y,u16 width,u16 height,u8 r,u8 mode,u16 FILL_color,u16 LINEcolor);//���ֱ߿�


#endif

