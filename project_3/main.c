#include"dc_motor.h"
#include"timer0.h"
#include"std_types.h"
#include"lm35_sensor.h"
#include "lcd.h"
#include"adc.h"
int main() {
	uint8 temperature; /*variable to store the temperature */
	Timer_Config Timer_config = { FAST_PWM_MODE, NON_INVERTING_MODE,
			F_CPU_CLOCK_8 }; /* define the timer with PWM mode*/
	ADC_ConfigType Adc_config = { INTERNAL, F_CPU_8 };
	Timer0_init(&Timer_config); /* initialize the timer*/
	LCD_init(); /* initialize the LCD*/
	DcMotor_Init(); /* initialize the MOTOR*/
	ADC_init(&Adc_config); /* initialize the LCD*/
	LCD_moveCursor(0, 3);/* initialize the Cursor */
	LCD_displayString("FAN is ");
	LCD_moveCursor(1, 3);
	LCD_displayString("Temp =    C");
	while (1) {

		temperature = LM35_getTemperature(); /* read the temperature value and store it in temp. parameter*/
		if (temperature >= 120) {
			LCD_moveCursor(0, 10);
			LCD_displayString("ON ");
			LCD_moveCursor(1, 10);
			LCD_intgerToString(temperature);
			DcMotor_Rotate(CW, 100);
		} else if (temperature >= 100 && temperature < 120) {
			LCD_moveCursor(0, 10);
			LCD_displayString("ON ");
			LCD_moveCursor(1, 10);
			LCD_intgerToString(temperature);
			DcMotor_Rotate(CW, 75);
		} else if (temperature >= 90 && temperature < 100) {
			LCD_moveCursor(0, 10);
			LCD_displayString("ON ");
			LCD_moveCursor(1, 10);
			LCD_intgerToString(temperature);
			DcMotor_Rotate(CW, 75);
			LCD_displayCharacter(' ');
		} else if (temperature >= 60 && temperature < 90) {
			LCD_moveCursor(0, 10);
			LCD_displayString("ON ");
			LCD_moveCursor(1, 10);
			LCD_intgerToString(temperature);
			DcMotor_Rotate(CW, 50);
			LCD_displayCharacter(' ');
		} else if (temperature >= 30 && temperature < 60) {
			LCD_moveCursor(0, 10);
			LCD_displayString("ON ");
			LCD_displayCharacter(' ');
			LCD_moveCursor(1, 10);
			LCD_intgerToString(temperature);
			DcMotor_Rotate(CW, 25);
			LCD_displayCharacter(' ');
		} else {
			LCD_moveCursor(0, 10);
			LCD_displayString("OFF");
			LCD_moveCursor(1, 10);
			LCD_intgerToString(temperature);
			DcMotor_Rotate(STOP, 0);
			LCD_displayCharacter(' ');
		}

	}
}

