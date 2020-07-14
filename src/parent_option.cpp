#include "parent_option.h"

ParentOption::ParentOption
(
    char* optionTitle, 
    ActionFuncPtr action = nullptr
) : MenuOption(optionTitle, action), _nextOptionNextLevel(nullptr), _numberOfNextOptions(0) 
{
    
}
  

ParentOption::ParentOption
(
    char* optionTitle, 
    MenuOption* prevOptionSameLevel,
    MenuOption* nextOptionSameLevel,
    MenuOption* prevOptionPrevLevel,
    MenuOption* nextOptionNextLevel, 
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
    _numberOfNextOptions = 0;
}
