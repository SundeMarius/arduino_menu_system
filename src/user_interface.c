#include "user_interface.h"

void UserInterface::print_to_display(char* text) {
    byte characters = sizeof(text) - 1;
    //if the string is longer than 16 char (one row), wrap text to next row
    if (characters > 16) {
        char copy[40];
        strcpy(copy, text);
        copy[15] = 0;
        display.setCursor(0,0)
        display.print(copy);
        display.setCursor(15,0);
        display.print('-');
        display.setCursor(0,1);
        text = &text[15];
        display.print(text);
    } else {
        display.setCursor(0,0), display.print(text);
    }
}

void UserInterface::Init() {
    //Initialize display and buttons
    this->display.init();
    this->display.backlight();
    for (int i=0; i<4; ++i) {
      this->buttons[i].init();
    }
    //Print welcome message to screen
    print_to_display(menu.getWelcomeMessage());
}
