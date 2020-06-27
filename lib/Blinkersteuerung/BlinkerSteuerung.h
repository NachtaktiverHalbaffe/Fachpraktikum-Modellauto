/*  BlinkerSteuerung.h
 *	1.0, 2020-06-17
 *	
 *
 *	(C) 2020 IAS, Universitaet Stuttgart
 *	Author: Felix Brugger
 */ 


#ifndef BLINKERSTEUERUNG_H_
#define BLINEKRSTEUERUNG_H_


#include  <avr/io.h>
#include "GlobalDefinitions.h"
#include "TimerDriver.h"
#include "RemoteControlDriver.h"


/********************************* Definitions ********************************/
#define BLINKER_RECHTS 0 // PORTB0
#define BLINKER_LINKS 3 // PORTB3
#define BLINK_TIME 0.5 // Time in seconds how long is one blink

/*********************************** Methods **********************************/

/* Component management */

/*
 * void BlinkerSteuerungInit(void)
 *
 * initialize the component
 */
void BlinkerSteuerungInit(void);

/** Public **/

/*
 * void blink(bool isBlinking)
 *
 * params: bool that says that the car is steering and the car has to blink 
 *  
 */
void blink(void);

/** Private **/

/*
 * void setBlinkingDirection(void)
 *
 * sets blinking on right or left side depending on steering direction
 * 
 */
void setBlinkingDirection(void);

/*
 * void blink(bool isBlinking)
 *
 * turns off all blinker
 * 
 */
void turnBlinkerOff(void);


#endif /* BLINKERSTEUERUNG_H_ */