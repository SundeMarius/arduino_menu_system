#include "menu.h"

//Impl constructor here
Menu::Menu(char* welcome_message, MenuOption* first_option) {
    this->welcomeMessage = welcome_message;
    this->firstOption = first_option;
    this->currentOption = first_option;
}

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


void Menu::add_option(MenuOption* head, MenuOption* option, MenuOption* children, byte numb_children) {
    //Append option to first option of menu
    if (head != option) {
        this->appendOption(head, option);
        //Set prev option prev level for each child
        MenuOption* parent = head->getPrevOptionPrevLevel();
        if (parent) {
            option->setPrevOptionPrevLevel(parent);
        }
    }
    //Make "children" the next level option(s) (child), "option" is parent
    if (children) {
        option->setNextOptionNextLevel(children);
        for (int i=0; i < numb_children; ++i) {
            children[i].setPrevOptionPrevLevel(option);
        }
    }
}
