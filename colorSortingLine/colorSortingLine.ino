#include <Arduino.h>

#include "config.h"
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define led 3
#define rbtt 8
#define lbtt 7
#define stobtt 6
#define onoff_logic 5


//#define sensPin 12 
int ObjectColor;
RF24 radio(9, 10);
//RF24 radio(9, 10); // CE, CSN
const byte address[6] = "00001";

bool Emergencystop;
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
  Emergencystop = digitalRead(stobtt);
  loopRemoteCtl();
//  feedMechLoop();
//  lineControlLoop();
//  colorRecognitionLoop();
//  armControlLoop();
  
}
