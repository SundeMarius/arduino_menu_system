#include "timer.h"

Timer::Timer() {}

void Timer::start_timer(unsigned int duration) {
    nextTimeout = millis() + duration;
}

bool Timer::timer_has_expired() {
  bool hasExpired  = false;
  if (millis() > nextTimeout) {
    hasExpired = true;
  } else {
    hasExpired = false;
  } return hasExpired;
}