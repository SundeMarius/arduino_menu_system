#include "menu_option.h"

MenuOption::MenuOption(string des)
{
    description = des;
    numbNextOptions = 0;
    nextOption = nullptr;
}

MenuOption::MenuOption(string des, MenuOption* nOption, byte NNOptions) 
{
    description = des;
    numbNextOptions = NNOptions;
    nextOption = nOption;
}
