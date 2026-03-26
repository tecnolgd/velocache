//server.cpp --> the cache application
#include "../include/velocache/cache.hpp"
#include "../include/velocache/common.hpp"
#include <cctype>

int main(){
    int number, choice;
    std::string userName, data;
    std::string dataNeeded;

    std::cout<<"velocache >>>>\n";

    do{
        std::cout<<"\nOperations supported\n1. Data storage\n2. Data retrieval\n3. Cache display\n4. Exit\n";

        std::cout<<"Enter your choice: ";
        std::cin>>choice; //error check needed in future versions
        
        switch(choice){
            case 1:
                load_from_file(); //load stored cache data from the file (hydration)

                std::cout<<"Enter number of users: ";
                std::cin>>number;
                for(int i=0; i<number; i++){
                    
                    std::cout<<"Enter username- "<<i+1<<"and its data: ";
                    std::cin>>userName>>data;
                    putValue(userName, data);
                }
                store_cache_data(head);
                //printData(); --> optional to map the LRU eviction in action
                break;

            case 2: 
                std::cout<<"\nEnter username(key) for which data is to be found: ";
                std::cin>>dataNeeded;
                std::cout<<"Getting data: "<< getValue(dataNeeded)<<std::endl;
                store_cache_data(head);
                
                break;

            case 3:
                std::cout<<std::endl;
                printData();
                break;

            case 4: 
                std::cout<<"Server terminated.\n";
                exit(0);
            
            default: std::cout<<"Invalid choice! Try again.\n";
        }
    }while(true);
        
    return 0;
}