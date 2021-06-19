
#define sensPin 12
int ObjectColor;

//void sortCurrentObject(){
//  switch (ObjectColor){
//    case 1:
//    //move to position
//    isObjectToSortIsPresent() = false;
//    break;
//    case 2:
//    //move to position
//    isObjectToSortIsPresent() = false;
//    break;
//    case 3:
//    //move to position
//    isObjectToSortIsPresent() = false;
//    break;
//    case 0:
//    //move to position
//    isObjectToSortIsPresent() = false;
//    break;
//  }
//}




bool availableObject = false;

void isObjectToSortIsPresent() {
  if (digitalRead(sensPin) == HIGH) {
    availableObject = true;
  }
}

void sortCurrentObject() {
  switch (ObjectColor) {
    case 1:
      availableObject = false;
      break;
    case 2:
      availableObject = false;
      break;
    case 3:
      availableObject = false;
      break;
    case 0:
      availableObject = false;
      break;
  }
}

void armControlLoop() {
  if (availableObject) {
    sortCurrentObject();
  }
}
