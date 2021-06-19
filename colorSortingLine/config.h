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
bool button_PRESSed = true;//за избиране на менюто
bool NextDown = false;//за местене на менюто надолу
bool NextUp = false;//за местене на менюто нагоре
bool EndOfLine = false;// за когато DisGlobalPos стигне крайната,за loop-а , стойност
unsigned int addr;
int DisGlobalPos = 2;  //for the display funcrions
int speedPercents = 75;//for regulating the speed of the line
unsigned long startMillis;
unsigned long currMillis;



struct line_control_params_t
{ unsigned int countOfThrowedObjects;
  unsigned int defaultDutyCycle;
  unsigned int maxDutyCycle;
  unsigned int minDutyCycle;
};
 struct line_control_params_t  lineControlparams = {0, 75, 100, 30};
// lineControlparams.countOfThrowedObjects = 0;
// lineControlparams.defaultDutyCycle = 75;
// lineControlparams.maxDutyCycle = 100;
// lineControlparams.minDutyCycle = 30;

String line_control_menu [4] =
{
  "Count of throwed objects",
  "Default DutyCycle",
  "maxDutyCycle",
  "minDutyCycle",
};
String sample [3] =
{
  "opt 1",
  "opt 2",
  "opt 3",
};
 
String opt_1 [3] =
{
  "nice",
  "option",
  "one",
};
  
String opt_2 [3] =
{
  "well",
  "done",
  "option 2",
};

String opt_3 [3] =
{
  "good",
  "job",
  "option 3",
};     
 

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

//remoteCtl
 
  //const byte address[6] = "00001";
  int a = 0;
