//library for receiver
#ifndef obstacleSensor_h
#define obstacleSensor_h

#include <Arduino.h>

class Receiver {
	public:
		Receiver(int rx_pin, int _transmit_speed);
		void setup();
		uint8_t start();
		int id;
		int value;
	private:
		int _rx_pin;
		int _transmit_speed;
};

#endif