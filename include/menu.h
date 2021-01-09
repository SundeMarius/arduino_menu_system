#ifndef menu_h
#define menu_h

#include "menu_option.h"

const char MENU_SYSTEM_VERSION[] = "1.0";

class Menu {
    private:
        MenuOption* firstOption;
        MenuOption* currentOption;
        char* welcomeMessage;

        //DLL stuff, which in not interesting for user (private)
        //Given the HEAD node headOption (first node in a DLL), append menuOption to the end of the list.
        void appendOption(MenuOption* menuOption, MenuOption* headOption);
        //Given the HEAD node headOption (first node in a DLL), add menuOption to the beginning of the list.
        void pushOption(MenuOption* menuOption, MenuOption* headOption);
    public:
        //Constructors
        Menu() : firstOption(nullptr), currentOption(nullptr),
                 welcomeMessage(nullptr) {}
        Menu(char* welcome_message, MenuOption* first_option);

        //Member functions
        //Construction of menu
        void add_option(MenuOption* head, MenuOption* option, MenuOption* children=nullptr, byte numb_children=0);

        //Menu specific
        char* getWelcomeMessage() const { return welcomeMessage; }

        MenuOption* getCurrentOption() { return currentOption; }

        MenuOption* getFirstOption() { return firstOption; }

        void setCurrentOption(MenuOption* current_option) { currentOption = current_option; }


        //Stuff shared between all instances of "Menu"
        static const char* version() { return MENU_SYSTEM_VERSION; }

};

#endif
