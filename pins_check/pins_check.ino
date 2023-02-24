int analog0;
int analog1;
int analog2;
int analog3;
int analog4;
int analog5;

int digital1;
int digital2;
int digital3;
int digital4;
int digital5;
int digital6;
int digital7;
int digital8;
int digital9;
int digital10;
int digital11;
int digital12;
int digital13;

int pinState;
int pin13state;

void analogTest(int delayMilliSec) {
  analog0 = analogRead(A0);
  analog1 = analogRead(A1);
  analog2 = analogRead(A2);
  analog3 = analogRead(A3);
  analog4 = analogRead(A4);
  analog5 = analogRead(A5);

  Serial.println(analog0);
  Serial.println(analog1);
  Serial.println(analog2);
  Serial.println(analog3);
  Serial.println(analog4);
  Serial.println(analog5);

  delay(delayMilliSec);  
}

void digitalTest(int delayMilliSec) {
  digital1 = digitalRead(1);
  digital2 = digitalRead(2);
  digital3 = digitalRead(3);
  digital4 = digitalRead(4);
  digital5 = digitalRead(5);
  digital6 = digitalRead(6);
  digital7 = digitalRead(7);
  digital8 = digitalRead(8);
  digital9 = digitalRead(9);
  digital10 = digitalRead(10);
  digital11 = digitalRead(11);
  digital12 = digitalRead(12);
  digital13 = digitalRead(13);
  
  Serial.println(digital1);
  Serial.println(digital2);
  Serial.println(digital3);
  Serial.println(digital4);
  Serial.println(digital5);
  Serial.println(digital6);
  Serial.println(digital7);
  Serial.println(digital8);
  Serial.println(digital9);
  Serial.println(digital10);
  Serial.println(digital11);
  Serial.println(digital12);
  Serial.println(digital13);

  delay(delayMilliSec);
}

void digitalLoopTest() {
  Serial.println("------- Each pin should match Pin#13. 1=HIGH 0=LOW -------");
  pinMode(13, OUTPUT);
  for (int pin = 2; pin <= 12; pin++) {
    pin13state = random(0, 2);
    if(pin13state == 1) {
      digitalWrite(13, HIGH);
    } else {
      digitalWrite(13, LOW);  
    }
    Serial.print ("pin13 = ");
    Serial.print(pin13state);
    Serial.print(", ");

    pinMode(pin, INPUT);
    Serial.print("pin");
    Serial.print(pin);
    Serial.print(" = ");
    
    
    pinState = digitalRead(pin);
    Serial.print(pinState);
    Serial.print(", \tpass? ");
    Serial.println(pin13state == pinState);
    //delay(100);
  }
  
  delay(500);  
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin (115200);
}

void loop() {
  
  digitalLoopTest();
  
  //analogTest(5000);
  //digitalTest(5000);
  //delay(1000000);
}
