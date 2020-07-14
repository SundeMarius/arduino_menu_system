#ifndef input_option_h
#define input_option_h

#include "parent_option.h"

/**
 * This class represents an input option i.e an option that requests an input from the user and stores it in a member field.
 **/
class InputOption : public ParentOption {
    
    private:
        char* _input;
    
    public:
        // Default constructor
        InputOption() : ParentOption(), _input(nullptr) {}
        // Another constructor (this is the one we're going to use usually.)
        InputOption
        (
            char* optionTitle, 
            MenuOption* prevOptionSameLevel,
            MenuOption* nextOptionSameLevel,
            MenuOption* prevOptionPrevLevel,
            MenuOption* nextOptionNextLevel, 
            byte numbNextOptions,
            ActionFuncPtr action
        );

};

#endif