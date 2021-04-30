int carRed = 12;//car traffic lights
int carYellow = 11;
int carGreen = 10;
int button = 9;//pushbutton pin
int pedRed = 8;//pedestrian lights
int pedGreen = 7;
int crossTime = 5000; // 5 sec for pedestrians to cross
long changeTime; //time button is pressed

void setup() {
  pinMode(carRed, OUTPUT);
  pinMode(carYellow, OUTPUT);
  pinMode(carGreen, OUTPUT);
  pinMode(pedRed, OUTPUT);
  pinMode(pedGreen, OUTPUT);
  pinMode(button, INPUT);
  digitalWrite(carGreen, HIGH); // initialize green traffic light as on
  digitalWrite(pedRed, HIGH); //initialize pedestrian red as on
}

void loop() {
  int state = digitalRead(button); // state takes the state of button
  if(state == HIGH && (millis()-changeTime) > 5000){ //if the button is pressed & 5 sec have passed after pressed
    changeLights(); // call changeLights() function

    /*millis() returns the number of millisec since arduino
    began running the current program*/
  }
}

void changeLights(){
  digitalWrite(carGreen, LOW); // green traffic light off
  digitalWrite(carYellow, HIGH); // yellow traffic light is on
  delay(2000); // wait 2 sec

  digitalWrite(carYellow, LOW); // yellow traffic light off
  digitalWrite(carRed, HIGH); // red traffic light on
  delay(1000); // wait 1 sec

  digitalWrite(pedRed, LOW);
  digitalWrite(pedGreen, HIGH);

  delay(crossTime); // time fo rcrossing street

  for(int x = 0; x < 10; x++){ //flashing pedestrian green light
    digitalWrite(pedGreen, HIGH);
    delay(250);
    digitalWrite(pedGreen, LOW);
    delay(250);
  }

  digitalWrite(pedRed, HIGH);
  delay(500);

  digitalWrite(carRed, LOW);
  digitalWrite(carYellow, HIGH);
  delay(1000);

  digitalWrite(carYellow, LOW);
  digitalWrite(carGreen, HIGH);

  changeTime = millis(); // record duration since last change
}
