#include "adc.h"
#include "delay.h"
#include "lcd.h"
#include "flag.h"

extern _flag_dev flag_dev;
void  Adc_Init(void)
{
    ADC_InitTypeDef ADC_InitStructure;
    GPIO_InitTypeDef GPIO_InitStructure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA |RCC_APB2Periph_ADC1	, ENABLE );	  //使能ADC1通道时钟


    RCC_ADCCLKConfig(RCC_PCLK2_Div6);   //设置ADC分频因子6 72M/6=12,ADC最大时间不能超过14M

    //PA1 作为模拟通道输入引脚
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;		//模拟输入引脚
//	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    ADC_DeInit(ADC1);  //复位ADC1

    ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;	//ADC工作模式:ADC1和ADC2工作在独立模式
    ADC_InitStructure.ADC_ScanConvMode = DISABLE;	//模数转换工作在单通道模式
    ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;	//模数转换工作在单次转换模式
    ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;	//转换由软件而不是外部触发启动
    ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;	//ADC数据右对齐
    ADC_InitStructure.ADC_NbrOfChannel = 1;	//顺序进行规则转换的ADC通道的数目
    ADC_Init(ADC1, &ADC_InitStructure);	//根据ADC_InitStruct中指定的参数初始化外设ADCx的寄存器


    ADC_Cmd(ADC1, ENABLE);	//使能指定的ADC1
    ADC_ResetCalibration(ADC1);	//使能复位校准
    while(ADC_GetResetCalibrationStatus(ADC1));	//等待复位校准结束
    ADC_StartCalibration(ADC1);	 //开启AD校准
    while(ADC_GetCalibrationStatus(ADC1));	 //等待校准结束

    //ADC_SoftwareStartConvCmd(ADC2, ENABLE);		//使能指定的ADC1的软件转换启动功能
}
//获得ADC值
//ch:通道值 0~3
u16 Get_Adc(u8 ch)
{
    //设置指定ADC的规则组通道，一个序列，采样时间
    ADC_RegularChannelConfig(ADC1, ch, 1, ADC_SampleTime_239Cycles5 );	//ADC1,ADC通道,采样时间为239.5周期

    ADC_SoftwareStartConvCmd(ADC1, ENABLE);		//使能指定的ADC1的软件转换启动功能

    while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC ));//等待转换结束

    return ADC_GetConversionValue(ADC1);	//返回最近一次ADC1规则组的转换结果
}

u16 Get_Adc_(u8 ch,u8 times)
{
    u32 temp_val=0;
    u8 t;
    u8 K;
    u32 val;
    for(t=0; t<times; t++)
        {
            val=Get_Adc(ch);
            delay_ms(1);
            if(val>500)
                {

                    temp_val=temp_val+val;
                    K++;
                }
        }

    return temp_val/K;
}
/*获取ADC值函数,计算电压*/
void GetValOfAdc(u8 ch,u32* AverageVal)
{	 
    u8 k;
    static u16 i,j,V;
    static u32 VAL,FIRAVERAGE,SECAVERAGE;
    static u16 lastval;
    u32 val;
    val=Get_Adc(ch);		
    if(i<120)
        {
            if(val>500)
                {									
                    VAL+=val;
                    i++;
                }
        }
    else
        {
            FIRAVERAGE=VAL/20;
            SECAVERAGE+=FIRAVERAGE;
            j++;
            i=0;
            VAL=0;
            if(j==40)
                {
                    *AverageVal=SECAVERAGE/80;
									  FIRAVERAGE=0;
                    SECAVERAGE=0;
                    j=0;
                }

            /*高压计算模式*/
            V=(*AverageVal)*236/5440;
            /*低压计算模式*/
            if(V<150)
                {													
                    V=(*AverageVal)*120/2676;
                }
            flag_dev.lastVAL=V;
						//LCD_ShowNum(0,0,val,5,30,WHITE,BLACK);
          //								LCD_ShowNum(0,150,*AverageVal,5,30,WHITE,BLACK);
            if(flag_dev.action_flag==HOME||flag_dev.action_flag==HOME_X)
                {
									
                    if(lastval!=V)
                        {
                            //LCD_ShowNum(162,100,*AverageVal,5,30,WHITE,BLACK);
                            LCD_ShowNum(162,38,V,3,64,WHITE,BLACK);
                            lastval=V;
                        }
                }
        }
}




