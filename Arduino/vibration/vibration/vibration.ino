int vibrationLed = 13 ;// led pin
int vibrationSensor = 10; // sensor pin

  
void setup (){
  pinMode (vibrationLed, OUTPUT) ; // Initialisierung Ausgangspin
  pinMode (vibrationSensor, INPUT) ; // Initialisierung Sensorpin
}
   
void loop ()
{
  val = digitalRead (vibrationSensor);
  if (val == HIGH) {
    digitalWrite (vibrationLed, LOW);
  }
  else {
    digitalWrite (vibrationLed, HIGH);
    delay(2000); //light up for 2s
    digitalWrite (vibrationLed, LOW);
    delay(200);
  }
}
