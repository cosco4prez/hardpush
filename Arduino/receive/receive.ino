#include <VirtualWire.h>

uint8_t currentPacket = 0; 

void setup() {
  /*
   * Set TX pin -> Connect FS1000A here
   */
  vw_set_tx_pin(12);
  /*
   * Set RX pin -> Connect XY-MK-5V here
   */
  vw_set_rx_pin(11);

  /*
   * Set transmission speed. Reciver and trasmitter have to use the same speed
   */
  vw_setup(1000);
  /*
   * Start to listen. Required on receiver side
   */
  vw_rx_start();

  Serial.begin(9600);
}

void loop() {
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;

  if (vw_get_message(buf, &buflen)) {
    /*
     * Recived packet, if checksum is correct, is avalable in buf variable
     * Send it over Serial, or do whatever you want with it
     */
    currentPacket = (uint8_t) buf[0];
    Serial.print("Got: ");
    Serial.println(currentPacket);
  }
  
}
