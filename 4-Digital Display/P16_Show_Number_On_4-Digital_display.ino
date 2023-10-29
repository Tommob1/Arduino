#include "TM1650.h"
#include <inttypes.h>
static uint8_t TubeTab[] = {
               0x3F,0x06,0x5B,0x4F,
               0x66,0x6D,0x7D,0x07,
               0x7F,0x6F,0x77,0x7C,
               0x39,0x5E,0x79,0x71,   
               };//0~9,A,B,C,D,E,F  
static uint8_t TubeTabwithPoit[] = {
               0xBF,0x86,0xDB,0xCF,
               0xE6,0xED,0xFD,0x87,
               0xFF,0xEF   
               };//0~9  
TM1650 DigitalLED(A5,A4);
int8_t number[] = {0,0,0,0};
void setup()
{
  //Serial.begin(9600);
}

void loop()
{
    DigitalLED.clearDisplay();
     delay(1000);
     DigitalLED.display(0,TubeTab[1]);
     DigitalLED.display(1,TubeTab[2]);
     DigitalLED.display(2,TubeTab[3]);
     DigitalLED.display(3,TubeTab[4]);
     delay(1000);
     DigitalLED.clearDisplay();
     delay(100);
     DigitalLED.display(0,TubeTabwithPoit[8]);
     DigitalLED.display(1,TubeTabwithPoit[0]);
     DigitalLED.display(2,TubeTabwithPoit[0]);
     DigitalLED.display(3,TubeTabwithPoit[8]);
     delay(1000);
}
