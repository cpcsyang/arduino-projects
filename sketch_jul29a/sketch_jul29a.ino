//www.elegoo.com
//2016.12.9
// frank yang
// 2019.7.29

#include <LiquidCrystal.h>
int tempPin = 0;
//                BS  E  D4 D5  D6 D7
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

// backLight on pin 2
// with a pull-down resistor of 10k
bool isBackLight;
bool backLightOn;

void setup()
{
  lcd.begin(16, 2);
  pinMode(13, OUTPUT);
  //digitalWrite(13, HIGH);
  // pi 2 is using external pull-down resistor of 10k
  pinMode(2, INPUT);
  Serial.begin(115200);
  backLightOn = true;
  // pin 3 is configured using internal pullup resistor
  pinMode(3, INPUT_PULLUP);
}
void loop()
{
  //check if back-light on/off toggle switch pressed?
  Serial.print("  D2:");
  Serial.print(digitalRead(2));
  Serial.print("  D3:");
  Serial.print(digitalRead(3));
  Serial.println();
  if(digitalRead(2) == 1) {   //OFF switch is pressed
    backLightOn = false;
  }
  if(digitalRead(3) == 0) {   //ON switch is pressed
    backLightOn = true;
  }
  digitalWrite(13, backLightOn);
  
  int tempReading = analogRead(tempPin);
  // This is OK
  double tempK = log(10000.0 * ((1024.0 / tempReading - 1)));
  tempK = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * tempK * tempK )) * tempK );       //  Temp Kelvin
  float tempC = tempK - 273.15;            // Convert Kelvin to Celcius
  float tempF = (tempC * 9.0)/ 5.0 + 32.0; // Convert Celcius to Fahrenheit
  /*  replaced
    float tempVolts = tempReading * 5.0 / 1024.0;
    float tempC = (tempVolts - 0.5) * 10.0;
    float tempF = tempC * 9.0 / 5.0 + 32.0;
  */
  
  // Display Temperature in C
  lcd.setCursor(0, 1);
  lcd.print("Temp         C  ");
  // Display Temperature in C
  lcd.setCursor(6, 1);
  lcd.print(tempC);
  
  //Display Temperature in F
  lcd.setCursor(0, 0);
  lcd.print("Temp         F  ");
  // Display Temperature in F
  lcd.setCursor(6, 0);
  lcd.print(tempF);
  
  delay(500);
}
