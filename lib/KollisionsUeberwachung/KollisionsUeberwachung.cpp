/*  BlinkerSteuerung.c
 *	1.0, 2020-05-17
 *	
 *	(C) 2020 IAS, Universitaet Stuttgart
 *	Author: Felix Brugger
 */

/****************************** include files ******************************************/
#include  <avr/io.h>
#include  "GlobalDefinitions.h"
#include  "KollisionsUeberwachung.h"


/****************************** end of include ****************************************/



/****************************** declaration of variables ******************************/
float mT=0; //Helper to store a current Time of an timer
float mD=0; //Helper to store a current Distance
float velocity = 0.0;

/****************************** end of variables **************************************/



/****************************** implementation of functions ***************************/
float getVelocity(void){
    if(mT == 0){
        Serial.println("No buffered time");
        // Determing that front sonic isnt out of range, otherwise using back sensor
        if(ReadSonic(1)<510){
            // Storing actual distance in Helper for future iterations
            mD= ReadSonic(0)/100; 
        } else mD= ReadSonic(1)/100;
        // Storing actual time in Helper for future iterations
        mT= getTime();
        return velocity;
    } else{
        //calculating the time since last measurement and storing afterwards new actual time in helper for next iteration 
        float delta_time = getTime() - mT;
        //exiting measurment if time period isnt biug enough
        if(delta_time< 0.1){
            return velocity;
        }
        mT = getTime();
        float delta_distance = 0;
        // Determing that front sonic isnt out of range, otherwise using back sensor
        if(ReadSonic(0)<510){
            // Calculating driven distance since last measurement and storing actual distance in helper for next iteration
            delta_distance = mD -ReadSonic(0)/100 ; 
            mD= ReadSonic(0)/100;
        } else {
            delta_distance = ReadSonic(1)/100 -mD;
            mD= ReadSonic(1)/100;
            }
        // calculating velocity and returning it
        velocity = delta_distance/delta_time;
        Serial.println("");
        Serial.print("Velocity: ");
        Serial.print(velocity);
        return velocity;
    }


}

bool collisioncontrol(bool isDrivingBackwards){
float distance = 0;
// get Distance from Sensor (in m)
if(isDrivingBackwards){
 distance= ReadSonic(0)/100;
} else distance= ReadSonic(1)/100;
//get Velocity
velocity = getVelocity();

/* Deciding if a collision is coming depending on current velocity and distance 
 * assuming  acceleration is 2 m/s^2 und t(time) to react 100ms
 *  distance = 0.5 * acceleration * t^2 +v *t = 0,01 + v *0,1
 *  => collision is coming when distance <= 0,01 +  velocity * 0,1  
 */

if( distance <= (0.01 + velocity * 0.1) ){
    Serial.println("");
    Serial.println("Warning: Collision appearing");
 return true;
} else return false;

}

/***************************** end of implementation **********************************/
