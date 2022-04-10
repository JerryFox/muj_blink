/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink
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
