int ledRed = 3;
int ledYellow_1 = 5;
int ledYellow_2 = 10;

void setup() {
  pinMode(ledRed, OUTPUT);
  pinMode(ledYellow_1, OUTPUT);
  pinMode(ledYellow_2, OUTPUT);
}

void loop() {
  brightSideYellow1(500,5);
}


void brightSideYellow1(unsigned int time, int pin_number){
  for(int x = 0;;x++){
    int value = random(120)+135;
    int value2 = random(90)+(255-90);
    int value3 = random(100) + 155;
    analogWrite(ledYellow_1, value);
    analogWrite(ledRed, value2);
    analogWrite(ledYellow_2, value3);
    delay(time/(255/5));
  }
}
