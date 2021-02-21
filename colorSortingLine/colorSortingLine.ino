#include <EEPROMex.h>
#include <EEPROMVar.h>
#include <Arduino.h>
#include "config.h"
#include <Wire.h>
#include "rgb_lcd.h"

//rgb_lcd lcd;

#include <Servo.h>

int phoRes = 6;//pin for the photoresistor
int DSmPin = 5;//pin for the DC motor
//int feedMechServo = 4;
int eleMag = 3;//pin for the electromagnet
int eleMag_2 = 2;//pin for the electromagnet 

void setup()
{

}



void loop()
{
  feedMechLoop();
  lineControlLoop();
  colorRecognitionLoop();
//  armControlLoop();
  
}
