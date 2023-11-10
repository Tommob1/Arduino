#include <LiquidCrystal.h>
#include <Servo.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
Servo servo;

int led = 13;
int pos = 0;
int activations = 0; // Keep track of how many times the servo has hit 180 degrees

void setup() {
  pinMode(led, OUTPUT);
  servo.attach(3);
  lcd.begin(16, 2);
  lcd.print("Claw mode: Crush");
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    servo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(1);                       // waits 10ms for the servo to reach the position
    if (pos == 180) {               // check if the servo has reached 180 degrees
      activations += 1;             // increment the activation count
      lcd.setCursor(0, 1);          // set the cursor to the second row
      lcd.print("Activations: ");   // print the message
      lcd.print(activations);       // print the number of activations
      digitalWrite(led, HIGH);
    }
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    servo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(5);                       // waits 10ms for the servo to reach the position
    digitalWrite(led, LOW);
  }
}
