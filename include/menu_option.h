#ifndef menu_option_h
#define menu_option_h

#include <string>

// Just to be able to compile with g++ (does not by default include datatype
// 'byte')
#ifndef Arduino_h
#define byte unsigned char
using namespace std;
#endif

/**
 * Represents an abstract class that is the base class for all menu options
 **/
class MenuOption {

    private:
        // Member fields
        // A description of the option (e.g "Feed pet")
        string description;

    public:
        // Constructors
        MenuOption();
        MenuOption(string desc);

        // Member functions here..
        string get_description() const { return description; }

        // Purpose of this method is just to make the class abstract (change later)
        virtual void getText() = 0; // Pure virtual function makes this class abstract
};

#endif
