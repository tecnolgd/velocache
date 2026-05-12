//utility function for validating choices and key-value input entered by the user

#include "../include/utils.hpp"
#include "../include/cache.hpp"
#include <iostream>

int getValidatedChoice() {
    std::string input;
    int choice;
    
    std::cout << "Select an option (1-4): ";
    while (std::getline(std::cin, input)) {
        try {
            choice = std::stoi(input);

            if (choice >= 1 && choice <= 4 && input.length() == 1) {
                return choice;
            }
            
        } catch (...){}
        std::cout << "Invalid choice. Try again: ";
    }
    return 1;
}

std::string getValidatedKeyInput() {
    std::string key;
    std::cout << "Enter key: ";
    std::getline(std::cin, key);
    return key;
}

std::string getValidatedValueInput() {
    std::string value;
    std::cout << "Enter value: ";
    std::getline(std::cin, value);
    return value;
}

int getValidatedNumberInput(int maxLimit) {
  
    std::string input;
    int choice;
    
    while (std::getline(std::cin, input)) {
        try {
            choice = std::stoi(input);

            if (choice >= 1 && choice <= maxLimit && input.length() == 1) {
                return choice;
            }
            
        } catch (...){}
        std::cout<<"Invalid user count! Try Again: ";
    }
    return 0;
}