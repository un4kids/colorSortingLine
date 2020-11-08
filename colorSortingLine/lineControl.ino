

void lineControlLoop()
{

}

void emergencyStop()
{
  while (emergencyStop = true)
  {
    digitalWrite(in_1, LOW) ;
    digitalWrite(in_2, LOW) ;
  }
}
