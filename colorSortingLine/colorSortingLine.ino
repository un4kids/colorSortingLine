#include <Arduino.h>

#include "config.h"


#include <Servo.h>
int servoPin = 4;

void setup()
{
  Servo1.attach(servoPin);  
}


void loop()
{
  feedMechLoop();
  lineControlLoop();
  colorRecognitionLoop();
  armControlLoop();
  
}
