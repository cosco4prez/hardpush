// Description: Receive signals from sensors and print to LCD (webserver only if lcd pins changed)
// Authors: K.H., K.L, L.W., F.S.
// Last Change: 19.12.2017

#include <Receiver.h>
#include <LiquidCrystal.h>
#include <SPI.h>
#include <Ethernet.h>
#include <SimpleTimer.h>

//Timer object
SimpleTimer timer;
bool isdone = 0;
//Server
boolean incoming = 0;
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
//IPAddress ip(10, 14, 215, 101); // IP address, see setup
EthernetServer server(80);  // create a server at port 80
EthernetClient client;
//LCD
const int rs = 22, en = 24, d4 = 5, d5 = 4, d6 = 2, d7 = 26;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
String mystring = "";
int strLength = mystring.length();
//Receiver
int recPin = 3;
int transmFreq = 1000;
//Serial
int baudRate = 9600;
//LED
int redPin = 6;
int greenPin = 7;
int bluePin = 8;
int whitePin = 9;
int maxBrightness = 255;
int minBrightness = 25;
int fadeAmount = 2;
//Receiver class
Receiver recv(recPin,transmFreq);

void setup() {
  //Set up LCD (columns, rows)
  lcd.begin(16, 2);
  delay(1000);
  //Set up LED
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(whitePin, OUTPUT);
  //Set up Serial
  Serial.begin(baudRate);
  //setup server
  Ethernet.begin(mac); //use DHCP, add ip for static assignment
  server.begin();
  //Set up receiver
  recv.setup();
  delay(500);
  printIP();
}

void loop() {
  // poll timer
  timer.run();
  //start receiving
  recv.start();
  //IP
  //start webserver
  webserver();
  //DEBUGGING
  //printIP();
  //Serial.println(freeRam());
  //Serial.println(mystring);
  //Serial.println(String("id: ") + String(recv.id) + String(" value: ") + String(recv.value));
  //Serial.println(isdone);
  //switch on receiver id (sensor id)
switch (recv.id) {
  case 1:
    mystring = "Trash!";
    //analogWrite(redPin, 255);
    softBlink(redPin, maxBrightness, minBrightness, fadeAmount);
    break;
  case 2:
    mystring = "Plants!";
    softBlink(greenPin, maxBrightness, minBrightness, fadeAmount);
    break;
  default:
    mystring = "Push Harder!";
    if (isdone == 1) {mystring = "Laundry!";}
    }
  //print to LCD
  lcd.print(mystring);
  delay(1000);
  lcd.clear();
  //clear LEDs
  analogWrite(redPin, 0);
  analogWrite(greenPin, 0);
  analogWrite(bluePin, 0);
  analogWrite(whitePin, 0);
}

void softBlink(int pin, int maxValue, int minValue, int fadeAmount) {
  int brightness = minValue;
  
  while (brightness <= maxValue){
    analogWrite(pin, brightness);
    brightness = brightness + fadeAmount;

    if (brightness >= maxValue) {
      fadeAmount = -fadeAmount;
    }
    if (brightness < minValue){
      break;
    }
    delay(10);
    }
}

int webserver() {
  EthernetClient client = server.available();  // try to get client
  if (client) {  // got client?
    boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {   // client data available to read
        char c = client.read();
        // if you've gotten to the end of the line (received a newline
        // character) and the line is blank, the http request has ended,
        // so you can send a reply
        
        //reads URL string from $ to first blank space
        if(incoming && c == ' '){incoming = 0;}
        if(c == '$') {incoming = 1;}

        //Checks for the URL string $1 or $2
        if(incoming == 1){
          Serial.println(c);
          if(c == '1'){
            Serial.println("ON");
            timer.setTimeout(10000, tdone);
            client.println("HTTP/1.1 200 OK");
            client.println("Content-Type: text/html");
            client.println("Connection: close");  // the connection will be closed after completion of the response
            client.println();
            client.println("<!DOCTYPE HTML>");
            client.println("<html>");
            client.println("Timer ON");
            client.println("</html>");
            client.stop();
          }
          if(c == '2'){
            Serial.println("OFF");
            client.println("HTTP/1.1 200 OK");
            client.println("Content-Type: text/html");
            client.println("Connection: close");  // the connection will be closed after completion of the response
            client.println();
            client.println("<!DOCTYPE HTML>");
            client.println("<html>");
            client.println("Timer OFF");
            client.println("</html>");
            client.stop();
            isdone = 0;
          }
        }
        
        if (c == '\n') {
          // you're starting a new line
          currentLineIsBlank = true;} 
        else if (c != '\r') {
          // you've gotten a character on the current line
          currentLineIsBlank = false;}
        }// end if (client.available())
        return 1;
      } // end while (client.connected())
    delay(10);      // give the web browser time to receive the data
    client.stop();// close the connection
  } // end if (client)
}

void printIP() {
  char ip[16];
  sprintf(ip, "%d.%d.%d.%d", Ethernet.localIP()[0], Ethernet.localIP()[1], Ethernet.localIP()[2], Ethernet.localIP()[3]);
  Serial.print("My IP address: ");
  Serial.println(ip);
}

void tdone() {
  isdone = 1;
}

int freeRam () {
  extern int __heap_start, *__brkval;
  int v;
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);
}
