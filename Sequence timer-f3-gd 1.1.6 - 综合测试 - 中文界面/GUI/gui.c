#include "gui.h"
#include "lcd.h"
/*
GUI的底层函数
*/

extern u16 POINT_COLOR;//画笔颜色
extern u16 BACK_COLOR;//背景色

_gui_phy gui_phy;		//gui结构体

//////////////////////////统一标准函数//////////////////////////////
//画点函数
//x0,y0:坐标
//color:颜色
void _gui_draw_point(u16 x0,u16 y0,u16 color)
{
    u16 tempcolor=POINT_COLOR;
    POINT_COLOR=color;
    LCD_DrawPoint(x0,y0);
    POINT_COLOR=tempcolor;
}

////////////////////////////////////////////////////////////////////
//gui初始化
void gui_init(void)
{

    gui_phy.draw_point=LCD_Fast_DrawPoint;//快速画点
    gui_phy.fill=LCD_Fill;
    gui_phy.colorfill=LCD_Color_Fill;
    gui_phy.lcdwidth=320;
    gui_phy.lcdheight=240;
}



//画大点函数
//x0,y0:坐标
//color:颜色
//以(x0,y0)为中心,画一个9个点的大点
void gui_draw_bigpoint(u16 x0,u16 y0,u16 color)
{
    u16 i,j;
    u16 x,y;
    if(x0>=1)x=x0-1;
    else x=x0;
    if(y0>=1)y=y0-1;
    else y=y0;
    for(i=y; i<y0+2; i++)
        {
            for(j=x; j<x0+2; j++)gui_phy.draw_point(j,i,color);
        }
}
//画任意线
//x0,y0:起点 x1,y1:终点
//color:颜色
void gui_draw_line(u16 x0,u16 y0,u16 x1,u16 y1,u16 color)
{
    u16 t;
    int xerr=0,yerr=0,delta_x,delta_y,distance;
    int incx,incy,uRow,uCol;

    delta_x=x1-x0; //计算坐标增量
    delta_y=y1-y0;
    uRow=x0;
    uCol=y0;
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
    for(t=0; t<=distance+1; t++ )   //画线输出
        {
            gui_phy.draw_point(uRow,uCol,color);//画点
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
//画一条粗线(方法0)
//(x1,y1),(x2,y2):线条的起止坐标
//size：线条的粗细程度
//color：线条的颜色
void gui_draw_bline(u16 x1, u16 y1, u16 x2, u16 y2,u8 size,u16 color)
{
    u16 t;
    int xerr=0,yerr=0,delta_x,delta_y,distance;
    int incx,incy,uRow,uCol;
    if(x1<size|| x2<size||y1<size|| y2<size)return;
    if(size==0)
        {
            gui_phy.draw_point(x1,y1,color);
            return;
        }
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
    for(t=0; t<=distance+1; t++ )   //画线输出
        {
            gui_fill_circle(uRow,uCol,size,color);//画点
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

//画一条粗线(方法1)
//x0,y0:起点 x1,y1:终点
//size:线粗细,仅支持:0~2.
//color:颜色
void gui_draw_bline1(u16 x0,u16 y0,u16 x1,u16 y1,u8 size,u16 color)
{
    u16 t;
    int xerr=0,yerr=0,delta_x,delta_y,distance;
    int incx,incy,uRow,uCol;

    delta_x=x1-x0; //计算坐标增量
    delta_y=y1-y0;
    uRow=x0;
    uCol=y0;
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
    for(t=0; t<=distance+1; t++ )   //画线输出
        {
            if(size==0)
                LCD_Fast_DrawPoint(uRow,uCol,color);//画点

            if(size==1)
                {
                    LCD_Fast_DrawPoint(uRow,uCol,color);//画点
                    LCD_Fast_DrawPoint(uRow+1,uCol,color);//画点
                    LCD_Fast_DrawPoint(uRow,uCol+1,color);//画点
                    LCD_Fast_DrawPoint(uRow+1,uCol+1,color);//画点
                }
            if(size==2)
                {
                    LCD_Fast_DrawPoint(uRow,uCol,color);//画点
                    LCD_Fast_DrawPoint(uRow+1,uCol,color);//画点
                    LCD_Fast_DrawPoint(uRow,uCol+1,color);//画点
                    LCD_Fast_DrawPoint(uRow+1,uCol+1,color);//画点
                    LCD_Fast_DrawPoint(uRow-1,uCol+1,color);//画点
                    LCD_Fast_DrawPoint(uRow+1,uCol-1,color);//画点
                    LCD_Fast_DrawPoint(uRow-1,uCol-1,color);//画点
                    LCD_Fast_DrawPoint(uRow-1,uCol,color);//画点
                    LCD_Fast_DrawPoint(uRow,uCol-1,color);//画点
                }
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
//画垂直线
//x0,y0:坐标
//len:线长度
//color:颜色
void gui_draw_vline(u16 x0,u16 y0,u16 len,u16 color)
{
    if((len==0)||(x0>gui_phy.lcdwidth)||(y0>gui_phy.lcdheight))return;
    gui_phy.fill(x0,y0,x0,y0+len-1,color);
}
//画水平线
//x0,y0:坐标
//len:线长度
//color:颜色
void gui_draw_hline(u16 x0,u16 y0,u16 len,u16 color)
{
    if((len==0)||(x0>gui_phy.lcdwidth)||(y0>gui_phy.lcdheight))return;
    gui_phy.fill(x0,y0,x0+len-1,y0,color);
}
//填充一个色块.
//x0,y0,width,height:坐标及填充尺寸
//ctbl:颜色表,横向填充时width,纵向填充时大小为height
//mode:填充模式(纵向:从左到右,从上到下填充;横向:从上到下,从左到右填充)
//[7:1]:保留
//[bit0]:0,纵向;1,横向
void gui_fill_colorblock(u16 x0,u16 y0,u16 width,u16 height,u16* ctbl,u8 mode)
{
    u16 i;
    if(height==0||width==0)return;
    if(mode&0x01)   //横向
        {
            for(i=0; i<width; i++)
                {
                    gui_draw_vline(x0+i,y0,height-1,ctbl[i]);
                }
        }
    else
        {
            for(i=0; i<height; i++)
                {
                    gui_draw_hline(x0,y0+i,width-1,ctbl[i]);
                }
        }
}

//画矩形
//x0,y0:矩形的左上角坐标
//width,height:矩形的尺寸
//color:颜色
void gui_draw_rectangle(u16 x0,u16 y0,u16 width,u16 height,u16 color)
{
    gui_draw_hline(x0,y0,width,color);
    gui_draw_hline(x0,y0+height-1,width,color);
    gui_draw_vline(x0,y0,height,color);
    gui_draw_vline(x0+width-1,y0,height,color);
}
//画圆角矩形/填充圆角矩形
//x,y,width,height:圆角矩形的位置和尺寸
//r:圆角的半径.
//mode:0,画矩形框;1,填充矩形.
//upcolor:上半部分颜色
//downcolor:下半部分颜色
void gui_draw_arcrectangle(u16 x,u16 y,u16 width,u16 height,u8 r,u8 mode,u16 upcolor,u16 downcolor)
{
    u16 btnxh=0;
    if(height%2)btnxh=height+1;//基偶数处理
    else btnxh=height;
    if(mode)   //填充
        {
            gui_fill_rectangle(x+r,y,width-2*r,btnxh/2,upcolor);			//中上
            gui_fill_rectangle(x+r,y+btnxh/2,width-2*r,btnxh/2,downcolor);	//中下
            gui_fill_rectangle(x,y+r,r,btnxh/2-r,upcolor);					//左上
            gui_fill_rectangle(x,y+btnxh/2,r,btnxh/2-r,downcolor);			//左下
            gui_fill_rectangle(x+width-r,y+r,r,btnxh/2-r,upcolor);			//右上
            gui_fill_rectangle(x+width-r,y+btnxh/2,r,btnxh/2-r,downcolor);	//右下
        }
    else
        {
            gui_draw_hline (x+r,y,width-2*r,upcolor);					//上
            gui_draw_hline (x+r,y+btnxh-1,width-2*r,downcolor);			//下
            gui_draw_vline (x,y+r,btnxh/2-r,upcolor);					//左上
            gui_draw_vline (x,y+btnxh/2,btnxh/2-r,downcolor);			//左下
            gui_draw_vline (x+width-1,y+r,btnxh/2-r,upcolor);			//右上
            gui_draw_vline (x+width-1,y+btnxh/2,btnxh/2-r,downcolor);	//右下
        }
    gui_draw_arc(x,y,x+r,y+r,x+r,y+r,r,upcolor,mode);//左上
    gui_draw_arc(x,y+btnxh-r,x+r,y+btnxh-1,x+r,y+btnxh-r-1,r,downcolor,mode);//左下
    gui_draw_arc(x+width-r,y,x+width,y+r,x+width-r-1,y+r,r,upcolor,mode);	 //右上
    gui_draw_arc(x+width-r,y+btnxh-r,x+width,y+btnxh-1,x+width-r-1,y+btnxh-r-1,r,downcolor,mode);//右下
}


//填充矩形
//x0,y0:矩形的左上角坐标
//width,height:矩形的尺寸
//color:颜色
void gui_fill_rectangle(u16 x0,u16 y0,u16 width,u16 height,u16 color)
{
    if(width==0||height==0)return;//非法.
    gui_phy.fill(x0,y0,x0+width-1,y0+height-1,color);
}
//画实心圆
//x0,y0:坐标
//r半径
//color:颜色
void gui_fill_circle(u16 x0,u16 y0,u16 r,u16 color)
{
    u32 i;
    u32 imax = ((u32)r*707)/1000+1;
    u32 sqmax = (u32)r*(u32)r+(u32)r/2;
    u32 x=r;
    gui_draw_hline(x0-r,y0,2*r,color);
    for (i=1; i<=imax; i++)
        {
            if ((i*i+x*x)>sqmax)
                {
                    // draw lines from outside
                    if (x>imax)
                        {
                            gui_draw_hline (x0-i+1,y0+x,2*(i-1),color);
                            gui_draw_hline (x0-i+1,y0-x,2*(i-1),color);
                        }
                    x--;
                }
            // draw lines from inside (center)
            gui_draw_hline(x0-x,y0+i,2*x,color);
            gui_draw_hline(x0-x,y0-i,2*x,color);
        }
}
//在区域内画点
//(sx,sy),(ex,ey):设定的显示范围
//(x,y):点坐标
//color:颜色
void gui_draw_expoint(u16 sx,u16 sy,u16 ex,u16 ey,u16 x,u16 y,u16 color)
{
    u16 tempcolor;
    if(x<=ex&&x>=sx&&y<=ey&&y>=sy)
        {
            tempcolor=POINT_COLOR;
            POINT_COLOR=color;
            LCD_DrawPoint(x,y);
            POINT_COLOR=tempcolor;
        }
}
//画8点(Bresenham算法)
//(sx,sy),(ex,ey):设定的显示范围
//(rx,ry,a,b):参数
//color:颜色
void gui_draw_circle8(u16 sx,u16 sy,u16 ex,u16 ey,u16 rx,u16 ry,int a,int b,u16 color)
{
    gui_draw_expoint(sx,sy,ex,ey,rx+a,ry-b,color);
    gui_draw_expoint(sx,sy,ex,ey,rx+b,ry-a,color);
    gui_draw_expoint(sx,sy,ex,ey,rx+b,ry+a,color);
    gui_draw_expoint(sx,sy,ex,ey,rx+a,ry+b,color);
    gui_draw_expoint(sx,sy,ex,ey,rx-a,ry+b,color);
    gui_draw_expoint(sx,sy,ex,ey,rx-b,ry+a,color);
    gui_draw_expoint(sx,sy,ex,ey,rx-b,ry-a,color);
    gui_draw_expoint(sx,sy,ex,ey,rx-a,ry-b,color);
}
//在指定位置画一个指定大小的圆
//(rx,ry):圆心
//(sx,sy),(ex,ey):设定的显示范围
//r    :半径
//color:颜色
//mode :0,不填充;1,填充
void gui_draw_arc(u16 sx,u16 sy,u16 ex,u16 ey,u16 rx,u16 ry,u16 r,u16 color,u8 mode)
{
    int a,b,c;
    int di;
    a=0;
    b=r;
    di=3-(r<<1);	//判断下个点位置的标志
    while(a<=b)
        {
            if(mode)for(c=a; c<=b; c++)gui_draw_circle8(sx,sy,ex,ey,rx,ry,a,c,color); //画实心圆
            else gui_draw_circle8(sx,sy,ex,ey,rx,ry,a,b,color);					   //画空心圆
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

/*
画带边框的圆角矩形
*/

void LCD_draw_arcrectangle(u16 x,u16 y,u16 width,u16 height,u8 r,u16 FILL_color,u16 LINEcolor)
{
    gui_draw_arcrectangle(x,y,width,height,r,1,FILL_color ,FILL_color);
    gui_draw_arcrectangle(x,y,width,height,r,0,LINEcolor,LINEcolor);

}

/*
画带边框的矩形
size：边框大小 0~2
*/
void LCD_draw_rectangle(u16 x0,u16 y0,u16 x1,u16 y1,u8 size,u16 color)
{

    gui_draw_bline1(x0,y0,x1,y0,size,color);
    gui_draw_bline1(x0,y0,x0,y1,size,color);
    gui_draw_bline1(x0,y1,x1,y1,size,color);
    gui_draw_bline1(x1,y0,x1,y1,size,color);

}

/*
画粗圆角边框
*/

void b_gui_draw_arcrectangle(u16 x,u16 y,u16 width,u16 height,u8 r,u8 mode,u16 FILL_color,u16 LINEcolor)
{
    if(LINEcolor==BLACK)
        {

            gui_draw_arcrectangle(x,y,width,height,r,mode,BLACK ,BLACK);
            gui_draw_arcrectangle(x+1,y+1,width-2,height-2,r,mode,WHITE,WHITE);
            gui_draw_arcrectangle(x+2,y+2,width-3,height-3,r,mode,WHITE,WHITE);

        }
    else
        {
            gui_draw_arcrectangle(x,y,width,height,r,mode,LINEcolor ,LINEcolor);
            gui_draw_arcrectangle(x+1,y+1,width-2,height-2,r,mode,LINEcolor,LINEcolor);
            gui_draw_arcrectangle(x+2,y+2,width-3,height-3,r,mode,LINEcolor,LINEcolor);

        }
}
















