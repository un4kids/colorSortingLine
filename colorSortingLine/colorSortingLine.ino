#include <Arduino.h>

#include "config.h"


#include <Servo.h>

int phoRes = 6//pin for the photoresistor
//int solPin = 5;
int feedMechServo = 4;
int eleMag = 3;//pin for the electromagnet
int eleMag_2 = 2;//pin for the electromagnet

void setup()
{
  Servo1.attach(feedMechServo);
  pinMode(solPin,OUTPUT);
  pinMode(eleMag,OUTPUT);
  pinMode(eleMag_2,OUTPUT);  
}



void loop()
{
  feedMechLoop();
  lineControlLoop();
  colorRecognitionLoop();
  armControlLoop();
  
}
