int LEDblue=6; //The word “LEDblue” stands for the value 6.
int button=8; //The word “button” stands for the value 7.
int buttonstatus=0;
int lastState=LOW;
int counter = 0;
float acc = 1;
//The word “buttonstatus” stands for the value 0. Later
//on there will be safed wheter the button is pushed or not.
void setup() {
	Serial.begin(9600);
//The setup starts here
pinMode(LEDblue, OUTPUT);
pinMode(button, INPUT);
//The pin connected to the LED (pin 6) is an output
//The pin connected to the button (pin 7) is an input.
}

void loop()
{
//with this bracket the loop part starts
buttonstatus=digitalRead(button);
//The value on pin 7 is read out (command:
//digitalRead). The result will be safed under “buttonstatus”. (HIGH means 5V
//and LOW means 0V)
if (buttonstatus == HIGH)
{	
		counter = counter + (int)(acc * 1);
		acc *= 1.11;
		 Serial.println("counter up!");
		 Serial.println(counter);
//		delay(150);
		
//If the button gets pushed (high voltage value)...
//open program part of the IF-command
digitalWrite(LEDblue, HIGH);
 delay(150);
//5000 miliseconds (5 seconds) long
digitalWrite(LEDblue, LOW);
}
//...the LED should light up
//after 5seconds the LED should turn off
//close the program part of the IF-command
else
{
//open the program part of the else-command
digitalWrite(LEDblue, LOW);
acc = 1;
//the LED shouldn't light up
} //close the program part of the else-command
} //with this bracket the whole loop parts gets closed