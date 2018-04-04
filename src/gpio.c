/*
 * gpio.c
 *
 *  Created on: 20 mar. 2018
 *      Author: uidp7521
 *
 * GPIO registers Description:
 * Config:
 * 		- GPIOx_MODER   register is used to select the I/O direction (input, output, AF, analog)
 * 			00: Input
 * 			01: General purpose output mode
 * 		    10: Alternate function mode
 * 		    11: Analog mode
 * 		- GPIOx_OTYPER  register is used to select the output type (push-pull or open-drain)
 *			 0: Output push-pull
 *			 1: Output open-drain
 * 		- GPIOx_OSPEEDR register is used to select speed (the I/O speed pins are directly connected to the
 *                      corresponding GPIOx_OSPEEDR register bits whatever the I/O direction)
 * 		- GPIOx_PUPDR   register is used to select the pull-up/pull-down whatever the I/O direction
 * 			00: No pull-up, pull-down
 * 			01: Pull-up
 * 			10: Pull-down
 * 			11: Reserved
 * Data:
 * 		- GPIOx_ODR     stores the data to be output, it is read/write accessible
 * 			- can be used to toggle the pin
 * 		- GPIOx_IDR     stores the data into this register
 *
 *      - GPIOx_BSRR
 *      	- pin_nr
 *      		 0 No action on the corresponding ODRx
 *      		 1: Resets the corresponding ODRx bit
 *      	- pin_nr<<16
 *      		 0: No action on the corresponding ODRx bit
 *      		 1: Sets the corresponding ODRx bit
 * */

#include "gpio.h"


void GPIO_INIT()
{
	/* local init struct for ports
	 * can be used for any ports
	 * if properly managed*/

	GPIO_InitTypeDef GPIOx_Init;

	GPIOx_Init.Pin   = LCD_D0 | LCD_D1 | LCD_D2 | LCD_D3 | LCD_RS | LCD_EN;
	GPIOx_Init.Mode  = GPIO_MODE_OUTPUT_PP;
	GPIOx_Init.Pull  = GPIO_NOPULL;
	GPIOx_Init.Speed = GPIO_SPEED_MEDIUM;

	/*Enable bus clock for ports*/
	__GPIOC_CLK_ENABLE();
    /*HAL func that will do the proper initialisation*/
	HAL_GPIO_Init(LCD_NIBBLE_1_PORT, &GPIOx_Init);

	GPIOx_Init.Pin   = LCD_D4 | LCD_D5 | LCD_D6 | LCD_D7 ;
	GPIOx_Init.Mode  = GPIO_MODE_OUTPUT_PP;
	GPIOx_Init.Pull  = GPIO_NOPULL;
	GPIOx_Init.Speed = GPIO_SPEED_MEDIUM;

	/*Enable bus clock for ports*/
	__GPIOA_CLK_ENABLE();
    /*HAL func that will do the proper initialisation*/
	HAL_GPIO_Init(LCD_NIBBLE_2_PORT, &GPIOx_Init);

	GPIOx_Init.Pin   = BUTT_1 | BUTT_2 ;
	GPIOx_Init.Mode  = GPIO_MODE_INPUT;
	GPIOx_Init.Pull  = GPIO_PULLDOWN;
	GPIOx_Init.Speed = GPIO_SPEED_MEDIUM;

    /*HAL func that will do the proper initialisation*/
	HAL_GPIO_Init(BUTT_PORT, &GPIOx_Init);
}


