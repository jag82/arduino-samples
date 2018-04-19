int MOTION = 2;
int LED = 3;

void setup() {
	Serial.begin(9600);

	pinMode(MOTION, OUTPUT);
	pinMode(LED, OUTPUT);	
}

void loop() {
	int motion = digitalRead(MOTION);
	Serial.println("motion:");
	Serial.println(motion);
	
	
	if(motion == HIGH) {
		digitalWrite(LED, HIGH);

	} else {
		digitalWrite(LED, LOW);
	}

	
}