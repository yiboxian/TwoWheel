#include "bsp_Init.h"
#include "stm32f1xx_hal.h"
void Bsp_Init(void)
	{
		HAL_NVIC_SetPriority(USART1_IRQn, 0, 0);
		
	
	}
