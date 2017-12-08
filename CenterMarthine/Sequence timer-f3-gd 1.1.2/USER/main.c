#include "stm32f10x.h"
#include "usart.h"
#include "delay.h"
#include "lcd.h"
#include "gui.h"
#include "touch.h"
#include <stdio.h>
#include "usart.h"
#include "key.h"


int main(void)
{
   void InitAll();
   InitAll();
	 LCD_Clear(BLACK);
	 LCD_draw_arcrectangle(105,60,90,40,1,BLUE,WHITE);
	 LCD_draw_arcrectangle(105,122,90,40,1,BLUE,WHITE);
	 LCD_Show_3030_String(120,64,"OPEN",WHITE);
	 LCD_Show_3030_String(115,126,"ClOSE",WHITE);
	
    while(1)
        {	
					

    
					
        }

}
void InitAll()
{

    delay_init();
    LCD_IO_FSMC_Init();
    LCD_Init();
    gui_init();
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置中断优先级分组为组2：2位抢占优先级，2位响应优先级    
    GPIO_SetBits(GPIOD,GPIO_Pin_13);
    GPIO_SetBits(GPIOC,GPIO_Pin_13);
}


//TODO:用位表示变量名称
void Slect(){
 static u8 Index	;
 if(encoder_dev.EN_STATE==TURN_R){
    if(~Index==1){
       		
       Index=0x02;
		}else if(){
		
		
		
		}  
    


}




}