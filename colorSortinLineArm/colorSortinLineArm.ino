#include "Robot_Arm_pinout.h"
//#include <Adafruit_NeoPixel.h>
#include "FastLED.h" // FastLED                                                                                              
//#include "StepperDriver.h"
#include "A4988.h"
#include "MultiDriver.h"
#include "SyncDriver.h"
#include <VarSpeedServo.h>
#include <SoftwareSerial.h>




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

VarSpeedServo armServo;

unsigned long timer = 0;


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
  //movementMode = 1;

  armServo.attach(13);


  Serial.begin(9600);
}
void loop() {
  /*TMP
    theMove();
    delay(3000);
  */
  simulateWelding();

  if (Serial.available() > 0)
  {
    // read the incoming byte:
    movementMode = Serial.read();
    Serial.println(movementMode);
  }

  //  if (millis() - timer >= 2000)
  //  {
  //    timer = millis();
  //    if(movementMode > MOVE_3)
  //    {
  //      movementMode = MOVE_1;
  //    }
  //    else
  //    {
  //      movementMode++;
  //    }
  //  }
}
void simulateWelding()
{
  switch (movementMode)
  {
    case MOVE_1:
      xMotor.enable();
      ctl.rotate(23, -16, 0); //move forward
      armServo.write(25, 50, true); //close arm
      delay(400);
      ctl.rotate(0, 8, 0); //move up
      delay(600);
      ctl.rotate(-23, 8, 0); //move to home
      delay(600);
      ctl.rotate(10, -6, 16); // go to container one
      armServo.write(90, 50, true); //open arm
      delay(600);
      ctl.rotate(-10, 6, -16); // go home
      Serial.print(GO_TO_HOME);
      movementMode = 0;
      break;
    case MOVE_2:
      ctl.rotate(23, -16, 0); //move forward
      armServo.write(25, 50, true); //close arm
      delay(400);
      ctl.rotate(0, 8, 0); //move up
      delay(600);
      ctl.rotate(-23, 8, 0); //move to home
      delay(600);
      armServo.write(90, 50, true); //open arm
      delay(600);
      //      weldEffect(random8(40, 140));
      Serial.print(GO_TO_HOME);

      movementMode = 0;
      break;
    case MOVE_3:
      ctl.rotate(23, -16, 0); //move forward
      armServo.write(25, 50, true); //close arm
      delay(400);
      ctl.rotate(0, 8, 0); //move up
      delay(600);
      ctl.rotate(-23, 8, 0); //move to home
      delay(600);
      ctl.rotate(10, -6, -16); // go to container one
      armServo.write(90, 50, true); //open arm
      delay(600);
      ctl.rotate(-10, 6, 16); // go home
      Serial.print(GO_TO_HOME);

      movementMode = 0;
      break;
  }



}
/* TMP
  void theMove(void)
  {
  //move(100, 100, 100)    ==> (left , back, down)
  //move(-100, -100, -100) ==> (right , forward, up)

  move(0, -4600, -150);
  LED_welding_effect_short();
  delay(500);
  move(0, 500, 180);
  move(90, 0, 0);
  move(0, -500, -180);
  LED_welding_effect_short();
  delay(500);
  move(0, 500, 180);
  move(90, 0, 0);
  move(0, -500, -180);
  LED_welding_effect_short();
  delay(500);
  move(0, 1500, 0);
  move(500, 0, 200);
  LED_welding_effect_long();
  delay(500);
  move(0, 3100, -50);
  move(-478, 0, 0);

  delay(40000);
  }

  void move(int Base_steps, int Arm_steps, int Useless_steps)
  {
  if (Base_steps < 0) step(true, X_DIR, X_STP, abs(Base_steps)); //X, Counterclockwise
  else step(false, X_DIR, X_STP, abs(Base_steps)); //X, Clockwise
  delay(100);

  if (Arm_steps < 0) step(true, Y_DIR, Y_STP, abs(Arm_steps)); //Y, Counterclockwise
  else step(false, Y_DIR, Y_STP, abs(Arm_steps)); //Y, Clockwise
  delay(100);

  if (Useless_steps < 0) step(true, Z_DIR, Z_STP, abs(Useless_steps)); //X, Counterclockwise
  else step(false, Z_DIR, Z_STP, abs(Useless_steps)); //Z, Clockwise
  delay(100);
  }

  void LED_effect_simple(void)
  {
  for (uint8_t blinks = 3; blinks > 0; blinks--)
  {
    pixels.setPixelColor(0, pixels.Color(0, 0, 170));
    pixels.show();
    //digitalWrite(EFFECT_LED_PIN, HIGH);
    delay(80);
    pixels.setPixelColor(0, pixels.Color(0, 0, 0));
    pixels.show();
    //digitalWrite(EFFECT_LED_PIN, LOW);
    delay(80);
  }
  }

  void LED_welding_effect_long(void)
  {
  int count;
  count = random(10, 60);
  for (uint8_t i = 0; i < count; i++)
  {
    pixels.setPixelColor(0, pixels.Color(200, 0, 0));
    pixels.show();
    //digitalWrite(EFFECT_LED_PIN, HIGH);
    delay(random(60));
    pixels.setPixelColor(0, pixels.Color(0, 0, 0));
    pixels.show();
    //digitalWrite(EFFECT_LED_PIN, LOW);
    delay(random(200));
  }
  delay(random(800, 2000));
  }

  void LED_welding_effect_short(void)
  {
  int count;
  count = random(4, 10);
  for (uint8_t i = 0; i < count; i++)
  {
    pixels.setPixelColor(0, pixels.Color(0, 150, 0));
    pixels.show();
    //digitalWrite(EFFECT_LED_PIN, HIGH);
    delay(random(60));
    pixels.setPixelColor(0, pixels.Color(0, 0, 0));
    pixels.show();
    //digitalWrite(EFFECT_LED_PIN, LOW);
    delay(random(200));
  }
  delay(random(400, 800));
  }

  void step(boolean dir, byte dirPin, byte stepPin, int steps)
  {
  digitalWrite(dirPin, dir);
  delay(2);
  for (int i = 0; i < steps; i++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(stepActiveTime);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(stepPassiveTime);
  }
  }
*/
