bool isObjectToSortIsPresent(){
  if (digitalRead(sensPin) == HIGH){
    return true;
  }
  return false;
  
}

void sortCurrentObject(){
  switch (ObjectColor){
    case 1:
    //move to position
    isObjectToSortIsPresent() = false;
    break;
    case 2:
    //move to position
    isObjectToSortIsPresent() = false;
    break;
    case 3:
    //move to position
    isObjectToSortIsPresent() = false;
    break;
    case 0:
    //move to position
    isObjectToSortIsPresent() = false;
    break;
  }
}

void armControlLoop(){
  if (isObjectToSortIsPresent()){
   sortCurrentObject(); 
   //sort
  }
}
