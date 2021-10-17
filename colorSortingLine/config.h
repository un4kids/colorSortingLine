//COMMON CONFIGS

#define TUNEL_SENS_A 25
#define TUNEL_SENS_B 27

bool tunelSesnTrigeredA = false;
bool tunelSensTrigeredB = false;

unsigned long tunelPresenceTimestampA = 0;
unsigned long tunelPresenceTimestampB = 0;


bool faster = false;
bool slower = false;

//CTL PANNEL
#define CTL_PANEL_ENCODER_BTTN_PIN 3
#define CTL_PANEL_BTTN_A_PIN 17
#define CTL_PANEL_BTTN_B_PIN 19
#define CTL_PANEL_BTTN_EMERGECY_STOP_PIN 13


#define IDLE_DISPLAY_MODE 1
#define MENU_DISPLAY_MODE 2
uint8_t currentDisplayMode = 1;
const uint8_t numRows = 2;
const uint8_t numCols = 16;

bool homeCursor = true;

int encoderNewPosition = 0;
int encoderOldPosition = 0;
static uint8_t menuPointerPos = 0;
static uint8_t currentCursorPos = 0;
static uint8_t oldMenuPointerPos = 0;
bool renderView = true;
bool onSubMenuItem = false;

int sharedParam = 0;
bool initSetting = false;

//connection configs
bool objectsAvailible;

//output congfigs
#define menuNumItems 7
String menu [menuNumItems] =
{
  "line def speed",
  "line max speed",
  "line min speed",
  "feed speed",
  "set color #1",
  "set color #2",
  "set color #3"
};
#define SET_LINE_DEF_SPEED 0
#define SET_LINE_MAX_SPEED 1
#define SET_LINE_MIN_SPEED 2
#define SET_FEED_SPEED 3
#define SET_COLOR_1 4
#define SET_COLOR_2 5
#define SET_COLOR_3 6
//#define lineSpeedMenuNumItems 3
//String lineSpeedMenu [menuNumItems] =
//{
//  "default speed",
//  "max speed",
//  "min speed",
//};
//#define colorMenuNumItems 3
//String colorMenu [menuNumItems] =
//{
//  "color #1",
//  "color #2",
//  "color #3",
//};


//ROBOT ARM CONTROL

const uint8_t objectColor1 = 49;
const uint8_t objectColor2 = 50;
const uint8_t objectColor3 = 51;
const uint8_t Home = 52;

// LED used for the welding effect
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




//COLOR RECOGNITION COLOR
//
//typedef struct
//{
//  uint8_t R;
//  uint8_t G;
//  uint8_t B;
//} object_color_t;
//
//object_color_t ethalonObject_1;
//
//object_color_t ethalonObject_2;
//
//object_color_t ethalonObject_3;
//
//object_color_t currentObject;


// Color Table for matching
typedef struct
{
  String    colorName;  // color name 8+nul
  colorData rgb;    // RGB value
} color_table_t;


color_table_t colorTable[] =
{
  {"WHITE", {255, 255, 255} },
  {"BLACK", {0, 0, 0} },
  {"YELLOW", {53, 30, 7} },
  {"ORANGE", {46, 8, 3} },
  {"RED", {23, 1, 2} },
  {"GREEN", {17, 26, 7} },
  {"BLUE", {2, 11, 25} },
  {"BROWN", {8, 0, 0} },

};

colorData cueerentCollorData;

#define NAN_COLOR 0
#define RED 1
#define GREEEN 2
#define BLUE 3

int currentColorId;
bool throwUnrecognizedObject = false;



#define photoResistor 2



//LINE CONTROL CONFIG


typedef struct {
  int countOfThrowedObjects;
  uint8_t defaultSpeed;
  uint8_t maxSpeed;
  uint8_t minSpeed;
} line_control_params_t;

line_control_params_t lineControlParams = {0, 0, 0, 0};

#define LINE_MOTOR_PIN 4//DSmPin
#define SOLENOID_PIN 6

// struct line_control_params_t  lineControlparams = {0, 75, 100, 30};

bool emergencyStopLine = false;
bool pauseLine = false;

bool objectIsUnrecognized = false;
unsigned long throwObjectTimer =  500;

unsigned long solenoidOldTimer = 0;
unsigned long solenoidTimer = 60;
bool solenoidTimerStarted = false;

bool objectThrowed = true;


//line control config

//FEED MECH CONFIG
#define FEED_MECH_SERVO_PIN 9
#define OBJECT_TANKER_SENS_PIN 11

typedef struct
{
  int countOfFeededObjects;
  unsigned long maxTimer;
  unsigned long minTimer;
  unsigned long mainTimer;

} feed_mech_params_t;

feed_mech_params_t feedMechServoConfig = {0, 0, 0, 0};

unsigned long currentTimer = 0;

unsigned long feedMechElapsedTime = 0;
bool retract = false;

uint8_t feedMechRetractAngle = 50;
uint8_t feedMechFeedAngle = 180;
uint8_t feedMechFeedSpeed = 200;
uint8_t feedMechRetractSpeed = 200;

bool objectTankerEmpty = false;

//REMOTE CTL
