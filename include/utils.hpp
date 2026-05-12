#ifndef UTILS
#define UTILS

#include <string>

int getValidatedChoice(); //function to validate user choice in velocache menu
std::string getValidatedKeyInput();      //get validated key from user
std::string getValidatedValueInput();   //get validated value from user
int getValidatedNumberInput(int maxLimit = 1000); //get validated number from user

#endif