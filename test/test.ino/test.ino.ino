#include <MIDI.h>
#include <StandardCplusplus.h>
#include <vector>

#define NUM_LEDS 200
#define DATA_PIN 3
#define MAX_BRIGHTNESS 25

#define POT A0
#define LEFT 7
#define RIGHT 6


MIDI_CREATE_DEFAULT_INSTANCE();

std::vector<int> list;
int index = 0;

int TEST = 13;
//pinMode(LED_BUILTIN, OUTPUT); 


void setup() {
//  Serial.begin(9600);
  MIDI.begin(MIDI_CHANNEL_OMNI);  // Listen to all incoming messages

  pinMode(TEST, OUTPUT);
  digitalWrite(TEST, LOW);

//  FastLED.addLeds<WS2812B, DATA_PIN, BRG>(leds, NUM_LEDS);
//  FastLED.setBrightness(MAX_BRIGHTNESS);
  //https://forum.arduino.cc/index.php?topic=70450.0
//  set_max_power_in_volts_and_milliamps(5, 90); //one light, max brightness = 60mA + 30mA IC?
//    set_max_power_in_volts_and_milliamps(5, 400); //max 400mA when connected via USB

//  pinMode(POT, INPUT);
//  pinMode(8, OUTPUT);
//  digitalWrite(8, HIGH);
  
//  pinMode(LEFT, INPUT);
//  pinMode(RIGHT, INPUT);
}

void loop() {
//  Serial.println("omg");
//  MIDI.sendNoteOn(42, 127, 1);
  if (MIDI.read()) {
    digitalWrite(TEST,HIGH);
  } else {
    digitalWrite(TEST,LOW);    
  }


}

