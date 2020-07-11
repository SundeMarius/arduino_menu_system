#include "menu_option.h"

MenuOption::MenuOption
(
    char* optionTitle, 
    MenuOption* prevOptionSameLevel,
    MenuOption* nextOptionSameLevel,
    MenuOption* prevOptionPrevLevel,
    ActionFuncPtr action = nullptr
) 
{
    _optionTitle = optionTitle;
    _prevOptionSameLevel = prevOptionSameLevel;
    _nextOptionSameLevel = nextOptionSameLevel;
    _prevOptionPrevLevel = prevOptionPrevLevel;
    _action = action;        
}

// MenuOption::~MenuOption() {
//     delete _optionTitle;
//     delete _prevOptionSameLevel;
//     delete _nextOptionSameLevel;
//     delete _prevOptionPrevLevel;
//     delete _action;
// }