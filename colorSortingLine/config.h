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

bool emergencyStop;
bool wrongObject;
bool slower;

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

feed_mech_params_t servo_modes = {0, 256, 50, 150};
unsigned long feedMechTimer_container = 0;
unsigned long* feedMechTimer_ptr;
