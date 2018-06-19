#include <FastLED.h>

#define NUM_STRIPS 6
#define NUM_LEDS_PER_STRIP 100

CRGB leds[NUM_STRIPS][NUM_LEDS_PER_STRIP];


void setup() {
  Serial.begin(9600);
  Serial.println("setup");
  FastLED.addLeds<WS2811, 5, BRG>(leds[0], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<WS2811, 6, BRG>(leds[1], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<WS2811, 7, BRG>(leds[1], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<WS2811, 8, BRG>(leds[1], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<WS2811, 9, BRG>(leds[1], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<WS2811, 10, BRG>(leds[1], NUM_LEDS_PER_STRIP);
}


void loop() {
  static int index = 10;
  static CRGB color = CRGB::White;
  FastLED.clear();
  for(int i = 0; i < NUM_STRIPS; i++) {
    leds[i][index] = color;
    
  }
  FastLED.show();

  // if(digitalRead(LEFT0)) {
  //   index--;
  // }

  // if(digitalRead(RIGHT0)) {
  //   index++;
  // }
  
  
  
  
  
  index++;
  if (index >= NUM_LEDS_PER_STRIP) {
    index = 0;
  }
  if(index < 0) {
    index = NUM_LEDS_PER_STRIP-1;
  }

  FastLED.delay(60);

}


