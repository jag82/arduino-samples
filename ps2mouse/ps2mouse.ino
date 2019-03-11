#include "src/PS2Mouse.h"
#define DATA_PIN 2
#define CLOCK_PIN 3

PS2Mouse mouse(CLOCK_PIN, DATA_PIN);

void setup() {
  Serial.begin(9600);
  Serial.println("Mouse Test:");
  mouse.initialize();
}

void loop() {
    MouseData data = mouse.readData();
    Serial.print(data.status, BIN);
    Serial.print("\tx=");
    Serial.print(data.position.x);
    Serial.print("\ty=");
    Serial.print(data.position.y);
    Serial.print("\twheel=");
    Serial.print(data.wheel);
    Serial.println();
    delay(20);
}
