int ledPin = 10;
void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //first S
  for(int x = 0; x<3;x++){
    digitalWrite(ledPin, HIGH);
    delay(150);//delay for 150ms
    digitalWrite(ledPin, LOW);
    delay(100);//delay for 100ms
  }
  delay(100);//delay 100ms between letters
  //first O
  for(int x=0; x<3; x++){
    digitalWrite(ledPin, HIGH);
    delay(400);
    digitalWrite(ledPin, LOW);
    delay(100);
  }
  delay(100);
  //2nd S
  for(int x = 0; x<3; x++){
    digitalWrite(ledPin, HIGH);
    delay(150);
    digitalWrite(ledPin, LOW);
    delay(100);
  }
  delay(5000);
}
