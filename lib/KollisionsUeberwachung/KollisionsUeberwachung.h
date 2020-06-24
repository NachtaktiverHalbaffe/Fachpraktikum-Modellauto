/*  KollisionsUeberwachung.h
 *	1.0, 2020-05-17
 *	
 *
 *	(C) 2020 IAS, Universitaet Stuttgart
 *	Author: Felix Brugger
 */ 


#ifndef KOLLISIONSUEBERWACHUNG_H_
#define KOLLISIONSUEBERWACHUNG_H_


#include  <avr/io.h>
#include "GlobalDefinitions.h"
#include "TimerDriver.h"


/********************************* Definitions ********************************/



/*********************************** Methods **********************************/

/* Component management */

/*
 * void KollisionsUeberwachungInit(void)
 *
 * initialize the component
 */
void KollisionsUeberwachungInit(void);

/** Public **/


/*
 * unsigned int ReadSonic(unsigned char channel)
 *
 * return: current velocity with velocity<0 for driving backwards
 */
float getVelocity(void);


/*
 * unsigned int ReadSonic(unsigned char channel)
 *
 * return: car is colliding (true) or not (false)
 */
bool collisioncontrol(void);

/** Private **/


#endif /* KOLLISIONSUEBERWACHUNG_H_ */