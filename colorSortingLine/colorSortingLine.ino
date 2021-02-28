#include <Arduino.h>

#include "config.h"
#include <EEPROMex.h>

void setup()
{
  colorRecognitionSetup();
}


void loop()
{
  feedMechLoop();
  lineControlLoop();
  colorRecognitionLoop();
  armControlLoop();
  mesureColor();
  
}
