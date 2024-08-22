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
  float humidity = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    lcd.clear();
    lcd.print("Sensor error");
    return;
  }

  Serial.print("T = ");
  Serial.print(temperature, 1);
  Serial.print(" deg. C, H = ");
  Serial.print(humidity, 1);
  Serial.println("%");

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature, 1);
  lcd.print((char)223);
  lcd.print("C");

  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  lcd.print(humidity, 1);
  lcd.print("%");

  delay(1000);
}