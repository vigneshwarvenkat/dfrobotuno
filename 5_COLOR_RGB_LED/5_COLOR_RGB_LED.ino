int redPin = 9;
int greenPin = 10;
int bluePin = 11;

void setup(){
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop(){
  colourRGB(random(0,255), random(0,255), random(0,255));
  delay(100);
}

void colourRGB(int red, int green, int blue){
  analogWrite(redPin, constrain(red, 0, 255));
  analogWrite(greenPin, constrain(green, 0, 255));
  analogWrite(bluePin, constrain(blue, 0, 255));  
}
