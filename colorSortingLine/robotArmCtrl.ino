void isObjectToSortIsPresent() {
  if (digitalRead(sensPin) == HIGH) {
    availableObject = true;
    sortCurrentObject();
    availableObject = false;
    //Serial.println("Sens pin = HIGH");
  }
}
void sortCurrentObject() {
  xMotor.enable();
  switch (uint8_t(currentColor)) {
    case objectColor1:
      Serial.print("Sorting object color 1");
      ctl.rotate(0, 6, -10);
      delay(250);
      myservo.write(0, 50, true);
      delay(250);
      ctl.rotate(0, -6, 10);
      //ctl.rotate(15, 0, 0);
      delay(200);
      //drop
      myservo.write(130, 50, true);
      delay(200);
      //ctl.rotate(-5, 0, 0);
      break;
    case objectColor2:
      Serial.println("Sorting object color 2");
      ctl.rotate(0, 6, -10);
      delay(250);
      myservo.write(0, 50, true);
      delay(250);
      ctl.rotate(0, -6, 10);
      ctl.rotate(8, 0, 0);
      delay(200);
      //drop
      myservo.write(130, 50, true);
      delay(200);
      ctl.rotate(-8, 0, 0);
      break;
    case objectColor3:
      Serial.println("Sorting object color 3");
      ctl.rotate(0, 6, -10);
      delay(250);
      myservo.write(5, 100, true);
      delay(250);
      ctl.rotate(0, -6, 10);
      ctl.rotate(-8, 0, 0);
      delay(200);
      //drop
      myservo.write(130, 50, true);
      delay(200);
      ctl.rotate(8, 0, 0);
      break;
     case Home:
      Serial.println("Sorting object color 3");
      ctl.rotate(0, -12, 12);
      delay(250);
      myservo.write(5, 100, true);
      break;
  }
  xMotor.disable();
  currentColor = 0;
}
void readCmd() {
  if (mySerial.available()) {
    currentColor = mySerial.read();
  }
  Serial.println(uint8_t(currentColor));
}
void setupArm() {
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
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Native USB only
  }
  // set the data rate for the SoftwareSerial port
  mySerial.begin(38400);
}
