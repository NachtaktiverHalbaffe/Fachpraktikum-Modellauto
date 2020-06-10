/*  ServoDriver.h
 *	1.0, 2020-05-17
 *	
 *		the header for the servo driver
 *
 *	(C) 2020 IAS, Universitaet Stuttgart
 *	Author: Alexander Laichinger
 */ 


#ifndef SERVODRIVER_H_
#define SERVODRIVER_H_


#include <Arduino.h> 
#include "GlobalDefinitions.h"
#include	<Servo.h>


/********************************* Definitions ********************************/

#define SENSOR_SERVO_MAX_LEFT			30
#define SENSOR_SERVO_MAX_RIGHT			150

#define STEERING_SERVO_MAX_LEFT			30
#define	STEERING_SERVO_MAX_RIGHT		150


/*********************************** Methods **********************************/

//uses Timer 1

/* Component management */
void ServoInit(void);

/** Public **/
void SetSteering(int value);
void SetSensor(int value);

/** Private **/


#endif /* SERVODRIVER_H_ */