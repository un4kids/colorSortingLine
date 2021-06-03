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

  //moveLine();
  //displayLineControlParamsDown();//function for moving the menu down
  displayLineControlParamsUp();//function for moving the menu up
};

//void emergencyStop() //TODO
//{
//  if (stopTheLine)
//  {
//    feedMechServo.write(0);
//  }
//}
//void throwUnrecognizedObj()
//{
//if (objectIsUnrecognized)
//{
//if (isObjectToThrowIsPresent())
//{
//startMillis = millis();
//ActivateSol();







//lineControlparams.countOfThrowedObjects++;
//objectIsUnrecognized = false;
//}
//}

//}
//bool isObjectToThrowIsPresent()
//{
//if (digitalRead(phoRes) == LOW)
//{
//return true;
//}
//return false;
//}
void moveLine()
{

  if (!stopTheLine)
  {
    int dc = map(speedPercents, 0, 100, 0, 255);
    analogWrite(DSmPin, dc);
  };
};
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
  while (DisGlobalPos < 3)
  {

    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print(">");
    Serial.println(">");
    lcd.setCursor(0, 0);
    //lcd.print(line_control_menu [DisGlobalPos]);
    lcd.print(sample [DisGlobalPos]);
    Serial.println(sample [DisGlobalPos]);
    lcd.setCursor(1, 1);
    //lcd.print(line_control_menu [DisGlobalPos + 1]);
    Serial.println(sample [DisGlobalPos + 1]);
    DisGlobalPos++;
  }


  if (DisGlobalPos == 2)
  {
    Serial.println(">");
    Serial.println(sample [2]);
    Serial.println(sample [0]);
    EndOfLine = true;


  }
  while (EndOfLine == true)
  {
    if (NextDown == true)
    {
      DisGlobalPos = 0;
      EndOfLine = false;
    }
  }
  while (button_PRESSed == true)
  {
    OPT_1();
  }


  delay(5000);


  //  if (DisGlobalPos = 2)
  //  {
  //    lcd.setCursor(1, 1);
  //    //lcd.print(line_control_menu [0]);
  //    lcd.print(sample [0]);
  //    Serial.println(sample [1]);
  //  }
  //  while (button_pressed == true) //for calling sub-arrays
  //  {
  //    if (DisGlobalPos == 1)
  //    {
  //      DisGlobalPos = 0;
  //      lcd.clear();
  //      lcd.setCursor(0, 1);
  //      lcd.print(">");
  //      Serial.println(">");
  //      lcd.setCursor(0, 0);
  //      Serial.println(opt_2 [DisGlobalPos]);
  //      lcd.setCursor(1, 1);
  //      if (DisGlobalPos == 2)
  //      {
  //        nextStrid = 0;
  //
  //      }
  //      else
  //      {
  //        nextStrid = DisGlobalPos + 1;
  //      }
  //      lcd.print(opt_2 [nextStrid]);
  //      Serial.println(opt_2 [nextStrid]);
  //      DisGlobalPos++;
  //      delay(5000);
  //    }
  //    else
  //    {
  //      DisGlobalPos = 0;
  //      lcd.clear();
  //      lcd.setCursor(0, 1);
  //      lcd.print(">");
  //      Serial.println(">");
  //      lcd.setCursor(0, 0);
  //      lcd.print(opt_3 [DisGlobalPos]);
  //      Serial.println(opt_3 [DisGlobalPos]);
  //      lcd.setCursor(1, 1);
  //      if (DisGlobalPos == 2)
  //      {
  //        nextStrid = 0;
  //
  //      }
  //      else
  //      {
  //        nextStrid = DisGlobalPos + 1;
  //      }
  //      lcd.print(opt_3 [nextStrid]);
  //      Serial.println(opt_3 [nextStrid]);
  //      DisGlobalPos++;
  //      delay(5000);
  //    }
  //  }
}
void displayLineControlParamsUp()
{


  while (DisGlobalPos > 0)
  {

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(">");
    Serial.println(">");
    lcd.setCursor(0, 1);
    //lcd.print(line_control_menu [DisGlobalPos]);
    lcd.print(sample [DisGlobalPos]);
    Serial.println(sample [DisGlobalPos]);
    lcd.setCursor(1, 0);
    //lcd.print(line_control_menu [DisGlobalPos - 1]);
    Serial.println(sample [DisGlobalPos - 1]);
    DisGlobalPos--;
    if (DisGlobalPos == 0)
    {
      Serial.println(">");
      Serial.println(sample[0]);
      Serial.println(sample[2]);
      EndOfLine = true;
    }
    while (EndOfLine == true)
    {
      if (NextUp == true)
      {
        DisGlobalPos = 3;
        EndOfLine = false;
      }
    }
    delay(3000);
  }
}
//    else// Това е пробен код(МОЖЕ и да потрябва)
//    {
//      nextStr = DisGlobalPos - 1;
//    }
//    lcd.print(sample [nextStr]);
//    Serial.println(sample [nextStr]);
//    DisGlobalPos--;
//    delay(5000);
//
//  }
//  if (DisGlobalPos == 0)
//  {
//    lcd.setCursor(1, 0);
//    //lcd.print(line_control_menu [3]);
//    lcd.print(sample [2]);//a test for swithching between manues
//    Serial.println(sample [2]);
//  }
//  while (button_pressed == true) arrays
//  {
//
//
//      lcd.clear();
//      lcd.setCursor(0, 1);
//      lcd.print(">");
//      Serial.println(">");
//      lcd.setCursor(0, 0);
//      lcd.print(opt_1 [DisGlobalPos]);
//      Serial.println(opt_1 [DisGlobalPos]);
//      lcd.setCursor(1, 1);
//      lcd.print(opt_1 [DisGlobalPos + 1]);
//      Serial.println(opt_1 [DisGlobalPos + 1]);
//      DisGlobalPos++;
//    if (DisGlobalPos == 3-1)
//    {
//           DisGlobalPos = 0;
//    }
//
//    delay(5000);
//  }
//}
//void ActivateSol()
//{
//currMillis=millis();

