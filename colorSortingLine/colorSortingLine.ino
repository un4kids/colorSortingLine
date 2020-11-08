#include <Arduino.h>

#include "config.h"

#define sensPin 12 
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
