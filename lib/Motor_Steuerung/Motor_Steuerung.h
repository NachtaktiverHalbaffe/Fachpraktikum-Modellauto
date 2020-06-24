/*  Motor_Steuerung.h
 *	1.0, 2020-06-17
 *	
 *
 *	(C) 2020 IAS, Universitaet Stuttgart
 *	Author: Rouven Rischert
 */ 


#ifndef MOTOR_STEUERUNG_H_
#define MOTOR_STEUERUNG_H_


#include  <avr/io.h>
#include "GlobalDefinitions.h"
#include "MotorDriver.h"
#include "RemoteControlDriver.h"
#include "KollisionsUeberwachung.h"
#include "ServoDriver.h"


/********************************* Definitions ********************************/



/*********************************** Methods **********************************/

/* Component management */

/** Public **/

/*
 * void drive(void)
 *
 * initialize the drive function
 */
void drive(void);


/*
 * void steer(void)
 *
 * initialize the steer function
 */
void steer(void);


/** Private **/


#endif /* MOTOR_STEUERUNG_H_ */