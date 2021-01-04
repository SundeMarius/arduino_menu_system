#ifndef user_interface_h
#define user_interface_h

#include "menu.h"
#include "LiquidCrystal_I2C.h"
#include "button.h"

class UserInterface {
    private:
        Menu _menu;
        LiquidCrystal_I2C _display;
        Button* _buttons;

    public:
        UserInterface(/* args */);
        ~UserInterface();
};
#endif
