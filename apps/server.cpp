//server.cpp --> the cache application

#include "../include/cache.hpp"
#include "../include/common.hpp"
#include "../include/utils.hpp"
#include <cctype>

int main(){
    int number, choice;
    std::string userName, data;
    std::string dataNeeded;

    std::cout<<"velocache >>>>\n";

    load_from_file(); //load cache data once every session

    atexit([]() { store_cache_data(head); }); //save cache data when application exits implicitly or explicity

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
                exit(0);
            
            default: std::cout<<"Invalid choice! Try again.\n";
        }
    }while(true);
        
    return 0;
}