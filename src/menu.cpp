#include "menu.h"

//Impl constructor here

//Member function impl.
void Menu::appendOption(MenuOption* headOption, MenuOption* menuOption) {
    // Make an extra pointer to HEAD used to iterate through list
    MenuOption* last = headOption;

    //if list is empty, make menuOption the HEAD and exit.
    if (headOption == nullptr) {
        menuOption->setPrevOptionSameLevel(nullptr);
        headOption = menuOption;
        return;
    }
    // else traverse list until end is reached
    while (last->getNextOptionSameLevel() != nullptr) {
        last = last->getNextOptionSameLevel();
    }

    //Set the next-pointer of last to menuOption
    last->setNextOptionSameLevel(menuOption);
    
    //Set prev-pointer of menuOption to last
    menuOption->setPrevOptionSameLevel(last);
}

void Menu::pushOption(MenuOption* headOption, MenuOption* menuOption) {
    // Make next-pointer of menuOption point to HEAD
    menuOption->setNextOptionSameLevel(headOption);
    // Make prev-pointer point to null (now menuOption is HEAD)
    menuOption->setPrevOptionSameLevel(nullptr);

    //if list is not empty, change prev-pointer of HEAD to menuOption
    if (headOption != nullptr) {
        headOption->setPrevOptionSameLevel(menuOption);
    } 

    //move the pointer of HEAD to menuOption
    headOption = menuOption;
}