/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/
#include "main.h"


int main(void)
{

	MAIN_INIT();

	HAL_GPIO_WritePin(LCD_NIBBLE_1_PORT, LCD_D0, GPIO_PIN_RESET);
	for(;;)
	{
		HAL_GPIO_WritePin(LCD_NIBBLE_1_PORT, LCD_D0, GPIO_PIN_SET);
		_delay(3000);
		HAL_GPIO_WritePin(LCD_NIBBLE_1_PORT, LCD_D0, GPIO_PIN_RESET);
		_delay(4000);
	}
}
