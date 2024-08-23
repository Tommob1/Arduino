#include <DHT.h>
#include <LiquidCrystal.h>

#define DHTTYPE DHT11
#define DHTPIN 6
DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2);
  dht.begin();
  lcd.print("Initializing...");
}

void loop()
{
  float temperature = dht.readTemperature();
  if (isnan(temperature)) {
    temperature = 0.0;
  }

  int sensorValue = analogRead(A0);
  float voltage = sensorValue * (5.0 / 1023.0);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("TEMP: ");
  lcd.print(temperature, 1);
  lcd.print((char)223);
  lcd.print("C");

  lcd.setCursor(0, 1);
  lcd.print("POWER: ");
  lcd.print(voltage, 2);
  lcd.print("V");

  Serial.print("Temp: ");
  Serial.print(temperature, 1);
  Serial.print("C, Rail V: ");
  Serial.print(voltage, 2);
  Serial.println("V");

  delay(1000);
}