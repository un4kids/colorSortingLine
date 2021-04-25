#include <Wire.h>
#include "rgb_lcd.h"

//rgb_lcd lcd;



void setupLinecontrol()
{ //  feedMechServo.attach(4);
  //pinMode(solPin,OUTPUT);
  pinMode(eleMag, OUTPUT);
 // pinMode(eleMag_2, OUTPUT);
  pinMode(DSmPin, OUTPUT);
  lcd.begin(16, 2);
  //startMillis=millis();

  lineControlparams.countOfThrowedObjects = 0;
  lineControlparams.defaultDutyCycle = 10;
  lineControlparams.maxDutyCycle = 255;
  lineControlparams.minDutyCycle = 0;
};
void lineControlLoop()
{
//  if (!stopTheLine)
//  {
//    moveLine(lineControlparams.defaultDutyCycle);
//  };
//
//  throwUnrecognizedObj();
  displayLineControlParamsDown();//function for moving the menu down
  displayLineControlParamsUp();//function for moving the menu up
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
      startMillis=millis();
      ActivateSol();
      
      
     
      
      
      

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

void displayLineControlParamsDown()
{

  //for ( DisGlobalPos <3; DisGlobalPos++;)
  while(DisGlobalPos <3)
  {
   int nextStrid =0;//за да не превърта менюто 
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print(">");
    lcd.setCursor(0, 0);
    //lcd.print(line_control_menu [DisGlobalPos]);
    lcd.print(sample [DisGlobalPos]);
    lcd.setCursor(1, 1);
    //lcd.print(line_control_menu [DisGlobalPos + 1]);
    if(DisGlobalPos == 2)
    {
      nextStrid = 0;
      
    }
    else
    {
      nextStrid = DisGlobalPos + 1;
    }
    lcd.print(sample [nextStrid]);
    DisGlobalPos++;
    delay(5000);
    
  }
  if(DisGlobalPos=2)
  {
    lcd.setCursor(1, 1);
    //lcd.print(line_control_menu [0]);
     lcd.print(sample [0]);
  }
  while(button_pressed==true)//for calling sub-arrays
  {
   if(DisGlobalPos= 1)
   {
    DisGlobalPos=0;
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print(">");
    lcd.setCursor(0, 0);
    lcd.print(opt_2 [DisGlobalPos]);
    lcd.setCursor(1, 1);
     if(DisGlobalPos == 2)
    {
      nextStrid = 0;
      
    }
    else
    {
      nextStrid = DisGlobalPos + 1;
    }
    lcd.print(opt_2 [nextStrid]);
    DisGlobalPos++;
    delay(5000);
   }
   else
   {
    DisGlobalPos=0;
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print(">");
    lcd.setCursor(0, 0);
    lcd.print(opt_3 [DisGlobalPos]);
    lcd.setCursor(1, 1);
     if(DisGlobalPos == 2)
    {
      nextStrid = 0;
      
    }
    else
    {
      nextStrid = DisGlobalPos + 1;
    }
    lcd.print(opt_3 [nextStrid]);
    DisGlobalPos++;
    delay(5000);
   }
  }
}  
void displayLineControlParamsUp()
{

  //for ( DisGlobalPos>0; DisGlobalPos--;)
  while(DisGlobalPos>0)
  {
   int nextStr = 0; 
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(">");
    lcd.setCursor(0, 1);
    //lcd.print(line_control_menu [DisGlobalPos]);
    lcd.print(sample [DisGlobalPos]);
    lcd.setCursor(1, 0);
    //lcd.print(line_control_menu [DisGlobalPos - 1]);
    if(DisGlobalPos == 0)
    {
      nextStr = 2;
      
    }
    else
    {
      nextStr = DisGlobalPos - 1;
    }
     lcd.print(sample [nextStr]);
    DisGlobalPos--;
    delay(5000);
    
  }
  if(DisGlobalPos=0)
  {
    lcd.setCursor(1, 0);
    //lcd.print(line_control_menu [3]);
    lcd.print(sample [2]);
  }
   while(button_pressed==true)//for calling sub-arrays
  {
   if(DisGlobalPos= 0)
   {
    DisGlobalPos=0;
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print(">");
    lcd.setCursor(0, 0);
    lcd.print(opt_1 [DisGlobalPos]);
    lcd.setCursor(1, 1);
    lcd.print(opt_1 [DisGlobalPos++]);
   }
   else
   {
    DisGlobalPos=0;
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print(">");
    lcd.setCursor(0, 0);
    lcd.print(opt_2 [DisGlobalPos]);
    lcd.setCursor(1, 1);
    lcd.print(opt_2 [DisGlobalPos++]);
   }
  }  
}
void ActivateSol()
{
  currMillis=millis();

  while(currMillis - startMillis = 20)
  {
    digitalWrite(eleMag,HIGH);
  }
  else()
  {
    digitalWrite(eleMag,LOW);
  }
  startMillis=currMillis;
} 
