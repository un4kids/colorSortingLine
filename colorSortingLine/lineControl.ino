

void lineControlLoop()
{
  throwUnrecognizedObj()
}

void emergency_Stop()
{
  while (emergency_Stop())
  {
    feedMechServo.write(0);
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
void moveline()
{
 for(int DCmotorSpeed = 0 ;  DCmotorSpeed <= 255;)
 {
 analogWrite(DSmPin, DCmotorSpeed); 
 delay(30);
 }      
}
