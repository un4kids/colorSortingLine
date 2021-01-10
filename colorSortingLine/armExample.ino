#include "Robot_Arm_pinout.h"
//#include <Adafruit_NeoPixel.h>
#include "FastLED.h" // FastLED                                                                                              
//#include "StepperDriver.h"
#include "A4988.h"
#include "MultiDriver.h"
#include "SyncDriver.h"



//Adafruit_NeoPixel pixels(1, EFFECT_LED_PIN, NEO_GRB + NEO_KHZ800);

/*TMP
  int stepActiveTime = 12;    // Delay between each pause (uS)
  int stepPassiveTime = 700;  // Delay between each pause (uS)
*/
struct CRGB effectLed;
int flashCounter = 0;

A4988 xMotor(STEPS_PER_REVOLUTION, X_DIR, X_STP, EN);
A4988 yMotor(STEPS_PER_REVOLUTION, Y_DIR, Y_STP, EN);
A4988 zMotor(STEPS_PER_REVOLUTION, Z_DIR, Z_STP, EN);

SyncDriver ctl(xMotor, yMotor, zMotor);

uint8_t movementMode = 0;
unsigned xWaitInMicros = 0;
unsigned yWaitInMicros = 0;
unsigned zWaitInMicros = 0;




void setup() {
  FastLED.addLeds<WS2811, EFFECT_LED_PIN, GRB>(&effectLed, NUM_LEDS).setCorrection( TypicalLEDStrip );

  //pinMode(EFFECT_LED_PIN, OUTPUT);
  //digitalWrite(EFFECT_LED_PIN, LOW);
  /* TMP
    pixels.begin();
    pixels.clear();
    pixels.show();

    digitalWrite(EN, LOW);
  */

  pinMode(X_DIR, OUTPUT); pinMode(X_STP, OUTPUT);
  pinMode(Y_DIR, OUTPUT); pinMode(Y_STP, OUTPUT);
  pinMode(Z_DIR, OUTPUT); pinMode(Z_STP, OUTPUT);

  xMotor.begin(X_RPM, MICROSTEPS);
  yMotor.begin(Y_RPM, MICROSTEPS);
  zMotor.begin(Z_RPM, MICROSTEPS);
  xMotor.setEnableActiveState(LOW);
  yMotor.setEnableActiveState(LOW);
  zMotor.setEnableActiveState(LOW);


  xMotor.setSpeedProfile(xMotor.LINEAR_SPEED, MOTOR_ACCEL, MOTOR_DECEL);
  yMotor.setSpeedProfile(yMotor.LINEAR_SPEED, MOTOR_ACCEL, MOTOR_DECEL);
  zMotor.setSpeedProfile(zMotor.LINEAR_SPEED, 600, 600);


  pinMode(EN, OUTPUT);
  movementMode = 1;

  Serial.begin(115200);
}

void loop() {
  /*TMP
    theMove();
    delay(3000);
  */
  simulateWelding();
}

void weldEffect(uint16_t iterations)
{
  for (int i = 0; i < iterations; i++)
  {
    fill_solid(&effectLed, 1, CHSV(random8(127, 255), random8(0, 100), 255));
    FastLED.show();
    delay(random8(3, 20));
    fill_solid(&effectLed, 1, CHSV(255, 0, 0));
    FastLED.show();
    if (flashCounter == 0)
    {
      delay (800);
    }
    delay(random8(50, 200));

    flashCounter++;
  }
  flashCounter = 0;
}

void simulateWelding()
{
  switch (movementMode)
  {
    case MOVE_1:
      xMotor.enable();
      ctl.rotate(0, 18, 12);
      delay(200);
      weldEffect(random8(40, 140));
      movementMode = MOVE_2;
      break;
    case MOVE_2:
      ctl.rotate(0, -4, -8);
      ctl.rotate(2, 4, 8);
      delay(200);
      weldEffect(random8(40, 140));
      movementMode = MOVE_3;
      break;
    case MOVE_3:
      // ctl.rotate(2, 4, 8);
      ctl.rotate(0, -4, -8);
      ctl.rotate(2, 4, 8);
      delay(200);
      weldEffect(random8(40, 140));
      movementMode = MOVE_4;
      break;
    case MOVE_4:
      ctl.rotate(2, 0, -8);
      delay(200);
      weldEffect(random8(40, 140));
      movementMode = MOVE_5;
      break;
    case MOVE_5:
      ctl.rotate(0, -4, 0);
      delay(200);
      weldEffect(random8(40, 140));
      movementMode = HOME;
      break;
    case HOME:
      fill_solid(&effectLed, 1, CHSV(255, 0, 0));
      FastLED.show();
      ctl.rotate(-6.0, -14.5, -4.5);
      delay(200);
      movementMode = MOVE_1;
      xMotor.disable();
      delay(random16(3000, 30000));

      break;
  }



}
