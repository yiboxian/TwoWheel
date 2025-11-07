#include "stm32f1xx_hal.h"
#include "tim.h"
struct Motor
{       
        int8_t MAX_Speed;
        int8_t Speed;
        /* data */
};

void Motor_Setspeed(int8_t Speed)
{
	if(Speed >= 0)
	{
        HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_RESET);	
	}
    else if(Speed <= 0)
	{
        HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_SET);
        __HAL_TIM_SetCompare(&htim1,TIM_CHANNEL_1,100);
	}
}