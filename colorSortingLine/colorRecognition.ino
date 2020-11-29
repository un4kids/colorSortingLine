
void colorRecognitionbegin()
{
  
}
void colorRecognitionLoop()
{
  if(isObjectPresent())
  {
    Serial.println("is present");
  }
  else{
     Serial.println("is not present");
  }
  


}
bool isObjectPresent() {
  if (digitalRead(2) == LOW)
  {
    return true;
  }
  return false;
}
