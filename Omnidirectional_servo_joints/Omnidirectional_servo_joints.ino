#include <Servo.h>

Servo servo1;
Servo servo2;

void setup() {
  servo1.attach(10);
  servo2.attach(11);
}

void loop() {
  // Move servo1 from 0 to 180 degrees
  for (int pos1 = 0; pos1 <= 180; pos1 += 1) {
    servo1.write(pos1);
    delay(15); // Delay for servo1 can be different if desired
  }

  // Move servo2 from 0 to 180 degrees, independently
  for (int pos2 = 0; pos2 <= 180; pos2 += 1) {
    servo2.write(pos2);
    delay(5); // Delay for servo2 can be different if desired
  }

  // Move servo1 back from 180 to 0 degrees
  for (int pos1 = 180; pos1 >= 0; pos1 -= 1) {
    servo1.write(pos1);
    delay(15); // Delay for servo1 can be different if desired
  }

  // Move servo2 back from 180 to 0 degrees, independently
  for (int pos2 = 180; pos2 >= 0; pos2 -= 1) {
    servo2.write(pos2);
    delay(5); // Delay for servo2 can be different if desired
  }
}
