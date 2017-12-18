//cpp for humidity sensor

#include <Arduino.h>
#include <humiditySensor.h>

humiditySensor::humiditySensor(int pin, int threshold) {
	_pin = pin;
	_threshold = threshold;
}

int humiditySensor::start() {
	int s = 1023 - analogRead(_pin);
	//Serial.print("Humidity sensor got: ");
	//Serial.println(s);
	return s >= _threshold ? 1 : 0;
}