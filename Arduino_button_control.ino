//Set pin locations on Arduino
const int LED = 12;
const int speaker = 5;
const int button = 6;

//Variable for reading the button push status
int buttonState = 0;

void setup() {
  //Set LED and speaker as OUTPUT. Set button as INPUT
  pinMode(LED, OUTPUT);
  pinMode(speaker, OUTPUT);
  pinMode(button, INPUT);
}

void loop() {
  //Reads button push status
  buttonState = digitalRead(button);
 
  if (buttonState == HIGH) {
    //Turn LED and speaker on
    digitalWrite(LED, HIGH);
    digitalWrite(speaker, HIGH);
  }
  else {
    //Turn LED and speaker off
    digitalWrite(LED, LOW);
    digitalWrite(speaker, LOW);
  }
}
