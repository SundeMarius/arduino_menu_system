/*
Button library for button interactions taking care of debouncing phenomena.
Creator: Marius Sunde S.
Version: 1.0
Last edit: 28.07.2018
*/
#ifndef button_h
#define button_h

#define byte unsigned char

class Button {
private:
  byte btnPin;
  bool state, lastState, changed, enablePullUp;
  unsigned long ms_lastChanged, ms_dbcTime;
public:
  //Constructor:
  /*------------------------------
            -expects button pin (number)
            -optional: set debounce time in millisec (number)
            -optional: enable pull_up (default: true)
  ----------------------------*/
  Button(byte buttonPin, unsigned long dbcTime = 40, bool EnablePullUp=true) :
  btnPin(buttonPin), ms_dbcTime(dbcTime), enablePullUp(EnablePullUp),
  ms_lastChanged(0) {}
  //Member functions
  /*------------------------------
    Initializes a button
    ----------------------------*/
  void init();
  /*------------------------------
    Checks if button was released
    -returns true if released
    -returns false if not released
    Does not change the state of button
    ----------------------------*/
  bool wasReleased();
  /*------------------------------
    Get reading from button.
    Changes the state of button if a proper change is detected
    ----------------------------*/
  void getReading();
  bool isPressed();
};
#endif
