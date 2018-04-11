#include "adc.h"
#include "delay.h"
#include "lcd.h"
#include "flag.h"

extern _flag_dev flag_dev;
void  Adc_Init(void)
{
    ADC_InitTypeDef ADC_InitStructure;
    GPIO_InitTypeDef GPIO_InitStructure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA |RCC_APB2Periph_ADC1	, ENABLE );	  //ʹ��ADC1ͨ��ʱ��


    RCC_ADCCLKConfig(RCC_PCLK2_Div6);   //����ADC��Ƶ����6 72M/6=12,ADC���ʱ�䲻�ܳ���14M

    //PA1 ��Ϊģ��ͨ����������
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;		//ģ����������
//	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    ADC_DeInit(ADC1);  //��λADC1

    ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;	//ADC����ģʽ:ADC1��ADC2�����ڶ���ģʽ
    ADC_InitStructure.ADC_ScanConvMode = DISABLE;	//ģ��ת�������ڵ�ͨ��ģʽ
    ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;	//ģ��ת�������ڵ���ת��ģʽ
    ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;	//ת��������������ⲿ��������
    ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;	//ADC�����Ҷ���
    ADC_InitStructure.ADC_NbrOfChannel = 1;	//˳����й���ת����ADCͨ������Ŀ
    ADC_Init(ADC1, &ADC_InitStructure);	//����ADC_InitStruct��ָ���Ĳ�����ʼ������ADCx�ļĴ���


    ADC_Cmd(ADC1, ENABLE);	//ʹ��ָ����ADC1
    ADC_ResetCalibration(ADC1);	//ʹ�ܸ�λУ׼
    while(ADC_GetResetCalibrationStatus(ADC1));	//�ȴ���λУ׼����
    ADC_StartCalibration(ADC1);	 //����ADУ׼
    while(ADC_GetCalibrationStatus(ADC1));	 //�ȴ�У׼����

    //ADC_SoftwareStartConvCmd(ADC2, ENABLE);		//ʹ��ָ����ADC1�����ת����������
}
//���ADCֵ
//ch:ͨ��ֵ 0~3
u16 Get_Adc(u8 ch)
{
    //����ָ��ADC�Ĺ�����ͨ����һ�����У�����ʱ��
    ADC_RegularChannelConfig(ADC1, ch, 1, ADC_SampleTime_239Cycles5 );	//ADC1,ADCͨ��,����ʱ��Ϊ239.5����

    ADC_SoftwareStartConvCmd(ADC1, ENABLE);		//ʹ��ָ����ADC1�����ת����������

    while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC ));//�ȴ�ת������

    return ADC_GetConversionValue(ADC1);	//�������һ��ADC1�������ת�����
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
/*��ȡADCֵ����,�����ѹ*/
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

            /*��ѹ����ģʽ*/
            V=(*AverageVal)*236/5440;
            /*��ѹ����ģʽ*/
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




