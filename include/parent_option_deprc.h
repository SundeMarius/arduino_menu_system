#ifndef parent_option_h
#define parent_option_h

#include "menu_option.h"

/**
 * This class represents a parent option i.e an option that can hold n > 0 number of children options.
 **/
class ParentOption : public MenuOption {

    protected:
        // Specify number of "childrens" this MenuOption is parent to.
        byte numberOfNextOptions;
        // Pointer to a children MenuOption
        MenuOption* nextOptionNextLevel;
    public:
        // Default constructor
        ParentOption() : MenuOption(), nextOptionNextLevel(nullptr), numberOfNextOptions(0) {}

        // Another constructors (these are the ones we're going to use usually.)
        ParentOption(char* optionTitle, ActionFuncPtr action = nullptr);

        ParentOption
        (
            char* optionTitle,
            MenuOption* prevOptionSameLevel,
            MenuOption* nextOptionSameLevel,
            MenuOption* prevOptionPrevLevel,
            MenuOption* nextOptionNextLevel,
            ActionFuncPtr action
        );

        // Member functions here..
        byte getNumberOfNextOptions() const { return numberOfNextOptions; }

        void setNumberOfNextOptions(byte nextOptions) { numberOfNextOptions = nextOptions; }

        void incrementNumbOfOptions() { ++numberOfNextOptions; }

        MenuOption* getNextOptionNextLevel() const { return nextOptionNextLevel; }

        void setNextOptionNextLevel(MenuOption* nextOption) {
          this->nextOptionNextLevel = nextOption;
          nextOption->setPrevOptionPrevLevel(this);
        }
};

#endif
