// cpp for obstacle sensor
#include "Arduino.h"
#include "obstacleSensor.h"



obstacleSensor::obstacleSensor(int pin, int interval) {
	pinMode(pin, INPUT);
	_pin = pin;
	_interval = interval;
	_count;
}

void obstacleSensor::start() { 
	bool val = digitalRead (_pin) ; // read sensor signal
// if sensor signal, turn on led and report obstacle
	if (val == HIGH){
		//Serial.println("No obstacles");
		_count = 0;
	}
	else {
		//Serial.println("Obstacle");
		_count++;
		(_count >= 10) ? (Serial.println("Something is probably full!")) : Serial.println("Something was there, better wait if it's still there after next cycle");
		(_count >= 100) ? (_count = 0):false;
	}
	delay(_interval);
}
