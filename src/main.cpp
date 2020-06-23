#include  "GlobalDefinitions.h"
#include  "SonicDriver.h"
#include  "ServoDriver.h"
#include  "RemoteControlDriver.h"
#include  "MotorDriver.h"
#include  "stdio.h"
#include  <avr/io.h>
#include  "HupenSteuerung.h"

void setup() {
  HupenSteuerungInit();
  MotorDriverInit();
  RemotePinInit();
  ServoInit();
  SonicPinInit();
}

void loop() {
  /*
   * HONK
   * 
   * ask for HORN_STATUS and in Case activate honk or not by using Honk-Function
  */
  static bool doHonk;
  doHonk = GetRemoteSignal(HORN_STATUS);
  Honk(doHonk);

  /*
   * DRIVING_DIRECTION
   * 
   * ask for DRIVING_DIRECTION from RemoteDriver and give it to the MotorDriver
   * GetRemoteSignal(DRIVING_DIRECTION) gives back a value between 0 and 1023
   * if the value is higher than 523  -> forward
   * if the value is lower than 500   -> reverse
   * if value is between 523 and 500  -> stand
   * 
   * DriveForward only works with values between 510 and 255
   * DriveReverse with values between 255 and 0
   * 
   * The factor 1/2 is to get the values from GetRemoteSignal into the correct range of values for DriveForward/DriveReverse
   * 
   * If GetDrivingDirection:
   *       0 = forward 
   *       1 = reverse
   *       2 = stand
   * 
   */
  static int driving_direction_main;
  driving_direction_main = GetRemoteSignal(DRIVING_DIRECTION)/2;
  if (GetDrivingDirection()==0){
    DriveForward(driving_direction_main);
  }
  else if (GetDrivingDirection()==1){
    DriveReverse(driving_direction_main);
  }
  else if (GetDrivingDirection()==2){
    MotorIdle();
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
  */
  static int steering_direction_main;
  steering_direction_main = GetRemoteSignal(DRIVING_DIRECTION);
  steering_direction_main = int(steering_direction_main/8.5)+30;
  SetSteering(steering_direction_main);

  }