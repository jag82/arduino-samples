
// attach a light to this pin
int PIN = 3;



void setup() {
  Serial.begin(9600);
  
  // put your setup code here, to run once:
  pinMode(PIN, OUTPUT);
 


  
//  pinMode (A0, INPUT);
//  digitalWrite (A0, HIGH);


  pinMode(A0, INPUT);
}


int counter = 0;

void loop() {
  // put your main code here, to run repeatedly:
 
  counter = counter + 1;
//  Serial.println(counter);

  if (counter > 255) {
    counter = 0;
  }

  analogWrite(PIN, counter);
  delay(50);
  
//  int photo = analogRead(A0);
//  Serial.println(photo);
  

//  analogWrite(PIN, 255 - map(photo, 60, 800, 0, 255));
//    if(counter > 2000) {
//      digitalWrite (PIN, LOW);
////      counter = 0;
//    } 
//    else if(counter > 1000) {
//      digitalWrite(PIN, HIGH);    
//    }

}
