//cache.cpp --> main engine of LRU eviction based cache
# include "../include/velocache/cache.hpp"

std::unordered_map<std::string, Node*> cacheMap;
Node* head = nullptr;
Node* tail = nullptr;

int main(){
    int number;
    std::string userName, data;
    std::cout<<"Enter number of users: ";
    std::cin>>number;
    for(int i=0; i<number; i++){
        
        std::cout<<"Enter username- "<<i+1<<"and its data: ";
        std::cin>>userName>>data;
       
        Node* temp = new Node{  userName, data, nullptr, nullptr};  //creating a new node
        cacheMap[userName] = temp; //register key and value in the map
        attachToHead(temp);
    }
    printData();
    std::string dataNeeded;
    std::cout<<"Enter key for which data is to be found: ";
    std::cin>>dataNeeded;
    std::cout<<"Getting data: "<< getValue(dataNeeded)<<std::endl;
    printData();

    return 0;
}

void disconnect(Node *n){  //to remove a node and set other nodes as nothing happened (making sure the chain doesn't break)
    
    if(n->prev != nullptr){
        n->prev->next = n->next;
    }
    else{
        head = n->next;
    }
    if(n->next != nullptr){
        n->next->prev = n->prev;
    }
    else{
        tail = n->prev;
    }
}

void attachToHead(Node * &n){  //to move the detached or 'plucked' node to the front making it the first node(recently used)
    n->next = head;
    n->prev = nullptr;
    if(head != nullptr){
        head->prev =n;
    }

    head = n;
    if(tail == nullptr){
        tail = n;
    }
  
}

std::string getValue(std::string key){
    if(cacheMap.find(key) == cacheMap.end()){
        return "Value NOT found!\n";
    }
    Node *target = cacheMap[key];

    disconnect(target);
    attachToHead(target);
    return target->value;
}

void printData(){
    Node* current = head;
    std::cout<<"List (MRU) -- > (LRU): ";
    while(current){
        std::cout<<"[" <<current->key <<":" << current->value << "]";
        current= current->next;
    }
    std::cout<<std::endl;
}
