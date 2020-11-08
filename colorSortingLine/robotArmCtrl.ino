#define sensPin 12
int ObjectColor;
bool availableObject = false;

void isObjectToSortIsPresent(){
  if (digitalRead(sensPin) == HIGH){
    availableObject = true;
  }
}

void sortCurrentObject(){
  switch (ObjectColor){
    case 1:
    availableObject = false;
    break;
    case 2:
    availableObject = false;
    break;
    case 3:
    availableObject = false;
    break;
  }
}

void armControlLoop()
{
  if (availableObject = true){
   sortCurrentObject(); 
  }
}
