/********************************************************************************
* @File Name: GPIO_interface.h
*
* @Author   : Ahmed Hossam
*
* @Data     : 16 - 8 - 2022
*
* @Brief    : Header file for ARM (STM32F4xx) GPIO driver contains the functions prototypes 
* 			  and configuration structure of the driver.
*
* @version	: 1.0.2
***********************************************************************************/
#ifndef GPIO_INTERFACE
#define GPIO_INTERFACE

#include "GPIO_private.h"

#define NUMBER_OF_USED_PINS 	2
#define PIN_VALUE 				LOGIC_HIGH

/* Description:
*	Configuration structure for GPIO driver.
*/
typedef struct
{
	uint8 PORT_ID     ;
	uint8 PIN_ID      ;
	uint8 MODE        ;
	uint8 OTYPE       ;
	uint8 OSPEED      ;
	uint8 PULL_UP_DOWN;
}pinInfo;

/*Function id*/
typedef enum
{
	GPIO_voidSetPinModeId,
	GPIO_voidSetPinValueODRId,
	GPIO_voidSetPinValueBSRRId,
	GPIO_voidreadPinInfoId
}GPIO_FunctionsIDs_E;

/*Errors id*/
typedef enum{
	GPIO_invalidPortId,
	GPIO_invalidPinId,
	GPIO_invalidValueHighLowId
}GPIO_ErrorsIDs_E;

/*Array of structure to configure more than one pin*/
pinInfo arrOfPins[NUMBER_OF_USED_PINS];

/* Description:
*  Function to configure pins in a specific port.
*  the configuration is set by a global structure that contain:
*  PORT_ID - PIN_ID - MODE - OTYPE - OSPEED - PULL_UP_DOWN.
*  input : void.
*  output: void.
*/
void GPIO_voidSetPinMode(void);

/* Description:
*  Function to set pins by ODR register.
*  Input : the pin value --> LOGIC_HIGH or LOGIC_LOW.
*  output: void.
*/
void GPIO_voidSetPinValue(PORT_IDs_E GPIO_portId, PIN_IDs_E GPIO_pinID, PIN_IDs_E value);

/* Description:
*  Function to read pins value.
*  input : void.
*  output: the pin value.
*/
uint8 GPIO_voidreadPinInfo(PORT_IDs_E GPIO_portId, PIN_IDs_E GPIO_pinID);

//int arr[5]= {[0]=5, [3]=6, [2]=1};

#endif
