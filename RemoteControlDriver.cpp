/* 	Remote_Control_Driver.c
 *	1.0, 2020-05-17
 *	
 *		receives information from the remote control
 *		the following functions are implemented:
 *			- void RemoteTimerInit():
 *				initializes the timers for the 4 pwm channels of the remote control
 *			- void RemotePinInit():
 *				initializes the remote control pins
 *			- int GetRemotePWMSignal(char channel):
 *				reads the pwm value of the remote control channels:
 *				channel:	
 *					DRIVING_DIRECTION (= 0) , STEERING_DIRECTION (= 1)
 *					LIGHT_STATUS (= 2), HORN_STATUS (= 3)
 *				returns the pwm value, range: 500 - 1000 or explicit values
 *			- unsigned char GetDrivingDirection ()
 *				returns	the driving direction
 *					DRIVING_FORWARD (= 0) , DRIVING_REVERSE (= 1) 
 *					DRIVING_STAND (= 2)
 *			- unsigned char GetSteeringDirection()
 *				returns	the steering direction
 *					STEERING_LEFT (= 0) , STEERING_RIGHT (= 1)
 *					STEERING_AHEAD (= 2)
 *			- unsigned char GetLightSwitchStatus()
 *				returns	the status of the light switch
 *					LIGHT_OFF (= 0) , LIGHT_AUTOMATIC (= 1) 
 *					LIGHT_ON (= 2)
 *			- unsigned char GetHornSwitchStatus()
 *				 returns the status of the horn switch
 *					HORN_OFF (= 0) , HORN_ON (= 1)
 *
 *	(C) 2020 IAS, Universitaet Stuttgart
 *	Author: Alexander Laichinger
 */

/****************************** include files ******************************************/
#include 	<Arduino.h> 
#include	"GlobalDefinitions.h"
#include	"RemoteControlDriver.h"

/****************************** end of include ****************************************/



/****************************** declaration of variables ******************************/

int driving_value;
int steering_value;
int horn_status;

/****************************** end of variables **************************************/



/****************************** declaration of functions ******************************/

void RemotePinInit(void);
int GetRemoteSignal(char channel);
unsigned char GetDrivingDirection(void);
unsigned char GetSteeringDirection(void);
unsigned char GetLightSwitchStatus(void);
unsigned char GetHornSwitchStatus(void);

/****************************** end of functions **************************************/



/****************************** implementation of functions ***************************/



/*
 * void RemotePinInit(void)
 *
 * initialize the pins for the remote control
 */
void RemotePinInit(void) {
	pinMode(A0, INPUT_PULLUP);
	pinMode(A1, INPUT_PULLUP);
	pinMode(A2, INPUT_PULLUP);
	
}


/*
 * int GetRemotePWMSignal(char channel)
 *
 * parameter: select the channel of the remote control that should be returned
 *
 * return:	the newest value of the remote control channel
 *			the value is in general between 313 and 625
 */
int GetRemoteSignal(char channel) {
	int driving_return;
	int steering_return;
	int light_return;
	int horn_return;
	
	switch(channel) {
		case DRIVING_DIRECTION:			
			driving_return = analogRead(A5);
			
			// avoid disturbing signal effect by ignoring values next
			// to the middle position of the remote switch
			if(driving_return >= MIN_REVERSE && driving_return <= MIN_FORWARD) {
				driving_return = DRIVING_PWM_STAND;
			}
			
			return driving_return;
		break;
		
		case STEERING_DIRECTION:			
			steering_return = analogRead(A4);
			
			// avoid disturbing signal effect by ignoring values next
			// to the middle position of the remote switch
			if(steering_return >= MIN_LEFT && steering_return <= MIN_RIGHT) {
				steering_return = STEERING_SERVO_AHEAD;
			}

			return steering_return;
		break;
		
		case LIGHT_STATUS:
			if(digitalRead(A2) == LOW) {
				light_return = LIGHT_AUTOMATIC;
			}
			else if(digitalRead(A1) == LOW) {
				light_return = LIGHT_ON;
			}
			else {
				light_return = LIGHT_OFF;
			}

			return light_return;
		break;
		
		case HORN_STATUS:
			horn_return = HORN_OFF;
			
			if(digitalRead(A0) == LOW) {
				horn_return = HORN_ON;
			}
			else {
				horn_return = HORN_OFF;
			}

			return horn_return;
		break;

		default:
			// return -1 if an error has occurred
			return -1;
		break;
	}

	// return -1 if an error has occurred
	return -1;
}


/*
 * unsigned char GetDrivingDirection(void)
 *
 * return:	the driving direction
 *			(DRIVING_FORWARD = 0, DRIVING_REVERSE = 1, DRIVING_STAND = 2)
 */
unsigned char GetDrivingDirection(void) {
	driving_value = analogRead(A5);
	if(driving_value > MIN_FORWARD) {
		return DRIVING_FORWARD;
	}
	else if(driving_value < MIN_REVERSE) {
		return DRIVING_REVERSE;
	}
	else {
		return DRIVING_STAND;
	}
}


/*
 * unsigned char GetSteeringDirection(void)
 *
 * return:	the steering direction
 *			(STEERING_LEFT = 0, STEERING_RIGHT = 1, STEERING_AHEAD = 2)
 */
unsigned char GetSteeringDirection(void) {
	steering_value = analogRead(A4);
	if(steering_value < MIN_LEFT) {
		return STEERING_LEFT;
	}
	else if(steering_value > MIN_RIGHT) {
		return STEERING_RIGHT;
	}
	else {
		return STEERING_AHEAD;
	}
}


/*
 * unsigned char GetLightSwitchStatus(void)
 *
 * return:	the status of the light switch
 *			(LIGHT_OFF = 0, LIGHT_AUTOMATIC = 1, LIGHT_ON = 2)
 */
unsigned char GetLightSwitchStatus(void) {
	
	if(digitalRead(A2) == LOW) {
		return LIGHT_AUTOMATIC;
	}
	else if(digitalRead(A1) == LOW) {
		return LIGHT_ON;
	}
	else {
		return LIGHT_OFF;
	}
	
	return LIGHT_OFF;
}


/*
 * unsigned char GetHornSwitchStatus(void)
 *
 * return:	the status of the horn switch
 *			(HORN_OFF = 0, HORN_ON = 1)
 */
unsigned char GetHornSwitchStatus(void) {
	if(analogRead(A0) == LOW) {
		return HORN_ON;
	}
	else {
		return HORN_OFF;
	}
}


/***************************** end of implementation **********************************/
