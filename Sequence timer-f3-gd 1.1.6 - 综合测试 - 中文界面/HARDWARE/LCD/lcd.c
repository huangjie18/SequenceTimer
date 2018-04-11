#include "lcd.h"
#include "sys.h"
#include "font.h"
#include "delay.h"

_lcd_dev lcddev;

u16 POINT_COLOR=0xFFFF;
u16 BACK_COLOR= 0x0000	  ;
void lcddev_assingment()
{
    lcddev.width=320;
    lcddev.height=240;
    lcddev.wramcmd=0X2C;
    lcddev.setxcmd=0X2A;//设置x方向
    lcddev.setycmd=0X2B; //设置y方向

}
//写寄存器函数
//regval:寄存器值
void LCD_WR_REG(vu16 regval)
{
    regval=regval;		//使用-O2优化的时候,必须插入的延时
    LCD->LCD_REG=regval;//写入要写的寄存器序号

}
//写LCD数据
//data:要写入的值
void LCD_WR_DATA(vu16 data)
{
    data=data;			//使用-O2优化的时候,必须插入的延时
    LCD->LCD_RAM=data;

}
//读LCD数据
//返回值:读到的值
u16 LCD_RD_DATA(void)
{
    vu16 ram;			//防止被优化
    ram=LCD->LCD_RAM;
    return ram;
}
void LCD_WriteReg(u16 LCD_Reg,u16 LCD_RegValue)
{
    LCD->LCD_REG = LCD_Reg;		//写入要写的寄存器序号
    LCD->LCD_RAM = LCD_RegValue;//写入数据

}

//读寄存器
//LCD_Reg:寄存器地址
//返回值:读到的数据
u16 LCD_ReadReg(u16 LCD_Reg)
{
    LCD_WR_REG(LCD_Reg);		//写入要读的寄存器序号
    delay_us(5);
    return LCD_RD_DATA();		//返回读到的值
}
//开始写GRAM
void LCD_WriteRAM_Prepare(void)
{

    LCD->LCD_REG=lcddev.wramcmd;
}


//LCD写GRAM
//RGB_Code:颜色值
void LCD_WriteRAM(u16 RGB_Code)
{
    LCD->LCD_RAM = RGB_Code;//写十六位GRAM
}

void Reset()
{
    GPIO_ResetBits(GPIOE,GPIO_Pin_0);
    delay_ms(200);
    GPIO_SetBits(GPIOE,GPIO_Pin_0);
    delay_ms(200);
}

