//cache data storage and loading mechanisms via file handling
#include <iostream>
#include <fstream>
#include <string>
#include "../include/cache.hpp"
#include "../include/common.hpp"

//to save data present in the DLL
void store_cache_data(Node* current){
    std::fstream cacheFile; //declare a file
    cacheFile.open("assets/cache_data.txt", std::ios::out); //write mode

    if(cacheFile.is_open()){
        current = tail;

    while(current){
        cacheFile <<current->key <<"     "<< current->value <<std::endl;
        current= current->prev;
    }
    std::cout<<std::endl;
    }
    else{
        std::cout<<"File unable to open";
    }
    cacheFile.close();
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
        // Print the previous line first (since it wasn't the last line). Executes total_lines - 1 times
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
void load_from_file(){
    std::ifstream load_file("assets/cache_data.txt");
    if(! load_file){
        return;
    }

    std::string key, data;

    while (load_file >> key >> data) {
        putValue(key, data); 
    }

    load_file.close();
    std::cout<<"LOG: Cache loaded from the file" <<std::endl;
}
