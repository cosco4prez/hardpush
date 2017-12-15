//library for receiver
#ifndef obstacleSensor_h
#define obstacleSensor_h

#include <Arduino.h>

class Receiver {
	public:
		Receiver(int rx_pin, int _transmit_speed);
		void setup();
		char start();
	private:
		int _rx_pin;
		int _transmit_speed;
		uint8_t _currentPacket = 0;
};

#endif