int obstacleSensor = 10; //pin for sensor
int obstacleCount = 0; // for differentiating between one time events and continuos obstacle
int obstacleInterval = 1000; // interval (ms)

// CABLING LAYOUT
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

  // if sensor signal, turn on led and report obstacle
  if (val == HIGH){
    //Serial.println("No obstacles");
    obstacleCount = 0;
   }
  else {
    //Serial.println("Obstacle");
    obstacleCount++;
    (obstacleCount >= 10) ? (Serial.println("Something is probably full!")) : Serial.println("Something was there, better wait if it's still there after next cycle");
    (obstacleCount >= 100) ? (obstacleCount = 0):false;
  }
  delay(obstacleInterval);
}
