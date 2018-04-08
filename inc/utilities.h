/*
 * utilities.h
 *
 *  Created on: 20 mar. 2018
 *      Author: uidp7521
 */

#ifndef UTILITIES_H_
#define UTILITIES_H_
#include "stm32f4xx.h"

typedef struct byteAsbits_s
{
	uint8_t bit_0 :1;
	uint8_t bit_1 :1;
	uint8_t bit_2 :1;
	uint8_t bit_3 :1;
	uint8_t bit_4 :1;
	uint8_t bit_5 :1;
	uint8_t bit_6 :1;
	uint8_t bit_7 :1;
}byteAsbits_t;


void _delay(uint32_t moment);
void ByteToBits (uint8_t in_byte, byteAsbits_t* out_bits );
#endif /* UTILITIES_H_ */