void LCD_IO_FSMC_Init()
{

    GPIO_InitTypeDef GPIO_InitStructure;
    FSMC_NORSRAMInitTypeDef  FSMC_NORSRAMInitStructure;
    FSMC_NORSRAMTimingInitTypeDef  readWriteTiming;
    FSMC_NORSRAMTimingInitTypeDef  writeTiming;

    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_FSMC,ENABLE);	//使能FSMC时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD|RCC_APB2Periph_GPIOC|RCC_APB2Periph_GPIOE,ENABLE);//使能PORTB,D,E,G以及AFIO复用功能时钟

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;				 //PD13 推挽输出 背光
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOD, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;				 //控制继电器的三极管
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOC, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;				 //LED
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 		 //推挽输出
   // GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOC, &GPIO_InitStructure);
    GPIO_ResetBits(GPIOC,GPIO_Pin_13);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;				 //reset
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOE, &GPIO_InitStructure);

    //PORTD复用推挽输出  PD5 WR PD4 RD   PD11(A16) RS PD7 (NE1) CS
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_14|GPIO_Pin_15;				 //	//PORTD复用推挽输出
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; 		 //复用推挽输出
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOD, &GPIO_InitStructure);

    //PORTE复用推挽输出 PE4 TSCK /PE6 MOSI /PE5 MISO /PE3 TCS /PE1 TBUSY /PE2 TIQP
    GPIO_InitStructure.GPIO_Pin =GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6| GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;				 //	//PORTD复用推挽输出
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; 		 //复用推挽输出
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOE, &GPIO_InitStructure);

    //读时序
    readWriteTiming.FSMC_AddressSetupTime = 0x03;	 //地址建立时间（ADDSET）为2个HCLK 1/36M=27ns
    readWriteTiming.FSMC_AddressHoldTime = 0x00;	 //地址保持时间（ADDHLD）模式A未用到
    readWriteTiming.FSMC_DataSetupTime = 0x0f;		 // 数据保存时间为16个HCLK,因为液晶驱动IC的读数据的时候，速度不能太快，尤其对1289这个IC。
    readWriteTiming.FSMC_BusTurnAroundDuration = 0x00;
    readWriteTiming.FSMC_CLKDivision = 0x00;
    readWriteTiming.FSMC_DataLatency = 0x00;
    readWriteTiming.FSMC_AccessMode = FSMC_AccessMode_A;	 //模式A

    //写时序
    writeTiming.FSMC_AddressSetupTime = 0x03;	 //地址建立时间（ADDSET）为1个HCLK
    writeTiming.FSMC_AddressHoldTime = 0x00;	 //地址保持时间（A
    writeTiming.FSMC_DataSetupTime = 0x05;		 ////数据保存时间为4个HCLK
    writeTiming.FSMC_BusTurnAroundDuration = 0x00;
    writeTiming.FSMC_CLKDivision = 0x00;
    writeTiming.FSMC_DataLatency = 0x00;
    writeTiming.FSMC_AccessMode = FSMC_AccessMode_A;	 //模式A


    FSMC_NORSRAMInitStructure.FSMC_Bank = FSMC_Bank1_NORSRAM1;//  NE1
    FSMC_NORSRAMInitStructure.FSMC_DataAddressMux = FSMC_DataAddressMux_Disable; // 不复用数据地址
    FSMC_NORSRAMInitStructure.FSMC_MemoryType =FSMC_MemoryType_SRAM;// FSMC_MemoryType_SRAM;  //SRAM
    FSMC_NORSRAMInitStructure.FSMC_MemoryDataWidth = FSMC_MemoryDataWidth_16b;//存储器数据宽度为16bit
    FSMC_NORSRAMInitStructure.FSMC_BurstAccessMode =FSMC_BurstAccessMode_Disable;// FSMC_BurstAccessMode_Disable;
    FSMC_NORSRAMInitStructure.FSMC_WaitSignalPolarity = FSMC_WaitSignalPolarity_Low;
    FSMC_NORSRAMInitStructure.FSMC_AsynchronousWait=FSMC_AsynchronousWait_Disable;
    FSMC_NORSRAMInitStructure.FSMC_WrapMode = FSMC_WrapMode_Disable;
    FSMC_NORSRAMInitStructure.FSMC_WaitSignalActive = FSMC_WaitSignalActive_BeforeWaitState;
    FSMC_NORSRAMInitStructure.FSMC_WriteOperation = FSMC_WriteOperation_Enable;	//  存储器写使能
    FSMC_NORSRAMInitStructure.FSMC_WaitSignal = FSMC_WaitSignal_Disable;
    FSMC_NORSRAMInitStructure.FSMC_ExtendedMode = FSMC_ExtendedMode_Enable; // 读写使用不同的时序
    FSMC_NORSRAMInitStructure.FSMC_WriteBurst = FSMC_WriteBurst_Disable;
    FSMC_NORSRAMInitStructure.FSMC_ReadWriteTimingStruct = &readWriteTiming; //读写时序
    FSMC_NORSRAMInitStructure.FSMC_WriteTimingStruct = &writeTiming;  //写时序

    FSMC_NORSRAMInit(&FSMC_NORSRAMInitStructure);  //初始化FSMC配置

    FSMC_NORSRAMCmd(FSMC_Bank1_NORSRAM1, ENABLE);  // 使能BANK1




}

