#ifndef leaf_option_h
#define leaf_option_h

#include "menu_option.h"

/**
 * This class represents a leaf option i.e an option that has no children options (end of tree if you like).
 **/
class LeafOption : public MenuOption {

    protected:
        // Need more member variables

    public:
        // Constructors
        LeafOption() : MenuOption() {};

        //Another constructor
        LeafOption(char* optionTitle, ActionFuncPtr action = nullptr);

        // Another constructor (this is the one we're going to use usually.)
        LeafOption
        (
            char* optionTitle,
            MenuOption* prevOptionSameLevel,
            MenuOption* nextOptionSameLevel,
            MenuOption* prevOptionPrevLevel,
            ActionFuncPtr action = nullptr
        );

        // Member functions here..
};
#endif
