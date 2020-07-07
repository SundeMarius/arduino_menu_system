#ifndef parent_option_h
#define parent_option_h

#include <string>
// Include MenuOption
#include "menu_option.h"

/**
 * This class represents a parent option i.e an option that can hold n number of children options.
 **/
class ParentOption : public MenuOption {

    private:
        // Specify number of "childrens" this MenuOption is parent to.
        byte numberOfNextOptions;
        // Pointer to a children MenuOption
        MenuOption* nextOption;
        // Need more member variables 
        
    public:
        // Constructors
        ParentOption() : MenuOption(), nextOption(nullptr), numberOfNextOptions(0) {};
            // ANicholasson's comment: Might want to change ParentOption argument to be a more "children" type of option class (TreeChildrenOption something something)
            // SundeMarius's comment: ParentOption* is fine as an argument if the child is indeed a parent.
            //                        I think this can be solved by using a pointer to the base class (MenuOption) as datatype 
            //                        (both ParentOption and LeafOption are MenuOptions).
        ParentOption(string des, MenuOption* nextOption, byte numbNextOptions);

        // Member functions here..
        byte get_number_next_options() const { return numberOfNextOptions; }
};

#endif