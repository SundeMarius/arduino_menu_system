#include "leaf_option.h"

LeafOption::LeafOption
(
    char* optionTitle, 
    MenuOption* prevOptionSameLevel,
    MenuOption* nextOptionSameLevel,
    MenuOption* prevOptionPrevLevel,
    ActionFuncPtr action = nullptr
) : MenuOption
(
    optionTitle, 
    prevOptionSameLevel,
    nextOptionSameLevel, 
    prevOptionPrevLevel,
    action
) 
{

}