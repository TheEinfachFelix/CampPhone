#include <Arduino.h>
#include "Sim800L_Lib\Sim800L.hpp"


#define RX 46
#define TX 9
//#define RX 9
//#define TX 46

Sim800L GSM(RX, TX);

 
void setup() {
  GSM.Debug = true;
  delay(4000);
  Serial.begin(9600);
  GSM.begin();    
  String pin = "2250";
  
  if (GSM.setPIN(pin)) Serial.println("Pin set");
  else 
  {
    do
    {
      Serial.println("Pin ERROR");
      delay(1000);
    } while (GSM.setPIN(pin));
  }

  Serial.println("OK lets Go!");
}

void loop() {
  // put your main code here, to run repeatedly:
  //GSM.checkStatus();
  if (GSM.getCallStatus() == 3) {
    Serial.println("Incoming call...");
    GSM.answerCall();
  }
  delay(300);
}