void LCD_Init()
{

    lcddev_assingment();
    Reset();
    LCD_WR_REG(0xCF);
    LCD_WR_DATA(0x00);
    LCD_WR_DATA(0xC1);
    LCD_WR_DATA(0X30);
    LCD_WR_REG(0xED);
    LCD_WR_DATA(0x64);
    LCD_WR_DATA(0x03);
    LCD_WR_DATA(0X12);
    LCD_WR_DATA(0X81);
    LCD_WR_REG(0xE8);
    LCD_WR_DATA(0x85);
    LCD_WR_DATA(0x10);
    LCD_WR_DATA(0x7A);
    LCD_WR_REG(0xCB);
    LCD_WR_DATA(0x39);
    LCD_WR_DATA(0x2C);
    LCD_WR_DATA(0x00);
    LCD_WR_DATA(0x34);
    LCD_WR_DATA(0x02);
    LCD_WR_REG(0xF7);
    LCD_WR_DATA(0x20);
    LCD_WR_REG(0xEA);
    LCD_WR_DATA(0x00);
    LCD_WR_DATA(0x00);
    LCD_WR_REG(0xC0);    //Power control
    LCD_WR_DATA(0x1B);   //VRH[5:0]
    LCD_WR_REG(0xC1);    //Power control
    LCD_WR_DATA(0x01);   //SAP[2:0];BT[3:0]
    LCD_WR_REG(0xC5);    //VCM control
    LCD_WR_DATA(0x30); 	 //3F
    LCD_WR_DATA(0x30); 	 //3C
    LCD_WR_REG(0xC7);    //VCM control2
    LCD_WR_DATA(0XB7);
    LCD_WR_REG(0x36);    // Memory Access Control
    //LCD_WR_DATA(0x68);
    LCD_WR_DATA(0xB8);
    LCD_WR_REG(0x3A);
    LCD_WR_DATA(0x55);
    LCD_WR_REG(0xB1);
    LCD_WR_DATA(0x00);
    LCD_WR_DATA(0x1A);
    LCD_WR_REG(0xB6);    // Display Function Control
    LCD_WR_DATA(0x0A);
    LCD_WR_DATA(0xA2);
    LCD_WR_REG(0xF2);    // 3Gamma Function Disable
    LCD_WR_DATA(0x00);
    LCD_WR_REG(0x26);    //Gamma curve selected
    LCD_WR_DATA(0x01);
    LCD_WR_REG(0xE0);    //Set Gamma
    LCD_WR_DATA(0x0F);
    LCD_WR_DATA(0x2A);
    LCD_WR_DATA(0x28);
    LCD_WR_DATA(0x08);
    LCD_WR_DATA(0x0E);
    LCD_WR_DATA(0x08);
    LCD_WR_DATA(0x54);
    LCD_WR_DATA(0XA9);
    LCD_WR_DATA(0x43);
    LCD_WR_DATA(0x0A);
    LCD_WR_DATA(0x0F);
    LCD_WR_DATA(0x00);
    LCD_WR_DATA(0x00);
    LCD_WR_DATA(0x00);
    LCD_WR_DATA(0x00);
    LCD_WR_REG(0XE1);    //Set Gamma
    LCD_WR_DATA(0x00);
    LCD_WR_DATA(0x15);
    LCD_WR_DATA(0x17);
    LCD_WR_DATA(0x07);
    LCD_WR_DATA(0x11);
    LCD_WR_DATA(0x06);
    LCD_WR_DATA(0x2B);
    LCD_WR_DATA(0x56);
    LCD_WR_DATA(0x3C);
    LCD_WR_DATA(0x05);
    LCD_WR_DATA(0x10);
    LCD_WR_DATA(0x0F);
    LCD_WR_DATA(0x3F);
    LCD_WR_DATA(0x3F);
    LCD_WR_DATA(0x0F);
    LCD_WR_REG(0x2A); //2A列地址设置命令
    LCD_WR_DATA(0x00);
    LCD_WR_DATA(0x00);
    LCD_WR_DATA(0x01);
    LCD_WR_DATA(0x3f);
    LCD_WR_REG(0x2B); //2B行地址设置命令
    LCD_WR_DATA(0x00);
    LCD_WR_DATA(0x00);
    LCD_WR_DATA(0x00);
    LCD_WR_DATA(0xef);

    LCD_WR_REG(0x11); //Exit Sleep
    delay_ms(120);
    LCD_WR_REG(0x29); //display on
    LCD_WR_REG(0x2C);


}

