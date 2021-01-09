#include "parent_option_deprc.h"

ParentOption::ParentOption
(
    char* optionTitle,
    ActionFuncPtr action
) : MenuOption(optionTitle, action), nextOptionNextLevel(nullptr), numberOfNextOptions(0)
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
    nextOptionNextLevel,
    action
)
{
    nextOptionNextLevel = nextOptionNextLevel;
    numberOfNextOptions = 0;
}
