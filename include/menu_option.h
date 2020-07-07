#ifndef menu_option_h
#define menu_option_h

#include <string>

// Just to be able to compile with g++ (does not by default include datatype
// 'byte')
#ifndef Arduino_h
#define byte unsigned char
using namespace std;
#endif


class MenuOption {
private:
    // Member fields
    // A description of the option (e.g "Feed pet")
    string description;
    // Specify number of "childrens" this MenuOption is parent to.
    byte numbNextOptions;
    // Pointer to a children MenuOption
    MenuOption* nextOption;
public:
    // Constructors
    MenuOption() = default;
    MenuOption(string des);
    MenuOption(string des, MenuOption* nOption, byte NNOptions);
    // Member functions here..
    string get_description() const { return description; }
    byte get_number_next_options() const { return numbNextOptions; }
};
#endif
