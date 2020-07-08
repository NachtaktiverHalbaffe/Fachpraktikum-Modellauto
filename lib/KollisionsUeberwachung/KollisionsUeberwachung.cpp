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
float velocity = 0.0; //Last measured velocity
bool isInRange = false; //bool for velocity measurement which is true when both sensors are out of ranche and old values are returned; 
                        //Falls eine Fehlererkennung drinnen gewesen wäre (worauf aufgrund der Testbarkeit in SimulIDE verzichtet wurde), wäre der Tag auch bei der Annahme von fehlerhaften Geschwindigkeiten aufgrund von Streueffekten o.ä. auf false gesetzt worden
/****************************** end of variables **************************************/


/****************************** implementation of functions ***************************/
float getVelocity(void){
    if(mT == 0){
        Serial.println("No buffered time");
        // Determing that front sonic isnt out of range, otherwise using back sensor or dont change last value
        if(ReadSonic(1)<490){
            // Storing actual distance in Helper for future iterations
            mD= (float)ReadSonic(0)/100; 
            isInRange= true;
        } else if(ReadSonic(0)<490){
            mD= (float)ReadSonic(1)/100;
            isInRange= true;
            }
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
        // Calculating driven distance since last measurement and storing actual distance in helper for next iteration
        if(ReadSonic(0)<490){
            //using front sensor for measurent if it isnt out of range 
            delta_distance = mD - (float)ReadSonic(0)/100 ; 
            mD= (float)ReadSonic(0)/100;
        } else if(ReadSonic(1)<490) {
            delta_distance = (float)ReadSonic(1)/100 - mD ;
            mD= (float)ReadSonic(1)/100;
            }
        else {
            // Both sensors out of range => returning last stored velocity
            Serial.println("Error: Both Sonars out of range. Returning last value.");
            isInRange= false;
            return velocity;
        }
        // calculating velocity and returning it
        velocity = delta_distance/delta_time;
        Serial.println("");
        Serial.print("Velocity: ");
        Serial.print(velocity);
        isInRange= true;
        return velocity;
    }


}

bool collisioncontrol(bool isDrivingBackwards){
float distance = 0;
// get Distance from Sensor (in m)
if(isDrivingBackwards){
 distance= (float)ReadSonic(1)/100;
} else distance= (float)ReadSonic(0)/100;
//get Velocity
velocity = getVelocity();

/* Deciding if a collision is coming depending on current velocity and distance 
 * assuming  acceleration is 2 m/s^2 und t(time) to react 100ms
 *  distance = 0.5 * acceleration * t^2 +v *t = 0,01 + v *0,1
 *  => collision is coming when distance <= 0,01 +  velocity * 0,1  
 */
//collision appearing on driving mode and if sensors are in range and velocity values legit and no old returned ones
if( (distance <= (0.01 + abs(velocity) * 0.1)) && velocity !=0 && isInRange){
    Serial.println("");
    Serial.println("Warning: Collision appearing");
    return true;
} 
//Car is standing in front of a wall
else if(distance <= 0.2){
    Serial.println("");
    Serial.println("Warning: Standing in front of a wall");
    return true;
} else return false;

}

//simple getter
bool getIsInRange(void){
    return isInRange;
}
/***************************** end of implementation **********************************/
