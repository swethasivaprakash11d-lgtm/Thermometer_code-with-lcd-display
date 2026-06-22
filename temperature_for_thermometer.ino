#include <LiquidCrystal.h>

int lm35Pin = A0;
LiquidCrystal lcd(12,11,5,4,3,2);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.print("Temperature");
  delay(3000);
  
  lcd.clear();

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int sensorValue = analogRead(lm35Pin);
float voltage = sensorValue * (5.0/ 1023.0);
float tempC = voltage * 100;

lcd.setCursor(0,1);
lcd.print("Temp: ");
lcd.print(tempC);
lcd.print(" C ");

lcd.print(millis() / 1000);
}
