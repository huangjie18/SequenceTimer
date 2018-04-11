#include "gui.h"
#include "lcd.h"
/*
GUI�ĵײ㺯��
*/

extern u16 POINT_COLOR;//������ɫ
extern u16 BACK_COLOR;//����ɫ

_gui_phy gui_phy;		//gui�ṹ��

//////////////////////////ͳһ��׼����//////////////////////////////
//���㺯��
//x0,y0:����
//color:��ɫ
void _gui_draw_point(u16 x0,u16 y0,u16 color)
{
    u16 tempcolor=POINT_COLOR;
    POINT_COLOR=color;
    LCD_DrawPoint(x0,y0);
    POINT_COLOR=tempcolor;
}

////////////////////////////////////////////////////////////////////
//gui��ʼ��
void gui_init(void)
{

    gui_phy.draw_point=LCD_Fast_DrawPoint;//���ٻ���
    gui_phy.fill=LCD_Fill;
    gui_phy.colorfill=LCD_Color_Fill;
    gui_phy.lcdwidth=320;
    gui_phy.lcdheight=240;
}



//����㺯��
//x0,y0:����
//color:��ɫ
//��(x0,y0)Ϊ����,��һ��9����Ĵ��
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
//��������
//x0,y0:��� x1,y1:�յ�
//color:��ɫ
void gui_draw_line(u16 x0,u16 y0,u16 x1,u16 y1,u16 color)
{
    u16 t;
    int xerr=0,yerr=0,delta_x,delta_y,distance;
    int incx,incy,uRow,uCol;

    delta_x=x1-x0; //������������
    delta_y=y1-y0;
    uRow=x0;
    uCol=y0;
    if(delta_x>0)incx=1; //���õ�������
    else if(delta_x==0)incx=0;//��ֱ��
    else
        {
            incx=-1;
            delta_x=-delta_x;
        }
    if(delta_y>0)incy=1;
    else if(delta_y==0)incy=0;//ˮƽ��
    else
        {
            incy=-1;
            delta_y=-delta_y;
        }
    if( delta_x>delta_y)distance=delta_x; //ѡȡ��������������
    else distance=delta_y;
    for(t=0; t<=distance+1; t++ )   //�������
        {
            gui_phy.draw_point(uRow,uCol,color);//����
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
//��һ������(����0)
//(x1,y1),(x2,y2):��������ֹ����
//size�������Ĵ�ϸ�̶�
//color����������ɫ
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
    delta_x=x2-x1; //������������
    delta_y=y2-y1;
    uRow=x1;
    uCol=y1;
    if(delta_x>0)incx=1; //���õ�������
    else if(delta_x==0)incx=0;//��ֱ��
    else
        {
            incx=-1;
            delta_x=-delta_x;
        }
    if(delta_y>0)incy=1;
    else if(delta_y==0)incy=0;//ˮƽ��
    else
        {
            incy=-1;
            delta_y=-delta_y;
        }
    if( delta_x>delta_y)distance=delta_x; //ѡȡ��������������
    else distance=delta_y;
    for(t=0; t<=distance+1; t++ )   //�������
        {
            gui_fill_circle(uRow,uCol,size,color);//����
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

//��һ������(����1)
//x0,y0:��� x1,y1:�յ�
//size:�ߴ�ϸ,��֧��:0~2.
//color:��ɫ
void gui_draw_bline1(u16 x0,u16 y0,u16 x1,u16 y1,u8 size,u16 color)
{
    u16 t;
    int xerr=0,yerr=0,delta_x,delta_y,distance;
    int incx,incy,uRow,uCol;

    delta_x=x1-x0; //������������
    delta_y=y1-y0;
    uRow=x0;
    uCol=y0;
    if(delta_x>0)incx=1; //���õ�������
    else if(delta_x==0)incx=0;//��ֱ��
    else
        {
            incx=-1;
            delta_x=-delta_x;
        }
    if(delta_y>0)incy=1;
    else if(delta_y==0)incy=0;//ˮƽ��
    else
        {
            incy=-1;
            delta_y=-delta_y;
        }
    if( delta_x>delta_y)distance=delta_x; //ѡȡ��������������
    else distance=delta_y;
    for(t=0; t<=distance+1; t++ )   //�������
        {
            if(size==0)
                LCD_Fast_DrawPoint(uRow,uCol,color);//����

            if(size==1)
                {
                    LCD_Fast_DrawPoint(uRow,uCol,color);//����
                    LCD_Fast_DrawPoint(uRow+1,uCol,color);//����
                    LCD_Fast_DrawPoint(uRow,uCol+1,color);//����
                    LCD_Fast_DrawPoint(uRow+1,uCol+1,color);//����
                }
            if(size==2)
                {
                    LCD_Fast_DrawPoint(uRow,uCol,color);//����
                    LCD_Fast_DrawPoint(uRow+1,uCol,color);//����
                    LCD_Fast_DrawPoint(uRow,uCol+1,color);//����
                    LCD_Fast_DrawPoint(uRow+1,uCol+1,color);//����
                    LCD_Fast_DrawPoint(uRow-1,uCol+1,color);//����
                    LCD_Fast_DrawPoint(uRow+1,uCol-1,color);//����
                    LCD_Fast_DrawPoint(uRow-1,uCol-1,color);//����
                    LCD_Fast_DrawPoint(uRow-1,uCol,color);//����
                    LCD_Fast_DrawPoint(uRow,uCol-1,color);//����
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
//����ֱ��
//x0,y0:����
//len:�߳���
//color:��ɫ
void gui_draw_vline(u16 x0,u16 y0,u16 len,u16 color)
{
    if((len==0)||(x0>gui_phy.lcdwidth)||(y0>gui_phy.lcdheight))return;
    gui_phy.fill(x0,y0,x0,y0+len-1,color);
}
//��ˮƽ��
//x0,y0:����
//len:�߳���
//color:��ɫ
void gui_draw_hline(u16 x0,u16 y0,u16 len,u16 color)
{
    if((len==0)||(x0>gui_phy.lcdwidth)||(y0>gui_phy.lcdheight))return;
    gui_phy.fill(x0,y0,x0+len-1,y0,color);
}
//���һ��ɫ��.
//x0,y0,width,height:���꼰���ߴ�
//ctbl:��ɫ��,�������ʱwidth,�������ʱ��СΪheight
//mode:���ģʽ(����:������,���ϵ������;����:���ϵ���,���������)
//[7:1]:����
//[bit0]:0,����;1,����
void gui_fill_colorblock(u16 x0,u16 y0,u16 width,u16 height,u16* ctbl,u8 mode)
{
    u16 i;
    if(height==0||width==0)return;
    if(mode&0x01)   //����
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

//������
//x0,y0:���ε����Ͻ�����
//width,height:���εĳߴ�
//color:��ɫ
void gui_draw_rectangle(u16 x0,u16 y0,u16 width,u16 height,u16 color)
{
    gui_draw_hline(x0,y0,width,color);
    gui_draw_hline(x0,y0+height-1,width,color);
    gui_draw_vline(x0,y0,height,color);
    gui_draw_vline(x0+width-1,y0,height,color);
}
//��Բ�Ǿ���/���Բ�Ǿ���
//x,y,width,height:Բ�Ǿ��ε�λ�úͳߴ�
//r:Բ�ǵİ뾶.
//mode:0,�����ο�;1,������.
//upcolor:�ϰ벿����ɫ
//downcolor:�°벿����ɫ
void gui_draw_arcrectangle(u16 x,u16 y,u16 width,u16 height,u8 r,u8 mode,u16 upcolor,u16 downcolor)
{
    u16 btnxh=0;
    if(height%2)btnxh=height+1;//��ż������
    else btnxh=height;
    if(mode)   //���
        {
            gui_fill_rectangle(x+r,y,width-2*r,btnxh/2,upcolor);			//����
            gui_fill_rectangle(x+r,y+btnxh/2,width-2*r,btnxh/2,downcolor);	//����
            gui_fill_rectangle(x,y+r,r,btnxh/2-r,upcolor);					//����
            gui_fill_rectangle(x,y+btnxh/2,r,btnxh/2-r,downcolor);			//����
            gui_fill_rectangle(x+width-r,y+r,r,btnxh/2-r,upcolor);			//����
            gui_fill_rectangle(x+width-r,y+btnxh/2,r,btnxh/2-r,downcolor);	//����
        }
    else
        {
            gui_draw_hline (x+r,y,width-2*r,upcolor);					//��
            gui_draw_hline (x+r,y+btnxh-1,width-2*r,downcolor);			//��
            gui_draw_vline (x,y+r,btnxh/2-r,upcolor);					//����
            gui_draw_vline (x,y+btnxh/2,btnxh/2-r,downcolor);			//����
            gui_draw_vline (x+width-1,y+r,btnxh/2-r,upcolor);			//����
            gui_draw_vline (x+width-1,y+btnxh/2,btnxh/2-r,downcolor);	//����
        }
    gui_draw_arc(x,y,x+r,y+r,x+r,y+r,r,upcolor,mode);//����
    gui_draw_arc(x,y+btnxh-r,x+r,y+btnxh-1,x+r,y+btnxh-r-1,r,downcolor,mode);//����
    gui_draw_arc(x+width-r,y,x+width,y+r,x+width-r-1,y+r,r,upcolor,mode);	 //����
    gui_draw_arc(x+width-r,y+btnxh-r,x+width,y+btnxh-1,x+width-r-1,y+btnxh-r-1,r,downcolor,mode);//����
}


//������
//x0,y0:���ε����Ͻ�����
//width,height:���εĳߴ�
//color:��ɫ
void gui_fill_rectangle(u16 x0,u16 y0,u16 width,u16 height,u16 color)
{
    if(width==0||height==0)return;//�Ƿ�.
    gui_phy.fill(x0,y0,x0+width-1,y0+height-1,color);
}
//��ʵ��Բ
//x0,y0:����
//r�뾶
//color:��ɫ
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
//�������ڻ���
//(sx,sy),(ex,ey):�趨����ʾ��Χ
//(x,y):������
//color:��ɫ
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
//��8��(Bresenham�㷨)
//(sx,sy),(ex,ey):�趨����ʾ��Χ
//(rx,ry,a,b):����
//color:��ɫ
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
//��ָ��λ�û�һ��ָ����С��Բ
//(rx,ry):Բ��
//(sx,sy),(ex,ey):�趨����ʾ��Χ
//r    :�뾶
//color:��ɫ
//mode :0,�����;1,���
void gui_draw_arc(u16 sx,u16 sy,u16 ex,u16 ey,u16 rx,u16 ry,u16 r,u16 color,u8 mode)
{
    int a,b,c;
    int di;
    a=0;
    b=r;
    di=3-(r<<1);	//�ж��¸���λ�õı�־
    while(a<=b)
        {
            if(mode)for(c=a; c<=b; c++)gui_draw_circle8(sx,sy,ex,ey,rx,ry,a,c,color); //��ʵ��Բ
            else gui_draw_circle8(sx,sy,ex,ey,rx,ry,a,b,color);					   //������Բ
            a++;
            //ʹ��Bresenham�㷨��Բ
            if(di<0)di +=4*a+6;
            else
                {
                    di+=10+4*(a-b);
                    b--;
                }
        }
}

/*
�����߿��Բ�Ǿ���
*/

void LCD_draw_arcrectangle(u16 x,u16 y,u16 width,u16 height,u8 r,u16 FILL_color,u16 LINEcolor)
{
    gui_draw_arcrectangle(x,y,width,height,r,1,FILL_color ,FILL_color);
    gui_draw_arcrectangle(x,y,width,height,r,0,LINEcolor,LINEcolor);

}

/*
�����߿�ľ���
size���߿��С 0~2
*/
void LCD_draw_rectangle(u16 x0,u16 y0,u16 x1,u16 y1,u8 size,u16 color)
{

    gui_draw_bline1(x0,y0,x1,y0,size,color);
    gui_draw_bline1(x0,y0,x0,y1,size,color);
    gui_draw_bline1(x0,y1,x1,y1,size,color);
    gui_draw_bline1(x1,y0,x1,y1,size,color);

}

/*
����Բ�Ǳ߿�
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
