//设置屏幕坐标
void LCD_SetCursor(u16 Xpos, u16 Ypos)
{


    LCD_WR_REG(lcddev.setxcmd);  //对于2AH和2BH来说都是四个寄存器的，所以不论是16位还是8位的LCD都要分两次写入
    LCD_WR_DATA(Xpos>>8);
    LCD_WR_DATA(Xpos&0XFF);
    LCD_WR_REG(lcddev.setycmd);
    LCD_WR_DATA(Ypos>>8);
    LCD_WR_DATA(Ypos&0XFF);
    LCD_WR_REG(0x2C);

}

//开窗函数

//在指定区域内填充单个颜色
//color:要填充的颜色
void LCD_Fill(u16 sx,u16 sy,u16 ex,u16 ey,u16 color)
{
    u16 height,width;
    u16 i,j;
    width=ex-sx+1; 			//得到填充的宽度
    height=ey-sy+1;			//高度
    for(i=0; i<height; i++)
        {
            LCD_SetCursor(sx,sy+i);   	//设置光标位置
            LCD_WriteRAM_Prepare();     //开始写入GRAM
            for(j=0; j<width; j++)LCD->LCD_RAM=color;		//写入数据


        }
}
//在指定区域内填充指定颜色块
//(sx,sy),(ex,ey):填充矩形对角坐标,区域大小为:(ex-sx+1)*(ey-sy+1)
//color:要填充的颜色
void LCD_Color_Fill(u16 sx,u16 sy,u16 ex,u16 ey,u16 *color)
{
    u16 height,width;
    u16 i,j;
    width=ex-sx+1; 			//得到填充的宽度
    height=ey-sy+1;			//高度
    for(i=0; i<height; i++)
        {
            LCD_SetCursor(sx,sy+i);   	//设置光标位置
            LCD_WriteRAM_Prepare();     //开始写入GRAM
            for(j=0; j<width; j++)LCD->LCD_RAM=color[i*width+j]; //写入数据
        }
}
//画点
//x,y:坐标
//POINT_COLOR:此点的颜色
void LCD_DrawPoint(u16 x,u16 y)
{
    LCD_SetCursor(x,y);		//设置光标位置
    LCD_WriteRAM_Prepare();	//开始写入GRAM
    LCD->LCD_RAM=POINT_COLOR;

}

//画线
//x1,y1:起点坐标
//x2,y2:终点坐标
void LCD_DrawLine(u16 x1, u16 y1, u16 x2, u16 y2,u16 color)
{
    u16 t;
    int xerr=0,yerr=0,delta_x,delta_y,distance;
    int incx,incy,uRow,uCol;
    delta_x=x2-x1; //计算坐标增量
    delta_y=y2-y1;
    uRow=x1;
    uCol=y1;
    if(delta_x>0)incx=1; //设置单步方向
    else if(delta_x==0)incx=0;//垂直线
    else
        {
            incx=-1;
            delta_x=-delta_x;
        }
    if(delta_y>0)incy=1;
    else if(delta_y==0)incy=0;//水平线
    else
        {
            incy=-1;
            delta_y=-delta_y;
        }
    if( delta_x>delta_y)distance=delta_x; //选取基本增量坐标轴
    else distance=delta_y;
    for(t=0; t<=distance+1; t++ ) //画线输出
        {
            LCD_Fast_DrawPoint(uRow,uCol,color);//画点
            xerr+=delta_x ;
            yerr+=delta_y ;
            if(xerr>distance)
                {
                    xerr-=distance;
                    uRow+=incx;
                }
            if(yerr>distance)
                {
                    yerr-=distance;
                    uCol+=incy;
                }
        }
}
//清屏函数
void LCD_Clear(u16 color)
{
    u32 index=0;
    u32 totalpoint=lcddev.width;
    totalpoint*=lcddev.height; 			//得到总点数
    LCD_SetCursor(0x00,0x0000);	//设置光标位置
    LCD_WriteRAM_Prepare();     		//开始写入GRAM
    for(index=0; index<totalpoint; index++)
        {
            LCD->LCD_RAM=color;
        }
}
//设置窗口,并自动设置画点坐标到窗口左上角(sx,sy).
//sx,sy:窗口起始坐标(左上角)
//width,height:窗口宽度和高度,必须大于0!!
//窗体大小:width*height.
void LCD_Set_Window(u16 sx,u16 sy,u16 width,u16 height)
{

    u16 twidth,theight;
    twidth=sx+width-1;
    theight=sy+height-1;

    LCD_WR_REG(lcddev.setxcmd);
    LCD_WR_DATA(sx>>8);
    LCD_WR_DATA(sx&0XFF);
    LCD_WR_DATA(twidth>>8);
    LCD_WR_DATA(twidth&0XFF);
    LCD_WR_REG(lcddev.setycmd);
    LCD_WR_DATA(sy>>8);
    LCD_WR_DATA(sy&0XFF);
    LCD_WR_DATA(theight>>8);
    LCD_WR_DATA(theight&0XFF);


    LCD_WR_REG(0x2C);

}


