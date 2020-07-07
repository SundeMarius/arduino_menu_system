

#ifndef tree_option_h
#define tree_option_h

#include <string>
// Include MenuOption
#include <menu_option.h>

// Just to be able to compile with g++ (does not by default include datatype
// 'byte')
#ifndef Arduino_h
#define byte unsigned char
using namespace std;
#endif

/**
 * This class represents a tree option. Which is an option that can hold n number of children options
 **/
class TreeOption : public MenuOption {

    private:
        // Specify number of "childrens" this MenuOption is parent to.
        byte numbNextOptions;
        // Pointer to a children MenuOption
        MenuOption* nextOption;
        
    public:
        // Constructors
        TreeOption() : MenuOption() {};
        TreeOption(string des) : MenuOption(des) {};

        // Might want to change TreeOption argument to be a more "children" type of option class (TreeChildrenOption something something)
        TreeOption(string des, TreeOption* nOption, byte NNOptions) : MenuOption(des) {};

        // Member functions here..
        byte get_number_next_options() const { return numbNextOptions; }
};

#endif