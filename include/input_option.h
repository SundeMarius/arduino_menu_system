#ifndef input_option_h
#define input_option_h

#include "menu_option.h"

/**
 * This class represents an input option i.e an option that requests an input from the user and stores it in a member field.
 **/
class InputOption : public MenuOption {

    private:
        char* input;

    public:
        // Default constructor
        InputOption() : MenuOption(), input(nullptr) {}
        // Another constructor (this is the one we're going to use usually.)
        InputOption
        (
            char* optionTitle,
            MenuOption* prevOptionSameLevel,
            MenuOption* nextOptionSameLevel,
            MenuOption* prevOptionPrevLevel,
            MenuOption* nextOptionNextLevel,
            ActionFuncPtr action
        );
};

#endif
