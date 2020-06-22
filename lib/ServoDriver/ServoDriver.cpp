/*  Servo_Driver.c
 *	1.0, 2020-05-17
 *	
 *		controls the servos for the steering and the distance sensors
 *		the following functions are implemented:
 *			- void ServoPWMInit():
 *				initializes the pwm channels for the servos
 *			- void SetSteeringPWM(int value):
 *				set the pwm value for the steering servos
 *				value: range 30 (max left) - 150 (max right)
 *			- void SetSensorPWM(int value):
 *				set the pwm value for the sensor servos
 *				value: range 30 (max left) - 150(max right)
 *
 *	(C) 2020 IAS, Universitaet Stuttgart
 *	Author: Alexander Laichinger
 */

/****************************** include files ******************************************/

#include	"GlobalDefinitions.h"
#include	"ServoDriver.h"
#include	<Servo.h>

/****************************** end of include ****************************************/



/****************************** declaration of variables ******************************/
Servo servosteer; // create servo object to control a servo
Servo servosensor;


/****************************** end of variables **************************************/



/****************************** declaration of functions ******************************/
/****************************** end of functions **************************************/



/****************************** implementation of functions ***************************/

/*
 * void ServoPWMInit(void)
 *
 * initialize the pwm generation for the steering and sensor servo
 */
void ServoInit(void) {
	servosensor.attach( SENSOR_SERVO_PIN, 1000, 2000 );  // attaches the servo on SENSOR_SERVO_PIN to the servo object
	servosteer.attach( STEERING_SERVO_PIN, 1000, 2000 );
}


/*
 * void SetSteeringPWM(int value)
 *
 * set the pwm value for the steering servos 
 * value: range 30 (max left) - 150 (max right)
 */
void SetSteering(int value) {
	// ensure that value is in the right range
	if(value < STEERING_SERVO_MAX_LEFT) {
		value = STEERING_SERVO_MAX_LEFT;
	}
	else if(value > STEERING_SERVO_MAX_RIGHT) {
		value = STEERING_SERVO_MAX_RIGHT;
	}
	
	servosteer.write(value);
}


/*
 * void SetSensorPWM(int value)
 *
 * set the pwm value for the sensor servos
 * value: range 30 (max left) - 150 (max right)
 */
void SetSensor(int value) {
	// ensure that value is in the right range	
	if(value < SENSOR_SERVO_MAX_LEFT) {
		value = SENSOR_SERVO_MAX_LEFT;
	}
	else if(value > SENSOR_SERVO_MAX_RIGHT) {
		value = SENSOR_SERVO_MAX_RIGHT;
	}	
	
	servosensor.write(value);
}



/***************************** end of implementation **********************************/
