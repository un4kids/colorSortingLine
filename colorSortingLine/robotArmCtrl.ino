void isObjectToSortIsPresent() {
  if (digitalRead(sensPin) == HIGH) {
    availableObject = true;
  }
}

void sortCurrentObject() {
  Serial.print(ObjectColor);
  switch (ObjectColor) {
    case MOVE_1:
      xMotor.enable();
      ctl.rotate(0, 18, 12);
      delay(200);
      break;
    case MOVE_2:
      ctl.rotate(0, -4, -8);
      ctl.rotate(2, 4, 8);
      delay(200);
      break;
    case MOVE_3:
      // ctl.rotate(2, 4, 8);
      ctl.rotate(0, -4, -8);
      ctl.rotate(2, 4, 8);
      delay(200);
      break;
    case HOME:
      ctl.rotate(-6.0, -14.5, -4.5);
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
  movementMode = 1;
  Serial.begin(115200);
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
