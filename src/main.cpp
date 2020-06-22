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
   */




}