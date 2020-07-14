#include "timer.h"

Timer::Timer() {
  _nextTimeout = 0;
}

void Timer::start_timer(unsigned long duration) {
    _nextTimeout = millis() + duration;
}

bool Timer::timer_has_expired() {
  return (millis() > _nextTimeout);
}