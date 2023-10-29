/*
Temperature sensor connect to AO
Relay connetct to D5
*/

#include <math.h>
int a;
float temperature;
int B=3975;                  //B value of the thermistor
float resistance;
// Connect the Relay to digital pin D5.
// give it a name:
int Relay = 5;

void setup()
{
  // initialize the digital pin as an output.
  pinMode(Relay, OUTPUT);  
  Serial.begin(9600);  
}

void loop()
{
    a=analogRead(0);
    resistance=(float)(1023-a)*10000/a; //get the resistance of the sensor;
    temperature=1/(log(resistance/10000)/B+1/298.15)-273.15;//convert to temperature via datasheet ;
    delay(1000);
    Serial.print("Current temperature is ");
    Serial.println(temperature);
    if(temperature>30)
    {
          digitalWrite(Relay, HIGH);  //if temperature >20 degree,turn the Relay on,fan working
    }
    else
    {
         digitalWrite(Relay, LOW);//if temperature <=20 degree,turn the Relay off,fan not working
    }
    
}
