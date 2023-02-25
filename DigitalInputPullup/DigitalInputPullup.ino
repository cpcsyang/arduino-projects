/*
  Input Pull-up Serial

  This example demonstrates the use of pinMode(INPUT_PULLUP). It reads a digital
  input on pin 2 and prints the results to the Serial Monitor.

  The circuit:
  - momentary switch attached from pin 2 to ground
  - built-in LED on pin 13

  Unlike pinMode(INPUT), there is no pull-down resistor necessary. An internal
  20K-ohm resistor is pulled to 5V. This configuration causes the input to read
  HIGH when the switch is open, and LOW when it is closed.

  created 14 Mar 2012
  by Scott Fitzgerald

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/InputPullupSerial
*/

void setup() {
  //start serial connection
  Serial.begin(9600);
  //configure pin 2 as an input and enable the internal pull-up resistor
  // pinMode(2, INPUT_PULLUP);  // use this to set "default" input to HIGH (pullup)
  pinMode(2, INPUT);
  pinMode(13, OUTPUT);
}
int totalSensorVal = 0;

void loop() {
  delay(1);
  // if pinMode is INPUT_PULLUP, then button/switch should be wired to GND
  // then value of digitalRead should return LOW when button/switch is pressed
  //read the pushbutton value into a variable
  int sensorVal = digitalRead(2); 
  totalSensorVal += sensorVal;
  //print out the value of the pushbutton
  // Serial.println(sensorVal);
  Serial.println(totalSensorVal);

  // Keep in mind the pull-up means the pushbutton's logic is inverted. It goes
  // HIGH when it's open, and LOW when it's pressed. Turn on pin 13 when the
  // button's pressed, and off when it's not:
  if (sensorVal == HIGH) {
    digitalWrite(13, HIGH);
    delay(10);
  } else {
    digitalWrite(13, LOW);
  }
}
