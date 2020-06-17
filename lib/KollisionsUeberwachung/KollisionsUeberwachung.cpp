/*  Sonic_Driver.c
 *	1.0, 2020-05-17
 *	
 *		controls the sonic sensors
 *		the following functions are implemented:
 *			- void SonicPinInit():
 *				initializes the sonic sensor pins
 *			- int ReadSonic(unsigned char channel):
 *				reads the sonic sensor value:
 *					FRONT_SONIC (= 0) / REAR_SONIC (= 1)
 *				returns the distance value, range: 0-400 (in cm)
 *
 *	(C) 2020 IAS, Universitaet Stuttgart
 *	Author: Alexander Laichinger
 */

/****************************** include files ******************************************/
#include  <avr/io.h>
#include  "GlobalDefinitions.h"
#include  "SonicDriver.h"

/****************************** end of include ****************************************/



/****************************** declaration of variables ******************************/


/****************************** end of variables **************************************/



/****************************** implementation of functions ***************************/
void KollisionsUeberwachungInit(void){
    
}


float getVelocity(bool isDrivingBackwards){

}

void collisioncontrol(bool isDrivingBackwards){

}

/***************************** end of implementation **********************************/
