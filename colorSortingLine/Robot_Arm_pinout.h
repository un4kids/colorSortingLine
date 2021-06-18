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
#define STEPS_PER_REVOLUTION 3200
#define X_RPM 4
#define Y_RPM 4
#define Z_RPM 6

#define MICROSTEPS 16

#define MOTOR_ACCEL 200
#define MOTOR_DECEL 100

//movement modes for non blocking
#define MOVE_1 1
#define MOVE_2 2 
#define MOVE_3 3 
#define MOVE_4 4 
#define MOVE_5 5
#define HOME 7
#endif
