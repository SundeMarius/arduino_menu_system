#include <iostream>
#include "menu.h"

#define MAX_STRING_SIZE 40

char option_titles_lvl1[][MAX_STRING_SIZE] =
{
  "Play",
  "Options",
  "Scoreboard",
  "Exit"
};
char option_titles_lvl2[][MAX_STRING_SIZE] =
{
  "Difficulty 1",
  "Difficulty 2",
  "Difficulty 3",
  "Adjust brightness",
  "Set clock"
};

//Create all options in the menu
MenuOption o1(option_titles_lvl1[0]);
    MenuOption o11(option_titles_lvl2[0]);
    MenuOption o12(option_titles_lvl2[1]);
    MenuOption o13(option_titles_lvl2[2]);
MenuOption o2(option_titles_lvl1[1]);
    MenuOption o21(option_titles_lvl2[3]);
    MenuOption o22(option_titles_lvl2[4]);
MenuOption o3(option_titles_lvl1[2]);
MenuOption o4(option_titles_lvl1[3]);
//Create menu object
char WELCOME_MESSAGE[] = "Welcome!";
Menu menu(WELCOME_MESSAGE, &o1);

int main() {
    std::cout << "Hello, world!" << std::endl;
    //Add the options to complete the menu
    //Level 1
    menu.add_option(&o1, &o1, &o11);
    menu.add_option(&o1, &o2, &o21);
    menu.add_option(&o1, &o3);
    menu.add_option(&o1, &o4);
    //Level 2
    menu.add_option(&o11, &o12);
    menu.add_option(&o11, &o13);

    menu.add_option(&o21, &o22);

    //Print welcome message!
    std::cout << menu.getWelcomeMessage() << std::endl;
    std::cout << "Print all level 1 menus: ";
    while (menu.getCurrentOption()) {
        std::cout << menu.getCurrentOption()->getOptionTitle() << " ";
        menu.setCurrentOption(menu.getCurrentOption()->getNextOptionSameLevel());
    }
    //Change current option, reprint
    menu.setCurrentOption(&o22);
    std::cout << std::endl
              << menu.getCurrentOption()->getPrevOptionPrevLevel()->getOptionTitle()
              << std::endl;

    return 0;
}
