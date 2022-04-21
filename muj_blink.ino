/*
  using functions
  blink without delay
  blinking with two leds
  using button
*/

int blink1_state = LOW;
int blink1_high_interval = 500;
int blink1_low_interval = 1000;
unsigned long int blink1_counter = 0;
int blink1_port = 13;
int led1_state = 0; // 0 - off, 1 - blink, 2 - on

int blink2_state = LOW;
int blink2_high_interval = 100;
int blink2_low_interval = 500;
unsigned long int blink2_counter = 0;
int blink2_port = 12;
int led2_state = 0; // 0 - off, 1 - blink, 2 - on

int but1_port = 7;
int but1_last_state = HIGH; 
unsigned long int but1_counter = 0;

int but_led_select = 0;



// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(but1_port, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, blink1_state);
  pinMode(blink2_port, OUTPUT);
  pinMode(blink1_port, OUTPUT);
  digitalWrite(blink2_port, blink2_state);
  digitalWrite(blink1_port, blink1_state);
  delay(100);
}

// the loop function runs over and over again forever
void loop() {
  int press1 = 0;
  blink1();
  blink2();
  press1 = button1();
  if (press1 == 2) {
    but_led_select = (but_led_select + 1) % 2;
  }
  if (press1 == 1) {
    if (but_led_select == 0) {
      led1_state = (led1_state + 1) % 3;      
    }
    else {
      led2_state = (led2_state + 1) % 3;      
    }
    //digitalWrite(LED_BUILTIN, state);
  }
}

int button1() {
  int state;
  int press = 0;
  
  //digitalWrite(LED_BUILTIN, HIGH);
  state = digitalRead(but1_port);
  if (state != but1_last_state) {
    if (state == 0) {
      //digitalWrite(LED_BUILTIN, LOW);
      but1_counter = millis();
    }
    else {
      //digitalWrite(LED_BUILTIN, LOW);
      long int but_pressed = millis() - but1_counter;
      if (but_pressed > 2000) {
        // long press
        press = 2;
      }
      else {
        if (but_pressed > 50) {
          // short press
          press = 1;
        }
      }
    }
    but1_last_state = state;
  }
  return press;
}

void blink() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(blink1_high_interval);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(blink1_low_interval);                       // wait for a second
}

void blink1() {
  switch (led1_state) {
    case 1:  
      if (blink1_counter <= millis()) {
        if (blink1_state == HIGH) {
          blink1_state = LOW;
          blink1_counter = millis() + blink1_low_interval;
        }
        else {
          blink1_state = HIGH;
          blink1_counter = millis() + blink1_high_interval;
        }
        digitalWrite(blink1_port, blink1_state);
      }
      break;
    case 0: 
      {
        digitalWrite(blink1_port, LOW);
      }
      break;
    case 2: 
      {
        digitalWrite(blink1_port, HIGH);
      }
      break;
  }
}

void blink2() {
  switch (led2_state) {
    case 1:  
    if (blink2_counter <= millis()) {
      if (blink2_state == HIGH) {
        blink2_state = LOW;
        blink2_counter = millis() + blink2_low_interval;
      }
      else {
        blink2_state = HIGH;
        blink2_counter = millis() + blink2_high_interval;
      }
      digitalWrite(blink2_port, blink2_state);
    }
    break;
    case 0: 
    {
      digitalWrite(blink2_port, LOW);
    }
    break;
    case 2: 
    {
      digitalWrite(blink2_port, HIGH);
    }
    break;
  }
}
