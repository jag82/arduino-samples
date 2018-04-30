#include <Adafruit_NeoPixel.h>

#define PIN            3
#define NUMPIXELS      20


Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin();
    pixels.setPixelColor(12, pixels.Color(100,100,100));    
  pixels.show();
}

void loop() {

}
