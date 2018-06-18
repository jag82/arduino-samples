int POT_PIN = 5;
int FLICK_PIN = 7;

void setup() {
	Serial.begin(9600);
	pinMode(POT_PIN, INPUT);
	pinMode(FLICK_PIN, INPUT);
	

}

void loop() {
	// int pot = analogRead(POT_PIN);
	bool flick = digitalRead(FLICK_PIN);
	Serial.println(flick);

}