//while(currMillis - startMillis = 20)
//{
//digitalWrite(eleMag,HIGH);
//}
//else()
//{
//digitalWrite(eleMag,LOW);
//}
//startMillis=currMillis;
//}
void ShowOpt_1Down()
{



  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print(">");
  Serial.println(">");
  lcd.setCursor(0, 0);
  //lcd.print(line_control_menu [DisGlobalPos]);
  lcd.print(opt_1 [DisGlobalPos]);
  Serial.println(sample [DisGlobalPos]);
  lcd.setCursor(1, 1);
  //lcd.print(line_control_menu [DisGlobalPos + 1]);
  Serial.println(opt_1 [DisGlobalPos + 1]);



  if (NextDown == true)
  {
    DisGlobalPos + 1;
  }

  if (DisGlobalPos == 2)
  {
    Serial.println(">");
    Serial.println(opt_1 [2]);
    Serial.println(opt_1 [0]);
    EndOfLine = true;


  }
  while (EndOfLine == true)
  {
    if (NextDown == true)
    {
      DisGlobalPos = 0;
      EndOfLine == false;
    }
  }
  if(NextUp= true)
  {
    ShowOpt_1Up();
  }
}
void ShowOpt_1Up()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(">");
  Serial.println(">");
  lcd.setCursor(0, 1);
  //lcd.print(line_control_menu [DisGlobalPos]);
  lcd.print(opt_1 [DisGlobalPos]);
  Serial.println(sample [DisGlobalPos]);
  lcd.setCursor(1, 0);
  //lcd.print(line_control_menu [DisGlobalPos - 1]);
  Serial.println(opt_1 [DisGlobalPos - 1]);
  
   if (NextUp == true)
  {
    DisGlobalPos - 1;
  }
  if (DisGlobalPos == 0)
  {
    Serial.println(">");
    Serial.println(opt_1[0]);
    Serial.println(opt_1[2]);
    EndOfLine = true;
  }
  while (EndOfLine == true)
  {
    if (NextUp == true)
    {
      DisGlobalPos = 3;
      EndOfLine = false;
    }
  }
  if(NextDown= true)
  {
    ShowOpt_1Down();
  }
}
void OPT_1()
{
 ShowOpt_1Down();
 ShowOpt_1Up();  
}