//在指定位置画一个指定大小的圆
//(x,y):中心点
//r    :半径
void LCD_Draw_Circle_(u16 x0,u16 y0,u8 r)
{
    int a,b;
    int di;
    a=0;
    b=r;
    di=3-(r<<1);             //判断下个点位置的标志
    while(a<=b)
        {
            LCD_DrawPoint(x0+a,y0-b);             //5
            LCD_DrawPoint(x0+b,y0-a);             //0
            LCD_DrawPoint(x0+b,y0+a);             //4
            LCD_DrawPoint(x0+a,y0+b);             //6
            LCD_DrawPoint(x0-a,y0+b);             //1
            LCD_DrawPoint(x0-b,y0+a);
            LCD_DrawPoint(x0-a,y0-b);             //2
            LCD_DrawPoint(x0-b,y0-a);             //7
            a++;
            //使用Bresenham算法画圆
            if(di<0)di +=4*a+6;
            else
                {
                    di+=10+4*(a-b);
                    b--;
                }
        }
}
//在指定位置画一个指定大小的圆
//(x,y):中心点
//r    :半径
void LCD_Draw_Circle(u16 x0,u16 y0,u8 r,u16 color)
{
    int a,b;
    int di;
    a=0;
    b=r;
    di=3-(r<<1);             //判断下个点位置的标志
    while(a<=b)
        {
            LCD_Fast_DrawPoint(x0+a,y0-b,color);             //5
            LCD_Fast_DrawPoint(x0+b,y0-a,color);             //0
            LCD_Fast_DrawPoint(x0+b,y0+a,color);             //4
            LCD_Fast_DrawPoint(x0+a,y0+b,color);             //6
            LCD_Fast_DrawPoint(x0-a,y0+b,color);             //1
            LCD_Fast_DrawPoint(x0-b,y0+a,color);
            LCD_Fast_DrawPoint(x0-a,y0-b,color);             //2
            LCD_Fast_DrawPoint(x0-b,y0-a,color);             //7
            a++;
            //使用Bresenham算法画圆
            if(di<0)di +=4*a+6;
            else
                {
                    di+=10+4*(a-b);
                    b--;
                }
        }
}
//画矩形
//(x1,y1),(x2,y2):矩形的对角坐标
void LCD_DrawRectangle(u16 x1, u16 y1, u16 x2, u16 y2,u16 color)
{
    LCD_DrawLine(x1,y1,x2,y1,color);
    LCD_DrawLine(x1,y1,x2,y2,color);
    LCD_DrawLine(x1,y1,x1,y2,color);
    LCD_DrawLine(x1,y2,x2,y2,color);
    LCD_DrawLine(x2,y1,x2,y2,color);
}

/*显示字符函数
 *x,y:起始坐标0
 *mode: 150，80,36,30,24字符集
 *numd对应字符在字符集的索引
 *注意此函数的循环写点的坐标自增需要自己设定（没有开窗函数时候）*/

