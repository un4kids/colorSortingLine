#include <EEPROM.h>

#include <EEPROMex.h>
#include <EEPROMVar.h>
#include <Arduino.h>
#include "config.h"
#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

#include <Servo.h>

//int phoRes = ;//pin for the photoresistor
int DSmPin = 4;//pin for the DC motor
int eleMag = 6;//pin for the electromagnet
 

void setup()
{
  lcd.begin(16,2);
  Serial.begin(9600);
}



void loop()
{
  feedMechLoop();
  lineControlLoop();
  colorRecognitionLoop();
//  armControlLoop();
  
}
