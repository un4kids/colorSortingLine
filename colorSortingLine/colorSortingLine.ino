<<<<<<< HEAD

#include <Arduino.h>
#include "VarSpeedServo.h"
=======
#include <SoftwareSerial.h>
#include <VarSpeedServo.h> 
#include <EEPROMex.h>
#include <Arduino.h>                                                                                            
#include "A4988.h"
#include "MultiDriver.h"
#include "SyncDriver.h"
>>>>>>> robotArm
#include "config.h"
#include "Robot_Arm_pinout.h"
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



void setup()
{
<<<<<<< HEAD
  Serial.begin(115200);
=======
  setupArm();
>>>>>>> robotArm
}


void loop()
{
  feedMechLoop();
  lineControlLoop();
  colorRecognitionLoop();
  //arm control
  currentColor = 51;
  readCmd();
  isObjectToSortIsPresent();
}
