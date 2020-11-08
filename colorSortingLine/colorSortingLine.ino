#include <Arduino.h>
#include "Servo.h"
#include "config.h"

void setup()
{
  Serial.begin(115200);
}


void loop()
{
  feedMechLoop();
  lineControlLoop();
  colorRecognitionLoop();
  armControlLoop();
  
}
