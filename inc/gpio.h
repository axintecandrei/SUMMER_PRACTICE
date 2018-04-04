/*
 * gpio.h
 *
 *  Created on: 20 mar. 2018
 *      Author: uidp7521
 */

#ifndef GPIO_H_
#define GPIO_H_
#include "stm32f4xx.h"

/*LCD PORTS&PINS*/

#define LCD_NIBBLE_1_PORT GPIOC
#define LCD_D0            GPIO_PIN_0
#define LCD_D1            GPIO_PIN_1
#define LCD_D2            GPIO_PIN_2
#define LCD_D3            GPIO_PIN_3
#define LCD_RS            GPIO_PIN_6
#define LCD_EN            GPIO_PIN_5

#define LCD_NIBBLE_2_PORT GPIOA
#define LCD_D4            GPIO_PIN_6
#define LCD_D5            GPIO_PIN_7
#define LCD_D6            GPIO_PIN_8
#define LCD_D7            GPIO_PIN_9

#define BUTT_PORT         GPIOA
#define BUTT_1			  GPIO_PIN_11
#define BUTT_2			  GPIO_PIN_12



void GPIO_INIT();
#endif /* GPIO_H_ */
