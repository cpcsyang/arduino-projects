//int ledPin = 13;      // LED connected to digital pin 13
//int inPin = 2;        // pushbutton connected to digital pin 2
int buttonState = 0;          // variable to store the read value
//int redLEDPin = 10;      // Red LED is on pin 10
//int yellowLEDPin = 11;   // Yellow LED is on pin 11
//int greenLEDPin = 12;    // Green LED is on pin 12


void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  
  // put your setup code here, to run once:
  // initialize digital pin LED_BUILTIN (=13) as an output.
  pinMode(LED_BUILTIN, OUTPUT);   //White LED, pin 13
  //pinMode(12, OUTPUT);            //Green LED
  //pinMode(11, OUTPUT);            //Yellow LED
  //pinMode(10, OUTPUT);            //Red LED

  //pinMode(ledPin, OUTPUT);      // sets the digital pin 13 as output
  //pinMode(inPin, INPUT);      // sets the digital pin 2 as input (location of the switch)
  pinMode(2, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(2);   // read the input pin
  //Serial.println(buttonState);
  digitalWrite(LED_BUILTIN, buttonState);    // sets the LED to the button's value
  
  //if(buttonState == HIGH){
    
  //}
  delay(100);
}
