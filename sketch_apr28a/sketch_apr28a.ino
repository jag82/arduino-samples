#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#define PIN 6   //Data pin
#define NUM_LEDS 30
#define BRIGHTNESS 40

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRBW + NEO_KHZ800);

void setup() {
  Serial.begin(115200);
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  // End of trinket special code
  strip.setBrightness(BRIGHTNESS);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

uint32_t color = 0x200000;      // Inital color (starts red)

void loop() {
  for (int j = 0; j < 3; j++) {
    //Loop the diff colors, RGBW
    for (int i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, color >> j * 8);
      strip.setPixelColor(i + 1, color >> j * 8);
      strip.show();                     // Refresh strip
      //Serial.println((color >> j * 8), HEX);  //Debug
      delay(50);
      clearLED(i);
    }
  }
}

void clearLED(int c) {
  //Turn off LED that are on
  for (int i = 0; i < 2; i++) {
    strip.setPixelColor(c + i, 0); //Off LED
  }
}
