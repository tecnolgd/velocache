//server.cpp --> the cache application
#include "../include/velocache/cache.hpp"
#include "../include/velocache/common.hpp"

int main(){
    int number, choice;
    std::string userName, data;

    std::cout<<"VeloCache - high-speed LRU eviction cache >>>>\n";
        std::cout<<"Enter Operation choice(1 --> use cache; 2 --> display cache contents): ";
    std::cin>>choice;
    
    load_from_file(); //load stored cache data from the file (hydration)

    std::cout<<"Enter number of users: ";
    std::cin>>number;
    for(int i=0; i<number; i++){
        
        std::cout<<"Enter username- "<<i+1<<"and its data: ";
        std::cin>>userName>>data;
        putValue(userName, data);
    }
    store_cache_data(head);
    printData();

    std::string dataNeeded;
    std::cout<<"\nEnter username(key) for which data is to be found: ";
    std::cin>>dataNeeded;
    std::cout<<"Getting data: "<< getValue(dataNeeded)<<std::endl;
    store_cache_data(head);
    printData();
    
    return 0;
}