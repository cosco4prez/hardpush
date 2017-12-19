#include <VirtualWire.h>
#include <obstacleSensor.h>
#include <humiditySensor.h>



// VARS FOR WIRE
uint8_t counter = 0; 
char msg[20];

int id;
int val;

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
  //IF SENSOR SEES SOMETHING, SEND 1 FOR INFRARED, SEND 2 FOR HUMIDITY
  if (obst.start()==1) {
    sprintf(msg, "%d.%d", 1,1);
  }
  else if (humid.start() == 1) {
    sprintf(msg, "%d.%d", 2,humid.value);
  }
  else {sprintf(msg, "%d.%d", 0,0);}
  
  //FOR DEBUGGING
  /*
  Serial.print("Infrared sensor returned: ");
  Serial.println(obst.start());
  Serial.print("Humidity sensor returned: ");
  Serial.println(humid.start());
  */
  Serial.println(msg);
  //Serial.println(humid.value);
  //Serial.println(msg[1]);
  
  //SEND
  vw_send((uint8_t *)msg, strlen(msg));
  vw_wait_tx();
}
