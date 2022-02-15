#ifndef _ROBOT_ARM_PINOUT_
#define _ROBOT_ARM_PINOUT_

// LED used for the welding effect
#define EFFECT_LED_PIN 12
#define NUM_LEDS 1

// Enable pin
#define EN    8

// Direction pin
#define X_DIR 2
#define Y_DIR 3
#define Z_DIR 4

// Step pin
#define X_STP 5
#define Y_STP 6
#define Z_STP 7


//A4988 settings
//#define STEPS_PER_REVOLUTION 3200
#define STEPS_PER_REVOLUTION 1600

//#define STEPS_PER_REVOLUTION 200/

#define X_RPM 2
#define Y_RPM 2
#define Z_RPM 6

#define MICROSTEPS 8

#define MOTOR_ACCEL 2000
#define MOTOR_DECEL 1000

//movement modes for non blocking
#define MOVE_1 49//1
#define MOVE_2 50//2 
#define MOVE_3 51//3 

#define GO_TO_HOME 4 
#endif
