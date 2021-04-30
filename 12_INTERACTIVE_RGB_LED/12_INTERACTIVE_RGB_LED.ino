int redPin = 9; //digitial output PWMs for LED
int greenPin = 10;
int bluePin = 11;

int potRedPin = 0;//analog input pins for potentiometer
int potGreenPin = 1;
int potBluePin = 2;

void setup(){
  
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  Serial.begin(9600);
}

void loop(){

  /* These values will be from 0 to 1023*/
  int redTurn = analogRead(0); //read the value of my potentiometer for red LED 
  int greenTurn = analogRead(1); //read the value of my potentiometer for green LED
  int blueTurn = analogRead(2); //read the value of my potentiometer for blue LED

  /*Convert these values to 0-255, since that is the constraint for our LED*/
  int val1 = map(redTurn, 0, 1023, 0, 255); //map(variable, min. input variable, max. input variable, min. output variable, max. output variable)
  int val2 = map(greenTurn, 0, 1023, 0, 255);
  int val3 = map(blueTurn, 0, 1023, 0, 255);

  /*We want to show the value of R,G & B on our serial monitor*/
  Serial.print("Red: ");
  Serial.print(val1);
  Serial.print(" Green: ");
  Serial.print(val2);
  Serial.print(" Blue: ");
  Serial.print(val3);
  
  /*call our RGB function*/
  colourRGB(val1,val2,val3); //convert everythign to visible LED values
  
}

void colourRGB(int red, int green, int blue){
  
  analogWrite(redPin, constrain(red, 0, 255));
  analogWrite(greenPin, constrain(green, 0, 255));
  analogWrite(bluePin, constrain(blue, 0, 255));
  
}
