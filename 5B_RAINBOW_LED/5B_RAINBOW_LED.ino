int redPin = 9;
int greenPin = 10;
int bluePin = 11;

void setup(){
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop(){
  colourRGB(238,130,238);//violet
  fadeOn(1000);


/*  colourRGB(75,0,130);//indigo
  fadeOn(1000);


  colourRGB(0,0,255);//blue
  fadeOn(1000);


  colourRGB(0,128,0);//green
  fadeOn(1000);


  colourRGB(255,255,0);//yellow
  fadeOn(1000);


  colourRGB(255,165,0);//orange
  fadeOn(1000);

  
  colourRGB(255,0,0);//red
  fadeOn(1000);*/

}

void colourRGB(int red, int green, int blue){
  analogWrite(redPin, constrain(red, 0, 255));
  analogWrite(greenPin, constrain(green, 0, 255));
  analogWrite(bluePin, constrain(blue, 0, 255));  
}

void fadeOn(unsigned int time){
  for(byte value = 0; value<256; value += 1){
    analogWrite(redPin, value);
    analogWrite(greenPin, value);
    analogWrite(bluePin, value);
    delay(time/(255/5));    
  }
  for(byte value = 255; value > 0; value -= 1){
    analogWrite(redPin, value);
    analogWrite(greenPin, value);
    analogWrite(bluePin, value);
    delay(time/(255/5));    
  }
}
