//utility function for validating choices entered by the user in the menu

#include "../include/utils.hpp"
#include <iostream>

int getValidatedChoice() {
    std::string choice;
    while (true) {
        std::cout << "Select an option (1-4): ";
        std::cin >> choice;

        // Check if the input is exactly one character and within '1'-'4'
        if (choice.length() == 1 && choice[0] >= '1' && choice[0] <= '4') {
            // Convert char to int ('1' becomes 1)
            return choice[0] - '0';
        }
        else{
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Invalid input! Please enter a single digit from 1 to 4.\n";
        }
    }
}