#include <FastLED.h>

#define NUM_LEDS 100
#define DATA_PIN 10

#define LEFT0 41
#define RIGHT0 40

CRGB leds[NUM_LEDS];


void setup() {
  Serial.begin(9600);
  FastLED.addLeds<WS2811, DATA_PIN, BRG>(leds, NUM_LEDS);
}


void loop() {
  static int index = 10;
  static CRGB color = CRGB::Red;
  FastLED.clear();
  leds[index] = color;
  FastLED.show();

  if(digitalRead(LEFT0)) {
    index--;
  }

  if(digitalRead(RIGHT0)) {
    index++;
  }
  
  
  
  
  
  index++;
  if (index >= NUM_LEDS) {
    index = 0;
  }
  if(index < 0) {
    index = NUM_LEDS-1;
  }

  FastLED.delay(60);

}

