/***5 steps to using IR coding
   1: include library
   2: set a pin as the ir receiver
   3: decode_results to store the results received
   4: set baud rate
   5: boot IR detection to start
** */

#include <IRremote.h>
int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results code_received;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (irrecv.decode(&code_received)) {
    Serial.println("Input code:");
    Serial.println(code_received.value, HEX);
    irrecv.resume();
  }
}
