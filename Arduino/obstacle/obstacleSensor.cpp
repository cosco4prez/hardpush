// cpp for obstacle sensor
#include "Arduino.h"
#include "obstacleSensor.h"



obstacleSensor::obstacleSensor(int pin, int interval) {
	pinMode(pin, INPUT);
	_pin = pin;
	_interval = interval;
	_count;
}

int obstacleSensor::start() { 
	bool val = digitalRead (_pin); // read sensor signal
	int s = 0;
// if sensor signal, turn on led and report obstacle
	if (val == HIGH){
		_count = 0;
		s = 0;
	}
	else {
		_count++;
		//if seen for 100 reset (no overflow)
		//if seen for 10 * interval
		if (_count >= 5) {
			//Serial.println("Probably full!");
			s = 1;
		}
		else {
			//Serial.println("Something was there, better wait if it's still there after next cycle");
			s = 0;
		}
		(_count >= 100) ? (_count = 0):false;
	}
	delay(_interval);
	return s;
}
