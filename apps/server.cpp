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

    do{
        std::cout<<"\nOperations supported\n1. Data storage\n2. Data retrieval\n3. Cache display\n4. Exit\n";
        load_from_file();
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
                store_cache_data(head);
                break;

            case 2: 
                std::cout<<"\n";
                dataNeeded = getValidatedKeyInput();
                if (!dataNeeded.empty()) {
                    std::cout<<"Getting data: "<< getValue(dataNeeded)<<std::endl;
                    store_cache_data(head);
                }
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