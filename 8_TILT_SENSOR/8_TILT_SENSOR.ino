int sensorLED = 13;
int sensorINPUT = 3;
unsigned char state = 0;

void setup(){
  pinMode(sensorLED, OUTPUT);
  pinMode(sensorINPUT, INPUT);
  attachInterrupt(1, blink, RISING); // trigger the function: blink whenever there is a RISE in value at digital pin 3
}

void loop(){
   if (state!=0){
    state = 0; //reset my state back to 0
    digitalWrite(sensorLED, HIGH); //what should happen when the interrupt is triggered?
    delay(500);
   }
   else{digitalWrite(sensorLED, LOW);} // what is the default state
  }

void blink(){
  state++;//increase the state when blink is triggered
}
