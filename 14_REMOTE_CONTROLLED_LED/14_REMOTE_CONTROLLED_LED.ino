#include <IRremote.h>

int RECV_PIN = 11;
int ledPin = 10;
IRrecv irrecv(RECV_PIN);
decode_results results;
boolean ledState = LOW;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(ledPin, OUTPUT);
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);

    if(results.value == 0xFD00FF){//if it matches the power code
      ledState = !ledState;
      digitalWrite(ledPin, ledState);
    }
    irrecv.resume(); // Receive the next value
  }
}
