/********************************************************************************
 * @File Name: GPIO_program.c
 *
 * @Author   : Ahmed Hossam
 *
 * @Data     : 16 - 8 - 2022
 *
 * @Brief    : Source file for ARM (STM32F4xx) GPIO driver using Det error report.
 *
 * @version	: 1.0.2
 ***********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DET.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

void GPIO_voidSetPinMode(void)
{
	uint8 local_uint8PinsCounter;
	for(local_uint8PinsCounter=0; local_uint8PinsCounter<NUMBER_OF_USED_PINS; local_uint8PinsCounter++)
	{
		switch(arrOfPins[local_uint8PinsCounter].PORT_ID)
		{
		case PORTA:
			/* Reset the pin then write the required configuration*/
			GPIOA -> MODER  &= ~((0b11) <<
					((arrOfPins[local_uint8PinsCounter].PIN_ID)*2));
			GPIOA -> MODER  |= ((arrOfPins[local_uint8PinsCounter].MODE) <<
					((arrOfPins[local_uint8PinsCounter].PIN_ID)*2));
			if(arrOfPins[local_uint8PinsCounter].MODE == OUTPUT)
			{	/* Reset the pin then write the required configuration*/
				GPIOA -> OTYPER  &= ~(1 << (arrOfPins[local_uint8PinsCounter].PIN_ID));
				GPIOA -> OTYPER  |=  ((arrOfPins[local_uint8PinsCounter].OTYPE) << (arrOfPins[local_uint8PinsCounter].PIN_ID));

				GPIOA -> OSPEEDR  &= ~((0b11) <<
						((arrOfPins[local_uint8PinsCounter].PIN_ID)*2));
				GPIOA -> OSPEEDR  |=  ((arrOfPins[local_uint8PinsCounter].OSPEED) <<
						((arrOfPins[local_uint8PinsCounter].PIN_ID)*2));
			}				
			else 
 			{	/* Reset the pin then write the required configuration*/
				GPIOA -> PUPDR  &= ~((0b11) <<
						((arrOfPins[local_uint8PinsCounter].PIN_ID)*2));
				GPIOA -> PUPDR  |=  ((arrOfPins[local_uint8PinsCounter].PULL_UP_DOWN) <<
						((arrOfPins[local_uint8PinsCounter].PIN_ID)*2));
			}
			break;
		case PORTB:
			/* Reset the pin then write the required configuration*/
			GPIOB -> MODER  &= ~((0b11) <<
					((arrOfPins[local_uint8PinsCounter].PIN_ID)*2));
			GPIOB -> MODER  |= ((arrOfPins[local_uint8PinsCounter].MODE) <<
					((arrOfPins[local_uint8PinsCounter].PIN_ID)*2));
			if(arrOfPins[local_uint8PinsCounter].MODE == OUTPUT)
			{	/* Reset the pin then write the required configuration*/
				GPIOB -> OTYPER  &= ~(1 << (arrOfPins[local_uint8PinsCounter].PIN_ID));
				GPIOB -> OTYPER  |=  ((arrOfPins[local_uint8PinsCounter].OTYPE) << (arrOfPins[local_uint8PinsCounter].PIN_ID));

				GPIOB -> OSPEEDR  &= ~((0b11) <<
						((arrOfPins[local_uint8PinsCounter].PIN_ID)*2));
				GPIOB -> OSPEEDR  |=  ((arrOfPins[local_uint8PinsCounter].OSPEED) <<
						((arrOfPins[local_uint8PinsCounter].PIN_ID)*2));
			}				
			else
			{	/* Reset the pin then write the required configuration*/
				GPIOB -> PUPDR  &= ~((0b11) <<
						((arrOfPins[local_uint8PinsCounter].PIN_ID)*2));
				GPIOB -> PUPDR  |=  ((arrOfPins[local_uint8PinsCounter].PULL_UP_DOWN) <<
						((arrOfPins[local_uint8PinsCounter].PIN_ID)*2));
			}
			break;
		case PORTC:
			/* Reset the pin then write the required configuration*/
			GPIOC -> MODER  &= ~((0b11) <<
					((arrOfPins[local_uint8PinsCounter].PIN_ID)*2));
			GPIOC -> MODER  |= ((arrOfPins[local_uint8PinsCounter].MODE) <<
					((arrOfPins[local_uint8PinsCounter].PIN_ID)*2));
			if(arrOfPins[local_uint8PinsCounter].MODE == OUTPUT)
			{	/* Reset the pin then write the required configuration*/
				GPIOC -> OTYPER  &= ~(1 << (arrOfPins[local_uint8PinsCounter].PIN_ID));
				GPIOC -> OTYPER  |=  ((arrOfPins[local_uint8PinsCounter].OTYPE) <<
						(arrOfPins[local_uint8PinsCounter].PIN_ID));

				GPIOC -> OSPEEDR  &= ~((0b11) <<
						((arrOfPins[local_uint8PinsCounter].PIN_ID)*2));
				GPIOC -> OSPEEDR  |=  ((arrOfPins[local_uint8PinsCounter].OSPEED) <<
						((arrOfPins[local_uint8PinsCounter].PIN_ID)*2));
			}				
			else
			{	/* Reset the pin then write the required configuration*/
				GPIOC -> PUPDR  &= ~((0b11) <<
						((arrOfPins[local_uint8PinsCounter].PIN_ID)*2));
				GPIOC -> PUPDR  |=  ((arrOfPins[local_uint8PinsCounter].PULL_UP_DOWN) <<
						((arrOfPins[local_uint8PinsCounter].PIN_ID)*2));
			}
			break;
		default:	
			Det_ReportError(DET_GPIOModuleId, GPIO_voidSetPinModeId, GPIO_invalidPortId);
			break;
		}
	}
}

