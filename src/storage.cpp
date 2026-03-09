
#include <iostream>
#include <fstream>

void store_cache_data(){
    std::fstream cacheFile; //declare a file
    cacheFile.open("assets/cache_data.txt", std::ios::out); //write mode

    if(cacheFile.is_open()){
        std::string line;
        while(getline(cacheFile, line)){
            cacheFile << line;
        }
    }
    else{
        std::cout<<"File unable to open";
    }
    cacheFile.close();
}