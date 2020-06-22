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
   * ask for HORN_STATUS and in Case activate honk or not by using Honk-Function
  */
  static bool doHonk;
  doHonk = GetRemoteSignal(HORN_STATUS);
  Honk(doHonk);

  /*
   * ask for DRIVING_DIRECTION from RemoteDriver and give it to the MotorDriver
   * GetRemoteSignal(DRIVING_DIRECTION) gives back a value between 0 and 1023
   * if the value is higher than 523  -> forward
   * if the value is lower than 500   -> reverse
   * if value is between 523 and 500  -> stand
   * 
   * DriveForward only works with values between 510 and 255
   * DriveReverse with values between 255 and 0
   * 
   * The factor 2 is to get the values from GetRemoteSignal into the right values for DriveForward/DriveReverse
   * 
   */
  static int driving_main;
  driving_main = GetRemoteSignal(DRIVING_DIRECTION)/2;
  if (GetDrivingDirection()==0){
    DriveForward(driving_main);
  }
  else if (GetDrivingDirection()==1){
    DriveForward(driving_main);
  }
  else if (GetDrivingDirection()==2){
    MotorIdle();
  }

  }