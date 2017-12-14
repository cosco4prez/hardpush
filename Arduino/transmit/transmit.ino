#include <VirtualWire.h>
#include <obstacleSensor.h>
uint8_t counter = 0; 
char msg[1];
obstacleSensor obst(10,1000);

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
    
}

void loop() {

  (obst.start()== 1) ? msg[0] = 1 : msg[0] = 0;
  /*
   * Send buffer
   */
  vw_send((uint8_t *)msg, 1);
  /*
   * Wait until trasmission is complete
   */
  vw_wait_tx();
  delay(1000);
}
