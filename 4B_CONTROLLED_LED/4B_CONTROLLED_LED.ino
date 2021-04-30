int pushBrighter = 9;
int pushDimmer = 10;
int led = 11;
int brightness = 255;

void setup(){
  pinMode(pushBrighter, INPUT);
  pinMode(pushDimmer, INPUT);
  pinMode(led, OUTPUT);
  analogWrite(led, brightness);
}

void loop(){
  int brighter = digitalRead(pushBrighter);
  int dimmer = digitalRead(pushDimmer);
  if (brighter == 1){
    increase();
  }
  else if (dimmer == 1){
    decrease();
  }
}

void increase(){
  brightness += 5;
  if (brightness < 256){
    analogWrite(led, brightness);
    delay(3000/(255/5));
  }
  else{
    brightness = 255;
    analogWrite(led, brightness);
    delay(3000/(255/5));
  }
}

void decrease(){
  brightness -= 5;
  if(brightness >=0){
    analogWrite(led, brightness);
    delay(3000/(255/5));
  }
  else{
    brightness = 0;
    analogWrite(led, brightness);
    delay(3000/(255/5));
  }
}
