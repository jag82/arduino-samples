int TRIGGER = 2;
int ECHO = 3;

long time = 0;
long dist = 0;

void setup() {
	Serial.begin(9600);

	pinMode(TRIGGER, OUTPUT);
	pinMode(ECHO, INPUT);
		
}

void loop() {

	//create sound wave
	digitalWrite(TRIGGER, LOW);
	delay(5);
	digitalWrite(TRIGGER, HIGH);
	delay(10);
	digitalWrite(TRIGGER, LOW);
	
	time = pulseIn(ECHO, HIGH);
	dist = (time/2) / 29.1;

	if(dist >= 500 || dist <= 0) {
		Serial.println("inaccurate measurement");
		
	} else {
		Serial.print(dist);
		Serial.println("cm");
		delay(1000);
		
	}
}