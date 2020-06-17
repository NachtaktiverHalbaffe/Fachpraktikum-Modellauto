/*  BlinkerSteuerung.c
 *	1.0, 2020-05-17
 *	
 *	(C) 2020 IAS, Universitaet Stuttgart
 *	Author: Felix Brugger
 */

/****************************** include files ******************************************/
#include  <avr/io.h>
#include  "GlobalDefinitions.h"
#include  "SonicDriver.h"

/****************************** end of include ****************************************/



/****************************** declaration of variables ******************************/
float mT=0; //Helper to store a current Time of an timer
int mD=0; //Helper to store a current Distance

/****************************** end of variables **************************************/



/****************************** implementation of functions ***************************/
void KollisionsUeberwachungInit(void){
    
}


float getVelocity(bool isDrivingBackwards){

}

void collisioncontrol(bool isDrivingBackwards){

}

/***************************** end of implementation **********************************/
