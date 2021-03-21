#include <Arduino.h>
#include "config.h"
#include <EEPROMex.h>
#define sensPin 12 
int ObjectColor;
int addr = 0;


//feedMechParams
//Object_color
//lineControlparams
void setup()
{
  
}
void ReadAllEEPROM(){
  readFeedMechParams();
  readObject_Color();
  readLineControlParams();
  addr = 0;
}
void WriteAllEEPROM(){
  updateFeedMechParams();
  readObject_Color();
  readLineControlParams();
  addr = 0;
}

void loop()
{
  feedMechLoop();
  lineControlLoop();
  colorRecognitionLoop();
  armControlLoop();
  
}
