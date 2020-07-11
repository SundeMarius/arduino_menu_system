#ifndef parent_option_h
#define parent_option_h

#include "menu_option.h"

/**
 * This class represents a parent option i.e an option that can hold n > 0 number of children options.
 **/
class ParentOption : public MenuOption {

    protected:
        // Specify number of "childrens" this MenuOption is parent to.
        byte _numberOfNextOptions;
        // Pointer to a children MenuOption
        MenuOption* _nextOptionNextLevel;
        
    public:
        // Default constructor
        ParentOption() : MenuOption(), _nextOptionNextLevel(nullptr),   _numberOfNextOptions(0) {}

        // Another constructor (this is the one we're going to use usually.)
        ParentOption
        (
            char* optionTitle, 
            MenuOption* prevOptionSameLevel,
            MenuOption* nextOptionSameLevel,
            MenuOption* prevOptionPrevLevel,
            MenuOption* nextOptionNextLevel, 
            byte numbNextOptions,
            ActionFuncPtr action
        );

        // Member functions here..
        byte getNumberOfNextOptions() const { return _numberOfNextOptions; }

        MenuOption* getNextOptionNextLevel() const { return _nextOptionNextLevel; }
};

#endif