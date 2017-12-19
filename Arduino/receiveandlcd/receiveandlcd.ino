/*
  LiquidCrystal Library - scrollDisplayLeft() and scrollDisplayRight()

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
*/

#include <Receiver.h>
#include <LiquidCrystal.h>

const int rs = 12, en = 10, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

String mystring = "";
int strLength = mystring.length();
int recPin = 11;
int transmFreq = 1000;

int baudRate = 9600;

int redPin = 6;
int greenPin = 7;
int bluePin = 8;
int whitePin = 9;

int maxBrightness = 255;
int minBrightness = 25;
int fadeAmount = 2;

int id, recvalue;
Receiver recv(recPin,transmFreq);

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(whitePin, OUTPUT);
  
  Serial.begin(baudRate);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  
  recv.setup();
}

void loop() {
  recv.start();
Serial.println(String("id: ") + String(recv.id) + String(" value: ") + String(recv.value));

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
    }
    
    lcd.print(mystring);
    delay(1250);

    //Serial.print("S: ");
  //Serial.println(s);
  //Serial.print("P: ");
  //Serial.println(p);
  lcd.clear();
  analogWrite(redPin, 0);
  analogWrite(greenPin, 0);
  analogWrite(bluePin, 0);
  analogWrite(whitePin, 0);

}

void softBlink(int pin, int maxValue, int minValue, int fadeAmount)
{
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
  // wait for 30 milliseconds to see the dimming effect
  
   }

