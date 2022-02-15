

void setupArmMasterConn()
{
  Serial3.begin(9600);

}


void armConnectionLoop()
{
  armTxLoop();
  armRxLoop();
}

void armTxLoop()
{
  //if queue is emty send home command
  if (isQueueEmpty(&colorsQueue) && currentArmState != ARM_IS_HOMED) //TODO
  {
    Serial.print("----------------------------> SENDING HOME CMD");
    //    Serial.println(colorsQueue.arr[2]);
    Serial3.print(GO_TO_HOME_CMD);
    currentArmState = ARM_IS_HOMED;//TODO need to reveive that from the arm?
  }
  else
  {
    if (endSensTriggered && currentArmState == ARM_IS_DONE)
    {

      Serial.print("----------------------------> front   ");
      Serial.print(rear(&colorsQueue));
      Serial.println("----");

      delay(2000);
      //      switch (front(&colorsQueue))
      switch (dequeue(&colorsQueue))
      {
        case COLOR_A:
          Serial.println("----------------------------> COLOR A CMD");
          Serial3.print(CONTAINER_A_CMD);
          break;
        case COLOR_B:
          Serial.println("----------------------------> COLOR B CMD");
          Serial3.print(CONTAINER_B_CMD);
          break;
        case COLOR_C:
          Serial.println("----------------------------> COLOR C CMD");
          Serial3.print(CONTAINER_C_CMD);
          break;
      }
    }
  }
}


void armRxLoop()
{
  if (Serial3.available() > 0)
  {
    // read the incoming byte:
    currentArmState = Serial.read();
  }
}
