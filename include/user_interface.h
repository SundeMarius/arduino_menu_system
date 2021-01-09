#ifndef user_interface_h
#define user_interface_h

#include "LiquidCrystal_I2C.h"
#include "button.h"
#include "menu.h"

class UserInterface {
    private:
        Menu menu;
        LiquidCrystal_I2C display;
        //Array of buttons: okButton, returnButton, leftButton, rightButton
        Button* buttons;

        void print_to_display(char* text);

    public:
        UserInterface(Menu& menu, LiquidCrystal_I2C& display, Button* buttons);
        ~UserInterface();

        void init();

        //Button interactions

        //Sets/gets
        //void setOkButton(Button& ok_button) { this->okButton = ok_button; }
        //void setReturnButton(Button& return_button) { this->returnButton = return_button; }
        //void setLeftButton(Button& left_button) { this->leftButton = left_button; }
        //void setRightButton(Button& right_button) { this->rightButton =right_button; }

        //Misc. display methods
        void clearDisplay() {display.clear();}

};
#endif
