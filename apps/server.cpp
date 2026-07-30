//server.cpp --> the cache application

#include "../include/cache.hpp"
#include "../include/common.hpp"
#include "../include/utils.hpp"
#include <cctype>
#include <csignal>
#include <cstdlib>

Cache ch(3);

namespace {     //used to keep the enclosed functions private and accessible only in this file
    void persistCacheOnExit() {
        ch.store_cache_data(); //store cache data for the next session
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

    ch.load_from_file(); //load cache data once every session

    registerShutdownHandlers(); //save cache data during normal exits and termination signals

    do{
        std::cout<<"\nOperations supported\n1. Data storage\n2. Data retrieval\n3. Cache display\n4. Save Cache\n5. Clear Cache\n6. Exit\n";
        
        choice = getValidatedChoice();  //get validated choice from 'utils/input_validation.cpp'
        
        switch(choice){
            case 1:
                
                std::cout << "Enter number of users: ";
                number = getValidatedNumberInput(1000);
                
                for(int i=0; i<number; i++){
                    std::cout<<"\n--- User "<<i+1<<" ---\n";
                    userName = getValidatedKeyInput();
                    
                    //runs always, returns true if overwrite is needed or even if there is no overwrite issue; returns false if overwrite should be avoided and just continue ot the next input
                    //prompts and messages are displayed by the function itself
                    if (!confirmOverwrite(userName, ch)) {
                        continue;
                    }

                    data = getValidatedValueInput();
                    ch.putValue(userName, data);
                }
                break;

            case 2: 
                std::cout<<"\n";
                dataNeeded = getValidatedKeyInput();
                if (!dataNeeded.empty()) {
                    std::cout<<"Getting data: "<< ch.getValue(dataNeeded)<<std::endl;
                }
                break;

            case 3:
                std::cout<<std::endl;
                printData();
                break;
            
            case 4: 
                std::cout << "Saving cache to disk..." << std::endl;
                ch.store_cache_data();
                std::cout << "Cache saved successfully." << std::endl;
                break;

            case 5: 
                std::cout<<"Clearing cache..."<<std::endl;
                ch.clear_cache();
                break;

            case 6: 
                std::cout<<"Server terminated.\n";
                exit(0); //triggers atexit()
            
            default: std::cout<<"Invalid choice! Try again.\n";
        }
    }while(true);
        
    return 0;
}
