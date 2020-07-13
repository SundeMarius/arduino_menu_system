#ifndef menu_h
#define menu_h

#include "menu_option.h"

#define MENU_SYSTEM_VERSION "1.0";

class Menu {  
    private:
        MenuOption* _currentOption;
        char* _welcomeMessage;

    public:

        //Constructors
        Menu();

        //TODO implement a proper constructor for "Menu"w
        
        //Member functions
        
        //DLL stuff
        //Given the HEAD node headOption (first node in a DLL), append menuOption to the end of the list. 
        void appendOption(MenuOption* menuOption, MenuOption* headOption);
        
        //Given the HEAD node headOption (first node in a DLL), add menuOption to the beginning of the list.
        void pushOption(MenuOption* menuOption, MenuOption* headOption);


        //Menu specific
        char* getWelcomeMessage() const { return _welcomeMessage; }

        const char* version() { return MENU_SYSTEM_VERSION }

        MenuOption* getCurrentOption() const { return _currentOption; }

        void setCurrentOption(MenuOption* currentOption) { _currentOption = currentOption;}
};

#endif
