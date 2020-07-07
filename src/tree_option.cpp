#include "tree_option.h"

TreeOption::TreeOption(string des) : MenuOption(des) {
    nextOption = nullptr;
    numbNextOptions = 0;
}

TreeOption::TreeOption(string des, TreeOption* nOption, byte NNOptions) : MenuOption(des)  {
    nextOption = nOption;
    numbNextOptions = NNOptions; 
}
