#include  "GlobalDefinitions.h"
#include  "SonicDriver.h"
#include  "ServoDriver.h"
#include  "RemoteControlDriver.h"
#include  "MotorDriver.h"
#include  "stdio.h"
#include  <avr/io.h>
#include  "HupenSteuerung.h"
#include  "Motor_Steuerung.h"
#include  "KollisionsUeberwachung.h"
#include  "BlinkerSteuerung.h"
#include  "Fahrlichtsteuerung.h"

void setup() {
  HupenSteuerungInit();
  MotorDriverInit();
  RemotePinInit();
  ServoInit();
  SonicPinInit();
  BlinkerSteuerungInit();
  lightControlInit();
  Serial.begin(2400);
  startTimer();
}

void loop() {
  Drive();
  Steer();
  blink();
  Honk();
  drivinglights();
  brakelights();
  backwardslight();
  }