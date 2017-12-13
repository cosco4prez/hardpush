int obstacleSensor = 10; //pin for sensor

// GND = GND
// V+ = 5V
// Signal = Pin 10
// Enable = Not needed with jumper on

 
void setup ()
{
  Serial.begin(9600); // Init serial output
  pinMode (obstacleSensor, INPUT) ; // Init Sensor pin
}

void loop(){
 obstacle();
}
void obstacle ()
{
  bool val = digitalRead (obstacleSensor) ; // read sensor signal
  int sensorcount = 0;
  
  if (val == HIGH){ // if sensor signal, turn on led
    Serial.println("No obstacles");
    sensorcount = 0;
   }
  else {
    Serial.println("Obstacle, move bitch, get out the way!");
    sensorcount++; 
  }
  //Serial.println("------------------------------------");
  delay(1000); // interval 

  if (sensorcount >= 15) {
    Serial.println("Something is probably full!")
    //do stuff here
  }
}
