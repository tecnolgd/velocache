#include <iostream>
#include <unodored_map>

struct Node {
    std::string key;
    std::string value;
    Node* prev;
    Node* next;
};

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
    if(n->next != nullptr){
        n->next->prev = n->prev;
    }
}

void deleteNode(Node * &head){  //deleting a node from start ; &head --> to make sure the actual head pointer is moved
    Node *current = head;
    while(current != nullptr){
        Node *newnode = current->next;
        std::cout<<"Deleting : %s"<<current->value<<std::endl;
        delete current;
        current = newnode; //current points to next node

    }
}

std::unodored_map <std::string, Node*> cacheMap;