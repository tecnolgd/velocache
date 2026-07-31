//server.cpp --> the cache application

#include "../include/cache.hpp"
#include "../include/common.hpp"
#include "../include/utils.hpp"
#include <cctype>
#include <csignal>
#include <cstdlib>

namespace {
    Cache* g_cache = nullptr;

    int parseCacheCapacity(int argc, char* argv[], int defaultCapacity = 3) {
        int capacity = defaultCapacity;
        for (int i = 1; i + 1 < argc; ++i) {
            std::string arg = argv[i];
            if (arg == "--capacity" || arg == "-c") {
                try {
                    capacity = std::stoi(argv[++i]);
                } catch (...) {
                    capacity = defaultCapacity;
                }
            }
        }
        return capacity > 0 ? capacity : defaultCapacity;
    }

    void persistCacheOnExit() {
        if (g_cache) {
            g_cache->store_cache_data(); // store cache data for the next session
        }
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

int main(int argc, char* argv[]) {
    int number, choice;
    std::string userName, data;
    std::string dataNeeded;

    int capacity = parseCacheCapacity(argc, argv);
    static Cache cache(capacity); // static so g_cache remains valid for the atexit callback
    g_cache = &cache;

    std::cout << "velocache >>>>\n";
    std::cout << "Cache capacity: " << capacity << "" << std::endl;

    cache.load_from_file(); //load cache data once every session

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
                    if (!confirmOverwrite(userName, cache)) {
                        continue;
                    }

                    data = getValidatedValueInput();
                    cache.putValue(userName, data);
                }
                break;

            case 2: 
                std::cout<<"\n";
                dataNeeded = getValidatedKeyInput();
                if (!dataNeeded.empty()) {
                    std::cout << "Getting data: " << cache.getValue(dataNeeded) << std::endl;
                }
                break;

            case 3:
                std::cout<<std::endl;
                printData();
                break;
            
            case 4: 
                std::cout << "Saving cache to disk..." << std::endl;
                cache.store_cache_data();
                std::cout << "Cache saved successfully." << std::endl;
                break;

            case 5: 
                std::cout << "Clearing cache..." << std::endl;
                cache.clear_cache();
                break;

            case 6:
                std::cout << "Server terminated.\n";
                return 0; // normal shutdown triggers destructors and atexit handlers
            
            default: std::cout<<"Invalid choice! Try again.\n";
        }
    }while(true);
        
    return 0;
}
