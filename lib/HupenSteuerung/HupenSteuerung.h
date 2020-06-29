/*  HupenSteuerung.h
 *	1.0, 2020-06-17
 *	
 *
 *	(C) 2020 IAS, Universitaet Stuttgart
 *	Author: Rouven Rischert
 */ 


#ifndef HUPENSTEUERUNG_H_
#define HUPENSTEUERUNG_H_


#include  <avr/io.h>
#include "GlobalDefinitions.h"
#include "RemoteControlDriver.h"


/********************************* Definitions ********************************/



/*********************************** Methods **********************************/

/* Component management */

/*
 * void HupenSteuerungInit(void)
 *
 * initialize the honk-component
 */
void HupenSteuerungInit(void);


/** Public **/

/*
 *
 * Makes the car Honk if the remote control gives the command to honk
*/

void Honk(void);

/** Private **/


#endif /* HUPENSTEUERUNG_H_ */