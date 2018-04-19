int DIAL = A0;
int LED = 3;

void setup() {
	Serial.begin(9600);

	pinMode(DIAL, INPUT);
	pinMode(LED, OUTPUT);	
}

void loop() {

	int dial = analogRead(DIAL);

	float fraction = dial/1023.00;
	// Serial.println(dial);
	
	// analogWrite(LED, 255);	
	analogWrite(LED, 255*fraction);

	delay(50);
}