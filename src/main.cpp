#include  "GlobalDefinitions.h"
#include  "SonicDriver.h"
#include  "ServoDriver.h"
#include  "RemoteControlDriver.h"
#include  "MotorDriver.h"
#include  "stdio.h"
#include  <avr/io.h>
#include  "HupenSteuerung.h"
#include  "Motor_Steuerung.h"

void setup() {
  HupenSteuerungInit();
  MotorDriverInit();
  RemotePinInit();
  ServoInit();
  SonicPinInit();
  Serial.begin(9600);
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
  
  drive();
  steer();
 


  

  }