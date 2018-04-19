/*
* Arduino Wireless Communication Tutorial
*     Example 1 - Transmitter Code
*                
* by Dejan Nedelkovski, www.HowToMechatronics.com
* 
* Library: TMRh20/RF24, https://github.com/tmrh20/RF24/
*/

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN

const byte address[6] = "00001";
int counter = 0;

void setup() {
  pinMode(4, INPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
  Serial.begin(9600);
}

void loop() {
  int btn = digitalRead(4);

  if(btn == HIGH) {
    counter++;
    if(counter % 2 == 0) {
      const char text[] = "Hello World";
      radio.write(&text, sizeof(text));  
      digitalWrite(2, HIGH);
    } else {
      const char text[] = "Goodbye World";
      radio.write(&text, sizeof(text));          
      digitalWrite(3, HIGH);
    }
    delay(200);  
  }
    digitalWrite(3, LOW);
    digitalWrite(2, LOW);
}
