

void lineControlLoop()
{

}

void emergencyStop()
{
  while (emergencyStop = true)
  {
    Servo1.write(0);
  }
}
