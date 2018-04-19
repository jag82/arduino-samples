int TEMP = A0;
int LED = 3;

void setup() {
	Serial.begin(9600);

	pinMode(TEMP, INPUT);
	pinMode(LED, OUTPUT);	
}

void loop() {

	int temp = analogRead(TEMP);

	// float fraction = temp/1023.00;
	//TODO: temperature readings are always close to 1000 but they should be between 0 and 410 -- is it already broken? does it need a resistor?
	Serial.println(temp);
	
	analogWrite(LED, 255);	
	// analogWrite(LED, 255*fraction);

	delay(50);
}