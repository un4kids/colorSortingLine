
void setupMech()
{
  feedMechServo.attach(FEED_MECH_SERVO_PIN);
  feedMechServo.write(60, feedMechFeedSpeed, true);
  delay(1000);
  feedMechServo.write(feedMechFeedAngle, feedMechFeedSpeed, true);


  feedMech.maxTimer = 4000;
  feedMech.minTimer = 800;
  feedMech.mainTimer = 2000;

  feedMechCurrentTimer = feedMech.mainTimer;
}

void feedMechLoop()
{
  if (!objectTankerEmpty && !emergencyStopLine)
  {
    //    Serial.print("-------------------> FEED");
    //    Serial.println(GO_TO_HOME_CMD);
    //    //Serial.print(slower);
    //    Serial.println();

    if (millis() - feedMechElapsedTime >= feedMechCurrentTimer)
    {
      feedMechElapsedTime = millis();
      if (!feedMechServo.isMoving())
      {
        if (!retract)
        {
          retract = !retract;
          feedMechServo.write(feedMechRetractAngle, feedMechRetractSpeed, false);

          //TODO for now we generate random coloe while pushing the object
          feedMech.countOfFeededObjects ++;
          renderView = true;
          renderObjCounter = true;
          pushColorInStack();
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
    feedMechCurrentTimer = feedMech.minTimer;
  }
  else if (slower)
  {
    feedMechCurrentTimer = feedMech.maxTimer;
  }
  else
  {
    feedMechCurrentTimer = feedMech.mainTimer;
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