void LCD_ShowChar(u16 x,u16 y,u8 num,u8 mode,u16 color)
{

    u16 csize,temp,t1,t,size;
    u16 y0=y;


    if(mode==150)
        {
            csize=400;//csize字符对应的点阵占用的字节数
            size=64;	//字符大小
        }
    else if(mode==24)
        {
            csize=36;
            size=24;
        }
    else if(mode==30)
        {
            csize=60;
            size=30;
        }
    else if(mode==48)
        {
            csize=144;
            size=48;

        }
    else if(mode==88)
        {
            csize=484;
            size=88;
        }

    for(t=0; t<csize; t++)
        {

            if(mode==150)
                {
                    temp  = asc2_150150[num][t];
                }
            else if(mode==24)
                {
                    temp = asc2_2424[num][t];
                }
            else if(mode==30)
                {
                    temp=asc2_3030[num][t];
                }
            else if(mode==48)
                {
                    temp = asc2_4848[num][t];
                }
            else if(mode==88)
                {
                    temp=asc2_8888[num][t];
                }

            for(t1=0; t1<8; t1++)
                {
                    if(temp&0x80)
                        {
                            LCD_Fast_DrawPoint(x,y,color);
                        }
                    temp<<=1;
                    y++;//坐标自增
//			if(y>=lcddev.height)return;		//超区域了
                    if((y-y0)==size)
                        {
                            y=y0;
                            x++;
//				if(x>=lcddev.width)return;	//超区域了
                            break;
                        }
                }
        }

}

//快速画点函数
void LCD_Fast_DrawPoint(u16 x,u16 y,u16 color)
{

    LCD_SetCursor(x,y);		//设置光标位置
    LCD_WriteRAM_Prepare();	//开始写入GRAM
    LCD->LCD_RAM=color;

//	  LCD_WR_REG(0x2C);

}



//画三角型函数
/*
在一个坐标(x1,y1)，（x2,y2）构成的正方形画三角形
x1不能大于x2
y1不能大于y2
dir为箭头方向
*/


void LCD_DrawLtrigo(u16 x1, u16 y1, u16 x2, u16 y2,u8 dir,u16 color)
{

    u8 i;
    u16 x,y;;
    if(dir==LEFT)
        {
            x = x1;
            y =y1+(y2-y1)/2;
            for(i=0; i<((x2-x1)/2); i++)
                {
                    LCD_DrawLine(x+i,y-i,x+i,y+i,color);
                }
        }
    else
        {
            x = x2;
            y =y1+(y2-y1)/2;
            for(i=0; i<((x2-x1)/2); i++)
                {
                    LCD_DrawLine(x-i,y-i,x-i,y+i,color);
                }


        }



}

/*
画箭头函数
在一个坐标(x1,y1)，（x2,y2）构成的正方形画三角形
x1不能大于x2
y1不能大于y2
dir为箭头方向
*/
void LCD_Draw_arrow_key(u16 x1, u16 y1, u16 x2, u16 y2,u8 dir,u16 color)
{


    u16 height,width;
    u16 i,j;

    u16 x0,y0;//坐标点是十六位数据，不能设置8位数据变量用来接受坐标数据

    if(dir==LEFT)
        {
            x0=x1+(x2-x1)/2;
            y0=y1+(y2-y1)/4;
            width=(x2-x1)/2; 			//得到填充的宽度
            height=(y2-y1)/2+1;			//高度
            for(i=0; i<height; i++)
                {
                    LCD_SetCursor(x0,y0+i);   	//设置光标位置
                    LCD_WriteRAM_Prepare();     //开始写入GRAM
                    for(j=0; j<width; j++)LCD->LCD_RAM=color;     //写入数据

                }
            LCD_DrawLtrigo(x1,y1,x2,y2,dir,color);
        }
    else
        {

            x0=x1;
            y0=y1+(y2-y1)/4;
            width= (x2-x1)/2+1; 			//得到填充的宽度
            height=(y2-y1)/2+1;			//高度

            for(i=0; i<height; i++)
                {


                    LCD_SetCursor(x0,y0+i);   	//设置光标位置
                    LCD_WriteRAM_Prepare();     //开始写入GRAM
                    for(j=0; j<width; j++)LCD->LCD_RAM=color;     //写入数据

                }


            LCD_DrawLtrigo(x1,y1,x2,y2,dir,color);

        }
}

