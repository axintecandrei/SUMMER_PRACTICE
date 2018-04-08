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
	byteAsbits_t data_out;
	static uint8_t number_inc = 0;
	for(;;)
	{

	   /*Buttons Demo using debounce */
	   if(DebounceButton(BUTT_PORT,BUTT_1,&DEBOUNCE_BUTTx[0]) == pressed)
	   {
	      HAL_GPIO_WritePin(LCD_CONTROL_PORT, LCD_RS, GPIO_PIN_SET);
	      number_inc++;
	      _delay(10);
	   }
	   else
	   {
	      HAL_GPIO_WritePin(LCD_CONTROL_PORT, LCD_RS, GPIO_PIN_RESET);
	   }

      if(DebounceButton(BUTT_PORT,BUTT_2,&DEBOUNCE_BUTTx[1]) == pressed)
      {
         HAL_GPIO_WritePin(LCD_CONTROL_PORT, LCD_EN, GPIO_PIN_SET);
         number_inc--;
         _delay(10);
      }
      else
      {
         HAL_GPIO_WritePin(LCD_CONTROL_PORT, LCD_EN, GPIO_PIN_RESET);
      }

      /*Output a number on 8 leds - emulationg a 8 bit register*/

      ByteToBits(number_inc,&data_out);

	   HAL_GPIO_WritePin(LCD_NIBBLE_1_PORT, LCD_D0, data_out.bit_0);
	   HAL_GPIO_WritePin(LCD_NIBBLE_1_PORT, LCD_D1, data_out.bit_1);
	   HAL_GPIO_WritePin(LCD_NIBBLE_1_PORT, LCD_D2, data_out.bit_2);
	   HAL_GPIO_WritePin(LCD_NIBBLE_1_PORT, LCD_D3, data_out.bit_3);
	   HAL_GPIO_WritePin(LCD_NIBBLE_2_PORT, LCD_D4, data_out.bit_4);
	   HAL_GPIO_WritePin(LCD_NIBBLE_2_PORT, LCD_D5, data_out.bit_5);
	   HAL_GPIO_WritePin(LCD_NIBBLE_2_PORT, LCD_D6, data_out.bit_6);
	   HAL_GPIO_WritePin(LCD_NIBBLE_2_PORT, LCD_D7, data_out.bit_7);
	   /*
	   number_inc++;
	   _delay(3000);*/
	}
}
