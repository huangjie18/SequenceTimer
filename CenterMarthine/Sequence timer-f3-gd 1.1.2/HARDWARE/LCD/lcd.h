#ifndef __LCD_H
#define __LCD_H
#include "sys.h"


 
//lcd结构体
typedef struct  
{										    
	u16 width;			//LCD 宽度
	u16 height;			//LCD 高度
	u16	wramcmd;		//开始写gram指令
	u16 setxcmd;		//设置x坐标指令
	u16 setycmd;		//设置y坐标指令 
}_lcd_dev; 	  

//LCD地址结构体
typedef struct
{
	vu16 LCD_REG;
	vu16 LCD_RAM;
} LCD_TypeDef;
//使用NOR/SRAM的 Bank1.sector4,地址位HADDR[27,26]=11 A16作为数据命令区分线 
//注意设置时STM32内部会右移一位对其! 111 1110=0X7E			    
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
#define MAGENTA       	 0xF81F//粉红色
#define GREEN         	 0x07E0
#define CYAN          	 0x7FFF
#define YELLOW        	 0xFFE0
#define BROWN 			 0XBC40 //棕色
#define BRRED 			 0XFC07 //棕红色
#define GRAY  			 0X8430 //灰色
#define Q_GRAY       0XEF5B//浅灰色


//箭头和三角形的方向
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


void LCD_SetCursor(u16 Xpos, u16 Ypos); //设置坐标函数
void LCD_Fill(u16 sx,u16 sy,u16 ex,u16 ey,u16 color); //填充函数
void LCD_Color_Fill(u16 sx,u16 sy,u16 ex,u16 ey,u16 *color);//填充函数
void LCD_DrawPoint(u16 x,u16 y);//画点函数
void LCD_DrawLine(u16 x1, u16 y1, u16 x2, u16 y2,u16 color);//画线函数
void LCD_Set_Window(u16 sx,u16 sy,u16 width,u16 height);//设置窗口函数
void LCD_Clear(u16 color)	;//清屏函数
void LCD_DrawRectangle(u16 x1, u16 y1, u16 x2, u16 y2,u16 color);//画矩形函数
void LCD_Draw_Circle_(u16 x0,u16 y0,u8 r);
void LCD_Draw_Circle(u16 x0,u16 y0,u8 r,u16 color); //画任意颜色圈
void LCD_Fast_DrawPoint(u16 x,u16 y,u16 color); //快速画任意颜色点函数
void LCD_ShowChar(u16 x,u16 y,u8 num,u8 mode,u16 color);  //显示字符，中文，数字函数
void LCD_DrawLtrigo(u16 x1, u16 y1, u16 x2, u16 y2,u8 dir,u16 color);//画三角函数
void LCD_Draw_arrow_key(u16 x1, u16 y1, u16 x2, u16 y2,u8 dir,u16 color);//画箭头函数
void LCD_Show_3030_String(u16 x,u16 y,u8 *p,u16 color);//显示30*30字符串
void LCD_Show_6464_String(u16 x,u16 y,u8 *p,u16 color);//显示64*64字符串
void LCD_Show_2424_String(u16 x,u16 y,u8 *p,u16 color);//显示24*24字符串
void LCD_Show_4848_String(u16 x,u16 y,u8 *p,u16 color);//显示48*48字符串
void LCD_Show_picture(u16 x,u16 y,u16 color,u8 type);//显示图片函数
u32 LCD_Pow(u8 m,u8 n);
void LCD_ShowNum(u16 x,u16 y,u32 num,u8 len,u8 size,u16 p_color,u16 b_color);
void LCD_Show200(u16 x,u16 y,u32 num,u8 len,u8 size,u16 p_color,u16 b_color);
void LCD_ShowChar_(u16 x,u16 y,u8 num,u8 size,u8 mode,u16 p_color,u16 b_color);
#endif



