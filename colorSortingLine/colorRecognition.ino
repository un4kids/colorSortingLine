
void colorRecognitionbegin()
{
  for (byte i=0;i<100;i++)
  {
     Serial.println cube[i].color.r = random (0,255);
   Serial.println cube[i].color.g = random (0,255);
   Serial.println cube[i].color.b = random (0,255);
  }
  Serial.begin(115200)
}

void colorRecognitionLoop()

{
  
  Serial.println (cube[i].color.r );
   Serial.println (cube[i].color.g);
   Serial.println (cube[i].color.b);
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
