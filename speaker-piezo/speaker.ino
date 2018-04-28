int SPEAKER = 3;

void setup() {
	Serial.begin(9600);

	pinMode(SPEAKER, OUTPUT);	
}

void loop() {

	//super annoying speaker -- still audible @ 1.
	analogWrite(SPEAKER, 255);	
	// analogWrite(SPEAKER, 255*fraction);

	delay(500);

	analogWrite(SPEAKER, 0);

	delay(250);
}