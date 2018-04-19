 #include <Servo.h> //Die Servobibliothek wird aufgerufen. Sie wird benötigt, damit die Ansteuerung des Servos vereinfacht wird.
 

Servo servoblau; //Erstellt für das Programm ein Servo mit dem Namen „servoblau“

int SERVO = 8;

void setup() {
	servoblau.attach(SERVO); 
}

 

void loop() {
	servoblau.write(0); //Position 1 ansteuern mit dem Winkel 0°

	delay(3000); //Das Programm stoppt für 3 Sekunden

	servoblau.write(90); //Position 2 ansteuern mit dem Winkel 90°

	delay(3000); //Das Programm stoppt für 3 Sekunden

	servoblau.write(90); //Position 3 ansteuern mit dem Winkel 180°

	delay(3000);//Das Programm stoppt für 3 Sekunden

	servoblau.write(90); //Position 4 ansteuern mit dem Winkel 20°

	delay(3000);//Das Programm stoppt für 3 Sekunden
}