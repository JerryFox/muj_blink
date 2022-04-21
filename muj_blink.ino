/*
  using functions
  blink without delay
  blinking with two leds
*/

// the setup function runs once when you press reset or power the board

int myLED = 13;
int blinkState = HIGH;
int blinkHighInterval = 100;
int blinkLowInterval = 1000;
long int blinkCounter = 0;

int myLED2 = 12;
int blink2State = HIGH;
int blink2HighInterval = 100;
int blink2LowInterval = 300;
long int blink2Counter = 0;

void blink() {
  digitalWrite(myLED, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(myLED, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}

void blink1(int port) {
  if (blinkCounter <= millis()) {
    if (blinkState == HIGH){
      blinkState = LOW;
      blinkCounter = millis() + blinkLowInterval;
    }
    else {
      blinkState = HIGH;
      blinkCounter = millis() + blinkHighInterval;
    }
    digitalWrite(port, blinkState);   
  }
}

void blink2(int port) {
  if (blink2Counter <= millis()) {
    if (blink2State == HIGH){
      blink2State = LOW;
      blink2Counter = millis() + blink2LowInterval;
    }
    else {
      blink2State = HIGH;
      blink2Counter = millis() + blink2HighInterval;
    }
    digitalWrite(port, blink2State);   
  }
}

void setup() {
  // initialize digital pin myLED as an output.
  pinMode(myLED, OUTPUT);
  pinMode(myLED2, OUTPUT);
  pinMode(7, INPUT_PULLUP);
}

// the loop function runs over and over again forever
void loop() {
  //blink1(myLED);
  //blink2(myLED2);
  if (digitalRead(7) == LOW) {
    digitalWrite(myLED, HIGH);
  }
  else {
    digitalWrite(myLED, LOW);
  }
}
