#include <Arduino.h>

#include "config.h"
int lm1 = 4;
int lm2 = 5;
pinMode(lm_1,OUTPUT) ;   
pinMode(lm_2,OUTPUT) ;
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
