int r = 3;
int g = 5;
int b = 6;
int d = 600;

int array[8][3] = {
	{ 0, 0, 255 }, //blue
	{ 0, 100, 0 }, //green
	{ 0, 100, 200 }, // g + b = ?
	{ 255, 0, 0 }, //red
	{ 150, 0, 150 }, // r + b = ?
	{ 250, 100, 0 }, // r + g = ?
	{ 100, 80, 100 }, // white
	{ 0 , 0, 0 } //off
};

int index = 0;

void setup() {
	Serial.begin(9600);
	pinMode(r, OUTPUT);
	pinMode(g, OUTPUT);
	pinMode(b, OUTPUT);
}

void loop() {
	// int colors[3] = &array[index];
	// analogWrite(r, colors[0]);
	// analogWrite(g, colors[1]);
	// analogWrite(b, colors[2]);
	analogWrite(r, array[index][0]);
	analogWrite(g, array[index][1]);
	analogWrite(b, array[index][2]);
	delay(d);
	index++;
	if(index >= 8) {
		// delay(d*10);
		index = 0;
	}
}