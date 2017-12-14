// cpp for obstacle sensor
#include "Arduino.h"
#include "obstacleSensor.h"



obstacleSensor::obstacleSensor(int pin, int interval) {
	pinMode(pin, INPUT);
	_pin = pin;
	_interval = interval;
	_count = 0;
}

void obstacleSensor::start() { 
	bool val = digitalRead (_pin) ; // read sensor signal
// if sensor signal, turn on led and report obstacle
	if (val == HIGH){
		_count = 0;
	}
	else {
		_count++;
		//if seen for 10 * interval
		(_count >= 10) ? (Serial.println("Something is probably full!")) : Serial.println("Something was there, better wait if it's still there after next cycle");
		//if seen for 100 reset (no overflow)
		(_count >= 100) ? (_count = 0):false;
	}
	delay(_interval);
}
