//#include "Sim800L.h"        // Include the library for the SIM800L module
//#include <TinyGsmClient.h>     // Include the library for the TinyGSM client
#include "Sim800L-Arduino-Library-revised/Sim800L.h"
#include <SoftwareSerial.h> 
#include <Arduino.h>              

#define RX  23
#define TX  22

Sim800L GSM(RX, TX);

/*
 * In alternative:
 * Sim800L GSM;                       // Use default pinout
 * Sim800L GSM(RX, TX, RESET);        
 * Sim800L GSM(RX, TX, RESET, LED);
 */

char* text;
char* number;
bool error; 					//to catch the response of sendSms


void setup(){
	GSM.begin(); 			
  GSM.Debug = true; // Enable debug mode to see AT command responses in Serial Monitor
  Serial.begin(9600);

  String pin = "2250";

  if (GSM.setPIN(pin)) Serial.println("Pin set");
  else Serial.println("Pin NOT set");

  delay(8000); //wait for the module to be ready
  //
  Serial.println("get Operator"); //ping the module to check if it is ready
  Serial.println(GSM.getOperator());
	text="Testing Sms";  		//text for the message. 
	number="+4916094842537"; 		//change to a valid number.
	error=GSM.sendSms(number,text);
  Serial.println("Message sent"); //message sent
  Serial.println(error); //error is true if the message was sent, false if not.
	GSM.getCallStatus();

  GSM.callNumber(number);
  Serial.println("call"); //message sent
	// OR 
	//Sim800L.sendSms("+540111111111","the text go here")
  GSM.checkStatus();
}

void loop(){
	//do nothing
}
