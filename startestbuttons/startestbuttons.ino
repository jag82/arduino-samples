#define TEST_PIN 13
#define DIAL_PIN A0
#define FLICK_PIN 7
#define BUTTON_PIN 8

void setup() {
  delay(2000);
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(TEST_PIN, OUTPUT);
  pinMode(DIAL_PIN, INPUT);
  pinMode(FLICK_PIN, INPUT);
  pinMode(BUTTON_PIN, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int dial = analogRead(DIAL_PIN);
  bool flick = digitalRead(FLICK_PIN);
  bool button = digitalRead(BUTTON_PIN);

  static int timer = 1000;
  if(timer == 0) {
    Serial.println(dial);
    Serial.println(flick);
    Serial.println(button);
    Serial.println("====");
    timer = 1000; 
  } else {
    timer--;
  }

  digitalWrite(13, LOW);
  
  if(button) {
    digitalWrite(13, HIGH);
  }
  if(flick) {
    digitalWrite(13, HIGH);
  }
  if(dial > 950) {
    digitalWrite(13, HIGH);
  }
  if(dial < 50) {
    digitalWrite(13, HIGH);
  }
}
