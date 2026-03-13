
#include <iostream>
#include <fstream>
#include <string>
#include "../include/velocache/cache.hpp"
#include "../include/velocache/common.hpp"


//to save data present in the DLL

void store_cache_data(Node* current){
    std::fstream cacheFile; //declare a file
    cacheFile.open("assets/cache_data.txt", std::ios::out); //write mode

    if(cacheFile.is_open()){
        current = tail;

    while(current){
        cacheFile <<current->key <<"  "<< current->value <<std::endl;
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
    cacheFile.open("assets/cache_data.txt", std::ios::in);
    if(cacheFile.is_open()){
        std::string line;
        std::cout << " Key  |  Value"<<std::endl;
        while(getline(cacheFile, line)){
            
            std::cout << "* " << line <<std::endl;
        }
    }
    else{
        std::cout<<"Oops! Data cant't be displayed at the moment.\n";
    }
}

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