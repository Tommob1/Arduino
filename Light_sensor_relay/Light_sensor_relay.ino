#include <math.h>
#include "TM1650.h"
#include <inttypes.h>

int lightPin = A0;
int Relay = 5;
int lightValue = 0;

static uint8_t TubeTab[] = 
{
  0x3F,0x06,0x5B,0x4F,
  0x66,0x6D,0x7D,0x07,
  0x7F,0x6F,0x77,0x7C,
  0x39,0x5E,0x79,0x71,
};

TM1650 DigitalLED(A5, A4);

void setup()
{
  pinMode(Relay, OUTPUT);
  pinMode(lightPin, INPUT);

  Serial.begin(9600);

  DigitalLED.init();
}

void loop()
{
  lightValue = analogRead(lightPin);

  Serial.print("Light Value: ");
  Serial.println(lightValue);

  if (lightValue < 800)
  {
    digitalWrite(Relay, LOW);
    DigitalLED.clearDisplay();
  }
  else
  {
    digitalWrite(Relay, HIGH);
    DigitalLED.display(0, TubeTab[8]);
    DigitalLED.display(1, TubeTab[0]);
    DigitalLED.display(2, TubeTab[0]);
    DigitalLED.display(3, TubeTab[8]);
  }
  delay(1000);
}
