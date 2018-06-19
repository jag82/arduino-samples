#include <FastLED.h>

#define NUM_LEDS 30
#define DATA_PIN 5
//5-8, 9,10

#define INPUT1 53
#define INPUT2 52
#define INPUT3 51

CRGB leds[NUM_LEDS];


void setup() {
  Serial.begin(9600);
  FastLED.addLeds<WS2811, DATA_PIN, BRG>(leds, NUM_LEDS);
  pinMode(INPUT1, INPUT);
}


void loop() {
  bool val1 = digitalRead(INPUT1);
  
  static int index = 0;
  FastLED.clear();
  leds[index] = CRGB::White;
  FastLED.show();

  if(val1) {
    index++;
    if (index >= NUM_LEDS) {
      index = 0;
    }  
  }

  FastLED.delay(30);

}

