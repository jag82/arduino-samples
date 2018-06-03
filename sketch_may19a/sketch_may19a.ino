int LEFT_PIN = 13;
int RIGHT_PIN = 12;

void setup() {
  Serial.begin(9600);
  pinMode(LEFT_PIN, INPUT);
  pinMode(RIGHT_PIN, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int left = digitalRead(LEFT_PIN);
  int right = digitalRead(RIGHT_PIN);
  Serial.println(right);
//  digitalWrite(LEFT_PIN, HIGH);
//  delay(400);
//  digitalWrite(LEFT_PIN, LOW);
//  delay(400);
}
