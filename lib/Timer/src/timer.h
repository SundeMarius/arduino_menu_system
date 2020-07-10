#ifndef TIMER_H
#define TIMER_H

#include <Arduino.h>

/**
 * This class represents a parent option i.e an option that can hold n number of children options.
 **/
class Timer {

    private:
        unsigned int nextTimeout = 0;
        
    public:
        /**
         * Default Constructor
         **/
        Timer();

        /**
        * Starts a timer for something to be performed
        */
        void start_timer(unsigned int duration);

        /**
        * Checks if the time we set in our timer has expired,
        * and then returns either true or false
        */
        bool timerHasExpired();
};

#endif