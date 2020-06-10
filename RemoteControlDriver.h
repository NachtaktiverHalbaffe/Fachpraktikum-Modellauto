/* 	RemoteControlDriver.h
 *	1.0, 2020-05-17
 *	
 *		the header for the remote control driver
 *
 *	(C) 2020 IAS, Universitaet Stuttgart
 *	Author: Alexander Laichinger
 */


#ifndef REMOTECONTROLDRIVER_H_
#define REMOTECONTROLDRIVER_H_


#include <Arduino.h> 
#include "GlobalDefinitions.h"

/********************************* Definitions ********************************/

#define DRIVING_FORWARD			0x00
#define DRIVING_REVERSE			0x01
#define DRIVING_STAND			0x02

#define STEERING_LEFT			0x00
#define STEERING_RIGHT			0x01
#define STEERING_AHEAD			0x02

#define DRIVING_PWM_STAND		 512
#define STEERING_PWM_AHEAD		 512



/*********************************** Methods **********************************/


/** Public **/
void RemotePinInit(void);
int GetRemoteSignal(char channel);
unsigned char GetDrivingDirection(void);
unsigned char GetSteeringDirection(void);
unsigned char GetLightSwitchStatus(void);
unsigned char GetHornSwitchStatus(void);

/** Private **/

#endif /* REMOTECONTROLDRIVER_H_ */