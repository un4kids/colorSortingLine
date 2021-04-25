

void setupRemoteCtl() {
  radio.begin();
  radio.openWritingPipe(address);
 // radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}
void loopRemoteCtl() {
  radio.write(& msgBuffer[5], sizeof(msgBuffer[5]));
  delay(2000);
  memset(msgBuffer[5],'0',sizeof(msgBuffer[0])*5);
}
void prepareMsg() {
  snprintf(msgBuffer, 5, "%c%c%c%c%c",
           (byte)Emergencystop, (byte)Setlinefaster, (byte)Setlineslower,
           (byte) (Ledbrightnesslevel & 0xff),
           (byte) ((Ledbrightnesslevel >> 8) & 0xff));
}
