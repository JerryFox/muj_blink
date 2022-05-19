/*
  using functions
  blink without delay
  blinking with two leds
  using button
  object version
*/

const byte BUTTON_PIN = 7;
const byte LED1_PIN = 13;
const byte LED2_PIN = 12;

class Led {
  public:
    int port;
    int blink_state = LOW;
    int blink_high_interval = 500;
    int blink_low_interval = 1000;
    int state = 0; // 0 - off, 1 - blink, 2 - on
    unsigned long int blink_counter = 0;
    
    void setup(int ipin) {
      pinMode(ipin, OUTPUT);
      port = ipin;
      digitalWrite(port, blink_state);
    }

    void loop() {
      switch (state) {
        case 1:  
          if (blink_counter <= millis()) {
            if (blink_state == HIGH) {
              blink_state = LOW;
              blink_counter = millis() + blink_low_interval;
            }
            else {
              blink_state = HIGH;
              blink_counter = millis() + blink_high_interval;
            }
            digitalWrite(port, blink_state);
          }
          break;
        case 0: 
          {
            digitalWrite(port, LOW);
          }
          break;
        case 2: 
          {
            digitalWrite(port, HIGH);
          }
          break;
      }
    }
};


class Button {
  public:
    int but_port = 7;
    int but_last_state = HIGH; 
    long int but_counter = 0;

    int pin;
    void setup(int ipin) {
      pinMode(ipin, INPUT_PULLUP);
      pin = ipin;
    }

    int loop() {
      int state;
      int press = 0;
      
      //digitalWrite(LED_BUILTIN, HIGH);
      state = digitalRead(but_port);
      if (state != but_last_state) {
        if (state == 0) {
          //digitalWrite(LED_BUILTIN, LOW);
          but_counter = millis();
        }
        else {
          //digitalWrite(LED_BUILTIN, LOW);
          long int but_pressed = millis() - but_counter;
          //Serial.println(but_pressed);
          if (but_pressed > 1000) {
            // long press
            //Serial.println("long");
            press = 2;
          }
          else {
            if (but_pressed > 50) {
              // short press
              //Serial.println("short");
              press = 1;
            }
          }
        }
        but_last_state = state;
      }
      return press;
    }
};

Button button;
Led led1;
Led led2;
int but_led_select = 0;


void setup() {
  button.setup(BUTTON_PIN);
  led1.setup(LED1_PIN);
  led2.setup(LED2_PIN);
  led2.blink_high_interval = 30;
  led2.blink_low_interval = 1000;
}

void loop() {
  int press1 = button.loop();
  if (press1 == 2) {
    but_led_select = (but_led_select + 1) % 2;
  }
  if (press1 == 1) {
    if (but_led_select == 0) {
      led1.state = (led1.state + 1) % 3;      
    }
    else {
      led2.state = (led2.state + 1) % 3;      
    }
  }
  led1.loop();
  led2.loop();
}
