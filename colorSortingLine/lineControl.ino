

void lineControlLoop()
{
  if (!stopTheLine)
  {
    moveLine(lineSpeed);
  }

  throwUnrecognizedObj()
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
void moveLine(int speedPercents)
{
  int dc = map(speedPercents, 0, 100, 0, 255);
  analogWrite(DSmPin, dc);

}
