#include <IRremote.h>
int RECV_PIN = 11;
int relayPin = 10;
boolean relayState = LOW;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup(){
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(relayPin, OUTPUT);
}

void loop(){
  if(irrecv.decode(&results)){
    Serial.println(results.value, HEX);
    
    //if the code received from the IR remote is the code from power button,
    if(results.value == 0xFD00FF){
      relayState = !relayState;           //reverse the state of my relay
      Serial.print(relayState);
    }
    irrecv.resume();
  }
  if(relayState == HIGH){
    digitalWrite(relayPin, HIGH);
  }
  else{digitalWrite(relayPin, LOW);}
}
