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
   
  if (val == HIGH) // if sensor signal, turn on led
  {
    Serial.println("No obstacles");
  }
  else
  {
    Serial.println("Obstacle, move bitch, get out the way!");
  }
  Serial.println("------------------------------------");
  delay(500); // interval 
}
