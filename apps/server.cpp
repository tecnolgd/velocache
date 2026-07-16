//server.cpp --> the cache application

#include "../include/cache.hpp"
#include "../include/common.hpp"
#include "../include/utils.hpp"
#include <cctype>
#include <csignal>
#include <cstdlib>

namespace {     //used to keep the enclosed functions private and accessible only in this file
    void persistCacheOnExit() {
        store_cache_data(head);
    }

    void handleTerminationSignal(int signal) {
        std::signal(signal, SIG_DFL);
        std::exit(128 + signal);
    }

    void registerShutdownHandlers() {
        std::atexit(persistCacheOnExit);
        std::signal(SIGINT, handleTerminationSignal);
        std::signal(SIGTERM, handleTerminationSignal);
    }
}

int main(){
    int number, choice;
    std::string userName, data;
    std::string dataNeeded;

    std::cout<<"velocache >>>>\n";

    load_from_file(); //load cache data once every session

    registerShutdownHandlers(); //save cache data during normal exits and termination signals

    do{
        std::cout<<"\nOperations supported\n1. Data storage\n2. Data retrieval\n3. Cache display\n4. Save Cache\n5. Exit\n";
        
        choice = getValidatedChoice();  //get validated choice from 'utils/input_validation.cpp'
        
        switch(choice){
            case 1:
                
                std::cout << "Enter number of users: ";
                number = getValidatedNumberInput(1000);
                
                for(int i=0; i<number; i++){
                    std::cout<<"\n--- User "<<i+1<<" ---\n";
                    userName = getValidatedKeyInput();

                    if (cacheMap.find(userName) != cacheMap.end()) {
                        if (!confirmOverwrite(userName)) {
                            std::cout << "Skipped duplicate key: " << userName << "\n";
                            continue;
                        }
                        std::cout << "Overwriting existing value for key: " << userName << "\n";
                    }

                    data = getValidatedValueInput();
                    putValue(userName, data);
                }
                break;

            case 2: 
                std::cout<<"\n";
                dataNeeded = getValidatedKeyInput();
                if (!dataNeeded.empty()) {
                    std::cout<<"Getting data: "<< getValue(dataNeeded)<<std::endl;
                }
                break;

            case 3:
                std::cout<<std::endl;
                printData();
                break;
            
            case 4: 
                std::cout << "Saving cache to disk..." << std::endl;
                store_cache_data(head);
                std::cout << "Cache saved successfully." << std::endl;
                break;

            case 5: 
                std::cout<<"Server terminated.\n";
                exit(0); //triggers atexit()
            
            default: std::cout<<"Invalid choice! Try again.\n";
        }
    }while(true);
        
    return 0;
}J