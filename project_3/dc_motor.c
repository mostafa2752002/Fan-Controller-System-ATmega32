/*
 * DC motor .c
 *
 *  Created on: Dec 24, 2023
 *      Author: Mustafa Taha
 */

#include"dc_motor.h"
#include"timer0.h"
#include"common_macros.h"
/*
 * Description :
 * setup the direction for the two
 * motor pins through the GPIO driver.
 * Stop at the DC-Motor at the beginning through the GPIO driver.
 */
void DcMotor_Init(void) {
	GPIO_setupPinDirection(DC_MOTOR_IN1_PORT_ID, DC_MOTOR_IN1_PIN_ID,
			PIN_OUTPUT);
	GPIO_setupPinDirection(DC_MOTOR_IN2_PORT_ID, DC_MOTOR_IN2_PIN_ID,
			PIN_OUTPUT);
	DcMotor_Rotate(STOP, 0);
}
/*
 * Description :
 * rotate the DC Motor CW/ or A-CW or
 * stop the motor based on the state input state value.
 * Send the required duty cycle to the PWM driver based on the
 * required speed value.
 */
void DcMotor_Rotate(DC_MOTOR_State state, uint8 speed) {
	switch (state) {
	case STOP:
		GPIO_writePin(DC_MOTOR_IN1_PORT_ID, DC_MOTOR_IN1_PIN_ID, LOGIC_LOW);
		GPIO_writePin(DC_MOTOR_IN2_PORT_ID, DC_MOTOR_IN2_PIN_ID, LOGIC_LOW);
		break;
	case CW:
		GPIO_writePin(DC_MOTOR_IN1_PORT_ID, DC_MOTOR_IN1_PIN_ID, LOGIC_LOW);
		GPIO_writePin(DC_MOTOR_IN2_PORT_ID, DC_MOTOR_IN2_PIN_ID, LOGIC_HIGH);
		break;
	case ACW:
		GPIO_writePin(DC_MOTOR_IN1_PORT_ID, DC_MOTOR_IN1_PIN_ID, LOGIC_HIGH);
		GPIO_writePin(DC_MOTOR_IN2_PORT_ID, DC_MOTOR_IN2_PIN_ID, LOGIC_LOW);
		break;
	}
	Timer0_PWM_Start(speed);
}

