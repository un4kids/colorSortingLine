#include <Arduino.h>

#include "config.h"
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

//#define sensPin 12 
int ObjectColor;
RF24 radio(9, 10);
//RF24 radio(9, 10); // CE, CSN
const byte address[6] = "00001";

bool Emergencystop = 1;
bool Setlinefaster;
bool Setlineslower;
int16_t Ledbrightnesslevel;
char msgBuffer[5];

void setup()
{
   setupRemoteCtl();
}


void loop()
{
  loopRemoteCtl();
//  feedMechLoop();
//  lineControlLoop();
//  colorRecognitionLoop();
//  armControlLoop();
  
}
