    /*
    * Arduino Wireless Communication Tutorial
    *       Example 1 - Receiver Code
    *                
    * by Dejan Nedelkovski, www.HowToMechatronics.com
    * 
    * Library: TMRh20/RF24, https://github.com/tmrh20/RF24/
    */

// for use with NRF 24L01 (which allows arduino-arduino comms, but doesn't seem to allow arduino-android easily)

    #include <SPI.h>
    #include <nRF24L01.h>
    #include <RF24.h>
    RF24 radio(7, 8); // CE, CSN
    const byte address[6] = "00001";
    void setup() {
      Serial.begin(9600);
      pinMode(3, OUTPUT);
      pinMode(2, OUTPUT);
      radio.begin();
      radio.openReadingPipe(0, address);
      radio.setPALevel(RF24_PA_MIN);
      radio.startListening();
    }
    void loop() {
      if (radio.available()) {
        char text[32] = "";
        radio.read(&text, sizeof(text));
        Serial.println(text);
        digitalWrite(3, HIGH);
        if(strcmp(text, "Hello World") == 0) {
          digitalWrite(2, HIGH);        
        }
        delay(200);
        digitalWrite(3, LOW);
        digitalWrite(2, LOW);
      } else {
        digitalWrite(3, LOW);
        digitalWrite(2, LOW);
      }
    }
