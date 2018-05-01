#include <SoftwareSerial.h>

SoftwareSerial BTSerial(5, 3);

int LED = 11;

void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);
//  pinMode(12, INPUT);
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
     BTSerial.write (c);           // Write the character to Bluetooth  
   }  
//   BTSerial.write('z');

  // Android sends a signal to us (Arduino)
  if (BTSerial.available()) {
    char in = BTSerial.read();
    //Serial.println(in);
    if(in == '0') {
      function0();
    }
    if(in == '1') {
      function1();
    }
  }

//  delay(50);
}


void function0()
{
  //Enter what you want the command to initiate (e.g LED, Servo etc)
  digitalWrite(LED, LOW);
}
void function1()
{
  //Enter what you want the command to initiate (e.g LED, Servo etc)
  digitalWrite(LED, HIGH);
}
 

