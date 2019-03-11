#include <FastLED.h>

#define NUM_STRIPS 6
#define NUM_LEDS_PER_STRIP 100

CRGB leds[NUM_STRIPS][NUM_LEDS_PER_STRIP];

  const int RIGHT_PIN = 53;
  const int LEFT_PIN = 52;
  const int DO_PIN = 51;

  const int RIGHT2_PIN = 49;
  const int LEFT2_PIN = 48;
  const int UNDO_PIN = 47;

  const int FLICK1_PIN = 45;
  const int FLICK2_PIN = 44;
  const int FLICK3_PIN = 43;
  const int FLICK4_PIN = 42;

  const int DIAL1_PIN = A12;
  const int DIAL2_PIN = A13;
  const int DIAL3_PIN = A14;

  const int DIAL0_PIN = A15;
  const int LEFT0_PIN = 41;
  const int RIGHT0_PIN = 40;



void setup() {
  Serial.begin(9600);
  Serial.println("setup");

    FastLED.addLeds<WS2811, 5, BRG>(leds[0], NUM_LEDS_PER_STRIP);
    FastLED.addLeds<WS2811, 6, BRG>(leds[1], NUM_LEDS_PER_STRIP);
    FastLED.addLeds<WS2811, 7, BRG>(leds[2], NUM_LEDS_PER_STRIP);
    FastLED.addLeds<WS2811, 8, BRG>(leds[3], NUM_LEDS_PER_STRIP);
    FastLED.addLeds<WS2811, 9, BRG>(leds[4], NUM_LEDS_PER_STRIP);
    FastLED.addLeds<WS2811, 10, BRG>(leds[5], NUM_LEDS_PER_STRIP);

//try powering potentiometers with 5V digital output pin (works!)
  pinMode(24, OUTPUT);
  digitalWrite(24, HIGH);
  //separately power left/right on same side of breadboard as potentiometers (otherwise we affecct their value!)
  pinMode(22, OUTPUT);
  digitalWrite(22, HIGH);
  pinMode(23, OUTPUT);
  digitalWrite(23, HIGH);
  
    pinMode(LEFT_PIN, INPUT);
    pinMode(RIGHT_PIN, INPUT);
    pinMode(DO_PIN, INPUT);

    pinMode(LEFT2_PIN, INPUT);
    pinMode(RIGHT2_PIN, INPUT);
    pinMode(UNDO_PIN, INPUT);

    pinMode(FLICK1_PIN, INPUT);
    pinMode(FLICK2_PIN, INPUT);
    pinMode(FLICK3_PIN, INPUT);
    pinMode(FLICK4_PIN, INPUT);

    pinMode(DIAL1_PIN, INPUT);
    pinMode(DIAL2_PIN, INPUT);
    pinMode(DIAL3_PIN, INPUT);

    pinMode(LEFT0_PIN, INPUT);
    pinMode(RIGHT0_PIN, INPUT);
    pinMode(DIAL0_PIN, INPUT);
}

void loop() {
  static int index = 10;
  index++;
  // put your main code here, to run repeatedly:
//  FastLED.clear();

  leds[0][index] = CRGB::White;

  FastLED.delay(60);

  if(index % 15 == 0) {
//    Serial.println(digitalRead(LEFT_PIN));    //left: above box (paired)
    Serial.println(digitalRead(49));   //left: above box (paired) [broken]
//    Serial.println(digitalRead(DO_PIN));      // left: between box and entrance

//    Serial.println(digitalRead(LEFT2_PIN)); //!!!! [broken]
//    Serial.println(digitalRead(RIGHT2_PIN));  //right: between box and box2 (needs its pair)
//    Serial.println(digitalRead(UNDO_PIN));    //right: far (jo's button (near tunnel))

    Serial.println("---");

//    Serial.println(digitalRead(FLICK1_PIN));  //[absent]
//    Serial.println(digitalRead(FLICK2_PIN));   //[absent]
//    Serial.println(digitalRead(FLICK3_PIN));   //left: above entrance
//    Serial.println(digitalRead(FLICK4_PIN));   //right: between box and box2

//    Serial.println(analogRead(DIAL1_PIN));
//    Serial.println(analogRead(DIAL2_PIN));
//    Serial.println(analogRead(DIAL3_PIN));    //right: far

    Serial.println("---");
//    Serial.println(digitalRead(LEFT0_PIN)); //[absent]
//    Serial.println(digitalRead(RIGHT0_PIN));  //[absent]
//    Serial.println(analogRead(DIAL0_PIN)); //left: above box (NOT TRIPLED!!! rejig code)
  
    Serial.println("====");
  }
}
