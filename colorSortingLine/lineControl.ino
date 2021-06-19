

void lineControlLoop()
{
  if (!emergencyStopLine || !pauseLine)
  {
    moveLine();
  }

  throwUnrecognizedObj();
}

//void emergencyStop() //TODO
//{
//  if (stopTheLine)
//  {
//    feedMechServo.write(0);
//  }
//}
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
  if (digitalRead(phoRes) == LOW)
  {
    return true;
  }
  return false;
}
void moveLine()
{
  analogWrite(DSmPin, lineControlParams.speedInPercents);

}

void setLineSpeed(int newSpeed)
{
  lineControlParams.speedInPercents = newSpeed;
  lineControlParams.defaultDutyCycle = map(newSpeed, 0, 100, 0, 255);
}
