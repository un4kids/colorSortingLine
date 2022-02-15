

void setupRemoteCtl() {
  //trans
  radio.begin();
  radio.openWritingPipe(address);
  // radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
  //rcv
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  //radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}
void loopRemoteCtl() {
  //trans
  radio.write(& msgBuffer[5], sizeof(msgBuffer[5]));
  delay(2000);
  memset(msgBuffer[5], '0', sizeof(msgBuffer[0]) * 5);

  //rcv
  if (radio.available()) {
    char text[32] = "";
    radio.read(&text, sizeof(text));
    unpackMsg(text[32]);
    Serial.println(text[32]);
  }
}
void prepareMsg() {
  snprintf(msgBuffer, 5, "%c%c%c%c%c",
           (byte)Emergencystop, (byte)Setlinefaster, (byte)Setlineslower,
           (byte) (Ledbrightnesslevel & 0xff),
           (byte) ((Ledbrightnesslevel >> 8) & 0xff));
}
void unpackMsg(char*inBuffer) {
  bool emergencyStop = inBuffer[0];
  bool Setlinefaster = inBuffer[1];
  bool Setlineslower = inBuffer[2];
  int16_t Ledbrightnesslevel = 0;
  Ledbrightnesslevel  = inBuffer[3] & 0xff;
  Ledbrightnesslevel = inBuffer[4] & 0xff << 8;
}
