//testing a single potentiometer

void setup() {
  Serial.begin(9600);
  Serial.println("setup");
//  pinMode(A15, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(analogRead(A15));
  delay(80);
}
