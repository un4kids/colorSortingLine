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
bool slower;
int lineSpeed = 10;

//feedMech config

typedef struct 
{
  unsigned long timer;
  
}feed_mech_params;
