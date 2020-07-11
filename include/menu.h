#ifndef menu_h
#define menu_h

#include "menu_option.h"

#define MENU_SYSTEM_VERSION "1.0";

class Menu {  
    private:
        MenuOption* _currentOption;
        char* _welcomeMessage;

    public:
        const char* getVersion() const { return MENU_SYSTEM_VERSION; }
};

#endif
