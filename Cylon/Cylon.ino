#include <FastLED.h>

// How many leds in your strip?
#define NUM_LEDS 100 

// For led chips like Neopixels, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806, define both DATA_PIN and CLOCK_PIN
#define DATA_PIN 6
//#define CLOCK_PIN 13

int pos = 0;

const int tailLength = 6;
int tail[tailLength];
int tailValues[tailLength];// = { 200, 150, 100, 80, 40, 0 };


// Define the array of leds
CRGB leds[NUM_LEDS];


void setup() { 
  Serial.begin(9600);
//	Serial.begin(57600);
//	Serial.println("resetting");
	LEDS.addLeds<WS2811,DATA_PIN,BRG>(leds,NUM_LEDS);
	LEDS.setBrightness(84);
 for(int i = 0; i < tailLength; i++) {
    tail[i] = pos;
    tailValues[i] = 20 * (tailLength - i - 1);
 }
}

void fadeall() { for(int i = 0; i < NUM_LEDS; i++) { leds[i].nscale8(250); } }


int waitLen = 30;
int waitFreq = 12;
int counter = 0;
int counterDir = 1;

void loop() { 

    for(int i = tailLength-1; i >= 0; i--) {
      //light tail from dullest to brightest
      leds[tail[i]] = CHSV(250, 255, tailValues[i]);      
      //pass position down chain
      if(i > 0) {
        tail[i] = tail[i-1];      
      } else {
        tail[i] = pos;
      }
    }
    leds[pos] = CHSV(250, 255, 255);

    if(counterDir == 1) {
      if(counter >= waitFreq) {
         counterDir = -1;
      } else {
        counter++;
        pos++;          
      }
    } else {
      counter --;
      if(counter <= 0) {
        counterDir = 1;
      }
    }

    if(pos >= NUM_LEDS) {
      pos = 0;
    }
    FastLED.show();
    delay(80);


}
