/*
 *DC MOTOR.h
 *
 *  Created on: Dec 24, 2023
 *      Author: Mustafa Taha
 */

#ifndef DCMOTOR_H_
#define DCMOTOR_H_
#include"std_types.h"
#include "gpio.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define DC_MOTOR_IN1_PORT_ID       PORTB_ID
#define DC_MOTOR_IN1_PIN_ID        PIN0_ID
#define DC_MOTOR_IN2_PORT_ID       PORTB_ID
#define DC_MOTOR_IN2_PIN_ID        PIN1_ID
/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
typedef enum DC_MOTOR_State {
	STOP, CW, ACW
} DC_MOTOR_State;
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/*
 * Description :
 * setup the direction for the two
 * motor pins through the GPIO driver.
 * Stop at the DC-Motor at the beginning through the GPIO driver.
 */
void DcMotor_Init(void);
/*
 * Description :
 * rotate the DC Motor CW/ or A-CW or
 * stop the motor based on the state input state value.
 * Send the required duty cycle to the PWM driver based on the
 * required speed value.
 */
void DcMotor_Rotate(DC_MOTOR_State state, uint8 speed);
#endif /* DCMOTOR_H_ */
