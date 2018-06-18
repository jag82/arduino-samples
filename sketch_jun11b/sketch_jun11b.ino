#include <FastLED.h>

#define NUM_STRIPS 6
#define NUM_LEDS_PER_STRIP 100

CRGB leds[NUM_STRIPS][NUM_LEDS_PER_STRIP];

void setup() {

    FastLED.addLeds<WS2811, 3, BRG>(leds[0], NUM_LEDS_PER_STRIP);
    FastLED.addLeds<WS2811, 4, BRG>(leds[1], NUM_LEDS_PER_STRIP);
    FastLED.addLeds<WS2811, 5, BRG>(leds[2], NUM_LEDS_PER_STRIP);
    FastLED.addLeds<WS2811, 6, BRG>(leds[3], NUM_LEDS_PER_STRIP);
    FastLED.addLeds<WS2811, 7, BRG>(leds[4], NUM_LEDS_PER_STRIP);
    FastLED.addLeds<WS2811, 8, BRG>(leds[5], NUM_LEDS_PER_STRIP);

    FastLED.clear();

}

void loop() {
  // put your main code here, to run repeatedly:
static int x = 0;
  FastLED.clear();

  for(int i = 0; i < NUM_STRIPS; i++) {
    leds[i][x] = CRGB::Red;
    
  }
  FastLED.show(); 
  x++;
  if(x >= NUM_LEDS_PER_STRIP) {
    x = 0;
  }
}
