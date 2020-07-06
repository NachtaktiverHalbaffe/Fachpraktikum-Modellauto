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
#include "SonicDriver.h"
#include <stdlib.h>



/********************************* Definitions ********************************/



/*********************************** Methods **********************************/

/* Component management */

/** Public **/


/*
 * unsigned int ReadSonic(unsigned char channel)
 *
 * return: current velocity with velocity < 0 for driving backwards
 * 
 * Hinweis: Zur Geschwindigkeitsermittlung werden die Frontsensoren primär benutzt (außer der Sensor ist out of Range). 
 * Theoretisch hätten die Werte aus beiden Sensoren verglichen und bei zu großen Unterschied anhand von anderen Fahrdaten die 
 * zuverlässigste Geschwindigkeit wählen sollen. 
 * Da in der Simulation praktisch die Geschwindigkeiten immer sehr weit auseinander liegen, da man nicht beide Sonare gleichzeitig 
 * in der gleichen Geschwindigkeit bedienen kann, und generell die Input-Daten sich nicht so verhalten wie in der Realität (wenn 
 * der Antrieb z.B. auf vorwärts eingestellt wird wird verändern sich die Sonare nicht analog dazu usw), wurde auf eine solche 
 * Fehlererkennung verzichtet, um Probleme bei der Simulation bzw der Präsentation der Simulation zu vermeiden.
 */
float getVelocity(void);


/*
 * unsigned int ReadSonic(unsigned char channel)
 * 
 * argument: if car is driving backwards that the collisiomncontrol uses the back sensor
 *
 * return: car is colliding (true) or not (false)
 */
bool collisioncontrol(bool isDrivingBackwards);

/** Private **/


#endif /* KOLLISIONSUEBERWACHUNG_H_ */