/*

显示30*30字符串函数
*/
//显示26个英文
//x,y:起点坐标
//width,height:区域大小
//*p:字符串起始地址
void LCD_Show_3030_String(u16 x,u16 y,u8 *p,u16 color)
{
    u8 num;
    while(*p!=0)
        {
            num=*p-' ';  //*p为字符串的初始地址（第一个字符），“A”对应ASCII码表中33，num则是对应asc2_3030字符集中的
            LCD_ShowChar(x,y,num,30,color);
            x+=14;//隔13个像素写一个字符
            p++;
        }

}

/*

显示64*64字符串函数
*/
//x,y:起点坐标
//width,height:区域大小
//*p:字符串起始地址
void LCD_Show_6464_String(u16 x,u16 y,u8 *p,u16 color)
{
    u8 num;
    while(*p!=0)
        {

            num=*p-'0';
            LCD_ShowChar(x,y,num,150,color);
            x+=30;//隔13个像素写一个字符
            p++;
        }

}

/*

显示64*64字符串函数
*/
//x,y:起点坐标
//width,height:区域大小
//*p:字符串起始地址
void LCD_Show_4848_String(u16 x,u16 y,u8 *p,u16 color)
{
    u8 num;
    while(*p!=0)
        {
            num=*p-'0';
            LCD_ShowChar(x,y,num,48,color);
            x+=21;//隔13个像素写一个字符
            p++;
        }

}




/*

显示24*24字符串函数
*/
//显示26个英文
//x,y:起点坐标
//width,height:区域大小
//*p:字符串起始地址
void LCD_Show_2424_String(u16 x,u16 y,u8 *p,u16 color)
{
    u8 num;
    while(*p!=0)
        {
            num=*p-' ';  //*p为字符串的初始地址（第一个字符），“A”对应ASCII码表中33，num则是对应asc2_3030字符集中的
            LCD_ShowChar(x,y,num,24,color);
            x+=12;//隔13个像素写一个字符
            p++;
        }

}


//显示图片函数

void LCD_Show_picture(u16 x,u16 y,u16 color,u8 type)
{


    u16 csize,temp,t1,t,size;
    u16 y0=y;

    if(type==0)
        {
            csize=180;//csize字符对应的点阵占用的字节数
            size=36;	//字符大小
        }
    else if(type==1)
        {

            csize=128;//csize字符对应的点阵占用的字节数
            size=32;	//字符大小
        }
    else if(type==2)
        {

            csize=128;//csize字符对应的点阵占用的字节数
            size=32;	//字符大小

        }
    else if(type==3)
        {
            csize=1464;
            size=48;
        }

    for(t=0; t<csize; t++)
        {

            if(type==0)
                {
                    temp  = gImage_110[0][t];

                }
            else if(type==1)
                {

                    temp  = gImage_111[0][t];
                }
            else if(type==2)
                {

                    temp  = gImage_112[0][t];
                }
            else if(type==3)
                {

                    temp=gImage_logo[0][t];
                }


            for(t1=0; t1<8; t1++)
                {
                    if(temp&0x80)
                        {
                            LCD_Fast_DrawPoint(x,y,color);
                        }
                    temp<<=1;
                    y++;//坐标自增
//			if(y>=lcddev.height)return;		//超区域了
                    if((y-y0)==size)
                        {
                            y=y0;
                            x++;
//				if(x>=lcddev.width)return;	//超区域了
                            break;
                        }
                }
        }

}

