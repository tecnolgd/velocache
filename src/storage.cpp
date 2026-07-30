//cache data storage and loading mechanisms via file handling
#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include "../include/cache.hpp"
#include "../include/common.hpp"
#include "../include/utils.hpp"

//to save data present in the DLL
void Cache::store_cache_data() {
    std::fstream cacheFile("assets/cache_data.txt", std::ios::out);
    if (!cacheFile.is_open()) {
        std::cout << "File unable to open";
        return;
    }

    Node* current = tail;
    while (current) {
        cacheFile << current->key << "     " << current->value << std::endl;
        current = current->prev;
    }
    std::cout << std::endl;
}

//to print DLL data from the file
void printData(){
    std::fstream cacheFile;
    std::string currentLine;
    std::string previousLine = "";
    bool isFirst = true;
   
    cacheFile.open("assets/cache_data.txt", std::ios::in);

    std::cout << " Key  |  Value"<<std::endl;

    while (std::getline(cacheFile, currentLine)) {
        if (currentLine.empty()){ //loop till the n-1 (EOF-1) line
            continue;
        }
        // Print the previous line first (since it wasn't the last line). Executes [total_lines - 1] times
        if (!isFirst) {
            std::cout << previousLine << std::endl;
        }

        previousLine = currentLine;
        isFirst = false;
    }

    // The loop ended, meaning 'previousLine' holds the absolute LAST line in the file
    if (!isFirst && !previousLine.empty()) {
        std::cout << previousLine << "  [ Recent ]" << std::endl;
    }
    else{
        std::cout<<"Oops! Data cant't be displayed at the moment.\n";
    }
}

//load cache data from the last session
void Cache::load_from_file() {
    std::ifstream load_file("assets/cache_data.txt");
    if (!load_file) {
        std::cerr << "Error: Could not open file." << std::endl;
        return;
    }

    if (validate_file(load_file, *this)) {
        std::cout << "LOG: Cache loaded from the file" << std::endl;
    } else {
        std::cerr << "Error: Loading failed." << std::endl;
        clear_cache();
    }
    load_file.close();
}

//clear cache
void Cache::clear_cache() {
    Node* current = head;
    while (current != nullptr) {
        Node* next_node = current->next;
        delete current;
        current = next_node;
    }

    head = nullptr;
    tail = nullptr;
    cacheMap.clear();

    std::ofstream clear_file("assets/cache_data.txt", std::ios::out | std::ios::trunc);
    clear_file.close();

    std::cout << "Cache cleared successfully." << std::endl;
} 
