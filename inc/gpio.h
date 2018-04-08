/*
 * gpio.h
 *
 *  Created on: 20 mar. 2018
 *      Author: uidp7521
 */

#ifndef GPIO_H_
#define GPIO_H_
#include "stm32f4xx.h"

/*
 * DEFINES
 */

/*LCD PORTS&PINS*/

#define LCD_NIBBLE_1_PORT GPIOC
#define LCD_D0            GPIO_PIN_0
#define LCD_D1            GPIO_PIN_1
#define LCD_D2            GPIO_PIN_2
#define LCD_D3            GPIO_PIN_3

#define LCD_CONTROL_PORT  GPIOC
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

#define CONFIDENCE_THR    (100)
#define BUTT_NR			  (  2)

/*
 * TYPE-DEFs
 */
typedef enum pin_state_e
{
	released =0,
	pressed = 1
}pin_state_t;

typedef struct debounce_state_s
{
	pin_state_t button_state;
	uint32_t    ButtonPressedConfidanceLevel;
	uint32_t    ButtonReleasedConfidanceLevel;
}debounce_state_t;

/*
 * VARIABLES
 */

debounce_state_t DEBOUNCE_BUTTx[BUTT_NR];


/*
 * FUNCTIONS
 */

void GPIO_INIT();
uint8_t DebounceButton(GPIO_TypeDef* port, uint16_t button, debounce_state_t* port_debounce_str);
#endif /* GPIO_H_ */
