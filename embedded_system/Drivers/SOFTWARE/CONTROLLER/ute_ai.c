#include "ute_ai.h"
/*********************/
uint8_t status=0;
double count = 0;

/*********************/
void Run(esc *Esc, servo *Servo, int16_t speed, int8_t angle) {
	/*********** Reverse Mode ***********/
	if (speed < 0 && count<=1000) {		
		while (count <= 500) {
			TIM3->CCR2 = 70;
			count += 0.001;	
		}
		
		while (count >= 500 && count <= 1000) {
			TIM3->CCR2 = 100;
			count += 0.001;	
		}
	}
	else if (speed > 0) count=0;
	
	/*********** Controller ***********/
	ESC_Run(Esc, speed);
	SERVO_Run(Servo, angle);
}
