//library for obstacle sensor
#ifndef obstacleSensor_h
#define obstacleSensor_h

#include "Arduino.h"

class obstacleSensor {
	public:
		obstacleSensor(int pin, int interval);
		void start();
	private:
		int _pin;
		int _interval;
		int _count = 0;
};

#endif