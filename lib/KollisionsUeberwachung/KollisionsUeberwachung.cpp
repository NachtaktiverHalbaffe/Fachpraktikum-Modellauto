/*  BlinkerSteuerung.c
 *	1.0, 2020-05-17
 *	
 *	(C) 2020 IAS, Universitaet Stuttgart
 *	Author: Felix Brugger
 */

/****************************** include files ******************************************/
#include  <avr/io.h>
#include  "GlobalDefinitions.h"

/****************************** end of include ****************************************/



/****************************** declaration of variables ******************************/
float mT=0; //Helper to store a current Time of an timer
int mD=0; //Helper to store a current Distance
const float threshHold= 0.5;

/****************************** end of variables **************************************/



/****************************** implementation of functions ***************************/
void KollisionsUeberwachungInit(void){
    TCCR1A = 0;
    TCCR1B = 0;
    TCCR1B |= (1<<CS10); //prescaler 1
    TIMSK1 |=(1<<TOIE1); // enable timer overflow
}


float getVelocity(bool isDrivingBackwards){

}

bool collisioncontrol(bool isDrivingBackwards){
int distance = 0;
float velocity = 0.0;

// get Distance from Sensor (in m)
if(isDrivingBackwards){
 distance= SonicDriver.ReadSonic(0)/100;
} else distance= SonicDriver.ReadSonic(1);
//get Velocity
velocity = getVelocity(isDrivingBackwards);

/* Deciding if a collision is coming depending on current velocity and distance 
 * assuming  acceleration is 4 m/s^2 und t(time) 100ms
 *  s=0.5 * acceleration  t^2 +v *t = 0,02 + v *0,1
 *  => collision is coming when distance<= 0,02 +  velocity * 0,1  
 */
if( distance <= 0,02 + velocity * 0,1 ){
 return true;
} else return false;

}

/***************************** end of implementation **********************************/
