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
} color;

//line control config

bool emergencyStop;
bool wrongObject;
bool slower;

//feedMech config
