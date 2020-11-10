

void lineControlLoop()
{
  throwUnrecognizedObj()
}

void emergencyStop()
{
  while (emergencyStop)
  {
    Servo1.write(0);
  }
}
void throwUnrecognizedObj()
{
  if (objectIsUnrecognized)
  {
    if (isObjectToThrowIsPresent())
    {
     //digitalWrite(eleMag, HIGH); 
     //digitalWrite(eleMa_2, LOW);
      if (isObjectToThrowIsPresent())
      {
       //digitalWrite(eleMag, LOW);
      }
    objectIsUnrecognized = false; 
    }
  }
  
}
bool isObjectToThrowIsPresent()
{
 if(digitalRead(phoRes)== LOW)
 {
  return true;
 }
  return false;
}
