/*  MotorDriver.h
 *	1.0, 2020-05-17
 *	
 *		the header for the motor driver
 *
 *	(C) 2020 IAS, Universitaet Stuttgart
 *	Author: Alexander Laichinger
 */ 


#ifndef MOTORDRIVER_H_
#define MOTORDRIVER_H_


#include <Arduino.h> 
#include "GlobalDefinitions.h"


/********************************* Definitions ********************************/



#define PWM_STAND					 255


/*********************************** Methods **********************************/

/* Component management */
void MotorDriverInit(void);

/** Public **/
void MotorBreak(void);
void MotorIdle(void);
void DriveForward(int forward_value);
void DriveReverse(int reverse_value);

/** Private **/


#endif /* MOTORDRIVER_H_ */