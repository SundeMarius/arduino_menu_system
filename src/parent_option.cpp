#include "parent_option.h"

ParentOption::ParentOption
(
    char* optionTitle, 
    MenuOption* prevOptionSameLevel,
    MenuOption* nextOptionSameLevel,
    MenuOption* prevOptionPrevLevel,
    MenuOption* nextOptionNextLevel, 
    byte numbNextOptions,
    ActionFuncPtr action
) : MenuOption
(
    optionTitle, 
    prevOptionSameLevel,
    nextOptionSameLevel,
    prevOptionPrevLevel,
    action
)
{
    _nextOptionNextLevel = nextOptionNextLevel; 
    _numberOfNextOptions = numbNextOptions;
}
