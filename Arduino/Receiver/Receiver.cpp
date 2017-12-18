// cpp for receiver
#include "Arduino.h"
#include "Receiver.h"
#include "VirtualWire.h"

Receiver::Receiver(int rx_pin, int transmit_speed) {
	_rx_pin = rx_pin;
	_transmit_speed = transmit_speed;
	uint8_t _currentPacket; 
}

void Receiver::setup() {
	vw_set_rx_pin(_rx_pin);
	vw_setup(_transmit_speed);
	vw_rx_start();
}

int Receiver::start() {
	uint8_t buf[VW_MAX_MESSAGE_LEN];
	uint8_t buflen = VW_MAX_MESSAGE_LEN;
	
  if (vw_get_message(buf, &buflen)) {
    _currentPacket = (uint8_t) buf[0];
    Serial.print("Receiver got: ");
    Serial.println(_currentPacket);
	return _currentPacket;
	}
}