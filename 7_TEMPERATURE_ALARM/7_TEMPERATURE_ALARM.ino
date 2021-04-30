float sinVal;
int toneVal;
unsigned long tepTimer;

void setup(){
  pinMode(8,OUTPUT);  //buzzer
  Serial.begin(9600); //configure baud rate to 9600bps
}

void loop(){
  int val; //save value of LM35 (temp sensor)
  double data; //save the converted value of temperature
  val = analogRead(0);//read value at analog pin 0
  data = (double)val*(5/10.24); //conver voltage value to a temperature
  if(data > 30){//if temp is higher than 30
    for(int x = 0; x < 180; x++){
      sinVal = (sin(x*(3.1412/180)));
      toneVal = 1000 + int(sinVal*1000);
      tone(8, toneVal);
      delay(2);
    }
  }
  else{
    noTone(8);
    }
  if(millis() - tepTimer > 50){//every 50 ms the serial port prints out an output
    tepTimer = millis(); //reset tepTimer value
    Serial.print("Temperature is : ");
    Serial.print(data); // prints our serial temperature data
    Serial.println("C");//println prints our on the next line
  }
}
