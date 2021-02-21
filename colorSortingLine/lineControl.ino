#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;



void setupLinecontrol()
{ //  feedMechServo.attach(4);
  //pinMode(solPin,OUTPUT);
  pinMode(eleMag, OUTPUT);
  pinMode(eleMag_2, OUTPUT);
  pinMode(DSmPin, OUTPUT);
  lcd.begin(16,2);

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
void saveLineControlparams(line_control_params_t* lcp)
{
  EEPROM.writeInt(addr, lcp->countOfThrowedObjects);
  addr += sizeof(int);
  EEPROM.writeInt(addr, lcp->defaultDutyCycle);
  addr += sizeof(int);
  EEPROM.writeInt(addr, lcp->maxDutyCycle);
  addr += sizeof(int);
  EEPROM.writeInt(addr, lcp->minDutyCycle);
  addr += sizeof(int);
  addr = 0;
};
void readLineControlparams(line_control_params_t* lcp)
{
 lcp->countOfThrowedObjects = EEPROM.readInt(addr);
 addr += sizeof(int);
 lcp->defaultDutyCycle = EEPROM.readInt(addr);
 addr += sizeof(int);
 lcp->maxDutyCycle = EEPROM.readInt(addr);
 addr += sizeof(int);
 lcp->minDutyCycle = EEPROM.readInt(addr);
 addr += sizeof(int);
 addr = 0;
};

void display_line_control_params()
{
 if(DisCurentPos == 0)
  DisCurentPos = 3;
 else
 {
  DisCurentPos --;
 }
 
 if(DisCurentPos==3)
  DisCurentPos = 0;
 else
 {
   DisCurentPos ++;
 }

 if(DisCurentPos <= 3 )
  DisCurentPos++;
 
 lcd.setCursor(0,0);
 lcd.print(line_control_menu [DisCurentPos]);
 lcd.setCursor(0,1);
 lcd.print(line_control_menu [DisCurentPos+1]); 
 
}
