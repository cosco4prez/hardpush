//library for humidity sensor
#ifndef humiditySensor_h
#define humiditySensor_h

#include "Arduino.h"

class humiditySensor {
	public:
		humiditySensor(int pin, int threshold);
		int start();
	private:
		int _pin;
		int _threshold;
};

#endif