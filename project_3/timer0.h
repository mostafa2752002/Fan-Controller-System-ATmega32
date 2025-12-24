/*
 * timer0.h
 *
 *  Created on: Dec 24, 2023
 *      Author: Mustafa Taha
 */

#ifndef TIMER0_H_
#define TIMER0_H_
#include "std_types.h"

/*********************************** Timer0 Registers Definitions ******************************/
#define TCNT0_REG     (*(volatile Timer0_TCNT0_Type*)0x52)
#define TCCR0_REG    (*(volatile Timer0_TCCR0_Type*)0x53)
#define OCR0_REG    (*(volatile Timer0_OCR0_Type*)0x5C)

/***********************************************************************************************/

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define TIMER0_MAX_VALUE 255
/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
typedef enum {
	NORMAL_MODE, COMPARE_MODE, FAST_PWM_MODE
} Timer_Mode;
typedef enum {
	NORMAL_PORT = 0, NON_INVERTING_MODE = 2, INVERTING_MODE = 3
} PWM_Mode;
typedef enum {
	NO_CLOCK,
	F_CPU_CLOCK,
	F_CPU_CLOCK_8,
	F_CPU_CLOCK_64,
	F_CPU_CLOCK_256,
	F_CPU_CLOCK_1024
} Timer_Clock;
typedef struct {
	Timer_Mode timer_mode;
	PWM_Mode pwm_mode;
	Timer_Clock clock;
} Timer_Config;

typedef union {
	uint8 Byte;
	struct{
		uint8 CS00_Bit:1;
		uint8 CS01_Bit:1;
		uint8 CS02_Bit:1;
		uint8 WGM01_Bit:1;
		uint8 COM00_Bit:1;
		uint8 COM01_Bit:1;
		uint8 WGM00_Bit:1;
		uint8 FOC0_Bit:1;
	}Bits;
}Timer0_TCCR0_Type;

typedef union {
	uint8 Byte;
	struct{
		uint8 Bit0:1;
		uint8 Bit1:1;
		uint8 Bit2:1;
		uint8 Bit3:1;
		uint8 Bit4:1;
		uint8 Bit5:1;
		uint8 Bit6:1;
		uint8 Bit7:1;
	}Bits;
}Timer0_TCNT0_Type;
typedef union {
	uint8 Byte;
	struct{
		uint8 Bit0:1;
		uint8 Bit1:1;
		uint8 Bit2:1;
		uint8 Bit3:1;
		uint8 Bit4:1;
		uint8 Bit5:1;
		uint8 Bit6:1;
		uint8 Bit7:1;
	}Bits;
}Timer0_OCR0_Type;


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/*
 * Description :
 * Function responsible for initialize the TIMER_0 driver.
 */
void Timer0_init(const Timer_Config *Config_Ptr);
 /*
  * Description :
  *  Setup the compare value based on the required input duty cycle.
  */
void Timer0_PWM_Start(uint8 duty_cycle_percentage);
/*
 * Description :
 * Function responsible for De_initialize the TIMER_0 driver.
 */
void TIMER0_deinit();
#endif /* TIMER0_H_ */
