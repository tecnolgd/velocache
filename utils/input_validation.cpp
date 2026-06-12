//utility function for validating choices and key-value input entered by the user


#include "../include/cache.hpp"
#include "../include/utils.hpp"
#include <iostream>


int getValidatedChoice() {
    std::string input;
    int choice;
    
    std::cout << "Select an option (1-5): ";
    while (std::getline(std::cin, input)) {
        try {
            choice = std::stoi(input);

            if (choice >= 1 && choice <= 5 && input.length() == 1) {
                return choice;
            }
            
        } catch (...){}
        std::cout << "Invalid choice. Try again: ";
    }
    return 1;
}

std::string getValidatedKeyInput() {
    std::string key;

    while (true) {
        std::cout << "Enter key: ";
        if (!std::getline(std::cin, key) || key.empty()) {
            std::cout << "Error: Key cannot be empty. Try again.\n";
            continue;
        }

        if (key.length() > 256) { // Arbitrary limit for a cache key
            std::cout << "Error: Key too long (max 256 chars).\n";
            continue;
        }
        return key;
    }
}

std::string getValidatedValueInput() {
    std::string value;

    while (true) {
        std::cout << "Enter value: ";
        if (!(std::getline(std::cin, value))) {
            std::cin.clear(); // Reset stream state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Error reading input. Please try again.\n";
            continue;
        }
        return value;
    }
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

bool confirmOverwrite(const std::string& key) {
    std::string input;
    while (true) {
        std::cout << "Warning: key '" << key << "' already exists. Overwrite? (y/n): ";
        if (!std::getline(std::cin, input)) {
            std::cin.clear();
            continue;
        }
        if (input.empty()) {
            continue;
        }
        char choice = std::tolower(input[0]);
        if (choice == 'y') {
            return true;
        }
        if (choice == 'n') {
            return false;
        }
        std::cout << "Please enter 'y' or 'n'.\n";
    }
}