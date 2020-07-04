#include "Button.h"

//Member functions
void Button::init() {
  pinMode(btnPin, enablePullUp ? INPUT_PULLUP : INPUT);
  state = digitalRead(btnPin);
  lastState = state;
  changed = false;
}

void Button::getReading() {
  bool reading = digitalRead(btnPin); //read input of button pin
  //Reset timer if debouncing is happening
  if (reading != lastState) ms_lastChanged = millis();
  //check if button has changed state for longer than debounce time
  if (millis() - ms_lastChanged > ms_dbcTime) {
    //Toggle new state of button
     if (state != reading) {
        state = reading;
        changed = true;
     } else {
        changed = false;
     }
  }
  lastState = reading;
}

bool Button::wasReleased() {
  return enablePullUp ? state && changed : !state && changed;
}

bool Button::isPressed() {
  return enablePullUp ? !state : state;
}
