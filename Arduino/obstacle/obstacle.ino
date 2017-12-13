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
  int obstacleCount = 0;
  
  if (val == HIGH){ // if sensor signal, turn on led
    Serial.println("No obstacles");
    obstacleCount = 0;
   }
  else {
    Serial.println("Obstacle, move bitch, get out the way!");
    obstacleCount++; 
  }
  //Serial.println("------------------------------------");
  delay(1000); // interval 

  if (obstacleCount >= 10) { //if X concurrent obstacles; it's probably full
    Serial.println("Something is probably full!")
    //do stuff here
  }
}
