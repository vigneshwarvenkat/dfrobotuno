int greenLED = 8;
int yellowLED = 9;
int redLED = 10;

void setup() {
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);
}

void loop() {
  digitalWrite(redLED,HIGH);
  delay(5000);//delay 5 sec
  
  digitalWrite(yellowLED,HIGH);
  delay(2000);//delay 2 sec

  digitalWrite(redLED,LOW);
  digitalWrite(yellowLED,LOW);
  digitalWrite(greenLED,HIGH);
  delay(5000); //delay 5 sec

  digitalWrite(greenLED,LOW);
  digitalWrite(yellowLED,HIGH);
  delay(2000); // delay 2 sec

  digitalWrite(yellowLED, LOW);

}
