
void colorRecognitionbegin()
{

}

void colorRecognitionLoop()
{
  if (isObjectPresent())
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
    else if (compareCurrentObject(currentObject, ethalonObject_2))
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
bool isObjectPresent() {
  if (digitalRead(photoResistor) == LOW)
  {
    return true;
  }
  return false;
}

object_color_t readCurrentColor()
{

}

bool compareCurrentObject(object_color_t currentObj, object_color_t objectToCompare)
{


}
