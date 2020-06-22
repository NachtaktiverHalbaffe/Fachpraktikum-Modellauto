#include  "GlobalDefinitions.h"
#include  "SonicDriver.h"
#include  "ServoDriver.h"
#include  "RemoteControlDriver.h"
#include  "MotorDriver.h"
#include  "stdio.h"
#include  <avr/io.h>
#include  "HupenSteuerung.h"

void setup() {
  
}

void loop() {
  /*
   * ask for HORN_STATUS and in Case activate honk or not by using Honk-Function
  */
  static bool doHonk;
  doHonk = GetRemoteSignal(HORN_STATUS);
  Honk(doHonk);



}