#include "menu_option.h"

MenuOption::MenuOption(char* optionTitle, ActionFuncPtr action) {
    this->optionTitle = optionTitle;
    this->prevOptionSameLevel = nullptr;
    this->nextOptionSameLevel = nullptr;
    this->prevOptionPrevLevel = nullptr;
    this->nextOptionNextLevel = nullptr;
    this->action = action;
}

MenuOption::MenuOption
(
    char* optionTitle,
    MenuOption* prevOptionSameLevel,
    MenuOption* nextOptionSameLevel,
    MenuOption* prevOptionPrevLevel,
    MenuOption* nextOptionNextLevel,
    ActionFuncPtr action
)
{
    this->optionTitle = optionTitle;
    this->prevOptionSameLevel = prevOptionSameLevel;
    this->nextOptionSameLevel = nextOptionSameLevel;
    this->prevOptionPrevLevel = prevOptionPrevLevel;
    this->nextOptionNextLevel = nextOptionNextLevel;
    this->action = action;
}
