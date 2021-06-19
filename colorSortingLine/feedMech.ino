
void feedMechBegin()
{
  VarSpeedServo feedMech_servo;
  feedMech_servo.attach(feedMechServoPin);
  
}

void feedMechLoop()
{
  if (objectsArePresent())
  {
    if (digitalRead(6) == LOW)
    {//boost
      feedMechTimer_ptr = &servo_modes.mainMaxTimer;
  
    } else if (digitalRead(7) == LOW)
    {//rand from main to max
      feedMechTimer_ptr = random(&servo_modes.mainMinTimer, &servo_modes.mainMaxTimer - 1) ;
    }else {
      //default
      feedMechTimer_ptr = &servo_modes.mainTimer;
    }
    if (millis() - feedMechTimer_container >= *feedMechTimer_ptr)
    {
      feedMechTimer_container = millis();
    }
  }
}


bool objectsArePresent()
{
  if (digitalRead(feedMechPhoPin) == 0)
  {
    return true;
  }
  return false;
}
