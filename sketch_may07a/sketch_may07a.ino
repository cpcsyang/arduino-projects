int yellowLEDPin = 7;
int redLEDPin = 4;
int yellowOnTime = 100;
int yellowOffTime = 100;
int redOnTime = 300;
int redOffTime = 100;
int numYellowBlinks = 4;
int numRedBlinks = 2;

void setup() {
  // put your setup code here, to run once:
  pinMode(yellowLEDPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  for(int i=0; i<numYellowBlinks; i++) {
    digitalWrite(yellowLEDPin, HIGH);
    delay(yellowOnTime);
    digitalWrite(yellowLEDPin, LOW);
    delay(yellowOffTime);
  }
  
  for (int i=0; i<numRedBlinks; i++) {
    digitalWrite(redLEDPin, HIGH);
    delay(redOnTime);
    digitalWrite(redLEDPin, LOW);
    delay(redOffTime);
  }

}
