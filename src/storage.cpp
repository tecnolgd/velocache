#include <iostream>
#include <fstream>

int main(){
    std::fstream cacheFile; //declare a file
    cacheFile.open("assets/cache_data.txt", std::ios::out); //write mode

    if(cacheFile.is_open()){
        cacheFile << "cache data";
    }
    else{
        std::cout<<"File unable to open";
    }
    cacheFile.close();
}