//显示数字,高位为0,则不显示
//x,y :起点坐标
//len :数字的位数
//size:字体大小
//color:颜色
//num:数值(0~4294967295);
void LCD_ShowNum(u16 x,u16 y,u32 num,u8 len,u8 size,u16 p_color,u16 b_color)
{
    u16 t,temp;
    u16 enshow=0;
    u8 num_h;
    u8 num_o;
    u8 num_t;
    for(t=0; t<len; t++)
        {

            if(!(size==64))
                {
                    temp=(num/LCD_Pow(10,len-t-1))%10;
                    if(enshow==0&&t<(len-1))
                        {
                            if(temp==0)
                                {

                                    LCD_ShowChar_(x+(size/2)*t,y,'0',size,0,p_color,b_color);

                                    continue;
                                }
                            else enshow=1;

                        }

                    LCD_ShowChar_(x+(size/2)*t,y,temp+'0',size,0,p_color,b_color);

                }
            else
                {
                    if(num>=100)
                        {
                            num_h=(num-num%100)/100;
                            num_o=(num%100)%10;
                            num_t=(num%100-num_o)/10;
                        }
                    else if(num<100)
                        {

                            num_h=0;
                            num_o=num%10;
                            num_t=(num-num_o)/10;
                        }
                    else if(num<=9)
                        {

                            num_h=0;
                            num_o=0;
                            num_t=num;
                        }
                    LCD_Fill(x,y+3,x+96,y+60,BLACK);
                    LCD_ShowChar(x+0,y,num_h,150,WHITE);
                    LCD_ShowChar(x+32,y,num_t,150,WHITE);
                    LCD_ShowChar(x+64,y,num_o,150,WHITE);
                }
        }
}


//在指定位置显示一个字符
//x,y:起始坐标
//num:要显示的字符:" "--->"~"
//size:字体大小 12/16/24
//mode:叠加方式(1)还是非叠加方式(0)
void LCD_ShowChar_(u16 x,u16 y,u8 num,u8 size,u8 mode,u16 p_color,u16 b_color)
{
    u8 temp,t1,t;
    u16 y0=y;
    u16 csize;

    csize=(size/8+((size%8)?1:0))*(size/2);		//得到字体一个字符对应点阵集所占的字节数
    num=num-' ';//得到偏移后的值（ASCII字库是从空格开始取模，所以-' '就是对应字符的字库）

    for(t=0; t<csize; t++)
        {
            if(size==24)
                {
                    temp=asc2_2424[num][t];	//调用2412字体
                }
            else if(size==30)
                {
                    temp=asc2_3030[num][t];
                }
            else if(size==64)
                {

                    temp=asc2_150150[num][t];

                }
            for(t1=0; t1<8; t1++)
                {
                    if(temp&0x80)LCD_Fast_DrawPoint(x,y,p_color);
                    else if(mode==0)LCD_Fast_DrawPoint(x,y,b_color);
                    temp<<=1;
                    y++;
                    if(y>=lcddev.height)return;		//超区域了
                    if((y-y0)==size)
                        {
                            y=y0;
                            x++;
                            if(x>=lcddev.width)return;	//超区域了
                            break;
                        }
                }
        }
}
//m^n函数
//返回值:m^n次方.
u32 LCD_Pow(u8 m,u8 n)
{
    u32 result=1;
    while(n--)result*=m;
    return result;
}

void ShowChineseChar(u16 x,u16 y,u8 num,u8 size,u16 colour)
{

    u16 csize,temp,t1,t;
    u16 y0=y;

    if(size==30)
      csize=400;
    if(size==24)
      csize=72;      
				
    for(t=0; t<csize; t++)
        {

            if(size==30)
                    temp  = ChaneseChar3030[num][t];
            if(size==24)
                    temp  = ChineseChar2424[num][t];
                 
           
            for(t1=0; t1<8; t1++)
                {
                    if(temp&0x80)
                        {
                            LCD_Fast_DrawPoint(x,y,colour);
                        }
                    temp<<=1;
                    y++;//坐标自增
                    if((y-y0)==size)
                        {
                            y=y0;
                            x++;
                            break;
                        }
                }
        }
}
void ShowTwoChineseChar(u16 x,u16 y,u8 one,u8 two,u8 size,u16 colour){

ShowChineseChar(x,y,one,size,colour);
ShowChineseChar(x+size,y,two,size,colour);	
	
}
