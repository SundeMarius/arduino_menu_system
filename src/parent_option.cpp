#include "parent_option.h"

ParentOption::ParentOption(string des, MenuOption* nextOption, byte numbNextOptions) {
    description = des;
    // Comment: "this" is a pointer to the class object itself i.e the ParentOption object. 
                //To access a member variable from a pointer to some object, use the "->" operator. 
                //Alternative: It's equivalent to *(this).nextOption where *(pointer) is used to 
                             //dereference the pointer to access what it points to. 
    this->nextOption = nextOption;
    this->numberOfNextOptions = numbNextOptions;

}