#include <FastLED.h>

#define NUM_LEDS 100
#define DATA_PIN 6

CRGB leds[NUM_LEDS];

int LEFT_PIN = 4;
int RIGHT_PIN = 2;

int index = 86;
float speed = 1.0df;
int MAX_BRIGHT = 50;
int brightness = 255;
int fadeRate = 10;

void setup() {
//  Serial.begin(9600);
  FastLED.addLeds<WS2811, DATA_PIN, BRG>(leds, NUM_LEDS);
  pinMode(LEFT_PIN, INPUT);
  pinMode(RIGHT_PIN, OUTPUT);
}
 

void loop() { 
  int left = digitalRead(LEFT_PIN);
  int right = digitalRead(RIGHT_PIN);

  if(left && !right) {
    if(index > 0) {
      index--;      
    }
  }

  if(right && !left) {
    if(index < NUM_LEDS-1) {
      index++;
    }
  }

  brightness -= fadeRate;
  if(brightness <= 0) {
    fadeRate *= -1;
    brightness = 0;
  }
  if(brightness >= MAX_BRIGHT){
    fadeRate *= -1;
    brightness = MAX_BRIGHT;
  }
  

  FastLED.clear();

  for(int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Blue;
    leds[i].fadeLightBy(254);
  }
  
  leds[index] = CRGB::HotPink;
  if(brightness < 255) {
    leds[index].fadeLightBy(255-brightness);
  }
  FastLED.show(); 

  FastLED.delay(30 / speed); 

}

//demo of fast LED
void loopFastLED() {
  FastLED.clear();

  leds[index] = CRGB::White; 
  FastLED.show(); 

  index++;
  if(index >= NUM_LEDS) {
    index = 0;
  }

  
  delay(30 / speed); 
  
}

 
