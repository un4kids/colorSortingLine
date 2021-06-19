//connection configs
bool objectsAvailible;




//output congfigs

////robot arm control config

const uint8_t objectColor1 = 49;
const uint8_t objectColor2 = 50;
const uint8_t objectColor3 = 51;
const uint8_t Home = 52;



//color recognition config
typedef struct
{
  uint8_t R;
  uint8_t G;
  uint8_t B;
} object_color_t;

object_color_t ethalonObject_1;

object_color_t ethalonObject_2;

object_color_t ethalonObject_3;

object_color_t currentObject;

#define NAN_COLOR 0
#define RED 1
#define GREEEN 2
#define BLUE 3

int currentColorId;
bool throwUnrecognizedObject = false;



#define photoResistor 2


//line control config


typedef struct{
  int coutnOfThrowedObjects;
  int defaultDutyCycle;
  int maxDutyCycle;
  int minDutyCycle;
  int speedInPercents;
  
}line_control_params_t;

line_control_params_t lineControlParams = {0, 0, 0, 0};

bool emergencyStopLine = false;
bool pauseLine = false;



bool objectIsUnrecognized = false;
bool wrongObject; 


//line control config

//bool emergencyStop;
bool wrongObject;
bool slower;
int lineSpeed = 10;

//feedMech config
#define feedMechServoPin A0
#define feedMechPhoPin 8
typedef struct
{
  int countOfFeededObjects;
  unsigned long mainMaxTimer;
  unsigned long mainMinTimer;
  unsigned long mainTimer;

} feed_mech_params_t;

feed_mech_params_t servo_modes = {0, 0, 0, 0};
unsigned long feedMechTimer_container = 0;
unsigned long* feedMechTimer_ptr;

typedef struct 
{
  unsigned long timer;
  
}feed_mech_params;

