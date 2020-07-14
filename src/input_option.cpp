#include "input_option.h"

InputOption::InputOption
(
    char* optionTitle, 
    MenuOption* prevOptionSameLevel,
    MenuOption* nextOptionSameLevel,
    MenuOption* prevOptionPrevLevel,
    MenuOption* nextOptionNextLevel, 
    byte numbNextOptions,
    ActionFuncPtr action
) : ParentOption
(
    optionTitle, 
    prevOptionSameLevel, 
    nextOptionSameLevel,
    prevOptionPrevLevel, 
    nextOptionNextLevel,
    numbNextOptions,
    action
)
{
    _input = nullptr;
}