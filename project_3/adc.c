/*
 * adc.c
 *
 *  Created on: Dec 24, 2023
 *      Author: Mustafa Taha
 */

#include "avr/io.h" /* To use the ADC Registers */
#include "adc.h"
#include "common_macros.h" /* To use the macros like SET_BIT */

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

void ADC_init(const ADC_ConfigType * Config_Ptr)
{
	/*set the prescaler and the mode of ADC based of the given value*/
	ADMUX=(ADMUX&0x3f)|(Config_Ptr->ref_volt<<6);
	SET_BIT(ADCSRA, ADEN); /*Enable ADC*/
	CLEAR_BIT(ADCSRA, ADIE); /*Disable interrupt*/
	ADCSRA = (ADCSRA & 0xF8) | (Config_Ptr->prescaler); /*set prescaler based on given value*/
}

uint16 ADC_readChannel(uint8 channel_num)
{
	/* clear the first 5 bits  MUX4:0: ,and then set the initial value based on passed value */
	ADMUX = (ADMUX & 0xe0) | (channel_num & 0x0f);
	SET_BIT(ADCSRA,ADSC); /* Start conversion write '1' to ADSC */
	while(BIT_IS_CLEAR(ADCSRA,ADIF)); /* Wait for conversion to complete, ADIF becomes '1' */
	SET_BIT(ADCSRA,ADIF); /* Clear ADIF by write '1' to it :) */
	return ADC; /* Read the digital value from the data register */
}

