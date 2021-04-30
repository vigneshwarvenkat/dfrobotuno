int ledGreen = 9;
int ledYellow = 10;
int ledRed = 11;
float sinVal;
int toneVal;
unsigned long tepTimer;

void setup(){
  pinMode(8, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledRed, OUTPUT);
  Serial.begin(9600);  
  digitalWrite(ledGreen, LOW);
  digitalWrite(ledRed, LOW);
  digitalWrite(ledYellow, LOW);
}

void loop(){
  int val;
  double data;
  val = analogRead(0);//voltage reading by A0
  data = double(val*(5/10.24));
  if (millis()-tepTimer > 500){
    tepTimer = millis();
    Serial.print("Temperature : ");
    Serial.print(data);
    Serial.println("*C");
  }
  if(data>30){
    for(int x = 0; x < 180; x++){
      sinVal = (sin(x*(3.1412/180)));
      toneVal = 2000 + int(sinVal * 1000);
      tone(8,toneVal);
      delay(2);
    }
    digitalWrite(ledRed, HIGH);
  }
  else if(data <=30 && data >25){
    for(int x = 0; x < 180; x++){
      sinVal = (sin(x*(3.1412/180)));
      toneVal = 2000 + int(sinVal * 250);
      tone(8,toneVal);
      delay(2);
    }
    digitalWrite(ledGreen, HIGH);
  }
  else{ // temperature below 25
    noTone(8);
    digitalWrite(ledYellow, HIGH);
  }
}
