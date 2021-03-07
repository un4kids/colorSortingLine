void isObjectToSortIsPresent() {
  if (digitalRead(sensPin) == HIGH) {
    //Serial.println("Sens pin = HIGH");
    availableObject = true;
  }
}

void sortCurrentObject() {
  xMotor.enable();
  //Serial.println(ObjectColor);
  switch (ObjectColor) {
    case MOVE_1:
    Serial.println("MOVE_1");
      ctl.rotate(0, 10, -15);
      //Serial.println("Movement right forward");
      //delay(400);
      //ctl.rotate(0, 10, 0);
      //Serial.println("Movement left forward");
      //delay(400);
      ctl.rotate(0, -10, 15);
      //Serial.println("Movement left backwards");
      //delay(400);
      //ctl.rotate(0, 0, 15);
      //Serial.println("Movement right backwards");
      delay(400);
      ctl.rotate(15, 0, 0);
      delay(200);
      //drop
      delay(200);
      ctl.rotate(-15, 0, 0);
      break;
    case MOVE_2:
      Serial.println("MOVE_2");
      ctl.rotate(0, 10, -15);
      //Serial.println("Movement right forward");
      //delay(400);
      //ctl.rotate(0, 10, 0);
      //Serial.println("Movement left forward");
      //delay(400);
      ctl.rotate(0, -10, 15);
      //Serial.println("Movement left backwards");
      //delay(400);
      //ctl.rotate(0, 0, 15);
      //Serial.println("Movement right backwards");
      delay(400);
      ctl.rotate(-15, 0, 0);
      delay(200);
      //drop
      delay(200);
      ctl.rotate(15, 0, 0);
      break;
    case MOVE_3:
    Serial.println("MOVE_3");
      ctl.rotate(0, 10, -15);
      //Serial.println("Movement right forward");
      //delay(400);
      //ctl.rotate(0, 10, 0);
      //Serial.println("Movement left forward");
      //delay(400);
      ctl.rotate(0, -10, 15);
      //Serial.println("Movement left backwards");
      //delay(400);
      //ctl.rotate(0, 0, 15);
      //Serial.println("Movement right backwards");
      delay(400);
      ctl.rotate(24, 0, 0);
      delay(200);
      //drop
      delay(200);
      ctl.rotate(-24, 0, 0);
      break;
    case HOME:
    Serial.println("HOME");
      delay(200);
      xMotor.disable();
  }
}

void armControlLoop() {
  if (availableObject) {
    sortCurrentObject();
    availableObject = false;
  }
}

void setupArm() {
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
  //movementMode = 1;
  Serial.begin(9600);
}
void saveArmSettings(ArmSettings* as, int address)
{
  EEPROM.writeInt(address, as->Movement1);
  address += sizeof(int);
  EEPROM.writeInt(address, as->Movement2);
  address += sizeof(int);
  EEPROM.writeInt(address, as->Movement3);
}

void readArnSettings(ArmSettings* as, int address)
{
 Serial.println(EEPROM.readInt(address));
 address += sizeof(int);
 Serial.println(EEPROM.readInt(address));
 address += sizeof(int);
 Serial.println(EEPROM.readInt(address));
}
