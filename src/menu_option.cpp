#include "menu_option.h"

MenuOption::MenuOption(char* optionTitle, ActionFuncPtr action) {
    _optionTitle = optionTitle;
    _prevOptionSameLevel = nullptr;
    _nextOptionSameLevel = nullptr;
    _prevOptionPrevLevel = nullptr;
    _action = action;
}

MenuOption::MenuOption
(
    char* optionTitle,
    MenuOption* prevOptionSameLevel,
    MenuOption* nextOptionSameLevel,
    MenuOption* prevOptionPrevLevel,
    ActionFuncPtr action
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
