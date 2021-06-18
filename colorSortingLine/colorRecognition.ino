
void colorRecognitionSetup()
{
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);

  // Setting frequency-scaling to 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);

  Serial.begin(9600);
}

void colorRecognitionLoop()
{
  isObjectPresent();
  if (objectIsPresent)
  {
    Serial.println("is present");
    throwUnrecognizedObject = false;

    currentObject = readCurrentColor();
    if (compareCurrentObject(currentObject, ethalonObject_1))
    {
      currentColorId = RED;

    }
    else if (compareCurrentObject(currentObject, ethalonObject_2))
    {
      currentColorId = GREEN;

    }
    else if (compareCurrentObject(currentObject, ethalonObject_3))
    {
      currentColorId = BLUE;

    }
    else
    {
      throwUnrecognizedObject = true;
      currentColorId = NAN_COLOR;
    }
  }
  else {
    Serial.println("is not present");
  }



}

void isObjectPresent() {
  if (digitalRead(photoResistor) == LOW)
  {
    objectIsPresent =  true;
  }
  objectIsPresent =  false;
}

object_color_t readCurrentColor()
{

}

bool compareCurrentObject(object_color_t currentObj, object_color_t objectToCompare)
{


}
void mesureColor ()
{
  if (millis() - mesureDelayR >= 20)
  {
    mesureDelayR = millis();
    currentObject.R = mesureColorComponent(MEASURE_MODE_R);
    Serial.print(currentObject.R);
    Serial.print(" ");
  }
  if (millis() - mesureDelayG >= 40)
  {
    mesureDelayG = millis();
    currentObject.G = mesureColorComponent(MEASURE_MODE_G);
    Serial.print(currentObject.G);
    Serial.print(" ");
  }
  if (millis() - mesureDelayB >= 60)
  {
    mesureDelayB = millis();
    currentObject.B = mesureColorComponent(MEASURE_MODE_B);
    Serial.println(currentObject.B);
  }
}
int mesureColorComponent(int mode)
{
  if (mode == MEASURE_MODE_R)
  {
    digitalWrite(S2, LOW);
    digitalWrite(S3, LOW);
    return pulseIn(sensorOut, LOW);
  }
  else if (mode == MEASURE_MODE_G)
  {
    digitalWrite(S2, HIGH);
    digitalWrite(S3, HIGH);
    return pulseIn(sensorOut, LOW);
  }
  else  (mode == MEASURE_MODE_B);
  {
    digitalWrite(S2, LOW);
    digitalWrite(S3, HIGH);
    return pulseIn(sensorOut, LOW);
  }
}
void writeObject_color(object_color_t* obj)
{
  EEPROM.writeInt(addr, obj->R );
  addr += sizeof(uint8_t);
  EEPROM.writeInt(addr, obj->G );
  addr += sizeof(uint8_t);
  EEPROM.writeInt(addr, obj->B );
  addr += sizeof(uint8_t);

}
void readObject_color(object_color_t* obj)
{

  obj->R = EEPROM.readInt(addr);
  addr += sizeof(int);
  Serial.println(EEPROM.readInt(addr));
  obj->G = EEPROM.readInt(addr);
  addr += sizeof(int);
  Serial.println(EEPROM.readInt(addr));
  obj->B = EEPROM.readInt(addr);
  addr += sizeof(int);
  Serial.println(EEPROM.readInt(addr));
  addr = 0;
}
