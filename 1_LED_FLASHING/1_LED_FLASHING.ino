/* Project 1*/

int ledPin = 10;
void setup(){
  pinMode(ledPin, OUTPUT);  
}
void loop(){
  digitalWrite(ledPin, HIGH); //turn on my led
  delay(1000); //delay for 1 sec
  digitalWrite(ledPin, LOW); //turn off my led
  delay(1000); //delay for 1 sec
}
