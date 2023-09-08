/********************************************************************************
* @File Name: GPIO_private.h
*
* @Author   : Ahmed Hossam
*
* @Data     : 16 - 8 - 2022
*
* @Brief    : Header file for ARM (STM32F4xx) GPIO driver registers.
*
* @version	: 1.0.2
***********************************************************************************/
#ifndef GPIO_PRIVATE
#define GPIO_PRIVATE

#define GPIOA_BASE_ADDRESS   0x40020000
#define GPIOB_BASE_ADDRESS   0x40020400
#define GPIOC_BASE_ADDRESS   0x40020800

/* Description:
*	The register of GPIO driver from the manual
*/
typedef struct
{
	uint32 MODER;				/* GPIO mode port register 			*/
	uint32 OTYPER;              /* GPIO port output type register 	*/
	uint32 OSPEEDR;             /* GPIO output speed register 		*/
	uint32 PUPDR;               /* GPIO port pull up/down register 	*/
	uint32 IDR;                 /* GPIO port input data register 	*/
	uint32 ODR;                 /* GPIO port outport data register 	*/
	uint32 BSRR;				/* GPIO port Bit set/reset register */
	uint32 LCKR;
	uint32 AFRL;
	uint32 AFRH;
}GPIO_type;

#define GPIOA ((GPIO_type*)GPIOA_BASE_ADDRESS)
#define GPIOB ((GPIO_type*)GPIOB_BASE_ADDRESS)
#define GPIOC ((GPIO_type*)GPIOC_BASE_ADDRESS)

#define NOT_USED  255

typedef enum
{
	PORTA,
	PORTB,
	PORTC
}PORT_IDs_E;

typedef enum
{
	PIN0  ,
	PIN1  ,
	PIN2  ,
	PIN3  ,
	PIN4  ,
	PIN5  ,
	PIN6  ,
	PIN7  ,
	PIN8  ,
	PIN9  ,
	PIN10 ,
	PIN11 ,
	PIN12 ,
	PIN13 ,
	PIN14 ,
	PIN15
}PIN_IDs_E;

typedef enum
{
	INPUT,
	OUTPUT,
	AF,
	ANALOG
}MODE_IDs_E;

typedef enum
{
	PUSH_PULL,
	OPEN_DRAIN
}TYPE_IDs_E;

typedef enum
{
    LOW_SPEED,
    MEDIUM_SPEED,
    HIGH_SPEED,
    VERY_HIGH_SPEED	
}SPEED_IDs_E;

typedef enum
{
	FLOATING,
	PULL_UP,
	PULL_DOWN
}INPUT_TYPE_IDs_E;

typedef enum
{
	LOW, HIGH
}PIN_STATE_E;

#endif
