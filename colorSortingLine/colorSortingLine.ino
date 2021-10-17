#include <Arduino.h>


//color recognition 
#include <MD_TCS230.h>
#include <FreqCount.h>

#include <SoftwareSerial.h>
#include <VarSpeedServo.h>
#include <EEPROMex.h>
#include "A4988.h"
#include "SyncDriver.h"

#include <ButtonEvents.h> //buttton lib --> https://github.com/fasteddy516/ButtonEvents
#include <Encoder.h>  //rotaary encoder lib  --> https://github.com/PaulStoffregen/Encoder


#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#include <Wire.h>
#include "rgb_lcd.h"

#include "config.h"


//ArmControl
int sensPin = HIGH;
bool needToSafe = true;

SoftwareSerial mySerial(12, 13); // RX, TX
VarSpeedServo myservo;

int currentColor = 0;
bool availableObject = false;
//robot arm control config
//typedef struct
//{
//  int objectColor1;
//  int objectColor2;
//  int objectColor3;
//  int Home;
//}ArmSettings;
//ArmSettings settingsForColor = {1, 2, 3, 4};

A4988 xMotor(STEPS_PER_REVOLUTION, X_DIR, X_STP, EN);
A4988 yMotor(STEPS_PER_REVOLUTION, Y_DIR, Y_STP, EN);
A4988 zMotor(STEPS_PER_REVOLUTION, Z_DIR, Z_STP, EN);
uint8_t movementMode = 0;
unsigned xWaitInMicros = 0;
unsigned yWaitInMicros = 0;
unsigned zWaitInMicros = 0;
SyncDriver ctl(xMotor, yMotor, zMotor);



//>>>>>>> remoteCtl
//#define sensPin 12
//int ObjectColor;
RF24 radio(9, 10);
//RF24 radio(9, 10); // CE, CSN
const byte address[6] = "00001";


bool Emergencystop = 1;
bool Setlinefaster;
bool Setlineslower;
int16_t Ledbrightnesslevel;
char msgBuffer[5];


//ctl panel variables
ButtonEvents ctlPanelEncoderButton;
ButtonEvents ctlPanelButtonA;
ButtonEvents ctlPanelButtonB;
ButtonEvents emergencyStopButton;


Encoder ctlPanelEncoder(5, 7);

rgb_lcd lcd;

VarSpeedServo feedMechServo;

//sensorData sdBlack = { 7770, 6720, 8840 };
//sensorData sdWhite = { 54390, 51740, 69490 };
sensorData sdBlack = { 0, 0, 0 };
sensorData sdWhite = { 0, 0, 0 };


void setup()
{
  Serial.begin(115200);
  setupLinecontrol();
  setupCtlPanel();
  setupMech();
  //  setupArm();
  //   setupRemoteCtl();
}

unsigned long mainTimer = 0;
void loop()
{
  lineControlLoop();
  ctlPanelLoop();
  feedMechLoop();
  //  colorRecognitionLoop();
  //arm control
  // currentColor = 51;
  //  readCmd();
  //  isObjectToSortIsPresent();
  //  loopRemoteCtl();
  //  feedMechLoop();
  //  lineControlLoop();
  //  colorRecognitionLoop();
  //  armControlLoop();





    if (millis() - mainTimer >= 2000)
    {
      mainTimer = millis();
      objectIsUnrecognized = true;
      //objectThrowed = false;
    }

  checkTunelSensA();
  checkTunelSensB();
  checkObjectTankerSens();
  //checkFinalSesn();
  //delay(600);
}
