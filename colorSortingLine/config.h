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

bool emergencyStop;
bool wrongObject; 
bool slower;

//feedMech config

typedef struct 
{
  unsigned long timer;
  
}feed_mech_params;
