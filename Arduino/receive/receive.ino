//#include <VirtualWire.h>
#include <Receiver.h>
//uint8_t currentPacket = 0; 

Receiver recv(11, 1000);

void setup() {
  
  //vw_set_tx_pin(12);
 
  //vw_set_rx_pin(11);

  //vw_setup(1000);
  
  //vw_rx_start();

  Serial.begin(9600);
  recv.setup();
}

void loop() {
  //uint8_t buf[VW_MAX_MESSAGE_LEN];
  //uint8_t buflen = VW_MAX_MESSAGE_LEN;

  //if (vw_get_message(buf, &buflen)) {
   
   // currentPacket = (uint8_t) buf[0];
    //Serial.print("Got: ");
    //Serial.println(currentPacket);
  //}

  recv.start();
}
