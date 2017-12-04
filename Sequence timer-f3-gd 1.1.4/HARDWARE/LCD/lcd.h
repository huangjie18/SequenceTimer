#ifndef __LCD_H
#define __LCD_H
#include "sys.h"


 
//lcd�ṹ��
typedef struct  
{										    
	u16 width;			//LCD ���
	u16 height;			//LCD �߶�
	u16	wramcmd;		//��ʼдgramָ��
	u16 setxcmd;		//����x����ָ��
	u16 setycmd;		//����y����ָ�� 
}_lcd_dev; 	  

//LCD��ַ�ṹ��
typedef struct
{
	vu16 LCD_REG;
	vu16 LCD_RAM;
} LCD_TypeDef;
//ʹ��NOR/SRAM�� Bank1.sector4,��ַλHADDR[27,26]=11 A16��Ϊ�������������� 
//ע������ʱSTM32�ڲ�������һλ����! 111 1110=0X7E			    
#define LCD_BASE        ((u32)(0x60000000 | 0x0001FFFE))
#define LCD             ((LCD_TypeDef *) LCD_BASE)


#define WHITE         	 0xFFFF
#define BLACK         	 0x0000	  
#define BLUE         	    0x01CF   
//#define BLUE         	   0x01CF  
#define BRED             0XF81F
#define GRED 			 0XFFE0
#define GBLUE			 0X07FF
#define RED           	 0xF800
#define MAGENTA       	 0xF81F//�ۺ�ɫ
#define GREEN         	 0x07E0
#define CYAN          	 0x7FFF
#define YELLOW        	 0xFFE0
#define BROWN 			 0XBC40 //��ɫ
#define BRRED 			 0XFC07 //�غ�ɫ
#define GRAY  			 0X8430 //��ɫ
#define Q_GRAY       0XEF5B//ǳ��ɫ


//��ͷ�������εķ���
#define LEFT 3
#define RIGHT 4


void LCD_Init(void);
void LCD_IO_FSMC_Init(void);
void LCD_WR_REG(vu16 regval);
void LCD_WR_DATA(vu16 data);
u16 LCD_RD_DATA(void);
void LCD_WriteReg(u16 LCD_Reg,u16 LCD_RegValue);
u16 LCD_ReadReg(u16 LCD_Reg);
void LCD_WriteRAM_Prepare(void);
void LCD_WriteRAM(u16 RGB_Code);
u16 LCD_BGR2RGB(u16 c);
void Reset(void);


void LCD_SetCursor(u16 Xpos, u16 Ypos); //�������꺯��
void LCD_Fill(u16 sx,u16 sy,u16 ex,u16 ey,u16 color); //��亯��
void LCD_Color_Fill(u16 sx,u16 sy,u16 ex,u16 ey,u16 *color);//��亯��
void LCD_DrawPoint(u16 x,u16 y);//���㺯��
void LCD_DrawLine(u16 x1, u16 y1, u16 x2, u16 y2,u16 color);//���ߺ���
void LCD_Set_Window(u16 sx,u16 sy,u16 width,u16 height);//���ô��ں���
void LCD_Clear(u16 color)	;//��������
void LCD_DrawRectangle(u16 x1, u16 y1, u16 x2, u16 y2,u16 color);//�����κ���
void LCD_Draw_Circle_(u16 x0,u16 y0,u8 r);
void LCD_Draw_Circle(u16 x0,u16 y0,u8 r,u16 color); //��������ɫȦ
void LCD_Fast_DrawPoint(u16 x,u16 y,u16 color); //���ٻ�������ɫ�㺯��
void LCD_ShowChar(u16 x,u16 y,u8 num,u8 mode,u16 color);  //��ʾ�ַ������ģ����ֺ���
void LCD_DrawLtrigo(u16 x1, u16 y1, u16 x2, u16 y2,u8 dir,u16 color);//�����Ǻ���
void LCD_Draw_arrow_key(u16 x1, u16 y1, u16 x2, u16 y2,u8 dir,u16 color);//����ͷ����
void LCD_Show_3030_String(u16 x,u16 y,u8 *p,u16 color);//��ʾ30*30�ַ���
void LCD_Show_6464_String(u16 x,u16 y,u8 *p,u16 color);//��ʾ64*64�ַ���
void LCD_Show_2424_String(u16 x,u16 y,u8 *p,u16 color);//��ʾ24*24�ַ���
void LCD_Show_4848_String(u16 x,u16 y,u8 *p,u16 color);//��ʾ48*48�ַ���
void LCD_Show_picture(u16 x,u16 y,u16 color,u8 type);//��ʾͼƬ����
u32 LCD_Pow(u8 m,u8 n);
void LCD_ShowNum(u16 x,u16 y,u32 num,u8 len,u8 size,u16 p_color,u16 b_color);
void LCD_Show200(u16 x,u16 y,u32 num,u8 len,u8 size,u16 p_color,u16 b_color);
void LCD_ShowChar_(u16 x,u16 y,u8 num,u8 size,u8 mode,u16 p_color,u16 b_color);
#endif



