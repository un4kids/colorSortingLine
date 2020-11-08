
void feedMechBegin()
{
  
}


void feedMechLoop()
{
  
}

bool objectsArePresent() 
{
 if (digitalRead(8) == 0)
 {
  return true;
 }
 return false;
}
