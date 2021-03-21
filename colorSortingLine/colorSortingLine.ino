#include <Arduino.h>
#include "config.h"
#include <EEPROMex.h>
#define sensPin 12 
int ObjectColor;
int EEPROMaddr = 0;


//feedMechParams
//Object_color
//lineControlparams
void setup()
{
  
}
//feedMechParams
//Object_color
//lineControlparams
void ReadAllEEPROM(){
  EEPROMaddr = 0;
  readFeedMechParams();
  readObject_Color();
  readLineControlParams();
  
}
void WriteAllEEPROM(){
  EEPROMaddr = 0;
  updateFeedMechParams();
  readObject_Color();
  readLineControlParams();
}
void loop()
{
  feedMechLoop();
  lineControlLoop();
  colorRecognitionLoop();
  armControlLoop();
  
}
