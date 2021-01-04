#include "leaf_option.h"

LeafOption::LeafOption(char* optionTitle, ActionFuncPtr action) : MenuOption(optionTitle, action) {}

LeafOption::LeafOption
(
    char* optionTitle,
    MenuOption* prevOptionSameLevel,
    MenuOption* nextOptionSameLevel,
    MenuOption* prevOptionPrevLevel,
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

}
