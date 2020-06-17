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


/********************************* Definitions ********************************/



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
 * unsigned int blink(bool isBlinking)
 *
 * params: bool that says that the car is steering and the car has to blink 
 *  
 */
void blink(bool isBlinking);

/** Private **/


#endif /* BLINKERSTEUERUNG_H_ */