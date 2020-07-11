#ifndef menu_option_h
#define menu_option_h

#include "Arduino.h"

#define byte unsigned char

typedef void (*ActionFuncPtr);

/**
 * Represents a class that is the base class for all menu options
 **/
class MenuOption {

    protected:
        // Member fields
        // The text to display for this option (C-array)
        char* _optionTitle;
        // DLL pointer to previous node same level
        MenuOption* _prevOptionSameLevel; 
        // DLL pointer to next node same level
        MenuOption* _nextOptionSameLevel;
        // A pointer to the parent of (*this)  
        MenuOption* _prevOptionPrevLevel;
        // A function pointer to an "action" sub-routine
        ActionFuncPtr _action;

    public:
        // Constructors
        // Default one
        MenuOption() : _optionTitle(nullptr), _prevOptionSameLevel(nullptr), 
                       _prevOptionPrevLevel(nullptr), _nextOptionSameLevel(nullptr), _action(nullptr) {}

        // Destructor (Ensure proper garbage management)
        //~MenuOption();
        
        // Another constructor (this is the one we're going to use usually.)
        MenuOption
        (   
            char* optionTitle, 
            MenuOption* prevOptionSameLevel,
            MenuOption* nextOptionSameLevel,
            MenuOption* prevOptionPrevLevel,
            ActionFuncPtr action = nullptr   
        );

        // Member functions here..
        char* getOptionTitle() const { return _optionTitle; }

        MenuOption* getPrevOptionSameLevel() const { return _prevOptionSameLevel; }

        MenuOption* getNextOptionSameLevel() const { return _nextOptionSameLevel; }

        MenuOption* getPrevOptionPrevLevel() const { return _prevOptionPrevLevel; }

        ActionFuncPtr getAction() const { return _action; }

        // Purpose of this method is just to make the class abstract (change later)
        //virtual void getText() = 0; // Pure virtual function makes this class abstract
};

#endif
