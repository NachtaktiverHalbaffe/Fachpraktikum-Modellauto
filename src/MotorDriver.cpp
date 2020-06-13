/*  Motor_Driver.c
 *	1.0, 2020-05-17
 *	
 *		communicates with the external motor driver via spi
 *		the following functions are implemented:
 *			- void MotorDriverInit():
 *				initialize the external motor driver
 *			- void MotorBreak():
 *				orders the motor driver to break
 *			- void MotorIdle():
 *				orders the motor driver to go to idle state
 *			- void MotorEnable(void):
 *				the motor can only be used after sending an enable order
 *			- void DriveForward(int forward_value):
 *				orders the motor driver to drive forwards with a speed value
 *				between 510 (max) and 255 (stand)
 *			- void DriveReverse(int reverse_value):
 *				orders the motor driver to drive reverse with a speed value
 *				between 0 (max) and 255 (stand)
 *
 *	(C) 2020 IAS, Universitaet Stuttgart
 *	Author: Alexander Laichinger
 */

/****************************** include files ******************************************/

#include	"GlobalDefinitions.h"
#include	"MotorDriver.h"

/****************************** end of include ****************************************/



/****************************** declaration of variables ******************************/

/****************************** end of variables **************************************/



/****************************** declaration of functions ******************************/

void MotorDriverInit(void);
void MotorBreak(void);
void MotorIdle(void);
void DriveForward(int forward_value);
void DriveReverse(int reverse_value);


/****************************** end of functions **************************************/



/****************************** implementation of functions ***************************/

/*
 * void MotorDriverInit(void):
 *
 * initialize the external motor driver
 */
void MotorDriverInit(void) {
	pinMode(MOTOR_FORWARD_PIN, OUTPUT);
	pinMode(MOTOR_REVERSE_PIN, OUTPUT);
}


/*
 * void MotorBreak():
 *
 * orders the motor driver to break
 */
void MotorBreak(void) {
	analogWrite(MOTOR_FORWARD_PIN, 0);
	analogWrite(MOTOR_REVERSE_PIN, 0);	
}


/*
 * void MotorIdle():
 *
 * orders the motor driver to go to idle state
 */
void MotorIdle(void) {
	analogWrite(MOTOR_FORWARD_PIN, 0);
	analogWrite(MOTOR_REVERSE_PIN, 0);
}


/*
 * void DriveForward(int forward_value):
 *				
 * orders the motor driver to drive forwards with a speed value between 510 (max) and 255 (stand)
 * if you call driveForeward the output at the Pin of driveReverse will be set to 0
 */
void DriveForward(int forward_value) {
	// cannot drive reverse at the same time
	analogWrite(MOTOR_REVERSE_PIN, 0);	
	// ensure that value is in the right range
	if(forward_value > PWM_MAX_FORWARD) {
		forward_value = PWM_MAX_FORWARD;
	}
	else if(forward_value < PWM_STAND) {
		forward_value = PWM_STAND;
	}
	
	// convert value to the motor driver range: 0 - 255
	forward_value = (forward_value - PWM_STAND );
	analogWrite(MOTOR_FORWARD_PIN, forward_value);
}

/*
 * void DriveReverse(int reverse_value):
 *
 * orders the motor driver to drive reverse with a speed value between 0 (max) and 255 (stand)
 * if you call driveReverse the output at the Pin of driveForward will be set to 0
 */
void DriveReverse(int reverse_value) {
	// cannot drive foreward at the same time
	analogWrite(MOTOR_FORWARD_PIN, 0);
	// ensure that value is in the right range
	if(reverse_value > PWM_STAND) {
		reverse_value = PWM_STAND;
	}
	else if(reverse_value < PWM_MAX_REVERSE) {
		reverse_value = PWM_MAX_REVERSE;
	}
	
	// convert value to the motor driver range: 0 - 255
	reverse_value = (PWM_STAND - reverse_value);
	analogWrite(MOTOR_REVERSE_PIN, reverse_value);
	
}



/***************************** end of implementation **********************************/

