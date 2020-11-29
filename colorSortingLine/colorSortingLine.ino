#include <Arduino.h>

#include "config.h"

void setup()
{
  colorRecognitionbegin();
}


void loop()
{
  feedMechLoop();
  lineControlLoop();
  colorRecognitionLoop();
  armControlLoop();
  
}
