#ifndef menu_option_h
#define menu_option_h

#define byte unsigned char

typedef void (*ActionFuncPtr);

/**
 * Represents a class that is the base class for all menu options
 **/
class MenuOption {
    protected:
        // Member fields
        // DLL pointer to previous node same level
        MenuOption* prevOptionSameLevel;
        // DLL pointer to next node same level
        MenuOption* nextOptionSameLevel;
        // A pointer to the parent of (*this)
        MenuOption* prevOptionPrevLevel;
        // A pointer to the parent of (*this)
        MenuOption* nextOptionNextLevel;
        // The text to display for this option (C-array)
        char* optionTitle;
        // A function pointer to an "action" sub-routine
        ActionFuncPtr action;

    public:
        // Constructors
        // Default one
        MenuOption() : optionTitle(nullptr), prevOptionSameLevel(nullptr),
                       prevOptionPrevLevel(nullptr), nextOptionSameLevel(nullptr),
                       nextOptionNextLevel(nullptr), action(nullptr) {}

        // More constructors (these two are the ones we're going to use usually.)
        MenuOption(char* optionTitle, ActionFuncPtr action = nullptr);

        MenuOption
        (
            char* optionTitle,
            MenuOption* prevOptionSameLevel,
            MenuOption* nextOptionSameLevel,
            MenuOption* prevOptionPrevLevel,
            MenuOption* nextOptionNextLevel,
            ActionFuncPtr action = nullptr
        );

        // Member functions here..
        // sets and gets
        char* getOptionTitle() const { return optionTitle; }

        MenuOption* getPrevOptionSameLevel() { return prevOptionSameLevel; }

        MenuOption* getPrevOptionPrevLevel() { return prevOptionPrevLevel; }

        MenuOption* getNextOptionSameLevel() { return nextOptionSameLevel; }

        MenuOption* getNextOptionNextLevel() { return nextOptionNextLevel; }

        void setPrevOptionPrevLevel(MenuOption* prevOption) { prevOptionPrevLevel = prevOption; }

        void setPrevOptionSameLevel(MenuOption* prevOption) { prevOptionSameLevel = prevOption; }

        void setNextOptionSameLevel(MenuOption* nextOption) {
          this->nextOptionSameLevel = nextOption;
          nextOption->setPrevOptionSameLevel(this);
        }
        void setNextOptionNextLevel(MenuOption* nextOption) {
          this->nextOptionNextLevel = nextOption;
          nextOption->setPrevOptionPrevLevel(this);
        }

        ActionFuncPtr getAction() const { return action; }

        void setAction(ActionFuncPtr action) { action = action; }

        // Purpose of this method is just to make the class abstract (change later)
        //virtual void getText() = 0; // Pure virtual function makes this class abstract
};
#endif
