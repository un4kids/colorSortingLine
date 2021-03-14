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
unsigned int addr;
int DisGlobalPos=0;  //for the display funcrions


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
 
 

//feedMech config
