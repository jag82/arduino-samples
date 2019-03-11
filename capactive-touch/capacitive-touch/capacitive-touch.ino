#include <CapacitiveSensor.h>

#define COMMON_PIN      2    // The common 'send' pin for all keys
#define NUM_OF_SAMPLES  10   // Higher number whens more delay but more consistent readings
#define CAP_THRESHOLD   150  // Capactive reading that triggers a note (adjust to fit your needs)

CapacitiveSensor key = CapacitiveSensor(COMMON_PIN, 3);

void setup() {
	Serial.begin(9600);

  key.set_CS_AutocaL_Millis(0xFFFFFFFF);
}

void loop() {
    int value = key.capacitiveSensor(NUM_OF_SAMPLES);
    Serial.println(value);
    delay(200);
    if(value > CAP_THRESHOLD) {
    }
}
