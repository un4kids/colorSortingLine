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

bool emergencyStop;
bool wrongObject;
bool slower;

//feedMech config
