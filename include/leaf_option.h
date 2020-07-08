#ifndef leaf_option_h
#define leaf_option_h

#include <string>
// Include MenuOption
#include "menu_option.h"

/**
 * This class represents a leaf option i.e an option that has no children options (end of tree if you like).
 **/
class LeafOption : public MenuOption {
        
    private:
        // Need more member variables 
        
    public:
        // Constructors
        LeafOption() : MenuOption() {};

        LeafOption(string des);

        // Member functions here..
};

#endif