#ifndef TIMER_H
#define TIMER_H

class Timer {

    private:
        unsigned long _nextTimeout;

    public:
        /**
         * Default Constructor
         **/
        Timer();

        /**
        * Starts a timer for something to be performed
        */
        void start_timer(unsigned long duration);

        /**
        * Checks if the time we set in our timer has expired,
        * and then returns either true or false
        */
        bool timer_has_expired();
};

#endif
