//utility function for validating choices entered by the user in the menu

#include "../include/utils.h"

int getValidatedChoice() {
    int choice;
    while (true) {
        std::cout << "Select an option (1-4): ";
        if (std::cin >> choice) {
            if (choice >= 1 && choice <= 4) {
                return choice;
            }
            std::cout << "Invalid range! ";
        } else {
            //clear the error flag and discard invalid input (like letters)
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input! Please enter a number: ";
        }
    }
}