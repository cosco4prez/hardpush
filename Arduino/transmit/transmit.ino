#include <VirtualWire.h>
#include <obstacleSensor.h>
#include <humiditySensor.h>



// VARS FOR WIRE
uint8_t counter = 0; 
char msg[1];

//INIT SENSOR CLASS
obstacleSensor obst(2,1000);
humiditySensor humid(A0, 30);

void setup() {
    //SETUP VIRTUAL WIRE
    vw_set_tx_pin(12);
    vw_setup(1000);
    
    //FOR DEBUGGING
    Serial.begin(9600); 
}

void loop() {
  //IF SENSOR SEES SOMETHING, SEND 1 FOR INFRARED, SEND 2 FOR HUMIDITY, OTHERWISE SEND 0
  ((obst.start()== 1) ? msg[0] = 1 : msg[0] = 0 ) || ((humid.start() == 1) ? msg[0] = 2 : msg[0] = 0);
  
  
  //FOR DEBUGGING
  Serial.print("Infrared sensor returned: ");
  Serial.println(obst.start());
  Serial.print("Humidity sensor returned: ");
  Serial.println(humid.start());

  //SEND
  vw_send((uint8_t *)msg, 1);
  vw_wait_tx();
}
