#include <iostream>
#include <unordered_map>
#include <string>

struct Node {
    std::string key;
    std::string value;
    Node* prev;
    Node* next;
};

std::unordered_map<std::string, Node*> cacheMap;
Node* head = nullptr;
Node* tail = nullptr;

int main(){
    Node* first = new Node();
    Node* second = new Node();
    Node* third = new Node();

    first->value = "10";
    second->value = "20";
    third->value = "30";

    first->next = third;
    first->prev = second;
    second->prev = nullptr;
    second->next = first;
    third->prev = first;
    third->next = nullptr;

    std::cout<<"First node data: "<<third->prev->prev->value<<std::endl;
    std::cout<<"Second node data: "<<first->next->value<<std::endl;
    std::cout<<" third node data: "<<third->prev->prev->value<<std::endl;

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

