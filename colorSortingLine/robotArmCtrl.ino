// <<<<<<< HEAD
// <<<<<<< HEAD
// <<<<<<< HEAD
/*
#define sensPin 12
int ObjectColor;
// =======
//bool isObjectToSortIsPresent(){
//  if (digitalRead(sensPin) == HIGH){
//    return true;
//  }
//  return false;
//
//}
// >>>>>>> remoteCtl

//void sortCurrentObject(){
//  switch (ObjectColor){
//    case 1:
//    //move to position
// <<<<<<< HEAD
//    isObjectToSortIsPresent() = false;
//    break;
//    case 2:
//    //move to position
//    isObjectToSortIsPresent() = false;
//    break;
//    case 3:
//    //move to position
//    isObjectToSortIsPresent() = false;
//    break;
//    case 0:
//    //move to position
//    isObjectToSortIsPresent() = false;
//    break;
//  }
//}




//bool availableObject = false;

// =======
// >>>>>>> robotArm
void isObjectToSortIsPresent()
{
  if (digitalRead(sensPin) == HIGH)
  {
    availableObject = true;
    sortCurrentObject();
    availableObject = false;
    //Serial.println("Sens pin = HIGH");
  }
}
void sortCurrentObject()
{
  xMotor.enable();
  switch (uint8_t(currentColor))
  {
    case objectColor1:
      Serial.print("Sorting object color 1");
      ctl.rotate(0, 10, -15);
      delay(250);
      myservo.write(0, 50, true);
      delay(250);
      ctl.rotate(0, -10, 15);
      ctl.rotate(15, 0, 0);
      delay(200);
      //drop
      myservo.write(130, 50, true);
      delay(200);
      ctl.rotate(-15, 0, 0);
      break;
    case objectColor2:
      Serial.println("Sorting object color 2");
      ctl.rotate(0, 10, -15);
      delay(250);
      myservo.write(0, 50, true);
      delay(250);
      ctl.rotate(0, -10, 15);
      ctl.rotate(-19, 0, 0);
      delay(200);
      //drop
      myservo.write(130, 50, true);
      delay(200);
      ctl.rotate(19, 0, 0);
      break;
    case objectColor3:
      Serial.println("Sorting object color 3");
      ctl.rotate(0, 10, -15);
      delay(250);
      myservo.write(0, 50, true);
      delay(250);
      ctl.rotate(0, -10, 15);
      ctl.rotate(24, 0, 0);
      delay(200);
      //drop
      myservo.write(130, 50, true);
      delay(200);
      ctl.rotate(-24, 0, 0);
      break;
  }
  xMotor.disable();
  currentColor = 0;
}
void readCmd()
{
  if (mySerial.available())
  {
    currentColor = mySerial.read();
  }
  Serial.println(uint8_t(currentColor));
}
void setupArm()
{
  myservo.attach(12);

  pinMode(X_DIR, OUTPUT); pinMode(X_STP, OUTPUT);
  pinMode(Y_DIR, OUTPUT); pinMode(Y_STP, OUTPUT);
  pinMode(Z_DIR, OUTPUT); pinMode(Z_STP, OUTPUT);

  xMotor.begin(X_RPM, MICROSTEPS);
  yMotor.begin(Y_RPM, MICROSTEPS);
  zMotor.begin(Z_RPM, MICROSTEPS);
  xMotor.setEnableActiveState(LOW);
  yMotor.setEnableActiveState(LOW);
  zMotor.setEnableActiveState(LOW);

  xMotor.setSpeedProfile(xMotor.LINEAR_SPEED, MOTOR_ACCEL, MOTOR_DECEL);
  yMotor.setSpeedProfile(yMotor.LINEAR_SPEED, MOTOR_ACCEL, MOTOR_DECEL);
  zMotor.setSpeedProfile(zMotor.LINEAR_SPEED, 600, 600);

  pinMode(EN, OUTPUT);
  Serial.begin(115200);
  while (!Serial)
  {
    ; // wait for serial port to connect. Needed for Native USB only
  }
  // set the data rate for the SoftwareSerial port
  mySerial.begin(38400);
}
// =======
// >>>>>>> lineControl
// =======
//   // isObjectToSortIsPresent() = false;
//    break;
//    case 2:
//    //move to position
//   // isObjectToSortIsPresent() = false;
//    break;
//    case 3:
//    //move to position
//    //isObjectToSortIsPresent() = false;
//    break;
//    case 0:
//    //move to position
//   // isObjectToSortIsPresent() = false;
//    break;
//  }
//}

//void armControlLoop(){
//  if (isObjectToSortIsPresent()){
//   sortCurrentObject();
//   //sort
//  }
//}
// >>>>>>> remoteCtl


*/
