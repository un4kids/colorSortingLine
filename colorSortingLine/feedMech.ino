
void setupMech()
{
  feedMechServo.attach(FEED_MECH_SERVO_PIN);
    feedMechServo.write(60, feedMechFeedSpeed, true);
delay(1000);
  feedMechServo.write(feedMechFeedAngle, feedMechFeedSpeed, true);


  feedMechServoConfig.maxTimer = 2000;
  feedMechServoConfig.minTimer = 400;
  feedMechServoConfig.mainTimer = 1000;

  currentTimer = feedMechServoConfig.mainTimer;
}

void feedMechLoop()
{
  if (!objectTankerEmpty && !emergencyStopLine)
  {
    Serial.print("-------------------> FEED");
    Serial.print(currentTimer);
    //Serial.print(slower);
    Serial.println();

    if (millis() - feedMechElapsedTime >= currentTimer)
    {
      feedMechElapsedTime = millis();
      if (!feedMechServo.isMoving())
      {
        if (!retract)
        {
          retract = !retract;
          feedMechServo.write(feedMechRetractAngle, feedMechRetractSpeed, false);
        }
        else
        {
          retract = !retract;
          feedMechServo.write(feedMechFeedAngle, feedMechFeedSpeed, false);
        }
      }
    }
  }
  else
  {
    feedMechServo.write(feedMechFeedAngle, feedMechFeedSpeed, false);

  }
  handleSpeed();
}

void handleSpeed()
{
  if (faster)
  {
    currentTimer = feedMechServoConfig.minTimer;
  }
  else if (slower)
  {
    currentTimer = feedMechServoConfig.maxTimer;
  }
  else
  {
    currentTimer = feedMechServoConfig.mainTimer;
  }
}


void checkObjectTankerSens()
{
  if (digitalRead(OBJECT_TANKER_SENS_PIN) == LOW && !objectTankerEmpty)
  {
    Serial.println("-------------------> EMPTY");
    objectTankerEmpty = true;
  }
  if (digitalRead(OBJECT_TANKER_SENS_PIN) == HIGH && objectTankerEmpty)
  {
    Serial.println("-------------------> PRESENT");

    objectTankerEmpty = false;
  }
}
