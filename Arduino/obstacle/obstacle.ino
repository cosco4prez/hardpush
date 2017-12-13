int obstacleSensor = 10; //pin for sensor
int obstacleCount = 0;

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
  
  
  if (val == HIGH){ // if sensor signal, turn on led
    Serial.println("No obstacles");
    obstacleCount = 0;
   }
  else {
    Serial.println("Obstacle");
    obstacleCount++;
    (obstacleCount >= 10) ? (Serial.println("Something is probably full!")) : Serial.println("Something was there, better wait if it's still there after next cycle");
    (obstacleCount >= 100) ? (obstacleCount = 0):false;
  }
  //Serial.println("------------------------------------");
  delay(1000); // interval
  
}
