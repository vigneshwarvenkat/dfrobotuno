float sinVal;
int toneVal;

void setup(){
  pinMode(8,OUTPUT);
}

void loop(){
  for(int x=0; x<180; x++){
    sinVal = (sin(x*(3.14159/180)));
    toneVal = 1000 + int((sinVal));
    tone(8, toneVal);
    delay(2);
  }
}
