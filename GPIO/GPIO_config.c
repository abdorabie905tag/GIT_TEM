/********************************************************************************
* @File Name: GPIO_config.c
*
* @Author   : Ahmed Hossam
*
* @Data     : 15 - 8 - 2022
*
* @Brief    : Source file for ARM (STM32F4xx) GPIO driver configuration.
*
* @version	: 1.0.2
***********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

/* For configuration:
 * Port ID --> PORTA, PORTB, PORTC.
 * PIN ID  --> PIN0.........PIN15
 * Mode    --> INPUT, OUTPUT, AF, ANALOG
 * In case of output:
 * 		OTYPE  		 --> PUSH_PULL, OPEN_DRAIN
 * 		OSPEED 		 --> LOW_SPEED, MEDIUM_SPEED, HIGH_SPEED, VERY_HIGH_SPEED
 * 		PULL_UP_DOWN --> NOT_USED
 * In case of input:
 *   	OTYPE  		 --> PUSH_PULL, OPEN_DRAIN
 * 		OSPEED 		 --> LOW_SPEED, MEDIUM_SPEED, HIGH_SPEED, VERY_HIGH_SPEED
 * 		PULL_UP_DOWN --> NOT_USED
 * 		*/
pinInfo arrOfPins[NUMBER_OF_USED_PINS] =
{
	{
		.PORT_ID      = PORTA,
		.PIN_ID       = PIN0,
		.MODE         = OUTPUT,  
		.OTYPE        = PUSH_PULL, 
		.OSPEED       = LOW_SPEED,
		.PULL_UP_DOWN = PULL_UP,
	},
	{
		.PORT_ID      = PORTA,
		.PIN_ID       = PIN1,
		.MODE         = OUTPUT,  
		.OTYPE        = PUSH_PULL, 
		.OSPEED       = LOW_SPEED,
		.PULL_UP_DOWN = PULL_UP,
	}
	
};
