#include <EEPROMex.h>
#include <Arduino.h>                                                                                            
#include "A4988.h"
#include "MultiDriver.h"
#include "SyncDriver.h"
#include "config.h"
//ArmControl
int ObjectColor1;
int ObjectColor2;
int ObjectColor3;
bool needToSafe = true;

struct ArmSettings
 { 
  int Movement1;
  int Movement2;
  int Movement3;
 };

ArmSettings settings = {22, 6, 576};

char ObjectColor;
bool availableObject = false;

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
  setupArm();
}


void loop()
{
  feedMechLoop();
  lineControlLoop();
  colorRecognitionLoop();
  armControlLoop();
  
}
