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
}color;

//line control config
bool objectIsUnrecognized = false;
bool stopTheLine = false;
bool wrongObject; 
bool slower;
int lineSpeed = 10;

//feedMech config
