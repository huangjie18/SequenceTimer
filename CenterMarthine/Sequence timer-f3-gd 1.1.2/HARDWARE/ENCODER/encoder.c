#include "encoder.h"
#include "sys.h"


void key_init(){

  GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
  	
  GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_12|GPIO_Pin_13;//����������Դ����
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //���ó���������
 	GPIO_Init(GPIOB, &GPIO_InitStructure);
	

}
u8 encoder_dir(){
	
	if(ENCODER_A!=ENCODER_B||ENCODER_KEY==0){
	  
		if(ENCODER_A==1){ //˳ʱ�� ����
		return TURN_R;
		
		}else if(ENCODER_B==0){ //��ʱ�� ����
		return TURN_L;
				
		}else if(ENCODER_KEY==0){
		return EN_KEY;
			
		}
	}		
	
	}
u8 relay_key(){
  if(KEY==1){
	return RE_KEY;	
	}
}
	
	




