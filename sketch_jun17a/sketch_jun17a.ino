#include <FastLED.h>

#define NUM_LEDS 200
#define DATA_PIN 3

CRGB leds[NUM_LEDS];


void setup() {
  Serial.begin(9600);
  FastLED.addLeds<WS2812B, DATA_PIN, BRG>(leds, NUM_LEDS);
}


void loop() {
  static int index = 0;
  FastLED.clear();
  leds[index] = CRGB::White;
  FastLED.show();

  index++;
  if (index >= NUM_LEDS) {
    index = 0;
  }

  FastLED.delay(60);

}

