#include "input_option.h"

InputOption::InputOption
(
    char* optionTitle,
    MenuOption* prevOptionSameLevel,
    MenuOption* nextOptionSameLevel,
    MenuOption* prevOptionPrevLevel,
    MenuOption* nextOptionNextLevel,
    ActionFuncPtr action
) : ParentOption
(
    optionTitle,
    prevOptionSameLevel,
    nextOptionSameLevel,
    prevOptionPrevLevel,
    nextOptionNextLevel,
    action
)
{
    _input = nullptr;
}