void GPIO_voidSetPinValue(PORT_IDs_E portID,PIN_IDs_E pinID, uint8 value)
{
	if(GPIO_pinID < 31){
		switch(portID)
		{
			case PORTA:
				if(value == LOGIC_HIGH)
				{
					SET_BIT(GPIOA -> ODR, pinID);
				}
				else if(value == LOGIC_LOW)
				{
					CLR_BIT(GPIOA -> ODR, pinID);
				}
				else
				{
					Det_ReportError(DET_GPIOModuleId, GPIO_voidSetPinValueODRId, GPIO_invalidValueHighLowId);
				}
			break;
			case PORTB:
				if(value == LOGIC_HIGH)
				{
					SET_BIT(GPIOB -> ODR, pinID);
				}
				else if(value == LOGIC_LOW)
				{
					CLR_BIT(GPIOB -> ODR, pinID);
				}
				else
				{
					Det_ReportError(DET_GPIOModuleId, GPIO_voidSetPinValueODRId, GPIO_invalidValueHighLowId);
				}
			break;
			case PORTC:
				if(value == LOGIC_HIGH)
				{
					SET_BIT(GPIOC -> ODR, pinID);
				}
				else if(value == LOGIC_LOW)
				{
					CLR_BIT(GPIOC -> ODR, pinID);
				}
				else
				{
					Det_ReportError(DET_GPIOModuleId, GPIO_voidSetPinValueODRId, GPIO_invalidValueHighLowId);
				}
			break;
			default:
					Det_ReportError(DET_GPIOModuleId, GPIO_voidSetPinValueODRId, GPIO_invalidPortId);
			break;
		}
	}
	else
	{
		Det_ReportError(DET_GPIOModuleId, GPIO_voidSetPinValueODRId, GPIO_invalidPinId);
	}
	
}

uint8 GPIO_voidreadPinInfo(PORT_IDs_E GPIO_portId, PIN_IDs_E GPIO_pinID)
{
	if(GPIO_pinID < 31)
	{
		if(GPIO_portId >= 3 || GPIO_portId < 0)
		{
			Det_ReportError(DET_GPIOModuleId, GPIO_voidreadPinInfoId, GPIO_invalidPortId);
		}
		else
		{
			return GET_BIT(((*((GPIO_type *)0X40020000 + GPIO_portId * 0x400)).IDR), GPIO_pinID);
		}
	}
	else
	{
		Det_ReportError(DET_GPIOModuleId, GPIO_voidreadPinInfoId, GPIO_invalidPinId);
		return 0;
	}
}


