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
float velocity = 0.0;

/****************************** end of variables **************************************/



/****************************** implementation of functions ***************************/
void KollisionsUeberwachungInit(void){

}


float getVelocity(void){
if(TimerDriver.getTime()==0){
    TimerDriver.startTimer();
    // Determing that front sonic isnt out of range, otherwise using back sensor
    if(SonicDriver.ReadSonic(1)<510){
    // Storing actual distance in Helper for future iterations
       mD= SonicDriver.ReadSonic(0)/100; 
    } else mD= SonicDriver.ReadSonic(1)/100;
    return velocity;
} else{
    if(mT != 0){
        // Determing that front sonic isnt out of range, otherwise using back sensor
        if(SonicDriver.ReadSonic(1)<510){
            // Storing actual distance in Helper for future iterations
            mD= SonicDriver.ReadSonic(0)/100; 
        } else mD= SonicDriver.ReadSonic(1)/100;
        // Storing actual time in Helper for future iterations
        mT= TimerDriver.getTime()/1000;
        return velocity;
    } else{
        //calculating the time since last measurement and storing afterwards new actual time in helper for next iteration 
        long delta_time = TimerDriver.getTime() - mT;
        mT = TimerDriver.getTime();
        int delta_distance = 0;
        // Determing that front sonic isnt out of range, otherwise using back sensor
        if(SonicDriver.ReadSonic(1)<510){
            // Calculating driven distance since last measurement and storing actual distance in helper for next iteration
            delta_distance = SonicDriver.ReadSonic(0)/100 - mD; 
        } else delta_distance = SonicDriver.ReadSonic(1)/100 -mD;
        // calculating velocity and returning it
        velocity = delta_distance/delta_time;
        return velocity;
    }
}

}

bool collisioncontrol(bool isDrivingBackwards){
int distance = 0;
// get Distance from Sensor (in m)
if(isDrivingBackwards){
 distance= SonicDriver.ReadSonic(0)/100;
} else distance= SonicDriver.ReadSonic(1)/100;
//get Velocity
velocity = getVelocity(isDrivingBackwards);

/* Deciding if a collision is coming depending on current velocity and distance 
 * assuming  acceleration is 2 m/s^2 und t(time) to react 100ms
 *  distance = 0.5 * acceleration * t^2 +v *t = 0,01 + v *0,1
 *  => collision is coming when distance <= 0,01 +  velocity * 0,1  
 */
if( distance <= 0,01 + velocity * 0,1 ){
 return true;
} else return false;

}

/***************************** end of implementation **********************************/
