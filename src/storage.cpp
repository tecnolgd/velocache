
#include <iostream>
#include <fstream>
#include "../include/velocache/cache.hpp"
#include "../include/velocache/common.hpp"


//to save data present in the DLL

void store_cache_data(Node* current){
    std::fstream cacheFile; //declare a file
    cacheFile.open("assets/cache_data.txt", std::ios::out); //write mode

    if(cacheFile.is_open()){
        current = head;
    cacheFile <<"List (MRU) -- > (LRU): \n";
    while(current){
        cacheFile <<"[" <<current->key <<":" << current->value << "]";
        current= current->next;
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
        while(getline(cacheFile, line)){
            std::cout << line;
        }
        std::cout<<std::endl;
    }
    else{
        std::cout<<"Oops! Data cant't be displayed at the moment.\n";
    }

}