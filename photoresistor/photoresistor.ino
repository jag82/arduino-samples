int PHOTO = A5;
int LED = 3;

void setup() {
	Serial.begin(9600);

	pinMode(PHOTO, INPUT);
	pinMode(LED, OUTPUT);	
}

void loop() {

	int photo = analogRead(PHOTO);

	float fraction = photo/1023.00;
 
	analogWrite(LED, 255*fraction);
	// delay(50);
}