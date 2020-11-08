#include <Arduino.h>

#include "config.h"

#define sensPin 12 //sens for the arm
int ObjectColor;


void setup()
{
  
}


void loop()
{
  feedMechLoop();
  lineControlLoop();
  colorRecognitionLoop();
  armControlLoop();
  
}
