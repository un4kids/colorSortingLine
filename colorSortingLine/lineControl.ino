
void setupLinecontrol()
{
  lineControlParams.countOfThrowedObjects = 0;
  lineControlParams.maxSpeed = 100;
  lineControlParams.minSpeed = 30;
  setLineSpeed(60);
};
void lineControlLoop()
{
  if (!emergencyStopLine && !pauseLine)
  {
    moveLine();
  }
  else
  {
    digitalWrite(LINE_MOTOR_PIN, LOW);
  }
  if (objectIsUnrecognized) {
    throwUnrecognizedObj();
  }
  emergencyStopButton.read() == HIGH ? emergencyStopLine = true : emergencyStopLine = false;
}

void moveLine()
{
  if (faster)
  {
    analogWrite(LINE_MOTOR_PIN, map(lineControlParams.maxSpeed, 0, 100, 0, 255));
  }
  else if (slower)
  {
    Serial.println("----------------------->SLOWER");
    analogWrite(LINE_MOTOR_PIN, map(lineControlParams.minSpeed, 0, 100, 0, 255));
  }
  else
  {
    analogWrite(LINE_MOTOR_PIN, map(lineControlParams.defaultSpeed, 0, 100, 0, 255));
  }
}

void setLineSpeed(uint8_t newSpeed)
{
  lineControlParams.defaultSpeed = newSpeed;
}

//bool moveSlower()
//{
//  if (ctlPanelButtonB.read() == LOW)//add triger from remote control
//  {
//    slower = true;
//  }
//  slower = false;
//}

void throwUnrecognizedObj()
{
  if (!objectThrowed)
  {
    if (millis() - tunelPresenceTimestampB >= throwObjectTimer)
    {
      if (!solenoidTimerStarted)
      {
        digitalWrite(SOLENOID_PIN, HIGH);
        solenoidOldTimer = millis();
        solenoidTimerStarted = true;

      }
      if (millis() - solenoidOldTimer >= solenoidTimer)
      {
        digitalWrite(SOLENOID_PIN, LOW);
        solenoidTimerStarted = false;
        objectIsUnrecognized = false;
        objectThrowed = true;
      }
    }
  }
}

void checkTunelSensA()
{
  if (digitalRead(TUNEL_SENS_A) == HIGH && !tunelSesnTrigeredA)
  {
    tunelSesnTrigeredA = true;
    tunelPresenceTimestampA =  millis();
  }
  if (digitalRead(TUNEL_SENS_A) == LOW && tunelSesnTrigeredA)
  {
    tunelSesnTrigeredA = false;
  }
}

void checkTunelSensB()
{
  if (digitalRead(TUNEL_SENS_B) == HIGH && !tunelSensTrigeredB)
  {
    Serial.println("LOW ---------> B");
    tunelSensTrigeredB = true;
    objectThrowed = false;
    tunelPresenceTimestampB =  millis();
  }
  if (digitalRead(TUNEL_SENS_B) == LOW && tunelSensTrigeredB)
  {
    Serial.println("HIGH ---------> B");
    tunelSensTrigeredB = false;
  }
}


void saveLineControlparams(line_control_params_t* lcp)
{
  //  EEPROM.write(addr, lcp->countOfThrowedObjects);
  //  addr += sizeof(int);
  //  EEPROM.write(addr, lcp->defaultDutyCycle);
  //  addr += sizeof(int);
  //  EEPROM.write(addr, lcp->maxDutyCycle);
  //  addr += sizeof(int);
  //  EEPROM.write(addr, lcp->minDutyCycle);
  //  addr += sizeof(int);
  //  addr = 0;
};
