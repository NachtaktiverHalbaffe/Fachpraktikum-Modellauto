/*  HupenSteuerung.c
 *	1.0, 2020-06-17
 *	    
 *
 *      controls the honk:
 *      the following functions are implemented:
 *          - HupenSteuerungInit():
 *              initialize the honk-pin
 *          - honk(doHonking)
 *              orders the Honk-Component to honk
 * 
 *		
 *
 *	(C) 2020 IAS, Universitaet Stuttgart
 *	Author: Rouven Rischert
 */

/****************************** include files ******************************************/

#include	"GlobalDefinitions.h"
#include    "Motor_Steuerung.h"


/****************************** end of include ****************************************/



/****************************** declaration of variables ******************************/
/****************************** end of variables **************************************/



/****************************** declaration of functions ******************************/
/****************************** end of functions **************************************/



/****************************** implementation of functions ***************************/

/*
   * DRIVING_DIRECTION
   * 
   * ask for DRIVING_DIRECTION from RemoteDriver and give it to the MotorDriver
   * GetRemoteSignal(DRIVING_DIRECTION) returns a value between 0 and 1023
   * if the value is higher than 523  -> forward
   * if the value is lower than 500   -> reverse
   * if value is between 523 and 500  -> stand
   * 
   * DriveForward needs values between 510(max) and 255(min)
   * DriveReverse with values between 255(min) and 0(max)
   * 
   * The factor 1/2 is to get the values from GetRemoteSignal into the correct range of values for DriveForward/DriveReverse
   * 
   * collisioncontrol needs a bool-param. -> 
   *        true:   driving backwards
   *        false:  driving forwards
   * 
   * get actual velocity with getVelocity()
   * 
   * 5 if-cases: 
   * 
   *    1. velocity < 0 & collisioncontrol == true
   *    2. velocity >= 0 & collisioncontrol == true
   *    3. GetDrivingDirection == 0 (forward)
   *    4. GetDrivingDirection == 1 (reverse)
   *    5. GetDrivingDirection == 2 (stand)
   * 
   * the Do's are written above every if-case
   * 
   */

  void Drive(void){
    static int driving_direction_main;
    driving_direction_main = GetRemoteSignal(DRIVING_DIRECTION)/2;

    
    static int velocity_drive = getVelocity();

    //if car is driving backwards, and collisioncontrol is true -> accelerate forwards until velocity > 0, then go to Idle
    if ((velocity_drive < 0) and collisioncontrol(true)){
        while (getVelocity() < 0){
            DriveForward(PWM_MAX_FORWARD);
        }
        MotorIdle();
    }

    //if car is driving forwards, and collisioncontrol is true -> accelerate backwards until velocity < 0, then go to Idle
    else if ((velocity_drive >= 0) and collisioncontrol(false)){
        while (getVelocity() > 0){
            DriveForward(PWM_MAX_REVERSE);
        }
        MotorIdle();
    }

    //if Remote gives Signal to drive forward -> drive forward with Input-Speed
    else if (GetDrivingDirection()==0){
        DriveForward(driving_direction_main);
    }

    //if Remote gives Signal to drive backward -> drive backward with Input-Speed
    else if (GetDrivingDirection()==1){
        DriveReverse(driving_direction_main);
    }
    //if Remote gives Signal to stand -> go to idle
    else if (GetDrivingDirection()==2){
        MotorIdle();
    }
  }

/*
   * STEERING
   * 
   * ask for STEERING_DIRECTION from RemoteDriver and give it to the ServoDriver to set Steer 
   * GetRemoteSignal(STEERING_DIRECTION) gives back a value between 0 and 1023
   * if the value is higher than 523  -> right
   * if the value is lower than 500   -> left
   * if value is between 523 and 500  -> straight
   * 
   * SetSteering has a value-range from 30 (max left) to 150 (max right). 
   * -> 150-30= 120 -> 1023/120 ≈ 8,5 -> dividing the GetRemoteSignal with 8.5 to get a Value between about 0 and 120
   * add 30 to get a Value-Range from 30 to 150
   * 
   * give the Value to SetSteering so the steer goes into the right position
  */
  void Steer(void){
    static int velocity_steer = getVelocity();
    static int steering_direction_main;
    steering_direction_main = GetRemoteSignal(DRIVING_DIRECTION);
    steering_direction_main = int(steering_direction_main/8.5)+30;
    if (((velocity_steer >= 0) and !collisioncontrol(false))or ((velocity_steer < 0) and !collisioncontrol(true))){
        SetSteering(steering_direction_main);
    }
    else {
        //gerade aus
        SetSteering(90);
    }
  }


/***************************** end of implementation **********************************/