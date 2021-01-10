
#include<EEPROM.h>

void setupLinecontrol()
{ //  feedMechServo.attach(4);
  //pinMode(solPin,OUTPUT);
  pinMode(eleMag, OUTPUT);
  pinMode(eleMag_2, OUTPUT);
  pinMode(DSmPin, OUTPUT);

  lineControlparams.countOfThrowedObjects = 0;
  lineControlparams.defaultDutyCycle = 10;
  lineControlparams.maxDutyCycle = 255;
  lineControlparams.minDutyCycle = 0;
};
void lineControlLoop()
{
  if (!stopTheLine)
  {
    moveLine(lineControlparams.defaultDutyCycle);
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

      lineControlparams.countOfThrowedObjects++;
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
