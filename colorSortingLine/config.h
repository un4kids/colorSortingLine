//connection configs
bool objectsAvailible;


//output congfigs

//robot arm control config

//color recognition config
typedef struct
{
  uint8_t R;
  uint8_t G;
  uint8_t B;
} color;

//line control config
bool objectIsUnrecognized = false;
bool stopTheLine = false;
bool wrongObject;
bool slower;
bool button_pressed = true;
unsigned int addr;
int DisGlobalPos=0;  //for the display funcrions
unsigned long startMillis;
unsigned long currMillis;


struct line_control_params_t
{ unsigned int countOfThrowedObjects;
  unsigned int defaultDutyCycle;
  unsigned int maxDutyCycle;
  unsigned int minDutyCycle;
};
 struct line_control_params_t  lineControlparams = {0, 200, 255, 10};
// lineControlparams.countOfThrowedObjects = 0;
// lineControlparams.defaultDutyCycle = 200;
// lineControlparams.maxDutyCycle = 255;
// lineControlparams.minDutyCycle = 10;

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
