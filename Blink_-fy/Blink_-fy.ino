/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO 
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino model, check
  the Technical Specs of your board  at https://www.arduino.cc/en/Main/Products
  
  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
  
  modified 2 Sep 2016
  by Arturo Guadalupi
  
  modified 8 Sep 2016
  by Colby Newman
*/


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN (=13) as an output.
  pinMode(LED_BUILTIN, OUTPUT);   //White LED, pin 13
  pinMode(12, OUTPUT);            //Green LED
  pinMode(11, OUTPUT);            //Yellow LED
  pinMode(10, OUTPUT);   //Red LED
}

// the loop function runs over and over again forever
void loop() {
  /*
  //Green LED
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(1000);                       // wait for a second
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
    delay(1000);                       // wait for a second
  
    //Yellow LED
    digitalWrite(12, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(1000);                       // wait for a second
    digitalWrite(12, LOW);    // turn the LED off by making the voltage LOW
    delay(1000);                       // wait for a second
  
    //Red LED
    digitalWrite(11, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(1000);                       // wait for a second
    digitalWrite(11, LOW);    // turn the LED off by making the voltage LOW
    delay(1000);                       // wait for a second
  */

  
  if(random(2)==1){
    digitalWrite(12, HIGH);   // turn the LED on (HIGH is the voltage level)
  }
  if(random(2)==1){
    digitalWrite(11, HIGH);   // turn the LED on (HIGH is the voltage level)
  }
  if(random(2)==1){
    digitalWrite(10, HIGH);   // turn the LED on (HIGH is the voltage level)
  }
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED on (HIGH is the voltage level)
  
  delay(1000);
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)

  digitalWrite(12, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(11, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(10, LOW);    // turn the LED off by making the voltage LOW

  delay(50);


}
