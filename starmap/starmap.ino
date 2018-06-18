//WARNING: DO NOT USE PIN 0 and 1 (Tx/Rx) on ARDUINO UNO!!!!
//WARNING: DO NOT USE SINGLE QUOTES WHEN DEBUGGING WITH SERIAL.PRINT!!

// wiring:
// https://github.com/rwaldron/johnny-five/wiki/Getting-Started-with-Johnny-Five-and-HC-05-Bluetooth-Serial-Port-Module

// 5V -> VCC
// GND -> GND
// 10 -> TX
// 11 -> RX

// HC06 red light flashes fast when: ?
// 2 flashes, long pause = can send/receive

#include <SoftwareSerial.h>

String dataReceived;

SoftwareSerial BTSerial(10, 11);
int LED = 13;


void function0()
{
//  Serial.println("func0");
  digitalWrite(LED, LOW);
}
void function1()
{
//  Serial.println("func1");
  digitalWrite(LED, HIGH);
}
 


void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);
  
}

void loop() {

  
   // We (Arduino) send a signal to Android
   // open Serial Monitor (ctrl+shift+M) and enter arbitrary text via keyboard, click Send
   char c;  
   if (Serial.available()) {  
     c = Serial.read();        
     Serial.println(c);             // Write the character to the Serial Monitor  
     BTSerial.write (c);           // Write the character to Bluetooth (aka Android)
   }  

  // Android sends a signal to us (Arduino)
  if (BTSerial.available()) {
    char in = BTSerial.read();
    dataReceived += in;

    Serial.println(dataReceived);
  //   Serial.println("btserial available");
  //   char in = BTSerial.read();
  //   if(in == '0') {
  //     function0();
  //   }
  //   if(in == '1') {
  //     function1();
  //   }
  }

//  delay(50);
}

