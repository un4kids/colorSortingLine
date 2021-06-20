
//#define RECV 1
#define TRANSMITTER 2
// led 3
// rbtt 8
// lbtt 7
// stobt 6
// onoff logic 5

void setupRemoteCtl() {
  #ifdef TRANSMITTER
  //trans
     Serial.begin(9600);

  radio.begin();
  radio.openWritingPipe(address);
 // radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
  #endif
  #ifdef RECV
  //rcv 
   Serial.begin(9600);
   radio.begin();
   radio.openReadingPipe(0, address);
    //radio.setPALevel(RF24_PA_MIN);
   radio.startListening();
   #endif
}
void loopRemoteCtl() {
  //Serial.println("eho");
  #ifdef TRANSMITTER
  prepareMsg();
  radio.write(& msgBuffer[5], sizeof(msgBuffer[5]));
 delay(500);  
memset(msgBuffer[5],'0',sizeof(msgBuffer[0])*5);
 Serial.println(Emergencystop);
  #endif
//  #ifdef RECV
//  //rcv
//   if (radio.available()) {
//    char text[32] = "";
//    radio.read(&text, sizeof(text));
//    unpackMsg(text[32]);
//    Serial.println(text[32]);
//  }
//  #endif
}
void prepareMsg() {
  #ifdef TRANSMITTER
  snprintf(msgBuffer, 5, "%c%c%c%c%c",
           (byte)Emergencystop, (byte)Setlinefaster, (byte)Setlineslower,
           (byte) (Ledbrightnesslevel & 0xff),
           (byte) ((Ledbrightnesslevel >> 8) & 0xff));
           #endif
}
void unpackMsg(char*inBuffer){
  #ifdef RECV
   bool Emergencystop = inBuffer[0];
   bool Setlinefaster = inBuffer[1];
   bool Setlineslower = inBuffer[2];
   int16_t Ledbrightnesslevel = 0;
   Ledbrightnesslevel  = inBuffer[3] & 0xff;
   Ledbrightnesslevel = inBuffer[4] & 0xff << 8;
   Serial.println(Emergencystop);
   #endif
}
